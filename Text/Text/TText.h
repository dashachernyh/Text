#pragma once
#include<fstream>
#include"TTextLink.h"
#include"TStack.h"
#include<string>
using namespace std;
class TText
{
private:
	TTextLink *pFirst, *pCurr;
	TStack <TTextLink*> Stack;
public:
	TText();
	~TText() {};
	TTextLink* GetpCurr();
	void GoFirstLink();   //перейти на первую строку
	void GoNextLink();   //перейти на следующий раздел в том же уровне
	void GoDownLink();   //перейти на следующий подуровень
	void GoPrevLink();   //вернутся на предыдущую строку
	void SetLink(string str1);   //записать строку на текущую поз
	string GetLink();    //получить текущую строку
	void InsNextLine(string str1);   //вставить следующую строку в этом же уровне
	void InsNextSect(string str1);   //вставить раздел в том же уровне
	void InsDownLine(string str1);   //вставить строку в том же подуровне
	void InsDownSect(string str1);   //вставить раздел в том же подуровне
	void DelNext();   //удаление строки на том же уровне
	void DelDown();   //удаление раздела на том же уровне
	void Read(string fn);   //ввод текста из файла
	TTextLink* ReadRec(ifstream &ifs);   //ввод
	void Write(string fn);   //вывод текста в файл 
	void WriteRec(ofstream &ofs, TTextLink *p);   //вывод
	//итераторы
	int Reset();   //установить на первую запись
	int IsEnd();   //конец ?
	int GoNext();   //переход к след записи
	void Print(TTextLink *p,TTextLink *curr);
};