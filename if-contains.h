#pragma once

#include <algorithm>
#include "helpers/contains-helper.h"

namespace IfContains
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
}//namespace IfContains

template<typename T>
inline IfContains::ConstRefHolder<T> operator^(decltype(IfContains::joiner), const T& value)
{
    return {value};
}

template<typename T>
inline IfContains::RvalueRefHolder<T> operator^(decltype(IfContains::joiner), T&& value)
{
    return {std::move(value)};
}


template<typename T, typename Container>
inline bool operator|(const Container& container, const IfContains::ConstRefHolder<T>& holder)
{
    return helper::containsValue(holder.value, container);
}


template<typename T, typename Container>
inline bool operator|(const Container& container, const IfContains::RvalueRefHolder<T>& holder)
{
    return helper::containsValue(holder.value, container);
}

#define contains |IfContains::joiner^

