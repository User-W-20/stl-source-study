//priority_queue��һ��ӵ��Ȩֵ�����queue
//ֻ�����ڵ׶˼���Ԫ�أ����Ӷ���ȡ��Ԫ�أ�����֮�����������ȡԪ�ص�;��

//priority_queue����Ȩֵ������ڵ�Ԫ�ز������ձ�����Ĵ������У������Զ�����Ԫ�ص�Ȩֵ���У�ͨ��Ȩֵ��ʵֵ��ʾ����Ȩֵ����ߣ�������ǰ��

//Ĭ�������priority_queueϵ����һ��max-heap��ɣ�������һ����vector���ֵ�complete binary tree
//max-heap��������priority_queue����Ҫ�ġ���Ȩֵ�ߵ��Զ��������򡱵�����

//Ĭ�����������vectorΪ�ײ�����

//queue�Եײ�������������й������������֡��޸�ĳ��ӿڣ��γ���һ�ַ�ò���������ߣ���Ϊadapter�������������ˣ�STL priority_queue������������Ϊcontainer������������������Ϊcontainer adapter

//priority_queue������Ԫ�أ���������һ���Ĺ���ֻ��queue���˵�Ԫ�أ�Ȩֵ����ߣ������л��ᱻ���ȡ��
//priority_queue���ṩ�������ܣ�Ҳ���ṩ������

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