//deque是一种双向开口的连续线性空间
//可以在头尾两端分别做元素的插入和删除操作。
//vector也可以在头尾两端进行操作，但是其头部操作效率奇差，无法被接受

/*deque和vector的最大差异
1、deque允许于常数时间内对起头端进行元素的插入或移除操作
2、deque没有容量（capacity）观念，因为它是动态地以分段连续空间组合而成，随时可以增加一段新的空间并链接起来
*/

//deque也提供Ramdon Access Iterator，但它的迭代器并不是普通指针
//对deque进行的排序操作，为了最高效率，可将deque先完整复制到一个vector身上，将vector排序后（利用STL sort算法），再复制回deque

//deque是连续空间
/*vector虽可成长，却只能向尾后端成长，而且其成长是个假象
事实上是：
（1）另觅更大空间；（2）将原数据复制回去；（3）释放原空间 三部曲*/

//deque系由一段一段的定量连续空间构成
//避开了“重新配置、复制、释放”的轮回，代价则是复杂的迭代器架构

//既叫分段连续线性空间，就必须有中央控制，而为了维持整体连续的假象，数据结构的设计及迭代器前进后腿等操作都颇为繁琐。

//deque采用一块所谓的map（不是STL的map容器）作为主控
//这里的map是一小块连续空间，其中每个元素（此处称为一个节点，node）都是指针，指向另一段（较大的）连续线性空间，称为缓冲区
//缓冲区才是deque的存储空间主体

//map其实是一个T**，也就是说它是一个指针，所指之物又是一个指针，指向型为T的一块空间。

//维持其“整体连续”假象的任务，落在了迭代器的operator++和operator--两个运算子身上.

/*deque迭代器应该具备：
首先，它必须能够指出分段连续空间（缓冲区）在哪里，
其次它必须能够判断自己是否已经处于其所在缓冲区的边缘，如果是，一旦前进或后退时就必须跳跃至下一个或上一个缓冲区，为了能够正确跳跃，deque必须随时掌握管控中心（map）*/

//一旦进行时遇到缓冲区边缘，要特别当心，视前进或后退而定，可能需要调用set_node（）跳一个缓冲区

#include<iostream>
#include<deque>
#include<algorithm>
#include<memory>
using namespace std;

int main() {
	deque<int, allocator<int>>ideq(20, 9);
	cout << "size=" << ideq.size() << endl;//size=20

	for (int i = 0; i < ideq.size(); i++)
		ideq[i] = i;

	for (int i = 0; i < ideq.size(); i++)
		cout << ideq[i] << ' ';//0 1 2 3 ...19
	cout << endl;

	for (int i = 0; i < 3; i++)
		ideq.push_back(i);

	for(int i=0;i<ideq.size();i++)
		cout << ideq[i] << ' ';//0 1 2 3 ...19 0 1 2
	cout << endl;
	cout << "size=" << ideq.size() << endl;//size=23

	ideq.push_back(3);
	for (int i = 0; i < ideq.size(); i++)
		cout << ideq[i] << ' ';//0 1 2 3 ...19 0 1 2 3
	cout << endl;
	cout << "size=" << ideq.size() << endl;//size=24

	ideq.push_front(99);
	for (int i = 0; i < ideq.size(); i++)
		cout << ideq[i] << ' ';//99 0 1 2 3 ...19 0 1 2 3
	cout << endl;
	cout << "size=" << ideq.size() << endl;//size=25

	ideq.push_front(98);
	ideq.push_front(97);
	for (int i = 0; i < ideq.size(); i++)
		cout << ideq[i] << ' ';//97 98 99 0 1 2 3 ...19 0 1 2 3
	cout << endl;
	cout << "size=" << ideq.size() << endl;//size=27

	deque<int, allocator<int>>::iterator itr;
	itr = find(ideq.begin(), ideq.end(), 99);
	cout << *itr << endl;//99
	
	return 0;
}

//无论从deque的最前端或最尾端取元素，都需要考虑在某种条件下，将缓冲区释放掉

//deque的最初状态（无任何元素时）保留有一个缓冲区。

