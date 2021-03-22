#include "SceneGame.h"
#include "singletons.h"

SceneGame::SceneGame() : Scene() {

}

SceneGame::~SceneGame() {

}

void SceneGame::preLoad() {

}

void SceneGame::unLoad() {

}

void SceneGame::init() {
	sprite_id = sResManager->getSpriteID("assets/sanic.png");
	sprite_rect = C_Rectangle{ 0, 0, 78, 82 };
	sprite_frame = 0;
	sprite_frame_time = 0;
	
		
	rect2 = C_Rectangle{ 0, 0, sResManager->getSpriteWidth(sprite_id), sResManager->getSpriteHeight(sprite_id) };
}

void SceneGame::enterScene()
{
}

void SceneGame::updateBegin() {
	sprite_frame_time += global_delta_time;
	if (sprite_frame_time > 100) {
		sprite_frame_time = 0;
		sprite_frame++;
		if (sprite_frame >= 8) {
			sprite_frame = 0;
		}
		sprite_rect.x = sprite_rect.w * sprite_frame;
	}
}

void SceneGame::update() {
	sprite_rect.y = 0;
	if (sInput->isKeyPressed(Input::KEY_A)) {
		std::cout << "A PRESSED" << std::endl;
	}
	if (sInput->isKeyDown(Input::KEY_A)) {
		std::cout << "A DOWN" << std::endl;
		sprite_rect.y = sprite_rect.h;
	}
	if (sInput->isKeyReleased(Input::KEY_A)) {
		std::cout << "A RELEASED" << std::endl;
	}

	if (sInput->isKeyPressed(Input::BACKSPACE)) {
		sDirector->goBack(); //FALSE PARA QUE NO SE REINICIE LA ESCENA Y SE MANTENGA COMO ESTABA
	}

}

void SceneGame::updateEnd() {

}

void SceneGame::renderBegin() {

}

void SceneGame::render() {
	sRenderer->drawSprite(sprite_id, 50, 50, sprite_rect);
	sRenderer->drawSprite(sprite_id, 50, 250, rect2);
}

void SceneGame::renderEnd() {

}

void SceneGame::renderGUI() {

}
