#pragma once
class GAME
{
//�R���e�i
private:
	class CONTAINER* Container;
//�Q�b�^�[
//���̕\�L�łǂ̃N���X������R���e�i�ɃA�N�Z�X�ł���
public:
	class CONTAINER* container() { return Container; }
//�V�[��
public:
	enum SCENE_ID {
		TITLE_ID,
		STAGE_ID,
		GAME_CLEAR_ID,
		GAME_OVER_ID,
		NUM_SCENES
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
public:
//�L�����N�^�[
private:
	class PLAYER* Player;
	class ENEMIES* Enemies;
	class PLAYER_BULLETS* PlayerBullets;
	class ENEMY_BULLETS* EnemyBullets;
	class HP_GAUGE* HpGauge;

public:
	void draw();
	class PLAYER* player() { return Player; }
	class ENEMIES* enemies() { return Enemies; }
	class PLAYER_BULLETS* playerBullets(){ return PlayerBullets; }
	class ENEMY_BULLETS* enemyBullets() { return EnemyBullets; }
	class HP_GAUGE* hpgauge() { return HpGauge; }

public:
	GAME();
	~GAME();
	void run();
	void changeScene(SCENE_ID sceneId);
};

