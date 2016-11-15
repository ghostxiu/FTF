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
    bool operator == (const Node &S) const
    {
        return this->value == S.value;
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

Node GetMaxTree (int arr[],int n)
{
    Node *Narr = new Node[n];
    Node Head;

    //将数组的值传入Narr[]中
    for(int i = 0 ; i != n ; i++)
    {
        Narr[i] = arr[i];
    }


    //开辟栈和拉链表帮助实现maxtree
    Stack<Node> stack ;
    unordered_map<Node,Node> lBigMap;
    unordered_map<Node,Node> rBigMap;

    //正 向遍历Narr ,构建左子树
    for(int i= 0 ; i != n ; i++ )
    {
        Node CurNode = Narr[i];
        if(!stack.empty() && stack.top().value < CurNode.value)
        {
            PopStackSetMap(stack,lBigMap);
        }
        stack.push(CurNode);
    }

    while(!stack.empty())
    {
        PopStackSetMap(stack,lBigMap);
    }


    //逆向遍历Narr,构建右子树
    for(int i = n -1 ; i != -1 ; i--)
    {
        Node CurNode = Narr[i];
        if(!stack.empty() && stack.top().value < CurNode.value)
        {
            PopStackSetMap(stack,rBigMap);
        }
        stack.push(CurNode);
    }

    while(!stack.empty())
    {
        PopStackSetMap(stack,rBigMap);
    }

    //从头构建树
    for(int i = 0 ; i != n ; i++)
    {
        Node CurNode = Narr[i];
        Node Left = lBigMap.erase(CurNode);
        Node Right = rBigMap.erase(CurNode);

        if(Left == NULL && Right == NULL)
        {
            //左右子树都为空创建头节点
            Head = CurNode;
        }

        else if (Left == NULL)
        {
            if(Right.left == NULL)
            {
                Right.left = &CurNode;
            }
            else
            {
                Right.right = &CurNode;
            }
        }
        else if (Right == NULL)
        {
            if(Left.left == NULL)
            {
                Left.left = &CurNode;
            }
            else
            {
                Left.right = &CurNode ;
            }
        }
        else
        {
            Node Parent = Left.value < Right.value?Left:Right;
            if(Parent.left == NULL)
            {
                Parent.left = &CurNode;
            }
            else
            {
                Parent.right = &CurNode;
            }
        }

    }

}

//时空复杂度为n


/* MaxTree的定义：
1.数组没有重复元素；
2.MaxTree是一棵二叉树，数组的每一个值对应一个二叉树节点
3.包括MaxTree树在内且在其中的每一棵子树上，值的最大节点都是树的头
*/
