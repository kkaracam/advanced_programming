// Poyraz Kývanç Karaçam	20967

#include <iostream>
#include <string>
#include "dyncharstack.h"
#include "dyncharqueue.h"

using namespace std;

int main()
{
	
	string s, input;

	do
	{
		cout << "Please choose which sequence format you are going to search ? First or Second: ";
		cin >> s;


		if(cin.eof())
		{
		}

		else if(s != "1" && s != "2")
		{
			cout << "You entered invalid input." << endl;
		}

		else
		{
			cout << "Enter a sequence: ";
			cin >> input;

			string frm = "The input is in correct format.\n";
			if(s == "1")
			{	
				DynCharStack stack;
				
				
				for(char & chr:input)
				{
					
					char rhs;

					if(chr >= 'a')
					{
						stack.push(chr);
					}
					else if(chr >= 'A')
					{
						stack.pop(rhs);
						
						if(rhs - chr != char('a') - char('A'))
						{
							frm = "Invalid format.\n";
						}
					}

				}

				if(!stack.isEmpty())
				{
					frm =  "Invalid format.\n";
				}

				cout << frm;
			}

			else if (s == "2")
			{
				DynCharQueue queue;

				for(char & chr:input)
				{
					
					char token;
					
					if(chr >= 'a')
					{
						queue.enqueue(chr);
					}
					else if(chr < 'a')
					{
						queue.dequeue(token);
						
						if(token - chr != char('a') - char('A'))
						{
							frm = "Invalid format.\n";
						}
					}
				}
				
				if(!queue.isEmpty())
				{
					frm =  "Invalid format.\n";
				}

				cout << frm;
			}
		}

	} while(!cin.eof());
	
	cin.ignore();
	cin.get();

	return 0;
}