#include <iostream>
#include <string>
using namespace std;

double cash = 0.0;

// Function to display the menu and get the user's choice
int getMenuChoice() {
    int choice;
    cout << "\nCINECHAI MENU\n";
    cout << "Your balance is $" << cash << endl;
    cout << "1. View films\n";
    cout << "2. View date & time\n";
    cout << "3. View price\n";
    cout << "4. Deposit cash\n";
    cout << "5. Book a ticket\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
    cin >> choice;
    return choice;
}

// Function to view the available films
void viewFilms() {
    cout << "\nAvailable films:\n";
    cout << "1. The Shawshank Redemption\n";
    cout << "2. The Godfather\n";
    cout << "3. The Dark Knight\n";
    cout << "4. Forrest Gump\n";
}

// Function to view the available dates and times
void viewDateAndTime() {
    cout << "\nAvailable date and time:\n";
    cout << "1. April 14, 2023 1:30PM\n";
    cout << "2. April 14, 2023 4:30PM\n";
    cout << "3. April 14, 2023 7:30PM\n";
}

// Function to view the prices
void viewPrice() {
    cout << "\nPrices:\n";
    cout << "Regular: $10.00\n";
    cout << "Senior Citizen: $8.00\n";
    cout << "Student: $8.00\n";
}

// Function to deposit cash
void depositCash(double amount) {
    double deposit;
    while (true) {
        cout << "\nEnter amount to deposit: $";
        if (cin >> deposit) {
            break;
        } else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore();
        }
    }
    cash += deposit;
    
    cout << "New balance: $" << cash << endl;
}


// Function to book a ticket
void bookTicket() {
    string film;
    int dateAndTime, age, cinemaGate;
    double price;
    const double REGULAR_PRICE = 10.00;
    const double SENIOR_CITIZEN_PRICE = 8.00;
    const double STUDENT_PRICE = 8.00;

    // Get film choice
    viewFilms();
    cout << "Enter the number of the film you want to watch: ";
    cin >> film;

    // Get date and time choice
    viewDateAndTime();
    cout << "Enter the number of the date and time you want to watch: ";
    cin >> dateAndTime;

    // Get age
    cout << "Enter your age: ";
    cin >> age;

    // Calculate price
    if (age >= 60) {
        price = SENIOR_CITIZEN_PRICE;
    } else if (age <= 18) {
        price = STUDENT_PRICE;
    } else {
        price = REGULAR_PRICE;
    }

    // Check if user has enough cash
    cout << "Price of ticket: $" << price << endl;
    cout << "Your balance: $" << cash << endl;
    if (cash < price) {
        cout << "Not enough cash. Please deposit more money.\n";
        return;
    }

    // Deduct price from balance
    cash -= price;

    // Determine cinema gate
    switch (dateAndTime) {
        case 1:
            cinemaGate = 1;
            break;
        case 2:
            cinemaGate = 2;
            break;
        case 3:
            cinemaGate = 3;
            break;
        default:
            cinemaGate = -1;
            break;
    }

    // Display ticket
    cout << "\nTicket:\n";
    cout << "Film: " << film << endl;
    cout << "Date and time: ";
    switch (dateAndTime) {
        case 1:
            cout << "April 14, 2023 1:30PM";
            break;
        case 2:
            cout << "April 14, 2023 4:30PM";
            break;
        case 3:
            cout << "April 14, 2023 7:30PM";
            break;
        default:
            cout << "Invalid date and time";
            break;
    }
    cout << endl;
    cout << "Cinema gate number: " << cinemaGate << endl;
    cout << "Price: $" << price << endl;
    cout << "New balance: $" << cash << endl;
}


int main() {
    int choice;

    do {
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                viewFilms();
                break;
            case 2:
                viewDateAndTime();
                break;
            case 3:
                viewPrice();
                break;
            case 4:
                depositCash(cash);
                break;
            case 5:
                bookTicket();
                break;
            case 6:
                cout << "\nThank you for using the Cinema System!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
