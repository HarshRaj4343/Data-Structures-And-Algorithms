#include <iostream>
using namespace std;
// //program always uses std namespace 


int main() {
    cout << "Hello Harsh!" << endl;
    cout << "Welcome to C++ programming." << "\n";
//     //both endl and "\n" are used to insert a new line but endl also flushes the output buffer hence endl is slower than "\n" and is used when we want to ensure that the output is displayed immediately
    int x;
//     // int datatype take 4 bytes of memory and can store values from -2,147,483,648 to 2,147,483,647
//     //long long int datatype takes 8 bytes of memory and can store values from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
//     //float datatype takes 4 bytes of memory and can store decimal values up to 6-7 digits
//     //double datatype takes 8 bytes of memory and can store decimal values up to 15 digits
//     //char datatype takes 1 byte of memory and can store a single character
//     //bool datatype takes 1 byte of memory and can store either true or false
//     //string datatype can store a sequence of characters
//     //vector is a dynamic array that can store elements of same datatype
//     //array is a static array that can store elements of same datatype
//     //pair is a container that can store two values of different datatypes
//     //map is a container that can store key-value pairs
//     //set is a container that can store unique values of same datatype
//     //unordered_map is a container that can store key-value pairs in no particular order
//     //unordered_set is a container that can store unique values of same datatype in no particular order
//     //algorithm is a library that contains functions for sorting, searching, etc.
//     //getline is a function that can be used to take input of a string with spaces
    cin >> x; //input from user
    cout << "You entered: " << x << endl;
    string s;
    cin >> s;
    cout << "You entered string: " << s << endl;
    return 0;
}




// different ways to take input of a string



#include <iostream>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    //PROBLEM: Take input of a string with spaces
    //SOLUTION: Use getline function
    cout << "You entered: " << s << endl;
    return 0;
}


// if else statements



// "\*" is used for multi-line comments
#include <iostream>
using namespace std;
int main() {
    int grade;
    cin>>grade;
    if (grade==10){
        cout<<"You scored outstanding"<<endl;
    }
    else if (grade==9){
        cout<<"You scored excellent"<<endl;
    }
    else if (grade==8){
        cout<<"You scored very good"<<endl;
    }
    else if (grade==7){
        cout<<"You scored good"<<endl;
    }
    else if (grade==6){
        cout<<"You scored average"<<endl;
    }
    else if (grade==5){
        cout<<"You scored below average"<<endl;
    }
    else{
        cout<<"You are a minor"<<endl;
    }
    return 0;
}

//switch command




#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    switch(n){
        case 1:
            cout<<"Monday"<<endl;
            break;
        case 2:
            cout<<"Tuesday"<<endl;
            break;
        case 3:
            cout<<"Wednesday"<<endl;
            break;
        case 4:
            cout<<"Thursday"<<endl;
            break;
        case 5:
            cout<<"Friday"<<endl;
            break;
        case 6:
            cout<<"Saturday"<<endl;
            break;
        case 7:
            cout<<"Sunday"<<endl;
            break;
        default:
            cout<<"Invalid input"<<endl;
    }
    return 0;
}



// arrays and strings in c++

// array cant be resized once declared and all elements are of same datatype

#include <iostream>
using namespace std;

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}




// 2d arrays in c++


#include <iostream>

using namespace std;

int main() {
    int arr[3][4];
    arr[1][2]=10;
    cout<<arr[1][3]<<endl;
    return 0;
}



//strings in c++


#include <iostream>

using namespace std;

int main() {
    string s="Harsh";
    int len=s.length();
    cout<<len<<endl;
    // while assigning a character to a string index, use single quotes for character and double quotes for string
    s[len-1]='k';

    // probable mistake: using "" instead of '' for character
    cout<<s[len-1]<<endl;
    return 0;
}




//for loops in c++


#include <iostream>

using namespace std;

int main() {
    for (int i=1;i<=10;i++){
        cout<<"Harsh"<<endl;
    }
    return 0;
}



//while loops in c++
#include <iostream>

using namespace std;

int main() {
    int i=1;
    while (i<=5){
        cout<<"Harsh"<<endl;
        i++;
    }
    
    return 0;
}

// printing a factorial using while loop in c++
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int fact = 1;
    while (n>0 ){
        fact = fact * n;
        n--;
    }
    cout<<fact<<endl;
    return 0;
}



//do while loops in c++


#include <iostream>
using namespace std;

int main() {
    int n;
    do {
        cin >> n;
    } while (n < 1 || n > 10);
    cout << "You entered: " << n << endl;
    return 0;
}



// functions in c++

// pass by value (COPY) and pass by reference (ORIGINAL)
// arr always go by pass by reference

// void- does not return any value

#include <iostream>
using namespace std;
void printHarsh(){
    cout<<"Harsh"<<endl;
}
int main() {
    printHarsh();
    return 0;
}


// PASS BY VALUE

#include <iostream>
using namespace std;

void modify(int a) {
    a = a + 10;
}

int main() {
    int x = 5;
    modify(x);
    cout << x << endl; 
    return 0;
}

// PASS BY REFERENCE

#include <iostream>
using namespace std;

void modify(int &a) {
    a = a + 10;
}

int main() {
    int x = 5;
    modify(x);
    cout << x << endl; // Output: 15
    return 0;
}