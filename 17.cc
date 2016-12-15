//17回文链表的判断,空间复杂度为n
#include<iostream>
#include "gx/abort_stl_list"
#include<list>
#include "gx/gx_stack"
using namespace std ;
bool JudgeMirror( List L)
{
	Stack<int> s ;
	Literator it  ;
	for( it = L.begin() ; it != L.end(); ++it )
	{
		s.push(*it);
	}

	for( it = L.begin() ; it != L.end() ; ++it )
	{
		int x = *it ;
		int y = s.top() ;
		if( x != y )
		{
			return false ;
		}
		s.pop() ;
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
	if(JudgeMirror(L))
	{
		cout << "Yes ,it is a mirror list.\n" << endl ;
	}
	else
	{
		cout << "No ,it isnt a mirror list.\n" << endl ;
	}

	return 0 ;
}
/*伪代码:
class Node{
public :
	int value ;
	Node *next ;
	Node(int data)
	{
		this->value = data ;
	}
}
bool JudgeMirror( List L)
{
	Stack<int> s ;
	Literator it  ;
	Node *p = head ;
	while(p != NULL)
	{
		s.push(p -> data ) ;
		p = p -> next ;
	}
	p = head;
	while(p != NULL )
	{
		int x = p -> data ;
		int y = s.top();
				if( x != y )
		{
			return false ;
		}
		s.pop() ;
	}
	return true ;
}
*/
