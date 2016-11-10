//第六题的递归实现，不能看懂先看hanoi.cc
//汉诺塔移动碟，更改后，只能从A->B->C
//不能直接从A到C，或者从C到A
#include<iostream>
#include<string>
using namespace std;

int Process(int num , string left, string mid,
            string right, string from ,string to)
{
    //如果从中——》右，左——》中仅需要一步，否则需要两步
    if(num == 1)
    {
        if(from == mid || to == mid )
        {
            cout << "Move 1 from " << from << " to "
                 << to << ".\n";
            return 1 ;
        }
        else
        {
            cout << "Move 1 from " << from << " to "
                 << mid << ".\n";
            cout << "Move 1 from " << mid  << " to "
                 << to << ".\n";
            return 2;
        }
    }

    if(from == mid || to == mid)
    {
        //从左到中，或从右到中，需要三步
        string an = (from == left || to == left) ? right : left;

        int part1 = Process(num -1 , left ,mid ,right ,from ,an);

        int part2 = 1;
        cout << "Move "<< num << " from " << from << " to "
             << mid << ".\n";
        int part3 = Process(num - 1 ,left , mid ,right , an, to);
        return part1 + part2 + part3;
    }else{
        //从左到右需要五步
        int part1 = Process(num-1 , left , mid ,right ,from ,to);
        //1~n-1 层塔 左 → 右
        int part2 = 1;
        cout << "Move "<< num << " from " << from << " to "
             << mid << ".\n";
        int part3 = Process(num-1 , left , mid ,right ,to ,from );
        //1~n-1 层塔 右 → 左
        int part4 = 1;
        cout << "Move "<< num << " from " << mid << " to "
             << to << ".\n";
        //1~n-1 层塔 左 → 右
        int part5 = Process(num-1,left,mid,right,from,to);

        return part1 + part2 + part3 + part4 + part5;
    }

}

int HanoiProblem1(int num , string left ,string mid ,
                  string right )
{
    if(num < 1)
    {
        return 0 ;
    }
    return Process(num,left,mid,right,left,right);
}


int main()
{
    int n,count ;
    cout << "Enter number n to slove n step new hanoi problem1:\n";
    cin >> n;
    count = HanoiProblem1(n,"Plant Left","Plant Mid","Plant Right");
    cout << count << " steps have been moved\n";
    return 0;

}


/* 程序逻辑：
一、若剩下n层塔，最上到最下依次为1~n-1全部 左 → 中
1.将1~n-1 层塔 左 → 右，递归；
2.将第n层塔 左 → 中；
3.将1~n-1 层塔 右 → 中 ，递归.
二、n层塔 右 → 中 ，与1同理
三、n层塔需要 左 → 中：
1.将1~n-1 层塔 左 → 右，递归；
2.将第n层塔 左 → 右；
3.将1~n-1 层塔 右 → 左 ，递归；
4.将第n 层塔 中 → 右；
5.将1~n-1 层塔 左 → 右。
*/
