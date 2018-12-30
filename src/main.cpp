#include <card.hpp>
#include <iostream>

auto main(int argc, char *argv[]) -> int
{
    (void)argc;
    (void)argv;

    int i;
    Deck deck{};

    auto print_deck = [&]() {
        i = 1;
        for (const auto& card: deck)
            std::cout << "* " << i++ << ": " << card << std::endl;
    };

    auto print_size = [&]() {
        std::cout << "number of cards: " << deck.size() << std::endl;
    };

    print_deck();
    print_size();

    deck.shuffle();

    std::cout << "---" << std::endl;

    i = 1;
    while (!deck.empty()) {
        std::cout << "- " << i++ << ": " << deck.draw() << std::endl;
    }

    print_size();
    std::cout << "---" << std::endl;
    print_deck();

    return 0;
}

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
