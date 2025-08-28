//list的好处：每次插入或删除一个元素，就配置或释放一个元素空间。

//对于任何位置的元素插入或元素移除，list永远是常数时间。

//list不能用普通指针作为迭代器，因为其节点不保证在存储空间中连续存在。

//list 双向链表  迭代器必须具备前移，后移的功能，所以list提供的是Bidirectional Iterators

//重要性质：插入操作（insert）和接合操作（splice）都不会造成原有的list迭代器失效。

//list的元素删除操作（crase）也只有“指向被删除元素”的那个迭代器生效，其它迭代器不受任何影响。

//list不仅是一个双向链表，而且还是一个环状双向链表。

//只要刻意在环状链表的尾端加上一个空白节点，便符合STL规范的“前闭后开”区间。

//#include<iostream>
//#include<list>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	int i=0;
//	list<int> ilist;
//	cout << "size=" << ilist.size() << endl;//size=0
//
//	ilist.push_back(0);
//	ilist.push_back(1);
//	ilist.push_back(2);
//	ilist.push_back(3);
//	ilist.push_back(4);
//	cout << "size=" << ilist.size() << endl;//size=5
//
//	list<int>::iterator ite;
//	for (ite = ilist.begin(); ite != ilist.end(); ++ite)
//		cout << *ite << " ";//0 1 2 3 4 
//	cout << endl;
//
//	ite = find(ilist.begin(), ilist.end(), 3);
//	if (ite != ilist.end())
//		ilist.insert(ite, 99);
//	cout << "size=" << ilist.size() << endl;//size=6
//	cout << *ite << endl;//3
//
//	for (ite = ilist.begin(); ite != ilist.end(); ++ite)
//		cout << *ite << " ";//0 1 2  99 3 4 
//	cout << endl;
//
//	ite= find(ilist.begin(), ilist.end(), 1);
//	if (ite != ilist.end())
//		cout << *(ilist.erase(ite)) << endl;//2
//
//	for (ite = ilist.begin(); ite != ilist.end(); ++ite)
//		cout << *ite << " ";//0  2  99 3 4 
//	cout << endl;
//}

//list默认使用alloc作为空间配置器，另外定义了一个list_node_allocator，目前是更方便的以节点大小为配置单位

//由于list是一个双向环状链表，只要把边际条件处理好，那么，在头部或尾部插入元素（push_front和push_back），操作几乎是一样的，移除元素（pop_front和pop_back）也几乎是一样的

//list内部提供一个迁移操作（transfer）：将某连续范围的元素迁移到某个特定位置之前。

//transfer并非公开接口

//list公开提供的是接合操作（splice）：将某连续范围的元素从一个list移动到另一个（或同一个）list的某个定点。