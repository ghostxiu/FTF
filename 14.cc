//14.反转单双向链表
#include<iostream>
#include<list>
#include"gx/abort_stl_list.cc"
using namespace std;
typedef list<int> List;
typedef List::iterator Literator;

template<class T>
void ReverseList(T &L ,int  s)
{
	Literator it = L.begin();
	for( int i = 0 ; i < s - 1 ; ++i )
	{//it始终指向第一次的begin的地址，即在本例子中，始终指向1
		int x = L.back();
		L.pop_back();

		L.insert(it,x);

	}


}
int main()
{
	cout << "Enter a num of the size of list to create:" ;
	int s ;
	cin >>  s ;
	List l;
	l = CreateAList(s);
	CoutList(l,"The list L:");
	ReverseList(l,s);
	CoutList(l,"The list L reversed:");
	return 0 ;
}



/* 伪代码:
1.单链表：
//有头节点
Node *p = NULL ,  *t = NULL;
while( head != NULL)
{
	t  = head -> next ;
	head -> next  = p;
	p = head ;
	head = t ;
}
head = p ;

2.双链表：
//有头节点
Node *p = NULL ,  *t = NULL;
while( head != NULL)
{
	t  = head -> next ;
	head -> next  = p ;
	p -> front = t ;
	p = head ;
	head = t ;
}
*/
