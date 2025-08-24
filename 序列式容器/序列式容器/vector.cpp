//vector的数据安排以及操作方式，与array非常相似，唯一差别在于空间的运用的灵活性

//array：静态空间
//vector：动态空间

//vector的实现技术：关键在于其对大小的控制以及重新配置时的数据移动效率。

//连续线性空间、支持随机存取

//以两个迭代器start和finish分别指向配置的得来的连续空间中目前已被使用的范围，并以迭代器end_of_storage指向整块连续空间（含备用空间）的尾端

//一个vecotr的容量永远大于或等于其大小。

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//int main() {
//	int i;
//	vector<int>iv(2, 9);
//	cout << "size=" << iv.size() << endl;//size=2
//	cout << "capacity=" << iv.capacity() << endl;//capacity=2
//	cout << "------------------------";
//	cout << endl;
//
//	iv.push_back(1);
//	cout << "size=" << iv.size() << endl;//size=3
//	cout << "capacity=" << iv.capacity() << endl;//capacity=4
//	cout << "------------------------";
//	cout << endl;
//
//	iv.push_back(2);
//	cout << "size=" << iv.size() << endl;//size=4
//	cout << "capacity=" << iv.capacity() << endl;//capacity=4
//	cout << "------------------------";
//	cout << endl;
//
//	iv.push_back(3);
//	cout << "size=" << iv.size() << endl;//size=5
//	cout << "capacity=" << iv.capacity() << endl;//capacity=8
//	cout << "------------------------";
//	cout << endl;
//
//	iv.push_back(4);
//	cout << "size=" << iv.size() << endl;//size=6
//	cout << "capacity=" << iv.capacity() << endl;//capacity=8
//	cout << "------------------------";
//	cout << endl;
//
//	for (i = 0; i < iv.size(); ++i)
//		cout << iv[i] << " ";//9 9 1 2 3 4
//	cout << endl;
//	cout << "------------------------";
//	cout << endl;
//
//	iv.push_back(5);
//	cout << "size=" << iv.size() << endl;//size=7
//	cout << "capacity=" << iv.capacity() << endl;//capacity=8
//	cout << "------------------------";
//	cout << endl;
//
//	for (i = 0; i < iv.size(); ++i)
//		cout << iv[i] << " ";//9 9 1 2 3 4 5
//	cout << endl;
//	cout << "------------------------";
//	cout << endl;
//
//	iv.pop_back();
//	iv.pop_back();
//	cout << "size=" << iv.size() << endl;//size=5
//	cout << "capacity=" << iv.capacity() << endl;//capacity=8
//	cout << "------------------------";
//	cout << endl;
//
//	iv.pop_back();
//	cout << "size=" << iv.size() << endl;//size=4
//	cout << "capacity=" << iv.capacity() << endl;//capacity=8
//	cout << "------------------------";
//	cout << endl;
//
//	vector<int>::iterator ivite = find(iv.begin(), iv.end(), 1);
//	if (ivite != iv.end()) iv.erase(ivite);
//	cout << "size=" << iv.size() << endl;//size=3
//	cout << "capacity=" << iv.capacity() << endl;//capacity=8
//	cout << "------------------------";
//	cout << endl;
//
//	for (i = 0; i < iv.size(); ++i)
//		cout << iv[i] << " ";//9 9 2
//	cout << endl;
//	cout << "------------------------";
//	cout << endl;
//
//	vector<int> ivec = { 1, 2, 4 };
//	auto ite = find(ivec.begin(), ivec.end(), 2);
//	if ((ite != ivec.end()))  ivec.insert(ite, 3, 7);
//
//		cout << "size=" << iv.size() << endl;//size=6
//		cout << "capacity=" << iv.capacity() << endl;//capacity=8
//		for (i = 0; i < ivec.size(); ++i)
//			cout << ivec[i] << " ";//9 9 2
//		cout << endl;
//		cout << "------------------------";
//		cout << endl;
//
//		iv.clear();
//		cout << "size=" << iv.size() << endl;//size=0
//		cout << "capacity=" << iv.capacity() << endl;//capacity=8
//		cout << endl;
//
//		return 0;
//}

//vector默认使用alloc作为空间配置器，另外定义了一个data_allocator，目前是更方便的以元素大小为配置单位

//动态增加大小，并不是在原空间之后接续新空间（因为无法保证原空间之后尚有可供配置的空间），而是以原大小的两倍另外配置一块较大空间，然后将原内容拷贝过来，然后才开始在原内容之后构造新元素，并释放原空间。

//对vector的任何操作，一旦引起空间重新配置，指向原vector的所有迭代器就都失效了。

