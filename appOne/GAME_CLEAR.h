#pragma once
#include "SCENE.h"
class GAME_CLEAR:
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
    DATA Game_clear;
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void create();
    void update();
    void draw();
    void nextScene();
};