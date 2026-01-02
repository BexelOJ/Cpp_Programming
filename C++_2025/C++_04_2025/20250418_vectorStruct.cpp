#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // for std::greater

using namespace std;

// Define a simple Student struct
class Student {
    public:
    string name;
    int marks;
};

// Helper function to print vector<int>
void printVector(const vector<int>& vec, const string& label) {
    cout << label;
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Helper function to print vector<Student>
void printStudents(const vector<Student>& students, const string& label) {
    cout << label << endl;
    for (const auto& s : students) {
        cout << "Name: " << s.name << ", Marks: " << s.marks << endl;
    }
    cout << endl;
}

int main() {
    // 1 Integer vector sorting
    vector<int> numbers = {4, 2, 10, 7, 5};

    // Ascending order
    sort(numbers.begin(), numbers.end());
    printVector(numbers, "Ascending: ");

    // Descending order using std::greater
    sort(numbers.begin(), numbers.end(), greater<int>());
    printVector(numbers, "Descending: ");

    // 2️ Sorting custom struct
    vector<Student> students = {
        {"Alice", 88},
        {"Bob", 75},
        {"Charlie", 92},
        {"Daisy", 80}
    };

    // Sort students by marks in descending order using a lambda
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.marks > b.marks;
    });

    printStudents(students, "Students sorted by marks (descending):");

    return 0;
}


