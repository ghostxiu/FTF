//10.最大值减去最小值小于或者等于num的子数组数量
//常规做法，时间复杂度为O(n³)
#include<iostream>
#include<deque>
#include "gx/alll.cc"
using namespace std;
int CountNum(int *arr , int n ,int num ) ;
int main()
{
	int n ;
	cout << "Enter a number of the size of arr to create:\n";
	cin >> n;
	cout << "Enter a number \"num\" to find the array,\n "
		 <<" which maxnum minus mininum below the num:";
	int num ;
	cin >> num ;
	int count = 0 ;

	int *arr = new int[n];
	CreateRandArr(arr,n);//创建随机数组
	DisplayArr(arr,n);
	count = CountNum(arr,n,num);
	cout << "The count is " << count <<endl;
	delete [] arr ;
	return 0 ;
}
int CountNum(int *arr , int n ,int num )
{
	int count = 0 ;
	for( int x = 1 ; x < n ; ++x)
	{//确定数组长度
		for(int i = 0 ; i < x ; ++i)
		{//确定数组的起点
			int max ,min ;
			max = min = arr[i];
			for(int j = 0 ; j <= x ; ++j)
			{
				if(arr[i] > max)
				{
					max = arr[i];
				}
				else if(arr[i] < min )
				{
					min = arr[i];
				}
			}
			int mjm = max - min ; //数组最大值减去最小值
			if(mjm <= num )
			{
				count++ ;
			}
		}
	}
	return count;
}
