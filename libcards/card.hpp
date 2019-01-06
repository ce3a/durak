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

class Deck {
private:
    std::vector<Card> _cards;

public:
    Deck();
    Deck(std::initializer_list<Card> il);
    bool empty() const;
    int  size()  const;
    void shuffle();
    Card draw();

    friend bool operator==(const Deck& lhs, const Deck& rhs);
    friend bool operator!=(const Deck& lhs, const Deck& rhs);

    /* For 'raged-base for' loops */
    auto begin() const { return _cards.begin(); }
    auto end()   const { return _cards.end();   }
};

#endif /* LIBCARDS_CARDS_HPP */

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
