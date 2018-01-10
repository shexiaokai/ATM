#pragma once

#include "Main.h"

class Menu
{

private:
	const int choose_num;
	const string* pstr;
	const int row_spacing;

	POINT datum_point;
	int now_choose;

	void PrintErasureArrow(bool=true)		const;
	void PrintAllChoose(void)				const;

public:
	Menu(int,const string*,POINT,int=1);
	Menu(int,const string*,RECT,int=1);
	~Menu(void);
	
	int MenuSelect(void);

};

