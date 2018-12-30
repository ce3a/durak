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
    suit(suit), rank(rank) {}

std::ostream& operator<< (std::ostream& out, const Card& card)
{
    out << card.rank << " of " << card.suit;
    return out;
}

Deck::Deck()
{
    for (const auto& s: Suit::first)
        for (const auto& r: Rank::first)
            cards.push_back(Card{s, r});

    cards.shrink_to_fit();
}

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
