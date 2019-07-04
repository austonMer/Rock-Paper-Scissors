/*
main.cpp for rock paper scissors

This is an early implementation made without 
splitting the files up.

author: Austin Merrick
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Player
{
    public:
        int choice;

    private:
};

class Computer
{
    public:
        int choice;

    private:
};

class GameRunner
{
    public:
        void getChoices()
        {
            //user choice
            string moveChoice;
            cout << "Choose rock, paper or scissors:" << endl;
            cin >> moveChoice;
            if (moveChoice[0]=='r')
                humanPlayer.choice=0;
            else if (moveChoice[0]=='p')
                humanPlayer.choice=1;
            else if (moveChoice[0]=='s')
                humanPlayer.choice=2;
            else
                humanPlayer.choice=3;

            //here get computer choice
            computerPlayer.choice = (rand() % 3); //random from 0-2

        }
        int evaluateWinner()
        {
            return winGrid[humanPlayer.choice][computerPlayer.choice];
        }
        void sayChoices()
        {
            cout << "You chose ";
                switch(humanPlayer.choice)
                {
                    case 0:
                        cout << "rock." << endl;
                        break;
                    case 1:
                        cout << "paper." << endl;
                        break;
                    case 2:
                        cout << "scissors." << endl;
                        break;
                }

            cout << "Computer chose ";
                switch(computerPlayer.choice)
                {
                    case 0:
                        cout << "rock." << endl;
                        break;
                    case 1:
                        cout << "paper." << endl;
                        break;
                    case 2:
                        cout << "scissors." << endl;
                        break;
                }
            
        }

    private:
        Player humanPlayer;
        Computer computerPlayer;
        const int winGrid[3][3] = {
            {0, 1, 2},
            {2, 0, 1},
            {1, 2, 0},
        };
};

int main()
{
    srand(time(0)); //setting seed from RNG as time

    cout << "Rock paper scissors started!" << endl; 

    GameRunner game;
    game.getChoices(); //calls for user and computer choice
    game.sayChoices();

    switch(game.evaluateWinner())
    {
        case 0:
            cout << "Draw!" << endl;
            break;
        case 1:
            cout << "Computer won!" << endl;
            break;
        case 2:
            cout << "Player won!" << endl;
            break;
    }

    return 0;
}