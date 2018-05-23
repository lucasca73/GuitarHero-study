#include "SceneGuitar.hpp"
#include "Image.hpp"
#include "Game.hpp"
#include "CutiaSDL.hpp"
#include <stdio.h>
#include <string>
#include <vector>



void SceneGuitar::setup(){

    tracks = vector<GuitarTrack*>();

    for(int i = 1; i <= 5; i++){

        GuitarTrack* track = new GuitarTrack();
        track->setupKeyAndPosition(std::to_string(i), i);

        objs.push_back(track);
        tracks.push_back(track);
    }
}



void SceneGuitar::update(){
    Scene::update();
    
    if(ticks > 30){

        //Create new note at top of the track
        tracks[0]->addNewNoteAtTop();
        tracks[1]->addNewNoteAtTop();
        tracks[2]->addNewNoteAtTop();
        tracks[3]->addNewNoteAtTop();
        tracks[4]->addNewNoteAtTop();

        ticks = 0;
    }

    ticks++;
}