//约瑟夫问题，使用List ，时间复杂度为n
#include<iostream>
#include<list>
#include "gx/abort_stl_list"
using namespace std ;

const int men = 41 ;

int JosephusCircle(List L)
{
	Literator it  = L.begin();
	int i = 0 ;
	while ( L.size() > 1 )
	{
		int p = *it ;
		++i ;
		if(i == 3 )
		{
			i = 0 ;
			L.remove(p);
			CoutList(L,"Now the alive people : ");
		}
		if( L.size() > 1)
		{
			if( *it == L.back())
			{
				*it = L.front();
			}
			else
			{
				++it;
			}
		}

	}
	int p = *it;
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
