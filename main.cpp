#include <iostream>
#include <string>
#include "tictactoe.h"
#include "strategy.h"

void two_players(unsigned int how_many_times);
void player_vs_cpu(unsigned int how_many_times);
void cpu_vs_cpu(unsigned how_many_times);

int main(int argc, char** argv) 
{
    unsigned int how_many_times = static_cast<unsigned int>(std::stoi(argv[2]));

    switch (*argv[1]) {
        case '1':
            two_players(how_many_times);
            break;
        case '2':
            player_vs_cpu(how_many_times);
            break;
        case '3':
            cpu_vs_cpu(how_many_times);
            break;
    }

    return 0;
}

void two_players(unsigned int how_many_times)
{
    for (auto i=0; i<how_many_times; ++i) 
    {
        std::cout <<"Match #" <<i <<": player #1 move [type S, or R, or P]: ";
        char p1{};
        std::cin >> p1;

        std::cout <<"Match #" <<i <<": player #2 move [type S, or R, or P]: ";
        char p2{};
        std::cin >> p2;

        game::match m;
        auto result = m.play(game::input_strategy{p1}, game::input_strategy{p2});
        std::cout <<"Match #" <<i <<" result: " <<game::match::state(result) <<std::endl;
    }
}

void cpu_vs_cpu(unsigned int how_many_times)
{
    for (auto i=0; i<how_many_times; ++i)
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
 
}

void player_vs_cpu(unsigned how_many_times)
{
}


