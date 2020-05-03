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
	void GoFirstLink();   //������� �� ������ ������
	void GoNextLink();   //������� �� ��������� ������ � ��� �� ������
	void GoDownLink();   //������� �� ��������� ����������
	void GoPrevLink();   //�������� �� ���������� ������
	void SetLink(string str1);   //�������� ������ �� ������� ���
	string GetLink();    //�������� ������� ������
	void InsNextLine(string str1);   //�������� ��������� ������ � ���� �� ������
	void InsNextSect(string str1);   //�������� ������ � ��� �� ������
	void InsDownLine(string str1);   //�������� ������ � ��� �� ���������
	void InsDownSect(string str1);   //�������� ������ � ��� �� ���������
	void DelNext();   //�������� ������ �� ��� �� ������
	void DelDown();   //�������� ������� �� ��� �� ������
	void Read(string fn);   //���� ������ �� �����
	TTextLink* ReadRec(ifstream &ifs);   //����
	void Write(string fn);   //����� ������ � ���� 
	void WriteRec(ofstream &ofs, TTextLink *p);   //�����
	//���������
	int Reset();   //���������� �� ������ ������
	int IsEnd();   //����� ?
	int GoNext();   //������� � ���� ������
	void Print(TTextLink *p,TTextLink *curr);
};