#ifndef PERSON
#define PERSON


#include <string>
using namespace std;

class person
{

public:
	virtual ~person() { };

	virtual int calSalary() = 0;		// Will be implemented in child classes. Calculates and returns the salary of a person.
	virtual void displayProfile() = 0;	// Will be implemented in child classes. Prints all the values related to a person.
	
	string getName()const
	{
		return name;
	};
	
protected:
	string name;		// Keeps the name of a person.
	int id;				// Keeps the ID of a person.
};

class Student : public person
{

public:
	virtual ~Student() { };

	virtual int calSalary() = 0;		// Will be implemented in child classes.
	virtual void displayProfile() = 0;	// Will be implemented in child classes.

protected:
	bool dormAccomodation;		// Return true if student stays in university campus.
};

class Employee : public person
{

public:
	virtual ~Employee() { };

	virtual int calSalary() = 0;		// Will be implemented in child classes.
	virtual void displayProfile() = 0;	// Will be implemented in child classes.

protected:
	string department;		// Specifies the department an employee works in.
};

class Undergraduate : public Student
{

public:
	Undergraduate();

	virtual int calSalary();			
	virtual void displayProfile();

private:
	int year;		// Returns a student's year in college.
};

class Graduate : public Student
{

public:
	Graduate();

	virtual int calSalary();
	virtual void displayProfile();

private:
	int scholarRank;		// Returns the rank of scholar a student had throughout his education.
	string level;			// Returns the graduation level of a student.
};

class Staff : public Employee
{

public:
	Staff();

	virtual int calSalary();
	virtual void displayProfile();

private:
	int position;			// Returns an employee's position in staff.
	int daysOfWork;			// Returns the day count of an employee.
};

class FacultyMember : public Employee
{

public:
	FacultyMember();

	virtual int calSalary();
	virtual void displayProfile();

private:
	int classestaught;		// Returns the number of classes taught by an instructor.
	int officeHours;		// Returns the number of hours an instructor stays in his office.
	int rank;				// Returns the level of an instructor.
};

#endif