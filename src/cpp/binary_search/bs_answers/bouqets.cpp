// class Solution {
// public:

//     bool possible(vector<int>& bloomDay, int m, int k, long long day) {
//         int cnt = 0;
//         int nOfBouquets = 0;

//         for (int i = 0; i < bloomDay.size(); i++) {

//             if (bloomDay[i] <= day) {
//                 cnt++;
//             }
//             else {
//                 nOfBouquets += cnt / k;
//                 cnt = 0;
//             }
//         }

//         // Count the last group
//         nOfBouquets += cnt / k;

//         return nOfBouquets >= m;
//     }

//     int minDays(vector<int>& bloomDay, int m, int k) {

//         long long n = bloomDay.size();

//         long long low = *min_element(
//             bloomDay.begin(), 
//             bloomDay.end()
//         );

//         long long high = *max_element(
//             bloomDay.begin(), 
//             bloomDay.end()
//         );

//         long long val = 1LL * m * k;

//         if (n < val)
//             return -1;

//         while (low <= high) {

//             long long mid = low + (high - low) / 2;

//             if (possible(bloomDay, m, k, mid)) {
//                 high = mid - 1;
//             }
//             else {
//                 low = mid + 1;
//             }
//         }

//         return low;
//     }
// };