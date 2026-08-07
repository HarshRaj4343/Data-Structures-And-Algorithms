#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> bruteforce(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[j][n - 1 - i] = matrix[i][j];
        }
    }
    return ans;
}

void optimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    // execute the transpose of the matrix -> a slightly bad version
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // do the reversal of each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
// tc = o(n/2*n/2) + o(n*n/2)
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // vector<vector<int>> ans = bruteforce(matrix);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    optimal(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}