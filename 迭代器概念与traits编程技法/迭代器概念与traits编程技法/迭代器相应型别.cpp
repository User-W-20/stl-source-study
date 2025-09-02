//利用function template的参数推导（argument deducation）机制

//template<class I,class T>
//void fun_impl(I iter, T t) {
//	T tmp;//这里解决了问题，T就是迭代器所指之物的型别 int
//	//... 这个做原本func()应该做的工作
//};
//
//template<class I>
//inline
//void func(I iter) {
//	func_impl(iter, *iter);//func的工作全部移往func_impl
//}
//
//int main() {
//	int i;
//	func(&i);
//}

//迭代器相应型别（associated types）不只是“迭代器所指对象的型别”一种