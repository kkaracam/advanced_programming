#include "person.h"
#include <iostream>
using namespace std;


Undergraduate::Undergraduate()
{	
	cin >> name >> id >> dormAccomodation >> year;
}

int Undergraduate::calSalary()
{
	return 0;
}

void Undergraduate::displayProfile()
{
	cout << "Name: " << name << "\nID: " << id << "\nDormitory Accomodation: " << (dormAccomodation == 1 ? "Yes" : "No") << "\nYear: " << year << endl;
}

Graduate::Graduate()
{
	cin >> name >> id >> dormAccomodation >> scholarRank >> level;
}

int Graduate::calSalary()
{
	int schCal = (scholarRank-1)*1250;
	return ( level == "phd" ? schCal + 600 : schCal+500);
}

void Graduate::displayProfile()
{
	cout << "Name: " << name << "\nID: " << id << "\nDormitory Accomodation: " << (dormAccomodation == 1 ? "Yes" : "No") << "\nScholarship Rank: " << scholarRank << "\nGraduate Level: " << level << endl;  
}

Staff::Staff()
{
	cin >> name >> id >> department >> position >> daysOfWork;
}

int Staff::calSalary()
{
	return 40*daysOfWork*position;
}

void Staff::displayProfile()
{
	cout << "Name: " << name << "\nID: " << id << "\nDepartment: " << department << "\nPosition: " << position << "\nDays of Work:" << daysOfWork << endl;
}

FacultyMember::FacultyMember()
{
	cin >> name >> id >> department >> classestaught >> officeHours >> rank;
}

int FacultyMember::calSalary()
{
	return classestaught*2000 + officeHours*100 + rank*1000;
}

void FacultyMember::displayProfile()
{
	cout << "Name: " << name << "\nID: " << id << "\nDepartment: " << department << "\nOffice Hours: " << officeHours << "\n# of classes taught: " << classestaught << "\nRank: " << rank << endl;
}