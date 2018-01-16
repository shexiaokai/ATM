#pragma once

#include <Main.h>

class Card;

class ATM{
private:
	Card* pcard;
	void ApplyInterface()		const;
	string GetIDNum()			const;
	string GetCardNum()			const;
	string GetPassword()		const;
	string MakeCardNum()		const;
	void SaveMoney();
	void SaveCardMessage()		const;
	int OperatingSelect()		const;		
	bool SearchCard();
	void AddMessage(string)		const;

public:
	ATM(void);
	int Welcome();
	void ApplyBankCard();
	void OperatingBankCard();
	
};
