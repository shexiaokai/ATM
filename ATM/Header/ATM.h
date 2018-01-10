#pragma once

#include <Main.h>

class Card;

class ATM{
private:
	void ApplyInterface()		const;
	string GetIDNum()			const;
	string GetPassword()		const;
	void SaveCardMessage(Card*)	const;
public:
	ATM(void);
	int Welcome();
	void ApplyBankCard();
	

};
