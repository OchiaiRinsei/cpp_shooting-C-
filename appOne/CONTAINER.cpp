#include "CONTAINER.h"
void CONTAINER::load() {
	setData();
	loadGraphic();
}
void CONTAINER::setData() {
	Data.title.backColor = COLOR(0, 20, 0);
	Data.title.textColor = COLOR(0, 255, 0);
	Data.title.textSize = 400;
	Data.title.pos.x = 180;
	Data.title.pos.y = 700;
	strcpy_s(Data.title.str, "KUNOICHI");

	Data.game_clear.textColor = COLOR(0, 0, 255);
	Data.game_clear.textSize = 350;
	Data.game_clear.pos = VECTOR2(160, 500);
	strcpy_s(Data.game_clear.str, "GAME_CLEAR");

	Data.game_over.textColor = COLOR(255, 0, 0);
	Data.game_over.textSize = 350;
	Data.game_over.pos = VECTOR2(180, 800);
	strcpy_s(Data.game_over.str, "GAME_OVER");

	Data.player.angle = 0;
	Data.player.deathAngle = 1.2;
	Data.player.advSpeed = 300;
	Data.player.pos.x = 960;
	Data.player.pos.y = 970;
	Data.player.limmitW = 100;
	Data.player.launchVec = VECTOR2(0, -1);
	Data.player.triggerErapsedTime = 0;
	Data.player.triggerInterval = 0.1f;
	Data.player.ofsLaunchDist = 100;

	Data.player.bcRadius = 40;
	Data.player.invincbleTime = 0.05;
	Data.player.invincbleRestTime = 0;
	Data.player.hp = 5;
	Data.player.hpGaugeOfst = VECTOR2(0, -120);
	Data.player.collisionColor = COLOR(255, 0, 0);
	Data.player.nomalColor = COLOR(255, 255, 255);


	Data.enemy.totalNum = 8;
	Data.enemy.curNum = Data.enemy.totalNum;
	Data.enemy.majRadius = 700;
	Data.enemy.minRadius = 100;
	Data.enemy.centerPos = VECTOR2(960, -300);
	Data.enemy.fallSpeed = 60;
	Data.enemy.targetPosY = 300;
	Data.enemy.refTheta = 0;
	Data.enemy.thetaSpeed = 0.6f;
	Data.enemy.triggerInterval = 0.72f;
	Data.enemy.ofstLaunchDist = 100;

	Data.enemy.bcRadius = 40;
	Data.enemy.invincbleTime = 0.05;
	Data.enemy.initHp = 5;
	Data.enemy.hpGaugeOfst = VECTOR2(0, -120);
	Data.enemy.collisionColor = COLOR(255, 0, 0);
	Data.enemy.nomalColor = COLOR(255, 255, 255);


	Data.playerBullet.totalNum = 20;
	Data.playerBullet.curNum = 0;
	Data.playerBullet.advSpeed = 600;
	Data.playerBullet.angSpeed = 5.0f;
	Data.playerBullet.bcRadius = 20;
	
	Data.enemyBullet.totalNum = 20;
	Data.enemyBullet.curNum = 0;
	Data.enemyBullet.advSpeed = 600;
	Data.enemyBullet.angSpeed = 0;
	Data.enemyBullet.bcRadius = 20;

	Data.hpGauge.coWidth = 30;
	Data.hpGauge.hi = 15;
	Data.hpGauge.safeColor = COLOR(0, 255, 0);
	Data.hpGauge.dangerColor = COLOR(255,0, 0);
}
void CONTAINER::loadGraphic() {
	Data.player.img = loadImage("assets\\player.png");
	Data.enemy.img = loadImage("assets\\enemy.png");
	Data.playerBullet.img = loadImage("assets\\pBullet.png");
	Data.enemyBullet.img = loadImage("assets\\eBullet.png");

}
