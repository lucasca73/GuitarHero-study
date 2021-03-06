#ifndef SCENE_GUITAR_HPP
#define SCENE_GUITAR_HPP

#include "Scene.hpp"
#include "GameObject.hpp"
#include "GuitarTrack.hpp"
#include <vector>

using std::vector;

class SceneGuitar : public Scene{

    private:
        vector<GuitarTrack*> tracks;
        int ticks;
        void createNewNoteAtTop();
        void setupNotes(string path);
        int counter = 100;

    public:
        void setup();
        void update();

};


#endif