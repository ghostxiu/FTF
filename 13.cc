//13.删除链表的中间
#include<iostream>
#include<list>
using namespace std;
typedef list<int> List;
typedef List::iterator Literator;
const int Size = 10 ;

List CreateAList();
template <class T>
void CoutList( T &L, string pr);

template<class T>
void DeleAverageMember( T &L)
{
	//实现主功能的程序
	cout << "\nNow start delete the CenterNum:\n" ;

	Literator x;
	int  k = Size /2; //k记录链表长度的一半
	Literator ki;
	for(x = L.begin() ; x != L.end() ; ++x )
	{
		if( k == 1 )
		{
			ki = x ;
			break ;
		}
		--k;
	}
	L.erase(ki);
}

int main()
{
	List L;
	L = CreateAList();
	CoutList(L,"The List L is create:");
	DeleAverageMember(L);//删除倒数第N个节点
	CoutList(L,"Now the L is:");
	return 0 ;
}

List CreateAList()
{
	//创建一个简单的链表
	List L;
	for(int i = 0 ; i < Size ; i++ )
	{
		L.push_back(i+1);
	}
	return L;
}

template<class T>
void CoutList( T &L, string pr)
{
	//输出链表
	cout << "\n" << pr << endl ;

	for(Literator l = L.begin(); l != L.end() ; l++)
	{
		cout << " " << *l;
	}
}
/* 数据结构的伪代码；
list head;
Node *p = head ;
int k = 0 ;

while(p -> next != NULL)
{
	//找到列表尾
	p = p -> next ;
	k++ ;
}
int j = 0;//取中值
while(j != n/2 + 1 ）
{
	//找倒数第中间节点的父节点
	p = p -> next ;
	k-- ;
}
//节点处理方法：
//1.单链表：
 Node *t = p -> next ;
 p -> next = t -> next ;
 delete t ;
 //2.双链表：
 Node *t = p -> next ;
 t -> next -> front = p ;
 p -> next = t -> next ;
 delete t ;
*/
