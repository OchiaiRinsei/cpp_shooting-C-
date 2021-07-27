#include"libOne.h"
#include "GAME.h"
#include "TITLE.h"
#include "STAGE.h"
#include "GAME_CLEAR.h"
#include "GAME_OVER.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include"HP_GAUGE.h"

GAME::GAME() {
    Container = new CONTAINER;
    Scenes[TITLE_ID] = new TITLE(this);
    Scenes[STAGE_ID] = new STAGE(this);
    Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
    Scenes[GAME_OVER_ID] = new GAME_OVER(this);


    Player = new PLAYER(this);
    Enemies = new ENEMIES(this);
    PlayerBullets = new PLAYER_BULLETS(this);
    EnemyBullets = new ENEMY_BULLETS(this);
    HpGauge = new HP_GAUGE(this);

}
GAME::~GAME() {
    delete HpGauge;
    delete EnemyBullets;
    delete PlayerBullets;
    delete Enemies;
    delete Player;
    for (int i = 0; i < NUM_SCENES; i++) {
        delete Scenes[i];
    }
    delete Container;
}
void GAME::run() {
    window(1920, 1080, full);
    hideCursor();

    Container->load();

    Scenes[TITLE_ID]->create();
    Scenes[GAME_CLEAR_ID]->create();
    Scenes[GAME_OVER_ID]->create();

    Player->create();
    Enemies->create();
    PlayerBullets->create();
    EnemyBullets->create();
    HpGauge->create();

    CurSceneId = TITLE_ID;
    Scenes[CurSceneId]->init();
    initDeltaTime();
    while (notQuit) {
        setDeltaTime();
        Scenes[CurSceneId]->proc();
    }
}

void GAME::changeScene(SCENE_ID sceneId) {
    CurSceneId = sceneId;
    Scenes[CurSceneId]->init();
}
void GAME::draw() {
    Player->draw();
    Enemies->draw();
    PlayerBullets->draw();
    EnemyBullets->draw();
}