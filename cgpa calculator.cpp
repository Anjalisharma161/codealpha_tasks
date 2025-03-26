#include <iostream>
#include <vector>
using namespace std;

// Function to calculate CGPA
double calculateCGPA(vector<double> gradePoints, vector<int> creditHours) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < gradePoints.size(); ++i) {
        totalGradePoints += gradePoints[i] * creditHours[i];
        totalCredits += creditHours[i];
    }

    return totalCredits == 0 ? 0.0 : totalGradePoints / totalCredits;
}

int main() {
    int numSubjects;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    vector<double> gradePoints(numSubjects);
    vector<int> creditHours(numSubjects);

    for (int i = 0; i < numSubjects; ++i) {
        cout << "Enter grade point for subject " << i + 1 << ": ";
        cin >> gradePoints[i];
        cout << "Enter credit hours for subject " << i + 1 << ": ";
        cin >> creditHours[i];
    }

    double cgpa = calculateCGPA(gradePoints, creditHours);
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}

