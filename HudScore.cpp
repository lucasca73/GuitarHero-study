#include "HudScore.hpp" 
#include <string>

using namespace std;

void HudScore::setup(){
    SDL_Color txt_color = {255,255,255};
    
    txt_score = new Text("0", "Silom.ttf", 42, txt_color);
    txt_score->x = 10;

    txt_combo = new Text("0x", "Silom.ttf", 20, txt_color);
    txt_combo->x = 10;
    txt_combo->y = 50;

    this->addComponent(txt_score);
    this->addComponent(txt_combo);
}

void HudScore::hitNote(){

    if (combo < 10){
        comboMultiplier = 1;
    }else if(combo < 20){
        comboMultiplier = 2;
    }else if(combo < 30){
        comboMultiplier = 3;
    }else {
        comboMultiplier = 4;
    }

    score += 10 * comboMultiplier;
    combo += 1;

    txt_score->setText( to_string(score) );
    txt_score->makeTexture();

    txt_combo->setText( to_string(comboMultiplier) + "x" );
    txt_combo->makeTexture();
}

void HudScore::missNote(){
    combo = 0;
    comboMultiplier = 1;
}