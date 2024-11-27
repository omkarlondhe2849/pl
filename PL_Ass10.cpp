#include <iostream>
#include <string>
using namespace std;

class student {
public:
    int roll_no;
    float SGPA;
    string name;
    string department;
};

void swap(student& a, student& b) {
    student temp = a;
    a = b;
    b = temp;
}

void bubble_sort(student s[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (s[j].roll_no > s[j + 1].roll_no) {
                swap(s[j], s[j + 1]);
            }
        }
    }
}

void insertion_sort(student s[], int size) {
    for (int step = 1; step < size; step++) {
        student key = s[step];
        int j = step - 1;

        while (j >= 0 && key.name < s[j].name) {
            s[j + 1] = s[j];
            --j;
        }
        s[j + 1] = key;
    }
}

int partition(student s[], int low, int high) {
    student pivot = s[low];
    int st = low;
    int end = high;

    while (st < end) {
        while (s[st].SGPA >= pivot.SGPA && st < end) {
            st++;
        }
        while (s[end].SGPA < pivot.SGPA) {
            end--;
        }
        if (st < end) {
            swap(s[st], s[end]);
        }
    }
    swap(s[low], s[end]);
    return end;
}

void quickSort(student s[], int low, int high) {
    if (low < high) {
        int idx = partition(s, low, high);
        quickSort(s, low, idx - 1);
        quickSort(s, idx + 1, high);
    }
}

int linear_search(student s[], int n, float key) {
    for (int i = 0; i < n; i++) {
        if (s[i].SGPA == key) {
            return i;
        }
    }
    return -1;
}

int binary_search(student s[], int n, string key) {
    int mid, low, high;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (s[mid].name == key) {
            return mid;
        } else if (s[mid].name > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int fibonacci_search(student s[], string sdept, int n) {
    int offset = 0;
    int fb_prev2 = 0;
    int fb_prev1 = 1;
    int fb_s = fb_prev2 + fb_prev1;

    while (fb_s < n) {
        fb_prev2 = fb_prev1;
        fb_prev1 = fb_s;
        fb_s = fb_prev2 + fb_prev1;
    }

    int i = 0;
    while (fb_s > 1) {
        i = min(offset + fb_prev2, n - 1);
        if (s[i].department < sdept) {
            fb_s = fb_prev1;
            fb_prev1 = fb_prev2;
            fb_prev2 = fb_s - fb_prev1;
            offset = i;
        } else if (s[i].department > sdept) {
            fb_s = fb_prev2;
            fb_prev1 = fb_prev1 - fb_prev2;
            fb_prev2 = fb_s - fb_prev1;
        } else
            return i;
    }
    if (fb_prev1 && s[offset + 1].department == sdept)
        return offset + 1;
    return -1;
}

void display_students(student s[], int size) {
    cout << "\nStudent Information:\n";
    cout << "Roll No"
         << "\t"
         << "Name "
         << "\t"
         << "SGPA "
         << "\t"
         << "Department " << endl;
    for (int i = 0; i < size; i++) {
        cout << s[i].roll_no << "\t" << s[i].name << "\t" << s[i].SGPA << "\t" << s[i].department << endl;
    }
}

int main() {
    const int size = 15;
    student students[size] = {
        {1, 8.7, "Jai", "Computer Science"},
        {2, 9.1, "Mrugmai", "Computer Science"},
        {3, 7.8, "Vaibhav", "Mechanical"},
        {4, 8.4, "Ritesh", "Civil"},
        {5, 8.0, "Ojas", "Electrical"},
        {6, 9.5, "Shlok", "Computer Science"},
        {7, 8.2, "Vaibhav", "Mechanical"},
        {8, 9.0, "Bapurao", "Civil"},
        {9, 7.5, "Shyam", "Electrical"},
        {10, 8.9, "Krishna", "Computer Science"},
        {11, 8.1, "Anooj", "Mechanical"},
        {12, 9.2, "Pooja", "Civil"},
        {13, 7.6, "Sakshi", "Electrical"},
        {14, 8.5, "ABCD", "Mechanical"},
        {15, 9.3, "Aditya", "Computer Science"}
    };

    int choice;
    int resultIndex;
    float searchSGPA;
    string searchName;
    string searchDept;

    do {
        cout << "\nMenu:\n";
        cout << "1. Display student information\n";
        cout << "2. Sort and display student information (Bubble Sort)\n";
        cout << "3. Sort and display student information (Insertion Sort)\n";
        cout << "4. Sort and display student information (Quick Sort)\n";
        cout << "5. Linear Search\n";
        cout << "6. Binary Search\n";
        cout << "7. Fibonacci Search\n";
        cout << "8. Exit the program\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            display_students(students, size);
            break;

        case 2:
            bubble_sort(students, size);
            display_students(students, size);
            break;

        case 3:
            insertion_sort(students, size);
            display_students(students, size);
            break;

        case 4:
            quickSort(students, 0, size - 1);
            display_students(students, size);
            break;

        case 5:
            cout << "Enter SGPA to search: ";
            cin >> searchSGPA;
            resultIndex = linear_search(students, size, searchSGPA);
            if (resultIndex != -1) {
                cout << "SGPA " << searchSGPA << " found at index " << resultIndex << endl;
            } else {
                cout << "SGPA " << searchSGPA << " not found\n";
            }
            break;

        case 6:
            cout << "Enter Name to search: ";
            cin >> searchName;
            resultIndex = binary_search(students, size, searchName);
            if (resultIndex != 1) {
                cout << "Name " << searchName << " found at index " << resultIndex << endl;
            } else {
                cout << "Name " << searchName << " not found\n";
            }
            break;

        case 7:
            cout << "Enter Department to search: ";
            cin >> searchDept;
            resultIndex = fibonacci_search(students, searchDept, size);
            if (resultIndex != -1) {
                cout << "Department " << searchDept << " found at index " << resultIndex << endl;
            } else {
                cout << "Department " << searchDept << " not found\n";
            }
            break;

        case 8:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }

    } while (choice != 8);

    return 0;
}
