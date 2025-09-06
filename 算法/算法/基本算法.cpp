//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<functional>
//#include<iterator>
//#include<string>
//#include<cstring>
//#include<deque>
//#include<list>
//#include"string.h"
//using namespace std;

//algobase.cpp
//namespace algobase {
//	template<class T>
//	struct display {
//		void operator()(const T& x)const {
//			cout << x << ' ';
//		}
//	};
//}

//equal
//�������������[first,last)��������ȣ�equal()����true������ڶ����е�Ԫ�رȽ϶࣬�������Ԫ�ز��迼��

//if (vec1.size() == vec2.size() && equal(vec1.begin(), vec1.end(), vec2.begin()));
//equality������ڶ����е�Ԫ�رȵ�һ�����٣�����㷨�ڲ����е�����Ϊʱ���ᳬԽ���е�β�ˣ���ɲ���Ԥ��ĺ��
//��1ȱʡ����Ԫ���������ṩ��equlity�����������д�С�Ƚ�
//��2����ָ���º���pred��Ϊ�Ƚ�����

//template<class InputIterator1,class InputIterator2 >
//inline bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
//	//���£�������һ�߹�һ�飬���ж��ಽ����
//	//�������һ��Ԫ�ظ���������ж���Ԫ�ظ��������鷳��
//	for (; first1 != last1; ++first1, ++first2)
//		if (*first1 != *first2)//ֻҪ��ӦԪ�ز����
//			return false;//�ͽ���������false
//	return true;//���ˣ�ȫ����ȣ�����true
//}

//template<class InputIterator1, class InputIterator2,class BinaryPredicate >
//inline bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,BinaryPredicate binary_pred) {
//	for (; first1 != last1; ++first1, ++first2)
//		if (!binary_pred( *first1 , *first2))
//			return false;
//	return true;
//}

//fill
//��[first,last)�ڵ�����Ԫ�ظ�����ֵ
//template<class ForwardIterator,class T>
//void fill(ForwardIterator first, ForwardIterator last, const T& value) {
//	for (; first != last; ++first)//�����߹���������
//		*first = value;//�趨��ֵ
//}

//fill_n
//��[first,last)�ڵ�ǰn��Ԫ�ظ�����ֵ�����ص�����ָ����������һ��Ԫ�ص���һλ��

//template<class OutputIterator,class Size,class T>
//OutputIterator fill_n(OutputIterator first, Size n, const T& value) {
//	for (; n > 0; --n, ++first)//����n��Ԫ��
//		*first = value;//�趨��ֵ
//	return first;
//}
//
//int ia[3] = { 0, 1, 2 };
//vector<int> iv(ia, ia + 3);
//
//fill_n(iv.begin(), 5,7);

//����ÿ�ε������е���assignment��������һ�ָ�д��overwrite������������һ���������䳬Խ��������С���ͻ���ɲ���Ԥ�ڵĽ��
//�������֮һ�ǣ�����inserter()����һ�����в��루insert�����Ǹ�д�����ĵ�����

//int ia[3] = { 0, 1, 2 };
//vector<int> iv(ia, ia + 3);//0 1 2 
//fill_n(inserter(iv, iv.begin()), 5, 7);//77777012

//iter_swap
//������ForwardIterators��ָ�Ķ���Ե�

//template<class ForwardIterator1, class ForwardIterator2>
//inline void iter_swap(ForwardIterator1 a, ForwardIterator2 b) {
//	_iter_swap(a, b, value_type(a));;//ע���������������
//}
//
//template<class ForwardIterator1, class ForwardIterator2,class T>
//inline void _iter_swap(ForwardIterator1 a, ForwardIterator2 b, T*) {
//	T tmp = *a;
//	*a = *b;
//	*b = tmp;
//}

//iter_swap()����֪����������value type�����ܹ��ݴ�����һ�����������ݴ��������ָ����

//template<class Iterator>
//inline typename iterator_traits<Iterator>::value_type*
//value_type(const Iterator&) {
//	return static_cast<typename iterator_traits<iterator>>::value_type tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//template<class ForwardIterator1, class ForwardIterator2>
//inline void iter_swap(ForwardIterator1 a, ForwardIterator2 b) {
//	typename iterator_traits<ForwardIterator1>::value_type tmp = *a;
//	*a = *b;
//	*b = tmp;
//}

//lexicographical_compare
//�ԡ��ֵ�����ʽ������������[first1,last1)��[first2,last2)���бȽ�

//��2����ָ��һ���º���comp��Ϊ�Ƚϲ���֮�ã�ȡ��Ԫ���������ṩ��less-than������
//template<class InputIterator1, class InputIterator2>
//bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
//	//���£��κ�һ�����е���β�ˣ��ͽ��������������о���ӦԪ��һһ�ȶ�
//	for (; firs1 != last1 && first2 != last2; ++first1, ++first2) {
//		//��һ����Ԫ��ֵС�ڵڶ����е���ӦԪ��ֵ
//		if (*first1 < *first2)
//			return true;
//		//�ڶ�����Ԫ��ֵС�ڵ�һ���е���ӦԪ��ֵ
//		if (*first2 < *first1)
//			return false;
//		//�����������������������ʾ��ֵ��ȣ�������һ��ƥ��
//	}
//	//���е���������һ���е���β�˶��ڶ�������������ô��һ����С�ڵڶ�����
//	return first1 == last1 && first2 != last2;
//}

//template<class InputIterator1, class InputIterator2, class Compare>
//bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
//	for (; firs1 != last1 && first2 != last2; ++first1, ++first2) {
//		if (comp(*first1, *first2))
//			return true;
//		//�ڶ�����Ԫ��ֵС�ڵ�һ���е���ӦԪ��ֵ
//		if (comp(*first2, *first1))
//			return false;
//		//�����������������������ʾ��ֵ��ȣ�������һ��ƥ��
//	}
//	//���е���������һ���е���β�˶��ڶ�������������ô��һ����С�ڵڶ�����
//	return first1 == last1 && first2 != last2;
//}

//����ԭ��ָ�� const unsigned char*
//inline bool
//lexicographical_compare(const unsigned char* first1,
//	const unsigned char* last1,
//	const unsigned char* first2,
//	const unsigned char* last2) {
//	const size_t len1 = last1 - first1;//��һ���г���
//	const size_t len2 = last2 - first2;//�ڶ����г���
//	//�ȱȽ���ͬ���ȵ�һ�Σ�memcmp�����ٶȼ���
//	const int result = memcmp(first1, first2, min(len1, len2));
//	//����������£��򳤶Ƚϳ��߱���Ϊ�Ƚϴ�
//	return result != 0 ? result < 0 : len1 < len2;
//}

//max
//ȡ���������еĽϴ���
//template<class T>
//inline const T& max(const T& a, const T& b) {
//	return a < b ? b : a;
//}
//
//template<class T,class Compare>
//inline const T& max(const T& a, const T& b,Compare comp) {
//	return comp( a , b) ? b : a;//��comp������С�Ƚϱ�׼
//}

//min
//ȡ���������еĽ�С��
//template<class T>
//inline const T& min(const T& a, const T& b) {
//	return  b<a  ? b : a;
//}
//
//template<class T, class Compare>
//inline const T& min(const T& a, const T& b, Compare comp) {
//	return comp( b,a) ? b : a;//��comp������С�Ƚϱ�׼
//}

//mismatch
//����ƽ�бȽ��������У�ָ������֮���һ����ƥ���

//template<class InputIterator1, class InputIterator2>
//pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator1 first2) {
//	//���£��������һ���꣬�ͽ���
//	//���£��������һ�����ж��Ķ�ӦԪ����ȣ��ͽ���
//	//����һ��Ԫ�ظ�������������ж���Ԫ�ظ������������޿�Ԥ��
//	while (first1 != last1 && *first1 == *first2) {
//		++first1;
//		++first2;
//	}
//	return pair<InputIterator1, InputIterator2>(first1, first2);
//}
//
//template<class InputIterator1, class InputIterator2,class BinaryPredicate >
//pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator1 first2, BinaryPredicate binary_pred) {
//	
//	while (first1 != last1 && binary_pred (*first1 , *first2)) {
//		++first1;
//		++first2;
//	}
//	return pair<InputIterator1, InputIterator2>(first1, first2);
//}

//swap
//�ú��������������Ե����������������
//template<class T>
//inline void swap(T& a, T& b) {
//	T tmp = a;
//	a = b;
//	b = tmp;
//}

//����copy���е��Ǹ��Ʋ����������Ӳ������������assignment operator��copy construct��copy�㷨��ǰ�ߣ�������ĳЩԪ������ӵ�е���trivial assignment operator���������ܹ�ʹ���ڴ�ֱ�Ӹ�����Ϊ�����ܹ���ʡ����ʱ��

//copy�㷨�ɽ���������[first,last)�ڵ�Ԫ�ظ��Ƶ��������[result,result+(last-first))��

//����ÿ����0��last-first��������������n��copyִ�и�ֵ����*(result+n)=*(first+n)����ֵ��������ǰ���༴�ۼ�n���ƽ���

//copy�㷨��һһ����Ԫ�صĸ�ֵ��������������������λ�����������ڣ�copy�㷨�㣨���ܣ�������������ģ�ĳЩ��Ԫ����δ������֮ǰ���͸�����ֵ�����´�����

//namespace copy_overlap {
//	template<class T>
//	struct display {
//		void operator()(const T& x) {
//			cout << x << ' ';
//		}
//	};
//}

//�����vectorȡ��deque���в��ԣ����ƽ��������ȷ�ģ���Ϊvector��������ʵ�Ǹ�ԭ��ָ�룬���µ��õ�copy�㷨��memmove()ִ��ʵ�ʸ��Ʋ���

//copy���ĵ���[result,result+(last-first))�е�������ָ���󣬶��Ǹ��ĵ���������

//Ҫ��Ԫ�ز��루���Ǹ�ֵ������֮�ڣ�ʹ������������insert����ʹ��copy�㷨������insert_iterator

//��ȫ�����汾
//template<class InputIterator,class OutputIterator>
//inline OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result) {
//	return _copy_dispatch<InputIterator, OutputIterator>() {
//		first, last, result;
//	}
//}

//���غ��������ԭ��ָ�루����Ϊһ������ĵ�������const char*��const wchar_t*�������ڴ�ֱ�ӿ�������

//����汾1��������ʽ
//inline char* copy(const char* first, const char* last, char* result) {
//	memmove(result, first, last - first);
//	return result + (last - first);
//}

//����汾2��������ʽ
//inline wchar_t* copy(const wchar_t* first, const wchar_t* last, wchar_t* result) {
//	memmove(result, first,sizeof(wchar_t)*( last - first));
//	return result + (last - first);
//}

//��ȫ�����汾
//template <class InputIterator,class OutputIterator>
//struct _copy_dispatch {
//	OutputIterator operator()(InputIterator first, InputIterator last, OutputIterator result) {
//		return _copy(first, last, result, iterator_category(first));
//	}
//};

//ƫ�ػ��汾1��������������T*ָ����ʽ
//template<class T>
//struct _copy_dispatch<T*, T*> {
//	T* operator()(T* first, T* last, T* result) {
//		typedef typename _type_traits<T>::has_trivial_assignment_operator t;
//		return _copy_t(first, last, result, t());
//	}
//};

//ƫ�ػ��汾2����һ������Ϊconst T*���ڶ�����ΪT*ָ����ʽ
//template<class T>
//struct _copy_dispatch<const T*, T*> {
//	T* operator()(const T* first, const T* last, T* result) {
//		typedef typename _type_traits<T>::has_trivial_assignment_operator t;
//		return _copy_t(first, last, result, t());
//	}
//};

//_copy_dispatch()����ȫ��������ݵ���������Ĳ�ͬ�������˲�ͬ��_copy()��Ϊ���ǲ�ͬ����ĵ�������ʹ�õ�ѭ��������ͬ���п���֮��

//InputIterator�汾
//template<class InputIterator, class OutputIterator>
//inline OutputIterator _copy(InputIterator first, InputIterator last, OutputIterator result, input_iterator_tag) {
//	//�Ե�������ͬ��񣬾���ѭ���Ƿ�������ٶ���
//	for (; first != last; ++result, ++first)
//		*result = *first;//assignment operator
//	return result;
//}

//RandomAccessIterator�汾
//template<class RandomAccessIterator,class OutputIterator >
//inline OutputIterator _copy(RandomAccessIterator first, RandomAccessIterator last, OutputIterator result, random_access_iterator_tag) {
//	//�ֻ��ֳ�һ��������Ϊ���������ط�Ҳ�����õ�
//	return _copy_d(first, last, result, distance_type(first));
//}

//template<class RandomAccessIterator, class OutputIterator,class Distance >
//inline OutputIterator _copy_d(RandomAccessIterator first, RandomAccessIterator last, OutputIterator result, Distance*) {
//	//��n����ѭ����ִ�д������ٶȿ�
//	for (Distance n = last - first; n > 0; --n, ++result, ++first)
//		*result = *first;
//	return *result;
//}

//���°汾�����ڡ�ָ����ָ�Ķ���߱�trivial assignment operator��
//template <class T>
//inline T* _copy_t(const T* first, const T* last, T* result, _true_type) {
//	memmove(result, first, sizeof(T) * (last - first));
//	return result + (last - first);
//}

//���°汾�����ڡ�ָ����ָ�Ķ���߱� non-trivial assignment operator��
//template <class T>
//inline T* _copy_t(const T* first, const T* last, T* result, _false_type) {
//	//ԭ��ָ������һ��RandomAccessIterator�����Խ���_copy_d()���
//	return _copy_d(first, last, result, (ptrdiff_t*)0);
//}

//namespace copy_test {
//	class C {
//	public:
//		C():_data(3){}
//	private:
//		int _data;
//	};
//}

//vecotr ctor������copy()

//������Ϊvector�ĵ�������random access iterator ��ʵ�������Ǹ�T*

//��Ȼclass C�߱�trivial operator=��Ϊʲô�����ж�Ϊһ��_false_type?
//��Ϊ������֮�У���������֤���û��Զ������͡������������ߺ��٣�<type_traits.h>��ֻ���C++�ı������������������Լ�¼
//���������е��û��Զ��������ͣ�������������Ϊӵ��non-trivial ctor/dtor/operator=

//����<type_traits.h>�е�_type_traits<T>,���class c��һ���ػ��汾
//�������������class C������(*traits)
//��������֧��partial specialization,_STL_TEMPLATE_NULL���趨Ϊtempalte<>
//_STL_TEMPLATE_NULL struct _type_traits<copy_test::C> {
//	typedef _false_type has_trivial_default_constructor;
//	typedef _true_type has_trivial_copy_constructor;
//	typedef _true_type has_trivial_assignment_operator;
//	typedef _false_type is_POD_type;
//};

//copy_backward
//template<class BidirectionalIterator1, class BidirectionalIterator2>
//inline BidirectionalIterator2 copy_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 result);

//��[first,last)�����ڵ�ÿһ��Ԫ�أ������еķ����Ƶ���result-1Ϊ��㣬������Ϊ���е�������
//copy_backward�����ܵĵ�����������BidirectionalIterator

//namespace copy_backward_overlap {
//	template<class T>
//	struct display {
//		void operator()(const T& x) {
//			cout << x << ' ';
//		}
//	};
//}
//int main() {
	////algobase.cpp
	//{
	//	int ia[9] = { 0,1,2,3,4,5,6,7,8 };
	//	vector<int>iv1(ia, ia + 5);
	//	vector<int>iv2(ia, ia + 9);

	//	//{0,1,2,3,4}vs{ 0,1,2,3,4,5,6,7,8 }
	//	//cout << *(mismatch(iv1.begin(), iv1.end(), iv2.begin()).first);//?
	//	//cout << *(mismatch(iv1.begin(), iv1.end(), iv2.begin()).second);//5
	//	//�����ж���������ĵ�һ����ƥ��㣬����һ����������������ɵ�pair
	//	//���е�һ��������ָ���һ����Ĳ�ƥ��㣬�ڶ���������ָ��ڶ�����Ĳ�ƥ���
	//	//����д����Σ�գ�Ӧ�����жϵ������Ƿ񲻵���������end������Ȼ��ſ������������

	//	//�������������[first,last)��������ȣ�equal()����true
	//	//����ڶ����е�Ԫ�رȽ϶࣬�������Ԫ�ز��迼��
	//	//cout << equal(iv1.begin(), iv1.end(), iv2.begin());//1

	//	//cout << equal(iv1.begin(), iv1.end(), &ia[3]);//0
	//	//{0,1,2,3,4}!={ 3,4,5,6,7 }

	//	//cout << equal(iv1.begin(), iv1.end(), &ia[3], less<int>());//1
	//	//{0,1,2,3,4}<{ 3,4,5,6,7 }

	//	//fill(iv1.begin(), iv1.end(), 9);//������ȫ����9
	//	//for_each(iv1.begin(), iv1.end(), algobase::display<int>());//9 9 9 9 9

	//	//fill_n(iv1.begin(), 3, 7);//�ӵ�������ָλ�ÿ�ʼ����3��7
	//	//for_each(iv1.begin(), iv1.end(), algobase::display<int>());//7 7 7 3 4

	//	vector<int>::iterator ite1 = iv1.begin();//ָ��7
	//	vector<int>::iterator ite2 = ite1;
	//	advance(ite2, 3);//ָ��9

	//	//iter_swap(ite1, ite2);//��������ָԪ�ضԵ�
	//	//cout << *ite1 << ' ' << *ite2 << endl;//3 0
	//	//for_each(iv1.begin(), iv1.end(), algobase::display<int>());//3 1 2 0 4

	//	//����ȡ��ֵ������
	//	//cout << max(*ite1, *ite2) << endl;//3

	//	////����ȡ��ֵ����С��
	//	//cout <<min(*ite1, *ite2) << endl;// 0

	//	//ǧ��Ҫ��д��������������˼�ǣ�ȡ������������������ģ���С�ģ�
	//	//Ȼ���ٴ�ӡ����ָ��ֵ��ע�⣬����������Ĵ�С�����û�û������
	//	//cout << *max(ite1, ite2) << endl;//3
	//	//cout << *min(ite1, ite2) << endl;//0

	//	//swap(*iv1.begin(), *iv2.begin());//������ֵ�Ե�
	//	//for_each(iv1.begin(), iv1.end(), algobase::display<int>());//0 1 2 3 4
	//	//for_each(iv2.begin(), iv2.end(), algobase::display<int>());//0 1 2 3 4 5 6 7 8

	//	//׼�������ַ�������
	//	string stra1[] = { "Jamie","JJHou","Jason" };
	//	string stra2[] = { "Jamie","JJhou","Jerry" };

	//	cout << lexicographical_compare(stra1, stra1 + 2, stra2, stra2 + 2);//1
	//	cout << lexicographical_compare(stra1, stra1 + 2, stra2, stra2 + 2, greater<string>());//0
	//}

	//copy_overlap.cpp
	//{
	//	{
	//	int ia[] = { 0,1,2,3,4,5,6,7,8 };

	//	//���£����������յ�����������ص���û����
	//	copy(ia + 2, ia + 7, ia);
	//	for_each(ia, ia + 9, copy_overlap::display<int>());//2 3 4 5 6 5 6 7 8
	//	cout << endl;
	//	}

	//	{
	//		int ia[] = { 0,1,2,3,4,5,6,7,8 };
	//		//���£����������������������ص������ܻ�������
	//		copy(ia + 2, ia + 7, ia+4);
	//		for_each(ia, ia + 9, copy_overlap::display<int>());//0 1 2 3 2 3 4 5 6
	//		cout << endl;
	//		//���������ȷ����Ϊ���õ�copy�㷨ʹ��memmove()ִ�и��Ʋ���
	//	}

	//	{
	//		int ia[] = { 0,1,2,3,4,5,6,7,8 };
	//		deque<int >id(ia, ia + 9);
	//		deque<int>::iterator first = id.begin();
	//		deque<int>::iterator last = id.end();
	//		++++first;//advance(first,2);
	//		cout << *first << endl;//2
	//		----last;//advance(first,-2);
	//		cout << *last << endl;//7

	//		deque<int>::iterator result = id.begin();
	//		cout << *result << endl;//0

	//		//���£����������յ������������ص���û����
	//		copy(first, last, result);
	//		for_each(id.begin(), id.end(), copy_overlap::display<int>());//2 3 4 5 6 5 6 7 8
	//		cout << endl;
	//	}

	//	{
	//		int ia[] = { 0,1,2,3,4,5,6,7,8 };
	//		deque<int >id(ia, ia + 9);
	//		deque<int>::iterator first = id.begin();
	//		deque<int>::iterator last = id.end();
	//		++++first;//advance(first,2);
	//		cout << *first << endl;//2
	//		----last;//advance(first,-2);
	//		cout << *last << endl;//7

	//		deque<int>::iterator result = id.begin();
	//		advance(result, 4);
	//		cout << *result << endl;//4

	//		//���£�����������������������ص������ܻ�������
	//		copy(first, last, result);
	//		for_each(id.begin(), id.end(), copy_overlap::display<int>());//0 1 2 3 2 3 2 3 2
	//		cout << endl;
	//		//�������������Ϊ���õ�copy�㷨����ʹ��memmove()ִ�и��Ʋ���
	//	}
	//}

	//{
	//	//����1
	//	const char ccs[5] = { 'a','b','c','d','e' };//������Դ
	//	char ccd[5];//����ȥ��
	//	copy(ccs, ccs + 5, ccd);
	//	//���õİ汾��copy(const char*)

	//	//����2
	//	const wchar_t cwcs[5] = { 'a','b','c','d','e' };//������Դ
	//	wchar_t cwcd[5];//����ȥ��
	//	copy(cwcs, cwcs + 5, cwcd);
	//	//���õİ汾��copy(const wchar_t*)

	//	//����3
	//	int ia[5] = { 0,1,2,3,4 };
	//	copy(ia, ia + 5, ia);//������Դ��ȥ����ͬ�����������
	//	/*���õİ汾��
	//		copy()
	//			_copy_dispatch(T*,T*)
	//				_copy_t(_true_type)*/

	//	//����4
	//	//list������������ΪInputIterator
	//	list<int>ilists(ia, ia + 5); //������Դ
	//	list<int>ilisted(5);//����ȥ��
	//	copy(ilists.begin(), ilists.end(), ilisted.begin());
	//	/*���õİ汾��
	//		copy()
	//			_copy_dispatch()
	//				_copy(input_iterator)*/

	//	//����5
	//	//vector������������Ϊԭ��ָ�루native pointer��
	//	vector<int >ivec(ia, ia + 5);
	//	vector<int>ivecd(5);
	//	copy(ivec.begin(), ivec.end(), ivecd.begin());
	//	/*copy()
	//		_copy_dispatch(T*,T*)
	//			_copy_t(_ture_type)*/

	//	//����6
	//	//class C�߱�trivial operator=
	//	copy_test::C c[5];
	//	vector<copy_test::C>Cvs(c, c +5);
	//	vector<copy_test::C>Cvd(5);
	//	copy(Cvs.begin(), Cvs.end(), Cvd.end());
	//	/*copy()
	//		_copy_dispatch(T*,T*)
	//			_copy_t(_false_type)
	//				_copy_d*/

	//	//����7
	//	//deque������������Ϊ random access Iterator
	//	deque<copy_test::C>Cds(c, c + 5);
	//	deque<copy_test::C>Cdd( 5);
	//	copy(Cds.begin(), Cds.end(), Cdd.end());
	//	/*copy()
	//		_copy_dispatch()
	//			_copy(random_access_iterator)
	//				_copy_d()*/

	//	//����8
	//	//class String�����ڡ�string.h���ڣ�ӵ��non-trivial operator=
	//	vector<String>strvs(5);
	//	vector<String>strvd(5);
	//	strvs[0] = "jjhou";
	//	strvs[1] = "grace";
	//	strvs[2] = "david";
	//	strvs[3] = "jeason";
	//	strvs[4] = "jerry";
	//	copy(strvs.begin(), strvs.end(), strvd.end());
	//	/*copy()
	//		_copy_dispatch(T*,T*)
	//			_copy_t(_false_type)
	//				_copy_d()*/

	//	//����9
	//	//deque������������Ϊrandom access iterator
	//	deque<String>strds(5);
	//	deque<String>strdd(5);
	//	strds.push_back("jjhou");
	//	strds.push_back("grace");
	//	strds.push_back("david");
	//	strds.push_back("jeason");
	//	strds.push_back("jerry");
	//	copy(strds.begin(), strds.end(), strdd.end());
	//	/*copy()
	//		_copy_dispatch()
	//			_copy_t(random_access_iterator)
	//				_copy_d()*/
	//}

	//copy_backward
//	{
//		{
//		int ia[] = { 0,1,2,3,4,5,6,7,8 };
//		//���£����������յ������������ص���û����
//		std::copy_backward(ia + 2, ia + 7, ia + 9);
//		for_each(ia, ia + 9, copy_backward_overlap::display<int>());
//		cout << endl;//0 1 2 3 2 3 4 5 6
//		}
//
//		{
//			int ia[] = { 0,1,2,3,4,5,6,7,8 };
//			//���£�����������������������ص������ܻ�������
//			std::copy_backward(ia + 2, ia + 7, ia + 5);
//			for_each(ia, ia + 9, copy_backward_overlap::display<int>());
//			cout << endl;//2 3 4 5 6 5 6 7 8
//			//���������ȷ����Ϊ���õ�copy�㷨ʹ��memmove()ִ��ʵ�ʸ��Ʋ���
//		}
//
//		{
//			int ia[] = { 0,1,2,3,4,5,6,7,8 };
//			deque<int>id(ia, ia + 9);
//
//			deque<int>::iterator first = id.begin();
//			deque<int>::iterator last = id.end();
//			++++first;//advance(first,2)
//			cout << *first << endl;//2
//			----last;//advance(first,-2)
//			cout << *last << endl;//7
//
//			deque<int>::iterator result = id.end();
//			//���£����������յ������������ص���û����
//			std::copy_backward(first, last, result);
//			for_each(id.begin(), id.end(), copy_backward_overlap::display<int>());
//			cout << endl;//0 1 2 3 2 3 4 5 6
//		}
//
//		{
//			int ia[] = { 0,1,2,3,4,5,6,7,8 };
//			deque<int>id(ia, ia + 9);
//
//			deque<int>::iterator first = id.begin();
//			deque<int>::iterator last = id.end();
//			++++first;//advance(first,2)
//			cout << *first << endl;//2
//			----last;//advance(first,-2)
//			cout << *last << endl;//7
//
//			deque<int>::iterator result = id.end();
//			advance(result, 5);
//			cout << *result << endl;
//			//���£�����������������������ص������ܻ�������
//			std::copy_backward(first, last, result);
//			for_each(id.begin(), id.end(), copy_backward_overlap::display<int>());
//			cout << endl;//656565678
//			//�������������Ϊ���õ�copy�㷨����ʹ��memmove()ִ��ʵ�ʸ��Ʋ���
//		}
//	}
//}