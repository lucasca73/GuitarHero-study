#include "BackgroundRoller.hpp" 
#include "Image.hpp"

void BackgroundRoller::setup(){

    backgrounds = vector<GameObject*>();

    int h = 600;

    for(int i = 0; i < 2; i++){

        Image* image = new Image("background_guitar.png");

        GameObject* bg = new GameObject();
        bg->x = 0;
        bg->y = -(h*i);

        bg->addComponent(image);
        backgrounds.push_back(bg);
    }
}

void BackgroundRoller::render(){
    for(auto bg : backgrounds){
        bg->render();
    }
}

void BackgroundRoller::update(){

    for(auto bg : backgrounds){
        bg->y += speed;

        if(bg->y >= 600){
            bg->y = -600;
        }
    }


}