**关于链表类的一些基础**

**说明**
1.此程序只是关于单链表的一些内容，切较为丑陋。如果想了解双链表请移步DoubleLinkList目录；
2.写得垃圾还请海涵，各位大佬也可以看看说不定我们可能范一些一样的错误（^_^）

**架构**
本程序采用C++进行编程，共定义了2个类：
1.节点类
template<class T> //模板，让节点的类型可自定义
class SingleLinkListNode {
public:
	T val; //链表节点值
	SingleLinkListNode* next; //指向下一个节点

	SingleLinkListNode(T a) : val(a), next(nullptr) {};
	SingleLinkListNode(SingleLinkListNode* temp) : val(nullptr), next(temp) {};
	SingleLinkListNode(T a, SingleLinkListNode* temp) : val(a), next(temp) {}; //构造函数
};
用于构造链表的结点

2.链表类
template <class T>
class SingleLinkList {
public:
	void InsertToHead(T val) {
		insert(val, 1);
	}
	void InsertToTail(T val) {
		GetLength();
		insert(val, GetLength());
	}
	void Insert(T val, int index) {
		insert(val, index);
	}
	void traverse();
	void ReverseOrderedTraverse();
	void ClearList() {
		while (head) {
			DeleteNode(1);
		}
	}
	void Reverse();
	int GetLength();
	T GetNodeValue(int index);
private:
	SingleLinkListNode<T>* head = nullptr;
	void insert(T val, int index);
	void DeleteNode(int index);
};
实现了一些链表的基本功能

**此程序仍存在大量优化空间，我也会不定期来优化一下**
**课程推荐看Harsha Suryanarayana 大神的课程。一级棒！！！**