//deque��һ��˫�򿪿ڵ��������Կռ�
//������ͷβ���˷ֱ���Ԫ�صĲ����ɾ��������
//vectorҲ������ͷβ���˽��в�����������ͷ������Ч�����޷�������

/*deque��vector��������
1��deque�����ڳ���ʱ���ڶ���ͷ�˽���Ԫ�صĲ�����Ƴ�����
2��dequeû��������capacity�������Ϊ���Ƕ�̬���Էֶ������ռ���϶��ɣ���ʱ��������һ���µĿռ䲢��������
*/

//dequeҲ�ṩRamdon Access Iterator�������ĵ�������������ָͨ��
//��deque���е����������Ϊ�����Ч�ʣ��ɽ�deque���������Ƶ�һ��vector���ϣ���vector���������STL sort�㷨�����ٸ��ƻ�deque

//deque�������ռ�
/*vector��ɳɳ���ȴֻ����β��˳ɳ���������ɳ��Ǹ�����
��ʵ���ǣ�
��1�����ٸ���ռ䣻��2����ԭ���ݸ��ƻ�ȥ����3���ͷ�ԭ�ռ� ������*/

//dequeϵ��һ��һ�εĶ��������ռ乹��
//�ܿ��ˡ��������á����ơ��ͷš����ֻأ��������Ǹ��ӵĵ������ܹ�

//�Ƚзֶ��������Կռ䣬�ͱ�����������ƣ���Ϊ��ά�����������ļ������ݽṹ����Ƽ�������ǰ�����ȵȲ�������Ϊ������

//deque����һ����ν��map������STL��map��������Ϊ����
//�����map��һС�������ռ䣬����ÿ��Ԫ�أ��˴���Ϊһ���ڵ㣬node������ָ�룬ָ����һ�Σ��ϴ�ģ��������Կռ䣬��Ϊ������
//����������deque�Ĵ洢�ռ�����

//map��ʵ��һ��T**��Ҳ����˵����һ��ָ�룬��ָ֮������һ��ָ�룬ָ����ΪT��һ��ռ䡣

//ά���䡰������������������������˵�������operator++��operator--��������������.

/*deque������Ӧ�þ߱���
���ȣ��������ܹ�ָ���ֶ������ռ䣨�������������
����������ܹ��ж��Լ��Ƿ��Ѿ����������ڻ������ı�Ե������ǣ�һ��ǰ�������ʱ�ͱ�����Ծ����һ������һ����������Ϊ���ܹ���ȷ��Ծ��deque������ʱ���չܿ����ģ�map��*/

//һ������ʱ������������Ե��Ҫ�ر��ģ���ǰ������˶�����������Ҫ����set_node������һ��������

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

//���۴�deque����ǰ�˻���β��ȡԪ�أ�����Ҫ������ĳ�������£����������ͷŵ�

//deque�����״̬�����κ�Ԫ��ʱ��������һ����������

