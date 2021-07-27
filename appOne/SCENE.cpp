#include "SCENE.h"
SCENE::SCENE(class GAME* game) ://この三行
	GAME_OBJECT(game) {//基底クラスのコンストラクタ
}//の呼び出し文法

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