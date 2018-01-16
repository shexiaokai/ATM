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
	pcard=new Card;
	ApplyInterface();
	Gotoxy(12,6);
	cin>>pcard->name;
	Gotoxy(12,9);
	cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
	Gotoxy(12,9);
	pcard->IDcard_num=GetIDNum();
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
	pcard->card_num=MakeCardNum();
	system("cls");
	cout<<"\n\n\n\t\t申请成功！\n\n\t\t您的卡号为:\n\n\t\t"\
		<<pcard->card_num<<"\n\n\t\t";
	SaveCardMessage();
	delete pcard;
	pcard=NULL;
	assert(pcard==NULL);
	system("pause");
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

string ATM::GetCardNum()		const
{
	string CardNum(17,0);
	char ch;
	int i=0;
	while(1)
	{
		ch=_getch();
		if(ch==13&&i==16)
		{
			break;
		}
		else if(ch>='0'&&ch<='9'&&i<16)
		{
			if(i==15)
				cout<<ch;
			else
				cout<<ch<<" ";
			CardNum[i]=ch;
			i++;
		}
		else if(ch==8&&i>0)
		{
			cout<<"\b\b_\b";
			CardNum[i]=0;
			i--;
		}
	}
	return CardNum;
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

string ATM::MakeCardNum()				const
{
	char num[5]={0};
	string str;
	srand((U8)time(0));
	for(int i=0;i<4;i++)
	{
		sprintf(num,"%04d",rand()%10000);
		str+=num;
	}
	return str; 
}

void ATM::SaveCardMessage()	const
{
	fstream file;
	
	file.open("Document\\CardList.txt",ios::app);
	file<<"*"<<pcard->card_num<<endl;
	file<<pcard->password<<endl;
	file<<pcard->name<<endl;
	file<<pcard->IDcard_num<<endl;
	file<<"0"<<endl<<'#'<<endl<<endl;
	file.close();
}

void ATM::OperatingBankCard()
{
	bool back=false;
	pcard=new Card;
	do
	{
		system("cls");
		Gotoxy(12,8);
		cout<<"请输入您的卡号：";
		Gotoxy(12,9);
		cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
		Gotoxy(12,9);
		pcard->card_num=GetCardNum();
	}while(!SearchCard());

	while(!back)
		switch(OperatingSelect())
		{
			case 1:SaveMoney();break;
			case 5:back=true;break;
		}
	delete pcard;
	pcard=NULL;
}

int ATM::OperatingSelect()	const
{
	int choose;
	RECT *a=new RECT;
	a->left=0;
	a->right=60;
	a->top=0;
	a->bottom=25;
	system("cls");
	Menu *pmenu1=new Menu(5,MENU_TEXT2,*a,2);
	delete a;
	a=NULL;
	assert(a==NULL);
	choose=pmenu1->MenuSelect();
	delete pmenu1;
	pmenu1=NULL;
	assert(pmenu1==NULL);
	assert(choose>0&&choose<=5);
	return choose;
}

bool ATM::SearchCard()
{
	bool search =false;
	char ch;
	fstream file;
	file.open("Document\\CardList.txt");
	while(!search)
	{
		if(!file.get(ch))
			break;
		else if(ch=='*')
		{
			string str(17,0);
			for(int i=0;i<16;i++)
			{
				file.get(ch);
				str[i]=ch;
			}
			if(str==pcard->card_num)
				search=true;
		}
	}
	if(!search)
	{
		MessageBox( NULL , TEXT("查无此卡") , TEXT("错误！") , MB_ICONINFORMATION);
	}
	else
	{
		file.get(ch);
		file>>pcard->password;
		file>>pcard->name;
		file>>pcard->IDcard_num;
		file>>pcard->money;
	}
	file.close();
	return search;

}

void ATM::SaveMoney()
{
	int m=0;
	system("cls");
	cout<<"\n\n\n\t\t请输入您要存入的金额：\n\n\t\t";
	cin>>m;
	cout<<"\n\n\t\t您已存入"<<m<<"元人民币"<<"\n\n\t\t";
	system("pause");
	pcard->money+=m;

	time_t t = time(0); 
    char tmp[33]={NULL};
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&t)); 
	char num[10]={NULL};
	sprintf(num,"%d",m);
	string str=tmp;
	str+="  ";
	str+="存入";
	str+=num;
	str+="元";
	AddMessage(str);

}

void ATM::AddMessage(string str1)	const
{
	char ch;
	fstream file;
	file.open("Document\\DataList.txt",ios::app);
	file<<"*"<<pcard->card_num<<endl;
	file<<str1<<endl;
	file.close();
}
