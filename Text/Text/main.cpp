#include<string>
#include<fstream>
#include<conio.h>
#include<iostream>
using namespace std;
#include"TText.h"
#include"TTextLink.h"
TTextMem TTextLink::MemHeader;
int main()
{
	TTextLink::InitMemSystem();
	TText txt;
	TTextLink *p;
	string str1;
	int key=0;
	txt.Read("fi.txt");
	txt.GoFirstLink();
	
	while (key != 50) {
		cout << "1 - add line to current level" << endl << "2 - add section to current level" << endl << "3 - add line to current sublevel" << endl << "4 - add section to current sublevel" << endl << "11 - delete line/section to current level" << endl << "21 - delete line/section to current sublevel" <<endl << "5 - go to first section" << endl << "6 - go to next section " << endl << "7 - go to down line" << endl << "8 - back to previous line" << endl << "9 -set line to current pos" << endl << "10 - print current line" << endl << "20-print" << endl << "50 - exit" << endl;
		cin >> key;
		switch (key)
		{
		case 1:
		{
			cout << "enter string" << endl;
			cin >> str1;
			txt.InsNextLine(str1); break;
		}
		case 2:
		{
			cout << "enter string" << endl;
			cin >> str1;
			txt.InsNextSect(str1); break;
		}
		case 3:
		{
			cout << "enter string" << endl;
			cin >> str1;
			txt.InsDownLine(str1); break;
		}
		case 4:
		{
			cout << "enter string" << endl;
			cin >> str1;
			txt.InsDownSect(str1); break;
		}
		case 11: 
		{
			txt.DelNext(); break;
		}
		case 21:
		{
			txt.DelDown(); break;
		}
		case 5:
		{
			txt.GoFirstLink(); break;
		}
		case 6:
		{
			txt.GoNextLink(); break;
		}
		case 7:
		{
			txt.GoDownLink(); break;
		}
		case 8:
		{
			txt.GoPrevLink(); break;
		}
		case 9:
		{
			cout << "enter string" << endl;
			cin >> str1;
			txt.SetLink(str1); break;
		}
		case 10:
		{
			cout << txt.GetLink()<<endl;
			 break;
		}
		case 20:
		{
			txt.GoFirstLink();
			p = txt.GetpCurr();
			txt.Print(p); break;
		}
		
		}
	}
	TTextLink::PrintFreeLink();
	TTextLink::MemCleaner(txt);
	TTextLink::PrintFreeLink();
	_getch();
}