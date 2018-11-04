#pragma once

#include <algorithm>
#include <type_traits>

namespace helper
{

template<typename... Ts> struct make_void { typedef void type;};
template<typename... Ts> using void_t = typename make_void<Ts...>::type;

template<typename Container, typename = void_t<>>
struct hasFindMemberFn : std::false_type
{};

template<typename Container>
struct hasFindMemberFn<Container, void_t<decltype(std::declval<Container>().find(std::declval<typename Container::key_type>()))>> : std::true_type
{};

template<typename Container>
struct hasFindMemberFn<Container, void_t<decltype(std::declval<Container>().find(std::declval<typename Container::value_type>()))>> : std::true_type
{};

template<typename T, typename Container>
inline auto containsValue(const T& value, const Container& container) -> std::enable_if_t<!hasFindMemberFn<Container>::value, bool>
{
    return std::find(container.begin(), container.end(), value) != container.end();
}

template<typename T, typename Container>
inline std::enable_if_t<hasFindMemberFn<Container>::value, bool>
    containsValue(const T& value, const Container& container)
{
    return container.find(value) != container.end();
}

}//namespace helper
