//STL一共提供了四种与set相关的算法，并集（union），交集（intersection），差集（difference），对称差集（symmetric difference）

//set可分为数学上的定义和STL的定义
//数学上的set允许元素重复而未经排序
//STL的定义则要求元素不得重复，并且经过排序
//四个算法所接受的set，必须是有序区间（sorted range），元素值得重复出现

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
//set_union可构造S1,S2的并集
//此集合内含S1，S2内的每一个元素

//由于S1和S2内的每个元素都不需唯一，因此，如果某个值在S1出现n次，在S2出现m次，那么该值在输出区间中会出现max(m,n)次，其中n个来自s1，其余来自s2

//set_union是一种稳定（stable）操作，意思是输入区间内的每个元素的相对顺序都不会改变

//并集，求存在于[first1,last1)或存在于[first2,last2)的所有元素
//set是一种sorted range，这是以下算法的前提
template<class InputIterator1,class InputIterator2,class OutputIterator>
OutputIterator set_union(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result) {
	//当两个区间都尚未到达尾端时，执行以下操作
	while (first1 != last1 && first2 != last2) {
		/* 当两区间内分别移动迭代器，首先将元素值较小者（假设为A区）记录于目标区，然后移动A区迭代器使之前进，同时间的另一个区迭代器不动，然后进行新一次的比大小，记录小值，迭代器移动……直到两区中有一区到达尾端，如果元素相等，取S1者记录于目标区，并同时移动两个迭代器*/
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
	//只要两区中有一区到达尾端，就结束上述的while循环
	//以下将尚未到达尾端的区间的所有剩余元素拷贝到目的端
	//此刻的[first1,last1),[first2,last2)之中有一个是空白区
	return copy(first2, last2, copy(first1, last1, result));
}

//set_intersection
//set_intersection可构造s1，s2的交集
//此集合内含同时出现于s1和s2内的每一个元素

//稳定操作

//交集，求存在于[first1,last1)且存在于[first2,last2)的所有元素

template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result) {
	//当两个区间都尚未到达尾端时，执行以下操作
	while (first1 != last1 && first2 != last2) {
		//在两区内分别移动迭代器，直到遇有元素相同，暂停，将该值记录于目标区
		//再继续移动迭代器，直到两区中有一区到达尾端
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
//set_difference可构造s1，s2的差集
//此集合内含“出现在s1但不出现于s2”的每一个元素，s1，s2及其交集都是以排序区间表示

//稳定操作

//差集，求存在于[first1,last1)且不存在于[first2,last2)的所有元素
template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result) {
	//当两个区间都尚未到达尾端时，执行以下操作
	while (first1 != last1 && first2 != last2) {
		//在两区间内分别移动迭代器，当第一区间的元素等于第二区间的元素（表示此值同时存在于两区间），就让两区间同时前进，当第一区间的元素大于第二区间的元素，就让第二区间前进：有了这两种处理，就保证第一区间的元素小于第二区间的元素时，第二区间的元素只存在于第一区间，不存在第二区间，于是将它记录于目标区
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
//set_symmetric_difference可构造s1，s2的对称差集
//此集合内含“出现于s1但不出现于s2”以及“出现于s2但不出现于s1”的每一个元素

//稳定操作

//对称差集，求存在于[first1,last1)且不存在于[first2,last2)的所有元素
//以及存在于[first2,last2)且不存在于[first1,last1)的所有元素
//注意：上述定义只有在“元素值独一无二”的情况下才成立，如果将set一般化，允许出现重复元素，那么set_symmetric_difference的定义应该是：
//如果某值在[first1,last1)出现n次，在[first2,last2)出现m次,
//那么它在result range中应该出现abs(n-m)次
template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result) {
	//当两个区间都尚未到达尾端时，执行以下操作
	while (first1 != last1 && first2 != last2) {
		//当两区间内分别移动迭代器，当两区间内的元素相等,就让两区同时前进
		//当两区间内的元素不等，就记录叫较小值于目标区，并且较小值所在区间前进
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