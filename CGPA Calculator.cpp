#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double getGradePoints(string grade) {
    if (grade == "A" || grade == "A+") return 4.0;
    else if (grade == "A-") return 3.67;
    else if (grade == "B+") return 3.33;
    else if (grade == "B")  return 3.0;
    else if (grade == "B-") return 2.67;
    else if (grade == "C+") return 2.33;
    else if (grade == "C")  return 2.0;
    else if (grade == "C-") return 1.67;
    else if (grade == "D+") return 1.33;
    else if (grade == "D")  return 1.0;1
    else return 0.0;
}

int main()
{
    int courses;
    double totalGradePoints = 0.0;
    double totalCreditHours = 0.0;

    cout << "========== CGPA Calculator ==========" << endl;
    cout << "Please enter the number of courses you're taking: ";
    cin >> courses;

    if (courses == 0)
        cout << "You're taking no courses";
    else if (courses < 0)
        cout << "Error!!! Invalid courses entered";
    else
    {
        for (int i = 1; i <= courses; i++)
        {
            string grade;
            int cr_hours;

            cout << endl << "--- Course " << i << " ---" << endl;
            cout << "Enter Grade (e.g., A, B+, C): ";
            cin >> grade;
            cout << "Enter Credit Hours: ";
            cin >> cr_hours;

            double points = getGradePoints(grade);

            cout << "-> Points for this course: " << points * cr_hours << endl;

            totalGradePoints += (points * cr_hours);
            totalCreditHours += cr_hours;
        }

        double sgpa = totalGradePoints / totalCreditHours;

        cout << endl << "-----------------------------------" << endl;
        cout << fixed << setprecision(2);
        cout << "Semester GPA (SGPA): " << sgpa << endl;
        cout << "Total Semester Credits: " << totalCreditHours << endl;

        char hasPrevious;
        cout << endl << "Do you have a GPA from previous semesters? (y/n): ";
        cin >> hasPrevious;

        if (hasPrevious == 'y' || hasPrevious == 'Y') {
            double prevCGPA, prevCredits;
            cout << "Enter previous CGPA: ";
            cin >> prevCGPA;
            cout << "Enter total credit hours from previous semesters: ";
            cin >> prevCredits;

            double currentSemPoints = totalGradePoints;
            double prevTotalPoints = prevCGPA * prevCredits;

            double finalTotalPoints = currentSemPoints + prevTotalPoints;
            double finalTotalCredits = totalCreditHours + prevCredits;

            double cgpa = finalTotalPoints / finalTotalCredits;

            cout << "Overall CGPA: " << cgpa << endl;
        }
        else {
            cout << "Overall CGPA: " << sgpa << endl;
        }
    }
    return 0;
}