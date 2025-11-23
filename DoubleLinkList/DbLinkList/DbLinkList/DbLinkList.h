#ifndef DbLinkList
#define DbLinkList

#include <utility>

template<class T>
class DoubleLinkListNode {
public:
	T val;
	DoubleLinkListNode<T>* prev, * next;
	DoubleLinkListNode(const T& data = T(), DoubleLinkListNode* tmp1 = nullptr, DoubleLinkListNode* tmp2 = nullptr) : val(data), prev(tmp1), next(tmp2) {};
};

template<class T>
class Iterator {
public:
	DoubleLinkListNode<T>* current;

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
	const T& operator *() const{ return current->val; }

	bool operator ==(const Iterator& itr) { return current == itr.current; }
	bool operator !=(const Iterator& itr) { return current != itr.current; }
};

template<typename T>
class DoubleLinkList
{
    DoubleLinkListNode<T>* head;
    DoubleLinkListNode<T>* tail;
    int size;
public:

    typedef Iterator<T>iterator;
    typedef const Iterator<T> const_iterator;
    DoubleLinkList()
    {
        size = 0;
        head = new DoubleLinkListNode<T>();
        tail = new DoubleLinkListNode<T>();
        tail->prev = head;
        head->next = tail;//连起来  变成链表

    };
    ~DoubleLinkList()
    {
        Clear();
        delete head;
        delete tail;
    };
    DoubleLinkList(const DoubleLinkList& l)
    {
        size = l.size;
        head = new DoubleLinkListNode<T>();
        tail = new DoubleLinkListNode<T>();
        tail->prev = head;
        head->next = tail;
        for (iterator temp = l.Begin(); temp != l.End(); temp++)
            push_back(*temp);//一个一个节点复制


    }
    void Clear()
    {
        iterator temp = Begin();
        while (temp != End())
            temp = Erase(temp);
    }

    iterator Begin() { return iterator(head->next); }
    const_iterator  Begin() const { return iterator(head->next); }

    iterator End() { return iterator(tail); }
    const_iterator End()const { return iterator(tail); }

    T& Front() { return *Begin(); }
    const T& Front()const { return *Begin(); }

    T& Back() { return  *(--End()); }
    const T& Back()const { return *(--End()); }

    DoubleLinkList& operator =(const DoubleLinkList& l)
    {
        if (this != &l)
        {
            Clear();
            size = l.size;

            for (iterator temp = l.Begin(); temp != l.End(); temp++)
                push_back(*temp);
            return *this;

        }

    }

    void push_front(const T& item) { Insert(Begin(), item); }
    void push_back(T& item) { Insert(End(), item); }

    void pop_front() { Erase(Begin()); }
    void pop_back() { Erase(--End()); }

    int Size()const { return size; }
    bool Empty() { return head->next == tail; }

    iterator Insert(const  iterator itr, const T& item)
    {
        DoubleLinkListNode<T>* n = itr.current;
        DoubleLinkListNode<T>* newnode = new DoubleLinkListNode<T>(item, n->prev, n);
        n->prev->next = newnode;
        n->prev = newnode;
        size++;

        return iterator(newnode);
    }

    iterator Erase(iterator itr)
    {
        DoubleLinkListNode<T>* temp = itr.current;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        size--;
        DoubleLinkListNode<T>* p = temp->next;
        delete temp;

        return iterator(p);
    }

};

#endif