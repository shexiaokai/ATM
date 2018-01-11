#pragma once

#include <Main.h>

class Card;

class ATM{
private:
	void ApplyInterface()		const;
	string GetIDNum()			const;
	string GetCardNum()			const;
	string GetPassword()		const;
	string MakeCardNum()		const;
	void SaveMoney();
	void SaveCardMessage(Card*)	const;
	int OperatingSelect()		const;		
	bool SearchCard(Card*);

public:
	ATM(void);
	int Welcome();
	void ApplyBankCard();
	void OperatingBankCard();
	
};
