#include "Game.hpp"
#include "SceneGuitar.hpp"
#include <iostream>
#include <stdio.h>

int main(){

    printf("Hello world!\n");

    SceneGuitar* initialScene = new SceneGuitar();
    Game::getInstance().Init(1024, 600, initialScene);
    initialScene->setup();

    Game::getInstance().run();
    Game::getInstance().~Game();

    return 0;
}