#ifndef GUITARTRACK
#define GUITARTRACK

#include "GameObject.hpp"
#include <string>
#include <vector>

using std::string;

class GuitarTrack : public GameObject{

    private:
        vector<GameObject*> notes;
        int pos = 0;
        string key;

    public:
        GuitarTrack(){ notes = vector<GameObject*>(); }
        string name;
        int speed = 5;

        void addNewNoteAtTop();
        void setupKeyAndPosition(string key, int pos);
        void render();
        void update();


};

#endif

