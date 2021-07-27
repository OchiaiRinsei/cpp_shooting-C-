#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class ENEMIES :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        int totalNum;
        int curNum;
        float majRadius;
        float minRadius;
        VECTOR2 centerPos;
        float fallSpeed;
        float targetPosY;
        float refTheta;
        float thetaSpeed;
        float triggerInterval;
        float ofstLaunchDist;
        //collision
        float bcRadius;
        float invincbleTime;
        int initHp;
        VECTOR2 hpGaugeOfst;
        COLOR collisionColor;
        COLOR nomalColor;
    };
private:
    //共通データ
    DATA Enemy;
    //単体データ配列
    struct ENEMY {
        VECTOR2 pos;
        float ofsTheta;
        float triggerErapsedTime;
        float invincbleRestTime;
        int hp;
        COLOR color;
    };
    ENEMY* Enemies;
public:
    ENEMIES(class GAME* game);
    ~ENEMIES();
    void create();
    void init();
    void update();
       void move();
       void launch();
       void collision();
    void draw();
    //gerret
    int curNum() { return Enemy.curNum; }
};

