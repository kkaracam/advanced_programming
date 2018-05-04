//	Poyraz Kývanç Karaçam 20967

#include "linkedlist.h"


// Constructor
linkedlist::linkedlist()	
{
	head = nullptr;
}




node *linkedlist::createClone() const
{
	if (head == nullptr)  //if list is empty
		return nullptr;   //clone is empty as well
	
	//first generate the first clone node and connect to head of clone
	node * headClone = new node (head->data, nullptr);
	node * ptr = head->next;  //second node in orig.
	node * ptrClone = headClone; //to track the clone list
	while (ptr) 
	{
		ptrClone->next = new node (ptr->data, nullptr);
		ptr = ptr->next;
		ptrClone = ptrClone->next;
	}
	return headClone;

}
// Deep Copy Constructor
linkedlist::linkedlist(const linkedlist & copy)
{
	head = copy.createClone();
}

// Add a new node to a sorted list
void linkedlist::addSorted(string n)
{
	node *newNode = new node;

	newNode->data = n;

	if (isEmpty())
	{
		head = newNode;
		newNode->next = nullptr;
	}

	else
	{
		node *it = head, *prev = head;
		int itdata, id;
		itdata = stoi(it->data);
		id = stoi(n);

		while(itdata < id)
		{
			prev = it;
			it = it->next;
			if (!it)
			{
				break;
			}

			else
			{
				itdata = stoi(it->data);				
			}
			
		}
		
		if (itdata == id)
		{
			delete newNode;
		}
		
		else
		{
			newNode->next = it;
			if(it == head)
			{
				head = newNode;
			}
			else
			{
				prev->next = newNode;
			}
		}
	}
}

// Returns true if the list is empty, returns false otherwise
bool linkedlist::isEmpty()
{
	bool emp = false;
	
	if (head == nullptr)
	{
		emp = true;
	}

	return emp;
}

// Displays datas of every node inside a list
void linkedlist::printList()
{
	node *it = head;

	if (head == nullptr)
	{
		cout << "List is Empty\n";
	}
	else
	{
		while (it != nullptr)
		{
			cout << it->data << endl;
			it = it->next;
		}
		cout << endl;
	}
	
}

// Takes two lists, returns the union of these lists with no duplication
const linkedlist &linkedlist::operator+(const linkedlist & rhs)
{
	static linkedlist it(*this);
	node *r = rhs.head;
	
	if (!r)
	{
		return *this;
	}
	else if (it.isEmpty())
	{
		return rhs;
	}

	while (r != nullptr)
	{
		bool add = true;
		for (node *l = it.head; l != nullptr; l = l->next)
		{
			if (l->data == r->data)
			{
				add = false;
			}			
		}

		if (add)
		{
			it.addSorted(r->data);
		}
		r = r->next;
	}
	
	

	return it; // return result in new object
}

// Takes two lists, returns the values which exist in the first list, but not int the second list. 
const linkedlist& linkedlist::operator-(const linkedlist & rhs)
{
	linkedlist it, lhs (*this), tempr = rhs;
	node *l = lhs.head, *pre = l;

	if (tempr.isEmpty())
	{
		return *this;
	}

	while (l != nullptr)
	{
		bool add = true;
		for (node *r = rhs.head; r != nullptr; r = r->next)
		{
			if (l->data == r->data)
			{
				add = false;
			}
		}

		if (add)
		{
			it.addSorted(l->data);
		}
		l = l->next;
	}
	
	return it; // return result in new object

}

// Index Search Operator. Takes an integer value and returns the data at specified index as a string.
string linkedlist::operator [] (const int n) const
{
	linkedlistIter it(*this);
	int i = 0;
	string error = "Out of bound";
	if (this->head == nullptr)
	{
		error = "List is empty.";
	}

	else
	{
		it.Init(); 
		for (i; it.HasMore() && i < n; i++)
		{
			it.Next();
		}
			
		if(i == n)
		{
			error = it.Current();
		}
			
	}	
	
	return error;	
}

linkedlist::~linkedlist()
{
	node * ptr = head;
	while (ptr != nullptr) 
	{
		 node * temp = ptr->next;
		 delete ptr;
		 ptr = temp;
	}
}
// Free function. Takes two lists and returns the intersection list of these, which involves the common datas.
linkedlist operator & (const linkedlist &lhs, const linkedlist &rhs)
{
	linkedlistIter l(lhs), r(rhs);
	linkedlist inter;
	
	// Compare every data inbetween.
	for (l.Init(); l.HasMore(); l.Next())
	{
		for (r.Init(); r.HasMore(); r.Next())
		{
			// If same data exists in both lists, add it to the returning list.
			if (l.Current() == r.Current())
			{
				inter.addSorted(l.Current());
			}
		}
	}
	if(inter.isEmpty())
	{
		cout << "List is empty.";
	}

	return inter;
}