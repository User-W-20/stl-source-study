//queue��һ���Ƚ��ȳ���First In First Out��FIFO�������ݽṹ
//������������
//������Ͷ˿��Լ��룬��˿���ȡ���⣬û���κ������������Դ�ȡqueue������Ԫ��
//queue�������б�����Ϊ

//SGI STL��deque��ΪĬ������µ�queue�ײ��ṹ

//����queueϵ�Եײ�������������й��������������֡��޸�ĳ��ӿڣ��γ���һ�ַ�ò���������ߣ���Ϊadapter�������������ˣ�SGI queue������������Ϊcontainer������������������Ϊcontainer adapter

//queue���ṩ�������ܣ�Ҳ���ṩ������

//����listΪ�ײ��ṹ�������ͷ�˿��ڣ�һ���ܹ������γ�һ��queue

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