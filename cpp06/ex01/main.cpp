#include "Serializer.hpp"

int main(void)
{
    Data raw_data;
    Data* deserialized_data;
    uintptr_t  int_data;
    raw_data.number = 15;
    raw_data.name = "test";

    std::cout << "raw_data pointer: " << &raw_data << std::endl;
    std::cout << "raw_data.number: " << raw_data.number << std::endl;
    std::cout << "raw_data.name: " << raw_data.name << std::endl;
    int_data = Serializer::serialize(&raw_data);
    std::cout << "uintptr_t: " << int_data << std::endl;
    deserialized_data = Serializer::deserialize(int_data);
    std::cout << "deserialized_data " << deserialized_data << std::endl;
    std::cout << "deserialized_data.number: " << deserialized_data->number << std::endl;
    std::cout << "deserialized_data.name: " << deserialized_data->name << std::endl;

    return 0;
}