//��������һ����Ϊ����ָ��Ķ��󣬶�ָ��ĸ�����Ϊ�����Ҳ������Ҫ�ı����ڴ����죨dereference���ͳ�Ա���ʣ�member access������ˣ�����������Ҫ�ı�̹������ܶ�operator*��operator->�������أ�overloading������
#include<iostream>
#include<memory>
#include"mylist-iter.h"
#include"mylist.h"
 //autoptr.cpp
template<class T>
class auto_ptr {
public:
	explicit auto_ptr(T*p=0):pointee(p){}
	template<class U>
	auto_ptr(auto_ptr<U>&rhs):pointee(rhs.release()){}
	~auto_ptr() { delete pointee; }

	template<class U>
	auto_ptr<T>& operator=(auto_ptr<U>rhs) {
		if (this != &rhs)reset(rhs.release());
		return *this;
	}

	T& operator*()const { return *pointee; }
	T* operator->()const { return pointee; }
	T* get()const { return pointee; }
private:
	T* pointee;

public:
	T* release(){
	T * tmp = pointee;
	pointee = 0;//��������Ȩ
	return tmp;
	}

	void reset(T* p = 0) {
		if (pointee != p) {
			delete pointee;
			pointee = p;
		}
	}
};

int main() {
	List<int>mylist;

	for (int i = 0; i < 5; ++i) {
		mylist.insert_front(i);
		mylist.insert_end(i + 2);
	}
	mylist.display();//4 3 2 1 0 2 3 4 5 6

	ListIter<ListItem<int>>begin(mylist.front());
	ListIter<ListItem<int>>end;//Ĭ�� 0��null
	ListIter<ListItem<int>>iter;//Ĭ�� 0��null

	iter =find(begin, end, 3);
	if (iter == end)//found 3
		std::cout << "not found" << std::endl;
	else
		std::cout << "found " << iter->value() << std::endl;

	iter = find(begin, end, 7);
	if (iter == end)//not found
		std::cout << "not found" << std::endl;
	else
		std::cout << "found " << iter->value() << std::endl;

}