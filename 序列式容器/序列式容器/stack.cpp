//stack ��һ���Ƚ������First In Last Out�������ݽṹ��ֻ��һ������
//��������⣬û���κ������������Դ�ȡstack������Ԫ��
//stack�������б�����Ϊ

//SGI STL��deque��ΪĬ������µ�stack�ײ��ṹ

//����stackϵ�Եײ�������������й��������������֡��޸�ĳ��ӿڣ��γ���һ�ַ�ò���������ߣ���Ϊadapter�������������ˣ�SGI stack������������Ϊcontainer������������������Ϊcontainer adapter

//stack���ṩ�߷ù��ܣ�Ҳ���ṩ������

//listҲ��˫�򿪿ڵ����ݽṹ
//����listΪ�ײ��ṹ�������ͷ�˿��ڣ�һ���ܹ������γ�һ��stack

#include<iostream>
#include<stack>
#include<list>
#include<algorithm>
using namespace std;

int main() {
	stack<int, list<int>>istack;
	istack.push(1);
	istack.push(3);
	istack.push(5);
	istack.push(7);

	cout << istack.size() << endl;//4
	cout << istack.top() << endl;//7

	istack.pop();cout<< istack.top() << endl;//5
	istack.pop();cout<< istack.top() << endl;//3
	istack.pop();cout<< istack.top() << endl;//1
	cout<< istack.size() << endl;//1
}