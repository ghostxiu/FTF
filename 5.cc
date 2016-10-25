//5.用一个栈实现另一个栈的排序
#include<iostream>
#include<gx/gx_stack>
#include<stdexcept>
#include<cstdlib>
#include<ctime>
using namespace std;

class OrderStack
{
private:
	Stack<int> ChStack;
	int miniValue;
public:
	OrderStack()
	{
		miniValue = 0;
	}
	void Arrange(Stack<int> stack)
	{
		int re = 0;
		while (!stack.empty())
		{
			//每次找到一个元素，最后原栈为空
			miniValue = stack.top();
			while (!stack.empty())
			{
				int ch;
				//遍历栈
				ch = stack.top();
				ChStack.push(ch);
				stack.pop();

				if (ChStack.top() < miniValue)
				{
					//找最小元素
					miniValue = ChStack.top();
				}
			}
			while (!ChStack.empty() && ChStack.top() != re)//re是上一回的最小元素
			{   //剔除最小元素
				if (ChStack.top() != miniValue)
				{
					int ch = ChStack.top();
					stack.push(ch);
				}
                ChStack.pop();
			}
			ChStack.push(miniValue);//存储本次的最小元素入栈
			re = miniValue;
		}
	}
	bool StackEmpty()
	{
		return ChStack.empty();
	}
	int StackPop()
	{
		int x;
		x = ChStack.top();
		ChStack.pop();
		return x;
	}
};
int main()
{
	Stack<int> stack;
	OrderStack stk;
	try {
		int x, y, z;
		x = 1; y = 1000;
		cout << "The stack is Pushing!\n...\n";
		for (int i = 0; i < 8; i++)
		{
			z = rand() % (y - x + 1) + x;
			stack.push(z);
			cout << " " << z;
		}
		cout << "\n\n\nNow Arrange the Stack!\n...\n";
		stk.Arrange(stack);
		cout << "Pop the Arrange Stack:\n";
		while (!stk.StackEmpty())
		{
			cout << " " << stk.StackPop();
		}

	}
	catch (exception &ex)
	{
		cerr << "Exception:" << ex.what() << endl;
		return -1;
	}
	return 0;
}
