#ifndef _STRATEGY_H
#define _STRATEGY_H

#include "tictactoe.h"
#include <array>
#include <random>
#include <iostream>

namespace game {

struct input_strategy 
{
    input_strategy(char what) : what_{what} {}
    game::match::current_move operator()() const {
        switch (what_) {
        case 's':
        case 'S':
            return game::match::current_move::shissor;
        case 'r':
        case 'R':
            return game::match::current_move::rock;
        case 'p':
        case 'P':
            return game::match::current_move::paper;
        default:
            return game::match::current_move::unknown;
        }
    }

    char what_;
};

struct random_strategy
{
    game::match::current_move operator()() const {
        static std::array<game::match::current_move,3> all_possible_moves{ 
            game::match::current_move::paper,
            game::match::current_move::rock,
            game::match::current_move::shissor };

        if (move_ == game::match::current_move::unknown)
        {
            std::random_device device;
            std::mt19937 generator(device());
            std::uniform_int_distribution<unsigned int> unif(0, 2);
            move_ = all_possible_moves[unif(generator)];
        }
        
        return move_;
    }

    mutable game::match::current_move move_ = game::match::current_move::unknown;
};

struct always_win {
    game::match::current_move operator()(game::match::current_move player_move) const 
    {
        using m = game::match::current_move;
        
        switch (player_move) 
        {
        case m::unknown:
            return m::unknown;
        case m::shissor:
            return m::rock;
        case m::rock:
            return m::paper;
        case m::paper:
            return m::shissor;
        };
    }
};

}

#endif
