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

void Deck::cut()
{
    auto mean   = _cards.size() / 2;
    auto stddev = _cards.size() / 6;

    std::random_device seed;
    std::mt19937 gen(seed());
    std::normal_distribution<> dist(mean, stddev);

    int n;
    do {
        n = dist(gen);
    } while (n <= 0 || n >= (int)_cards.size());

    std::vector<Card>::const_iterator first = _cards.begin();
    std::vector<Card>::const_iterator mid   = _cards.begin() + n;
    std::vector<Card>::const_iterator last  = _cards.end();

    std::vector<Card> tmp(mid, last);
    tmp.insert(tmp.end(), first, mid);

    _cards.swap(tmp);
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
