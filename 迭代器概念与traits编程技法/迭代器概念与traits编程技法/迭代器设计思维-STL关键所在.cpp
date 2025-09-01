//Iterator模式定义：提供一种方法，使得能够依序巡访某个聚合物（容器）所含的各个元素，而又无须暴露该聚合物的内部表述方式

//STL的中心思想在于：将数据容器（containers）和算法（algorithms）分开，彼此独立设计，最后再以一贴粘合剂将它们撮合在一起

//C++的class templates和function templates可分别达成目标

//#include<iostream>
//#include<vector>
//#include<deque>
//#include<list>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	const int arraySize = 7;
//	int ia[arraySize] = { 0,1,2,3,4,5,6 };
//
//	vector<int>ivec{ ia,ia + arraySize };
//	list<int>ilist{ ia,ia + arraySize };
//	deque<int>ideuqe{ ia,ia + arraySize };//VC6[x]，未符合标准
//
//	vector<int>::iterator it1 = find(ivec.begin(), ivec.end(), 4);
//	if (it1 == ivec.end())
//		cout << "4 not found" << endl;
//	else
//		cout << "4 found" << *it1 << endl;
//	//4 found4
//
//	list<int>::iterator it2 = find(ilist.begin(), ilist.end(), 6);
//	if (it2 == ilist.end())
//		cout << "6 not found" << endl;
//	else
//		cout << "6 found" << *it2 << endl;
//	//6 found6
//
//	deque<int>::iterator it3 = find(ideuqe.begin(), ideuqe.end(), 8);
//	if (it3 == ideuqe.end())
//		cout << "8 not found" << endl;
//	else
//		cout << "8 found" << *it3 << endl;
//	//8 not found
//}
