#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template <typename Template>
void swap(Template &a, Template &b)
{
    Template temp = a;
    a = b;
    b = temp;
}

template <typename Template>
Template min(Template &a, Template &b)
{
    if (a > b)
        return b;
    return a;
}

template <typename Template>
Template max(Template &a, Template &b)
{
    if (a < b)
        return b;
    return a;
}

#endif