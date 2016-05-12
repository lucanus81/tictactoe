#ifndef _TICTACTOE_H
#define _TICTACTOE_H

#include <utility>
#include <string>

namespace game {

class match
{
public:
    enum class current_move {unknown, paper, shissor, rock};
    enum class game_state {unknown, win_p1, win_p2, draw};
    
    template <typename Strategy>
    game_state play(Strategy&& player1, Strategy&& player2) 
    {
        match::current_move p1 = std::forward<Strategy>(player1)();
        match::current_move p2 = std::forward<Strategy>(player2)();
        
        return winner(p1, p2);
    }

    static std::string state(game_state m);
    static std::string move_name(current_move m);

private:
    game_state winner(current_move p1, current_move p2) 
    {
        /*      (1)
              U P R S
            U U U U U
        (2) P U D 2 1
            R U 1 D 2
            S U 2 1 D*/
        static constexpr game_state solver[4][4] { 
            {game_state::unknown, game_state::unknown, game_state::unknown, game_state::unknown}, 
            {game_state::unknown, game_state::draw, game_state::win_p2, game_state::win_p1}, 
            {game_state::unknown, game_state::win_p2, game_state::draw, game_state::win_p2}, 
            {game_state::unknown, game_state::win_p2, game_state::win_p1, game_state::draw} };

        return solver[static_cast<int>(p1)][static_cast<int>(p2)];
    }
};

} // namespace game

#endif
