//17的进阶,空间复杂度为O(1)
//必须创建工程
#include<iostream>
#include<list>
#include "gx/abort_stl_list"


bool JudgeMirror2(List L)
{
	int n = L.size();
	ReverseInPart(L,n/2+1,n);//反转后半部分链表
	//ReverseInPart( T & L ,int n )
	//使用了第15题反转部分链表的方法
	Literator ltr = L.begin();//记录链表右半边位置的迭代器
    for(int i = 1 ; i <= n/2 ; ++i )
	{
		++ltr;
	}

	Literator ltl = L.begin();//记录链表左半边位置的迭代器
	for(int i = 1 ; i <= n/2 ; ++i,++ltr,++ltl)
	{
		int x = *ltl ;
		int y = *ltr ;
		if( x != y )
		{
			return false ;
		}
	}
	if( n/2 + n/2 != n)
	{//基数个元素非镜像链
		return false ;
	}
	return true ;
}

int main ()
{
	List L;
	cout << "Enter a number about the List size:" ;
	int n ;
	cin >> n ;
	cout << "Now Input the List member: " ;
	L = InputAIntList(n);
	if(JudgeMirror2(L))
	{
		cout << "Yes ,it is a mirror list.\n" << endl ;
	}
	else
	{
		cout << "No ,it isnt a mirror list.\n" << endl ;
	}

	return 0;
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
bool JudgeMirror2( List L)
{

	Node *pl = head ;
	int n ;
	while(pl != NULL)
	{
		pl = pl -> next ;
		n++ ;
	}
	pl = head ;
	Node *pr ;
	for( int i = 0 ; i < n/2 ; ++i )
	{
		pl = pl -> next ;
	}
	pr = pl -> next ;//pr指向mid+1
	pl -> next = NULL ;
	pl = head;
	while(pl != NULL )
	{
		int x = pl -> data ;
		int y = pr -> data ;
		if( x != y )
		{
			return false ;
		}
		pl = pl -> next ;
		pr = pr -> next ;
	}
	return true ;
}
*/
