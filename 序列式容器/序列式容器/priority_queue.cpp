//priority_queue是一个拥有权值观念的queue
//只允许在底端加入元素，并从顶端取出元素，除此之外别无其它存取元素的途径

//priority_queue带有权值观念，其内的元素并非依照被推入的次序排列，而是自动依照元素的权值排列（通常权值以实值表示），权值最高者，排在最前面

//默认情况下priority_queue系利用一个max-heap完成，后者是一个以vector表现的complete binary tree
//max-heap可以满足priority_queue所需要的“依权值高低自动递增排序”的特性

//默认情况下是以vector为底部容器

//queue以底部容器完成其所有工作。具有这种“修改某物接口，形成另一种风貌”的性质者，称为adapter（配接器），因此，STL priority_queue往往不被归类为container（容器），而被归类为container adapter

//priority_queue的所有元素，进出都有一定的规则，只有queue顶端的元素（权值最高者），才有机会被外界取用
//priority_queue不提供遍历功能，也不提供迭代器

//#include<iostream>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	int ia[9] = { 0,1,2,3,4,8,9,3,5 };
//	priority_queue<int> ipq(ia, ia + 9);
//	cout << "size=" << ipq.size() << endl;//size=9
//
//	for (int i = 0; i < ipq.size(); ++i)
//		cout << ipq.top() << ' ';//9 9 9 9 9 9 9 9 9
//	cout << endl;
//
//	while (!ipq.empty()) {
//		cout << ipq.top() << ' ';//9 8 5 4 3 3 2 1 0
//		ipq.pop();
//	}
//	cout << endl;
//}