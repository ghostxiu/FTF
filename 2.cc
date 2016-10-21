//用两个栈模拟一个队列
#include<iostream>
#include<vector>
#include<stdexcept>
#include<gx/gx_stack>
//gx_stack是一个由ghostxiu改写的头文件用vector造了一个stack
using namespace std;

template <class T>
class TwoStackQueue
{
public:
	Stack <int> InStack;//读栈，入队元素先进入此栈
	Stack <int> OutStack;//出栈，出队元素从此队中走出

	int x;
	//入队
	void InQueue(T const& elem)
	{
		InStack.push(elem);
	}

	int o;
	void out()
	{
		//推栈
		while (!InStack.empty())
		{//只要读栈不为空则把元素从读栈推到出栈
			o = InStack.top();
			InStack.pop();//xxx忘记了读栈的出栈，导致无限循环
			OutStack.push(o);
		}
	}

	//出队
	int OutQueue()
	{

		if (EmptyQ())//如果队列元素为空，出队则抛出异常
		{
			throw out_of_range("Queue<>::Out ::emptyQueue\n");
		}

		//如果读栈非空而出栈为空，则把元素全部推入出栈
		if (OutStack.empty() && !InStack.empty())
		{
			out();
		}
        //如果出栈不为空
		if (!OutStack.empty())
		{
			x = OutStack.top();
		}
		OutStack.pop();//出栈首元素出队--xxx出错位置，忘记了写这行
		return x;
	}


	//队首元素

	int top()//栈顶指针
	{
		if (InStack.empty() && OutStack.empty())
		{//两栈为空则队为空队
			throw out_of_range("Stack<>::pop : empty stack");
		}
		else if (OutStack.empty() && !InStack.empty())
		{
		    //若读栈空，出栈非空，则将读栈元素压入出栈
			out();
		}
		//队首元素始终是出栈的栈顶元素
		return OutStack.top();
	}

	bool EmptyQ()
	{
	    //两栈不同时为空则非空
		return (InStack.empty() && OutStack.empty());
	}

};

int main()
{
	int x;
	TwoStackQueue<int> Stk;
	try {
		for (int i = 1; i<6; i++)
		{
			Stk.InQueue(i);
		}

		while (!Stk.EmptyQ())
		{
			cout << "Now The Queue head is :" << Stk.top() << endl;
			Stk.OutQueue();
		}
	}
	catch (exception const &ex)
	{
		cerr << "Exception :" << ex.what() << endl;
		return -1;
	}
	return 0;
}
/*出队规则：
根据队列先进先出的规则，出队时：
1.若读栈非空，出栈空，则把元素从读栈全部转入出栈，再推出出栈元素（即执行第二部）；
2.若读栈空，出栈非空，则推出出栈元素；
3.若读栈出栈皆非空，则先推出出栈元素至出栈元素为空时，再执行第1步；
4.若两栈皆为空，则队空。
*/
