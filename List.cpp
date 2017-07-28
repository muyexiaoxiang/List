#include <iostream>
#include <cassert>
using namespace std;


typedef int DataType;

struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	DataType _data;

	ListNode(DataType x)
		:_data(x)
		, _next(NULL)
		, _prev(NULL)
	{}
};

class List
{
	typedef ListNode Node;
public:
	List()
		:_head(NULL)
		, _tail(NULL)
	{}

	List(const List& L)
		:_head(NULL)
		, _tail(NULL)
	{
		Node* cur = L._head;

		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}

	List& operator=(List L)
	{
		Swap(L);
		return *this;
	}

	~List()
	{
		Node* cur = _head;

		while (cur)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		_head = _tail = NULL;
	}

	void Swap(List L)
	{
		swap(_head, L._head);
		swap(_tail, L._tail);
	}
	void PushBack(DataType x)
	{
		Node* tmp = new Node(x);
		//没有结点
		if (_head == NULL)
		{
			_head = _tail = tmp;
		}
		//有结点
		else
		{
			_tail->_next = tmp;
			tmp->_prev = _tail;
			_tail = tmp;
		}

	}

	void PopBack()
	{
		//没有结点
		if (_head == NULL)
		{
			return;
		}
		//1个结点
		else if (_head == _tail)
		{
			delete _head;
			_head = _tail = NULL;
		}
		//多个结点
		else
		{
			Node* prev = _tail->_prev;
			delete _tail;
			_tail = prev;
			_tail->_next = NULL;
		}
	}

	void PushFront(DataType x)
	{
		Node* tmp = new Node(x);

		//没有结点
		if (_head == NULL)
		{
			_head = _tail = tmp;
		}
		//有结点
		else
		{
			tmp->_next = _head;
			_head->_prev = tmp;
			_head = tmp;
		}
	}

	void PopFront()
	{
		//没有结点
		if (_head == NULL)
		{
			return;
		}
		//1个结点
		else if (_head == _tail)
		{
			delete _head;
			_head = _tail = NULL;
		}
		//多个结点
		else
		{
			Node* next = _head->_next;
			delete _head;
			_head = next;
			_head->_prev = NULL;
		}
	}
	// 在pos的前面插入一个
	void Insert(Node* pos, DataType x)
	{
		assert(pos);

		//头插
		if (_head == pos)
		{
			PushFront(x);
		}
		//其余位置
		else
		{
			Node* tmp = new Node(x);
			Node* prev = pos->_prev;

			tmp->_next = pos;
			pos->_prev = tmp;
			prev->_next = tmp;
			tmp->_prev = prev;
		}
	}

	void Erase(Node* pos)
	{
		assert(pos);

		//头删
		if (pos == _head)
		{
			PopFront();
		}
		//尾删
		else if (pos == _tail)
		{
			PopBack();
		}
		//其余位置
		else
		{
			Node* prev = pos->_prev;
			Node* next = pos->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos;
			pos = NULL;
		}
	}

	Node* Find(DataType x)
	{
		Node* cur = _head;

		while (cur)
		{
			if (cur->_data == x)
				return cur;

			cur = cur->_next;
		}

		return NULL;
	}

	void Reverse()
	{
		if (_head == NULL)
			return;

		else if (_head == _tail)
			return;

		else
		{
			Node* cur = _head;

			while (cur)
			{
				swap(cur->_next, cur->_prev);
				cur = cur->_prev;
			}
			swap(_head, _tail);
		}
	}

	void print()
	{
		Node* cur = _head;

		while (cur)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
private:
	Node* _head;
	Node* _tail;
};


//测试

typedef ListNode Node;
void test1()
{
	List L1;
	L1.PushBack(1);
	L1.PushBack(2);
	L1.PushBack(3);
	L1.PushBack(4);
	L1.print();

	Node* pos = L1.Find(3);
	L1.Insert(pos, 30);
	pos = L1.Find(1);
	L1.Insert(pos, 0);
	L1.print();
	pos = L1.Find(0);
	L1.Erase(pos);
	pos = L1.Find(30);
	L1.Erase(pos);
	pos = L1.Find(4);
	L1.Erase(pos);
	L1.print();
}

void test2()
{
	List L1;
	L1.PushFront(1);
	L1.PushFront(2);
	L1.PushFront(3);
	L1.PushFront(4);
	L1.print();

	L1.PopFront();
	L1.PopFront();
	L1.PopFront();
	L1.PopFront();
	L1.PopFront();
	L1.print();
}

void test3()
{
	List L1;
	L1.PushBack(1);
	L1.PushBack(2);
	L1.PushBack(3);
	L1.PushBack(4);
	L1.print();

	L1.Reverse();
	L1.print();

}
int main()
{
	test3();

	system("pause");
	return 0;
}




