#include <boost/test/unit_test.hpp>
#include <card.hpp>
#include <sstream>

BOOST_AUTO_TEST_CASE(card)
{
    std::ostringstream oss;
    Card card{Suit::diamonds, Rank::queen};

    BOOST_CHECK(card.suit() == Suit::diamonds);
    BOOST_CHECK(card.rank() == Rank::queen);

    oss << card;
    BOOST_CHECK(oss.str() == "Queen of Diamonds");
}

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
