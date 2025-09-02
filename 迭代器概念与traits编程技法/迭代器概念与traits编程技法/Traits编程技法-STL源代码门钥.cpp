//��������ָ������ͱ𣬳�Ϊ�õ�������value type
//value type����ȫ����ã���һvalue type�������ں����Ĵ���ֵ���������޲��ˣ��Ͼ������ġ�template�����Ƶ����ơ��Ƶ���ֻ�ǲ������޷��Ƶ������ķ���ֵ����
#include<iostream>
#include<string>
#include<iterator>
using namespace std;
template<class T>
struct MyIter
{
	typedef T value_type;//��Ƕ����������nested type��T* ptr;
	MyIter(T*p=0):ptr(p){}
	T& operator*()const { return *ptr; }
};

template<class I>
typename I::value_type
func(I ite)
{
	return *ite;
}

MyIter<int>ite(new int(8));
cout<< func(ite);//���8


//��������ʱ����֪��MyIter<T>::value_type�������һ���ͱ���һ��member function����һ��data member
//typename���������ڸ��߱���������һ���ͱ���˲���˳��ͨ������

//���������еĵ���������class type

//Partial Specialization��ƫ�ػ���������
//���class templateӵ��һ�����ϵ�template�����������������ĳ����������������ȫ����template���������ػ�����

template<typename U, typename V, typename T>
class C{};

//Partial Specialization����˼���ṩ��һ��template����ʽ�����䱾����Ϊtemplatized
//��ԣ��κΣ�template��������һ����������������Ƴ�����һ���ػ��汾

template<typename T>
class C{};//T

//����ػ��汾�������ڡ�TΪԭ��ָ�롱�����
//��TΪԭ��ָ�롱���ǡ�TΪ�κ��ͱ𡱵�һ������һ������������
template<typename T>
class C<T* > {};


template<class I>
struct iterator_traits
{
	typedef typename I::value_type value_type;
};
//traits�����ǣ����I�������Լ���value type����ôͨ�����traits�����ã���ȡ������value_type����I::value_type

template<class I>
typedef iterator_traits<I>::value_type//��������
func(I ite) {
	return *ite;
}

//traits����ӵ���ػ��汾

template<class T>
struct iterator_traits<T*>//ƫ�ػ�-T*
{
	typedef T value_type;
};

//����������Ǹ�pointer-to-const��Ӧ���跨����value typeΪһ��non-const����

template<class T>
struct iterator_traits<const T*>//ƫ�ػ�-const T* 
{								//��ȡ����������һ����T����const T
	typedef T value_type;
};

//1��value type
namespace value_type{
////��νvalue type,��ָ��������ָ���������
////�κ�һ��������STL�㷨�����������class����Ӧ�ö����Լ���value type��Ƕ����
}

////2��difference type
namespace difference_type {
//	//difference type������ʾ����������֮��ľ��룬���Ҳ����������ʾһ�������������������Ϊ���������ռ���ԣ�ͷβ֮��ľ���������������
//
	template<class I, class T >
	typename iterator_traits<I>::difference_type//������������
		count(I first, I last, const T& value) {
		typename iterator_traits<I>::difference_type n = 0;
		for (; first != last; ++first)
			if (*first == value)
				++n;
		return n;
	}

	template<class I>
	struct iterator_traits
	{
		typedef typename I::difference_type difference_type;
	};

	//T*
	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t difference_type;
	};

	//const T*
	template<class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t difference_type;
	};
}

//3��reference type
namespace reference_type {
////������ı䡰��ָ��������ݡ�����Ϊconstant iterators
////����ı䡰��ָ��������ݡ�����Ϊmutable iterators
////����һ��mutable iterators�����������ʱ����õĲ�Ӧ����һ����ֵ��rvalue����Ӧ����һ����ֵ��lvalue������Ϊ��ֵ������ֵ������assignment������ֵ������
//
	int* pi = new int(5);
	const int* pci = new int(9);
	//��mutable iterators�����������ʱ����õ�Ӧ���Ǹ���ֵ������ֵ
	*pi = 7;
	//������constant iterators���Ǹ���ֵ��������ֵ����
	*pci = 1;
}

////4��pointer type
namespace pointer_type {
	//�ܹ�����һ��pointer��ָ���������ָ֮��

	template<class I>
	struct iterator_traits
	{
		typedef typename I::pointer pointer;
		typedef typename I::reference reference;
	};

	//T*
	template<class T>
	struct iterator_traits<T*>
	{
		typedef T* pointer;
		typedef T&  reference;
	};

	//const T*
	template<class T>
	struct iterator_traits<const T*>
	{
		typedef const T* pointer;
		typedef const T& reference;
	};
}

//5��iterator_category
namespace iterator_category {
	//Input iterator:ֻ����read only��
	//Output iterator:ֻд��write only��
	//Forward iterator:�����д
	//Bidirectional iterator:��˫���ƶ�
	//Random Access iterator:ǰ���ֵ�������ֻ��Ӧһ����ָ���������ܣ�ǰ����operator++���ټ��ϵ�����operator--�����������򺭸�����ָ����������������p+n,p-n,p[n],p1-p2,p1<p2

	//�������ĳ�ֵ������ṩһ����ȷ���壬����Ը�ǿ����ĳ�ֵ������ṩ��һ�ֶ��壬���������ڲ�ͬ������ṩ���Ч��
}

//��advancedΪ��
namespace advanced {
	template<class InputIterator, class Distance>
	void advace_II(InputIterator& i, Distance n) {
		//������һǰ��
		while (n--)++i;//��for(;n>0;--n,++i);
	}

	template<class BidirectionalIterator, class Distance>
	void advace_BI(BidirectionalIterator& i, Distance n) {
		//˫����һǰ��
		if (n >= 0)
			while (n--)++i;//��for(;n>0;--n,++i);
		else
			while (n++)--i;//��for(;n<0;++n,--i);
	}

	template<class RandomAccessIterator, class Distance>
	void advace_RAI(RandomAccessIterator& i, Distance n) {
		//˫����Ծǰ��
		i += n;
	}

	template<class InputIterator, class Distance>
	void advance(InputIterator& i, Distance n) {
		if (is_random_access_iterator(i))
			advace_RAI(i, n);
		else if (is_bidirectional_iterator(i))
			advace_BI(i, n);
		else
			advace_II(i, n);
	}

	//����ܹ��ڱ����ھ�ѡ����ȷ�İ汾�����غ������ƿ��Դ�����Ŀ��

	//���traits��������ȡ�������������࣬���������������������͡���Ӧ�ͱ���Ϊadvance()�ĵ�������

	struct input_iterator_tag{};
	struct output_iterator_tag{};
	struct forward_iterator_tag:public input_iterator_tag{};
	struct bidirectional_iterator_tag:public forward_iterator_tag{};
	struct random_access_iterator_tag:public bidirectional_iterator_tag{};

	template<class InputIterator,class Distance>
	inline void _advance(InputIterator& i, Distance n, input_iterator_tag) {
		//������һǰ��
		while (n--)++i;
	}

	//�����Ĵ��ݵ��ú�����trivial forwarding function��
	template<class ForwardIterator, class Distance>
	inline void _advance(ForwardIterator& i, Distance n, forward_iterator_tag) {
		//�����Ľ��д��ݵ��ú���(forwarding)
		advance(i, n, input_iterator_tag());
	}

	template<class BidirectionalIterator, class Distance>
	inline void _advance(BidirectionalIterator& i, Distance n, bidirectional_iterator_tag) {
		//˫����һǰ��
		if (n >= 0)
			while (n--)++i;
		else
			while (n++)--i;
	}

	template<class RandomAccessIterator, class Distance>
	inline void _advance(RandomAccessIterator& i, Distance n, random_access_iterator_tag) {
		//˫����Ծǰ��
		i += n;
	}

	template<class InputIterator, class Distance>
	inline void advance(InputIterator& i, Distance n) {
		_advance(i, n, iterator_traits<InputIterator>::iterator_category());
	}

	template<class I>
	struct Iterator_traits {
		typedef typename I::itertaor_category() itertaor_category;
	};

	//T*
	template<class T>
	struct Iterator_traits<T*> {
		//ԭ��ָ����һ��random_access_iterator
		typedef random_access_iterator_tag  itertaor_category;
	};

	//const T*
	template<class T>
	struct Iterator_traits<const T*> {
		//const T*��һ��random_access_iterator
		typedef random_access_iterator_tag  itertaor_category;
	};

	//�κ�һ������������������ԶӦ�����ڡ��õ������������ĸ��������У���ǿ�����Ǹ���

	//���㷨���ܽ��ܵ���ͽ׵��������ͣ���Ϊ��������ͱ��������
}

//�������������ݵ��õĺ�����
//��class������������ĸ��ַ����ǩ���������Դٳ����ػ��Ƶĳɹ���������һ���ô��ǣ�ͨ���̳У����Բ�����д���������ݵ��á��ĺ���


//struct B{};//B�ɱ���ΪInputIterator
//struct D1:public B{};//D1�ɱ���ΪForwardIterator
//struct D2:public D1{};//D2�ɱ���Ϊ�ɱ���Ϊ
//
//template<class I>
//void func(I& p, B) {
//	cout << "B version" << endl;
//}
//
//template<class I>
//void func(I& p, D2) {
//	cout << "D2 version" << endl;
//}
//
//
//int main() {
//	int* p;
//	func(p, B()); //B version
//	func(p, D1()); //B version
//	func(p, D2()); //D2 version
//}

//��distance()Ϊ��
namespace distance {
	template<class InputIterator>
	inline iterator_traits<InputIterator>::difference_type
		_distance(InputIterator first, InputIterator last, input_iterator_tag) {
		iterator_traits<InputIterator>::difference_type n = 0;
		//��һ�ۼƾ���
		while (first != last) {
			++first; ++n;
		}
		return n;
	}

	template<class RandomAccessIterator>
	inline iterator_traits<RandomAccessIterator>::difference_type
		_distance(RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag) {
		//ֱ�Ӽ�����
		return last - first;
	}

	template<class InputIterator>
	inline iterator_traits<InputIterator>::difference_type
		distance(InputIterator first,InputIterator last){
		typedef typename iterator_traits<InputIterator>::iterator_category category;
	return _distance(first, last, category());
	}

}