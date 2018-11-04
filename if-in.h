#pragma once

#include <algorithm>
#include "helpers/contains-helper.h"

namespace IfIn
{
template<typename T>
struct ConstRefHolder
{
    const T& value;
};

template<typename T>
struct RvalueRefHolder
{
    T&& value;
};

struct {} joiner;
}//namespace IfIn

template<typename T>
inline IfIn::ConstRefHolder<T> operator^(const T& value, decltype(IfIn::joiner))
{
    return {value};
}

template<typename T>
inline IfIn::RvalueRefHolder<T> operator^(T&& value, decltype(IfIn::joiner))
{
    return {std::move(value)};
}


template<typename T, typename Container>
inline bool operator|(const IfIn::ConstRefHolder<T>& holder, const Container& container)
{
    return helper::containsValue(holder.value, container);
}


template<typename T, typename Container>
inline bool operator|(const IfIn::RvalueRefHolder<T>& holder, const Container& container)
{
    return helper::containsValue(holder.value, container);
}

#define in ^IfIn::joiner|

