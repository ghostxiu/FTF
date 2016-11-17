//9.量子矩阵
#include<iostream>
#include<ctime>
#include<windows.h>
#include <algorithm> //max() need
#include<gx\gx_stack>
using namespace std ;

void Display(int **arr, int l , int w );//显示二维数组
int **CreatRectangleRandArr(int l ,int w);//创建二维数组
int MaxRecFromBottom(int * height,int w)
{
    if(height == 0 || w == 0)
    {
        return 0 ;
    }
    int maxArea = 0 ;
    Stack<int> stack;
    //每次算出最大的面积并不是当前柱的最大延展
    //而是当最后一个可延展的柱弹出时获得正确的面积
    for(int i = 0 ;i < w ; i++ )
    {

        while(!stack.empty() && height[i] <= height[stack.top()])
            {
                int j = stack.top();
                stack.pop();
                int k = (stack.empty()?-1:stack.top());
                int curArea = (i - k - 1) * height[j];
                maxArea = max(maxArea,curArea);
            }
        stack.push(i);//每次把height的下标压入栈中
    }
    while(!stack.empty())
    {
        int j = stack.top();
        stack.pop();
        int k = (stack.empty() ?-1:stack.top());
        int curArea = (w -  k - 1) *height[j];
        maxArea = max(curArea,maxArea);
    }
    return maxArea;
}

int MaxSize(int ** arr, int l, int w )
{
    if(arr == 0 || w == 0 || l == 0)
    {
        return 0 ;
    }
    int maxArea = 0;
    int * height = new int[w];//按行切分

    //动态数组必须全部初始化为0，否则下一步会出错
    for(int i = 0 ; i < w ; i++ )
    {
        height[i] = 0;
    }


    for( int i = 0 ; i < l ; i++)
    {
        for(int j = 0 ; j < w ; j++)
        {

            height[j] = (arr[i][j] == 0? 0 : (height[j]+1));
            cout << "height["<<j<<"] = " << height[j] << endl;
            cout <<"The max now is " << maxArea << endl ;
        }
        maxArea = max(maxArea,MaxRecFromBottom(height,w));
        //比较每次按行切分的height和当前最大面积
    }

    return maxArea ;
}

int main()
{
    srand(time(NULL));

    int ** arr;
    int l = (rand()%120)/10+1 ;
    int w = (rand()%120)/10+1 ;

    arr = CreatRectangleRandArr(l,w);

    int maxArea = MaxSize(arr,l,w);

    cout << "The max area of the rectangle is:"
         << maxArea << endl;
    return 0;
}
/* 将量子矩阵每一行进行切分，
将底部值连续为1的存入height数组，
height 为一个立柱群 ，
通过对height群左右延展得到最大值，
借助一个栈来实现
每一次切割的时间复杂度为l，而每一个位置进出栈一次，加起来为w
时间复杂度为：l*w
*/


void Display(int ** arr,int l,int w)
{
        for(int i = 0 ; i < l ; i++)
        {
            for(int j = 0 ; j < w ; j++ )
            {
                cout << arr[i][j] << " ";
            }
            cout << endl ;
        }
}


int **CreatRectangleRandArr(int l ,int w)
{
    //产生随机矩形数组
    //动态二维数组作为函数参数和返回值
    srand(time(NULL));

    int ** arr = new int *[l];

    //开辟二维动态数组
    for(int i = 0 ;i < l ;i++)
    {
        arr[i] = new int[w];
    }

    //寻址
    for(int i = 1; i < l; i++)
    {
        arr[i] = arr[i-1] + w;
    }
    //产生随机的0和1
    for(int i = 0 ; i < l ; i++)
    {
        for(int j = 0 ; j < w ; j++ )
        {
            arr[i][j] = (rand()%19)/10;
        }
    }
    cout << "The Rand arr:\n";
    Display(arr,l,w);
    return arr;
}
