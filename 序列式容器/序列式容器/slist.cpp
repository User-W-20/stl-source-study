//STL list�Ǹ�˫������double linked list��
//SGI STL���ṩ��һ����������single linked list������Ϊslist

//������Ҫ������ڣ�slist�ĵ��������ڵ����Forword Iterator��list�ĵ���������˫���Bidirectional Iterator
//�������������õĿռ��С��ĳЩ��������

//��ͬ���е�һ����ͬ��ɫ�ǣ����ǵĲ��루insert�����Ƴ���erase�����Ӻϣ�splice���Ȳ������������ԭ�еĵ�����ʧЧ

//slistû���κη���ķ������Ի�ͷ����ǰһ��λ�ã�����������ͷ����
//����slist��㸽��������֮�⣬������λ���ϱ������erase��insert������������������֮��

//slist���ṩpush_back(),ֻ�ṩpush_front(),���slist��Ԫ�ش�����Ԫ�ز�������Ĵ����෴

//slist�����˼̳й�ϵ�����������ת�����и��ӵı���

//#include<iostream>
//#include<ext/slist>
//#include<algorithm>
//using namespace std;
//using namespace __gnu_cxx;
//
//int main() {
//    int i;
//    slist<int>islist;
//    cout << "size=" << islist.size() << endl;//size=0
//
//    islist.push_front(9);
//    islist.push_front(1);
//    islist.push_front(2);
//    islist.push_front(3);
//    islist.push_front(4);
//    cout << "size=" << islist.size() << endl;//size=5
//
//    slist<int>::iterator ite = islist.begin();
//    slist<int>::iterator ite2 = islist.end();
//    for (; ite != ite2; ++ite)
//        cout << *ite << ' ';//4 3 2 1 9 
//    cout << endl;
//
//    ite = find(islist.begin(), islist.end(), 1);
//    if (ite != 0)
//        islist.insert(ite, 99);
//    cout << "size=" << islist.size() << endl;//size=6
//    cout << *ite << endl;//1
//
//    ite = islist.begin();
//    ite2 = islist.end();
//    for (; ite != ite2; ++ite)
//        cout << *ite << ' ';//4 3 2 99 1 9 
//    cout << endl;
//
//    ite = find(islist.begin(), islist.end(), 3);
//    if (ite != 0)
//        cout << *(islist.erase(ite)) << endl;//2
//
//    ite = islist.begin();
//    ite2 = islist.end();
//    for (; ite != ite2; ++ite)
//        cout << *ite << ' ';//4 2 99 1 9 
//    cout << endl;
//}