#include <iostream>
#include "DynCharQueue.h"
using namespace std;

//************************************************
// Constructor. Generates an empty queue         *
//************************************************
DynCharQueue::DynCharQueue()
{
	front = NULL;
	rear = NULL;   
	
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
void DynCharQueue::enqueue(char ch)
{       
	if (isEmpty())   //if the queue is empty
	{	//make it the first element
		front = new QueueNode(ch);
		rear = front;
	}
	else  //if the queue is not empty
	{	//add it after rear
		rear->next = new QueueNode(ch);
		rear = rear->next;
	} 
	
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
void DynCharQueue::dequeue(char &ch)
{
	QueueNode *temp;
	if (isEmpty())
	{

	}
	else //if the queue is not empty
	{	//return front's value, advance front and delete old front
		ch = front->value;
		temp = front;
		front = front->next;
		delete temp;      
	}
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
bool DynCharQueue::isEmpty() const
{
	if (front == NULL)
		return true;
	else 
		return false;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************
void DynCharQueue::clear()
{
	char value;   // Dummy variable for dequeue

	while(!isEmpty())
		dequeue(value); //delete all elements

}