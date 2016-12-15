//16.约瑟夫问题，使用List
#include<iostream>
#include<list>
#include "gx/abort_stl_list"
using namespace std ;

const int men = 41 ;

int JosephusCircle(List L)
{
	Literator it = L.begin();
	//begin()是值，而end()是元素个数
	int i = 0 ;
	int flag =  0;
	for( i = 1 ; L.size() > 1 ; ++i)
	{
		int p = *it ;
		if( *it == L.back() )
		{
		//只有用begin()和back()组合可以得到正确的结果
			it = L.begin() ;
		}
		else
		{
			++it;
		}

		if(i == 3 )
		{
			i = 0 ;
			L.remove(p);
			CoutList(L,"Now the alive people : ");
		}
	}

	int p = L.front();
	return p ;
}

int main()
{
	List L = CreateAList(men);
	CoutList(L,"These people play a JosephusCircle to kill themselves:\n ");
	int x = JosephusCircle(L) ;
	cout << "Just the No." << x << " man alive!"<< endl ;
	return 0 ;
}
/* 伪代码
class Node{
public :
	int value ;
	Node *next ;
	Node(int data)
	{
		this->value = data ;
	}
}

Node JosephusKill(Node head , int m)//m = 3
{
	if( head == NULL || head.next == head || m < 1)
	{
		return head ;
	}
	Node *last = head ;
	while (last->next != head )
	{
		last = last -> next ;
	}
	int count  = 0 ;
	while(head != last)
	{
		if( ++count  == m)
		{
			last->next = head->next;
			count = 0 ;
		}
		else
		{
			last = last -> next ;
		}
		head = last -> next ;
	}
	return head;
}
*/
