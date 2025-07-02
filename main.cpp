// Age Calculator Program
// This program calculates a person's age in years, months, days, and other time units

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    // Get current system time
    time_t now = time(0);

    // Convert time to string format and display
    char* dt = ctime(&now);
    cout << "The local date and time is: " << dt << endl;

    // Convert to local time structure for easier access to components
    tm* local = localtime(&now);

    // Extract current date and time components from system
    double hours, mints, seconds, days, weeks, months, years;
    hours = local->tm_hour;
    mints = local->tm_min;
    seconds = local->tm_sec;
    days = local->tm_mday;
    weeks = local->tm_wday;
    months = local->tm_mon + 1;
    years = local->tm_year + 1900;

    int ageN[3];
    string age[3] = { "day","Month","year" };

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter your " << age[i] << endl;
        cin >> ageN[i];
    }

    for (int i = 0; i < 3; i++)
    {
        cout << ageN[i];
        if (i != 2) cout << " | ";
    }
    cout << endl;

    int ageYears = years - ageN[2];
    int ageMonth = months - ageN[1];
    int ageDays = days - ageN[0];

    int age_days = ageYears * 365 + ageMonth * 30 + ageDays;
    int age_weeks = age_days / 7;
    int age_hours = age_days * 24 + hours;
    int age_mintus = age_hours * 60 + mints;
    int age_seconds = age_mintus * 60 + seconds;

    if (ageDays < 0) {
        ageDays += 30;
        ageMonth--;
    }
    if (ageMonth < 0) {
        ageMonth += 12;
        ageYears--;
    }

    cout << "age: " << ageYears << " years, " << ageMonth << " months, " << ageDays << " days" << endl;

    char again;
    do {
        cout << "\nIf you want to know your age more precisely in days, weeks, etc., you must confirm or exit. " << endl;
        cout << "Do you want to continue? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Your age in days: " << age_days << endl;
            cout << "Your age in weeks: " << age_weeks << endl;
            cout << "Your age in hours: " << age_hours << endl;
            cout << "Your age in minutes: " << age_mintus << endl;
            cout << "Your age in seconds: " << age_seconds << endl;
        }
        else if (choice == 'n' || choice == 'N') {
            cout << "Thank you for using the program!" << endl;
        }
        else {
            cout << "Something went wrong please try again!" << endl;
        }

        cout << "Do you want to try the last step? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}