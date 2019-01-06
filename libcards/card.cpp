#include <card.hpp>

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

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
