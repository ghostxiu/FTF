//汉诺塔原函数，递归实现
#include<iostream>
using namespace std ;
int count = 0 ;
void hanoi(int n,char A,char B,char C)
{
    count++;
    if(n==1)
    {
       cout << "Move disk "<< n << " from " <<  A << " to " << C << ".\n";
    }
    else
    {
        hanoi(n-1,A,C,B);
        cout << "Move disk "<< n << " from " <<  A << " to " << C << ".\n";
        hanoi(n-1,B,A,C);
    }
}
int main()
{
    int n;
    cout << "Enter number n to slove n step hanoi problem:\n";
    cin >> n;
    hanoi(n,'A','B','C');
    cout << count << " steps has been moved\n";
    return 0;
}

