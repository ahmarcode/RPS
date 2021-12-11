#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    //VARIABLE DECLERATION AND INICIALIZATION
    int a, invest, profit, loss, max, random, current, powerup, rob, validity;
    string output, input;
    string rules;
    bool win;
    validity = 20;
    current = 10000;
    while (current > 0)
    {
    //INSTRUCTIONS
        cout << "Press 1 : Play: \nPress 2 : For rules and commands: \nPress 3 : For Power-ups: \nPress 4 : Rob: (Coming Soon)\n";
        cin >> a;

        //RULES AND COMMANDS
        if(a == 2)
        {
             cout << "If you win the money will be rewarded as doubled of investment.\nIf you lose the investment is gone.\nIf it is draw then get your investment back.\nFor every invalid input 10$ will be reduced.\n";
        }

        //POWER-UP STORE
        else if(a == 3)
        {
            cout << "Welcome to STORE OF POWER-UPS.\nPress 1 : Bonus Factor : $2000\nPress 2 : Loss-Guard : $1000\nPress 3 : Rob-Guard : $1500 (Coming Soon)\nPress 4 : Details of POWER-UPS :\n";
            cout << "Your current balance is $" << current << ".\n";
            cin >> powerup;
            

            if(powerup == 4)
            {
                cout << "Bonus Factor : Increases the profit to thrice of investment\n";
                cout << "Loss-Guard : Defend you from losses.\n";
                cout << "Rob-Guard : Security from robbing (Coming Soon)\n";
            }
            
            else if(powerup == 1 || powerup == 2)
            {
            //    if(validity > 0)
            //  {
            //        cout << "Your validity is not over yet. Validity is " << validity << endl;
            //  }
            //    else 
            //    {
                current = current - 2000;
              //  }
            }
            if(powerup != 4)
            {
                cout << "Thanks for Purchasing!!\nThese power-ups are only valid for 20 turns of investments.\n";
            }
        }

        else if(a == 1)
        {   
            //CURRENT MONEY
            cout << "Your initial money is $" << current << endl;
            //OPPONENT RESPONSE GENERATOR
            max = 3;
            srand(time(0));
            random = (rand() % max) + 1;

            //INVESTMENT INPUT
            cout << "Enter the amount you want to invest: ";
            cin >> invest;
            
            //LOW INVESTMENT CONDITION
            while (invest > current)
            {
                cout << "Be in your limit.\nYou can only invest money you have.\n";

                cout << "Enter the amount you want to invest: ";
                cin >> invest;
            }
            //ATTACK INPUT
            cout << "Enter your choice: ";
            cin >> input;

            //INVALID INPUT INITIATIVE
            if (input != "rock" && input != "paper" && input != "scissor")
            {
                cout << "Invalid Input\n";
                current = current - 10;
            }

            //OPPONENT RESPONSE MANUPILATOR
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

            //VICTORY JUDGEMENT
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
            //REWARDS
            if (win == true)
            {
                if (output != input)
                {
                    
                    current = current - invest;
                    //BONUS-FACTOR
                    if(powerup == 1 && validity <= 20)
                    {
                        profit = (3 * invest);
                        validity--;
                    }
                    else 
                    {
                        profit = 2 * invest;
                    }
                    current = current + profit;
                    cout << "Your current money is $" << current << endl;
                }

                else if (output == input)
                {
                    cout << "Your current money is $" << current << endl;
                }
            }

            else if (win == false)
            {
                current = current - invest;
                //LOSS-GUARD
                if(powerup == 2 && validity <= 20)
                {
                    loss = 0;
                }
                else 
                {
                    current = current - loss;
                }
                cout << "Your current money is $" << current << endl;
            }
        }
        

    }   
    return 0;
}
