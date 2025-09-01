#pragma once
#include"mylist.h"

//Item可以是单向链表节点或双向链表节点
//此处这个迭代器特定只为链表服务，因为其独特的operator++的缘故
template<class Item>
struct ListIter
{
	Item* ptr;//保持与容器之间的一个联系

	ListIter(Item* p = 0) :ptr(p){}//默认构造

	Item& operator*() const { return *ptr; }
	Item* operator->()const { return ptr; }

	//以下的operator++遵守标准做法
	//1、前置++
	ListIter& operator++() {
		ptr = ptr->next();
		return *this;
	}

	//2、后置++
	ListIter operator++(int) {
		ListIter tmp = *this; 
		++(*this); 
		return tmp;
	}

	bool operator==(const ListIter& i)const {
		return ptr == i.ptr;
	}

	bool operator!=(const ListIter& i)const {
		return ptr != i.ptr;
	}

	
	
	
};

template<typename Iter, typename T>
Iter find(Iter first, Iter last, const T& value) {
	while (first != last) {
		if ((*first).value() == value)
			return first;
		++first;
	}
	return last;
}