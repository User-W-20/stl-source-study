//STL list是个双向链表（double linked list）
//SGI STL另提供了一个单向链表（single linked list），名为slist

//二者主要差别在于，slist的迭代器属于单向的Forword Iterator，list的迭代器属于双向的Bidirectional Iterator
//单向链表所耗用的空间更小，某些操作更快

//共同具有的一个相同特色是，它们的插入（insert）、移除（erase）、接合（splice）等操作并不会造成原有的迭代器失效

//slist没有任何方便的方法可以回头定出前一个位置，因此它必须从头找起
//除了slist起点附近的区域之外，在其它位置上必须采用erase或insert操作函数，都属不智之举

//slist不提供push_back(),只提供push_front(),因此slist的元素次序会和元素插入进来的次序相反

//slist运用了继承关系，因此在类型转换上有复杂的表现

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