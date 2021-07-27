#include"libOne.h"
#include "TITLE.h"
#include "GAME.h"
#include"CONTAINER.h"
TITLE::TITLE(class GAME* game):
    SCENE(game){
}
TITLE::~TITLE() {
}
void TITLE::create(){
	Title = game()->container()->title();
}
void TITLE::draw(){
	clear(Title.backColor);
	textSize(Title.textSize);
	fill(Title.textColor);
	text(Title.str,Title.pos.x, Title.pos.y);
	//print("title");
}
void TITLE::nextScene(){
	if (isTrigger(KEY_Z)) {
	    game()->changeScene(GAME::STAGE_ID);
	}
}