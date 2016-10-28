//5.按照原书改写的C++版本
#include<iostream>
#include<gx_stack>
#include<stdexcept>
#include<cstdlib>
#include<ctime>
using namespace std;
Stack<int> *SortStack(Stack<int> *stack)
{
	Stack<int> help;
	if (stack->empty())
	{
		throw out_of_range("Empty Stack!");
	}
	while (!stack->empty())
	{
		int cur = stack->top();
		stack->pop();
		while (!help.empty() && (help.top() > cur))
		{
			stack->push(help.top());
			help.pop();
		}
		help.push(cur);
	}
	while (!help.empty())
	{
		stack->push(help.top());
		help.pop();
	}
	return stack;
}


//下面是输出效果
int main()
{
	Stack<int> *stack = new Stack<int>;
	try {
		int x, y, z;
		x = 1; y = 1000;
		cout << "The stack is Pushing!\n...\n";
		for (int i = 0; i < 8; i++)
		{
			z = rand() % (y - x + 1) + x;
			stack->push(z);
			cout << " " << stack->top();
		}
		cout << "\n\n\nNow Arrange the Stack!\n...\n";
		stack = SortStack(stack);
		cout << "Pop the Arrange Stack:\n";
		while (!stack->empty())
		{
			cout << " " << stack->top();
			stack->pop();
		}

	}
	catch (exception &ex)
	{
		cerr << "Exception:" << ex.what() << endl;
		return -1;
	}
	return 0;
}
