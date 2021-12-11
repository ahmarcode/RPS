#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int a, invest, profit, loss, max, random, current, initial;
    string output, input;
    string rules;
    bool win;
    current = 10000;
    while (current > 0)
    {
        
        cout << "press 1 : play: \nPress 2 : For rules and commands: ";
        cin >> a;
        if(a == 2)
        {
             cout << "If you win the money will be rewarded as doubled of investment.\nIf you lose the investment is gone.\nIf it is draw then get your investment back.\nFor every invalid input 10$ will be reduced.\n";
        }

        else if(a == 1)
        {   initial = current;
            cout << "Your initial money is $" << initial << endl;
            max = 3;
            srand(time(0));
            random = (rand() % max) + 1;
            cout << "Enter the amount you want to invest: ";
            cin >> invest;

            while (invest > current)
            {
                cout << "Be in your limit.\nYou can only invest money you have.\n";

                cout << "Enter the amount you want to invest: ";
                cin >> invest;
            }
       
            cout << "Enter your choice: ";
            cin >> input;
            if (input != "rock" && input != "paper" && input != "scissor")
            {
                cout << "Invalid Input\n";
                current = current - 10;
            }

            if (random == 1)
            {
                output = "rock";
            }

            else if (random == 2)
            {
                output = "paper";
                }

            else if (random == 3)
            {
                output = "scissor";
            }

            if (output == input)
            {
                cout << "Draw.\n";
                cout << "The rival played " << input << endl;
                cout << "Money is refunded." << endl;
                win = true;
            }

            else if (random == 1 && input == "paper")
            {
                cout << "You Win!\n";
                win = true;
                cout << "The rival played rock." << endl;
                ;
            }

            else if (random == 1 && input == "scissor")
            {
                cout << "You Lost!\n";
                win = false;
                cout << "The rival played rock." << endl;
            }

            else if (random == 2 && input == "scissor")
            {
                cout << "You Win!\n";
                win = true;
                cout << "The rival played paper." << endl;
            }

            else if (random == 2 && input == "rock")
            {
                cout << "You Lost!\n";
                win = false;
                cout << "The rival played paper." << endl;
            }

            else if (random == 3 && input == "paper")
            {
                cout << "You Lost!\n";
                win = false;
                cout << "The rival played scissor." << endl;
            }

            else if (random == 3 && input == "rock")
            {
                cout << "You Win!\n";
                win = true;
                cout << "The rival played scissor." << endl;
            }

            if (win == true)
            {
                if (output != input)
                {
                    current = initial - invest;
                    profit = 2 * invest;
                    current = current + profit;
                    cout << "Your current money is $" << current << endl;
                }

                else if (output == input)
                {
                    current = initial;
                    cout << "Your current money is $" << current << endl;
                }
            }

            else if (win == false)
            {
                loss = invest;
                current = initial - loss;
                cout << "Your current money is $" << current << endl;
            }
        }
    }   
    return 0;
}   
