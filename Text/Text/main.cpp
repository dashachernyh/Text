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
	TTextLink *p, *m;
	string str1;
	char key='0';
	txt.Read("fi.txt");
	txt.GoFirstLink();
	m = txt.GetpCurr();
	while (key != '6') 
	{
		cout << ">, ^, 1-Down, 2- Add, 3- Del, 4- Wtire/Read, 5 - Print, 6 - Exit  " << endl;
		cin >> key;
		switch (key)
		{
		case '>':
		{
			txt.GoDownLink();
			break;
		}
		case '1':
		{
			txt.GoNextLink();
			break;
		}
		case'^':
		{
			txt.GoPrevLink();
			break;
		}
		case '2':
		{
			char k1;
			cout << "1 - ins current pos, 2 - ins next line, 3 - ins down line, 4 - ins next section, 5 - ins down section" << endl;
			cin >> k1;
			switch (k1)
			{
				case '1':
				{
					cout << "enter string"<<endl;
					cin >> str1;
					txt.SetLink(str1); break;
				}
				case '2':
				{
					cout << "enter string"<<endl;
					cin >> str1;
					txt.InsNextLine(str1); break;
				}
				case '3':
				{
					cout << "enter string"<<endl;
					cin >> str1;
					txt.InsDownLine(str1); break;
				}
				case '4':
				{
					cout << "enter string"<<endl;
					cin >> str1;
					txt.InsNextSect(str1); break;
				}
				case '5':
				{
					cout << "enter string"<<endl;
					cin >> str1;
					txt.InsDownSect(str1); break;
				}
			
			}
			break;
		}
		case '3':
		{
			int k;
			cout << "1-delete line/section to current level, 2 - delete line/section to current sublevel" << endl; 
			cin >> k;
			switch (k)
			{
			case 1: txt.DelNext(); break;
			case 2: txt.DelDown(); break;
			}
			break;
		}
		case '4':
		{
			int k2;
			cout << "1 - read from file, 2 - write to file" << endl;
			cin >> k2;
			switch (k2) 
			{
			case 1: txt.Read("fi.txt"); break;
			case 2: txt.Write("fi.txt"); break;
			}
			break;

		}
		case '5':
		{
			p = txt.GetpCurr();
			txt.Print(m, p);
			break;
		}
	
		}
	}
	cout << "Last printing" << endl;
	TTextLink::PrintFreeLink();
	TTextLink::MemCleaner(txt);
	cout << "aftre memleaner" << endl;
	TTextLink::PrintFreeLink();
	
	_getch();
}