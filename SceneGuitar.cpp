#include "SceneGuitar.hpp"
#include <stdio.h>
#include <string>
#include <vector>

#include "Image.hpp"
#include "Game.hpp"
#include "CutiaSDL.hpp"
#include "BackgroundRoller.hpp"
#include "Audio.hpp"

#include "MidiFile.h"
#include <iostream>
using namespace std;
using namespace smf;


void SceneGuitar::setup(){

    //Creating backgroundRoller
    BackgroundRoller* bgRoller = new BackgroundRoller();
    bgRoller->setup();
    bgRoller->speed = 6;

    objs.push_back(bgRoller);

    //Creating tracks
    tracks = vector<GuitarTrack*>();

    for(int i = 1; i <= 5; i++){

        GuitarTrack* track = new GuitarTrack();
        track->setupKeyAndPosition(std::to_string(i), i);

        objs.push_back(track);
        tracks.push_back(track);
    }

    setupNotes("Scorpions.mid");
}



void SceneGuitar::update(){
    Scene::update();

    counter -= 1;
    if(counter == 0){
        Audio* music = new Audio("Scorpions.wav");
        music->play();
    }
}


void SceneGuitar::setupNotes(string path){
    
    path = ASSETS_PATH + path;

    MidiFile midifile;
    midifile.read("/Users/lucasaraujo/projects/CutiaEngine/sample_assets/Scorpions.mid");

    if (!midifile.status()) {
        cerr << "Error reading MIDI file " << path.c_str() << endl;
        exit(1);
    }

    midifile.joinTracks();
    int track = 0;

    for (int i=0; i<midifile[track].size(); i++) {
        if (!midifile[track][i].isNoteOn()) {
            continue;
        }

        if(midifile[track][i].getKeyNumber() >= 95 && midifile[track][i].track == 1 ){

            int track_key = abs(midifile[track][i].getKeyNumber() - 100);
            tracks[track_key]->addNewNoteAtTick(midifile[track][i].tick - 3000);
        }
    }
}