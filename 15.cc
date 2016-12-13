//反转部分链表
#include<iostream>
#include"gx/abort_stl_list"
#include<list>
#include<exception>
const int ArrSize = 10 ;//定义链表大小
using namespace std ;
typedef list<int> List;
typedef List::iterator Literator ;
template<class T>
void ReverseInPart( T & L ,int n )
{//实现功能的主要部分，反转f到t的f-t个元素
	cout << "Enter two number as changed form and to :" ;
	int f, t ;
	cin >> f >> t ;

	if(f >= t || t > n || f < 1)
	{
		cout  << "Do not need reverse!\n" ;
	}

	Literator lt= L.begin();
	int l = 1 ;
	while ( l < f)
	{
		lt++;
		l++ ;
	}
	Literator ch = lt ;//使用迭代器来完成
	++ch;
	//迭代器始终指向一个元素的位置，所以lt迭代器每次都前移
	//而ch每次指向下一个元素，即第i+1个元素
	for(int i = f ; i < t ; ++i,--lt)
	{
		int x =  *ch ;
		++ch;
		//由于remove会删除所有值为*ch 的元素，所以ch 应该先增加
		L.remove(x);
		L.insert(lt,x);
	}
//remove void remove( const TYPE &val );删除所有值为val的元素
}

int main()
{
	List L = CreateAList(ArrSize);
	CoutList(L,"The previous list:");
	cout << "Now start Change the List:\n" ;
	ReverseInPart(L,ArrSize);
	CoutList(L,"Now the value change to :");
	return 0 ;
}

/*伪代码：

List RevreseListFormTo(Node head )
{
	int from , to ;
	cin >> from >> to ;
	Node *p ,*t , *c ;
	int f = 1 ;
	p = head;
	while(f !=  from - 1 )
	{//走到from的前一个节点
		p = p -> next ;
		int f ;
	}
	for(int i = from ; i < to ; ++i )
	{
		//相当于置换p后面两个元素的位置，p始终不变
		t = p -> next ;
		c = t -> next ;
		t -> next = c -> next ;
		p -> next = c ;
	}
	return head ;
}
*/
