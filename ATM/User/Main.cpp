#include <Main.h>


const string MENU_TEXT1[3]={
	"1.�������п�",
	"2.�������п�",
	"3.�˳�",
};

int main()
{
	ATM atm;
	Initial();
	//Gotoxy(10, 10);
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),);
	//int result = MessageBox( NULL , TEXT("���ǶԻ���") , TEXT("���") , MB_ICONINFORMATION|MB_YESNO);
	while(1)
	{
		switch(atm.Welcome()){
		case 1:break;
		case 2:atm.ApplyBankCard();break;
		case 3:exit(0);break;

		}
		system("pause");
	}
}

void Initial()
{
	system("title ATM��");
	system("mode con cols=60 lines=25");
	system("color 0B");
	
	
	//system("date /T");
	//system("TIME /T");
}