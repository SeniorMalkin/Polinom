#pragma once
#include "../TList/_TList_Head.h"
#include <iostream>
class TPolinom: public _TList_Head<TMonom>
{
public:
	TPolinom( int monom[][2] = NULL, int nm = 0);
	TPolinom(const TPolinom &pol);
	void sortins(const TMonom& el);
	TPolinom & operator+(TPolinom &q); // сложение полиномов
	TPolinom & operator=(TPolinom &q); // присваивание

	~TPolinom();
};

