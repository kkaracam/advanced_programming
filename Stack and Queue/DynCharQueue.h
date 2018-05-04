#ifndef DYNCHARQUEUE_H
#define DYNCHARQUEUE_H

struct QueueNode
{
	char value;
	QueueNode *next;
	QueueNode(char ch, QueueNode *ptr = nullptr)
	{
		value = ch;
		next = ptr;
	}
};

class DynCharQueue
{
private:
	// These track the front and rear of the queue.
	QueueNode *front;
	QueueNode *rear;	
public:
	// Constructor.
	DynCharQueue();
	
	// Member functions.
	void enqueue(char);
	void dequeue(char &);
	bool isEmpty() const;     
	void clear();
};
#endif