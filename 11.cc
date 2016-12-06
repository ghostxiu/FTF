//打印两个链表head1和head2的公共部分
#include<iostream>
#include<list>//使用list链表
using namespace std;
typedef list<int> List;
typedef List::iterator Literator;
template<class T>
void Create2List(T &h1, T &h2);

template<class T>
void CoutCommon(T &h1, T &h2)
{
	//实现的问题主功能区
	Literator x1 = h1.begin(), x2 = h2.begin() ;
	cout << "\n\n\nThe common part is :" << endl ;
	while(x1 != h1.end() && x2 != h2.end())
	{//依次向前寻找
		if(*x1 > *x2)
		{
			++x2;
		}
		else if (*x2 > *x1)
		{
			++x1;
		}
		else
		{
			cout << *x1 << " " ;
			++x1;//相同部分同时往下走一个位置
			++x2;
		}
	}

	cout << endl ;
}
int main()
{
	List head1;
	List head2;
	cout << "My list  head 1 contain:\n";
	Create2List(head1,head2);
	for(Literator x = head1.begin();x != head1.end();x++)
	{
		cout << ' ' <<*x;
	}
	cout << "\nMy list  head 2 contain:\n";
	for(Literator x = head2.begin();x != head2.end();x++)
	{
		cout << ' ' <<*x;
	}
	CoutCommon(head1,head2);
	return 0 ;
}


template<class T>
void Create2List(T &h1, T &h2)
{
	for(int i = 0 ; i < 5; i++)
	{
		h1.push_back(i+2);
		if(i<2)
		{
			h2.push_back(i+5);
		}
		else
		{
			h2.push_back(i+7);
		}
	}
	for(int i = 10; i < 16;i++)
	{
		h1.push_back(i+1);
		h2.push_back(i+2);
	}
}
