#pragma once

#include <Main.h>

class Card
{

private:
	string card_num;
	string password;
	string name;
	string IDcard_num;
	int money;

public:
	Card();
	//void SaveCrad();


friend class ATM;
};