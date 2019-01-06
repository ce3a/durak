#ifndef LIBCARDS_CARD_HPP
#define LIBCARDS_CARD_HPP

#include <ostream>
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
    Suit _suit;
    Rank _rank;

public:
    Card() = delete;
    Card(Suit suit, Rank rank);
    Suit suit() const;
    Rank rank() const;

    friend std::ostream& operator<< (std::ostream &out, const Card &card);
    friend bool operator==(const Card& lhs, const Card& rhs);
    friend bool operator!=(const Card& lhs, const Card& rhs);
};

#endif /* LIBCARDS_CARD_HPP */

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
