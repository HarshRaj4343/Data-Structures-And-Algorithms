#include <iostream>
#include <string>
using namespace std;

// ============================================================
// 1. Basic I/O — cout, cin, endl vs "\n"
// ============================================================
void basicIO() {
    cout << "Hello Harsh!" << endl;
    cout << "Welcome to C++ programming." << "\n";
    // endl flushes the output buffer -> slower than "\n"
    // "\n" is preferred unless an immediate flush is needed

    int x;
    cin >> x; // cin >> stops at whitespace
    cout << "You entered: " << x << endl;

    string s;
    cin >> s;
    cout << "You entered string: " << s << endl;
}

/*
    Datatype quick reference:
    int           -> 4 bytes  | -2,147,483,648 to 2,147,483,647
    long long     -> 8 bytes  | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
    float         -> 4 bytes  | ~6-7 decimal digits precision
    double        -> 8 bytes  | ~15 decimal digits precision
    char          -> 1 byte   | single character
    bool          -> 1 byte   | true / false
    string        -> sequence of characters
    vector        -> dynamic array, same datatype elements
    array         -> static array, same datatype elements
    pair          -> stores two values, possibly different datatypes
    map           -> key-value pairs (ordered)
    set           -> unique values (ordered)
    unordered_map -> key-value pairs (no particular order)
    unordered_set -> unique values (no particular order)
    <algorithm>   -> sorting, searching, etc.
    getline()     -> reads a full line, including spaces
*/

// ============================================================
// 2. String input with spaces — getline
// ============================================================
void stringInputWithSpaces() {
    // PROBLEM: cin >> stops reading at the first space
    // SOLUTION: use getline(cin, s) to capture the whole line
    string s;
    getline(cin, s);
    cout << "You entered: " << s << endl;
}

// ============================================================
// 3. if-else statements
// ============================================================
void ifElseDemo() {
    int grade;
    cin >> grade;
    if (grade == 10)      cout << "You scored outstanding" << endl;
    else if (grade == 9)  cout << "You scored excellent" << endl;
    else if (grade == 8)  cout << "You scored very good" << endl;
    else if (grade == 7)  cout << "You scored good" << endl;
    else if (grade == 6)  cout << "You scored average" << endl;
    else if (grade == 5)  cout << "You scored below average" << endl;
    else                  cout << "You are a minor" << endl;
}

// ============================================================
// 4. switch statement
// ============================================================
void switchDemo() {
    int n;
    cin >> n;
    switch (n) {
        case 1: cout << "Monday" << endl; break;
        case 2: cout << "Tuesday" << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        case 4: cout << "Thursday" << endl; break;
        case 5: cout << "Friday" << endl; break;
        case 6: cout << "Saturday" << endl; break;
        case 7: cout << "Sunday" << endl; break;
        default: cout << "Invalid input" << endl;
    }
}

// ============================================================
// 5. Arrays — fixed size, same datatype, cannot be resized
// ============================================================
void arrayDemo() {
    int arr[10];
    for (int i = 0; i < 10; i++) cin >> arr[i];
    for (int i = 0; i < 10; i++) cout << arr[i] << endl;
}

// ============================================================
// 6. 2D Arrays
// ============================================================
void array2DDemo() {
    int arr[3][4];
    arr[1][2] = 10;
    cout << arr[1][3] << endl; // not set -> garbage value, just for demo
}

// ============================================================
// 7. Strings — indexing and mutation
// ============================================================
void stringDemo() {
    string s = "Harsh";
    int len = s.length();
    cout << len << endl;

    // Single quotes for a char, double quotes for a string.
    // Common mistake: using "" instead of '' when assigning to an index.
    s[len - 1] = 'k';
    cout << s[len - 1] << endl;
}

// ============================================================
// 8. for loop
// ============================================================
void forLoopDemo() {
    for (int i = 1; i <= 10; i++) {
        cout << "Harsh" << endl;
    }
}

// ============================================================
// 9. while loop
// ============================================================
void whileLoopDemo() {
    int i = 1;
    while (i <= 5) {
        cout << "Harsh" << endl;
        i++;
    }
}

// ============================================================
// 10. while loop — factorial
// ============================================================
void factorialDemo() {
    int n;
    cin >> n;
    int fact = 1;
    while (n > 0) {
        fact = fact * n;
        n--;
    }
    cout << fact << endl;
}

// ============================================================
// 11. do-while loop
// ============================================================
void doWhileDemo() {
    int n;
    do {
        cin >> n;
    } while (n < 1 || n > 10);
    cout << "You entered: " << n << endl;
}

// ============================================================
// 12. Functions — void, no return value
// ============================================================
void printHarsh() {
    cout << "Harsh" << endl;
}

// ============================================================
// 13. Pass by value vs pass by reference
// ============================================================
void modifyByValue(int a) {
    a = a + 10; // modifies only the local copy
}

void modifyByReference(int &a) {
    a = a + 10; // modifies the original variable
    // Note: arrays are always passed by reference in C++
}

void passByValueDemo() {
    int x = 5;
    modifyByValue(x);
    cout << x << endl; // Output: 5 (unchanged)
}

void passByReferenceDemo() {
    int x = 5;
    modifyByReference(x);
    cout << x << endl; // Output: 15 (changed)
}

// ============================================================
// main — uncomment ONE demo at a time to run it
// ============================================================
int main() {
    // basicIO();
    // stringInputWithSpaces();
    // ifElseDemo();
    // switchDemo();
    // arrayDemo();
    // array2DDemo();
    // stringDemo();
    // forLoopDemo();
    // whileLoopDemo();
    // factorialDemo();
    // doWhileDemo();
    printHarsh();
    // passByValueDemo();
    // passByReferenceDemo();

    return 0;
}