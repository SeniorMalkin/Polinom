#pragma once
#include "../TList/_TList_Head.h"
class Polinom : public _TList_Head<TMonom>
{
public:
	Polinom();
	Polinom(int monom[][2], int nm);
	Polinom(TMonom el[], int nm);
	Polinom(Polinom &pol);
	friend ostream& operator << (ostream &oatr, Polinom& bf);
	void insbyorder(const TMonom& tm);
	void sortins(const TMonom& el);
	Polinom  operator+(Polinom &q); 
	Polinom  operator-(Polinom &q);// сложение полиномов
	Polinom & operator=(Polinom &q); // присваивание
	~Polinom();
};

