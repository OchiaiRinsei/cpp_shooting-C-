#include"CONTAINER.h"
#include"GAME.h"
#include "PLAYER.h"
#include "PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
PLAYER::PLAYER(class GAME* game):
	GAME_OBJECT(game) {
}
void PLAYER::create(){
	Player = game()->container()->player();
}
void PLAYER::init(){
	Player.pos = game()->container()->player().pos;
	Player.hp = game()->container()->player().hp;
	Player.angle = game()->container()->player().angle;
}
void PLAYER::update() {
	move();
	launch();
	collision();
}
void PLAYER::move() {
	if (Player.pos.x > Player.limmitW && isPress(KEY_A)) {
		Player.pos.x += -Player.advSpeed * delta;
	}
	else if (Player.pos.x < width - Player.limmitW &&
		isPress(KEY_D)) {
		Player.pos.x += Player.advSpeed * delta;
	}
}
void PLAYER::launch() {
	if (isPress(KEY_SPACE)) {
		Player.triggerErapsedTime += delta;
		if (Player.triggerErapsedTime >= Player.triggerInterval) {
			VECTOR2 pos = Player.pos + Player.launchVec * Player.ofsLaunchDist;
			game()->playerBullets()->launch(pos, Player.launchVec);
			Player.triggerErapsedTime = 0;
		}
	}
	else {
		Player.triggerErapsedTime = Player.triggerInterval;
	}
}
void PLAYER::collision() {
	if (Player.invincbleRestTime > 0) {
		Player.invincbleRestTime -= delta;
	}
	else {
		Player.color = Player.nomalColor;
		ENEMY_BULLETS* bullets = game()->enemyBullets();
		float distance = Player.bcRadius + bullets->bcRadius();
		float sqDistance = distance * distance;
		for (int i = bullets->curNum() - 1; i >= 0; i--) {
			VECTOR2 vec = Player.pos - bullets->pos(i);
			if (sqLength(vec) < sqDistance) {
				Player.hp--;
				Player.invincbleRestTime = Player.invincbleTime;
				Player.color = Player.collisionColor;
				bullets->kill(i);
				i = 0;
			}
		}
	}
}
void PLAYER::losemove() {
	Player.angle = Player.deathAngle;
}
void PLAYER::draw(){
	imageColor(Player.color);
	rectMode(CENTER);
	image(Player.img, Player.pos.x, Player.pos.y, Player.angle);
	game()->hpgauge()->draw(Player.pos, Player.hpGaugeOfst, Player.hp);
	
}