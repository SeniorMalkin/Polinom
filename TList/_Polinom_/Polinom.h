#pragma once
#include "../TList/_TList_Head.h"
#include <string>
#include <list> 
#include <regex>
class Polinom : public _TList_Head<TMonom>
{
public:
	Polinom();
	Polinom(TMonom el[], int nm);
	Polinom(Polinom &pol);
	friend ostream& operator << (ostream &oatr, Polinom& bf);
	friend istream& operator >> (istream& istr, Polinom& bf);
	void insbyorder(const TMonom& tm); 
	Polinom operator*(int q);
	Polinom operator*(TMonom &q);
	Polinom operator*(Polinom &q);
	bool operator==(Polinom &q);
	Polinom  operator+(Polinom &q); 
	Polinom  operator-(Polinom &q);// сложение полиномов
	Polinom & operator=(Polinom &q); // присваивание
	string str(void);
	void magic(string st);
	~Polinom();
};

