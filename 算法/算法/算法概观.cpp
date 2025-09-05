//以有限的步骤，解决逻辑或数学上的问题，称为算法（algorithms）

//唯有用来解决特定问题，并且获得数学上的效能分析与证明，这样的算法才具有可复用性

//特定的算法往往搭配特定的数据结构

//当发现（发明）一个可以解决问题的算法时，下一个重要步骤就是决定该算法所耗用的资源，包括空间和时间。称为算法分析（algorithm analysis）

//一般而言，算法的执行时间与其所要处理的数据量有关，两者之间存在某些函数关系，可能是一次（线性，linear），二次（quadratic），三次（cubic）或对数（logarithm）关系

//当数据量很小时，多项式函数的每一项都可能对结果带来相当程度的影响
//但是当数据量够大时，只有最高次方的项目才具有主导地位

//最小元素问题解法一定必须两两元素比对，逐一进行
//最短距离问题所需计算的元素对（pairs）共有N(N-1)/2,所以大数据量和执行时间呈二次关系
//三点共线问题要计算的元素对（pairs）共有N(N-1)(N-2)/3，所以大数据量和执行时间呈三次关系

//以Big_Oh标记法表示为O(N),O(N²),O(N³)

//如果有任何正值常数c和N₀，使得当N≥N₀时，T(N)≤cF(N)，那么便可将T(N)的复杂度表示为O(F(N))

//Big_Oh并不适合用来标记小数据量下的情况

//问题规模的降低比例如何，并不会带来影响，因为它会反应在对数的底上，而底对于Big_Oh标记法是没有影响的

//所有的STL算法都作用在由迭代器[first,last)所标示出来的区间上
//“质变算法”，是指运算过程中会改变区间内（迭代器所指）的元素内容

/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ia[] = { 22,20,30,17,33,40,17,23,22,12,20 };
vector<int> iv(ia, ia + sizeof(ia) / sizeof(int));

vector<int>::const_iterator cite1 = iv.begin();

vector<int>::const_iterator cite2 = iv.end();

sort(cite1, cite2);*/  //此声明没有存储类或类型说明符

//“非质变算法”，是指运算过程中不会更改区间内（迭代器所指）的元素内容

//template<class T>
//struct plus2 {
//	void operator()(T& x)const
//	{
//		x += 2;
//	}
//};
//
//int ia[] = { 22,20,30,17,33,40,17,23,22,12,20 };
//vector<int> iv(ia, ia + sizeof(ia) / sizeof(int));
//
//for_each(iv.begin(), iv.end(), plus2<int>());
//元素会被改变

//所有泛型算法的前两个参数都是一对迭代器（iterators），通常称为first和last，用以标示算法的操作区间
//STL习惯采用前闭后开区间（或称左涵盖区间）标示法，写成[first,last),表示区间涵盖first至last（不含last）之间的所有元素

//这个[first,last)区间的必要条件时，必须能够经由increment（累加）操作符的反复运用，从first到达last

//每一个STL算法的声明，都表现出它所需要的最低程度的迭代器类型

//将无效的迭代器传给某个算法，虽然是一种错误，却不保证能够在编译时期就被捕捉出来，因为“迭代器类型”并不是真实的型别，只是function template 的一种型别参数（type parameters）

//许多STL算法不只支持一个版本
//这一类算法的某个版本采用缺省运算行为，另一个版本提供额外参数，接受外界传入一个仿函数（functor），以便采用其它策略

//质变算法（mutatingalgorithms）通常提供两个版本，一个是in-place（就地进行）版，就地改变其操作对象，另一个是copy（另地进行）版，将操作对象的内容复制一个副本，然后在副本上进行修改并返回该副本
//如果希望以这类“无copy版本”的质变算法施行于某一段区间元素的副本上，必须自行制作并传递那一份副本

