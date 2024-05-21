struct Node
{
	int x, y;
	Node* next;
	Node() {};
	Node(int x, int y) { this->x = x; this->y = y; }
};

class Stack
{
public:
	Stack();					//默认构造函数
	~Stack();					//析构函数
	bool empty();				//判断栈空
	bool get_top(Node*& x);		//取栈顶元素
	bool push(const Node* node);		//入栈
	bool pop();					//出栈
	bool contains(Node* xy);	//是否存在
	int  size();				//栈内容数量
	void removeAll();			//清空栈
	void addAll(Stack x);	    //拷贝
	void addAll(Node* node);	//拷贝
private:
	int count;					//总数
	Node* top;				//栈顶指针
};

//----------Stack类实现----------
Stack::Stack()
{
	count = 0;
	top = NULL;
}

bool Stack::empty()
{
	return count == 0;		//return top == NULL
}

bool Stack::get_top(Node*& x)
{
	if (empty())
		return false;
	x = top;
	return true;
}

bool Stack::push(const Node* node)
{
	Node* s = new Node;
	s->x = node->x;
	s->y = node->y;
	s->next = top;
	top = s;
	count++;

	return true;
}

bool Stack::pop()
{
	if (empty())
		return false;
	Node* temp = top;
	top = temp->next;
	delete temp;
	count--;
	return true;
}

bool Stack::contains(Node* xy) {
	Node* temp = top;
	for (; temp != NULL; temp = temp->next) {
		if (temp->x == xy->x && temp->y == xy->y)
			return true;
	}
	return false;
}

int Stack::size()
{
	return count;
}

void Stack::removeAll() {
	count = 0;
	while (!empty())
		pop();
}

void Stack::addAll(Stack x) {
	Node* temp;
	x.get_top(temp);
	addAll(temp);
}

void Stack::addAll(Node* node) {
	if (node != NULL) {
		addAll(node->next);
		push(node);
	}

}

Stack::~Stack()
{
	count = 0;
	while (!empty())
		pop();
}