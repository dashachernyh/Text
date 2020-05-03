#include<fstream>
#include<string>
using namespace std;
#include"TTextLink.h"
#include"TStack.h"
#include"TText.h"

TText::TText()
{
	pFirst = NULL;
	Stack.ClearSt();
}
TTextLink* TText::GetpCurr()
{
	return pCurr;
}
void TText::GoFirstLink()
{
	pCurr = pFirst;
	Stack.ClearSt();
}
void TText::GoNextLink()
{

	if (!pCurr) throw - 1;
	if (pCurr->pNext == NULL) return;
	Stack.Push(pCurr);
	pCurr = pCurr->pNext;
}
void TText::GoDownLink()
{
	if (!pCurr) throw - 1;
	if (pCurr->pDown == NULL) return;
	Stack.Push(pCurr);
	pCurr = pCurr->pDown;
}
void TText::GoPrevLink()
{
	if (pCurr == NULL) throw - 1;
	if (Stack.IsEmpty()) return;
	pCurr = Stack.Pop();
}
void TText::SetLink(string str1)
{
	if (!pCurr) throw - 1;
	strcpy_s(pCurr->str, str1.c_str());
}
string TText::GetLink()
{
	return string(pCurr->str);
}
void TText::InsNextLine(string str1)
{
	if (!pCurr) throw - 1;
	TTextLink *p = new TTextLink (str1.c_str());
	p->pNext = pCurr->pNext;
	pCurr->pNext = p;
}
void TText::InsNextSect(string str1)
{
	if (!pCurr) throw - 1;
	TTextLink *p =new TTextLink(str1.c_str());
	p->pDown = pCurr->pNext;
	pCurr->pNext = p;
}
void TText::InsDownLine(string str1)
{
	if (!pCurr) throw - 1;
	TTextLink *p = new TTextLink(str1.c_str());
	p->pNext = pCurr->pDown;
	pCurr->pDown = p;
}
void TText::InsDownSect(string str1)
{
	if (!pCurr) throw - 1;
	TTextLink *p = new TTextLink(str1.c_str());
	p->pDown = pCurr->pDown;
	pCurr->pDown = p;
}
void TText::DelNext()
{
	if (!pCurr) throw - 1;
	if (!pCurr->pNext) return;
	TTextLink *p = pCurr->pNext;
	pCurr->pNext = p->pNext;
	delete p;
}
void TText::DelDown()
{
	if (!pCurr) throw - 1;
	if (!pCurr->pDown) return;
	TTextLink *p = pCurr->pDown;
	pCurr->pDown = p->pNext;
	delete p;
}
   //чтение текста из файла
void TText::Read(string fn)
{
	ifstream ifs(fn);
	pFirst = ReadRec(ifs);
}
   //чтение текста из файла
TTextLink* TText::ReadRec(ifstream& ifs)
{
	TTextLink *pHead, *p;
	pHead=new TTextLink;
	pHead = NULL;
	p = NULL;
	char str[81];
	while (!ifs.eof())
	{
		ifs.getline(str, 80, '\n');
		if (str[0] == '}') break;
		else
			if (str[0] == '{')
				p->pDown = ReadRec(ifs);
			else
			{
				TTextLink *tmp = new TTextLink(str);
				if (pHead == NULL)
					pHead = p = tmp;
				else
				{
					p->pNext = tmp;
					p = p->pNext;
				}
			}
	}
	return pHead;
}
    //сохранение текста в файл
void TText:: Write(string fn)
{
	while (!Stack.IsEmpty()) Stack.Pop();
	ofstream ofs(fn);
	WriteRec(ofs, pFirst);

}
   //сохранение текста в файл
void TText::WriteRec(ofstream& ofs, TTextLink *p)
{
	if (p)
	{ 
		string s;
		int tab = Stack.Size();
		for (int i = 0; i < tab; i++)  s +=' ';
		s += p->str;
		ofs << s << endl;
		if (p->pDown)
		{
			ofs << '{' << endl;
			Stack.Push(p);
			WriteRec(ofs, p->pDown);
			Stack.Pop();
			ofs << '}' << endl;
		}
		if (p->pNext)
			WriteRec(ofs, p->pNext);
	}
}
//итераторы
int TText::Reset()
{
	while (!Stack.IsEmpty()) Stack.Pop();
	pCurr = pFirst;
	if (pCurr != NULL)
	{
		Stack.Push(pCurr);
		if (pCurr->pNext != NULL) Stack.Push(pCurr->pNext);
		if (pCurr->pDown != NULL) Stack.Push(pCurr->pDown);
	}
	return IsEnd();
}
int TText::IsEnd()
{
	return !Stack.Size();
}
int TText::GoNext()
{
	if (!IsEnd())
	{
		pCurr = Stack.Top();
		Stack.Pop();
		if (pCurr != pFirst)
		{
			if (pCurr->pNext != NULL) Stack.Push(pCurr->pNext);
			if (pCurr->pDown != NULL) Stack.Push(pCurr->pDown);
		}
		return true;
	}
	return false;
}

void TText::Print(TTextLink *p,TTextLink *curr)
{

	if (p)
	{
		string s;
		int tab = Stack.Size();
		for (int i = 0; i < tab; i++)  s += ' ';
		s += p->str;
		if (curr == p) cout << "/pCurr/ " << s << endl;
		else cout<<"/-----/ "<<s<< endl;
		if (p->pDown)
		{
			//cout << '{' << endl;
			Stack.Push(p);
			Print(p->pDown,curr);
			Stack.Pop();
			//cout << '}' << endl;
		}
		if (p->pNext)
			Print(p->pNext,curr);
	}
	pCurr = curr;
}