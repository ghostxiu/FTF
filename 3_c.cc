//由于不能很好的理解算法3，的改写
#include<iostream>
#include<stdexcept>
#include<vector>
#include<gx/gx_stack>

using namespace std;
template <class T>
class  ReStack {
private:
	Stack<int> Stk;
	Stack<int> ReStk;
public:

	void Push(int x)
	{
		Stk.push(x);
	}
	void Pop()
	{
		if (ReStk.empty())
		{
			throw out_of_range("Stack is Empty!\n");
		}
		ReStk.pop();
	}
	void Re()
	{
		//接口
		Reverse(Stk);
	}
	//递归转置序列
	void Reverse(Stack<int> Stk)
	{
		int x;
		while (!Stk.empty())
		{
			x = Stk.top();
			Stk.pop();
			ReStk.push(x);
		}
	}
	int Top()
	{
		if (ReStk.empty())
		{
			throw out_of_range("Stack is Empty!\n");
		}
		return ReStk.top();
	}
};
int main()
{
	ReStack<int> stack;
	try {
		cout << "Now Show the primary Stack：\n";
		for (int i = 1; i <= 6; i++)
		{
			stack.Push(i);
			cout << i << "  ";
		}
		stack.Re();
		cout << "\n\n\nNow Show the changed Stack：\n";
		for (int i = 1; i <= 6; i++)
		{
			cout << stack.Top() << "  ";
			stack.Pop();
		}
	}
	catch (exception const& ex)
	{
		cerr << "Exception:" << ex.what();
		return -1;
	}
	return 0;
}
