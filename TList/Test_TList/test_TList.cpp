#include "gtest.h"
#include "../TList/_TList_.h"
#include <iostream>
using namespace std;
TEST(_TList_, can_create_integer_list)
{
	EXPECT_NO_THROW(_TList_<int> qu());
}
TEST(_TList_, at_the_begining_list_is_empty)
{
	_TList_<int> qu;
	EXPECT_TRUE(qu.IsEmpty());
}
TEST(_TList_, can_insert_the_first_element_if_the_list_is_empty)
{
	_TList_<int> qu;
	qu.insfirst(2);
	EXPECT_EQ(2,qu.GetCurr());
}
TEST(_TList_, can_insert_the_last_element_if_the_list_is_empty)
{
	_TList_<int> qu;
	qu.inslast(2);
	EXPECT_EQ(2, qu.GetCurr());
}
TEST(_TList_, can_insert_the_element_if_the_list_is_empty)
{
	_TList_<int> qu;
	qu.inscurr(2);
	EXPECT_EQ(2, qu.GetCurr());
}
TEST(_TList_, can_insert_the_first_element_if_the_list_is_not_empty)
{
	_TList_<int> qu;
	int val = 1;
	qu.insfirst(val);
	for (int i = 0; i != 5; i++)
	{
		val++;
		qu.sortins(val);
	}
	qu.GetList();
	qu.insfirst(2);
	qu.Reset();
	qu.GetList();
	cout << endl;
	EXPECT_EQ(2, qu.GetCurr());
}
TEST(_TList_, can_insert_the_last_element_if_the_list_is_not_empty)
{
	_TList_<int> qu;
	int val = 1;
	qu.insfirst(val);
	for (int i = 0; i != 5; i++)
	{
		val++;
		qu.sortins(val);
	}
	qu.GetList();
	qu.inslast(2);
	qu.GetList();
	cout << endl;
	qu.SetCurr(6);
	EXPECT_EQ(2, qu.GetCurr());
}
TEST(_TList_, can_insert_the_element_if_the_list_is_not_empty)
{
	_TList_<int> qu;
	int val = 1;
	qu.insfirst(val);
	for (int i = 0; i != 5; i++)
	{
		val++;
		qu.sortins(val);
	}
	qu.GetList();
	qu.SetCurr(4);
	qu.inscurr(2);
	qu.GetList();
	cout << endl;
	qu.SetCurr(4);
	EXPECT_EQ(2, qu.GetCurr());
}
TEST(_TList_, can_insert_the_element_into_the_rigth_position)
{
	_TList_<int> qu;
	int val = 1;
	qu.insfirst(val);
	for (int i = 0; i != 5; i++)
	{
		val++;
		qu.sortins(val);
	}
	qu.GetList();
	qu.sortins(3);
	cout << endl;
	qu.GetList();
	qu.SetCurr(3);
	EXPECT_EQ(3, qu.GetCurr());
}
TEST(_TList_, can_delete_the_first_element_if_the_list_is_not_empty)
{
	_TList_<int> qu;
	int val = 1;
	qu.insfirst(val);
	for (int i = 0; i != 5; i++)
	{
		val++;
		qu.sortins(val);
	}
	qu.GetList();
	qu.delfirst();
	qu.GetList();
	cout << endl;
	EXPECT_NE(1,qu.GetCurr());
}

TEST(_TList_, can_delete_the_current_element_if_the_list_is_not_empty)
{
	_TList_<int> qu;
	int val = 1;
	qu.insfirst(val);
	for (int i = 0; i != 5; i++)
	{
		val++;
		qu.sortins(val);
	}
	qu.GetList();
	qu.SetCurr(4);
	qu.delcurr();
	qu.GetList();
	cout << endl;
	qu.SetCurr(4);
	EXPECT_NE(4, qu.GetCurr());
}

TEST(_TList_, can_delete_the_list)
{
	_TList_<int> qu;
	int val = 1;
	qu.insfirst(val);
	for (int i = 0; i != 5; i++)
	{
		val++;
		qu.sortins(val);
	}

	qu.dellist();
	EXPECT_TRUE(qu.IsEmpty());
}
TEST(_TList_, get_value_of_the_previous_element)
{
	_TList_<int> qu;
	int val = 1;
	qu.insfirst(val);
	for (int i = 0; i != 5; i++)
	{
		val++;
		qu.sortins(val);
	}
	qu.GetList();
	qu.SetCurr(3);
	cout << "Current elment:" << qu.GetCurr() << endl<<endl;
	EXPECT_EQ(3,qu.GetPrew());
}
TEST(_TList_, get_length_of_the_list)
{
	_TList_<int> qu;
	int val = 1;
	qu.insfirst(val);
	for (int i = 0; i != 5; i++)
	{
		val++;
		qu.sortins(val);
	}
	qu.GetList();
	EXPECT_EQ(6, qu.GetListLength());
}