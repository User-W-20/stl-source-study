//Ϊ�˷��Ϲ淶���κε�������Ӧ���ṩ�����Ƕ��Ӧ�ͱ�������traits��ȡ����������Ա�������STL�ܹ��������޷�������STL���˳������
//STL�ṩ��һ��iterators class

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

//iterators�����κγ�Ա������ֻ���ͱ��壬���Լ̳��������ᵼ���κζ��⸺��

//����ʵ�����Ӧ�ͱ�associated types�����ǵ�����������
//����ʵ��ĵ���������������������

//traits��̼�������������STL��ʵƷ��