#include "game.h"
#include "logger.h"

int main()
{
    Logger::log(LogLevel::INFO, "Starting MyFolks");
    Game game;
    game.run();
    return 0;
}
