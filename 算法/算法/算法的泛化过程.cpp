//如何将算法独立于其所处理的数据结构之外，不受数据结构的羁绊，思想层面就不是那么简单了
//如何在即将处理的位置的数据结构上，正确地实现所有操作？

//关键在于，只要把操作对象的型别加以抽象化，把操作对象的标示法和区间目标的移动行为抽象化，整个算法也就在一个抽象层面上工作了。
//整个过程称为算法的泛型化（generalized），简称泛化

int* find(int* arrayHead, int arraySize, int value) {
	for (int i = 0; i < arraySize; ++i) {
		if (arrayHead[i] == value)
			return &(arrayHead[i]);
	}
	return nullptr;
}

//该函数在某个区间内查找value，返回的是一个指针，指向它所找到的第一个符合条件的元素，如果没有找到，就返回最后一个元素的下一位置（地址）
//最后一个元素的下一位置称为end，end对比null的优势在于，end指针可以对其他种类的容器带来泛型效果

//一个指向array元素的指针，不但可以合法地指向array内的任何位置，也可以指向array尾端以外的任何位置
//当指针指向array尾端以外的位置时，它只能用来与其他array指针相比较，不能提领（dereference）其值

//const int arraySize = 7;
//int ia[arraySize] = { 0,1,2,3,4,5,6 };
//int* end = ia + arraySize;//最后元素的下一位置
//
//int* ip = find(ia, sizeof(ia) / sizeof(int), 4);
//if (ip == end) //两个array指针的比较
//cout << "4 not found" << endl;
//else
//cout << "4 found" << endl;

//find()的这种做法暴露了容器的太多的实现细节，也因此太过依附特定容器
//为了让find()适用于所有类型的容器，其操作应该更抽象化

int* find(int* begin, int* end, int value) {
	while (begin != end && *begin != value)
		++begin;

	return begin;
}

//这个函数在“前闭后开”区间[begin,end)内查找value，并返回一个指针，指向它所找到的第一个符合条件的元素，如果没有找到，就返回end

//const int arraySize = 7;
//int ia[arraySize] = { 0,1,2,3,4,5,6 };
//int* end = ia + arraySize;
//
//int* ip = find(ia, end, 4);
//if(ip==end)
//cout<< "4 not found" << endl;
//else
//cout << "4 found" << endl;

//find()函数也可以很方便地用来查找array的子区间
//int* ip = find(ia + 2, ia + 5, 3);
//if (ip == end)
//cout << "3 not found" << endl;
//else
//cout << "3 found" << endl;

//由于find()之内并无任何操作是针对特定的整数array而发的，所以可以将它改为一个template
//template<typename T>
//T* find(T* begin, T* end, const T& value) {
//	//以下用到了operator!=,operator*,operator++
//	while (begin!=end&&*begin!=value)
//	{
//		++begin;
//	}
//	//以下返回操作会引发copy行为
//	return begin;
//}

//数值的传递由pass-by-value改为pass-by-reference-to-const，因为如今所传递的value，其型别可为任意：于是对象一大，传递成本便会提升，pass-by-reference可完全避免这些成本

//几乎适用于任何容器-只要该容器允许指针插入，指针又都支持以下4中find()
//inequality（判断不相等）操作符
//dereferencelm（提领，取值）操作符
//prefix increment（前置式递增）操作符
//copy（复制）行为（以便产生函数的返回值）

//C++有一个极大的优点便是，几乎任何东西都可以改写为自定义的形式或行为
//上述这些操作符或操作行为都可以被重载（overloaded）
//何必将find限制为只能使用指针呢？何不让支持以上四种行为的。行为很像指针的“某种对象”都可以被find()使用呢?
//find()函数便可以从原生(native)指针的思想框框中跳脱出来

//迭代器是一种行为类似指针的对象，是一种smart pointers

//template<class Iterator,class T>
//Iterator find(Iterator begin, Iterator end, const T& value) {
//	whie(begin != end && *begin != value)
//		++begin;
//
//	return begin;
//}

//完全泛化的find()函数