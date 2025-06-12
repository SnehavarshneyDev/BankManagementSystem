
#include <iostream>
using namespace std;

struct Account {
    int accNumber;
    string name;
    float balance;
    int pin;
};

void showMenu() {
    cout << "\n--- Sneha Bank ---\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Display Account Info\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

bool verifyPIN(int realPIN) {
    int inputPIN;
    cout << "Enter your 4-digit PIN: ";
    cin >> inputPIN;
    return inputPIN == realPIN;
}

int main() {
    Account acc;
    int choice;
    bool accountCreated = false;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                cin >> acc.accNumber;
                cin.ignore(); // Clear newline from buffer

                cout << "Enter Name: ";
                getline(cin, acc.name);

                cout << "Enter Initial Balance: ";
                cin >> acc.balance;

                cout << "Set a 4-digit PIN: ";
                cin >> acc.pin;

                accountCreated = true;
                cout << "Account Created Successfully!\n";
                break;

            case 2:
                if (!accountCreated) {
                    cout << "Please create an account first.\n";
                    break;
                }
                if (verifyPIN(acc.pin)) {
                    float deposit;
                    cout << "Enter amount to deposit: ";
                    cin >> deposit;
                    if (deposit > 0) {
                        acc.balance += deposit;
                        cout << "Amount Deposited. New Balance: " << acc.balance << endl;
                    } else {
                        cout << "Invalid deposit amount!\n";
                    }
                } else {
                    cout << "Incorrect PIN.\n";
                }
                break;

            case 3:
                if (!accountCreated) {
                    cout << "Please create an account first.\n";
                    break;
                }
                if (verifyPIN(acc.pin)) {
                    float withdraw;
                    cout << "Enter amount to withdraw: ";
                    cin >> withdraw;

                    if (withdraw <= 0) {
                        cout << "Invalid withdrawal amount!\n";
                    } else if (withdraw <= acc.balance) {
                        acc.balance -= withdraw;
                        cout << "Amount Withdrawn. New Balance: " << acc.balance << endl;
                    } else {
                        cout << "Insufficient Balance!\n";
                    }
                } else {
                    cout << "Incorrect PIN.\n";
                }
                break;

            case 4:
                if (!accountCreated) {
                    cout << "Please create an account first.\n";
                    break;
                }
                if (verifyPIN(acc.pin)) {
                    cout << "\n--- Account Info ---\n";
                    cout << "Account Number: " << acc.accNumber << endl;
                    cout << "Name: " << acc.name << endl;
                    cout << "Balance: " << acc.balance << endl;
                } else {
                    cout << "Incorrect PIN.\n";
                }
                break;

            case 5:
                cout << "Exiting... Thank you!\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
