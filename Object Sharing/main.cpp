// Poyraz Kývanç Karaçam - 20967

#include <iostream>
#include "Board.h"
#include "Player.h"
#include <string>
using namespace std;

int main()
{
	
	bool resume=true;
	string name1, name2;
	Board board;
	cout<<"Please enter the name of the first player: ";
	cin>>name1;
	cout<<"Please enter the name of the second player: ";
	cin>>name2;
	Player player1(board,name1);
	Player player2(board,name2);
	cin.ignore();
	while (resume)
	{
		if (cin.get()=='\n')
		{
			resume=player1.rollDice();
		}
		else
		{
			cout<<"User must press enter to continue the game "<<endl;
			return 0;
		}
		if (cin.get()=='\n')
		{
			if (resume)
			{
			 resume=player2.rollDice();
			}
		}
		else
		{
			cout<<"User must press enter to continue the game "<<endl;
			return 0;
		}
		 board.display();
		
	}

	cout<<"The game is finished and scores of players are as follow: "<<endl;
			double score1=player1.calculateScore(), score2=player2.calculateScore();
			cout<<name1<<"    "<<score1<<endl;
			cout<<name2<<"    "<<score2<<endl;
			cout<<"The winner is: ";
			if (score1==score2)
			{
				cout<<name1<<" and "<<name2;
			}
			else if (score1>score2)
			{
				cout<<name1<<endl;
			}
			else
			{
				cout<<name2<<endl;
			}
}