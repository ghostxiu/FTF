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
    //xxx-注意必须使用动态数组，否则传值会被销毁
    deque<int> qmax;//开辟一个双端队列存储最大值下标
    if(arr == NULL || w < 1 || n < w)
    {
        return NULL;
    }
    int index = 0 ;
    for(int i = 0 ; i < n ; i++ )
    {
        //遍历数组
        while(!qmax.empty()&&arr[qmax.back()]<=arr[i])
        {
            //若qmax队尾的下标对应值小于等于i对应的值时出队
            qmax.pop_back();
        }
        qmax.push_back(i);
        //先将队标都入队
        if(qmax.front() == i - w)
        {
            //队首元素过期，出队
            qmax.pop_front();
        }
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
