#include <card.hpp>
#include <algorithm>
#include <random>

std::ostream& operator<< (std::ostream &out, const Suit &suit)
{
    switch (suit) {
        case Suit::spades:   out << "Spades";   break;
        case Suit::hearts:   out << "Hearts";   break;
        case Suit::diamonds: out << "Diamonds"; break;
        case Suit::clubs:    out << "Clubs";    break;
        default:             out.setstate(std::ios_base::failbit);
    }

    return out;
}

std::ostream& operator<< (std::ostream &out, const Rank &rank)
{
    switch (rank) {
        case Rank::six:   out << "Six";   break;
        case Rank::seven: out << "Seven"; break;
        case Rank::eight: out << "Eight"; break;
        case Rank::nine:  out << "Nine";  break;
        case Rank::ten:   out << "Ten";   break;
        case Rank::jack:  out << "Jack";  break;
        case Rank::queen: out << "Queen"; break;
        case Rank::king:  out << "King";  break;
        case Rank::ace:   out << "Ace";   break;
        default:          out.setstate(std::ios_base::failbit);
    }

    return out;
}

Card::Card(Suit suit, Rank rank) :
    _suit(suit), _rank(rank) {}

Suit Card::suit() const
{
    return this->_suit;
}

Rank Card::rank() const
{
    return this->_rank;
}

std::ostream& operator<< (std::ostream& out, const Card& card)
{
    out << card._rank << " of " << card._suit;
    return out;
}

bool operator==(const Card& lhs, const Card& rhs)
{
    return lhs._suit == rhs._suit && lhs._rank == rhs._rank;
}

bool operator!=(const Card& lhs, const Card& rhs)
{
    return !(lhs == rhs);
}

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
