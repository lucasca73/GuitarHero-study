#ifndef NOTE_OBJECT
#define NOTE_OBJECT

#include "GameObject.hpp"
#include "CutiaSDL.hpp"
#include "Image.hpp"
#include <string>

using std::string;


class NoteObject : public GameObject{

    private:
        int state = 0; //0 nothing, 1 missed, 2 hitted
        Image* imageNoteNormal;
        Image* imageNoteHitted;
        Image* imageNoteMissed;
        Image* image;
        // Sound* soundMissedNote;

        int dieCounter = 5;

    public:
        int speed = 0;
        void setupImage(string imageNormal, string imageHitted, string imageMissed);
        void gotHitted();
        void gotMissed();
        void update();

};

#endif

