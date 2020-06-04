#pragma once
#include<fstream>
#include"TTextLink.h"
#include"TStack.h"
#include<string>
using namespace std;

class TText
{
protected:
	TTextLink *pFirst;   //��������� �� ������ �����
	TTextLink *pCurr;    //��������� �� �������
	TStack <TTextLink*> Stack;  //���� ��� ���������

	void WriteRec(ofstream &ofs, TTextLink *p);   //�����
	TTextLink* ReadRec(ifstream &ifs);   //����
public:
	TText();  //�����������
	~TText() {};  //����������
	//������
	TTextLink* GetpCurr();  //�������� ������� ������
	void SetLink(string str1); //�������� ������ �� ������� ���
	string GetLink();    //�������� �������� ������� ������
	//���������
	void GoFirstLink();  //������� �� ������ ������
	void GoNextLink();   //������� �� ��������� ������ � ��� �� ������
	void GoDownLink();   //������� �� ��������� ����������
	void GoPrevLink();   //�������� �� ���������� ������
	//�����������
	void InsNextLine(string str1);   //�������� ��������� ������ � ���� �� ������
	void InsNextSect(string str1);   //�������� ������ � ��� �� ������
	void InsDownLine(string str1);   //�������� ������ � ��� �� ���������
	void InsDownSect(string str1);   //�������� ������ � ��� �� ���������
	void DelNext();   //�������� ������ �� ��� �� ������
	void DelDown();   //�������� ������� �� ��� �� ������
	//���������
	int Reset();   //���������� �� ������ ������
	int IsEnd();   //����� ?
	int GoNext();   //������� � ���� ������
	//������ � ������
	void Read(string fn);   //���� ������ �� �����
	void Write(string fn);   //����� ������ � ���� 
	//������
	void Print(TTextLink *p, TTextLink *curr);  //������ �� �������
};