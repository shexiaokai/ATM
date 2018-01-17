#include <Main.h>


const string MENU_TEXT1[3]={
	"1.插入银行卡",
	"2.申请银行卡",
	"3.退出",
};

const string MENU_TEXT2[5]={
	"1.存钱",
	"2.取钱",
	"3.转账",
	"4.查看细明",
	"5.退卡",
};

int main()
{
	ATM atm;
	Initial();
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
	system("title ATM机");
	system("mode con cols=60 lines=25");
	system("color 0B");
	
	
	//system("date /T");
	//system("TIME /T");
}