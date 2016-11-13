//7.窗口最大值问题
//双端队列处理
#include<iostream>
#include<deque>//双端队列

using namespace std;

//C++返回一个int类型的数组
int* screen_max(int arr[] , int n, int w)
{
    int *fd= new int[n- w +1];
    //存储窗口最大值的数组，这里使用动态数组的方法
    deque<int> qmax;//开辟一个双端队列存储最大值下标
    if(arr == NULL || w < 1 || n < w)
    {
        return NULL;
    }
    int index = 0 ;
    for(int i = 0 ; i < n ; i++ )
    {
        while(!qmax.empty()&&arr[qmax.back()]<=arr[i])
        {
            qmax.pop_back();
        }
        qmax.push_back(i);
        if( i >= w - 1)
        {
            fd[index++] = arr[qmax.front()];
        }
    }


    return fd;
}

int main()
{
    cout << "Enter a number n to arr size :\n";
    int n ;
    cin >> n ;
    int arr[n];
    cout << "Then enter " << n << " elements of arr:\n";
    int j = 0 ;
    while(j<n)
    {
        cin >> arr[j];
        j++;
    }
    int w ;
    cout << "Now enter the w of screen:\n";
    cin >> w;

    //找最大值
    int* fd = new int ; //安全的C++申请指针的用法
    fd = screen_max(arr,n,w);
    for(int k = 0;k< n- w +1;k++)
    {
        cout << "find[" <<k<<"] = " << fd[k] << endl;
    }
    return 0;
}
