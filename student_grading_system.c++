#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    string name[n];
    int grade[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name[i];
        cout << "Enter grade of student " << i + 1 << ": ";
        cin >> grade[i];
    }
    int sum = 0;
    int max_grade = grade[0];
    int min_grade = grade[0];
    for (int i = 0; i < n; i++) {
        sum += grade[i];
        if (grade[i] > max_grade) {
            max_grade = grade[i];
        }
        if (grade[i] < min_grade) {
            min_grade = grade[i];
        }
    }
    double average = (double)sum / n;
    cout << "Average grade: " << average << endl;
    cout << "Highest grade: " << max_grade << endl;
    cout << "Lowest grade: " << min_grade << endl;
}
