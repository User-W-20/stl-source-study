//_type_traits��˫����ǰ׺����ָ����SGI STL�ڲ����õĶ���������STL��׼�淶֮��

//iterator_traits������ȡ�����������ԣ�_type_traits������ȡ�ͱ�type��������

//������SGI<type_traits.h>�е�_type_traits,�ṩ��һ�ֻ��ƣ�������Բ�ͬ���ͱ����ԣ�type attributes�����ڱ���ʱ����ɺ������;�����function dispatch��

_type_traits<T>::has_trivial_default_constructor
_type_traits<T>::has_trivial_copy_constructor
_type_traits<T>::has_trivial_assignment_operator
_type_traits<T>::has_trivial_destructor
_type_traits<T>::is_POD_type //POD:Plain Old Data

//ϣ������ʽ����Ӧ���桱�򡰼١����Ա��ھ�������ʲô���ԣ�����������Ӧ���Ǹ�boolֵ��Ӧ���Ǹ�����/�����ʵġ�����,��Ϊϣ����������Ӧ��������в����Ƶ�����������ֻ�����class object��ʽ�Ĳ������Ż��������Ƶ�

struct _true_type{};
struct _false_type{};
//������classesû���κγ�Ա������������⸺����ȴ���ܱ�ʾ���

//SGI��������Ƕ���Ͷ�����Ϊ_false_type
//SGI�������ص�ֵ��Ȼ�������һ���������ͣ�scalar types������ʵ���_type_traits�ػ��汾

//һ������壨general instantiation�����ں����������Ͷ��ض���Ч�ı���ֵ
//�����������ػ��汾
//ĳЩ���������Զ�Ϊ���������ṩ�ʵ����ػ��汾

//���class�ں�ָ���Ա�����Ҷ��������ڴ涯̬���ã���ô���class����Ҫʵ�ֳ��Լ���non-trival-xxx