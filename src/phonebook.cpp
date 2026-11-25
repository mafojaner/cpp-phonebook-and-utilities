#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
using namespace std;

struct Contact {
    string firstName;
    string surname;
    string phoneNumber;
    string email;

    void display() const {
        cout << left << setw(15) << firstName
             << setw(15) << surname
             << setw(15) << phoneNumber
             << setw(25) << email << endl;
    }
};

struct Phonebook {
    vector<Contact> contacts;
    const int MAX_CONTACTS = 15;

    void loadFromFile() {
        cout << "\nLoading contacts from file...\n";

        ifstream file("contactList.dat");
        if (!file.is_open()) {
            cout << "No existing contact list found. Starting fresh.\n";
            return;
        }

        contacts.clear();
        string line;
        getline(file, line); 

        Contact c;
        int loadedCount = 0;
        while (file >> c.firstName >> c.surname >> c.phoneNumber >> c.email) {
            contacts.push_back(c);
            loadedCount++;
        }

        file.close();
        cout << "Contacts loaded successfully! " << loadedCount 
             << "contact(s) found.\n";
    }

    void saveToFile() {
        ofstream file("contactList.dat");
        file << left << setw(15) << "FirstName"
             << setw(15) << "Surname"
             << setw(15) << "PhoneNumber"
             << setw(25) << "Email" << endl;

        for (const auto& c : contacts) {
            file << left << setw(15) << c.firstName
                 << setw(15) << c.surname
                 << setw(15) << c.phoneNumber
                 << setw(25) << c.email << endl;
        }
        file.close();
    }

    bool isValidPhoneNumber(const string& number) {
        if (number.length() != 10) return false;
        for (char ch : number) if (!isdigit(ch)) return false;
        return true;
    }

    bool isValidName(const string& name) {
        if (name.length() <= 1) return false;
        for (char ch : name) if (!isalpha(ch)) return false;
        return true;
    }

    bool isValidEmail(const string& email) {
        return (email.find('@') != string::npos) && (email.find('.') != string::npos);
    }

    void addContact() {
        if (contacts.size() >= MAX_CONTACTS) {
            cout << "\nPhonebook is full! Maximum contacts reached.\n";
            cout << "Current contacts:\n";
            cout << left << setw(5) << "ID" 
                 << setw(15) << "FirstName" 
                 << setw(15) << "Surname" 
                 << setw(15) << "PhoneNumber" 
                 << setw(25) << "Email" << endl;
            cout << string(75, '-') << endl;

            for (size_t i = 0; i < contacts.size(); i++) {
                cout << setw(5) << i + 1;
                contacts[i].display();
            }

            int action;
            do {
                cout << "\nChoose an action:\n";
                cout << "1. Go back to main menu\n";
                cout << "2. Delete a contact to add a new one\n";
                cout << "Enter choice (1 or 2): ";
                cin >> action;

                if (cin.fail() || (action != 1 && action != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nInvalid input. Enter 1 or 2.\n";
                    continue;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            } while (true);

            if (action == 1) {
                cout << "\nReturning to main menu...\n";
                return;
            } else {
                int deleteID;
                do {
                    cout << "Enter the ID of the contact to delete (1-" << MAX_CONTACTS << "): ";
                    cin >> deleteID;
                    if (cin.fail() || deleteID < 1 || deleteID > (int)contacts.size()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid ID. Try again.\n";
                    } else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                } while (true);

                contacts.erase(contacts.begin() + deleteID - 1);
                cout << "Contact deleted. You can now add a new contact.\n";
            }
        }

        Contact newContact;

        // Input first name
        do {
            cout << "Enter First Name: ";
            cin >> newContact.firstName;
            if (!isValidName(newContact.firstName))
                cout << "Invalid input. Name must be at least 2 letters and contain only alphabets.\n";
        } while (!isValidName(newContact.firstName));

        // Input surname
        do {
            cout << "Enter Surname: ";
            cin >> newContact.surname;
            if (!isValidName(newContact.surname))
                cout << "Invalid input. Surname must be at least 2 letters and contain only alphabets.\n";
        } while (!isValidName(newContact.surname));

        // Input phone number
        do {
            cout << "Enter Phone Number (10 digits, numbers only): ";
            cin >> newContact.phoneNumber;
            if (!isValidPhoneNumber(newContact.phoneNumber))
                cout << "Invalid phone number. Must be 10 digits with no letters.\n";
        } while (!isValidPhoneNumber(newContact.phoneNumber));

        // Input email
        do {
            cout << "Enter Email Address: ";
            cin >> newContact.email;
            if (!isValidEmail(newContact.email))
                cout << "Invalid email. Must contain '@' and '.' (e.g., example@outlook.com).\n";
        } while (!isValidEmail(newContact.email));

        contacts.push_back(newContact);
        saveToFile();
        cout << "\nContact added successfully!\n";
    }

    void findContact() {
        string query;
        do {
            cout << "\nEnter first name or surname to search: ";
            cin >> query;
            if (query.length() <= 1)
                cout << "Your input is either too short or empty. Please enter at least 2 characters.\n";
        } while (query.length() <= 1);

        bool found = false;
        cout << "\nSearch Results:\n";
        cout << left << setw(15) << "FirstName"
             << setw(15) << "Surname"
             << setw(15) << "PhoneNumber"
             << setw(25) << "Email" << endl;
        cout << string(70, '-') << endl;

        for (const auto& c : contacts) {
            if (c.firstName == query || c.surname == query) {
                c.display();
                found = true;
            }
        }

        if (!found)
            cout << "No contact found with that name.\n";
    }

    void displayContacts() {
        if (contacts.empty()) {
            cout << "\nNo contacts to display.\n";
            return;
        }

        cout << "\nAll Contacts:\n";
        cout << left << setw(5) << "ID"
             << setw(15) << "FirstName"
             << setw(15) << "Surname"
             << setw(15) << "PhoneNumber"
             << setw(25) << "Email" << endl;
        cout << string(75, '-') << endl;

        for (size_t i = 0; i < contacts.size(); i++) {
            cout << setw(5) << i + 1;
            contacts[i].display();
        }
    }
};

int main() {
    Phonebook phonebook;
    phonebook.loadFromFile();
    int choice;

    while (true) {
        cout << "\n====== PHONEBOOK MENU ======" << endl;
        cout << "Contacts Loaded: " << phonebook.contacts.size()
             << " / " << phonebook.MAX_CONTACTS << endl;
        cout << "1. Add New Contact" << endl;
        cout << "2. Find Contact" << endl;
        cout << "3. Display All Contacts" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number between 0 and 3.\n";
            cout << "Press Enter to try again...";
            cin.get();
            cin.get();
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice < 0 || choice > 3) {
            cout << "\nPlease enter a valid option (0-3).\n";
            cout << "Press Enter to try again...";
            cin.get();
            continue;
        }

        switch (choice) {
            case 1:
                phonebook.addContact();
                break;
            case 2:
                phonebook.findContact();
                break;
            case 3:
                phonebook.displayContacts();
                break;
            case 0:
                cout << "\nExiting Phonebook. Goodbye!\n";
                phonebook.saveToFile();
                return 0;
        }
    }

    return 0;
}
