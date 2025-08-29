//queue是一种先进先出（First In First Out，FIFO）的数据结构
//它有两个出口
//除了最低端可以加入，最顶端可以取出外，没有任何其他方法可以存取queue的其它元素
//queue不允许有遍历行为

//SGI STL以deque作为默认情况下的queue底部结构

//由于queue系以底部容器完成其所有工作，而具有这种“修改某物接口，形成另一种风貌”的性质者，称为adapter（配接器），因此，SGI queue往往不被归类为container（容器），而被归类为container adapter

//queue不提供遍历功能，也不提供迭代器

//若以list为底部结构并封闭其头端开口，一样能够轻易形成一个queue

//#include<iostream>
//#include<queue>
//#include<list>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	queue<int, list<int>>iqueue;
//	iqueue.push(1);
//	iqueue.push(3);
//	iqueue.push(5);
//	iqueue.push(7);
//
//	cout << iqueue.size() << endl;//4
//	cout << iqueue.front() << endl;//1
//
//	iqueue.pop(); cout << iqueue.front() << endl;//3
//	iqueue.pop(); cout << iqueue.front() << endl;//5
//	iqueue.pop(); cout << iqueue.front() << endl;//7
//	cout << iqueue.size() << endl;
//}