#pragma once
#include <fstream>

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
		file.open("save.txt", std::ios::in);
		file >> m_health;
		file >> m_damage;
		file.close();
	}

private:
	float m_health;
	float m_damage;
};

