#include"libOne.h"
#include"CONTAINER.h"
#include "GAME_CLEAR.h"
#include"GAME.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game) :
	SCENE(game) {
}
GAME_CLEAR::~GAME_CLEAR() {
}
void GAME_CLEAR::create() {
	Game_clear = game()->container()->game_clear();
}
void GAME_CLEAR::update() {
	game()->playerBullets()->update();
	game()->enemyBullets()->update();
}
void GAME_CLEAR::draw() {
	clear();
	game()->draw();
	fill(Game_clear.textColor);
	textSize(Game_clear.textSize);
	text(Game_clear.str, Game_clear.pos.x, Game_clear.pos.y);
}
void GAME_CLEAR::nextScene() {
	if (isTrigger(KEY_C)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}