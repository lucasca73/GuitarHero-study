#ifndef HUDSCORE
#define HUDSCORE

#include "GameObject.hpp"
#include "Text.hpp"

class HudScore : public GameObject{

    private:
        Text* txt_score;
        Text* txt_combo;
        int score = 0;
        int combo = 0;
        int comboMultiplier = 0;

    public:
        void setup();
        void hitNote();
        void missNote();
};

#endif

