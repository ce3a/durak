#include <cards/deck.hpp>
#include <algorithm>
#include <random>

Deck::Deck()
{
    for (const auto& s: Suit::first)
        for (const auto& r: Rank::first)
            _cards.push_back(Card{s, r});

    _cards.shrink_to_fit();
}

Deck::Deck(std::initializer_list<Card> il)
{
    _cards.insert(_cards.begin(), il);
}

bool Deck::empty() const
{
    return _cards.empty();
}

int Deck::size() const
{
    return _cards.size();
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(_cards.begin(), _cards.end(), g);
}

Card Deck::draw()
{
    Card card = _cards.back();
    _cards.pop_back();
    return card;
}

bool operator==(const Deck& lhs, const Deck& rhs)
{
    return lhs._cards == rhs._cards;
}

bool operator!=(const Deck& lhs, const Deck& rhs)
{
    return !(lhs == rhs);
}

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
