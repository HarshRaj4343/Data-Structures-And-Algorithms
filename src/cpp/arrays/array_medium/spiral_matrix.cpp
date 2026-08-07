#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;

    int n = matrix.size();
    int m = matrix[0].size();

    int left = 0;
    int right = m - 1;
    int top = 0;
    int bottom = n - 1;

    while (left <= right && top <= bottom) {

        // Left -> Right
        for (int j = left; j <= right; j++) {
            ans.push_back(matrix[top][j]);
        }
        top++;

        // Top -> Bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // Right -> Left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        // Bottom -> Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> ans = spiralOrder(matrix);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}