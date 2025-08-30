//heap��������STL�������
//��������priority queue������
//priority queue�����û����κδ����κ�Ԫ�����������ڣ���ȡ��ʱһ���Ǵ�����Ȩ��ߣ�Ҳ������ֵ��ߣ���Ԫ�ؿ�ʼȡ
//binary max heap �������������ԣ��ʺ���Ϊpriority queue�ĵײ����

//���ʹ��list��Ϊpriority queue�ĵײ���ƣ�Ԫ�ز������������ʱ��
//����Ҫ�ҵ�list�еļ�ֵ��ȴ��Ҫ������list��������ɨ��
//Ҳ���Ըı���������Ԫ�ز���ǰ�Ⱦ�������ʹ��list��Ԫ��ֵ������С���󣨻��ɴ�С������������Ȼȡ�ü�ֵ�Լ�Ԫ��ɾ�������ﵽ���Ч�ʣ���Ԫ�صĲ���ȴֻ�����Ա���

//�����binary search tree��Ϊpriority queue�ĵײ����
//Ԫ�صĲ���ͼ�ֵ��ȡ�þ���O(logN)�ı���
//������̫С������ˣ�һ��binary search tree��������Ҫ�㹻������ԣ�����binary search tree��������ʵ��
//binary heap�������������µ���Ѻ�ѡ��

//binary heap����һ��complete binary tree����ȫ��������
//����binary tree������ײ��Ҷ�ڵ�֮�⣬���������ģ�����ײ��Ҷ�ڵ����������ֲ����п�϶

//complete binary tree��������û���κνڵ�©��
//��������array���洢���нڵ�
//��array��#0Ԫ�ر���������Ϊ����������С������ô��complete binary tree�е�ĳ���ڵ�λ��array��i��ʱ�������ӽڵ��λ��array��2i���������ӽڵ��λ��array��2i+1�����丸�ڵ��λ�ڡ�i/2��������/�������˹���ţ�ȡ��������
//������array����tree�ķ�ʽ����Ϊ��ʽ��������implicit represemtation��

//array��ȱ�����޷���̬�ı��С����heap��Ҫ������ܣ�����vector�Ǵ���array�ĸ���ѡ��

//����Ԫ�����з�ʽ����Ϊmax-heap��min-heap��ǰ��ÿ���ڵ�ļ�ֵ��key�������ڻ�������ӽڵ�ļ�ֵ������ÿ���ڵ�ļ�ֵ��key����С�ڻ�������ӽڵ�ļ�ֵ
//max-heap�����ֵ�ڸ��ڵ㣬������λ�ڵײ�array��vector����ͷ��
//min-heap����Сֵ�ڸ��ڵ㣬������λ�ڵײ�array��vector����ͷ��
//STL�ṩ����max-heap

//push_heap�㷨
//ִ��һ��percolate up�����ݣ����򣬽��½ڵ��������丸�ڵ�Ƚϣ�������ֵ��key���ȸ��ڵ�󣬾͸��ӶԻ�λ�ã����һֱ���ݣ�ֱ������Ҫ�Ի���ֱ�����ڵ�Ϊֹ

//pop_heap�㷨
//ִ��һ��percolate down�����ݣ����򣺽����ڵ㣨���ֵ��ȡ�ߺ��γ�һ�������������������Ǹ�ʧȥ����ռ��Ҷ�ӽ�㣬�ٽ����������������ӽڵ�Ƚϼ�ֵ��key��������ϴ���ӽڵ�Ե�λ�á�һֱ�·ţ�ֱ������������ļ�ֵ�������������ӽڵ㣬��ֱ���·���Ҷ�ӽڵ�Ϊֹ

//sort_heap�㷨
//ÿ��pop_heap�ɻ��heap�м�ֵ����Ԫ��
//����������heap��pop_heap������ÿ�ν�������Χ�Ӻ���ǰ����һ��Ԫ�أ���Ϊpop_heap��Ѽ�ֵ����Ԫ�ط��ڵײ���������β�ˣ�������������ִ�����ʱ��������һ����������

//make_heap�㷨
//��һ�����е�����ת��Ϊһ��heap
//��Ҫ����complete binary tree����ʽ������implicit representation��

//heap������Ԫ�ض�������ѭ�ر�ģ�complete binary tree�����й�������heap���ṩ�������ܣ�Ҳ���ṩ������

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	{
//		//test heap(�ײ���vector���)
//		int ia[9] = { 0,1,2,3,4,8,9,3,5 };
//		vector<int>ivec(ia, ia + 9);
//
//		make_heap(ivec.begin(), ivec.end());
//		for (int i = 0; i < ivec.size(); ++i)
//			cout << ivec[i] << ' ';//9 5 8 3 4 0 2 3 1
//		cout << endl;
//		cout << "-------------------" << endl;
//
//		ivec.push_back(7);
//		push_heap(ivec.begin(), ivec.end());
//		for (int i = 0; i < ivec.size(); ++i)
//			cout << ivec[i] << ' ';//9 7 8 3 5 0 2 3 1 4
//		cout << endl;
//		cout << "-------------------" << endl;
//
//		pop_heap(ivec.begin(), ivec.end());
//		cout << ivec.back() << endl;//9�����ص����Ƴ�
//		ivec.pop_back();//�Ƴ����һ��Ԫ�ز��Ҳ�����
//		cout << "-------------------" << endl;
//
//		for (int i = 0; i < ivec.size(); ++i)
//			cout << ivec[i] << ' ';//8 7 4 3 5 0 2 3 1
//		cout << endl;
//		cout << "-------------------" << endl;
//
//		sort_heap(ivec.begin(), ivec.end());
//		for (int i = 0; i < ivec.size(); ++i)
//			cout << ivec[i] << ' '; //0 1 2 3 3 4 5 7 8
//		cout << endl;
//		cout << "-------------------" << endl;
//	}
//	
//	{
//		//test heap(�ײ���array���)
//		int ia[9] = { 0,1,2,3,4,8,9,3,5 };
//		make_heap(ia, ia + 9);
//		//array�޷���̬�ı��С����˲��ɶ����ص�array����push_heap��������
//		//��Ϊ�ǵ�����arrayβ������һ��Ԫ��
//
//		sort_heap(ia, ia + 9);
//		for (int i = 0; i < 9; ++i)
//			cout << ia[i] << ' ';//0 1 2 3 3 4 5 8 9
//		cout << endl;
//		//��������֮���heap�������Ǹ��Ϸ���heap
//		cout << "-------------------" << endl;
//
//		//��������һ��heap
//		
//		make_heap(ia, ia + 9);
//		pop_heap(ia, ia + 9);
//		cout << ia[8] << endl;//9
//		cout << "-------------------" << endl;
//	}
//
//	{
//		//test heap(�ײ���array���)
//		int ia[6] = { 4,1,7,6,2,5 };
//		make_heap(ia, ia + 6);
//		for (int i = 0; i < 6; ++i)
//			cout << ia[i] << ' ';//7 6 5 1 2 4
//		cout << endl;
//	}
//}
