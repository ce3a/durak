#include <boost/test/unit_test.hpp>
#include <cards/deck.hpp>
#include <sstream>

BOOST_AUTO_TEST_CASE(deck_init)
{
    Deck deck{};

    BOOST_REQUIRE(deck.size()  == 36);
    BOOST_REQUIRE(deck.empty() == false);
}

BOOST_AUTO_TEST_CASE(deck_init_ilist)
{
    Deck deck1({});

    BOOST_CHECK(deck1.size()  == 0);
    BOOST_CHECK(deck1.empty() == true);

    Deck deck2{
        Card{Suit::diamonds, Rank::queen},
        Card{Suit::hearts,   Rank::ace}
    };

    BOOST_CHECK(deck2.size()  == 2);
    BOOST_CHECK(deck2.empty() == false);
}

BOOST_AUTO_TEST_CASE(deck_shuffle)
{
    Deck deck1{};
    Deck deck2{};

    BOOST_CHECK(deck2 == deck1);
    deck2.shuffle();
    BOOST_CHECK(deck2 != deck1);
    BOOST_CHECK(deck2.size()  == 36);
    BOOST_CHECK(deck2.empty() == false);
}

BOOST_AUTO_TEST_CASE(deck_draw)
{
    std::ostringstream oss;
    Deck deck{};

    Card card = deck.draw();
    oss << card;
    BOOST_CHECK(oss.str()    == "Ace of Clubs");
    BOOST_CHECK(deck.size()  == 35);
    BOOST_CHECK(deck.empty() == false);

    while (!deck.empty())
        deck.draw();

    BOOST_CHECK(deck.size()  == 0);
    BOOST_CHECK(deck.empty() == true);
}

BOOST_AUTO_TEST_CASE(deck_loop)
{
    Deck deck{};
    int i = 0;

    auto card_is_valid = [](const Card& card) {
        return card.suit() >= Suit::first &&
               card.suit() <= Suit::last  &&
               card.rank() >= Rank::first &&
               card.rank() <= Rank::last;
    };

    for (const auto& card : deck) {
        BOOST_CHECK(card_is_valid(card));
        i++;
    }

    BOOST_CHECK(i == deck.size());
}

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
