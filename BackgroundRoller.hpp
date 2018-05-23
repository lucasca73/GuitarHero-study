#ifndef BACKGROUNDROLLER
#define BACKGROUNDROLLER

#include "GameObject.hpp"
#include <vector>

class BackgroundRoller : public GameObject{

    private:
        vector<GameObject*> backgrounds;

    public:
        int speed = 0;
        void setup();
        void render();
        void update();

};

#endif

