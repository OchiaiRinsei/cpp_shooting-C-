#pragma once
#include"TITLE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"BULLETS.h"
#include"HP_GAUGE.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		GAME_CLEAR::DATA game_clear;
		GAME_OVER::DATA game_over;
		PLAYER::DATA player;
		ENEMIES::DATA enemy;
		BULLETS::DATA playerBullet;
		BULLETS::DATA enemyBullet;
		HP_GAUGE::DATA hpGauge;
	};
	DATA Data;
public:
	void load();
	void setData();
	void loadGraphic();
	const TITLE::DATA& title() { return Data.title; }
	const GAME_CLEAR::DATA& game_clear() { return Data.game_clear; }
	const GAME_OVER::DATA& game_over() { return Data.game_over; }
	const PLAYER::DATA& player() { return Data.player; }
	const ENEMIES::DATA& enemy() { return Data.enemy; }
	const BULLETS::DATA& playerBullet() { return Data.playerBullet; }
	const BULLETS::DATA& enemyBullet() { return Data.enemyBullet; }
	const HP_GAUGE::DATA& hpGauge() { return Data.hpGauge; }
};

