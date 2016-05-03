#include <iostream>
#include "tictactoe.h"

struct input_strategy {
    input_strategy(char what) : what_{what} {}
    game::match::current_move operator()() {
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

int main(int argc, char** argv) 
{
    std::cout <<"Player 1 move [type S, or R, or P]: ";
    char p1{};
    std::cin >> p1;

    std::cout <<"player 2 move [type S, or R, or P]: ";
    char p2{};
    std::cin >> p2;

    game::match m;
    std::cout <<game::match::state( m.play(input_strategy{p1}, input_strategy{p2}) ) <<std::endl;
    std::cout <<game::match::state( m.play(input_strategy{p1}, input_strategy{p2}) ) <<std::endl;
    
    return 0;
}
