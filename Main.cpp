#include "Game.hpp"
#include "SceneGuitar.hpp"

int main(){

    Scene* initialScene = new SceneGuitar();

    Game::getInstance().Init(1024, 600, initialScene);
    Game::getInstance().run();
    Game::getInstance().~Game();

    return 0;
}