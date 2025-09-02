//迭代器所指对象的型别，称为该迭代器的value type
//value type并且全面可用：万一value type必须用于函数的传回值，就束手无策了，毕竟函数的“template参数推导机制”推导的只是参数，无法推导函数的返回值类型
#include<iostream>
#include<string>
#include<iterator>
using namespace std;
template<class T>
struct MyIter
{
	typedef T value_type;//内嵌类型声明（nested type）T* ptr;
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
cout<< func(ite);//输出8


//编译器此时并不知道MyIter<T>::value_type代表的是一个型别还是一个member function或是一个data member
//typename的用意在于告诉编译器这是一个型别，如此才能顺利通过编译

//并不是所有的迭代器都是class type

//Partial Specialization（偏特化）的意义
//如果class template拥有一个以上的template参数，可以针对其中某个（或数个，但非全部）template参数进行特化工作

template<typename U, typename V, typename T>
class C{};

//Partial Specialization的意思是提供另一份template定义式，而其本身仍为templatized
//针对（任何）template参数更进一步的条件限制所设计出来的一个特化版本

template<typename T>
class C{};//T

//这个特化版本仅适用于“T为原生指针”的情况
//“T为原生指针”便是“T为任何型别”的一个更进一步的条件限制
template<typename T>
class C<T* > {};


template<class I>
struct iterator_traits
{
	typedef typename I::value_type value_type;
};
//traits意义是，如果I定义有自己的value type，那么通过这个traits的作用，萃取出来的value_type就是I::value_type

template<class I>
typedef iterator_traits<I>::value_type//返回类型
func(I ite) {
	return *ite;
}

//traits可以拥有特化版本

template<class T>
struct iterator_traits<T*>//偏特化-T*
{
	typedef T value_type;
};

//如果迭代器是个pointer-to-const，应该设法令其value type为一个non-const类型

template<class T>
struct iterator_traits<const T*>//偏特化-const T* 
{								//萃取出来的类型一个是T而非const T
	typedef T value_type;
};

//1、value type
namespace value_type{
////所谓value type,是指迭代器所指对象的类型
////任何一个打算与STL算法有完美搭配的class，都应该定义自己的value type内嵌类型
}

////2、difference type
namespace difference_type {
//	//difference type用来表示两个迭代器之间的距离，因此也可以用来表示一个容器的最大容量，因为对于连续空间而言，头尾之间的距离就是其最大容量
//
	template<class I, class T >
	typename iterator_traits<I>::difference_type//函数返回类型
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

//3、reference type
namespace reference_type {
////不允许改变“所指对象的内容”，称为constant iterators
////允许改变“所指对象的内容”，称为mutable iterators
////当对一个mutable iterators进行提领操作时，获得的不应该是一个右值（rvalue），应该是一个左值（lvalue），因为右值不允许赋值操作（assignment），左值才允许
//
	int* pi = new int(5);
	const int* pci = new int(9);
	//对mutable iterators进行提领操作时，获得的应该是个左值，允许赋值
	*pi = 7;
	//不允许，constant iterators，是个右值，不允许赋值操作
	*pci = 1;
}

////4、pointer type
namespace pointer_type {
	//能够传回一个pointer，指向迭代器所指之物

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

//5、iterator_category
namespace iterator_category {
	//Input iterator:只读（read only）
	//Output iterator:只写（write only）
	//Forward iterator:允许读写
	//Bidirectional iterator:可双向移动
	//Random Access iterator:前四种迭代器都只供应一部分指针算术功能（前三种operator++，再加上第四种operator--），第五种则涵盖所有指针算术能力，包括p+n,p-n,p[n],p1-p2,p1<p2

	//尽量针对某种迭代器提供一个明确定义，并针对更强化的某种迭代器提供另一种定义，这样才能在不同情况下提供最大效率
}

//以advanced为例
namespace advanced {
	template<class InputIterator, class Distance>
	void advace_II(InputIterator& i, Distance n) {
		//单向，逐一前进
		while (n--)++i;//或for(;n>0;--n,++i);
	}

	template<class BidirectionalIterator, class Distance>
	void advace_BI(BidirectionalIterator& i, Distance n) {
		//双向，逐一前进
		if (n >= 0)
			while (n--)++i;//或for(;n>0;--n,++i);
		else
			while (n++)--i;//或for(;n<0;++n,--i);
	}

	template<class RandomAccessIterator, class Distance>
	void advace_RAI(RandomAccessIterator& i, Distance n) {
		//双向，跳跃前进
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

	//最好能够在编译期就选择正确的版本，重载函数机制可以达成这个目标

	//如果traits有能力萃取出迭代器的种类，便可利用这个“迭代器类型”相应型别作为advance()的第三参数

	struct input_iterator_tag{};
	struct output_iterator_tag{};
	struct forward_iterator_tag:public input_iterator_tag{};
	struct bidirectional_iterator_tag:public forward_iterator_tag{};
	struct random_access_iterator_tag:public bidirectional_iterator_tag{};

	template<class InputIterator,class Distance>
	inline void _advance(InputIterator& i, Distance n, input_iterator_tag) {
		//单向，逐一前进
		while (n--)++i;
	}

	//单纯的传递调用函数（trivial forwarding function）
	template<class ForwardIterator, class Distance>
	inline void _advance(ForwardIterator& i, Distance n, forward_iterator_tag) {
		//单纯的进行传递调用函数(forwarding)
		advance(i, n, input_iterator_tag());
	}

	template<class BidirectionalIterator, class Distance>
	inline void _advance(BidirectionalIterator& i, Distance n, bidirectional_iterator_tag) {
		//双向，逐一前进
		if (n >= 0)
			while (n--)++i;
		else
			while (n++)--i;
	}

	template<class RandomAccessIterator, class Distance>
	inline void _advance(RandomAccessIterator& i, Distance n, random_access_iterator_tag) {
		//双向，跳跃前进
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
		//原生指针是一种random_access_iterator
		typedef random_access_iterator_tag  itertaor_category;
	};

	//const T*
	template<class T>
	struct Iterator_traits<const T*> {
		//const T*是一种random_access_iterator
		typedef random_access_iterator_tag  itertaor_category;
	};

	//任何一个迭代器，其类型永远应该落在“该迭代器所隶属的各种类型中，最强化的那个”

	//以算法所能接受的最低阶迭代器类型，来为其迭代器型别参数命名
}

//消除“单纯传递调用的函数”
//以class来定义迭代器的各种分类标签，不仅可以促成重载机制的成功运作，另一个好处是，通过继承，可以不必再写“单纯传递调用”的函数


//struct B{};//B可比拟为InputIterator
//struct D1:public B{};//D1可比拟为ForwardIterator
//struct D2:public D1{};//D2可比拟为可比拟为
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

//以distance()为例
namespace distance {
	template<class InputIterator>
	inline iterator_traits<InputIterator>::difference_type
		_distance(InputIterator first, InputIterator last, input_iterator_tag) {
		iterator_traits<InputIterator>::difference_type n = 0;
		//逐一累计距离
		while (first != last) {
			++first; ++n;
		}
		return n;
	}

	template<class RandomAccessIterator>
	inline iterator_traits<RandomAccessIterator>::difference_type
		_distance(RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag) {
		//直接计算差距
		return last - first;
	}

	template<class InputIterator>
	inline iterator_traits<InputIterator>::difference_type
		distance(InputIterator first,InputIterator last){
		typedef typename iterator_traits<InputIterator>::iterator_category category;
	return _distance(first, last, category());
	}

}