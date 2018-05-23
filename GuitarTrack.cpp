#include "GuitarTrack.hpp" 
#include "Game.hpp"
#include "Image.hpp"

using std::string;

void GuitarTrack::addNewNoteAtTop(){

    GameObject* note = new GameObject();
    note->x = 100 + 100*this->pos;
    note->y = 0;

    //Adding image
    Component* image = new Image("circle.png");

    note->addComponent(image);

    notes.push_back(note);
}

void GuitarTrack::setupKeyAndPosition(string key, int pos){
    this->pos = pos;
    this->key = key;
    this->name = "Track 1";
}

void GuitarTrack::render(){
    for (auto e_obj : notes) {
        e_obj->render();
    }
}

void GuitarTrack::update(){

    bool didClicked = false;
    
    if (Game::getInstance().buttonDown(this->key)){
        didClicked = true;
        printf("Click received.\n");
    }

    for (auto e_obj : notes) {

        e_obj->y += this->speed; // Dev purposes

        if( didClicked ){

            if ( abs(e_obj->y - 600) < 20 ){
                e_obj->x += 100;
                e_obj->y = 400;
            }
        }

        if (e_obj->y > 700){
            //remove obj from vector
        }
    }
}