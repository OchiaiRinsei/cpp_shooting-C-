#pragma once
#include "GAME_OBJECT.h"
#include "libOne.h"
class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        VECTOR2 pos;
        float angle;
        float deathAngle;
        float limmitW;
        float advSpeed;
        //launch
        VECTOR2 launchVec;
        float triggerErapsedTime;
        float triggerInterval;
        float ofsLaunchDist;
        //collision
        float bcRadius;
        float invincbleTime;
        float invincbleRestTime;
        int hp;
        VECTOR2 hpGaugeOfst;
        COLOR collisionColor;
        COLOR nomalColor;
        COLOR color;
    };
private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    void create();
    void init();
    void update();
         void move();
         void launch();
         void collision();
         void losemove();
    void draw();
    VECTOR2 pos() { return Player.pos; }
    int hp() { return Player.hp; }
};

