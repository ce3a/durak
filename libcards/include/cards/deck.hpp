#ifndef LIBCARDS_DECK_HPP
#define LIBCARDS_DECK_HPP

#include <cards/card.hpp>
#include <vector>
#include <initializer_list>

class Deck {
private:
    std::vector<Card> _cards;

public:
    Deck();
    Deck(std::initializer_list<Card> il);
    bool empty() const;
    int  size()  const;
    void shuffle();
    void cut();
    Card draw();

    friend bool operator==(const Deck& lhs, const Deck& rhs);
    friend bool operator!=(const Deck& lhs, const Deck& rhs);

    /* For 'raged-base for' loops */
    auto begin() const { return _cards.begin(); }
    auto end()   const { return _cards.end();   }
};

#endif /* LIBCARDS_DECK_HPP */

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
