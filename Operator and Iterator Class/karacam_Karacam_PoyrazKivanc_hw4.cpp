//	Poyraz Kıvanç Karaçam 20967

#include"linkedlist.h"

// Takes student IDs as inputs from the use for a course until (Ctrl+Z) entered, creates a sorted list.
void MakeList(linkedlist &crs)
{
	string crsname;

	cout << "Enter the name of the course: ";
	cin >>crsname;
	cout << "Course " << crsname << " registration list.\n";

	while (!cin.eof())		// Until (Ctrl+Z)
	{
		string id;
		
		cout << "Please enter a student ID:\n";
		cin >> id;
		if (cin.eof())
		{
			break;
		}

		crs.addSorted(id);
	}
	cin.clear();		// To avoid possible complications about iostream.

	cout << "List of students who registered to the course "<< crsname << ":\n" ;
	if (crs.isEmpty())
	{
		cout << "List is empty.\n\n";
	}
	else
	{
		crs.printList();
		cout << endl;
	}
}

// This menu is displayed to the user after the lists are created and until user wants to exit.
void DisplayMenu()
{
	cout << "\n***************************" << endl;
	cout << "* 1. union(+) *" << endl;
	cout << "* 2. difference(-) *" << endl;
	cout << "* 3. Intersection (&) *" << endl;
	cout << "* 4. [] operator *" << endl;
	cout << "* 5. Exit *" << endl;
	cout << "***************************" << endl;
}

linkedlist Union(linkedlist crs1, linkedlist crs2)
{
	linkedlist *res = new linkedlist;

	cout << "Union of two lists:\n";
	*res = crs1 + crs2;
	return *res;
}

linkedlist Difference(linkedlist crs1, linkedlist crs2)
{
	linkedlist res;
	int side;
	cout << "Please enter the lhs list: ";
	cin >> side;

	if (side == 1)		// If the first list is lhs:
	{
		res = crs1 - crs2;
		cout << "Difference of list1 - list2:\n";
	}
	
	else				// If the second list is lhs:
	{
		res = crs2 - crs1;
		cout << "Difference of list1 - list2:\n";
	}

	
	return res;
}

linkedlist Intersection(linkedlist crs1, linkedlist crs2)
{
	cout << "Intersection of two lists:\n";

	return crs1 & crs2;
}

string IndexSearch(linkedlist crs)
{
	int index;
	string *ind = new string;

	cout << "Please enter an index number: ";
	cin >> index;
	cout << endl;

	cout << "The index " << index << " of the list is:\n";
	*ind = crs[index];

	return *ind;
}

int main()
{
	linkedlist crs1, crs2;
	
	MakeList(crs1);
	MakeList(crs2);
	int inp;

	do
	{
		DisplayMenu();

		cout << "\nYour choice: ";
		cin >> inp;
		cout << endl;

		if (inp == 1)
		{
			Union(crs1, crs2).printList();
		}

		else if (inp == 2)
		{
			Difference(crs1, crs2).printList();
		}

		else if (inp == 3)
		{
			Intersection(crs1, crs2);
		}

		else if (inp == 4)
		{
			int list;
			cout << "Please enter the list number: ";
			cin >> list;

			if (list == 1)
			{
				cout << IndexSearch(crs1);
			}

			else if (list == 2)
			{
				cout << IndexSearch(crs2);
			}
		}

	} while (inp != 5);

	cout << "\nProgram exiting...\n";

	return 0;
}