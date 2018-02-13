#pragma once
#include "_TList_.h"
//Звено полинома ( моном )
struct TMonom
{
	double coeff; //коэффициент при терме
	int index;    //свертка степеней манома (x*100 + y*10 +z)
};

//***********************************************************

bool operator < (const TMonom& t1, const TMonom& t2)
{
	if (t2.index > t1.index)
		return true;
	else
		return false;
}

//***********************************************************

bool operator > (const TMonom& t1, const TMonom& t2)
{
	if (t2.index < t1.index)
		return true;
	else
		return false;
}

//***********************************************************

bool operator == (const TMonom& t1, const TMonom& t2)
{
	if (t2.index == t1.index)
		return true;
	else
		return false;
}

//************************************************************

bool operator <= (const TMonom& t1, const TMonom& t2)
{
	if ((t2.index == t1.index) || (t2.index > t1.index))
		return true;
	else
		return false;
}

//************************************************************

//Циклический список
template <class T>
class _TList_Head : public _TList_<T>
{
protected:
	TLink<T>*   pHead;                        //головное звено
public:
	                                        
	_TList_Head(void):_TList_<T>()               // создание нулевого полинома (только голова)
	{
		pHead = new TLink<TMonom>;
		pStop = pHead;
		pHead->pNext = pHead;
	}

	~_TList_Head(void)
	{
		delete pHead;
	}
	void insfirst(const T& a)               // перекрытие вставки звена перед первым
	{
		_TList_::insfirst(a);
		pHead->pNext = pFirst;
	}
	void delfirst()                         // перекрытие удаления первого звена
	{
		_TList_::delfirst();
		pHead->pNext = pFirst;
	}
};
