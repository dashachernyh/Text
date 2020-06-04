#pragma once
#include<fstream>
#include"TTextLink.h"
#include"TStack.h"
#include<string>
using namespace std;

class TText
{
protected:
	TTextLink *pFirst;   //указатель на первое звено
	TTextLink *pCurr;    //указатель на текущее
	TStack <TTextLink*> Stack;  //стек для итератора

	void WriteRec(ofstream &ofs, TTextLink *p);   //вывод
	TTextLink* ReadRec(ifstream &ifs);   //ввод
public:
	TText();  //конструктор
	~TText() {};  //деструктор
	//доступ
	TTextLink* GetpCurr();  //получить текущую запись
	void SetLink(string str1); //записать строку на текущую поз
	string GetLink();    //получить значение текущей строки
	//навигация
	void GoFirstLink();  //перейти на первую строку
	void GoNextLink();   //перейти на следующий раздел в том же уровне
	void GoDownLink();   //перейти на следующий подуровень
	void GoPrevLink();   //вернутся на предыдущую строку
	//модификация
	void InsNextLine(string str1);   //вставить следующую строку в этом же уровне
	void InsNextSect(string str1);   //вставить раздел в том же уровне
	void InsDownLine(string str1);   //вставить строку в том же подуровне
	void InsDownSect(string str1);   //вставить раздел в том же подуровне
	void DelNext();   //удаление строки на том же уровне
	void DelDown();   //удаление раздела на том же уровне
	//итераторы
	int Reset();   //установить на первую запись
	int IsEnd();   //конец ?
	int GoNext();   //переход к след записи
	//работа с файлом
	void Read(string fn);   //ввод текста из файла
	void Write(string fn);   //вывод текста в файл 
	//печать
	void Print(TTextLink *p, TTextLink *curr);  //печать на консоль
};