// Poyraz Kývanç Karaçam - 20967

#include <iostream>
#include <string>
using namespace std;

typedef unsigned int ui;

template <typename Type>
void D_Encrypt(const ui *msg, ui *cphr, ui *plaintext, int sz, Type var) // Encrypts the taken integers according to specified key, then decrytps the encryption.
{	
	ui cVar = ui(var), temp = ui(var);		// Converts the key variable into unsigned integer.
	const ui shift = sizeof(Type)*8;		// Initializes shift count according to the specified key type.

	for(ui i = sizeof(Type); i < sizeof(ui); i += sizeof(Type))			// Binary operations to replicate missmatched types.
	{
		cVar = cVar << shift;
		cVar = cVar ^ temp;
	}

	for (int m = 0; m < sz; m++)
	{
		cphr[m] = cVar ^ msg[m];			// Encryption with the taken key.
	}

	for(int i = 0; i < sz; i ++)
	{
		plaintext[i] = cphr[i] ^ cVar;		// Decryption.
	}
}


int main()
{
	cout << "\nJust for FYI --------------------------" << endl;
	cout << "size of unsigned char is " << sizeof(char) << endl;
	cout << "size of unsigned short is " << sizeof(short) << endl;
	cout << "size of unsigned int is " << sizeof(int) << endl;
	cout << "---------------------------------------\n\n\n";

	ui* message_array;
	ui* ciphertext;
	ui* plaintext;

	cout << "Size of the message array is ";
	ui no_ints; 
	cin >> no_ints;
	message_array = new ui[no_ints];
	cout << "Enter the message array integers one after another by pressing enter after each number:" << endl;
	for(int i = 0; i < no_ints; i++) 
	{
	  cin >> message_array[i];
	}
	cout << "Type of key is unsigned ";
	string key_type;
	cin >> key_type;
  
	//TODO: Homework 6
	if (key_type != "int" && key_type != "short" && key_type != "char")
	{
		cout << "Invalid type for key entered. Program exiting...\n";
		exit(1);			// In case of an invalid input, program stops executing.
	}

	else
	{
		ciphertext = new ui[no_ints];		// Memory allocation before calling encryption-decryption function.
		plaintext = new ui[no_ints];

		cout << "The value of the key is ";
		if (key_type == "int")				// Take the key input according to specified key type.
		{
			unsigned int x;			
			cin >> x;
			D_Encrypt(message_array, ciphertext, plaintext, no_ints, x);
		}

		else if (key_type == "short")
		{
			unsigned short x;
			cin >> x;
			D_Encrypt(message_array, ciphertext, plaintext, no_ints, x);
		}

		else if (key_type == "char")
		{
			unsigned char x;
			cin >> x;
			D_Encrypt(message_array, ciphertext, plaintext, no_ints, x);
		}

		cout << "Ciphertext is: ";
		for (ui i = 0; i < no_ints; i++)
		{
			cout << ciphertext[i] << " ";
		}

		cout << "\nPlaintext is: ";
		for (ui i = 0; i < no_ints; i++)
		{
			cout << plaintext[i] << " ";
		}
		
	}



	return 0;
}
