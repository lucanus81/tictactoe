#include "tictactoe.h"
#include <array>

namespace game {

std::string match::state(match::game_state m)
{
    static std::array<std::string, 4> index{ "unknown", "winner_player1", "winnner_player2", "draw" };
    return index[static_cast<int>(m)];
}

}
