#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

//  Precomputed hashing
    int hash[11] = {0};   // assuming all array values are between 0 and 10

    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;   // increment frequency count for each value
    }

    int q;
    cin >> q;  // number of questions you are asking

    while (q--) {
        int x;
        cin >> x;
        cout << hash[x] << endl;  // print how many times x appeared in the array
    }

    return 0;
}

//character hashing

#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    //precompute
    int hash[26] = {0};
    for (int i=0; i<s.size(); i++){
        hash[s[i]-'a']++;
    } // assuming only lowercase letters
    int q;
    cin >> q;
    while (q--) {
        char x;
        cin >> x;
        //fetching
        cout << hash[x - 'a'] << endl;
    }
    return 0;
}


//another method

#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    //precompute
    int hash[256] = {0};
    for (int i=0; i<s.size(); i++){
        hash[s[i]]++;
    } // assuming only lowercase letters
    int q;
    cin >> q;
    while (q--) {
        char x;
        cin >> x;
        //fetching
        cout << hash[x] << endl;
    }
    return 0;
}

//using maps in sorted manner

#include <iostream>
#include <map>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    //precompute
    map<int,int> mpp;
    for (int i=0; i<n;i++){
        mpp[arr[i]]++;
    }

    int q;
    cin>>q;
    while (q--){
        int number;
        cin>>number;
        cout<<mpp[number]<<endl;
    }
    return 0;
}


//time complexity of storing and fetching in log(N) in all cases ( best, medium, worst)


//using unordered map

#include <iostream>
#include <map>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    //precompute
    unordered_map<int,int> mpp;
    for (int i=0; i<n;i++){
        mpp[arr[i]]++;
    }

    int q;
    cin>>q;
    while (q--){
        int number;
        cin>>number;
        cout<<mpp[number]<<endl;
    }
    return 0;
}

// here, time complexity usually for best and average case is O(1) but rarely , in the worst case scenario, it could change to O(n).


// instead of this, we can also find the element with highest frequency and lowest frequency using vectors

#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Precompute frequencies
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    // Find highest and lowest frequency elements
    int maxFreq = INT_MIN, minFreq = INT_MAX;
    int maxElem = -1, minElem = -1;

    for (auto it : mpp) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            maxElem = it.first;
        }
        if (it.second < minFreq) {
            minFreq = it.second;
            minElem = it.first;
        }
    }

    cout << "Element with highest frequency: " << maxElem << " (appeared " << maxFreq << " times)\n";
    cout << "Element with lowest frequency: " << minElem << " (appeared " << minFreq << " times)\n";

    // Query section
    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        cout << mpp[number] << endl;
    }

    return 0;
}
// time complexity remains the same as above.