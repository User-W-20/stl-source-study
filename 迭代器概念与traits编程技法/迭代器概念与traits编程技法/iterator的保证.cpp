//为了符合规范，任何迭代器都应该提供五个内嵌相应型别，以利于traits萃取，否则便是自别于整个STL架构，可能无法与其他STL组件顺利搭配
//STL提供了一个iterators class

template<class Category,
	class T,
	class Distance = ptrdiff_t,
	class Pointer = T*,
	class Reference = T&>
struct iterator
{
	typedef Category iterator_category;
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
};

//iterators不含任何成员，纯粹只是型别定义，所以继承它并不会导致任何额外负担

//设计适当的相应型别（associated types），是迭代器的责任
//设计适当的迭代器，则是容器的责任

//traits编程技法大量运用于STL现实品中