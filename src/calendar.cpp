#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


enum Months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
enum Weekdays { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };
enum TimeOfDay { HOUR = 0, SECOND = 0 };


namespace TimeUtils {


    void display12HourFormat(int hour, int minute) {
        string period = (hour >= 12) ? "PM" : "AM";
        int hour12 = (hour % 12 == 0) ? 12 : (hour % 12);
        cout << "\n12-hour format: "
             << setw(2) << setfill('0') << hour12 << ":"
             << setw(2) << setfill('0') << minute << " " << period << endl;
    }


    void displayHoursRemaining(int hour) {
        if (hour < 0 || hour > 23) {
            cout << "Invalid hour input. Must be between 0 and 23.\n";
            return;
        }
        cout << "Hours remaining in the day: " << (23 - hour) << " hours.\n";
    }
}


namespace CalendarUtils {


    string getMonthName(int month) {
        string names[] = {"January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};
        if (month >= 1 && month <= 12)
            return names[month - 1];
        else
            return "Invalid";
    }


    int getDaysInMonth(int month) {
        switch (month) {
            case APR: case JUN: case SEP: case NOV:
                return 30;
            case FEB:
                return 28;
            default:
                return 31;
        }
    }


    void displayMonthDetails(int month, int firstDay) {
        cout << "\nMonth: " << getMonthName(month) << endl;
        cout << "Number of days: " << getDaysInMonth(month) << endl;

        string weekDays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        cout << "First day of the month: " << weekDays[firstDay % 7] << endl;
    }


    void generateCalendar(int month, int firstDay) {
        int days = getDaysInMonth(month);
        cout << "\n     " << getMonthName(month) << " Calendar\n";
        cout << "Su Mo Tu We Th Fr Sa\n";


        for (int i = 0; i < firstDay; ++i)
            cout << "   ";

        for (int d = 1; d <= days; ++d) {
            cout << setw(2) << d << " ";
            if ((d + firstDay) % 7 == 0) cout << endl;
        }
        cout << "\n";
    }
}


int main() {
    int choice;

    do {
        cout << "\n========= CALENDAR APPLICATION =========\n";
        cout << "1. Time Utilities\n";
        cout << "2. Calendar Utilities\n";
        cout << "3. Exit\n";
        cout << "===============================================\n";
        cout << "Select a menu option by entering any number between 1 - 3: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n==============================\n";
                cout << "        TIME UTILITIES\n";
                cout << "==============================\n";
                int hour, minute;
                cout << "Enter hour (0-23): ";
                cin >> hour;
                cout << "Enter minute (0-59): ";
                cin >> minute;

             
                TimeUtils::display12HourFormat(hour, minute);
                TimeUtils::displayHoursRemaining(hour);
                break;
            }

            case 2: {
                cout << "\n==============================\n";
                cout << "       CALENDAR UTILITIES\n";
                cout << "==============================\n";
                int month, firstDay;
                cout << "Enter month number (1-12): ";
                cin >> month;
                cout << "Enter first day of month (0=Sun, 1=Mon, ..., 6=Sat): ";
                cin >> firstDay;

              
                CalendarUtils::displayMonthDetails(month, firstDay);
                CalendarUtils::generateCalendar(month, firstDay);
                break;
            }

            case 3:
                cout << "\nExiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
