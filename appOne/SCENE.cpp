#include "SCENE.h"
SCENE::SCENE(class GAME* game) ://���̎O�s
	GAME_OBJECT(game) {//���N���X�̃R���X�g���N�^
}//�̌Ăяo�����@

SCENE::~SCENE(){}
void SCENE::create(){}
void SCENE::init(){}
void SCENE::proc(){
	update();
	draw();
	nextScene();
}
void SCENE::update(){}
void SCENE::draw(){}
void SCENE::nextScene(){}