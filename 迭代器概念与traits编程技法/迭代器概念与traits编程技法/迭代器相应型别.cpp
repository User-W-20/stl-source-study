//����function template�Ĳ����Ƶ���argument deducation������

//template<class I,class T>
//void fun_impl(I iter, T t) {
//	T tmp;//�����������⣬T���ǵ�������ָ֮����ͱ� int
//	//... �����ԭ��func()Ӧ�����Ĺ���
//};
//
//template<class I>
//inline
//void func(I iter) {
//	func_impl(iter, *iter);//func�Ĺ���ȫ������func_impl
//}
//
//int main() {
//	int i;
//	func(&i);
//}

//��������Ӧ�ͱ�associated types����ֻ�ǡ���������ָ������ͱ�һ��