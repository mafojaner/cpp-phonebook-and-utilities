#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;


void toolkitHeader() {
    cout << "===================================================" << endl;
    cout << "=========UTILITY TOOLKIT: IT Professionals=========" << endl;
    cout << "===================================================" << endl;
}

void toolkitPrompt() {
    cout << "Welcome to the productivity Utility Toolkit! Use any of the following tools:" << endl;
    cout << "" << endl;
    cout << "1. Acronym Generator" << endl;
    cout << "2. Vowel Counter" << endl;
    cout << "3. Currency Formatter" << endl;
    cout << "0. Exit" << endl;
    cout << "Which tool do you want to use? (Select by entering either of 1 - 3 or 0)" << endl;
}

void toolkitSyntaxError() {
    cout << "" << endl;
    cout << "===================================================" << endl;
    cout << "=============UTILITY TOOLKIT: - Error==============" << endl;
    cout << "===================================================" << endl;
    cout << "" << endl;
    cout << "That is not a valid menu option! Enter one of the correct numbers as shown in menu" << endl;
    cout << "Valid options: Either 1-3, or 0 to exit." << endl;
}

void toolkitExitMessage() {
    cout << "" << endl;
    cout << "=============[ Exiting Utility Toolkit...]=================" << endl;
    cout << "" << endl;
    cout << "Thank you for using the Utility Toolkit!<< endl" << endl;
}


void acronymHeader() {
    cout << "" << endl;
    cout << "===================================================" << endl;
    cout << "=============UTIL: ACRONYM GENERATOR===============" << endl;
    cout << "===================================================" << endl;
    cout << "" << endl; 
}

void acronymPrompt() {
    cout << "Welcome to the Acronym Generator!" << endl;
    cout << "Please enter a multi-word term/phrase/noun to form an cronym (2 words or more)" << endl;
}

void acronymError() {
    cout << "" << endl;
    cout << "===================================================" << endl;
    cout << "========UTIL: ACRONYM GENERATOR - Error============" << endl;
    cout << "===================================================" << endl;
    cout << "" << endl;
    cout << "Two or more words required to form an acronym! \n(each word should be space seperated) \nPlease ensure you enter a term/phrase/noun with 2 words or more." << endl;
}

void generateAcronym(string inputPhrase) {
    cout << "" << endl;
    cout << "===================================================" << endl;
    cout << "=========UTIL: ACRONYM GENERATOR - Result==========" << endl;
    cout << "===================================================" << endl;
    cout << "" << endl;
    cout << "Your acronym is: " << inputPhrase << endl;
}

void generateAcronym() {
    while (true) {
        acronymHeader();
        acronymPrompt();

        string user_input;
        getline(cin >> ws, user_input); 

        stringstream ss(user_input);
        string word;
        string acronym = "";
        int wordCount = 0;

        while (ss >> word) {
            if (!word.empty()) {
                acronym += toupper(word[0]);
                wordCount++;
            }
        }

        cout << "" << endl;

        if (wordCount < 2) {
            acronymError();
            cout << "\nPlease try again:\n" << endl;
            continue; 
        } 
        else {
            cout << "===================================================" << endl;
            cout << "=========UTIL: ACRONYM GENERATOR - Result==========" << endl;
            cout << "===================================================" << endl;
            cout << "" << endl;
            cout << "The Acronym for \"" << user_input << "\" is: " << acronym << endl;
            cout << "Press 'Return/Enter' to return to the main menu." << endl;
            break; 
        }
    }
}


void vowelHeader() {
    cout << "" << endl;
    cout << "===================================================" << endl;
    cout << "===============UTIL: VOWEL COUNTER=================" << endl;
    cout << "===================================================" << endl;
    cout << "" << endl; 
}

void vowelPrompt() {
    cout << "Welcome to the Vowel Counter!" << endl;
    cout << "Please enter the text to count the number of vowels (max 250 characters)" << endl;
}

void vowelError() {
    cout << "" << endl;
    cout << "===================================================" << endl;
    cout << "===========UTIL: VOWEL COUNTER - Error=============" << endl;
    cout << "===================================================" << endl;
    cout << "The input text is too great to calculate (max 250 characters)" << endl;
    cout << "" << endl;
}

void generateVowel() {
    cout << "" << endl;
    cout << "===================================================" << endl;
    cout << "===========UTIL: VOWEL COUNTER - Result============" << endl;
    cout << "===================================================" << endl;
    cout << "" << endl;
    cout << "Your acronym is: ";
}

void vowelCounter() {
    while (true) { 
        vowelHeader();
        vowelPrompt();

        string user_input;
        getline(cin >> ws, user_input);

        if (user_input.empty() || user_input.find_first_not_of(' ') == string::npos) {
            vowelError();
            cout << "\nInput cannot be empty. Please try again.\n" << endl;
            continue;
        }
        if (user_input.length() > 250) {
            vowelError();
            continue;
        }

        int vowelCount = 0;
        for (char c : user_input) {
            char lowerC = tolower(c);
            if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
                vowelCount++;
            }
        }

        cout << "" << endl;
        cout << "===================================================" << endl;
        cout << "===========UTIL: VOWEL COUNTER - Result============" << endl;
        cout << "===================================================" << endl;
        cout << "\nThe input \"" << user_input << "\" contains " << vowelCount << " vowel";
        if (vowelCount != 1) cout << "s";
        cout << "." << endl;

        break; 
    }
}




void currencyHeader() {
    cout << "" << endl;
    cout << "===================================================" << endl;
    cout << "===============UTIL: CURRENCY FORMATTER===========" << endl;
    cout << "===================================================" << endl;
    cout << "" << endl;
}

void currencyPrompt() {
    cout << "Welcome to the Currency Formatter!" << endl;
    cout << "Please enter a positive numerical amount to format as currency: " << endl;
}

void currencyError() {
    cout << "" << endl;
    cout << "===================================================" << endl;
    cout << "===========UTIL: CURRENCY FORMATTER - Error=======" << endl;
    cout << "===================================================" << endl;
    cout << "" << endl;
    cout << "Invalid input! Enter a positive numerical value only." << endl;
}

void currencyResult(string formattedAmount) {
    cout << "" << endl;
    cout << "===================================================" << endl;
    cout << "===========UTIL: CURRENCY FORMATTER - Result=======" << endl;
    cout << "===================================================" << endl;
    cout << "" << endl;
    cout << "The formatted amount is: " << formattedAmount << endl;
    cout << "Amount successfully written to balance.txt" << endl;
    cout << "Press 'Return/Enter' to return to the main menu." << endl;
}


void currencyFormatter() {
    while (true) {
        currencyHeader();
        currencyPrompt();

        string input;
        getline(cin >> ws, input);

        double amount;
        try {
            amount = stod(input);
            if (amount < 0) throw invalid_argument("negative number");
        } catch (...) {
            currencyError();
            continue; 
        }


        amount = round(amount * 100) / 100.0;

       
        stringstream ss;
        ss << fixed << setprecision(2) << amount;
        string str = ss.str();
        int dotPos = str.find('.');
        string intPart = str.substr(0, dotPos);
        string decimalPart = str.substr(dotPos); 

        string formatted = "";
        int count = 0;
        for (int i = intPart.size() - 1; i >= 0; --i) {
            formatted = intPart[i] + formatted;
            count++;
            if (count % 3 == 0 && i != 0)
                formatted = "," + formatted;
        }
        formatted += decimalPart;
        formatted = "R " + formatted;

     
        ofstream file("balance.txt", ios::app);
        if (file)
            file << formatted << endl;

        currencyResult(formatted);
        break; 
    }
}


int main() {
    int userChoice;

    while (true) { 
        toolkitHeader();
        toolkitPrompt();

        while (true) {
            cin >> userChoice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                toolkitSyntaxError();
                continue;
            }

            if (userChoice >= 0 && userChoice <= 3) {
                break; 
            } else {
                toolkitSyntaxError();
            }
        }

        switch (userChoice) {
            case 0:
                toolkitExitMessage();
                return 0; 
            case 1:
                generateAcronym();
                break;
            case 2:
                vowelCounter();
                break;
            case 3:
                currencyFormatter ();
                break;
            default:
                break;
        }

        cout << "\nPress Enter to return to the main menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}
