#ifndef DbLinkList
#define DbLinkList

template<class T>
class DoubleLinkListNode {
public:
	T val;
	DoubleLinkListNode<T>* prev, * next;
	DoubleLinkListNode(const T& data = T(), DoubleLinkListNode* tmp1 = nullptr, DoubleLinkListNode* tmp2 = nullptr) : val(data), prev(tmp1), next(tmp2) {};
};

template<class T>
class Iterator {
private:
	DoubleLinkListNode<T>* current;

public:
	Iterator() : current(nullptr) {};
	Iterator(DoubleLinkListNode<T>* node) : current(node) {};
	Iterator(const Iterator& itr) : current(itr.current) {};

	Iterator& operator ++() { current = current->next; return *this; }
	Iterator& operator ++(int n) {
		Iterator old = *this;
		++(*this);
		return old;
	}
	Iterator& operator --() { current = current->prev; return *this; }
	Iterator& operator --(int n) {
		Iterator old = *this;
		--(*this);
		return old;
	}

	T& operator *() { return current->val; }
	const T& operator *() { return current->val; }

	bool operator ==(const Iterator& itr) { return current == itr.current; }
	bool operator !=(const Iterator& itr) { return current != itr.current; }
};

template<class T>
class DoubleLinkList {
private:
	DoubleLinkListNode<T>* head = nullptr;
	DoubleLinkListNode<T>* tail = nullptr;
	int size;

	typedef Iterator<T>iterator;
	typedef const Iterator<T> const_iterator;

public:
	DoubleLinkList() {
		head = new DoubleLinkListNode<T>();
		tail = new DoubleLinkListNode<T>();
		size = 0;
		head->next = tail;
		tail->prev = head;
	}
	~DoubleLinkList() {
		Clear();
		delete head;
		delete tail;
	}
	DoubleLinkList(const DoubleLinkList& list) {
		size = list.size;
		head = new DoubleLinkListNode<T>();
		tail = new DoubleLinkListNode<T>();
		for (iterator temp = list.Begin(); temp != list.End(); temp++) {
			PushBack(*temp);
		}
	}

	void Clear();
	void Erase();
	void Insert();
	void PushFront(const T& item);
	void PushBack(const T& item);
	void PopFront();
	void PopBack();
};

#endif