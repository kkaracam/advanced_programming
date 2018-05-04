//	Poyraz Kývanç Karaçam - 20967
#define _VARIADIC_MAX 10

#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <mutex>



using namespace std;

typedef unsigned int uint;


struct transaction {

	//TODO: Implement a transaction
	uint current;
	uint prev;
	uint rand;
	thread::id id;

	transaction *next;
};


struct transactionChain {

	//TODO: Implement a linked-list of transactions. You can implement member functions if needed.
	transaction *head;
};

/* This function hashes a transaction to an unsigned integer value. 
	It shifts curent value by 16, previous value by 8 and the random 
	value by 1 bit to the left and uses std::hash to hash. */
uint hashTransaction(transaction tran)
{
	uint result = (tran.current << 16) ^ (tran.prev << 8) ^ (tran.rand << 1);
	std::hash<uint> uint_hash;
	return uint_hash(result);
}

bool transactionValidator(transactionChain &tChain, uint threshold)
{
	transaction *temp = tChain.head->next;
	bool valid = true;

	while (temp != nullptr)
	{
		if (hashTransaction(*temp) > threshold)
			valid = false;

		temp = temp->next;
	}
	return valid;
}

mutex m;


void mine(bool ready, bool stat, transactionChain &chain, uint ids[], uint threshold, uint &track)
{
	uint bitcoins = 0; // A private unsigned integer for keeping track of the bitcoins mined by this thread.
	
	srand((hash<thread::id>()(this_thread::get_id())) ^ 2 % 10000); // We should use different seeds for each thread to find different random numbers.


	//TODO: Wait until the flag is set.
	while (!ready) 
	{
		this_thread::yield();
	}


	//TODO: Start mining. Each miner will attack the same entry and try finding a solution for that. 
	//					  When a solution is found, every thread should skip to the next entry. (Hint: update the shared integer.)

	transaction *prevT = chain.head;

	while (track <= ids[0])
	{
		stat = true;
		transaction *t = new transaction;
		t->current = ids[track];
		t->prev = hashTransaction(*prevT);
		
		do
		{			
			t->rand = rand();

				if (hashTransaction(*t) < threshold)
				{
					m.lock();
					prevT->next = t;
					prevT = t;
					prevT->next = nullptr;
					track++;
					stat = false;
					bitcoins++;
					m.unlock();
				}
		


		}while (stat);
	}

	//TODO: This line should be printed out one by one by each thread. (Hint: mutex)
	m.lock();
	cout << "Thread " << this_thread::get_id() << " has " << bitcoins << " bitcoin(s)" << endl;
	m.unlock();
}

int main()
{
	/*TODO: -Take inputs from user.*/
	uint diff, numiners;
	ifstream input;
	string filename;


	cout << "Please enter a difficulty level (between 1-10): ";
	cin >> diff;

	uint threshold = 1 << (31 - diff);		// Calculate threshold.
	cout << threshold << " is the threshold." << endl;

	cout << "Please enter the filename of input file: ";
	cin >> filename;
	input.open(filename);

	cout << "Please enter the number of miners: ";
	cin >> numiners;

	uint dummy;
	input >> dummy;
	const uint size = dummy + 1;
	uint *ids = new uint [size];
	ids[0] = dummy;

	for (uint i = 1; input >> dummy; i++)
	{
		ids[i] = dummy;
	}
			/*
			-Read file into an array
			-Create a transaction chain with one node which is [0,0,0, main thread id]
			-Create threads using the mine function. When all threads are created set a flag to start mining.*/
	thread *threads = new thread [numiners];
	transaction *prime = new transaction;
	prime->current = 0;
	prime->prev = 0;
	prime->rand = 0;
	prime->id = this_thread::get_id();

	transactionChain chain;
	chain.head = prime;
	chain.head->next = nullptr;

	uint track = 1;

	bool ready= false;
	bool stat = true;
	

	for (uint i=0; i < numiners; ++i)
	{
		threads[i] = thread(mine, &ready, &stat, chain, ids, threshold, track);
	}
	ready = true;
			/*-Check validity
			-Don't forget to join the threads	*/
	for (uint i=0; i < numiners; ++i)
	{
		threads[i].join();
	}
	if (transactionValidator(chain, threshold))
	{
		cout << "Transaction is valid.\n";
	}

	


	return 0;
}


