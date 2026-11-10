#include "GameEngine.h"
#include "Renderer.h"
#include <ctime>
#include <cstdlib>



int main(){
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	GameEngine game;
	Renderer renderer;

	renderer.mainMenu(game);
	return 0;
}