// Read the marks obtained by students of second year in an online examination
// of particular subject. Find out maximum and minimum marks obtained in that
// subject. Use heap data structure. Analyze the algorithm

#include <iostream>
using namespace std;

void min_heapify(int *a, int i, int n) {
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n) {
        if (j < n && a[j + 1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        else if (temp >= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
}

void max_heapify(int *a, int i, int n) {
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n) {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        if (temp > a[j])
            break;
        else if (temp <= a[j]) {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
}

void build_minheap(int *a, int n) {
    int i;
    for (i = n / 2; i >= 1; i--) {
        min_heapify(a, i, n);
    }
}

void build_maxheap(int *a, int n) {
    int i;
    for (i = n / 2; i >= 1; i--) {
        max_heapify(a, i, n);
    }
}

int main() {
    int n, i, ch;
    char choice;
    cout << "Enter the number of marks: ";
    cin >> n;
    int a[20];
    for (i = 1; i <= n; i++) {
        cout << "Enter marks " << i << ": ";
        cin >> a[i];
    }
    do {
        cout << "\n***Enter the choice***\n1. Find Minimum Mark\n2. Find Maximum Mark\n";
        cin >> ch;
        switch (ch) {
            case 1:
                build_minheap(a, n);
                cout << "Minimum Mark: " << a[1] << endl;
                break;
            case 2:
                build_maxheap(a, n);
                cout << "Maximum Mark: " << a[1] << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
        cout << "Do you want to continue (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
