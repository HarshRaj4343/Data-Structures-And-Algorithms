#include <iostream>
#include <utility>
#include <vector>    // ✅ include vector header 
#include <list>      // ✅ include list header
#include <deque>     // ✅ include deque header (was missing)
#include <stack>     // ✅ include stack header (was missing)
#include <queue>     // ✅ include queue header (was missing)
#include <set>       // ✅ include set header (was missing)
#include <unordered_set> // ✅ include unordered_set header (was missing)
#include <map>       // ✅ include map header (was missing)
#include <unordered_map> // ✅ include unordered_map header (was missing)
#include <algorithm> // ✅ include algorithm header for sort, max_element, etc. 
using namespace std;

void explainpair() {
    pair<int, int> p1 = {1, 3};
    cout << p1.first << endl;   // prints first element of the pair
    cout << p1.second << endl;  // prints second element of the pair

    // pair inside a pair
    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.first << endl;          // prints outer pair's first element
    cout << p2.second.first << endl;   // prints inner pair's first element
    cout << p2.second.second << endl;  // prints inner pair's second element

    // initializing array of pairs
    pair<int, int> arr[] = {{1, 2}, {1, 4}, {1, 5}};
    cout << arr[1].second << endl; // prints 2nd pair's 2nd element → 4
}

void explainvector() {
    // vectors are dynamic arrays (they can grow or shrink in size)
    vector<int> v1;

    v1.push_back(1);  // adds 1 at the end of vector
    v1.push_back(2);  // adds 2 at the end of vector
    v1.emplace_back(2); // emplace_back is faster than push_back (constructs in-place)

    cout << v1[0] << endl;
    cout << v1[1] << endl;
    cout << v1[2] << endl;

    // vector of pairs
    vector<pair<int, int>> v2;
    v2.push_back({1, 2});
    v2.emplace_back(3, 4); // no need for {} with emplace_back
    cout << v2[0].first << endl;
    cout << v2[1].second << endl;

    // vector of size 5 with all values as 100
    vector<int> v3(5, 100);
    cout << v3[0] << endl;

    // vector of size 5 with default values (0)
    vector<int> v4(5);
    cout << v4[0] << endl;

    // copying one vector to another
    vector<int> v5(9, 0);
    vector<int> v6(v5); // copies v5 to v6
    cout << v6[0] << endl;
}

void accessvector() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    cout << "First element: " << v1.front() << endl; // first element
    cout << "Last element: " << v1.back() << endl;   // last element
    cout << "Element at index 1: " << v1.at(1) << endl; // safer than [] (checks bounds)

    cout << "Size of vector: " << v1.size() << endl; // prints current size of vector

    // using iterators to traverse the vector
    vector<int>::iterator it = v1.begin(); // begin points to first element
    it++;
    cout << *it << endl; // prints element at position 1 (2)
    it = it + 1;
    cout << *it << endl; // prints element at position 2 (3)

    // end iterator
    cout << "Using end iterator: " << endl;
    vector<int>::iterator it2 = v1.end(); // end points to memory after last element
    it2--;
    cout << *it2 << endl; // prints last element

    // reverse iterators
    cout << "Using rbegin iterator: " << endl;
    vector<int>::reverse_iterator it3 = v1.rbegin(); // points to last element
    cout << *it3 << endl;

    cout << "Using rend iterator: " << endl;
    vector<int>::reverse_iterator it4 = v1.rend(); // points to element before first
    it4--;
    cout << *it4 << endl; // prints first element

    cout << v1.back() << endl; // prints last element

    // traversing with iterator
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // using auto keyword for cleaner code
    for (auto it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // using range-based for loop
    for (auto it : v1) {
        cout << it << " ";
    }
    cout << endl;

    // deletion of vector elements
    v1.erase(v1.begin() + 1); // erases element at index 1
    cout << "After erasing element at index 1: ";
    for (auto it : v1) {
        cout << it << " ";
    }
    cout << endl;

    v1.erase(v1.begin(), v1.begin() + 1); // erases elements from index 0 to 1 (1 not included)
    cout << "After erasing elements from index 0 to 1: ";
    for (auto it : v1) {
        cout << it << " ";
    }
    cout << endl;

    v1.clear(); // clears the entire vector
    cout << "Size after clearing the vector: " << v1.size() << endl;

    // insert function
    vector<int> v2(2, 100);
    v2.insert(v2.begin(), 300);         // inserts 300 at the beginning
    v2.insert(v2.begin() + 1, 2, 10);   // inserts two 10s at index 1
    // {start, number of times, value}

    cout << "Vector after insertions: ";
    for (auto it : v2) {
        cout << it << " ";
    }
    cout << endl;

    // copy one vector into another
    vector<int> copy(3, 50);
    v2.insert(v2.end(), copy.begin(), copy.end()); // inserts all elements of 'copy' at the end of v2

    cout << "Vector after copying another vector at the end: ";
    for (auto it : v2) {
        cout << it << " ";
    }
    cout << endl;

    cout << "Size of v2: " << v2.size() << endl;

    v2.pop_back(); // removes last element

    // swap function
    vector<int> v3(2, 200);
    cout << "Before swapping:" << endl;
    cout << "v2: ";
    for (auto it : v2) {
        cout << it << " ";
    }
    cout << endl;
    cout << "v3: ";
    for (auto it : v3) {
        cout << it << " ";
    }
    cout << endl;

    v2.swap(v3); // swaps content of v2 and v3

    cout << "After swapping:" << endl;
    cout << "v2: ";
    for (auto it : v2) {
        cout << it << " ";
    }
    cout << endl;
    cout << "v3: ";
    for (auto it : v3) {
        cout << it << " ";
    }
    cout << endl;

    // int mn = *min_element(v.begin(), v.end());
    // int mx = *max_element(v.begin(), v.end());
}

void explainlist() {
    list<int> l1;

    l1.push_back(1);  // adds 1 at the end
    l1.push_front(2); // adds 2 at the beginning

    cout << "List elements: ";
    for (auto it : l1) {
        cout << it << " ";  
    }
    cout << endl;
    // doubly-linked list allows O(1) time complexity for insertions and deletions at both ends
    // singly-linked list allows O(1) for insertions/deletions at front but O(n) at back. example is vectors.
    l1.pop_back();  // removes last element
    l1.pop_front(); // removes first element
    l1.push_front(5); 
    //insert function in vectors is O(n) but in lists it is O(1)
    l1.emplace_front(7); // faster than push_front
    l1.emplace_back(9);  // faster than push_back
    cout << "List size after pops: " << l1.size() << endl;
    //all other functions like insert, erase, clear, swap are also available for lists similar to vectors
}

void explainDeque() {
    // Deque (Double Ended Queue) allows insertion and deletion from both ends in O(1) time
    deque<int> d1;
    d1.push_back(1);   // adds 1 at the end
    d1.push_front(2);  // adds 2 at the beginning

    cout << "Deque elements: ";
    for (auto it : d1) {
        cout << it << " ";
    }
    cout << endl;

    d1.pop_back();    // removes last element
    d1.pop_front();   // removes first element

    d1.emplace_front(5); // faster than push_front
    d1.emplace_back(9);  // faster than push_back

    cout << "Deque size after pops: " << d1.size() << endl;
    // Other functions like insert, erase, clear, swap are also available for deques similar to vectors and lists
    //difference between list and deque is that deque provides random access like vectors but lists do not.
    //random acceess means accessing any element in O(1) time using index.
}

void explainStack() {
    // Stack is a LIFO (Last In First Out) data structure
    stack<int> s1;
    s1.push(1); // adds 1 to the top of the stack
    s1.push(2); // adds 2 to the top of the stack
    s1.emplace(3); // faster than push

    cout << "Top element: " << s1.top() << endl; // prints top element (3, not 2 - it's the last one added)

    s1.pop(); // removes top element (3)

    cout << "Top element after pop: " << s1.top() << endl; // prints new top element (2)

    cout << "Stack size: " << s1.size() << endl; // prints size of stack (2)

    cout << "Is stack empty? " << (s1.empty() ? "Yes" : "No") << endl; // checks if stack is empty
    // syntax ? "value_if_true" : "value_if_false" is called ternary operator in C++
    // Other functions like swap are also available for stacks similar to other STL containers
    // all operations in stack are O(1) time complexity
}

void explainQueue() {
    // Queue is a FIFO (First In First Out) data structure
    queue<int> q1;
    q1.push(1); // adds 1 to the back of the queue
    q1.push(2); // adds 2 to the back of the queue
    q1.emplace(3); // faster than push

    cout << "Front element: " << q1.front() << endl; // prints front element (1)
    cout << "Back element: " << q1.back() << endl;   // prints back element (3, not 2)

    q1.pop(); // removes front element (1)

    cout << "Front element after pop: " << q1.front() << endl; // prints new front element (2)

    cout << "Queue size: " << q1.size() << endl; // prints size of queue (2)

    cout << "Is queue empty? " << (q1.empty() ? "Yes" : "No") << endl; // checks if queue is empty
    // Other functions like swap are also available for queues similar to other STL containers
    // all operations in queue are O(1) time complexity
}

void explainPriorityQueue() {
    // Priority Queue is a special type of queue where elements are ordered by priority
    priority_queue<int> pq1; // max-heap by default
    pq1.push(5);
    pq1.push(1);
    pq1.push(10);

    cout << "Top element (max): " << pq1.top() << endl; // prints top element (10)

    pq1.pop(); // removes top element (10)

    cout << "Top element after pop: " << pq1.top() << endl; // prints new top element (5)

    cout << "Priority Queue size: " << pq1.size() << endl; // prints size of priority queue (2)

    cout << "Is priority queue empty? " << (pq1.empty() ? "Yes" : "No") << endl; // checks if empty

    // Min-heap implementation
    priority_queue<int, vector<int>, greater<int>> pq2;  // default is less<int> for max-heap
    pq2.push(5);
    pq2.push(1);
    pq2.push(10);

    cout << "Top element (min): " << pq2.top() << endl; // prints top element (1)
    // time complexity for all operations in priority queue is O(log n)
    // time complexity for top() is O(1)
    // time complexity for push() and pop() is O(log n)
}

void explainSet() {
    // Set is a collection of unique elements stored in sorted order (in increasing order by default but syntax for decreasing order is given by set<int>, greater<int>> s;)
    set<int> s1;
    s1.insert(5);
    s1.insert(1);
    s1.insert(10);
    s1.insert(5); // duplicate, will not be added

    cout << "Set elements: ";
    for (auto it : s1) {
        cout << it << " ";
    }
    cout << endl;

    cout << "Set size: " << s1.size() << endl; // prints size of set (3)

    s1.erase(1); // removes element 1

    cout << "Set elements after erasing 1: ";
    for (auto it : s1) {
        cout << it << " ";
    }
    cout << endl;

    cout << "Is 10 in set? " << (s1.count(10) ? "Yes" : "No") << endl; // checks if 10 is in set

    auto it = s1.find(5); // returns iterator to element 5
    if (it != s1.end()) {
        cout << "Found element: " << *it << endl;
        // if it could not find the element, it returns s1.end()
    } else {
        cout << "Element not found" << endl;
    }

    int cnt = s1.count(10); // returns 1 if 10 is present, else 0
    cout << "Count of 10: " << cnt << endl;

    // CORRECTED: Fixed the erase logic - it1 will be s1.end() since 15 doesn't exist
    // So this erase won't work as intended. Better example below:
    s1.insert(15);
    s1.insert(20);
    auto it1 = s1.find(10); // finds element 10
    auto it2 = s1.find(20); // finds element 20
    s1.erase(it1, it2); // erases elements from iterator it1 to it2 (not including it2)
    cout << "Set elements after erasing from it1 to it2: ";
    for(auto it : s1) {
        cout << it << " ";
    }
    cout << endl;
    // Other functions like find, clear, swap are also available for sets
    // time complexity for insert, erase, and find is O(log n)
    // time complexity for count is O(log n)
}
// check for upper and lower bound functions in set - left to do for now
void explainMultiset() {
    // Multiset is similar to set but allows duplicate elements
    multiset<int> ms1;
    ms1.insert(5);
    ms1.insert(1);
    ms1.insert(10);
    ms1.insert(5); // duplicate, will be added

    cout << "Multiset elements: ";
    for (auto it : ms1) {
        cout << it << " ";
    }
    cout << endl;

    cout << "Multiset size: " << ms1.size() << endl; // prints size of multiset (4)

    ms1.erase(5); // removes all occurrences of element 5

    cout << "Multiset elements after erasing 5: ";
    for (auto it : ms1) {
        cout << it << " ";
    }
    cout << endl;

    cout << "Count of 5 in multiset: " << ms1.count(5) << endl; // counts occurrences of 5

    // Other functions like find, clear, swap are also available for multisets
    // time complexity for insert, erase, and find is O(log n)
    // time complexity for count is O(log n)
}

void explainUnorderedset(){
    // Unordered Set is a collection of unique elements stored in no particular order ..note that lower and upper bound functions are not available for unordered sets as they are not sorted
    unordered_set<int> us1;
    us1.insert(5);
    us1.insert(1);
    us1.insert(10);
    us1.insert(5); // duplicate, will not be added

    cout << "Unordered Set elements: ";
    for (auto it : us1) {
        cout << it << " ";
    }
    cout << endl;

    cout << "Unordered Set size: " << us1.size() << endl; // prints size of unordered set (3)

    us1.erase(1); // removes element 1

    cout << "Unordered Set elements after erasing 1: ";
    for (auto it : us1) {
        cout << it << " ";
    }
    cout << endl;

    cout << "Is 10 in unordered set? " << (us1.count(10) ? "Yes" : "No") << endl; // checks if 10 is in unordered set

    auto it = us1.find(5); // returns iterator to element 5
    if (it != us1.end()) {
        cout << "Found element: " << *it << endl;
    } else {
        cout << "Element not found" << endl;
    }
    // lower bound and upper bound functions are not available for unordered sets as they are not sorted
    // Other functions like find, clear, swap are also available for unordered sets
    // average time complexity for insert, erase, and find is O(1)
    // time complexity for count is O(1)
    // worst case time complexity for insert, erase, and find is O(n)
    // it does not store elements in sorted order or any particular order, hence it has better average time complexity than set except for collision cases.
}

void explainMap() {
    // Map is a collection of key-value pairs with unique keys stored in sorted order
    map<int, string> m1;
    m1[1] = "One";
    m1[2] = "Two";
    m1[3] = "Three";

    cout << "Map elements: " << endl;
    for (auto it : m1) {
        cout << it.first << " -> " << it.second << endl;
    }

    cout << "Size of map: " << m1.size() << endl; // prints size of map (3)

    m1.erase(2); // removes key-value pair with key 2

    cout << "Map elements after erasing key 2: " << endl;
    for (auto it : m1) {
        cout << it.first << " -> " << it.second << endl;
    }

    cout << "Is key 3 in map? " << (m1.count(3) ? "Yes" : "No") << endl; // checks if key 3 is in map

    auto it = m1.find(1); // returns iterator to key-value pair with key 1
    if (it != m1.end()) {
        cout << "Found key 1 with value: " << it->second << endl;
    } else {
        cout << "Key not found" << endl;
    }
    // Other functions like clear, swap are also available for maps
    // time complexity for insert, erase, and find is O(log n)
    // time complexity for count is O(log n)
    // map stores unique keys in sorted order
    // lower and upper bound functions are available for maps
}

void explainMultimap() {
    // Multimap is similar to map but allows duplicate keys
    multimap<int, string> mm1;
    mm1.insert({1, "One"});
    mm1.insert({2, "Two"});
    mm1.insert({1, "Uno"}); // duplicate key, will be added

    cout << "Multimap elements: " << endl;
    for (auto it : mm1) {
        cout << it.first << " -> " << it.second << endl;
    }

    cout << "Size of multimap: " << mm1.size() << endl; // prints size of multimap (3)

    mm1.erase(1); // removes all key-value pairs with key 1

    cout << "Multimap elements after erasing key 1: " << endl;
    for (auto it : mm1) {
        cout << it.first << " -> " << it.second << endl;
    }

    cout << "Count of key 2 in multimap: " << mm1.count(2) << endl; // counts occurrences of key 2

    auto it = mm1.find(2); // returns iterator to key-value pair with key 2
    if (it != mm1.end()) {
        cout << "Found key 2 with value: " << it->second << endl;
    } else {
        cout << "Key not found" << endl;
    }
    // Other functions like clear, swap are also available for multimaps
    // time complexity for insert, erase, and find is O(log n)
    // time complexity for count is O(log n)
    // lower and upper bound functions are available for multimaps
}

void explainUnorderedMap(){
    // Unordered Map is a collection of key-value pairs with unique keys stored in no particular order
    unordered_map<int, string> um1;
    um1[1] = "One";
    um1[2] = "Two";
    um1[3] = "Three";
    cout << "Unordered Map elements: " << endl;
    for (auto it : um1) {
        cout << it.first << " -> " << it.second << endl;
    }
    cout << "Size of unordered map: " << um1.size() << endl; // prints size of unordered map (3)
    um1.erase(2); // removes key-value pair with key 2
    cout << "Unordered Map elements after erasing key 2: " << endl;
    for (auto it : um1) {
        cout << it.first << " -> " << it.second << endl;
    }
    cout << "Is key 3 in unordered map? " << (um1.count(3) ? "Yes" : "No") << endl; // checks if key 3 is in unordered map
    auto it = um1.find(1); // returns iterator to key-value pair with key 1
    if (it != um1.end()) {
        cout << "Found key 1 with value: " << it->second << endl;
    } else {
        cout << "Key not found" << endl;
    }
    // Other functions like clear, swap are also available for unordered maps
    // average time complexity for insert, erase, and find is O(1)
    // time complexity for count is O(1)
    // worst case time complexity for insert, erase, and find is O(n)
}

// Comparator function for sorting pairs
// This function defines custom sorting behavior
bool comp(pair<int,int> p1, pair<int,int> p2){
    if (p1.second < p2.second) return true;  // if p1's second < p2's second, p1 comes first
    if (p1.second > p2.second) return false; // if p1's second > p2's second, p2 comes first
    // CORRECTED: Changed = to == for comparison
    if (p1.second == p2.second){  // if both seconds are equal
        if (p1.first > p2.first) return true; // sort by first element in descending order
        return false;
    }
    return false; // Added return statement for completeness
}

void explainExtra(){
    // CORRECTED: Added proper declarations and sample data
    int a[] = {5, 2, 8, 1, 9};
    int n = 5;
    
    sort(a, a+n); // sorts entire array a in ascending order
    
    vector<int> v = {5, 2, 8, 1, 9};
    sort(v.begin(), v.end()); // sorts entire vector v in ascending order
    
    sort(a+2, a+4); // sorts elements from index 2 to 3 (4 is not included)
    sort(a, a+n, greater<int>()); // sorts array in descending order using greater comparator
    
    pair<int,int> arr[] = {{1,2}, {2,1}, {4,1}};
    //sort it according to second element
    // if second element is same, then sort
    // it according to first element but in descending

    sort(arr, arr+3, comp); // uses custom comparator function
    // Result: {4,1},{2,1},{1,2}
    
    cout << "Sorted pairs: ";
    for(int i = 0; i < 3; i++){
        cout << "{" << arr[i].first << "," << arr[i].second << "} ";
    }
    cout << endl;

    int num = 7;
    // CORRECTED: Fixed function name from __bulletin_popcount to __builtin_popcount
    int cnt = __builtin_popcount(num); // counts number of set bits (1s) in binary representation
    cout << "Number of set bits in " << num << ": " << cnt << endl;
    
    long long num2 = 1633279735999LL; // CORRECTED: Added LL suffix for long long literal
    // CORRECTED: Fixed function name from __bulletin_popcountll to __builtin_popcountll
    int cnt2 = __builtin_popcountll(num2); // counts set bits in long long
    cout << "Number of set bits in " << num2 << ": " << cnt2 << endl;

    string s = "123";
    sort(s.begin(), s.end()); // sorts string characters

    // Generates all permutations of string s in lexicographically sorted order
    do{
        cout << s << endl;
    }
    while(next_permutation(s.begin(), s.end())); // CORRECTED: Added semicolon

    int maxi = *max_element(a, a+n); // finds maximum element in array
    cout << "Maximum element: " << maxi << endl;
}

int main() {
    explainpair();   // demonstrates use of pairs
    explainvector(); // demonstrates vector basics
    accessvector();  // demonstrates advanced vector operations
    explainlist();  // demonstrates list operations
    explainDeque(); // demonstrates deque operations
    explainStack(); // demonstrates stack operations
    explainQueue(); // demonstrates queue operations
    explainPriorityQueue(); // demonstrates priority queue operations
    explainSet();   // demonstrates set operations
    explainMultiset(); // demonstrates multiset operations
    explainUnorderedset(); // demonstrates unordered set operations
    explainMap();   // demonstrates map operations
    explainMultimap(); // demonstrates multimap operations
    explainUnorderedMap(); // demonstrates unordered map operations
    explainExtra(); // demonstrates additional STL utilities
    return 0;
}