#include "GameEngine.h"
#include "Renderer.h"



int main(){
	GameEngine game;
	Renderer renderer;
	game.LoadGame();
	renderer.run(game);
	return 0;
}