#include "GuitarTrack.hpp" 
#include "Game.hpp"
#include "Image.hpp"

using std::string;

int touchLimit = 500;
int touchRange = 20;

void GuitarTrack::addNewNoteAtTop(){

    NoteObject* note = new NoteObject();
    note->x = 100 + 100*this->pos;
    note->y = 0;

    //Adding image
    note->setupImage("circle.png","circle_green.png","circle_red.png");

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
    }

    for (NoteObject* e_obj : notes) {
        
        e_obj->speed = 5;
        e_obj->update();

        if( didClicked ){
            
            int touchZone = abs(e_obj->y - touchLimit);

            // note touched is inside touchZone range
            if ( touchZone < touchRange ){
                e_obj->gotHitted();
            }
        }

        //note passed away
        if (e_obj->y > touchLimit){
            e_obj->gotMissed();
            //remove obj from vector
        }
    }
}