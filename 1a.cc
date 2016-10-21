//10.21日修正
//创建一个有getmin功能的栈
#include<iostream>
#include<vector>
#include<stdexcept>
#include<gx/gx_stack>
using namespace std;

template <class T>
class GetMinStack{
    private:
        Stack<int> DataStack;//DataStack是数据栈
        Stack<int> MinStack;//MinStack用来保存最小元素
    public:
        //入栈
        void Push( T const &elem )
        {
            DataStack.push(elem);
            //当最小栈为空或者小于等于栈顶元素时才Push
            if(MinStack.empty() || elem <= MinStack.top())
            {
                MinStack.push(elem);
            }
        }
        //出栈
        void Pop()
        {
            if(Empty())
            {
                throw out_of_range("Stack<>::Empty!");
            }
            int x;
            x = DataStack.top();
            DataStack.pop();
            //当前元素时等于最小元素，出栈
            if(x == MinStack.top())
            {
                MinStack.pop();
            }
        }
        //取最小值
        int GetMin()
        {
            return MinStack.top();
        }
        bool Empty()
        {
            return DataStack.empty();
        }

    };

int main()
{
    GetMinStack<int> G;
    int x = 5 ,num;

    try{
        cout <<"Please Enter a Num push in Stack:\n";
        while(x--)
        {
            cin >> num ;
            G.Push(num);
            cout <<"Please Enter a Num push in Stack:\n";
        }
        cout << "\n\n\nNow pull them out!\n\n";
        while(!G.Empty())
        {
            G.Pop();
            cout << "The Min Num in stack now is :" << G.GetMin() << endl;
        }
    }
    catch (exception const& ex)
    {
        cerr << "Exception :" << ex.what() << endl;
		return -1;
    }
    return 0 ;
}
