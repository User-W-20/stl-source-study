//#include<numeric>
//#include<vector>
//#include<functional>
//#include<iostream>
//#include<iterator>
//using namespace std;
//
//int main() {
//	int ia[5] = { 1,2,3,4,5 };
//	vector<int> iv(ia, ia + 5);
//
//	cout << accumulate(iv.begin(), iv.end(), 0) << endl;
//	//15 0+1+2+3+4+5
//
//	cout << accumulate(iv.begin(), iv.end(), 0,minus<int>()) << endl;
//	//-15 0-1-2-3-4-5
//
//	cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10) << endl;
//	//65 10+1*1+2*2+3*3+4*4+5*5
//
//	cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10,minus<int>(), plus<int>()) << endl;
//	//-20 10-1+1-2+2-3+3-4+4-5+5
//
//	//以下这个迭代器将绑定到cout，作为输出用
//	ostream_iterator<int>oite(cout, " ");
//	partial_sum(iv.begin(), iv.end(), oite);
//	//1 3 6 10 15(第n个新元素是前n个旧元素的相加总计)
//
//	partial_sum(iv.begin(), iv.end(), oite,minus<int>());
//	//1 -1 -4 -8 -13(第n个新元素是前n个旧元素的相加总计)
//
//	adjacent_difference(iv.begin(), iv.end(), oite);
//	//1 1 1 1 1 （#1元素照录，#n新元素等于#n旧元素-#n旧元素）
//
//	adjacent_difference(iv.begin(), iv.end(), oite,plus<int>());
//	//1 3 5 7 9（#1元素照录，#n新元素等于op(#n旧元素,#n-1旧元素)）
//	cout << endl;
//	int n = 3;
//	iota(iv.begin(), iv.end(), n);//在指定区间内填入n,n+1,n+2
//	for (int i = 0; i < iv.size(); ++i)
//		cout << iv[i] << ' ';//3 4 5 6 7
//}

//accumulate
//版本1
//template<class InputIterator ,class T>
//T accumulate(InputIterator first, InputIterator last, T init) {
//	for (; first != last; ++first)
//		init = init + *first;//将每个元素值累加到初值init上
//	return init;
//}

//版本2
//template<class InputIterator, class T,class BinaryOperation>
//T accumulate(InputIterator first, InputIterator last, T init,BinaryOperation binary_op) {
//	for (; first != last; ++first)
//		//对每一个元素执行二元操作
//		init = binary_op( init , *first);
//	return init;
//}

//accumulate用来计算init和[first,last)内所有元素的总和
//一定得提供一个初始值init，当[first,last)为空区间时仍能获得一个明确定义的值
//如果希望计算[first,last)中所有数值的总和，应该将init设为0

//二元操作符不必满足交换律（commutative）和结合律（associative）

//accumulate的行为顺序有明确的定义，先将init初始化，然后针对[first,last)区间中的每一个迭代器i，依次执行init=init+*i（第一版）和init=binary_op(first,*i)(第二版)

//adjacent_difference
//版本1
//template<class InputIterator, class OutputIterator>
//OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result) {
//	if (first == last)return result;
//	*result = *first;//首先记录第一个元素
//	return _adjacent_difference(first, last, result, value_type(first));

	//if (first == last)return result;
	//*result = *first;
	//iterator_traits<InputIterator>::value_type value = *first;
	//while(++first!=last)//遍历整个区间
	////以下同_adjacent_difference对应的内容
//}

//template<class InputIterator, class OutputIterator ,class T>
//OutputIterator _adjacent_difference(InputIterator first, InputIterator last, OutputIterator result, T*) {
//	T value = *first;
//	while (++first != last) {//遍历区间
//		T tmp = *first;
//		//将相邻两元素的差额（后-前），赋值给目的端
//		*++result = tmp - value;
//		value = tmp;
//	}
//	return ++result;
//}

//版本2
//template<class InputIterator, class OutputIterator,class BinaryOperation>
//OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result,BinaryOperation binary_op) {
//	if (first == last)return result;
//	*result = *first;//首先记录第一个元素
//	return _adjacent_difference(first, last, result, value_type(first),binary_op);
//}

//template<class InputIterator, class OutputIterator, class T, class BinaryOperation>
//OutputIterator _adjacent_difference(InputIterator first, InputIterator last, OutputIterator result, T*,BinaryOperation binary_op) {
//	T value = *first;
//	while (++first != last) {//遍历区间
//		T tmp = *first;
//		//将相邻两元素的差额（后-前），赋值给目的端
//		*++result =binary_op( tmp - value);
//		value = tmp;
//	}
//	return ++result;
//}

//adjacent_difference用来计算[first,last)中相邻元素的差额
//将*first赋值给*result，并针对[first,last)内的每个迭代器i，将*i-*(i-1)的值赋值给*(result+(i-first))

//可以采用就地（in place）运算方式，令result=first 质变算法

//存储第一元素的值，然后存储后继元素的差值
//这么以来便有足够的信息可以重建输入区间的原始内容

//第一版本使用operato-，第二版本使用外部提供的二元仿函数

//版2将binary_op(*i,*(i-1))的运算结果赋值给*(result+(i-first))

//inner_product
//版1
//template<class InputIterator1,class InputIterator2,class T>
//T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init) {
//	//以第一序列的元素为据，将两个序列都走一遍
//	for (; first1 != last1; ++first1, ++first2)
//		init = init + (*first1 * *first2);//执行两个序列的一般内积
//	return init;
//}

//版2
//template<class InputIterator1, class InputIterator2, class T,class BinaryOperation1, class BinaryOperation2>
//T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init,BinaryOperation1 binary_op1, BinaryOperation2 binary_op2) {
//	//以第一序列的元素为据，将两个序列都走一遍
//	for (; first1 != last1; ++first1, ++first2)
//		//以外界提供的仿函数来取代第一个版本中的operator*和operator+
//		init = binary_op1( init ,binary_op2( *first1 , *first2));
//	return init;
//}

//inner_product能够计算[first1,last1)和[first2,first2+[last1-first1))的一般内积（generalized inner product）
//一定得提供init，当[first,last)为空时，仍可获得一个明确定义的结果
//计算两个vectors的一般内积，应该将init设为0

//版1会将两个区间的内积结果加上init
//先将结果初始化为init，然后针对[first,last)的每一个迭代器i，由头至尾依序执行result=result+(*i)* *(first2+(i-first1))

//版2和版1唯一差异是以外界提供的仿函数来取代operator*和operator+
//首先将结果初始化为init，然后针对[first1,last1)的每一个迭代器i，由头至尾依序执行result=binary_op1(result,binary_op2(*i,*(first2+(i-first1))

//partial_sum
//版本1
//template<class InputIterator, class OutputIterator>
//OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result) {
//	if (first == last)return result;
//	*result = *first;
//	return _partial_sum(first, last, result, value_type(first));
//}

//template<class InputIterator, class OutputIterator,class T>
//OutputIterator _partial_sum(InputIterator first, InputIterator last, OutputIterator result, T*) {
//	T value = *first;
//	while (++first != last) {
//		value = value + *first;//前n个元素的总和
//		*++result = value;//指定给目的端
//	}
//	return ++result;
//}

//版2
//template<class InputIterator, class OutputIterator,class BinaryOperation>
//OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result,BinaryOperation binary_op) {
//	if (first == last)return result;
//	*result = *first;
//	return _partial_sum(first, last, result, value_type(first),binary_op);
//}

//template<class InputIterator, class OutputIterator, class T, class BinaryOperation>
//OutputIterator _partial_sum(InputIterator first, InputIterator last, OutputIterator result, T*, BinaryOperation binary_op) {
//	T value = *first;
//	while (++first != last) {
//		value = binary_op( value , *first);//前n个元素的总和
//		*++result = value;//指定给目的端
//	}
//	return ++result;
//}

//partial_sum用来计算局部总和
//将*first赋值给*result，将*first和*(first+1)的和赋值给*(result+1)
//result可以等于first，使得可以完成就地（in place）计算
//质变算法

//运算中的总和首先初始为*first，然后赋值给*result
//对于[first+1,last)中每个迭代器i，从头至尾执行sum=sum+*i(版1)或sum=binary_op(sum,*i)(版2)，然后再将sum赋值给*(result+(i-first))

//本算法返回输出区间的最尾端位置：result+(last-first)

//power
//SGI专属
//用来计算某术的n幂次方
//n幂次是指自己对自己进行的某种运算，达n次，运算类型可由外界指定

//版1,乘幂
//template<class T,class Interger>
//inline T power(T x, Interger n) {
//	return power(x, n, multiplies<T>());//指定运算型式为乘法
//}

//版2，幂次方，如果指定为乘法运算，则当n>=0是返回x^n
//注意：MonoidOperation必须满足结合律（associative）
//但不需满足交换律（commutative）
//template<class T,class Interger,class MonoidOperation>
//T power(Tx, Interger n, MonoidOperation op) {
//	if (n == 0)
//		return identity_elem(op);//取出“证同元素”
//	else {
//		while ((n & 1) == 0) {
//			n >>= 1;
//			x = op(x, x);
//		}
//
//		T result = x;
//		n >>= 1;
//		while (n != 0) {
//			x = op(x, x);
//			if ((n & 1) != 0)
//				result = op(result, x);
//			n >>= 1;
//		}
//		return result;
//	}
//}

//itoa
//用来设定某个区间的内容，是使其内的每一个元素从指定的value值开始，呈现递增状态
//质变算法
//函数意义：在[first,last)区间内填入value，value+1，value+2
//template<class ForwardIterator,class T>
//void iota(ForwardIterator first, ForwardIterator last, T value) {
//	while (first != last)
//		*first++ = value++;
//}