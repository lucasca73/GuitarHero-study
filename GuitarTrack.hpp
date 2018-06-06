#ifndef GUITARTRACK
#define GUITARTRACK

#include "GameObject.hpp"
#include "NoteObject.hpp"
#include <string>
#include <vector>

#include "HudScore.hpp"

using std::string;

class GuitarTrack : public GameObject{

    private:
        vector<NoteObject*> notes;
        int pos = 0;
        string key;
        GameObject* button;

    public:
        GuitarTrack(){ notes = vector<NoteObject*>(); }
        string name;
        int speed = 6;
        HudScore *score;

        void addNewNoteAtTick(int tick);
        void addNewNoteAtTop();
        void setupKeyAndPosition(string key, int pos);
        void render();
        void update();


};

#endif

