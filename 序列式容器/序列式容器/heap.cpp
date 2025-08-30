//heap并不属于STL容器组件
//但它扮演priority queue的助手
//priority queue允许用户以任何次序将任何元素推入容器内，但取出时一定是从优先权最高（也就是数值最高）的元素开始取
//binary max heap 具有这样的特性，适合作为priority queue的底层机制

//如果使用list作为priority queue的底层机制，元素插入操作可享常数时间
//但是要找到list中的极值，却需要对整个list进行线性扫描
//也可以改变做法，让元素插入前先经过排序，使得list的元素值总是由小到大（或由大到小）；但这样虽然取得极值以及元素删除操作达到最高效率，可元素的插入却只有线性表现

//如果以binary search tree作为priority queue的底层机制
//元素的插入和极值的取得就有O(logN)的表现
//但这样太小题大做了，一来binary search tree的输入需要足够的随机性，二来binary search tree并不容易实现
//binary heap便是这种条件下的最佳候选者

//binary heap就是一种complete binary tree（完全二叉树）
//整棵binary tree除了最底层的叶节点之外，都是填满的，而最底层的叶节点由左至右又不得有空隙

//complete binary tree整棵树内没有任何节点漏洞
//可以利用array来存储所有节点
//将array的#0元素保留（或设为无穷大或无穷小），那么当complete binary tree中的某个节点位于array的i处时，其左子节点必位于array的2i处，其右子节点必位于array的2i+1处，其父节点必位于“i/2”处（“/”代表高斯符号，取其整数）
//这种以array表述tree的方式，称为隐式表述法（implicit represemtation）

//array的缺点是无法动态改变大小，而heap需要这个功能，所以vector是代替array的更好选择

//根据元素排列方式，分为max-heap和min-heap，前者每个节点的键值（key）都大于或等于其子节点的键值，后者每个节点的键值（key）都小于或等于其子节点的键值
//max-heap的最大值在根节点，并总是位于底层array或vector的起头处
//min-heap的最小值在根节点，并总是位于底层array或vector的起头处
//STL提供的是max-heap

//push_heap算法
//执行一个percolate up（上溯）程序，将新节点拿来与其父节点比较，如果其键值（key）比父节点大，就父子对换位置，如此一直上溯，直到不需要对换或直到根节点为止

//pop_heap算法
//执行一个percolate down（下溯）程序：将根节点（最大值被取走后，形成一个“洞”）填入上述那个失去生存空间的叶子结点，再将它拿来和其两个子节点比较键值（key），并与较大的子节点对调位置。一直下放，直到这个“洞”的键值大于左右两个子节点，或直到下放至叶子节点为止

//sort_heap算法
//每次pop_heap可获得heap中键值最大的元素
//持续对整个heap做pop_heap操作，每次将操作范围从后往前缩减一个元素（因为pop_heap会把键值最大的元素放在底部容器的最尾端），当整个程序执行完毕时，便有了一个递增序列

//make_heap算法
//将一段现有的数据转化为一个heap
//主要依据complete binary tree的隐式表述（implicit representation）

//heap的所有元素都必须遵循特别的（complete binary tree）排列规则，所以heap不提供遍历功能，也不提供迭代器

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	{
//		//test heap(底层以vector完成)
//		int ia[9] = { 0,1,2,3,4,8,9,3,5 };
//		vector<int>ivec(ia, ia + 9);
//
//		make_heap(ivec.begin(), ivec.end());
//		for (int i = 0; i < ivec.size(); ++i)
//			cout << ivec[i] << ' ';//9 5 8 3 4 0 2 3 1
//		cout << endl;
//		cout << "-------------------" << endl;
//
//		ivec.push_back(7);
//		push_heap(ivec.begin(), ivec.end());
//		for (int i = 0; i < ivec.size(); ++i)
//			cout << ivec[i] << ' ';//9 7 8 3 5 0 2 3 1 4
//		cout << endl;
//		cout << "-------------------" << endl;
//
//		pop_heap(ivec.begin(), ivec.end());
//		cout << ivec.back() << endl;//9，返回但不移除
//		ivec.pop_back();//移除最后一个元素并且不返回
//		cout << "-------------------" << endl;
//
//		for (int i = 0; i < ivec.size(); ++i)
//			cout << ivec[i] << ' ';//8 7 4 3 5 0 2 3 1
//		cout << endl;
//		cout << "-------------------" << endl;
//
//		sort_heap(ivec.begin(), ivec.end());
//		for (int i = 0; i < ivec.size(); ++i)
//			cout << ivec[i] << ' '; //0 1 2 3 3 4 5 7 8
//		cout << endl;
//		cout << "-------------------" << endl;
//	}
//	
//	{
//		//test heap(底层以array完成)
//		int ia[9] = { 0,1,2,3,4,8,9,3,5 };
//		make_heap(ia, ia + 9);
//		//array无法动态改变大小，因此不可对满载的array进行push_heap（）操作
//		//因为那得先在array尾端增加一个元素
//
//		sort_heap(ia, ia + 9);
//		for (int i = 0; i < 9; ++i)
//			cout << ia[i] << ' ';//0 1 2 3 3 4 5 8 9
//		cout << endl;
//		//经过排序之后的heap，不再是个合法的heap
//		cout << "-------------------" << endl;
//
//		//重新再做一个heap
//		
//		make_heap(ia, ia + 9);
//		pop_heap(ia, ia + 9);
//		cout << ia[8] << endl;//9
//		cout << "-------------------" << endl;
//	}
//
//	{
//		//test heap(底层以array完成)
//		int ia[6] = { 4,1,7,6,2,5 };
//		make_heap(ia, ia + 6);
//		for (int i = 0; i < 6; ++i)
//			cout << ia[i] << ' ';//7 6 5 1 2 4
//		cout << endl;
//	}
//}
