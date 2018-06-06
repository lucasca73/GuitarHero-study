#include "GuitarTrack.hpp" 
#include "Game.hpp"
#include "Image.hpp"

using std::string;

int touchLimit = 510;
int touchRange = 50;

void GuitarTrack::addNewNoteAtTick(int tick){
    NoteObject* note = new NoteObject();
    note->x = 200 + 90*pos;
    note->y = -(tick/3);

    //Adding image
    note->setupImage("circle.png","circle_green.png","circle_red.png");

    notes.push_back(note);
}

void GuitarTrack::addNewNoteAtTop(){

    NoteObject* note = new NoteObject();
    note->x = 200 + 90*pos;
    note->y = -100;

    //Adding image
    note->setupImage("circle.png","circle_green.png","circle_red.png");

    notes.push_back(note);
}

void GuitarTrack::setupKeyAndPosition(string key, int pos){
    this->pos = pos;
    this->key = key;
    this->name = "Track 1";

    button = new GameObject();
    button->x = 200 + 90*pos;
    button->y = 490;

    Image* baseButtonImage = new Image("circle.png");

    button->addComponent(baseButtonImage);
}

void GuitarTrack::render(){
    for (auto e_obj : notes) {
        e_obj->render();
    }
    button->render();
}

void GuitarTrack::update(){

    bool didClicked = false;
    
    if (Game::getInstance().buttonDown(this->key)){
        didClicked = true;
    }

    for (NoteObject* e_obj : notes) {
        
        e_obj->speed = this->speed;
        e_obj->update();

        if( didClicked ){
            
            int touchZone = abs(e_obj->y - touchLimit);

            // note touched is inside touchZone range
            if ( touchZone < touchRange ){
                e_obj->gotHitted();
                score->hitNote();
            }
        }

        //note passed away
        if (e_obj->y > touchLimit){
            e_obj->gotMissed();
            score->missNote();
            //remove obj from vector
        }
    }
}