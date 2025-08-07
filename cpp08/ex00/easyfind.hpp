#pragma once
#include <algorithm>
template<typename Container>
typename Container::iterator easyfind(Container& container, int num)
{
    return std::find(container.begin(), container.end(), num);
}

template<typename Container>
typename Container::const_iterator easyfind(const Container& container, int num)
{
    return std::find(container.begin(), container.end(), num);
}