//6.用栈实现汉诺塔,即实现6_recursion.cc的功能
#include<iostream>
#include<gx/stack>
#include<string>
#include<climits>//MAX_INT need()
using namespace std;
enum Action {No,LToM,MToL,MToR,RToM};

//注意同时改变实参的值需要引用
int fStackTotStack(Action &record,Action PreNoAct,Action NowAct,
                              Stack<int> &fStack,Stack<int> &tStack,string from ,string to)
{
    if((record != PreNoAct) && (fStack.top()<tStack.top()))
    {
        tStack.push(fStack.top());
        fStack.pop();
        cout << "Move " << tStack.top() <<" from " << from
             << " to " << to <<".\n" ;
        record = NowAct;
        return 1;

    }
    return 0 ;
}




int HanoiProblem2(int num ,string left,string mid,string right)
{
    Stack<int> LS;
    Stack<int> MS;
    Stack<int> RS;
    LS.push(INT_MAX);
    MS.push(INT_MAX);
    RS.push(INT_MAX);
    //申请左中右三个栈
    for(int i = num ;i > 0 ;i--)
    {
        LS.push(i);//刚开始都在左边
    }
    Action record = No;
    /*申请枚举类型数组，实际上此处只用到了record[0],故无需申请数组
    Action record[5];
    //注意此处申请枚举类型数组和java不同，必须给出固定空间
    record = {No};
    */

    int step = 0;
    while(RS.size() != num + 1)
    {
        step += fStackTotStack(record,MToL,LToM,LS,MS,left,mid);
        step += fStackTotStack(record,LToM,MToL,MS,LS,mid,left);
        step += fStackTotStack(record,RToM,MToR,MS,RS,mid,right);
        step += fStackTotStack(record,MToR,RToM,RS,MS,right,mid);
    }
    return step ;
}
int main()
{
    int n,count ;
    cout << "Enter number n to slove n step new hanoi problem2:\n";
    cin >> n;
    count = HanoiProblem2(n,"Plant Left","Plant Mid","Plant Right");
    cout << count << " steps have been moved\n";
    return 0;
}


/*两个原则：
1.上小下大
2.相邻不可逆

四个动作：
L->M M->R M->L R-M

第一个动作一定是L->M
下一个动作一定是M->R 和 R->M 中的一个
*/
