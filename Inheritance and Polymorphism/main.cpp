//	Poyraz Kývanç Karaçam - 20967

#include <iostream>
#include "person.h"

using namespace std;

person *getPerson()
{
	int in;
	cout << "Choose an option:\n1.undergraduate student\n2.graduate student\n3.staff\n4.faculty member\n";
	cin >> in;
	
	person *per;
	if (in == 1)
	{
		cout << "You chose undergraduate. Give person's name, id, accommodation status (1 for yes and 0 for no), and year:\n";
		per = new Undergraduate;		
	}

	else if (in == 2)
	{
		cout << "You chose graduate. Give person's name, id, accommodation status (1 for yes and 0 for no),scholar Rank(btw 1 and 3) and level(phd or master):\n";
		per = new Graduate;
	}

	else if (in == 3)
	{
		cout << "You chose staff. Give person's name, id, department, position(btw 1 and 4) and Days of work:\n";
		per = new Staff;
	}

	else
	{
		cout <<	"You chose faculty member. Give person's name, id, department, number of classes taught,officehours, and rank(btw 1 and 4):\n";
		per = new FacultyMember;
	}

	return per;
}

int main()
{
	cout << "WELCOME TO THE PERSON PROGRAM" << endl;
	cout << "FOR EXITIING PRESS Y/y, OTHERWISE PRESS ANY KEY" <<endl;
	person *person_1; /* define person_1 of the class person.*/
	char c;
	while (tolower(c = getchar())!='y')
	{
		cout<<"Getting person "<<endl;
		person_1 = getPerson();
		cout<<"********************************************************************"<<endl<<endl;
	    cout<<"The profile of a person:"<<endl;
		person_1->displayProfile();
		cout<<"Salary: "<<person_1->calSalary()<<endl;
		cout<<"********************************************************************"<<endl;
		cout<<"FOR EXITIING PRESS Y/y, OTHERWISE, FOR ANOTHER COMPARISON PRESS ANY KEY"<<endl<<endl;
		cin.ignore();//flushing the buffer for remaining character(s), in order getchar() to work
	}
	cout<<"PROGRAM EXITING. THANKS FOR USING IT."<<endl;
    system("pause");
    return 0;
}