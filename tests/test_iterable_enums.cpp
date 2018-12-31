#include <boost/test/unit_test.hpp>
#include <iterable_enums.hpp>
#include <type_traits>

enum class Number {
   one = 1, two, three, four, five,
   first = one, last = five
};
template<> constexpr bool is_iterable_enum<Number> = true;

BOOST_AUTO_TEST_CASE(iterable_enums_add)
{
    Number n = Number::one;

    n = n + 2;
    BOOST_CHECK(n == Number::three);
    BOOST_CHECK(++n == Number::four);
}

BOOST_AUTO_TEST_CASE(iterable_enums_loop)
{
    std::underlying_type_t<Number> i = enum_value(Number::one);

    for (const auto& n : Number::one) {
        BOOST_CHECK(enum_value(n) == i++);
    }

    BOOST_CHECK((i - 1) == enum_value(Number::last));
}

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
