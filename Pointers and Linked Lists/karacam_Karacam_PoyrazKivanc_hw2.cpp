// Poyraz Kývanç Karaçam	20967


#include "date.h"
#include <iostream>
#include <iomanip>

using namespace std;

struct BorrowInfo
{
	int studentID;
	Date borrowDate;
	Date returnDate;
	BorrowInfo* next;
	BorrowInfo *prev;
};

struct Book
{
	int bookID;
	string bookName;
	Book *next;
	BorrowInfo *borrowInfos;
};

void DisplayMenu();
bool isEmpty(Book *top);
void borrowRefund(Book *top);
bool infoCheck(int stuid, Date const &bdate, const Book *myBook);
bool idCheck(int id, Book *top);
void displayCirc(Book *top);
void displayList(Book *top);
void curBorStu(Book *top);
void preBorStu(Book *top);
void deleteBook(Book *top);
void deleteInfo(BorrowInfo *ptr);
void refund(Book const *myBook);
void ext(Book *top);



void ext(Book *top)
{
	if(top)
	{
		deleteInfo(top->borrowInfos);
		ext(top->next);
		delete top;
	}
}

void refund(Book const *myBook)
{
	int stuid, m, d, y;
	
	BorrowInfo *ptr;

	cout << "Enter the ID of the student: ";
	cin >> stuid;
	cout << endl;

	cout << "Enter the return date for the book in format DD MM YYYY: ";
	cin >> d >> m >> y;
	Date rdate(m, d, y);
	ptr = myBook->borrowInfos;

	while (ptr != nullptr && ptr->studentID != stuid)
	{
		ptr = ptr->next;
	}

	if(ptr == nullptr)
	{
		cout << "You have not borrowed this book!" << endl;
	}

	else if(ptr->next != nullptr && rdate > ptr->next->borrowDate)
	{
			cout << "Return date can not be later since there is a request for the book on " << ptr->next->borrowDate << endl;
	}

	else if(rdate < ptr->borrowDate)
	{
		cout << "Return date could not be sooner that the borrow date!" << endl;
	}

	else
	{
		cout << "Return date of the book with the ID " << myBook->bookID << " is updated from " << ptr->returnDate << " to " << rdate << endl;
		ptr->returnDate = rdate;
	}
}

void deleteInfo(BorrowInfo *ptr)
{	
	if(ptr)
	{
		deleteInfo(ptr->next);
		delete ptr;
	}
}

void deleteBook(Book *top)
{
	int id;
	Book *myBook = top, *pre = myBook;

	cout << "Enter the ID of the book you want to delete: ";
	cin >> id;

	while (myBook != nullptr && myBook->bookID != id)
	{
		pre = myBook;
		myBook = myBook->next;
	}

	if(myBook == nullptr)
	{
		cout << "There is no book in the list." << endl;
	}

	else
	{
		if(myBook->next == nullptr)
		{
			delete myBook->next;
			myBook = nullptr;
		}

		else{
		Book *temp;
		BorrowInfo *del;

		del = myBook->borrowInfos;
		deleteInfo(del);

		temp = myBook->next;
		delete myBook;
		pre->next=temp;
		delete temp;
		}

		cout << "Book is succesfully deleted." << endl;
	}
}
void preBorStu(Book *top)
{
	Book *myBook = top;
	BorrowInfo *ptr;
	int stuid, count = 0;
	Date d;

	

	cout << "Enter ID of the students to see all books previously borrowed by him/her: ";
	cin >> stuid;
	cout << endl;

	for(myBook; myBook != nullptr; myBook = myBook->next)
	{
		ptr = myBook->borrowInfos;
		while(ptr != nullptr)
		{
			if(ptr->studentID == stuid && ptr->returnDate < d)
			{
				cout << "Book ID: " << myBook->bookID << " Book Name: " << myBook->bookName << endl;
				count++;
			}
			ptr = ptr->next;
		}
	}

	if(count == 0)
	{
		cout << "There are no books previously borrowed." << endl;
	}
}

void curBorStu(Book *top)
{
	Book *myBook = top;
	BorrowInfo *ptr;
	int stuid, count = 0;
	Date d;


	cout << "Enter ID of the students to see all books previously borrowed by him/her: ";
	cin >> stuid;
	cout << endl;

	for(myBook; myBook != nullptr; myBook = myBook->next)
	{
		ptr = myBook->borrowInfos;
		while(ptr != nullptr)
		{
			if(ptr->studentID == stuid && ptr->returnDate > d && ptr->borrowDate < d)
			{
				cout << "Book ID: " << myBook->bookID << " Book Name: " << myBook->bookName << endl;
				count++;
			}
			ptr = ptr->next;
		}
	}

	if(count == 0)
	{
		cout << "There are no books currently borrowed." << endl;
	}
}

void displayList(Book *top)
{
	Book *myBook = top;
	int count = 0;

	while(myBook != nullptr)
	{
		cout << "Book ID: " << myBook->bookID << " Name: " << myBook->bookName << endl;
		count++;
		myBook = myBook->next;
	}

	if(count == 0)
	{
		cout << "There are no books in the list." << endl;
	}
}


void displayCirc(Book *top)
{
	Book *bk = top;
	BorrowInfo *ptr;
	int bkid;

	cout << "Enter ID of the book for displaying its circulation : ";
	cin >> bkid;
	cout << endl;

	while(bk != nullptr && bkid != bk->bookID)
	{
		bk = bk->next;
	}

	ptr = bk->borrowInfos;

	if(bk == nullptr)
	{
		cout << "The book does not exist." << endl;
	}

	else if (ptr == nullptr)
	{
		cout << "Circulation info for this book does not exist." << endl;
	}

	else
	{
		cout << setw(22) << "StudentID";
		cout << setw(22) << "BorrowDate";
		cout << "	ReturnDate";
		cout << endl;
	
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
	
		while (ptr != nullptr)
		{
			cout << setw(22) << ptr->studentID;
			cout << setw(22) << ptr->borrowDate;
			cout << "\t" << ptr->returnDate;
			cout << endl;

			ptr = ptr->prev;
		}
	}
}

bool idCheck(int id, Book *top)
{
	Book *temp;
	temp = top;

	while (temp != nullptr)
	{
		if(id == temp->bookID)
		{
			
			return true;
		}
		
		temp = temp->next;
	}
	delete temp;

	return false;
}

bool infoCheck(int stuid, Date const &bdate, const Book *myBook)
{
	bool status = true;
	BorrowInfo *temp;

	temp = myBook->borrowInfos;


	if (temp == nullptr)
	{
		status = true;
	}

	else
	{
		while(temp != nullptr)
		{
			if(stuid == temp->studentID)
			{
				status = false;
				cout << "Student with ID: " << stuid << " could not borrow the book more than once. " << endl;
			}

			else if(temp->returnDate >= bdate)
			{
				status = false;
				cout << "You can not borrow this book. The book is on hold untill: " << temp->returnDate << endl;
			}

			temp = temp->next;
		}		
	}

	delete temp;

	return status;
}

void borrowRefund(Book *top)
{
	int id, stuid, m, d, y;
	string bor;
	Book *myBook = top;

	cout << "Enter the ID of the book: ";
	cin >> id;
	cout << endl;

	while (myBook != nullptr &&  id != myBook->bookID)
	{
		myBook = myBook->next;
	}

	if(!idCheck(id, top))
	{
		cout << "The book does not exist to borrow." << endl;
	}

	else
	{

		cout << "Do you want Borrow or return the book(press B for borrow and R for return): ";
		cin >> bor;
		cout << endl;

		if(bor == "b" || bor == "B")
		{
			cout << "Enter the ID of the student :";
			cin >> stuid;
			cout << endl;

			cout << "Enter the start date for borrowing the book in format DD MM YYYY: ";
			cin >> d >> m >> y;
			Date bordate(m, d, y);
			
			if(infoCheck(stuid, bordate, myBook))
			{
				BorrowInfo *info = new BorrowInfo;
				BorrowInfo *ptr = myBook->borrowInfos;

				
				info->studentID = stuid;
				info->borrowDate = bordate;
				info->returnDate = bordate + 30;

				if(myBook->borrowInfos == nullptr)
				{	
					myBook->borrowInfos = info;
					info->next = nullptr;
					info->prev = nullptr;
					cout << "Borrow information for book ID " << myBook->bookID << " and student ID " <<  info->studentID << " is added to the list." << endl;
					
				}
				else
				{
					BorrowInfo *pre = ptr;
					while (ptr != nullptr && ptr->returnDate < info->borrowDate)
					{
						pre = ptr;
						ptr = ptr->next;
					}
					pre->next = info;
					
					if(ptr == nullptr)
					{
						info->next = nullptr;
						info->prev = pre;
					}
					
					else
					{
						ptr->prev = info;
					}
					cout << "Borrow information for book ID " << myBook->bookID << " and student ID: " <<  info->studentID << " is added to the list." << endl;
				}
			}

		}

		else if (bor == "r" || bor == "R")
		{
			refund(myBook);
		}
	}

}

bool isEmpty(Book *top)
{
	bool status;

	if(top==nullptr)
		status=true;

	else 
		status=false;

	return status;
}



void DisplayMenu()
{
	cout <<"*******************************************************************"<< endl;
	cout <<"* Welcome to the Online Library Manager *"<< endl;
	cout <<"* Please select one option: *"<< endl;
	cout <<"* 1. Add a book *"<< endl;
	cout <<"* 2. Borrow/Return the book *"<< endl;
	cout <<"* 3. Display all previous circulation information for a book *"<< endl;
	cout <<"* 4. Delete a book *"<< endl;
	cout <<"* 5. Find all books which are previously borrowed by a student *"<< endl;
	cout <<"* 6. Find all books which are currently borrowed by a student *"<< endl;
	cout <<"* 7. Display book list *"<< endl;
	cout <<"* 8. Exit *"<< endl;
	cout <<"*******************************************************************"<< endl << endl;
	cout <<"Your choice: " ;
}



int main()
{
	int inp;
	Book *top = new Book;
	top = nullptr;

	Book head();

	do
	{
		DisplayMenu();
		cin >>inp;

		if(inp == 1)
		{
			int id;
			string name, ext;
			char space;
			Book *newBook = new Book;


			cout << "Enter the ID of the book: ";
			cin >> id;
			cin.ignore();

			cout << "Enter the name of the book: ";
			std::getline(cin, name);

			newBook->bookID = id;
			newBook->bookName = name;
			newBook->borrowInfos = nullptr;

			if (isEmpty(top))
			{
				top = newBook;
				top->next = nullptr;
				cout << "BookID " << id << " is added to the list." << endl;
			}

			else
			{
		
		
				if (!idCheck(id, top))
				{
					newBook->next = top;
					top = newBook;

					cout << "BookID " << id << " is added to the list." << endl;
				}

				else
				{
					cout << "The book is already added to the list." << endl;
				}
		
			}

		}
		

		else if(inp == 2)
		{
			borrowRefund(top);
		}

		else if (inp == 3)
		{
			displayCirc(top);
		}

		else if(inp == 4)
		{
			deleteBook(top);
		}

		else if(inp == 5)
		{
			preBorStu(top);
		}

		else if(inp == 6)
		{
			curBorStu(top);
		}

		else if(inp == 7)
		{
			displayList(top);
		}

		else if(inp == 8)
		{
			ext(top);

			cout << "All dynamically allocated memory have been return to heap\n\nProgram Exiting...";

		}

		else
		{
			cout << "Please select a valid number from menu." << endl;
		}
	} while(inp != 8);


	cin.ignore();
	cin.get();

	return 0;
}