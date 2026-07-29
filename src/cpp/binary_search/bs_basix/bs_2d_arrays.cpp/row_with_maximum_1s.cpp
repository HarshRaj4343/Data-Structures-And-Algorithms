#include <iostream>
#include <vector>
using namespace std;

// since each row contains only 0s and 1s, we could also do onesCount = sum of all elements in that row

int lowerbound(vector<int> &arr, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int rowWithMaxOnes1(vector<vector<int>> &grid, int rows, int cols)
{
    int maxRowIndex = -1;
    int maxOnesCount = 0;

    for (int i = 0; i < rows; i++)
    {
        int onesCount = 0;
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                onesCount++;
            }
        }
        if (onesCount > maxOnesCount)
        {
            maxOnesCount = onesCount;
            maxRowIndex = i;
        }
    }

    return maxRowIndex;
}

// TC = O(rows * cols)

// For BS, compute either of them:-
// 1. lower_bound(1)
// 2. upper_bound(0)
// 3. first_occurence(1)

int rowWithMaxOnes2(vector<vector<int>> &grid, int rows, int cols)
{
    int maxRowIndex = -1;
    int maxOnesCount = 0;

    for (int i = 0; i < rows; i++)
    {
        int cnt = lowerbound(grid[i], cols, 1); // index of first 1 in the row
        int onesCount = cols - cnt;             // number of 1s in the row
        if (onesCount > maxOnesCount)
        {
            maxOnesCount = onesCount;
            maxRowIndex = i;
        }
    }

    return maxRowIndex;
}

// TC = O(rows * log(cols))

// if entire rows are sorted, and we need to optimise O(n*m) --> Think of BS

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }

    int result = rowWithMaxOnes1(grid, rows, cols);
    cout << result << endl;

    int result1 = rowWithMaxOnes2(grid, rows, cols);
    cout << result1 << endl;

    return 0;
}