#pragma once
#include "_TList_.h"
using namespace std;
//����� �������� ( ����� )
struct TMonom
{
	double coeff; //����������� ��� �����
	int x; 
	int y;
	int z;//������� �������� ������ (x*100 + y*10 +z)
	
	bool operator < ( const TMonom& t2)
	{
		int sum = x * 100 + y * 10 + z;
		int sum1 = t2.x * 100 + t2.y * 10 + t2.z;
		if (sum1 > sum)
			return true;
		else
			return false;
	}
	
	//***********************************************************

	bool operator > ( const TMonom& t2)
	{
		int sum = x * 100 + y * 10 + z;
		int sum1 = t2.x * 100 + t2.y * 10 + t2.z;
		if (sum1 < sum)
			return true;
		else
			return false;
	}

	//***********************************************************

	bool operator == ( const TMonom& t2)
	{
		int sum = x * 100 + y * 10 + z;
		int sum1 = t2.x * 100 + t2.y * 10 + t2.z;
		if ((sum1 == sum) && (coeff==t2.coeff))
			return true;
		else
			return false;
	}

	//************************************************************

	bool operator <= ( const TMonom& t2)
	{
		int sum = x * 100 + y * 10 + z;
		int sum1 = t2.x * 100 + t2.y * 10 + t2.z;
		if ((sum1 == sum) || (sum1 > sum))
			return true;
		else
			return false;
	}
};



//***********************************************************
/*
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

std::ostream& operator << (std::ostream &ostr, const TMonom& mon)
{
	ostr << mon.coeff << "X^" << (mon.index / 100) << "Y^" << (mon.index / 10) % 10 << "Z^" << mon.index % 10;
	return ostr;
}

//************************************************************
*/
//����������� ������
template <class T>
class _TList_Head : public _TList_<T>
{
protected:
	TLink<T>*   pHead;                        //�������� �����
public:
	                                        
	_TList_Head(void):_TList_<T>()               // �������� �������� �������� (������ ������)
	{
		pHead = new TLink<TMonom>;
		pFirst = pPrew = pCurr = pLast = pStop = pHead;
		pHead->pNext = pHead;
	}

	~_TList_Head(void)
	{
		delete pHead;
	}
	void insfirst(const T& a)               // ���������� ������� ����� ����� ������
	{
		_TList_::insfirst(a);
		pHead->pNext = pFirst;
	}
	void delfirst()                         // ���������� �������� ������� �����
	{
		_TList_::delfirst();
		pHead->pNext = pFirst;
	}
};
