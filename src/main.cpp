#include <card.hpp>
#include <iostream>

auto main(int argc, char *argv[]) -> int
{
    (void)argc;
    (void)argv;

    Deck deck{};

    auto print_deck = [&deck]() {
      for (const auto& card: deck)
          std::cout << card << std::endl;
    };

    print_deck();

    deck.shuffle();

    std::cout << "---" << std::endl;
    print_deck();

    return 0;
}

// vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
