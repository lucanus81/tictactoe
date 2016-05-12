#include "tictactoe.h"
#include <array>

namespace game {

std::string match::state(match::game_state m)
{
    static std::array<std::string, 4> index{ "unknown", "winner_player1", "winnner_player2", "draw" };
    return index[static_cast<size_t>(m)];
}

std::string match::move_name(match::current_move m)
{
    static std::array<std::string,4> index{ "unknown", "paper", "shissor", "rock"};
    return index[static_cast<size_t>(m)];
}

}
