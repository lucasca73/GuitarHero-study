#ifndef SCORE_MANAGER
#define SCORE_MANAGER

#include "GameObject.hpp"

class ScoreManager : public GameObject{

    public:
        void hitedNote();
        void missedNote();
};

#endif

