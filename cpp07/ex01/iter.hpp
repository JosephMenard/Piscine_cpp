#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename ADR, typename FUNC>
void iter(ADR *adr, size_t length, FUNC fonction)
{
    if (!adr)
        return;
    for (size_t i = 0; i < length; ++i)
        fonction(adr[i]);
}


#endif