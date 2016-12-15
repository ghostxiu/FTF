//16约瑟夫算法的进阶版，要求时间复杂度为n
#include<iostream>
#include<list>
#include "gx/abort_stl_list"
const int men = 41 ;

int GetLive( int i , int m )
{//主要理解这个递归算法
	if ( i == 1)
	{
		return 1 ;
	}
	return (GetLive( i - 1 , m ) + m - 1 ) % i  + 1 ;
}

int JosePhusKill(List L )
{

	int tmp = GetLive(men,3) ;
	for( int i  = 1 ; i <= men ; i++ )
	{
		if( i != tmp )
		{
			L.remove(i);
		}
	}
	int x = L.front();
	return x;
}

int main()
{
	List L = CreateAList(men);
	CoutList(L,"The alive man at start :");
	cout << "The alive man at last : " << JosePhusKill(L) << endl ;
	return 0 ;
}


/* 伪代码
Node JosePhusKill(Node head , int m )
{
	if(head == NULL || head -> next == head || m < 1 )
	{
		return head ;
	}
	Node *cur = head -> next ;
	int tmp = 1 ; // tmp -> list size
	while( cur != head )
	{//找出链表长度
		tmp++ ;
		cur = cur -> next ;
	}
	tmp = GetLive(tmp,m) ;
	while( --tmp != 0)
	{
		head = head -> next;
	}
	head -> next = head ;
	return head ;
}
int GetLive(int i ,int m)
{//实际寻找节点的函数
	if( i == 1)
	{
		return 1 ;
	}
	return (GetLive( i -1 , m ) + m - 1) % i + 1 ;
}
1.遍历链表，求链表节点数个数记为n，时间复杂度为O(n)
2.根据n和m的值，还有上文分析的Num(i-1）和Num(i)的关系，
递归求生存编号的节点，递归曾为N层，时间复杂度为O(N)
3.最后根据生存节点编号，遍历寻找生存节点，时间复杂度为n
*/
