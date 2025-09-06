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
//	//����������������󶨵�cout����Ϊ�����
//	ostream_iterator<int>oite(cout, " ");
//	partial_sum(iv.begin(), iv.end(), oite);
//	//1 3 6 10 15(��n����Ԫ����ǰn����Ԫ�ص�����ܼ�)
//
//	partial_sum(iv.begin(), iv.end(), oite,minus<int>());
//	//1 -1 -4 -8 -13(��n����Ԫ����ǰn����Ԫ�ص�����ܼ�)
//
//	adjacent_difference(iv.begin(), iv.end(), oite);
//	//1 1 1 1 1 ��#1Ԫ����¼��#n��Ԫ�ص���#n��Ԫ��-#n��Ԫ�أ�
//
//	adjacent_difference(iv.begin(), iv.end(), oite,plus<int>());
//	//1 3 5 7 9��#1Ԫ����¼��#n��Ԫ�ص���op(#n��Ԫ��,#n-1��Ԫ��)��
//	cout << endl;
//	int n = 3;
//	iota(iv.begin(), iv.end(), n);//��ָ������������n,n+1,n+2
//	for (int i = 0; i < iv.size(); ++i)
//		cout << iv[i] << ' ';//3 4 5 6 7
//}

//accumulate
//�汾1
//template<class InputIterator ,class T>
//T accumulate(InputIterator first, InputIterator last, T init) {
//	for (; first != last; ++first)
//		init = init + *first;//��ÿ��Ԫ��ֵ�ۼӵ���ֵinit��
//	return init;
//}

//�汾2
//template<class InputIterator, class T,class BinaryOperation>
//T accumulate(InputIterator first, InputIterator last, T init,BinaryOperation binary_op) {
//	for (; first != last; ++first)
//		//��ÿһ��Ԫ��ִ�ж�Ԫ����
//		init = binary_op( init , *first);
//	return init;
//}

//accumulate��������init��[first,last)������Ԫ�ص��ܺ�
//һ�����ṩһ����ʼֵinit����[first,last)Ϊ������ʱ���ܻ��һ����ȷ�����ֵ
//���ϣ������[first,last)��������ֵ���ܺͣ�Ӧ�ý�init��Ϊ0

//��Ԫ�������������㽻���ɣ�commutative���ͽ���ɣ�associative��

//accumulate����Ϊ˳������ȷ�Ķ��壬�Ƚ�init��ʼ����Ȼ�����[first,last)�����е�ÿһ��������i������ִ��init=init+*i����һ�棩��init=binary_op(first,*i)(�ڶ���)

//adjacent_difference
//�汾1
//template<class InputIterator, class OutputIterator>
//OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result) {
//	if (first == last)return result;
//	*result = *first;//���ȼ�¼��һ��Ԫ��
//	return _adjacent_difference(first, last, result, value_type(first));

	//if (first == last)return result;
	//*result = *first;
	//iterator_traits<InputIterator>::value_type value = *first;
	//while(++first!=last)//������������
	////����ͬ_adjacent_difference��Ӧ������
//}

//template<class InputIterator, class OutputIterator ,class T>
//OutputIterator _adjacent_difference(InputIterator first, InputIterator last, OutputIterator result, T*) {
//	T value = *first;
//	while (++first != last) {//��������
//		T tmp = *first;
//		//��������Ԫ�صĲ���-ǰ������ֵ��Ŀ�Ķ�
//		*++result = tmp - value;
//		value = tmp;
//	}
//	return ++result;
//}

//�汾2
//template<class InputIterator, class OutputIterator,class BinaryOperation>
//OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result,BinaryOperation binary_op) {
//	if (first == last)return result;
//	*result = *first;//���ȼ�¼��һ��Ԫ��
//	return _adjacent_difference(first, last, result, value_type(first),binary_op);
//}

//template<class InputIterator, class OutputIterator, class T, class BinaryOperation>
//OutputIterator _adjacent_difference(InputIterator first, InputIterator last, OutputIterator result, T*,BinaryOperation binary_op) {
//	T value = *first;
//	while (++first != last) {//��������
//		T tmp = *first;
//		//��������Ԫ�صĲ���-ǰ������ֵ��Ŀ�Ķ�
//		*++result =binary_op( tmp - value);
//		value = tmp;
//	}
//	return ++result;
//}

//adjacent_difference��������[first,last)������Ԫ�صĲ��
//��*first��ֵ��*result�������[first,last)�ڵ�ÿ��������i����*i-*(i-1)��ֵ��ֵ��*(result+(i-first))

//���Բ��þ͵أ�in place�����㷽ʽ����result=first �ʱ��㷨

//�洢��һԪ�ص�ֵ��Ȼ��洢���Ԫ�صĲ�ֵ
//��ô���������㹻����Ϣ�����ؽ����������ԭʼ����

//��һ�汾ʹ��operato-���ڶ��汾ʹ���ⲿ�ṩ�Ķ�Ԫ�º���

//��2��binary_op(*i,*(i-1))����������ֵ��*(result+(i-first))

//inner_product
//��1
//template<class InputIterator1,class InputIterator2,class T>
//T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init) {
//	//�Ե�һ���е�Ԫ��Ϊ�ݣ����������ж���һ��
//	for (; first1 != last1; ++first1, ++first2)
//		init = init + (*first1 * *first2);//ִ���������е�һ���ڻ�
//	return init;
//}

//��2
//template<class InputIterator1, class InputIterator2, class T,class BinaryOperation1, class BinaryOperation2>
//T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init,BinaryOperation1 binary_op1, BinaryOperation2 binary_op2) {
//	//�Ե�һ���е�Ԫ��Ϊ�ݣ����������ж���һ��
//	for (; first1 != last1; ++first1, ++first2)
//		//������ṩ�ķº�����ȡ����һ���汾�е�operator*��operator+
//		init = binary_op1( init ,binary_op2( *first1 , *first2));
//	return init;
//}

//inner_product�ܹ�����[first1,last1)��[first2,first2+[last1-first1))��һ���ڻ���generalized inner product��
//һ�����ṩinit����[first,last)Ϊ��ʱ���Կɻ��һ����ȷ����Ľ��
//��������vectors��һ���ڻ���Ӧ�ý�init��Ϊ0

//��1�Ὣ����������ڻ��������init
//�Ƚ������ʼ��Ϊinit��Ȼ�����[first,last)��ÿһ��������i����ͷ��β����ִ��result=result+(*i)* *(first2+(i-first1))

//��2�Ͱ�1Ψһ������������ṩ�ķº�����ȡ��operator*��operator+
//���Ƚ������ʼ��Ϊinit��Ȼ�����[first1,last1)��ÿһ��������i����ͷ��β����ִ��result=binary_op1(result,binary_op2(*i,*(first2+(i-first1))

//partial_sum
//�汾1
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
//		value = value + *first;//ǰn��Ԫ�ص��ܺ�
//		*++result = value;//ָ����Ŀ�Ķ�
//	}
//	return ++result;
//}

//��2
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
//		value = binary_op( value , *first);//ǰn��Ԫ�ص��ܺ�
//		*++result = value;//ָ����Ŀ�Ķ�
//	}
//	return ++result;
//}

//partial_sum��������ֲ��ܺ�
//��*first��ֵ��*result����*first��*(first+1)�ĺ͸�ֵ��*(result+1)
//result���Ե���first��ʹ�ÿ�����ɾ͵أ�in place������
//�ʱ��㷨

//�����е��ܺ����ȳ�ʼΪ*first��Ȼ��ֵ��*result
//����[first+1,last)��ÿ��������i����ͷ��βִ��sum=sum+*i(��1)��sum=binary_op(sum,*i)(��2)��Ȼ���ٽ�sum��ֵ��*(result+(i-first))

//���㷨��������������β��λ�ã�result+(last-first)

//power
//SGIר��
//��������ĳ����n�ݴη�
//n�ݴ���ָ�Լ����Լ����е�ĳ�����㣬��n�Σ��������Ϳ������ָ��

//��1,����
//template<class T,class Interger>
//inline T power(T x, Interger n) {
//	return power(x, n, multiplies<T>());//ָ��������ʽΪ�˷�
//}

//��2���ݴη������ָ��Ϊ�˷����㣬��n>=0�Ƿ���x^n
//ע�⣺MonoidOperation�����������ɣ�associative��
//���������㽻���ɣ�commutative��
//template<class T,class Interger,class MonoidOperation>
//T power(Tx, Interger n, MonoidOperation op) {
//	if (n == 0)
//		return identity_elem(op);//ȡ����֤ͬԪ�ء�
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
//�����趨ĳ����������ݣ���ʹ���ڵ�ÿһ��Ԫ�ش�ָ����valueֵ��ʼ�����ֵ���״̬
//�ʱ��㷨
//�������壺��[first,last)����������value��value+1��value+2
//template<class ForwardIterator,class T>
//void iota(ForwardIterator first, ForwardIterator last, T value) {
//	while (first != last)
//		*first++ = value++;
//}