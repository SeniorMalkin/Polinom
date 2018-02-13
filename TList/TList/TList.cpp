// TList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "_TList_.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	_TList_<int> a;
	//a.insfirst(3);
	//a.inslast(5);
	//a.GetList();
	cout << endl;
	random_device rd;
	int count;
	int random;
	int flag = 0;
	int flag1 = 0;
	cout << "Сколько чисел необходимо добавить в список?"<<endl;
	cin >> count;
	//srand(time(NULL));
	//random = 10 + rand() % 91;
	int val = 1;
	a.insfirst(val/*random*/);
	for (int i = 0; i != count-1; i++)
	{
		val++;
		//random=10 + rand() % 91;
		a.sortins(val/*random*/);
	}
	a.GetList();
	cout << endl;
	a.insfirst(7);
	a.GetList();
	cout << endl;
	cout << a.GetListLength();
	cout << endl;
	cout << a.GetCurr();
	cout << endl;
	cout << a.GetCurrPos();
	//srand(time(NULL));
	//cout << 10 + rand()%91 << endl;
    return 0;
}

