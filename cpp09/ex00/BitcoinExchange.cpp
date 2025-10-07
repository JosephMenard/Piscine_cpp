#include "BitcoinExchange.hpp"

int countDecimals(std::string s)
{
    size_t pos = s.find('.');
    if (pos == std::string::npos)
        return 0;
    return s.size() - pos - 1;
}

bool isValidStringValue(std::string s) 
{
    if (s.empty())
        return false;

    int dotCount = 0;
    for (size_t i = 0; i < s.size(); ++i) 
    {
        char c = s[i];
        if (c == '.') 
        {
            dotCount++;
            if (dotCount > 1)
                return false;
        }
        else if (!std::isdigit(static_cast<unsigned char>(c)))
            return false;
    }
    return true;
}

std::string removeSpace(const std::string& input) 
{
    std::string result;
    for (size_t i = 0; i < input.length(); ++i) 
    {
        char c = input[i];
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r')
            result += c;
    }
    return result;
}

std::string floatToString(float v) {
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

float BitcoinExchange::doConversion(std::string date, float value) const
{
   for (std::multimap<std::string, float>::const_iterator it = _data.lower_bound(date); it != _data.end(); ++it)
    {
        if (it->first == date)
        {
            return value * it->second;
        }
        if (it->first > date)
        {
            --it;
            return value * it->second;
        }
    }
    return -1;
}

bool BitcoinExchange::checkInput(std::string& line, std::string date, float value) const
{
    if (date.empty())
    {
        line = "Error: empty date => ";
        return false;
    }
    if (value > 1000)
    {
        line = "Error: too large a number => ";
        return false;
    }
    if (value < 0)
    {
        line = "Error: not a positive number => ";
        return false;
    }
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        line = "Error: invalid date format => ";
        return false;
    }
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        line = "Error: Invalid date => ";
        return false;
    }
    std::tm t;
    std::memset(&t, 0, sizeof(t));
    t.tm_year = year - 1900;
    t.tm_mon  = month - 1;
    t.tm_mday = day;
    std::time_t input_time = std::mktime(&t);
    if (input_time == -1 || t.tm_year != year - 1900 || t.tm_mon  != month - 1 || t.tm_mday != day)
    {
        line = "Error: Invalid date => ";
        return false;
    }
    std::string firstDate = _data.begin()->first;
    int y = atoi(firstDate.substr(0,4).c_str());
    int m = atoi(firstDate.substr(5,2).c_str());
    int d = atoi(firstDate.substr(8,2).c_str());
    std::tm t2;
    std::memset(&t2, 0, sizeof(t2));
    t2.tm_year = y - 1900;
    t2.tm_mon  = m - 1;
    t2.tm_mday = d;
    std::time_t first_time = std::mktime(&t2);
    if (input_time < first_time) 
    {
        line = "Error: date before database start => ";
        return false;
    }

    return true;
}

void BitcoinExchange::render(void) const
{
    std::cout << "Bitcoin Exchange Data:" << std::endl;
    std::cout << "------------------------" << std::endl;
    if (_data.empty())
    {
        std::cout << "No data available." << std::endl;
        return;
    }
    std::ifstream file(_file_name.c_str());
    std::string line;
    std::string error_line;
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open : " <<  _file_name << std::endl;
        return;
    }
    while (std::getline(file, line))
    {
        size_t i = line.find("|", 0);
        if (i == std::string::npos)
        {
            std::cout << "Error: missing separator '|' => " << line << std::endl;
            continue;
        }
        i++;
        std::string date = line.substr(0, i - 1);
        date = removeSpace(date);
        std::string stringValue = line.substr(i, line.length() - i);
        stringValue = removeSpace(stringValue);
        if (!isValidStringValue(stringValue))
        {
            std::cout << "Error: not a valid value => " << line << std::endl;
            continue;
        }
        errno = 0;
        char* endptr = NULL;
        double tmp = strtod(stringValue.c_str(), &endptr);
        if (endptr == stringValue.c_str() || *endptr != '\0' || errno == ERANGE)
            continue;
        float value = static_cast<float>(tmp);
        if (checkInput(error_line, date, value))
            std::cout << date << " => " << stringValue << " = " << std::fixed << std::setprecision(countDecimals(stringValue)) << doConversion(date, value) << std::endl;
        else
            std::cout << error_line << line << std::endl;
    }
    file.close();
    std::cout << "------------------------" << std::endl;
}

void BitcoinExchange::parseData(void)
{
    std::ifstream file("data.csv");
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open data file." << std::endl;
        return;
    }
    while (std::getline(file, line))
    {
        int i = line.find(",", 0) + 1;
        std::string date = line.substr(0, i - 1);
        std::string stringValue = line.substr(i, line.length() - i);
        errno = 0;
        char* endptr = NULL;
        double tmp = strtod(stringValue.c_str(), &endptr);
        if (endptr == stringValue.c_str() || *endptr != '\0' || errno == ERANGE)
            continue;
        float value = static_cast<float>(tmp);
        _data.insert(std::make_pair(date, value));
    }
    file.close();
}

void BitcoinExchange::printData(void) const
{
    std::cout << "BitcoinExchange Data:" << std::endl;
    std::cout << "------------------------" << std::endl;
    for (std::multimap<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string value) : _file_name(value)
{
    parseData();
}

BitcoinExchange::~BitcoinExchange(void) 
{ 
}




