//list�ĺô���ÿ�β����ɾ��һ��Ԫ�أ������û��ͷ�һ��Ԫ�ؿռ䡣

//�����κ�λ�õ�Ԫ�ز����Ԫ���Ƴ���list��Զ�ǳ���ʱ�䡣

//list��������ָͨ����Ϊ����������Ϊ��ڵ㲻��֤�ڴ洢�ռ����������ڡ�

//list ˫������  ����������߱�ǰ�ƣ����ƵĹ��ܣ�����list�ṩ����Bidirectional Iterators

//��Ҫ���ʣ����������insert���ͽӺϲ�����splice�����������ԭ�е�list������ʧЧ��

//list��Ԫ��ɾ��������crase��Ҳֻ�С�ָ��ɾ��Ԫ�ء����Ǹ���������Ч�����������������κ�Ӱ�졣

//list������һ��˫���������һ���һ����״˫������

//ֻҪ�����ڻ�״�����β�˼���һ���հ׽ڵ㣬�����STL�淶�ġ�ǰ�պ󿪡����䡣

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

//listĬ��ʹ��alloc��Ϊ�ռ������������ⶨ����һ��list_node_allocator��Ŀǰ�Ǹ�������Խڵ��СΪ���õ�λ

//����list��һ��˫��״����ֻҪ�ѱ߼���������ã���ô����ͷ����β������Ԫ�أ�push_front��push_back��������������һ���ģ��Ƴ�Ԫ�أ�pop_front��pop_back��Ҳ������һ����

//list�ڲ��ṩһ��Ǩ�Ʋ�����transfer������ĳ������Χ��Ԫ��Ǩ�Ƶ�ĳ���ض�λ��֮ǰ��

//transfer���ǹ����ӿ�

//list�����ṩ���ǽӺϲ�����splice������ĳ������Χ��Ԫ�ش�һ��list�ƶ�����һ������ͬһ����list��ĳ�����㡣