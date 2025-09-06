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
//如果两个序列在[first,last)区间内相等，equal()返回true，如果第二序列的元素比较多，多出来的元素不予考虑

//if (vec1.size() == vec2.size() && equal(vec1.begin(), vec1.end(), vec2.begin()));
//equality，如果第二序列的元素比第一序列少，这个算法内部进行迭代行为时，会超越序列的尾端，造成不可预测的后果
//版1缺省采用元素类型所提供的equlity操作符来进行大小比较
//版2允许指定仿函数pred作为比较依赖

//template<class InputIterator1,class InputIterator2 >
//inline bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
//	//以下，将序列一走过一遍，序列二亦步亦趋
//	//如果序列一的元素个数多过序列二的元素个数，就麻烦了
//	for (; first1 != last1; ++first1, ++first2)
//		if (*first1 != *first2)//只要对应元素不相等
//			return false;//就结束并返回false
//	return true;//至此，全部相等，返回true
//}

//template<class InputIterator1, class InputIterator2,class BinaryPredicate >
//inline bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,BinaryPredicate binary_pred) {
//	for (; first1 != last1; ++first1, ++first2)
//		if (!binary_pred( *first1 , *first2))
//			return false;
//	return true;
//}

//fill
//将[first,last)内的所有元素改填新值
//template<class ForwardIterator,class T>
//void fill(ForwardIterator first, ForwardIterator last, const T& value) {
//	for (; first != last; ++first)//迭代走过整个区间
//		*first = value;//设定新值
//}

//fill_n
//将[first,last)内的前n个元素改填新值，返回迭代器指向被填入的最后一个元素的下一位置

//template<class OutputIterator,class Size,class T>
//OutputIterator fill_n(OutputIterator first, Size n, const T& value) {
//	for (; n > 0; --n, ++first)//经过n个元素
//		*first = value;//设定新值
//	return first;
//}
//
//int ia[3] = { 0, 1, 2 };
//vector<int> iv(ia, ia + 3);
//
//fill_n(iv.begin(), 5,7);

//由于每次迭代进行的是assignment操作，是一种覆写（overwrite）操作，所以一旦操作区间超越了容器大小，就会造成不可预期的结果
//解决方法之一是，利用inserter()产生一个具有插入（insert）而非覆写能力的迭代器

//int ia[3] = { 0, 1, 2 };
//vector<int> iv(ia, ia + 3);//0 1 2 
//fill_n(inserter(iv, iv.begin()), 5, 7);//77777012

//iter_swap
//将两个ForwardIterators所指的对象对调

//template<class ForwardIterator1, class ForwardIterator2>
//inline void iter_swap(ForwardIterator1 a, ForwardIterator2 b) {
//	_iter_swap(a, b, value_type(a));;//注意第三参数的限制
//}
//
//template<class ForwardIterator1, class ForwardIterator2,class T>
//inline void _iter_swap(ForwardIterator1 a, ForwardIterator2 b, T*) {
//	T tmp = *a;
//	*a = *b;
//	*b = tmp;
//}

//iter_swap()必须知道迭代器的value type，才能够据此声明一个对象，用来暂存迭代器所指对象

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
//以“字典排序方式”对两个序列[first1,last1)和[first2,last2)进行比较

//版2允许指定一个仿函数comp作为比较操作之用，取代元素类型所提供的less-than操作符
//template<class InputIterator1, class InputIterator2>
//bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
//	//以下，任何一个序列到达尾端，就结束，否则两序列就相应元素一一比对
//	for (; firs1 != last1 && first2 != last2; ++first1, ++first2) {
//		//第一序列元素值小于第二序列的相应元素值
//		if (*first1 < *first2)
//			return true;
//		//第二序列元素值小于第一序列的相应元素值
//		if (*first2 < *first1)
//			return false;
//		//如果不符合以上两条件，表示两值相等，进行下一组匹配
//	}
//	//进行到这里，如果第一序列到达尾端而第二序列尚有余额，那么第一序列小于第二序列
//	return first1 == last1 && first2 != last2;
//}

//template<class InputIterator1, class InputIterator2, class Compare>
//bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
//	for (; firs1 != last1 && first2 != last2; ++first1, ++first2) {
//		if (comp(*first1, *first2))
//			return true;
//		//第二序列元素值小于第一序列的相应元素值
//		if (comp(*first2, *first1))
//			return false;
//		//如果不符合以上两条件，表示两值相等，进行下一组匹配
//	}
//	//进行到这里，如果第一序列到达尾端而第二序列尚有余额，那么第一序列小于第二序列
//	return first1 == last1 && first2 != last2;
//}

//用于原生指针 const unsigned char*
//inline bool
//lexicographical_compare(const unsigned char* first1,
//	const unsigned char* last1,
//	const unsigned char* first2,
//	const unsigned char* last2) {
//	const size_t len1 = last1 - first1;//第一序列长度
//	const size_t len2 = last2 - first2;//第二序列长度
//	//先比较相同长度的一段，memcmp（）速度极快
//	const int result = memcmp(first1, first2, min(len1, len2));
//	//如果不相上下，则长度较长者被视为比较大
//	return result != 0 ? result < 0 : len1 < len2;
//}

//max
//取两个对象中的较大者
//template<class T>
//inline const T& max(const T& a, const T& b) {
//	return a < b ? b : a;
//}
//
//template<class T,class Compare>
//inline const T& max(const T& a, const T& b,Compare comp) {
//	return comp( a , b) ? b : a;//由comp决定大小比较标准
//}

//min
//取两个对象中的较小者
//template<class T>
//inline const T& min(const T& a, const T& b) {
//	return  b<a  ? b : a;
//}
//
//template<class T, class Compare>
//inline const T& min(const T& a, const T& b, Compare comp) {
//	return comp( b,a) ? b : a;//由comp决定大小比较标准
//}

//mismatch
//用来平行比较两个序列，指出两者之间第一个不匹配点

//template<class InputIterator1, class InputIterator2>
//pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator1 first2) {
//	//以下，如果序列一走完，就结束
//	//以下，如果序列一和序列二的对应元素相等，就结束
//	//序列一的元素个数必须多于序列二的元素个数，否则结果无可预期
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
//该函数用来交换（对调）两个对象的内容
//template<class T>
//inline void swap(T& a, T& b) {
//	T tmp = a;
//	a = b;
//	b = tmp;
//}

//由于copy进行的是复制操作，而复杂操作不外乎运用assignment operator或copy construct（copy算法用前者），但是某些元素类型拥有的是trivial assignment operator，因此如果能够使用内存直接复制行为，便能够节省大量时间

//copy算法可将输入区间[first,last)内的元素复制到输出区间[result,result+(last-first))内

//对于每个从0到last-first（不含）的整数n，copy执行赋值操作*(result+n)=*(first+n)。赋值操作是向前（亦即累加n）推进的

//copy算法是一一进行元素的赋值操作，如果输出区间的起点位于输入区间内，copy算法便（可能）会在输入区间的（某些）元素尚未被复制之前，就覆盖其值，导致错误结果

//namespace copy_overlap {
//	template<class T>
//	struct display {
//		void operator()(const T& x) {
//			cout << x << ' ';
//		}
//	};
//}

//如果以vector取代deque进行测试，复制结果将是正确的，因为vector迭代器其实是个原生指针，导致调用的copy算法以memmove()执行实际复制操作

//copy更改的是[result,result+(last-first))中迭代器所指对象，而非更改迭代器本身

//要将元素插入（而非赋值）序列之内，使用序列容器的insert，或使用copy算法并搭配insert_iterator

//完全泛化版本
//template<class InputIterator,class OutputIterator>
//inline OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result) {
//	return _copy_dispatch<InputIterator, OutputIterator>() {
//		first, last, result;
//	}
//}

//多载函数，针对原生指针（可视为一种特殊的迭代器）const char*和const wchar_t*，进行内存直接拷贝操作

//特殊版本1，重载形式
//inline char* copy(const char* first, const char* last, char* result) {
//	memmove(result, first, last - first);
//	return result + (last - first);
//}

//特殊版本2，重载形式
//inline wchar_t* copy(const wchar_t* first, const wchar_t* last, wchar_t* result) {
//	memmove(result, first,sizeof(wchar_t)*( last - first));
//	return result + (last - first);
//}

//完全泛化版本
//template <class InputIterator,class OutputIterator>
//struct _copy_dispatch {
//	OutputIterator operator()(InputIterator first, InputIterator last, OutputIterator result) {
//		return _copy(first, last, result, iterator_category(first));
//	}
//};

//偏特化版本1，两个参数都是T*指针形式
//template<class T>
//struct _copy_dispatch<T*, T*> {
//	T* operator()(T* first, T* last, T* result) {
//		typedef typename _type_traits<T>::has_trivial_assignment_operator t;
//		return _copy_t(first, last, result, t());
//	}
//};

//偏特化版本2，第一个参数为const T*，第二参数为T*指针形式
//template<class T>
//struct _copy_dispatch<const T*, T*> {
//	T* operator()(const T* first, const T* last, T* result) {
//		typedef typename _type_traits<T>::has_trivial_assignment_operator t;
//		return _copy_t(first, last, result, t());
//	}
//};

//_copy_dispatch()的完全泛化版根据迭代器种类的不同，调用了不同的_copy()，为的是不同种类的迭代器所使用的循环条件不同，有快慢之分

//InputIterator版本
//template<class InputIterator, class OutputIterator>
//inline OutputIterator _copy(InputIterator first, InputIterator last, OutputIterator result, input_iterator_tag) {
//	//以迭代器等同与否，决定循环是否继续，速度慢
//	for (; first != last; ++result, ++first)
//		*result = *first;//assignment operator
//	return result;
//}

//RandomAccessIterator版本
//template<class RandomAccessIterator,class OutputIterator >
//inline OutputIterator _copy(RandomAccessIterator first, RandomAccessIterator last, OutputIterator result, random_access_iterator_tag) {
//	//又划分出一个函数，为的是其它地方也可能用到
//	return _copy_d(first, last, result, distance_type(first));
//}

//template<class RandomAccessIterator, class OutputIterator,class Distance >
//inline OutputIterator _copy_d(RandomAccessIterator first, RandomAccessIterator last, OutputIterator result, Distance*) {
//	//以n决定循环的执行次数，速度快
//	for (Distance n = last - first; n > 0; --n, ++result, ++first)
//		*result = *first;
//	return *result;
//}

//以下版本适用于“指针所指的对象具备trivial assignment operator”
//template <class T>
//inline T* _copy_t(const T* first, const T* last, T* result, _true_type) {
//	memmove(result, first, sizeof(T) * (last - first));
//	return result + (last - first);
//}

//以下版本适用于“指针所指的对象具备 non-trivial assignment operator”
//template <class T>
//inline T* _copy_t(const T* first, const T* last, T* result, _false_type) {
//	//原生指针属于一种RandomAccessIterator，所以交给_copy_d()完成
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

//vecotr ctor调用了copy()

//我们以为vector的迭代器是random access iterator 但实际上它是个T*

//既然class C具备trivial operator=，为什么它被判断为一个_false_type?
//因为编译器之中，有能力验证“用户自定义类型”的类型特性者很少，<type_traits.h>内只针对C++的标量类型做了类型特性记录
//程序中所有的用户自定义线类型，都被编译器视为拥有non-trivial ctor/dtor/operator=

//借用<type_traits.h>中的_type_traits<T>,针对class c做一个特化版本
//编译器无力辨别class C的特性(*traits)
//当编译器支持partial specialization,_STL_TEMPLATE_NULL被设定为tempalte<>
//_STL_TEMPLATE_NULL struct _type_traits<copy_test::C> {
//	typedef _false_type has_trivial_default_constructor;
//	typedef _true_type has_trivial_copy_constructor;
//	typedef _true_type has_trivial_assignment_operator;
//	typedef _false_type is_POD_type;
//};

//copy_backward
//template<class BidirectionalIterator1, class BidirectionalIterator2>
//inline BidirectionalIterator2 copy_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 result);

//将[first,last)区间内的每一个元素，以逆行的方向复制到以result-1为起点，方向亦为逆行的区间上
//copy_backward所接受的迭代器必须是BidirectionalIterator

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
	//	//以上判断两个区间的第一个不匹配点，返回一个由两个迭代器组成的pair
	//	//其中第一个迭代器指向第一区间的不匹配点，第二个迭代器指向第二区间的不匹配点
	//	//上述写法很危险，应该先判断迭代器是否不等于容器的end（），然后才可以做输出操作

	//	//如果两个序列在[first,last)区间内相等，equal()返回true
	//	//如果第二序列的元素比较多，多出来的元素不予考虑
	//	//cout << equal(iv1.begin(), iv1.end(), iv2.begin());//1

	//	//cout << equal(iv1.begin(), iv1.end(), &ia[3]);//0
	//	//{0,1,2,3,4}!={ 3,4,5,6,7 }

	//	//cout << equal(iv1.begin(), iv1.end(), &ia[3], less<int>());//1
	//	//{0,1,2,3,4}<{ 3,4,5,6,7 }

	//	//fill(iv1.begin(), iv1.end(), 9);//区间内全部填9
	//	//for_each(iv1.begin(), iv1.end(), algobase::display<int>());//9 9 9 9 9

	//	//fill_n(iv1.begin(), 3, 7);//从迭代器所指位置开始，填3个7
	//	//for_each(iv1.begin(), iv1.end(), algobase::display<int>());//7 7 7 3 4

	//	vector<int>::iterator ite1 = iv1.begin();//指向7
	//	vector<int>::iterator ite2 = ite1;
	//	advance(ite2, 3);//指向9

	//	//iter_swap(ite1, ite2);//迭代器所指元素对调
	//	//cout << *ite1 << ' ' << *ite2 << endl;//3 0
	//	//for_each(iv1.begin(), iv1.end(), algobase::display<int>());//3 1 2 0 4

	//	//以下取两值中最大的
	//	//cout << max(*ite1, *ite2) << endl;//3

	//	////以下取两值中最小的
	//	//cout <<min(*ite1, *ite2) << endl;// 0

	//	//千万不要错写成以下那样，意思是，取两个迭代器（本身）大的（或小的）
	//	//然后再打印其所指的值，注意，迭代器本身的大小，对用户没有意义
	//	//cout << *max(ite1, ite2) << endl;//3
	//	//cout << *min(ite1, ite2) << endl;//0

	//	//swap(*iv1.begin(), *iv2.begin());//将两数值对调
	//	//for_each(iv1.begin(), iv1.end(), algobase::display<int>());//0 1 2 3 4
	//	//for_each(iv2.begin(), iv2.end(), algobase::display<int>());//0 1 2 3 4 5 6 7 8

	//	//准备两个字符串数组
	//	string stra1[] = { "Jamie","JJHou","Jason" };
	//	string stra2[] = { "Jamie","JJhou","Jerry" };

	//	cout << lexicographical_compare(stra1, stra1 + 2, stra2, stra2 + 2);//1
	//	cout << lexicographical_compare(stra1, stra1 + 2, stra2, stra2 + 2, greater<string>());//0
	//}

	//copy_overlap.cpp
	//{
	//	{
	//	int ia[] = { 0,1,2,3,4,5,6,7,8 };

	//	//以下，输出区间的终点与输出区间重叠，没问题
	//	copy(ia + 2, ia + 7, ia);
	//	for_each(ia, ia + 9, copy_overlap::display<int>());//2 3 4 5 6 5 6 7 8
	//	cout << endl;
	//	}

	//	{
	//		int ia[] = { 0,1,2,3,4,5,6,7,8 };
	//		//以下，输出区间的起点与输出区间重叠，可能会有问题
	//		copy(ia + 2, ia + 7, ia+4);
	//		for_each(ia, ia + 9, copy_overlap::display<int>());//0 1 2 3 2 3 4 5 6
	//		cout << endl;
	//		//本例结果正确，因为调用的copy算法使用memmove()执行复制操作
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

	//		//以下，输出区间的终点与输入区间重叠，没问题
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

	//		//以下，输出区间的起点与输入区间重叠，可能会有问题
	//		copy(first, last, result);
	//		for_each(id.begin(), id.end(), copy_overlap::display<int>());//0 1 2 3 2 3 2 3 2
	//		cout << endl;
	//		//本例结果错误，因为调用的copy算法不再使用memmove()执行复制操作
	//	}
	//}

	//{
	//	//测试1
	//	const char ccs[5] = { 'a','b','c','d','e' };//数据来源
	//	char ccd[5];//数据去处
	//	copy(ccs, ccs + 5, ccd);
	//	//调用的版本是copy(const char*)

	//	//测试2
	//	const wchar_t cwcs[5] = { 'a','b','c','d','e' };//数据来源
	//	wchar_t cwcd[5];//数据去处
	//	copy(cwcs, cwcs + 5, cwcd);
	//	//调用的版本是copy(const wchar_t*)

	//	//测试3
	//	int ia[5] = { 0,1,2,3,4 };
	//	copy(ia, ia + 5, ia);//数据来源和去处相同，这是允许的
	//	/*调用的版本是
	//		copy()
	//			_copy_dispatch(T*,T*)
	//				_copy_t(_true_type)*/

	//	//测试4
	//	//list迭代器被归类为InputIterator
	//	list<int>ilists(ia, ia + 5); //数据来源
	//	list<int>ilisted(5);//数据去处
	//	copy(ilists.begin(), ilists.end(), ilisted.begin());
	//	/*调用的版本是
	//		copy()
	//			_copy_dispatch()
	//				_copy(input_iterator)*/

	//	//测试5
	//	//vector迭代器被归类为原生指针（native pointer）
	//	vector<int >ivec(ia, ia + 5);
	//	vector<int>ivecd(5);
	//	copy(ivec.begin(), ivec.end(), ivecd.begin());
	//	/*copy()
	//		_copy_dispatch(T*,T*)
	//			_copy_t(_ture_type)*/

	//	//测试6
	//	//class C具备trivial operator=
	//	copy_test::C c[5];
	//	vector<copy_test::C>Cvs(c, c +5);
	//	vector<copy_test::C>Cvd(5);
	//	copy(Cvs.begin(), Cvs.end(), Cvd.end());
	//	/*copy()
	//		_copy_dispatch(T*,T*)
	//			_copy_t(_false_type)
	//				_copy_d*/

	//	//测试7
	//	//deque迭代器被归类为 random access Iterator
	//	deque<copy_test::C>Cds(c, c + 5);
	//	deque<copy_test::C>Cdd( 5);
	//	copy(Cds.begin(), Cds.end(), Cdd.end());
	//	/*copy()
	//		_copy_dispatch()
	//			_copy(random_access_iterator)
	//				_copy_d()*/

	//	//测试8
	//	//class String定义于“string.h”内，拥有non-trivial operator=
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

	//	//测试9
	//	//deque迭代器被归类为random access iterator
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
//		//以下，输出区间的终点与输入区间重叠，没问题
//		std::copy_backward(ia + 2, ia + 7, ia + 9);
//		for_each(ia, ia + 9, copy_backward_overlap::display<int>());
//		cout << endl;//0 1 2 3 2 3 4 5 6
//		}
//
//		{
//			int ia[] = { 0,1,2,3,4,5,6,7,8 };
//			//以下，输出区间的起点与输入区间重叠，可能会有问题
//			std::copy_backward(ia + 2, ia + 7, ia + 5);
//			for_each(ia, ia + 9, copy_backward_overlap::display<int>());
//			cout << endl;//2 3 4 5 6 5 6 7 8
//			//本例结果正确，因为调用的copy算法使用memmove()执行实际复制操作
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
//			//以下，输出区间的终点与输入区间重叠，没问题
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
//			//以下，输出区间的起点与输入区间重叠，可能会有问题
//			std::copy_backward(first, last, result);
//			for_each(id.begin(), id.end(), copy_backward_overlap::display<int>());
//			cout << endl;//656565678
//			//本例结果错误，因为调用的copy算法不再使用memmove()执行实际复制操作
//		}
//	}
//}