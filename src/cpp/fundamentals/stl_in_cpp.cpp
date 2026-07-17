#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ============================================================
//  1. PAIR
// ============================================================
void explainPair() {
    pair<int, int> p1 = {1, 3};
    cout << p1.first << endl;   // prints first element of the pair
    cout << p1.second << endl;  // prints second element of the pair

    // pair inside a pair (nested pair)
    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.first << endl;          // outer pair's first element
    cout << p2.second.first << endl;   // inner pair's first element
    cout << p2.second.second << endl;  // inner pair's second element

    // array of pairs
    pair<int, int> arr[] = {{1, 2}, {1, 4}, {1, 5}};
    cout << arr[1].second << endl; // 2nd pair's 2nd element -> 4
}

// ============================================================
//  2. SEQUENCE CONTAINERS
// ============================================================

// ---------- 2a. VECTOR (dynamic array) ----------
void explainVector() {
    // vectors are dynamic arrays: they grow/shrink in size automatically
    vector<int> v1;

    v1.push_back(1);    // adds 1 at the end
    v1.push_back(2);    // adds 2 at the end
    v1.emplace_back(2); 
    // emplace_back can be faster because it constructs the object directly inside the container's memory, whereas push_back typically constructs a temporary object first, then copies or moves it into the container.

    cout << v1[0] << endl;
    cout << v1[1] << endl;
    cout << v1[2] << endl;

    // vector of pairs
    vector<pair<int, int>> v2;
    v2.push_back({1, 2});
    v2.emplace_back(3, 4); // no need for {} with emplace_back
    cout << v2[0].first << endl;
    cout << v2[1].second << endl;

    // vector of size 5, every value initialized to 100
    vector<int> v3(5, 100);
    cout << v3[0] << endl;

    // vector of size 5, default-initialized values (0 for int)
    vector<int> v4(5);
    cout << v4[0] << endl;

    // copying one vector into another
    vector<int> v5(9, 0);
    vector<int> v6(v5); // copy-constructs v6 from v5
    cout << v6[0] << endl;
}

void accessVector() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    // ---- accessors ----
    cout << "First element: " << v1.front() << endl;
    cout << "Last element: " << v1.back() << endl;
    cout << "Element at index 1: " << v1.at(1) << endl;
    // bounds-checked, safer than []
    cout << "Size of vector: " << v1.size() << endl;

    // ---- forward iterators ----
    vector<int>::iterator it = v1.begin(); // points to first element
    it++;
    cout << *it << endl; // element at position 1 (2)
    it = it + 1;
    cout << *it << endl; // element at position 2 (3)

    // ---- end iterator ----
    cout << "Using end iterator: " << endl;
    vector<int>::iterator it2 = v1.end(); // points to memory AFTER the last element
    it2--;
    cout << *it2 << endl; // last element

    // ---- reverse iterators ----
    cout << "Using rbegin iterator: " << endl;
    vector<int>::reverse_iterator it3 = v1.rbegin(); // points to last element
    cout << *it3 << endl;
// A reverse iterator moves in the opposite direction.
    cout << "Using rend iterator: " << endl;
    vector<int>::reverse_iterator it4 = v1.rend(); // points to "before first" element
    it4--;
    cout << *it4 << endl; // first element

    cout << v1.back() << endl;

    // ---- traversal styles ----
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = v1.begin(); it != v1.end(); it++) { // auto = cleaner iterator syntax
        cout << *it << " ";
    }
    cout << endl;

    for (auto it : v1) { // range-based for loop
        cout << it << " ";
    }
    cout << endl;

    // ---- deletion ----
    v1.erase(v1.begin() + 1); // erases element at index 1
    cout << "After erasing element at index 1: ";
    for (auto it : v1) cout << it << " ";
    cout << endl;

    v1.erase(v1.begin(), v1.begin() + 1); // erases range [0, 1) -> index 1 not included
    cout << "After erasing elements from index 0 to 1: ";
    for (auto it : v1) cout << it << " ";
    cout << endl;

    v1.clear(); // removes all elements
    cout << "Size after clearing the vector: " << v1.size() << endl;

    // ---- insertion ----
    vector<int> v2(2, 100);
    v2.insert(v2.begin(), 300);        // inserts 300 at the beginning
    v2.insert(v2.begin() + 1, 2, 10);  // inserts two 10s starting at index 1
                                        // syntax: {position, count, value}

    cout << "Vector after insertions: ";
    for (auto it : v2) cout << it << " ";
    cout << endl;

    // ---- inserting one vector's contents into another ----
    vector<int> copy(3, 50);
    v2.insert(v2.end(), copy.begin(), copy.end()); // appends all of 'copy' to the end of v2

    cout << "Vector after copying another vector at the end: ";
    for (auto it : v2) cout << it << " ";
    cout << endl;

    cout << "Size of v2: " << v2.size() << endl;

    v2.pop_back(); // removes last element

    // ---- swap ----
    vector<int> v3(2, 200);
    cout << "Before swapping:" << endl;
    cout << "v2: "; for (auto it : v2) cout << it << " "; cout << endl;
    cout << "v3: "; for (auto it : v3) cout << it << " "; cout << endl;

    v2.swap(v3); // swaps contents of v2 and v3

    cout << "After swapping:" << endl;
    cout << "v2: "; for (auto it : v2) cout << it << " "; cout << endl;
    cout << "v3: "; for (auto it : v3) cout << it << " "; cout << endl;

    // int mn = *min_element(v.begin(), v.end());
    // int mx = *max_element(v.begin(), v.end());
}

// ---------- 2b. LIST (doubly-linked list) ----------
void explainList() {
    list<int> l1;

    l1.push_back(1);  // adds 1 at the end
    l1.push_front(2); // adds 2 at the beginning

    cout << "List elements: ";
    for (auto it : l1) cout << it << " ";
    cout << endl;

    // doubly-linked list -> O(1) insert/delete at BOTH ends
    // (a vector is like a singly-linked array: O(1) at back, O(n) at front)
    l1.pop_back();   // removes last element
    l1.pop_front();  // removes first element
    l1.push_front(5);

    // insert() on a vector is O(n); insert() on a list is O(1)
    l1.emplace_front(7); // faster than push_front
    l1.emplace_back(9);  // faster than push_back
    cout << "List size after pops: " << l1.size() << endl;
    // insert, erase, clear, swap all work the same way as on vectors
}

// ---------- 2c. DEQUE (double-ended queue) ----------
void explainDeque() {
    // deque allows O(1) insertion/deletion at BOTH ends, like a list,
    // but ALSO supports random access by index, like a vector
    deque<int> d1;
    d1.push_back(1);   // adds 1 at the end
    d1.push_front(2);  // adds 2 at the beginning

    cout << "Deque elements: ";
    for (auto it : d1) cout << it << " ";
    cout << endl;

    d1.pop_back();
    d1.pop_front();

    d1.emplace_front(5);
    d1.emplace_back(9);

    cout << "Deque size after pops: " << d1.size() << endl;
    // insert, erase, clear, swap are all available, same as vector/list
    // key difference vs list: deque supports O(1) random access (d1[i]); list does not
}

// ============================================================
//  3. CONTAINER ADAPTERS
// ============================================================

// ---------- 3a. STACK (LIFO) ----------
void explainStack() {
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.emplace(3); // faster than push

    cout << "Top element: " << s1.top() << endl; // 3 (last one pushed)

    s1.pop(); // removes top element (3)
    cout << "Top element after pop: " << s1.top() << endl; // 2

    cout << "Stack size: " << s1.size() << endl;
    cout << "Is stack empty? " << (s1.empty() ? "Yes" : "No") << endl;
    // "? :" is the ternary operator: condition ? value_if_true : value_if_false
    // all stack operations are O(1)
}

// ---------- 3b. QUEUE (FIFO) ----------
void explainQueue() {
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.emplace(3); // faster than push

    cout << "Front element: " << q1.front() << endl; // 1
    cout << "Back element: " << q1.back() << endl;   // 3

    q1.pop(); // removes front element (1)
    cout << "Front element after pop: " << q1.front() << endl; // 2

    cout << "Queue size: " << q1.size() << endl;
    cout << "Is queue empty? " << (q1.empty() ? "Yes" : "No") << endl;
    // all queue operations are O(1)
}

// ---------- 3c. PRIORITY QUEUE (heap) ----------
void explainPriorityQueue() {
    priority_queue<int> pq1; // max-heap by default
    pq1.push(5);
    pq1.push(1);
    pq1.push(10);

    cout << "Top element (max): " << pq1.top() << endl; // 10
    pq1.pop();
    cout << "Top element after pop: " << pq1.top() << endl; // 5

    cout << "Priority Queue size: " << pq1.size() << endl;
    cout << "Is priority queue empty? " << (pq1.empty() ? "Yes" : "No") << endl;

    // min-heap: pass greater<int> as the comparator
    priority_queue<int, vector<int>, greater<int>> pq2; // default comparator is less<int>
    pq2.push(5);
    pq2.push(1);
    pq2.push(10);

    cout << "Top element (min): " << pq2.top() << endl; // 1
    // top()            -> O(1)
    // push() / pop()   -> O(log n)
}

// ============================================================
//  4. ORDERED ASSOCIATIVE CONTAINERS (sorted, tree-based)
// ============================================================

// ---------- 4a. SET (unique, sorted) ----------
void explainSet() {
    // set = unique elements, stored sorted ascending by default
    // (descending order: set<int, greater<int>> s;)
    set<int> s1;
    s1.insert(5);
    s1.insert(1);
    s1.insert(10);
    s1.insert(5); // duplicate -> ignored

    cout << "Set elements: ";
    for (auto it : s1) cout << it << " ";
    cout << endl;

    cout << "Set size: " << s1.size() << endl; // 3

    s1.erase(1); // removes element 1
    cout << "Set elements after erasing 1: ";
    for (auto it : s1) cout << it << " ";
    cout << endl;

    cout << "Is 10 in set? " << (s1.count(10) ? "Yes" : "No") << endl;

    auto it = s1.find(5); // returns iterator to 5, or s1.end() if not found
    if (it != s1.end()) cout << "Found element: " << *it << endl;
    else cout << "Element not found" << endl;

    int cnt = s1.count(10); // 1 if present, else 0 (sets never have duplicates)
    cout << "Count of 10: " << cnt << endl;

    // range-erase example
    s1.insert(15);
    s1.insert(20);
    auto it1 = s1.find(10);
    auto it2 = s1.find(20);
    s1.erase(it1, it2); // erases [it1, it2) -> up to but NOT including 20

    cout << "Set elements after erasing from it1 to it2: ";
    for (auto it : s1) cout << it << " ";
    cout << endl;

    // find, clear, swap also available
    // insert / erase / find -> O(log n); count -> O(log n)
    // NOTE: lower_bound / upper_bound are also available on set (worth exploring separately)
}

// ---------- 4b. MULTISET (duplicates allowed, sorted) ----------
void explainMultiset() {
    multiset<int> ms1;
    ms1.insert(5);
    ms1.insert(1);
    ms1.insert(10);
    ms1.insert(5); // duplicate -> allowed

    cout << "Multiset elements: ";
    for (auto it : ms1) cout << it << " ";
    cout << endl;

    cout << "Multiset size: " << ms1.size() << endl; // 4

    ms1.erase(5); // removes ALL occurrences of 5
    cout << "Multiset elements after erasing 5: ";
    for (auto it : ms1) cout << it << " ";
    cout << endl;

    cout << "Count of 5 in multiset: " << ms1.count(5) << endl;
    // find, clear, swap also available
    // insert / erase / find / count -> O(log n)
}

// ---------- 4c. MAP (unique keys, sorted) ----------
void explainMap() {
    map<int, string> m1;
    m1[1] = "One";
    m1[2] = "Two";
    m1[3] = "Three";

    cout << "Map elements: " << endl;
    for (auto it : m1) cout << it.first << " -> " << it.second << endl;

    cout << "Size of map: " << m1.size() << endl;

    m1.erase(2); // removes the key-value pair with key 2
    cout << "Map elements after erasing key 2: " << endl;
    for (auto it : m1) cout << it.first << " -> " << it.second << endl;

    cout << "Is key 3 in map? " << (m1.count(3) ? "Yes" : "No") << endl;

    auto it = m1.find(1);
    if (it != m1.end()) cout << "Found key 1 with value: " << it->second << endl;
    else cout << "Key not found" << endl;

    // clear, swap also available
    // insert / erase / find -> O(log n)
    // keys are always unique and kept in sorted order
    // lower_bound / upper_bound are also available
}

// ---------- 4d. MULTIMAP (duplicate keys, sorted) ----------
void explainMultimap() {
    multimap<int, string> mm1;
    mm1.insert({1, "One"});
    mm1.insert({2, "Two"});
    mm1.insert({1, "Uno"}); // duplicate key -> allowed

    cout << "Multimap elements: " << endl;
    for (auto it : mm1) cout << it.first << " -> " << it.second << endl;

    cout << "Size of multimap: " << mm1.size() << endl; // 3

    mm1.erase(1); // removes ALL pairs with key 1
    cout << "Multimap elements after erasing key 1: " << endl;
    for (auto it : mm1) cout << it.first << " -> " << it.second << endl;

    cout << "Count of key 2 in multimap: " << mm1.count(2) << endl;

    auto it = mm1.find(2);
    if (it != mm1.end()) cout << "Found key 2 with value: " << it->second << endl;
    else cout << "Key not found" << endl;

    // clear, swap also available; lower_bound / upper_bound also available
    // insert / erase / find -> O(log n)
}

// ============================================================
//  5. UNORDERED ASSOCIATIVE CONTAINERS (hash-based)
// ============================================================

// ---------- 5a. UNORDERED_SET ----------
void explainUnorderedSet() {
    // unique elements, NO particular order (hash-based, not sorted)
    // note: lower_bound / upper_bound are NOT available here, since it isn't sorted
    unordered_set<int> us1;
    us1.insert(5);
    us1.insert(1);
    us1.insert(10);
    us1.insert(5); // duplicate -> ignored

    cout << "Unordered Set elements: ";
    for (auto it : us1) cout << it << " ";
    cout << endl;

    cout << "Unordered Set size: " << us1.size() << endl; // 3

    us1.erase(1);
    cout << "Unordered Set elements after erasing 1: ";
    for (auto it : us1) cout << it << " ";
    cout << endl;

    cout << "Is 10 in unordered set? " << (us1.count(10) ? "Yes" : "No") << endl;

    auto it = us1.find(5);
    if (it != us1.end()) cout << "Found element: " << *it << endl;
    else cout << "Element not found" << endl;

    // find, clear, swap also available
    // average case: insert / erase / find / count -> O(1)
    // worst case (hash collisions): O(n)
    // generally faster on average than 'set' since it skips maintaining sorted order
}

// ---------- 5b. UNORDERED_MAP ----------
void explainUnorderedMap() {
    unordered_map<int, string> um1;
    um1[1] = "One";
    um1[2] = "Two";
    um1[3] = "Three";

    cout << "Unordered Map elements: " << endl;
    for (auto it : um1) cout << it.first << " -> " << it.second << endl;

    cout << "Size of unordered map: " << um1.size() << endl;

    um1.erase(2);
    cout << "Unordered Map elements after erasing key 2: " << endl;
    for (auto it : um1) cout << it.first << " -> " << it.second << endl;

    cout << "Is key 3 in unordered map? " << (um1.count(3) ? "Yes" : "No") << endl;

    auto it = um1.find(1);
    if (it != um1.end()) cout << "Found key 1 with value: " << it->second << endl;
    else cout << "Key not found" << endl;

    // clear, swap also available
    // average case: insert / erase / find / count -> O(1)
    // worst case (hash collisions): O(n)
}

// ============================================================
//  6. ALGORITHMS & MISC STL UTILITIES
// ============================================================

// custom comparator: sort pairs by 'second' ascending;
// on a tie, sort by 'first' descending
bool comparePairs(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    if (p1.second == p2.second) {
        if (p1.first > p2.first) return true;
        return false;
    }
    return false;
}

void explainAlgorithms() {
    // ---- sort() ----
    int a[] = {5, 2, 8, 1, 9};
    int n = 5;
    sort(a, a + n); // sorts entire array ascending

    vector<int> v = {5, 2, 8, 1, 9};
    sort(v.begin(), v.end()); // sorts entire vector ascending

    sort(a + 2, a + 4);            // sorts only indices [2, 4) -> partial range
    sort(a, a + n, greater<int>()); // sorts descending using a built-in comparator

    // ---- sort() with a custom comparator ----
    pair<int, int> arr[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort by second element ascending; ties broken by first element descending
    sort(arr, arr + 3, comparePairs);
    // result: {4,1}, {2,1}, {1,2}

    cout << "Sorted pairs: ";
    for (int i = 0; i < 3; i++) {
        cout << "{" << arr[i].first << "," << arr[i].second << "} ";
    }
    cout << endl;

    // ---- bit-counting utilities ----
    int num = 7;
    int cnt = __builtin_popcount(num); // counts set bits (1s) in an int's binary form
    cout << "Number of set bits in " << num << ": " << cnt << endl;

    long long num2 = 1633279735999LL; // LL suffix marks a long long literal
    int cnt2 = __builtin_popcountll(num2); // counts set bits in a long long
    cout << "Number of set bits in " << num2 << ": " << cnt2 << endl;

    // ---- permutations ----
    string s = "123";
    sort(s.begin(), s.end()); // next_permutation requires a sorted starting point

    // generates every permutation of s, in lexicographically increasing order
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    // ---- max_element() ----
    int maxi = *max_element(a, a + n); // dereference the iterator to get the value
    cout << "Maximum element: " << maxi << endl;

    // int mn = *min_element(v.begin(), v.end());
    // int mx = *max_element(v.begin(), v.end());
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    explainPair();            // pairs, nested pairs, arrays of pairs

    explainVector();          // vector basics: push_back, emplace_back, sized init, copying
    accessVector();           // vector iterators, traversal, insert/erase, swap

    explainList();            // doubly-linked list operations
    explainDeque();           // double-ended queue operations

    explainStack();           // LIFO container
    explainQueue();           // FIFO container
    explainPriorityQueue();   // max-heap / min-heap

    explainSet();             // unique + sorted
    explainMultiset();        // duplicates + sorted
    explainMap();             // unique keys + sorted
    explainMultimap();        // duplicate keys + sorted

    explainUnorderedSet();    // unique + hash-based (no order)
    explainUnorderedMap();    // unique keys + hash-based (no order)

    explainAlgorithms();      // sort, custom comparators, bit tricks, permutations, max_element

    return 0;
}