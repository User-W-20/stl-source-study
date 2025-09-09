//STLһ���ṩ��������set��ص��㷨��������union����������intersection�������difference�����ԳƲ��symmetric difference��

//set�ɷ�Ϊ��ѧ�ϵĶ����STL�Ķ���
//��ѧ�ϵ�set����Ԫ���ظ���δ������
//STL�Ķ�����Ҫ��Ԫ�ز����ظ������Ҿ�������
//�ĸ��㷨�����ܵ�set���������������䣨sorted range����Ԫ��ֵ���ظ�����

//#include<iostream>
//#include<set>
//#include<algorithm>
//#include<iterator>
//using namespace std;
//
//template<class T>
//struct display{
//	void operator()(const T & x) {
//		cout << x << ' ';
//	}
//};
//
//int main() {
//	int ia1[6] = { 1,3,5,7,9,11 };
//	int ia2[7] = { 1,1,2,3,5,8,13 };
//
//	multiset<int>S1(ia1, ia1 + 6);
//	multiset<int>S2(ia2, ia2 + 7);
//
//	for_each(S1.begin(), S1.end(), display<int>());
//	cout << endl;
//	for_each(S2.begin(), S2.end(), display<int>());
//	cout << endl;
//
//	multiset<int>::iterator first1 = S1.begin();
//	multiset<int>::iterator last1 = S1.end();
//	multiset<int>::iterator first2 = S2.begin();
//	multiset<int>::iterator last2 = S2.end();
//
//	cout << "Union of S1 and S2: ";
//	set_union(first1, last1, first2, last2, ostream_iterator<int>(cout, " "));
//	cout << endl;
//
//	first1 = S1.begin();
//	first2 = S2.begin();
//	cout << "Intersection of S1 and S2: ";
//	set_intersection(first1, last1, first2, last2, ostream_iterator<int>(cout, " "));
//	cout << endl;
//
//	first1 = S1.begin();
//	first2 = S2.begin();
//	cout << "Difference of S1 and S2 (S1-S2) ";
//	set_difference(first1, last1, first2, last2, ostream_iterator<int>(cout, " "));
//	cout << endl;
//
//	first1 = S1.begin();
//	first2 = S2.begin();
//	cout << "Symmetric difference of S1 and S2: ";
//	set_symmetric_difference(first1, last1, first2, last2, ostream_iterator<int>(cout, " "));
//	cout << endl;
//
//	first1 = S2.begin();
//	first2 = S1.begin();
//	last1 = S2.end();
//	last2 = S1.end();
//	cout << "Difference of S2 and S1 (S2-S1) ";
//	set_difference(first1, last1, first2, last2, ostream_iterator<int>(cout, " "));
//	cout << endl;
//
//		/*1 3 5 7 9 11
//		1 1 2 3 5 8 13
//		Union of S1 and S2: 1 1 2 3 5 7 8 9 11 13
//		Intersection of S1 and S2 : 1 3 5
//		Difference of S1 and S2(S1 - S2) 7 9 11
//		Symmetric difference of S1 and S2 : 1 2 7 8 9 11 13
//		Difference of S2 and S1(S2 - S1) 1 2 8 13*/
//}

//set_union
//set_union�ɹ���S1,S2�Ĳ���
//�˼����ں�S1��S2�ڵ�ÿһ��Ԫ��

//����S1��S2�ڵ�ÿ��Ԫ�ض�����Ψһ����ˣ����ĳ��ֵ��S1����n�Σ���S2����m�Σ���ô��ֵ����������л����max(m,n)�Σ�����n������s1����������s2

//set_union��һ���ȶ���stable����������˼�����������ڵ�ÿ��Ԫ�ص����˳�򶼲���ı�

//�������������[first1,last1)�������[first2,last2)������Ԫ��
//set��һ��sorted range�����������㷨��ǰ��
template<class InputIterator1,class InputIterator2,class OutputIterator>
OutputIterator set_union(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result) {
	//���������䶼��δ����β��ʱ��ִ�����²���
	while (first1 != last1 && first2 != last2) {
		/* ���������ڷֱ��ƶ������������Ƚ�Ԫ��ֵ��С�ߣ�����ΪA������¼��Ŀ������Ȼ���ƶ�A��������ʹ֮ǰ����ͬʱ�����һ����������������Ȼ�������һ�εıȴ�С����¼Сֵ���������ƶ�����ֱ����������һ������β�ˣ����Ԫ����ȣ�ȡS1�߼�¼��Ŀ��������ͬʱ�ƶ�����������*/
		if (*first1 < *first2) {
			*result = *first1;
			++first1;
		}
		else if (*first2 < *first1) {
			*result = *first2;
			++first2;
		}
		else {//*first2==*first1
			*result = *first1;
			++first1;
			++first2;
		}
		++result;
	}
	//ֻҪ��������һ������β�ˣ��ͽ���������whileѭ��
	//���½���δ����β�˵����������ʣ��Ԫ�ؿ�����Ŀ�Ķ�
	//�˿̵�[first1,last1),[first2,last2)֮����һ���ǿհ���
	return copy(first2, last2, copy(first1, last1, result));
}

//set_intersection
//set_intersection�ɹ���s1��s2�Ľ���
//�˼����ں�ͬʱ������s1��s2�ڵ�ÿһ��Ԫ��

//�ȶ�����

//�������������[first1,last1)�Ҵ�����[first2,last2)������Ԫ��

template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result) {
	//���������䶼��δ����β��ʱ��ִ�����²���
	while (first1 != last1 && first2 != last2) {
		//�������ڷֱ��ƶ���������ֱ������Ԫ����ͬ����ͣ������ֵ��¼��Ŀ����
		//�ټ����ƶ���������ֱ����������һ������β��
		if (*first1 < *first2)
			++first1;
		else if (*first2 < *first1)
			++first2;
		else {
			*first2 == *first1
				* result = *first1;
			++first1;
			++first2;
			++result;
		}
	}
	return result;
}

//set_difference
//set_difference�ɹ���s1��s2�Ĳ
//�˼����ں���������s1����������s2����ÿһ��Ԫ�أ�s1��s2���佻�����������������ʾ

//�ȶ�����

//����������[first1,last1)�Ҳ�������[first2,last2)������Ԫ��
template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result) {
	//���������䶼��δ����β��ʱ��ִ�����²���
	while (first1 != last1 && first2 != last2) {
		//���������ڷֱ��ƶ�������������һ�����Ԫ�ص��ڵڶ������Ԫ�أ���ʾ��ֵͬʱ�����������䣩������������ͬʱǰ��������һ�����Ԫ�ش��ڵڶ������Ԫ�أ����õڶ�����ǰ�������������ִ����ͱ�֤��һ�����Ԫ��С�ڵڶ������Ԫ��ʱ���ڶ������Ԫ��ֻ�����ڵ�һ���䣬�����ڵڶ����䣬���ǽ�����¼��Ŀ����
		if (*first1 < *first2) {
			*result = *first1;
			++first1;
			++result;
		}
		else if (*first2 < *first1) {
			++first2;
		}
		else { //*first1==*first2
			++first1;
			++first2;
		}
		return copy(first1, last1, result);
	}
}

//set_symmetric_difference
//set_symmetric_difference�ɹ���s1��s2�ĶԳƲ
//�˼����ں���������s1����������s2���Լ���������s2����������s1����ÿһ��Ԫ��

//�ȶ�����

//�ԳƲ���������[first1,last1)�Ҳ�������[first2,last2)������Ԫ��
//�Լ�������[first2,last2)�Ҳ�������[first1,last1)������Ԫ��
//ע�⣺��������ֻ���ڡ�Ԫ��ֵ��һ�޶���������²ų����������setһ�㻯����������ظ�Ԫ�أ���ôset_symmetric_difference�Ķ���Ӧ���ǣ�
//���ĳֵ��[first1,last1)����n�Σ���[first2,last2)����m��,
//��ô����result range��Ӧ�ó���abs(n-m)��
template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result) {
	//���������䶼��δ����β��ʱ��ִ�����²���
	while (first1 != last1 && first2 != last2) {
		//���������ڷֱ��ƶ������������������ڵ�Ԫ�����,��������ͬʱǰ��
		//���������ڵ�Ԫ�ز��ȣ��ͼ�¼�н�Сֵ��Ŀ���������ҽ�Сֵ��������ǰ��
		if (*first1 < *first2) {
			*result = *first1;
			++first1;
			++result;
		}
		else if (*first2 < *first1) {
			*result = *first2;
			++first2;
			++result;
		}

		else{//*first2=first1
			++first1;
			++first2;
	}
	}
	return copy(first2, last2, copy(first1, last1, result));
}