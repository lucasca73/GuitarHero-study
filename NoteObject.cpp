#include "NoteObject.hpp" 


void NoteObject::setupImage(string imageNormal, string imageHitted, string imageMissed){
    imageNoteNormal = new Image(imageNormal);
    imageNoteHitted = new Image(imageHitted);
    imageNoteMissed = new Image(imageMissed);
    
    image = new Image(imageNormal);

    this->addComponent(image);
}

void NoteObject::gotHitted(){
    if(state == 2) return;
    state = 2;
    image->texture = imageNoteHitted->texture;
}

void NoteObject::gotMissed(){
    if(state == 1) return;
    state = 1;
    image->texture = imageNoteMissed->texture;
}

void NoteObject::update(){

    if(state != 2){
        this->y += speed;
    }else{
        dieCounter -= 1;

        if (dieCounter <= 0){
            this->y = -500;
            this->enabled = false;
        }
    }
}