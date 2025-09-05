//��ν��㷨������������������ݽṹ֮�⣬�������ݽṹ���˼�����Ͳ�����ô����
//����ڼ��������λ�õ����ݽṹ�ϣ���ȷ��ʵ�����в�����

//�ؼ����ڣ�ֻҪ�Ѳ���������ͱ���Գ��󻯣��Ѳ�������ı�ʾ��������Ŀ����ƶ���Ϊ���󻯣������㷨Ҳ����һ����������Ϲ����ˡ�
//�������̳�Ϊ�㷨�ķ��ͻ���generalized������Ʒ���

int* find(int* arrayHead, int arraySize, int value) {
	for (int i = 0; i < arraySize; ++i) {
		if (arrayHead[i] == value)
			return &(arrayHead[i]);
	}
	return nullptr;
}

//�ú�����ĳ�������ڲ���value�����ص���һ��ָ�룬ָ�������ҵ��ĵ�һ������������Ԫ�أ����û���ҵ����ͷ������һ��Ԫ�ص���һλ�ã���ַ��
//���һ��Ԫ�ص���һλ�ó�Ϊend��end�Ա�null���������ڣ�endָ����Զ����������������������Ч��

//һ��ָ��arrayԪ�ص�ָ�룬�������ԺϷ���ָ��array�ڵ��κ�λ�ã�Ҳ����ָ��arrayβ��������κ�λ��
//��ָ��ָ��arrayβ�������λ��ʱ����ֻ������������arrayָ����Ƚϣ��������죨dereference����ֵ

//const int arraySize = 7;
//int ia[arraySize] = { 0,1,2,3,4,5,6 };
//int* end = ia + arraySize;//���Ԫ�ص���һλ��
//
//int* ip = find(ia, sizeof(ia) / sizeof(int), 4);
//if (ip == end) //����arrayָ��ıȽ�
//cout << "4 not found" << endl;
//else
//cout << "4 found" << endl;

//find()������������¶��������̫���ʵ��ϸ�ڣ�Ҳ���̫�������ض�����
//Ϊ����find()�������������͵������������Ӧ�ø�����

int* find(int* begin, int* end, int value) {
	while (begin != end && *begin != value)
		++begin;

	return begin;
}

//��������ڡ�ǰ�պ󿪡�����[begin,end)�ڲ���value��������һ��ָ�룬ָ�������ҵ��ĵ�һ������������Ԫ�أ����û���ҵ����ͷ���end

//const int arraySize = 7;
//int ia[arraySize] = { 0,1,2,3,4,5,6 };
//int* end = ia + arraySize;
//
//int* ip = find(ia, end, 4);
//if(ip==end)
//cout<< "4 not found" << endl;
//else
//cout << "4 found" << endl;

//find()����Ҳ���Ժܷ������������array��������
//int* ip = find(ia + 2, ia + 5, 3);
//if (ip == end)
//cout << "3 not found" << endl;
//else
//cout << "3 found" << endl;

//����find()֮�ڲ����κβ���������ض�������array�����ģ����Կ��Խ�����Ϊһ��template
//template<typename T>
//T* find(T* begin, T* end, const T& value) {
//	//�����õ���operator!=,operator*,operator++
//	while (begin!=end&&*begin!=value)
//	{
//		++begin;
//	}
//	//���·��ز���������copy��Ϊ
//	return begin;
//}

//��ֵ�Ĵ�����pass-by-value��Ϊpass-by-reference-to-const����Ϊ��������ݵ�value�����ͱ��Ϊ���⣺���Ƕ���һ�󣬴��ݳɱ����������pass-by-reference����ȫ������Щ�ɱ�

//�����������κ�����-ֻҪ����������ָ����룬ָ���ֶ�֧������4��find()
//inequality���жϲ���ȣ�������
//dereferencelm�����죬ȡֵ��������
//prefix increment��ǰ��ʽ������������
//copy�����ƣ���Ϊ���Ա���������ķ���ֵ��

//C++��һ��������ŵ���ǣ������κζ��������Ը�дΪ�Զ������ʽ����Ϊ
//������Щ�������������Ϊ�����Ա����أ�overloaded��
//�αؽ�find����Ϊֻ��ʹ��ָ���أ��β���֧������������Ϊ�ġ���Ϊ����ָ��ġ�ĳ�ֶ��󡱶����Ա�find()ʹ����?
//find()��������Դ�ԭ��(native)ָ���˼���������ѳ���

//��������һ����Ϊ����ָ��Ķ�����һ��smart pointers

//template<class Iterator,class T>
//Iterator find(Iterator begin, Iterator end, const T& value) {
//	whie(begin != end && *begin != value)
//		++begin;
//
//	return begin;
//}

//��ȫ������find()����