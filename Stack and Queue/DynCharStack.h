struct StackNode
{
	char value;
	StackNode *next;
};

class DynCharStack
{
private:
	StackNode *top;

public:
	DynCharStack(void);
	void push(char);
	void pop(char &);
	bool isEmpty(void);
};
