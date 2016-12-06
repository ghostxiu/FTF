//10.最大值减去最小值小于或者等于num的子数组数量
//书上的做法，时间复杂度为O(n)
#include<iostream>
#include<deque>
#include "gx/arr_abort"
#include "gx/create_arr"
using namespace std;
int GetNum(int *arr , int n ,int num ) ;
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
	count = GetNum(arr,n,num);
	cout << "The count is " << count <<endl;
	delete [] arr ;
	return 0 ;
}
int GetNum(int *arr , int n ,int num )
{
	if(&arr == NULL|| n == 0)
	{
		return 0 ;
	}
	int count = 0 ; //统计满足的数组个数
	deque<int> qmax ;
	deque<int> qmin ;
	int i = 0 ,j = 0 ;


	while( i < n )
	{

		while( j < n)
		{
			//数组尾
			while(!qmin.empty() && arr[qmin.back()] >= arr[j])
			{//更新qmin,保持子数组最小值
				qmin.pop_back();
			}

			qmin.push_back(j);//当前元素下标进入qmin队尾
			while(!qmax.empty() && arr[qmax.back()] <= arr[j])
			{//更新qmax
				qmax.pop_back();
			}
			qmax.push_back(j);//当前元素下标进入qmax队尾

			if(arr[qmax.front()] - arr[qmin.front()] > num )
			{//不满足的数组已经无需继续循环
				break;
			}
			++j;
		}


		if(qmax.front() == i )
		{
			//更新qmax，完成使命，出队
			qmax.pop_front();
		}
		if(qmin.front() == i )
		{
			//更新qmin
			qmin.pop_front();
		}


		count += j - i - 1;//包含在arr[i~j] 内的子数组都满足
		++i;
		cout << "count = " << count << endl ;
		}
	return count;
}
/* 说明
1.传入一个数组arr,以及数组长度n，num
i和j两个变量，i记录子数组头，j记录子数组尾
2.j++ -> arr不满足时，j停止自增，
以i为头的数组以后的数组都不满足，
count += j- i ;//此时满足的数组的数量
此时满足的数组有 j-i个。
3.2完成一次i++，更新qmax，qmin
更新规则：如果qmax或qmin等于i，则队头出队
4.i,j都是一直增加，不减小，
最多进qmax，qmin一次，出一次，
所以时间复杂度为O(n)。
*/
