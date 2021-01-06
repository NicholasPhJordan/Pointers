#include <iostream>
#include <fstream>
#include "Character.h"

bool binaryFileExample()
{
	//Initialize charcaters 
	Character sbeve = Character();
	sbeve.health = 100;
	sbeve.damage = 12;
	Character sbeve2 = Character();
	sbeve2.health = 110;
	sbeve2.damage = 13;
	Character sbeve3 = Character();
	sbeve3.health = 111;
	sbeve3.damage = 13;

	//Create instance of file stream
	std::fstream file;

	//Open wanted file to save to
	file.open("save2.txt", std::ios::out | std::ios::binary);

	//checks if the file open before usuing 
	if (!file.is_open())
		return false;

	//writes all characters to file
	file.write((char*)&sbeve, sizeof(Character));
	file.write((char*)&sbeve2, sizeof(Character));
	file.write((char*)&sbeve3, sizeof(Character));

	//closes file once writing is complete
	file.close();

	//create a character to store the loaded data
	Character sbeve4 = Character();

	//open file to load from
	file.open("save2.txt", std::ios::in | std::ios::binary);

	//check to see if the file is open
	if (!file.is_open())
		return false;

	//position marker to two characters away from beginning
	file.seekg(sizeof(Character) * 2, std::ios::beg);

	//set character to be the value read from the file
	file.read((char*)&sbeve4, sizeof(Character));

	//prints results
	std::cout << sbeve4.health << std::endl;
	std::cout << sbeve4.damage << std::endl;
	system("pause");

	//close file
	file.close();
	return true;
}

int main()
{
	binaryFileExample();

	//Character player = Character();
	//player.health = 100;
	//player.damage = 5;


	///////Example of saving to a text file/////

	////create instance of file to stream
	//std::fstream file;

	///*search for file with name given in the first argument, 
	//if no file with this name exists, one is created.
	//Then std::ios::out is used to say that we want to output data to that text file*/
	//file.open("save.txt", std::ios::out);

	////check if the file isn't open. If so, return to main
	//if (!file.is_open())
	//	return 1;

	////writes player stats to text file
	//file << player.health << std::endl;
	//file << player.damage;

	////close the file when we're done
	//file.close();


	///////Example of loading from a text file/////
	//Character player2 = Character();

	///*Search for ffile that has the given name.
	//The std::ios::in is used to say that we want input from this file.*/
	//file.open("save.txt", std::ios::in);

	////check if the file isn't open. If so, return to main
	//if (!file.is_open())
	//	return 1;

	////reads player stats from text file
	//file >> player2.health;
	//file >> player2.damage;

	////close file when done
	//file.close();

	//std::cout << player2.health << std::endl;
	//std::cout << player2.damage << std::endl;

	return 0;
}
