#ifndef LIBCARDS_CARDS_HPP
#define LIBCARDS_CARDS_HPP

#include <iostream>
#include <vector>
#include <iterable_enums.hpp>

enum class Suit {
    spades = 1, hearts, diamonds, clubs,
    first = spades, last = clubs
};

enum class Rank {
    six = 6, seven, eight, nine, ten, jack, queen, king, ace,
    first = six, last = ace
};

template<> constexpr bool is_iterable_enum<Suit> = true;
template<> constexpr bool is_iterable_enum<Rank> = true;

std::ostream& operator<< (std::ostream &out, const Suit &suit);
std::ostream& operator<< (std::ostream &out, const Rank &rank);

class Card {
private:
    Suit suit;
    Rank rank;

public:
    Card() = delete;
    Card(Suit suit, Rank rank);

    friend std::ostream& operator<< (std::ostream &out, const Card &card);
};

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck();

    /* For 'raged-base for' loops */
    auto begin() const { return cards.begin(); }
    auto end()   const { return cards.end();   }
};

#endif /* LIBCARDS_CARDS_HPP */

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
