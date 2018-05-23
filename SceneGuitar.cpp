#include "SceneGuitar.hpp"
#include "Image.hpp"
#include "Game.hpp"
#include "CutiaSDL.hpp"
#include "GuitarTrack.hpp"
#include <stdio.h>


//Test dev
GuitarTrack* track = nullptr;


void SceneGuitar::setup(){

    track = new GuitarTrack();
    track->setupKeyAndPosition("1", 1);

    objs.push_back(track);
}



void SceneGuitar::update(){
    Scene::update();
    
    if(ticks > 30){

        //Create new note at top of the track
        if(track)
            track->addNewNoteAtTop();

        ticks = 0;
    }

    ticks++;
}