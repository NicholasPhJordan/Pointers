#include "Game.h"
#include <iostream>
#include <fstream>

void Game::run()
{
	start();

	while (!getGameOver())
	{
		update();
		draw();

		system("pause");
	}

	end();
}

void Game::start()
{
	int input = 0; //creates an input variable and sets it to zero
	std::fstream file; //creates instance of file stream

	//checks if player has played before 
	std::cout << "Have you player before?" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
	while (input != 1 && input != 2)
	{
		input = 0;
		std::cin >> input;
		if (input == 1)
		{
			m_player1 = new Character(10, 10);
			m_player1->loadStats();
			std::cout << m_player1->getHealth() << std::endl;
			std::cout << m_player1->getDamage() << std::endl;
			system("pause");
			system("cls");
		}
		else if (input == 2)
		{
			std::cout << "Choose your class." << std::endl;
			std::cout << "1. Knight" << std::endl;
			std::cout << "2. Rogue" << std::endl;
			std::cout << "3. Mage" << std::endl;
			input = 0;
			while (input != 1 && input != 2 && input != 3)
			{
				input = 0;
				std::cin >> input;
				if (input == 1)  //makes new character with knight stats
				{
					m_player1 = new Character(100, 10);
					std::cout << "You chose the Knight!" << std::endl;
					system("pause");
					system("cls");
				}
				else if (input == 2)  //makes new character with rogue stats
				{
					m_player1 = new Character(90, 15);
					std::cout << "You chose the Rogue!" << std::endl;
					system("pause");
					system("cls");
				}
				else if (input == 3)  //makes new charcter with mage stats
				{
					m_player1 = new Character(80, 20);
					std::cout << "You chose the Mage!" << std::endl;
					system("pause");
					system("cls");
					input = 2;
				}
				else  //when you cant count to 3
				{
					std::cout << "Wrong choice! Try again!" << std::endl;
				}
			}
			//saves player information 
			file.open("save.txt", std::ios::out);
			if (!file.is_open())
			{
				return setGameOver(true);
			}
			file << m_player1->getHealth() << std::endl;
			file << m_player1->getDamage();
			file.close();
		}
	}

	m_enemy1 = new Character(50, 10);
}

void Game::update()
{
	system("cls");

	std::cout << "Health: " << m_player1->getHealth() << "          " << "Enemy Health: " << m_enemy1->getHealth() << std::endl; //prints player and enemy health
	std::cout << "" << std::endl;
	std::cout << "Press 1 to Attack!" << std::endl; //tells the player to attack and waits for input
	int input = 0;
	while (input != 1)
	{
		input = 0;
		std::cin >> input;
		if (input == 1)
		{
			m_player1->attack(m_enemy1);
		}
		else
		{
			std::cout << "Try again!" << std::endl;
		}
	}
	m_enemy1->attack(m_player1); //enemy attacks
}

void Game::draw()
{
	std::cout << "The enemy took " << m_player1->getDamage() << " damage!" << std::endl;  //tells how much damage the player delt
	std::cout << "The enemy attacks you for " << m_enemy1->getDamage() << " damage!" << std::endl;  //tells how much the enemy attacks 
	std::cout << "" << std::endl;
	//checks if player or enemy helth is less than or equal to 0
	if (m_player1->getHealth() <= 0)
	{
		std::cout << "YOU DIED!" << std::endl;;
		std::cout << "" << std::endl;
		setGameOver(true);
	}
	else if (m_enemy1->getHealth() <= 0)
	{
		std::cout << "YOU WON!!" << std::endl;;
		std::cout << "" << std::endl;
		setGameOver(true);
	}
}

void Game::end()
{
	delete m_player1;
	delete m_enemy1;
}