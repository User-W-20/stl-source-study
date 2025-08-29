//stack 是一种先进后出（First In Last Out）的数据结构，只有一个开口
//除了最顶端外，没有任何其他方法可以存取stack的其他元素
//stack不允许有遍历行为

//SGI STL以deque作为默认情况下的stack底部结构

//由于stack系以底部容器完成其所有工作，而具有这种“修改某物接口，形成另一种风貌”的性质者，称为adapter（配接器），因此，SGI stack往往不被归类为container（容器），而被归类为container adapter

//stack不提供走访功能，也不提供迭代器

//list也是双向开口的数据结构
//若以list为底部结构并封闭其头端开口，一样能够轻易形成一个stack

#include<iostream>
#include<stack>
#include<list>
#include<algorithm>
using namespace std;

int main() {
	stack<int, list<int>>istack;
	istack.push(1);
	istack.push(3);
	istack.push(5);
	istack.push(7);

	cout << istack.size() << endl;//4
	cout << istack.top() << endl;//7

	istack.pop();cout<< istack.top() << endl;//5
	istack.pop();cout<< istack.top() << endl;//3
	istack.pop();cout<< istack.top() << endl;//1
	cout<< istack.size() << endl;//1
}