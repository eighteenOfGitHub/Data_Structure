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
	Stack();					//Ĭ�Ϲ��캯��
	~Stack();					//��������
	bool empty();				//�ж�ջ��
	bool get_top(Node*& x);		//ȡջ��Ԫ��
	bool push(const Node* node);		//��ջ
	bool pop();					//��ջ
	bool contains(Node* xy);	//�Ƿ����
	int  size();				//ջ��������
	void removeAll();			//���ջ
	void addAll(Stack x);	    //����
	void addAll(Node* node);	//����
private:
	int count;					//����
	Node* top;				//ջ��ָ��
};

//----------Stack��ʵ��----------
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