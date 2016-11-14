//构造数组的MaxTree
#include<iostream>
#include<unordered_map>
#include<gx/gx_stack>
//这里使用效率更高的unordered_map代替hash_map
//编译器需要加上：-std=gnu++0x或者-std=c++
using namespace std;
class Node{

public:
    int value ;
    Node *left;
    Node *right;

    Node (int data)
    {
        value = data ;
    }
    //需要构造函数初始化值
    Node()
    {
        value  = 0 ;
    }


    bool operator= =(const Node &S)
    {
        if(this->value != S.value)
        {
            return false;
        }
        return ture;
    }
};
//涉及map，类数组

void PopStackSetMap(Stack<Node> &stack,unordered_map<Node,Node> &map);
Node GetMaxTree(int arr[],int n );

int main ()
{
    int n ;
    //数组的读入和树的构造
    cout << "Please enter the size of arr:" ;
    cin >> n ;
    int arr[n];
    Node MaxTree = GetMaxTree(arr,n);


    return 0;
}

void PopStackSetMap(Stack<Node> &stack,unordered_map<Node,Node> &map)
{
    Node PopNode = stack.top();
    stack.pop();
    if(stack.empty())
    {
        map.insert(unordered_map<Node,Node>::value_type(PopNode,NULL));
    }
    else
    {
        map.insert(unordered_map<Node,Node>::value_type(PopNode,stack.top()));
    }
}

/* MaxTree的定义：
1.数组没有重复元素；
2.MaxTree是一棵二叉树，数组的每一个值对应一个二叉树节点
3.包括MaxTree树在内且在其中的每一棵子树上，值的最大节点都是树的头
*/
