#include "Menu.h"

Menu::Menu(int n,const string* p,POINT point,int row):\
choose_num(n),pstr(p),datum_point(point),row_spacing(row),now_choose(0)
{
	PrintAllChoose();
}

Menu::Menu(int n,const string* p,RECT rc,int row):\
choose_num(n),pstr(p),row_spacing(row),now_choose(0)
{
	int str_max=0;
	int str_long;
	assert(rc.right>rc.left&&rc.bottom>rc.top);
	HideCursor();

	for(int i=0;i<n;i++)
		str_max = str_max>(str_long=(p+i)->length())? str_max:str_long;
	datum_point.x=(rc.right-rc.left)/2+rc.left-str_max/2;
	datum_point.y=(rc.bottom-rc.top)/2+rc.top-(n+(n-1)*row)/2;
	PrintAllChoose();
	PrintErasureArrow();

}

Menu::~Menu(void)
{
	HideCursor(true);
}

void Menu::PrintAllChoose(void) const
{
	
	for(int i=0;i<choose_num;i++)
	{

		Gotoxy(datum_point.x,datum_point.y+i*(1+row_spacing));
		cout<<*(pstr+i);
	}
}

void Menu::PrintErasureArrow(bool pore)		const
{
	Gotoxy(datum_point.x-3,datum_point.y+now_choose*(1+row_spacing));
	if(pore)
		cout<<"->";
	else
		cout<<"  ";
}

int Menu::MenuSelect(void)
{
	U8 ch;
	int select=0;
	while(!select)
	{
		ch=_getch();
		if(ch==13);
		else if(ch<224)
			continue;
		else
			ch=_getch();
		
		switch(ch)
		{
			case 72:
				PrintErasureArrow(false);
				if(now_choose==0) 
					now_choose=choose_num-1; 
				else 
					now_choose--; 
				PrintErasureArrow();
				break;

			case 80:
				PrintErasureArrow(false);
				if(now_choose==choose_num-1) 
					now_choose=0; 
				else 
					now_choose++; 
				PrintErasureArrow();
				break;

			case 13:
				select=now_choose+1;
				break;
		}
	}
	assert(select>0&&select<choose_num+1);
	return select;
}