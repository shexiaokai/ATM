#include <ATM.h>

const string APPLY_TEXT[4]={
	"请输入您的真实姓名：",
	"请输入您的身份证号：",
	"请设置你的密码：",
	"请确定您的密码：",
};

ATM::ATM(void)
{
	;
}

int ATM::Welcome()
{
	int choose;
	RECT *a=new RECT;
	a->left=0;
	a->right=60;
	a->top=0;
	a->bottom=25;
	system("cls");
	Menu *pmenu1=new Menu(3,MENU_TEXT1,*a,3);
	delete a;
	a=NULL;
	assert(a==NULL);
	choose=pmenu1->MenuSelect();
	delete pmenu1;
	pmenu1=NULL;
	assert(pmenu1==NULL);
	return choose;
}

void ATM::ApplyBankCard()
{
	bool password_same=false;
	Card *pcard=new Card;
	ApplyInterface();
	Gotoxy(12,6);
	cin>>pcard->name;
	Gotoxy(12,9);
	cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
	Gotoxy(12,9);
	pcard->card_num=GetIDNum();
	while(!password_same)
	{
		Gotoxy(12,12);
		cout<<"_ _ _ _ _ _";
		Gotoxy(12,15);
		cout<<"_ _ _ _ _ _";
		Gotoxy(12,12);
		string ps1=GetPassword();
		Gotoxy(12,15);
		string ps2=GetPassword();
		if(ps1==ps2)
		{
			password_same=true;
			pcard->password=ps1;
		}
		else
			MessageBox( NULL , TEXT("两次密码不一致！") , TEXT("错误！") , MB_ICONINFORMATION);
	}
	
	SaveCardMessage(pcard);
	delete pcard;
	pcard=NULL;
	assert(pcard==NULL);
}

void ATM::ApplyInterface()	const
{
	system("cls");
	for(int i=0;i<4;i++)
	{
		Gotoxy(12,5+i*3);
		cout<<APPLY_TEXT[i];
	}
}

string ATM::GetIDNum()		const
{
	string idNum(19,0);
	char ch;
	int i=0;
	while(1)
	{
		ch=_getch();
		if(ch==13&&i==18)
		{
			break;
		}
		else if((ch=='x'||ch=='X')&&i==17)
		{
			cout<<'X';
			idNum[i]='X';
			i++;
		}
		else if(ch>='0'&&ch<='9'&&i<18)
		{
			if(i==17)
				cout<<ch;
			else
				cout<<ch<<" ";
			idNum[i]=ch;
			i++;
		}
		else if(ch==8&&i>0)
		{
			cout<<"\b\b_\b";
			idNum[i]=0;
			i--;
		}
	}
	return idNum;
}

string ATM::GetPassword()	const
{
	string password(7,0);
	char ch;
	int i=0;
	while(1)
	{
		ch=_getch();
		if(ch==13&&i==6)
		{
			break;
		}
		else if(ch>='0'&&ch<='9'&&i<6)
		{
			if(i==17)
				cout<<"*";
			else
				cout<<"*"<<" ";
			password[i]=ch;
			i++;
		}
		else if(ch==8&&i>0)
		{
			cout<<"\b\b_\b";
			password[i]=0;
			i--;
		}
	}
	return password;
}

void ATM::SaveCardMessage(Card *pcard)	const
{
	fstream file;
	file.open("Document\\CardList.txt",ios::app);
	file<<"*"<<pcard->card_num<<endl;
	file<<pcard->password<<endl;
	file<<pcard->name<<endl;
	file.close();


}