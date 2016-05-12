#include <iostream>
#include "tictactoe.h"
#include "strategy.h"

int main(int argc, char** argv) 
{
    // First strategy for two players
    std::cout <<"Player 1 move [type S, or R, or P]: ";
    char p1{};
    std::cin >> p1;

    std::cout <<"player 2 move [type S, or R, or P]: ";
    char p2{};
    std::cin >> p2;

    game::match m;
    auto result = m.play(game::input_strategy{p1}, game::input_strategy{p2});
    std::cout <<game::match::state(result) <<std::endl;

    // Two computers playing against each other
    for (size_t i=0; i<10; ++i)
    {
        game::random_strategy r1{};
        game::random_strategy r2{};
        
        auto rr1 = r1();
        auto rr2 = r2();

        game::match m;
        std::cout <<"Match #" <<i <<": " 
            <<game::match::move_name(rr1)
            <<" vs "
            <<game::match::move_name(rr2)
            <<" = " 
            <<game::match::state(m.play(std::move(r1), std::move(r2))) <<std::endl;
    }
    
    return 0;
}
