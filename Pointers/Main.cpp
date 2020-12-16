#include <iostream>
#include "Game.h"

void changeNumber(int& num) {
	num = 5;
}

int main()
{
	int number = 2;
	int& numberReference = number;
	numberReference = 5;
	std::cout << number << std::endl;
	changeNumber(number);
	std::cout << number << std::endl;
	system("pause");
	Game game = Game();
	game.run();
	return 0;
}