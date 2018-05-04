/*************************************
*Modified by Leyli Javid
*Date: 20.10.2016
*************************************/

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <string>
#include <iostream>
using namespace std;

struct node
{
	string data;  // studentID in string
	node *next;

	node::node()
	{}

	node::node(const string &s, node * link)
		: data(s), next(link)
	{}
};

class linkedlist
{
private:
	node *head;		//Head node, start of LinkedList
	node *createClone() const;  // Helper function for copy constructor
public:
	linkedlist();			    // Constructor
	~linkedlist();				// Destructor
	linkedlist(const linkedlist & copy);	// Deep Copy Constructor
	void printList();		    // Prints the given LinkedList from head to end
	void addSorted(string n);   // Insert a new node such that the list is sorted
	bool isEmpty();
	
	//overloading operators as member function 
	const linkedlist& operator+ (const linkedlist &);
	const linkedlist& operator-(const linkedlist & rhs);
	string operator[] (const int n) const;

	friend class linkedlistIter;
	friend linkedlist operator & (const linkedlist &lhs, const linkedlist &rhs);
};
/***************************************
 * Iterator Class for the "linkedlist" *
 **************************************/
class linkedlistIter
{
private:
	const linkedlist & mylist;
	node * myCurrent;
public:
	linkedlistIter(const linkedlist &list): mylist(list), myCurrent(nullptr)	// Constructor
	{};
	void Init()
	{
		myCurrent = mylist.head;
		// myCurrent points to the first node of the list.
	};

	bool HasMore() const
	{
		if (myCurrent == nullptr)
		{
			return false;
		}

		return true;
	};
	string Current() const
	{
		return myCurrent->data;
	};
	void Next()
	{
		myCurrent = myCurrent->next;
	}
	;

};
#endif