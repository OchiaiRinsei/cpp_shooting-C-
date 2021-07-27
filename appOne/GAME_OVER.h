#pragma once
#include "SCENE.h"
class GAME_OVER :
    public SCENE
{
    
public:
    struct DATA {
        COLOR textColor;
        float textSize;
        VECTOR2 pos;
        char str[16];
    };
private:
    DATA Game_over;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void create();
    void update();
    void draw();
    void nextScene();
};