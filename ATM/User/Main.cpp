#include <Main.h>


const string MENU_TEXT1[3]={
	"1.�������п�",
	"2.�������п�",
	"3.�˳�",
};

const string MENU_TEXT2[5]={
	"1.��Ǯ",
	"2.ȡǮ",
	"3.ת��",
	"4.�鿴ϸ��",
	"5.�˿�",
};

int main()
{
	ATM atm;
	Initial();
	time_t t = time(0); 
    char tmp[32]={NULL};
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&t)); 
    cout<<tmp<<endl;
	_getch();
	//Gotoxy(10, 10);
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),);
	//int result = MessageBox( NULL , TEXT("���ǶԻ���") , TEXT("���") , MB_ICONINFORMATION|MB_YESNO);
	while(1)
	{
		switch(atm.Welcome()){
		case 1:atm.OperatingBankCard();break;
		case 2:atm.ApplyBankCard();break;
		case 3:exit(0);break;
		}
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