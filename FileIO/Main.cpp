#include <iostream>
#include <fstream>
#include "Character.h"

int main()
{
	Character player = Character();
	player.health = 100;
	player.damage = 5;


	/////Example of saving to a text file/////

	//create instance of file to stream
	std::fstream file;

	/*search for file with name given in the first argument, 
	if no file with this name exists, one is created.
	Then std::ios::out is used to say that we want to output data to that text file*/
	file.open("save.txt", std::ios::out);

	//check if the file isn't open. If so, return to main
	if (!file.is_open())
		return 1;

	//writes player stats to text file
	file << player.health << std::endl;
	file << player.damage;

	//close the file when we're done
	file.close();


	/////Example of loading from a text file/////
	Character player2 = Character();

	/*Search for ffile that has the given name.
	The std::ios::in is used to say that we want input from this file.*/
	file.open("save.txt", std::ios::in);

	//check if the file isn't open. If so, return to main
	if (!file.is_open())
		return 1;

	//reads player stats from text file
	file >> player2.health;
	file >> player2.damage;

	//close file when done
	file.close();

	std::cout << player2.health << std::endl;
	std::cout << player2.damage << std::endl;

	return 0;
}
