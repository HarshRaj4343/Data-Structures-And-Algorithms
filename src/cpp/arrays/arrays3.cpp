// Finding Missing Number in an Array

// Brute Force Approach

#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    for (int i=1;i<=n;i++){
        int flag=0;
        for (int j=0;j<n-1;j++){
            if (arr[j]==i){
                flag=1;
                break;
            }
        }
        if (flag==0){
            cout<<i;
        }
    }
}


// Better Approach


#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector <int> arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector <int> hash(n+1,0);
    for (int i=0;i<n-1;i++){
        hash[arr[i]]=1;
    }
    for (int i=1;i<n;i++){
        if (hash[i]==0){
            cout<<i;
        }
    }
    return 0;
}


// Optimal Solution - 1

#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int total=n*(n+1)/2;
    int sum=0;
    for (int i=0;i<n-1;i++){
        sum+=arr[i];
    }
    cout<<total-sum;
    return 0;
}


// Optimal Solution - 2.1
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int xor1=0;
    for (int i=1;i<=n;i++){
        xor1=xor1^i;
    }
    int xor2=0;
    for (int i=0;i<n-1;i++){
        xor2=xor2^arr[i];
    }
    cout<<(xor1^xor2);  
    return 0;
}

// Optimal Solution - 2.2

#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int xor1=0;
    int xor2=0;
    for (int i=0;i<n-1;i++){
        xor1=xor1^(i+1);
        xor2=xor2^arr[i];
    }
    xor1=xor1^n;
    cout<<(xor1^xor2);
    return 0;
}



// Finding Maximum consecutive Ones in an Array

#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count=0;
    int maxi=0;
    for (int i=0;i<n;i++){
        if (arr[i]==1){
            count++;
            if (count>maxi) maxi=count;
        }
        else {
            count=0;
        }
    }
    cout<<maxi;
    return 0;
}

// FInding the number that appears once in an array where every other number appears twice

// Brute Force Approach

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == 1) {
            cout << arr[i];
            break;
        }
    }
    return 0;
}

// Tc: O(n^2)  Sc: O(1)

// Better Solution

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int maxi;
    for (int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    vector <int> hash(maxi+1,0);
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    for (int i = 0; i <= maxi; i++) {
        if (hash[i]==1){
            cout << i;
            break;
        }
    }
    return 0;
}

// Tc: O(n)  Sc: O(m) where m is the maximum element in the array

// Refer to notes for further details on Better Solution!


// Most Optimal Solution

#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int xor1=0;
    for (int i=0;i<n;i++){
        xor1=xor1^arr[i];
    }
    cout<<xor1;
    return 0;
}

// Tc: O(n)  Sc: O(1)