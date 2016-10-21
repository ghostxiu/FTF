//算法1：设计一个有getmin功能的栈
//方法1：空间略胜
#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<stdexcept>
#include<cstring>

using namespace std ;

template <class S>
class Stack{
    protected:
        vector<S> elems ;
    public:
        S top() const //栈顶指针
        {
            if(elems.empty())
            {
                throw out_of_range("Stack<>::pop : empty stack");
            }
            return elems.back();

        }
        //虚函数，要进行重载
        virtual void push(S const& elem)
        {
            //传入元素
            elems.push_back(elem);
        }
        virtual void pop( )
        {
            if(elems.empty())
            {
                throw out_of_range("Stack<>::pop : empty stack");
            }
            elems.pop_back();
            //A reference to the last element in the vector
        }
        bool empty () const
        {
            return elems.empty();
        }
};

//保存最小值的栈，是基类stack类的派生类
template <class S1>
class MinStack:public Stack<S1>{
    protected:
        vector<S1> elems ;
    public:
        S1 top() const //栈顶指针
        {
            if(elems.empty())
            {
                throw out_of_range("Stack<>::pop : empty stack");
            }
            return elems.back();

        }
        //重载基类的push函数,当传入元素小于或等于栈顶元素时，才push
        void push(S1 const& elem)
        {
            //minstack为空，传入元素
            if(elems.empty())
            {
                elems.push_back(elem);
            }
            //当传入元素小于或等于栈顶元素时
            if(elem <= elems.back())
            {
                elems.push_back(elem);
            }

        }

        //重载基类的pop函数，当栈顶元素等于stack出栈元素时，minstack出栈
        void pop( S1 const& elem )
        {
            if(elems.empty())
            {
                throw out_of_range("Stack<>::pop : empty stack");
            }
            if(elem == elems.back())
            {
                elems.pop_back();
            }
            cout << "The mini value in stack is :" << elems.back()
                 << endl ;

        }
        bool empty () const
        {
            return elems.empty();
        }
};

int main()
{
    Stack<int> stackData;     // stackData存储数据
    MinStack<int> stackMin; // stackMin存储数据最小值
    int x,v;//x用于记录进栈元素，v用于记录出栈元素

    try{


        //进栈
        cout << "Push a New num :" ;
        cin >> x;
        stackData.push(x);
        stackMin.push(x);

        cout << "Now the mini Data is :"
             << stackMin.top() << endl;

        cout << "Push a New num :" ;
        cin >> x;
        stackData.push(x);
        stackMin.push(x);
        cout << "Now the mini Data is :"
             << stackMin.top() << endl;

        cout << "Push a New num :" ;
        cin >> x;
        stackData.push(x);
        stackMin.push(x);
        cout << "Now the mini Data is :"
             << stackMin.top() << endl;

        cout << "Push a New num :" ;
        cin >> x;
        stackData.push(x);
        stackMin.push(x);
        cout << "Now the mini Data is :"
             << stackMin.top()<< endl<<endl<<endl<<endl;




        //出栈

        v = stackData.top();stackData.pop();
        cout << v << " is out of the stack\n";
        stackMin.pop(v);
        v = stackData.top();stackData.pop();
        cout << v << " is out of the stack\n";
        stackMin.pop(v);
                v = stackData.top();stackData.pop();
        cout << v << " is out of the stack\n";
        stackMin.pop(v);
        v = stackData.top();stackData.pop();
        cout << v << " is out of the stack\n";
        stackMin.pop(v);

    }
    catch (exception const &ex)
    {
        cerr << "Exception :" << ex.what() << endl ;
        return -1;
    }
    return 0;
}
//xxx类模版的重载
