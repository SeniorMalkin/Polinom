#pragma once
#include "../TList/_TList_Head.h"
#include <iostream>
class TPolinom: public _TList_Head<TMonom>
{
public:
	TPolinom( int monom[][2], int nm );
	TPolinom(TMonom el[], int nm);
	TPolinom();
	TPolinom(TPolinom &pol);
	void insbyorder(const TMonom& tm);
	void sortins(const TMonom& el);
	TPolinom & operator+(TPolinom &q); // сложение полиномов
	TPolinom & operator=(TPolinom &q); // присваивание

	~TPolinom();
};

