#pragma once
#include <fstream>
#include <iostream>

class Character
{
public:
	Character();
	Character(float health, float damage);

	void attack(Character* other);
	float takeDamage(float damageAmount);

	float getDamage() { return m_damage; }
	float getHealth() { return m_health; }

	void loadStats() 
	{
		std::fstream file;
		file.open("save.txt", std::ios::in | std::ios::binary);
		if (!file.is_open())
		{
			while (!file.eof() && file.peek() != EOF)
			{
				file.read((char*)&Character(), sizeof(Character));
				std::cout << "Health: " << m_health << std::endl << "Damage: " << m_damage << std::endl << std::endl;
			}
			file.close();
		}
	}

private:
	float m_health;
	float m_damage;
};

