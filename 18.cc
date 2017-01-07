/*
给出一个链表，和一个数值pivot
将链表三分，大于pivot和小于pivot
的分别放在链表的左右两边，等于pivot
的放在中间
*/
#include<iostream>
#include<list>
#include "gx/abort_stl_list"

void PartitionArr(double *NodeArr,double pivot , int n);
void Swap(double *NodeArr , int a , int b);

void PartitionList(List &L,int n,double pivot)
{
	//排序分区
	Literator x = L.begin();

	double *NodeArr = new double[n];
	//借用一个数组
	for(int i = 0 ; i < n ; ++i,++x )
	{
		NodeArr[i] = *x;
	}
	L.clear();
	//将数组排序
	PartitionArr(NodeArr,pivot,n);
	//写回链表
	for(int i = 0 ; i < n ; ++i )
	{
		L.push_back(NodeArr[i]);
	}

	delete [] NodeArr ;
}

int main()
{
	List L;
	cout << "Enter a number about the List size:" ;
	int n ;
	cin >> n ;
	cout << "Now Input the List member: " ;
	L = InputADoubleList(n);
	cout << "Now Input the number to partition : ";
	double pivot ;
	cin >> pivot;
	CoutList(L,"The list you input:");
	PartitionList(L,n,pivot);
	CoutList(L,"The list after partition:");

	return 0 ;
}

void PartitionArr(double *NodeArr,double pivot,int n )
{
	int index = 0 ;
	int small = -1 ;
	int big = n ;
	while(index != big)
	{
		if(NodeArr[index] < pivot)
		{
			Swap(NodeArr,++small,index++);
		}
		else if(NodeArr[index] == pivot)
		{
			index++ ;
		}
		else
		{
			Swap(NodeArr,--big,index);
		}
	}
}
void Swap(double *NodeArr , int a , int b)
{
	double tmp = NodeArr[a];
	NodeArr[a] = NodeArr[b];
	NodeArr[b] = tmp ;
}
/*伪代码描述法
class Node{
private:
	double value;
public:
	Node *next;
	Node ( double data)
	{
		this -> value = data ;
	}
}head;

Node PartionList(Node *head ,double pivot )
{
	if(head == NULL)
		return head ;
	Node *p = head ;
	int i = 0 ;
	while(p -> next != NULL)
	{
		//统计元素数量
		i++ ;
		p = p -> next ;
	}
	int n =  i ;
	array<Node,n> ArrList ;
	p = head ;
	for(i = 0 ; i < n ; ++ i)
	{
		ArrList[i] = p ;
		p = p -> next ;
	}
	PartitionArr(Arrlist,privot)；
	for(int i = 1 ; i < n ; ++i)
	{
		ArrList[i-1] -> next = ArrList[i];
	}
	ArrList[i-1] -> next = NULL;
	return ArrList[0];
}

void ArrPartition(Node *Arrlist,double privot)
{
	int index = 0 ;
	int small = -1 ;
	int big = Arrlist.size();
	while( index != big )
	{
		if(Arrlist[index] -> value < privot)
		{
			Swap(ArrList,++small,index++);
		}
		else if(Arrlist[index] -> value == privot)
		{
			index++;
		}
		else
		{
			Swap(Arrlist,--big,index)；
		}
	}
}

void Swap(Node *Arrlist,int a , int b)
{
	Node *p = ArrList[a];
	Arrlist[a] = Arrlist[b] ;
	Arrlist[n] = p;
}
*/
