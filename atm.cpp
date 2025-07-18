#include <iostream>
using namespace std;

void login(string &correct_user_name, string &correct_password, string &user_name, string &password) 
{
    do {
        cout << "\nEnter Username: ";
        cin >> user_name;

        cout << "Enter Password: ";
        cin >> password;

        if (user_name == correct_user_name && password == correct_password) 
        {
            cout << "\nLogin Successful!" << endl;
            break;
        } 
        else 
        {
            cout << "\nIncorrect Username or Password!" << endl;
        }
    } while (true);
}

int main()
{
    int balance = 10000, choice, change_option;
    float deposit_amount, withdraw_amount;
    string correct_user_name = "admin", correct_password = "1234", user_name, password;

    // Initial login
    login(correct_user_name, correct_password, user_name, password);

    do
    {
        cout << "\n===== ATM Menu =====" << endl;
        cout << "1- Check balance" << endl;
        cout << "2- Deposit" << endl;
        cout << "3- Withdraw" << endl;
        cout << "4- Change Username or Password" << endl;
        cout << "5- Exit" << endl;

        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                cout << "\nYour current Bank Balance: " << balance << endl;
                break;
            }
            case 2:
            {
                cout << "\nEnter the amount you want to Deposit: ";
                cin >> deposit_amount;

                if (deposit_amount <= 0)
                {
                    cout << "\nYou can only add amount greater than Zero" << endl;
                }
                else
                {
                    balance += deposit_amount;
                    cout << "\nTransaction successful. New Balance: " << balance << endl;
                }
                break;
            }
            case 3:
            {
                cout << "\nEnter the amount you want to Withdraw: ";
                cin >> withdraw_amount;

                if (withdraw_amount > balance)
                {
                    cout << "\nNot enough balance!" << endl;
                }
                else if (withdraw_amount <= 0)
                {
                    cout << "\nWithdraw amount must be greater than Zero!" << endl;
                }
                else
                {
                    balance -= withdraw_amount;
                    cout << "\nTransaction successful. New Balance: " << balance << endl;
                }
                break;
            }
            case 4:
            {
                cout << "\n1- Username" << endl;
                cout << "2- Password" << endl;

                cout << "Choose Option: ";
                cin >> change_option;

                if (change_option == 1)
                {
                    cout << "\nEnter new Username without space: ";
                    cin >> correct_user_name;

                    cout << "\nUsername updated successfully!" << endl;
                    login(correct_user_name, correct_password, user_name, password);
                }
                else if (change_option == 2)
                {
                    cout << "\nEnter new Password without space: ";
                    cin >> correct_password;

                    cout << "\nPassword updated Successfully!" << endl;
                    login(correct_user_name, correct_password, user_name, password);
                }
                else
                {
                    cout << "\nInvalid Option for change!" << endl;
                }
                break;
            }
            case 5:
            {
                cout << "\nExiting......Thank you for using our Bank service!" << endl;
                break;
            }
            default:
            {
                cout << "\nInvalid Option!" << endl;
            }
        }
    } while (choice != 5);

    return 0;
}