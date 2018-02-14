#pragma once
#include <iostream>
//********************************************************************
//����� ������

template <class T>
struct TLink
{
	T val;            //�������� ���������� � �����
	TLink* pNext;     //��������� �� ��������� ������� ������
};


//********************************************************************
//����� �������� �������
template <class T>
class _TList_
{
protected:
	TLink<T> *pFirst, // ��������� �� ������ ����� ������
		     *pPrew,  // ��������� �� ����� �������������� ��������
		     *pCurr,  // ��������� �� ������� ����� 
		     *pLast,  // ��������� �� ��������� ����� ������
		     *pStop;  // ���������� ��������������� �� ��������� ������
	int size;         // ������  ������
	int pos;          // ����� �������� �����

public:
	_TList_();
	~_TList_();
	bool IsEmpty       ( void );   // ������ ����?
	int  GetListLength ( void ) { return size; }   // ����� ������� � ������
	T    GetPrew       ( void );   // �������� �������� ��������������� �����
	void GetList       ( void );   // ������� ������
	void sortins(const T& el);
	//������� �����
	T    SetCurr    ( int pos );   // ���������� ������� �����
	T    GetCurr    ( void );      // �������� �������� �������� �����
	int  GetCurrPos ( void ) { return pos; }     // �������� ����� �������� �����
	void Reset      ( void );      // ������� � ������ ������
	void GoNext     ( void );      // ������� � ���������� �����
	bool IsEnd      ( void );      // ����� ������?

	//������� �������
	void insfirst (const T& el); // ����� ������
	void inslast  (const T& el);   // ���������
	void inscurr  (const T& el);   // �������

	//�������� �������
	void delfirst ( void );        // �������
	void delcurr  ( void );        // ��������
	void dellist  ( void );        // �������� ����� ������
};

template <class T>
_TList_<T>::_TList_()
{
	size = pos = 0;
	pFirst = pPrew = pCurr = pLast = pStop = NULL;
}

//******************************************************

template <class T>
_TList_<T>::~_TList_()
{
	if (pFirst != pStop)
	{
		TLink<T> * buf;
		pCurr = pFirst;
		pPrew = pStop;
		while (pCurr->pNext != pStop)
		{
			buf = pCurr;
			pCurr = pCurr->pNext;
			delete buf;
		}
		delete pCurr;
	}
}

//******************************************************

template <class T>
bool _TList_<T>::IsEmpty()
{
	if ((pFirst == pStop) && (pLast == pStop))
		return true;
	return false;
}

//******************************************************

template <class T>
 void _TList_<T>::insfirst (const T& el)
{
TLink<T>* tmp = new TLink<T>;
tmp->val = el;
tmp->pNext = pFirst;
if (pFirst == pStop)
{
	pFirst = pLast = pCurr = tmp;
	pos = 0;
}
else
{
	pFirst = tmp;
	pos++;
}
size++;
}

//*****************************************************

 template <class T>
 void _TList_<T>::inslast(const T& el)
 {
	 TLink<T>* tmp = new TLink<T>;
	 tmp->val = el;
	 tmp->pNext = pStop;
	 if (pFirst == pStop)
	 {
		 pFirst = pLast = pCurr = tmp;
		 pos = 0;
	 }
	 else
	 {
		 pLast->pNext = tmp;
		 pLast = tmp;
	 }
	 size++;
 }

//******************************************************

  template <class T>
  void _TList_<T>::inscurr(const T& el)
  {
	  if (pCurr == pFirst)
		  insfirst(el);
	  else
	  {
		  if (pCurr == pStop)
			  inslast(el);
		  else
		  {
			  TLink<T>* tmp = new TLink<T>;
			  tmp->val = el;
			  tmp->pNext = pCurr;
			  pPrew->pNext = tmp;
			  pCurr = tmp;
		  }
	  }
	  size++;
}

//******************************************************
  template <class T>
  void _TList_<T>::Reset ( void )
  {
	  pos = 0;
	  pCurr = pFirst;
	  pPrew = pStop;

  }

//*******************************************************

  template <class T>
  void _TList_<T>::GoNext()
  {
	  pPrew = pCurr;
	  pCurr = pCurr->pNext;
	  pos++;
  }

  //******************************************************

  template <class T>
  bool _TList_<T>::IsEnd( void )
  {
	  return (pCurr == pStop);
  }

  //******************************************************

  template <class T>
  void _TList_<T>::delfirst(void)
  {
	  if (size == 1)
	  {
		  delete pFirst;
		  pFirst = pCurr = pLast = pPrew = pStop;
		  pos = 0;
	  }
  
	  else
	  {
		  TLink<T> * buf = pFirst;
		  pFirst = pFirst -> pNext;
		  delete buf;
		  pos--;
	  }
	  size--;
  }

//*********************************************************

  template <class T>
  void _TList_<T>::delcurr(void)
  {
	  if (size == 1)
	  {
		  delete pFirst;
		  pFirst = pCurr = pLast = pPrew = pStop;
		  pos = 0;
	  }

	  else
	  {
		  pCurr = pCurr-> pNext;
		  delete pPrew->pNext;
		  pPrew->pNext=pCurr;
		 
	  }
	  size--;
  }

//******************************************************

  template <class T>
  void _TList_<T>::dellist(void)
  {
	  if (pFirst != pStop)
	  {
		  TLink<T> * buf;
		  pCurr = pFirst;
		  pPrew = pStop;
		  while (pCurr->pNext != pStop)
		  {
			  buf = pCurr;
			  pCurr = pCurr->pNext;
			  delete buf;
		  }
		  delete pCurr;
	  }
	  pFirst = pCurr = pLast = pStop;
	  pos = 0;
	  size = 0;
  }

//*****************************************************

  template <class T>
  T _TList_<T>::GetCurr(void)
  {
	  return pCurr->val;
  }

//*****************************************************

  template <class T>
  T    _TList_<T>::SetCurr(int pos1)
  {
	  Reset();
	  while (pos != pos1)
	  {
		  TLink<T>* buf = pCurr;
		  pCurr = pCurr -> pNext;
		  pPrew = buf;
		  pos++;
	  }
	  return GetCurr();
  }

//*****************************************************

  template <class T>
  T _TList_<T>::GetPrew()
  {
	  return pPrew->val;
  }
  
//*******************************************************

  template <class T>
  void _TList_<T>::GetList()
  {
	  cout << endl << "List:" << endl;
	  for (Reset(); !IsEnd(); GoNext())
		  cout << GetCurr()<<" ";
	  cout << endl;
	  Reset();
  }
  
//*******************************************************

  template <class T>
  void _TList_<T>::sortins(const T& el)
  {
	  int flag = 0;
	  int flag1 = 0;

	  for (Reset(); !IsEnd(); GoNext())
	  {
		  if (!IsEmpty())
		  {
			  if (GetCurrPos() == 0)
			  {
				  if (el <= GetCurr())
				  {
					  insfirst(el);
					  flag1++;
					  break;
				  }
			  }
			  else
			  {
				  if (GetCurr() == el)
				  {
					  inscurr(el);
					  flag1++;
					  break;
				  }
				  if ((el > GetPrew()) && (el < GetCurr()))
				  {
					  inscurr(el);
					  flag1++;
					  break;
				  }
			  }
		  }
		  else
		  {
			  insfirst(el);
			  flag1++;
			  break;
		  }

	  }
	  if (flag1 == 0)
		  inslast(el);
	  Reset();
  }