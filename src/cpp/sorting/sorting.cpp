// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     // Input array
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     // Selection sort
//     for (int i = 0; i <= n - 2; i++) {
//         int minIndex = i; // assume the current index is minimum
//         for (int j = i; j<=n-1; j++) {
//             if (arr[j] < arr[minIndex]) {
//                 minIndex = j; // found smaller element
//             }
//         }
//         // swap the found minimum with the first element
//         swap(arr[i], arr[minIndex]);
//     }
//     // Output sorted array
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

//time complexity: n+n-1+n-2....+2+1= n(n+1)/2
//hence, tc=O(n^2) (both best and worst and average case)





//BUBBLE SORT


/* BUBBLE SORT (disabled to avoid duplicate main in this single translation unit)
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    // getting the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // bubble sorting initialisation
    for (int i = n - 1; i >= 1; i--) {  
        for (int j = 0; j <= i - 1; j++) { // since we don't want to compare the last value by itself
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);  // swapping the adjacent elements if they are in the wrong order
            } 
            // if you are trying to access an index which is not present, it will show RUNTIME ERROR
        }
    }
    // printing the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
*/

//time complexity: O(n(n+1)/2)=O(n^2) only. (Worst and Average TC)


// RECURSIVE BUBBLE SORT


// #include <iostream>
// #include <vector>
// using namespace std;
// void f(vector<int>& arr, int n){
//     if (n==1) return;
//     for (int j=0; j<=n-2; j++){
//         if (arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
//     }

//     f(arr, n-1);
// }
// int main() {
//     vector<int> arr = {13, 46, 24, 52, 20, 9};
//     int n = arr.size();
//     cout << "Before Using Bubble Sort: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     f(arr, n);
//     cout << "After Using bubble sort: " << "\n";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << "\n";
//     return 0;
// }

// Time Complexity: O(N2), (where N = size of the array), for the worst, and average cases.

// Space Complexity: O(N) auxiliary stack space.


//OPTIMISED VERSION

// #include<iostream>
// using namespace std;

// void bubble_sort(int arr[], int n) {
//     // Base Case: range == 1.
//     if (n == 1) return;

//     int didSwap = 0;
//     for (int j = 0; j <= n - 2; j++) {
//         if (arr[j] > arr[j + 1]) {
//             int temp = arr[j + 1];
//             arr[j + 1] = arr[j];
//             arr[j] = temp;
//             didSwap = 1;
//         }
//     }

//     // if no swapping happens.
//     if (didSwap == 0) return;

//     //Range reduced after recursion:
//     bubble_sort(arr, n - 1);
// }

// int main()
// {
//     int arr[] = {13, 46, 24, 52, 20, 9};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     cout << "Before Using Bubble Sort: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     bubble_sort(arr, n);
//     cout << "After Using bubble sort: " << "\n";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << "\n";
//     return 0;
// }

// Time Complexity: O(N2) for the worst and average cases and O(N) for the best case. Here, N = size of the array.

// Space Complexity: O(N) auxiliary stack space.




//optimised Bubble sort for already sorted array
// TC = O(n) --> BEST CASE SCENARIO


// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     // getting the array
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     int didSwap=0;
//     // bubble sorting initialisation
//     for (int i = n - 1; i >= 1; i--) {  
//         for (int j = 0; j <= i - 1; j++) { // since we don't want to compare the last value by itself
//             if (arr[j] > arr[j + 1]) {
//                 swap(arr[j], arr[j + 1]);  // swapping the adjacent elements if they are in the wrong order
//                 didSwap=1;
//             } 
//             // if you are trying to access an index which is not present, it will show RUNTIME ERROR
//         }
//         if (didSwap==0){
//             break;
//         }
//     }
//     // printing the sorted array
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }



// Insertion Sort

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     // getting the array
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     // insertion sort initialisation
//     for (int i = 0; i < n; i++) {
//         int j = i;
//         // keep swapping while previous element is greater than current
//         while (j > 0 && arr[j - 1] > arr[j]) {
//             swap(arr[j - 1], arr[j]);
//             j--;
//         }
//     }
//     // printing the sorted array
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << "<=>";
//     }
//     return 0;
// }


//time complexity = worst case and average case--> O(n^2)

//optimised -- no change

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     // getting the array
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     // insertion sort initialisation
//     for (int i = 0; i < n; i++) {
//         int j = i;
//         // keep swapping while previous element is greater than current
//         while (j > 0 && arr[j - 1] > arr[j]) {
//             swap(arr[j - 1], arr[j]);
//             j--;
//         }
//     }
//     // printing the sorted array
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << "<=>";
//     }
//     return 0;
// }

// for best case scenario: it will only run for O(n)


// Recursive Insertion sort

#include <iostream>
using namespace std;
void insertion_sort(int arr[], int i, int n) {
    // Base Case: i == n.
    if (i == n) return;
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        swap(arr[j],arr[j-1]);
        j--;
    }

    insertion_sort(arr, i + 1, n);
}

int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, 0, n);
    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

// #include <iostream>                 // I/O (cin, cout)
// #include <vector>                   // vector container
// using namespace std;                // saves typing std::

// void merge(vector<int>& arr, int low, int mid, int high) { // merge two sorted halves
//     vector<int> temp;              // holds merged result
//     int left = low;                // pointer for left half
//     int right = mid + 1;           // pointer for right half

//     while (left <= mid && right <= high) { // while both halves have elements
//         if (arr[left] <= arr[right]) {     // smaller element is on left?
//             temp.push_back(arr[left]);     // take left
//             left++;                        // advance left pointer
//         } else {
//             temp.push_back(arr[right]);    // take right
//             right++;                       // advance right pointer
//         }
//     }

//     while (left <= mid) {         // leftover elements in left half
//         temp.push_back(arr[left]); // copy them
//         left++;
//     }

//     while (right <= high) {       // leftover elements in right half
//         temp.push_back(arr[right]); // copy them
//         right++;
//     }

//     for (int i = low; i <= high; i++) { // copy merged into original array
//         arr[i] = temp[i - low];    // map temp[0..] back to arr[low..high]
//     }
// }

// void mergesort(vector<int>& arr, int low, int high) { // recursive sort
//     if (low >= high) return;     // base case: 0 or 1 element
//     int mid = (low + high) / 2;  // split point

//     mergesort(arr, low, mid);    // sort left half
//     mergesort(arr, mid + 1, high);// sort right half
//     merge(arr, low, mid, high);  // merge sorted halves
// }

// int main() {
//     int n;                       
//     cin >> n;                     // read size

//     vector<int> arr(n);           // create array of size n
//     for (int i = 0; i < n; i++) { // read elements
//         cin >> arr[i];
//     }

//     mergesort(arr, 0, n - 1);     // sort the whole array

//     for (int i = 0; i < n; i++) { // print results
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;                     // done
// }


//time complexity: dividing by 2 continuously --> log(2) [n] for mergesort fxn
// merge fxn -- > worst case : O(n)
// so total complexity: O(nlogn)

//space complexity : O(n) in merge fxn




// Quick Sort

// #include <vector>
// #include <iostream>
// using namespace std;
// int f(vector<int> & arr, int low, int high){
//     int pivot=arr[low];
//     int i=low;
//     int j=high;
//     while (i<j){
//         while(arr[i]<=pivot &&  i < high){
//             i++;
//         }
//         while (arr[j]>pivot && j>= low+1){
//             j--;
//         }
//         if (i<j) swap(arr[i],arr[j]);
//     }
//     swap(arr[low], arr[j]);
//     return j;
// }
// void quicksort(vector<int>& arr, int low, int high){
//     if (low<high){
//         int partition_index=f(arr,low,high);
//         quicksort(arr, low, partition_index-1);
//         quicksort(arr, partition_index+1, high);
//     }
// }
// int main() {
//     int n; 
//     cin>>n;
//     vector <int> arr(n);
//     for (int i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     quicksort(arr, 0 , n-1);

//     for (int i=0; i<n; i++){
//         cout<<arr[i]<<"->";
//     }
//     return 0;
// }


// time complexity: O(nlog n)