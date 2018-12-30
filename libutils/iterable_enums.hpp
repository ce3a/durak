#ifndef ITERABLE_ENUMS_HPP
#define ITERABLE_ENUMS_HPP

#include <type_traits>

/**
 * Example: Iterable Enums can be declared as follows:
 *
 * enum class Color {
 *     red, gree, blue,
 *     first = red, last = blue
 * };
 * template<> constexpr bool is_iterable_enum<Color> = true;
 */

template <class E>
constexpr auto enum_value(E e) noexcept
{
    return static_cast<std::underlying_type_t<E>>(e);
}

/* https://stackoverflow.com/questions/53973204/
 * how-to-reuse-operator-overloads-for-different-types */
template<class>
constexpr bool is_iterable_enum = false;

template<class T>
using for_iterable_enums = std::enable_if_t<is_iterable_enum<T>, T>;

template<class T> for_iterable_enums<T>
operator+(T c, int v)
{
    return (T)(enum_value(c) + v);
}

template<class T> for_iterable_enums<T>
operator++(T& r)
{
    return r = r + 1;
}

template<class T> for_iterable_enums<T>
operator*(T c)
{
    return c;
}

template<class T> for_iterable_enums<T>
begin(T)
{
    return T::first;
}

template<class T> for_iterable_enums<T>
end(T)
{
    return T::last + 1;
}

#endif /* ITERABLE_ENUMS_HPP */

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
