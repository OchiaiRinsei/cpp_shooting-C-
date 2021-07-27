#include"libOne.h"
#include"CONTAINER.h"
#include "GAME_OVER.h"
#include"GAME.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"

GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game) {
}
GAME_OVER::~GAME_OVER() {
}
void GAME_OVER::update() {
	game()->playerBullets()->update();
	game()->enemyBullets()->update();
	game()->enemies()->move();
	game()->player()->losemove();
}
void GAME_OVER::create() {
	Game_over = game()->container()->game_over();
}
void GAME_OVER::draw() {
	clear();
	fill(Game_over.textColor);
	textSize(Game_over.textSize);
	text(Game_over.str,Game_over.pos.x, Game_over.pos.y);
	game()->draw();
}
void GAME_OVER::nextScene() {
	if (isTrigger(KEY_V)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}