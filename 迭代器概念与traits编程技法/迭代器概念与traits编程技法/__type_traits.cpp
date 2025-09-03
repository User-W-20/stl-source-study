//_type_traits，双底线前缀词意指这是SGI STL内部所用的东西，不在STL标准规范之内

//iterator_traits负责萃取迭代器的特性，_type_traits则复杂萃取型别（type）的特性

//定义于SGI<type_traits.h>中的_type_traits,提供了一种机制，允许针对不同的型别属性（type attributes），在编译时期完成函数派送决定（function dispatch）

_type_traits<T>::has_trivial_default_constructor
_type_traits<T>::has_trivial_copy_constructor
_type_traits<T>::has_trivial_assignment_operator
_type_traits<T>::has_trivial_destructor
_type_traits<T>::is_POD_type //POD:Plain Old Data

//希望上述式子响应“真”或“假”（以便于决定采用什么策略），但其结果不应该是个bool值，应该是个有真/假性质的“对象”,因为希望利用其响应结果来进行参数推导，而编译器只有面对class object形式的参数，才会做参数推导

struct _true_type{};
struct _false_type{};
//这两个classes没有任何成员，不会带来额外负担，却又能标示真假

//SGI把所有内嵌类型都定义为_false_type
//SGI定义出最保守的值，然后在针对一个标量类型（scalar types）设计适当的_type_traits特化版本

//一般具现体（general instantiation），内含对所有类型都必定有效的保守值
//经过声明的特化版本
//某些编译器会自动为所有类型提供适当的特化版本

//如果class内含指针成员，并且对它进行内存动态配置，那么这个class就需要实现出自己的non-trival-xxx