#include <iostream>
#include <iomanip>
using namespace std;

void displayResults(float marks[], string subjects[], float totalGPA)
{
    cout << "\n--- Subject GPAs ---\n";
    for (int i = 0; i < 8; i++)
    {
        cout << fixed << setprecision(2);
        cout << subjects[i] << ": " << marks[i] << endl;
    }

    cout << "\n---------------------\n";
    cout << "Your SGPA is: " << fixed << setprecision(2) << totalGPA / 19 << endl;
    cout << "Thanks for using my program!!" << endl;
}

int main()
{
    float marks[8];
    string subjects[] = {
        "LA",
        "DS",
        "DSA",
        "COAL",
        "TOA",
        "Socio",
        "DSA Lab",
        "COAL Lab"
    };

    int creditHours[] = {3, 3, 3, 3, 3, 2, 1, 1};

    for (int i = 0; i < 8; i++)
    {
        cout << "Enter GPA obtained in " << subjects[i] << ": ";
        cin >> marks[i];
    }

    float totalGPA = 0;
    for (int i = 0; i < 8; i++)
    {
        totalGPA += marks[i] * creditHours[i];
    }

    displayResults(marks, subjects, totalGPA);
    return 0;
}
