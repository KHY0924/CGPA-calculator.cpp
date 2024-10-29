#include <iostream>
#include <iomanip>
using namespace std;

float update_grade(string grade); // Declare the update_grade function

int main() {
    int sem, subject, obtainhours;  // Semester, number of subjects, and credit hours
    float cgpa_sum = 0.0;           // CGPA total (sum of all semester GPAs)
    int totalCreditHours = 0;       // Total credit hours across all semesters
    string grade;                   // Grade input

    cout << "Enter the number of semesters (1-4): ";
    cin >> sem;

    // Check if the semester count is valid
    while (sem < 1 || sem > 4) {
        cout << "Invalid number of semesters. Please enter a valid number (1-4): ";
        cin >> sem;
    }

    cout << "\nCGPA Calculator\n";
    cout << "-----------------------------------------\n";

    // Loop through each semester
    for (int i = 0; i < sem; i++) {
        int semesterCreditHours = 0;  // Total credit hours for the current semester
        float semester_sum = 0.0;     // Weighted grade points total for the current semester

        cout << "Semester " << (i + 1) << ":\n";
        cout << "-----------------------------------------\n";
        cout << left << setw(15) << "Subject" << setw(10) << "Grade" << setw(15) << "Credit Hours" << setw(10) << "Points" << endl;
        cout << "-----------------------------------------\n";
        
        cout << "Enter the number of subjects for semester " << (i + 1) << ": ";
        cin >> subject;

        // Loop through each subject
        for (int j = 0; j < subject; j++) {
            cout << "Enter the grade for subject " << (j + 1) << " (A+, A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
            cin >> grade;
            cout << "Enter the credit hours for this subject: ";
            cin >> obtainhours;

            float grade_point = update_grade(grade);  // Get the grade point

            if (grade_point == -1) {
                cout << "Invalid grade entered.\n";
            } else {
                semester_sum += grade_point * obtainhours; // Weighted grade points for the current semester
                semesterCreditHours += obtainhours;        // Total credit hours for the current semester

                // Print subject details in a structured way
                cout << left << setw(15) << (j + 1) << setw(10) << grade << setw(15) << obtainhours << setw(10) << (grade_point * obtainhours) << endl;
            }
        }

        // Calculate GPA for the current semester
        if (semesterCreditHours > 0) {
            float gpa = semester_sum / semesterCreditHours;
            cout << "-----------------------------------------\n";
            cout << "The GPA for semester " << (i + 1) << " is: " << gpa << endl;

            // Add the current semester's weighted GPA to the CGPA total
            cgpa_sum += gpa * semesterCreditHours;
            totalCreditHours += semesterCreditHours; // Add to total credit hours
        } else {
            cout << "No valid credit hours entered. GPA cannot be calculated.\n";
        }
    }

    // Calculate CGPA
    if (totalCreditHours > 0) {
        float cgpa = cgpa_sum / totalCreditHours;
        cout << "-----------------------------------------\n";
        cout << "The CGPA across all semesters is: " << cgpa << endl;
    } else {
        cout << "No valid credit hours entered. CGPA cannot be calculated.\n";
    }

    return 0;
}

// Function to update grade
float update_grade(string grade) {
    if (grade == "A+" || grade == "A") return 4.0;
    else if (grade == "A-") return 3.7;
    else if (grade == "B+") return 3.3;
    else if (grade == "B") return 3.0;
    else if (grade == "B-") return 2.7;
    else if (grade == "C+") return 2.3;
    else if (grade == "C") return 2.0;
    else if (grade == "C-") return 1.7;
    else if (grade == "D+") return 1.3;
    else if (grade == "D") return 1.0;
    else if (grade == "F") return 0.0;
    else return -1;  // Return -1 if the grade is invalid
}
