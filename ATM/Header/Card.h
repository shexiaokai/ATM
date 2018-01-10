#pragma once

#include <Main.h>

class Card
{

private:
	string card_num;
	string password;
	string name;

public:
	Card();
	//void SaveCrad();


friend class ATM;
};