//Iteratorģʽ���壺�ṩһ�ַ�����ʹ���ܹ�����Ѳ��ĳ���ۺ�������������ĸ���Ԫ�أ��������뱩¶�þۺ�����ڲ�������ʽ

//STL������˼�����ڣ�������������containers�����㷨��algorithms���ֿ����˴˶�����ƣ��������һ��ճ�ϼ������Ǵ����һ��

//C++��class templates��function templates�ɷֱ���Ŀ��

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
//	deque<int>ideuqe{ ia,ia + arraySize };//VC6[x]��δ���ϱ�׼
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
