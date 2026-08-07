#include <iostream>
#include <vector>
using namespace std;

void markRow(vector<vector<int>> &matrix, int n, int m, int h){
    for (int j = 0; j < m; j++) {
        if (matrix[h][j] != 0){
            matrix[h][j] = -1;
        } 
    }
} 

void markColumn(vector<vector<int>> &matrix, int n, int m, int k){
    for (int i = 0; i < n; i++) {
        if (matrix[i][k] != 0){
            matrix[i][k] = -1;
        }
    }
} 

void bruteforce(vector<vector<int>> &matrix, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0){
                markRow(matrix,n,m,i);
                markColumn(matrix,n,m,j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) matrix[i][j] = 0;
        }
    }
}
// tc = o(n*m(1+(n+m)))

void better(vector<vector<int>> &matrix, int n, int m){
    vector <int> row(n,0);
    vector <int> col(m,0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((row[i] == 1) || (col[j] == 1)){
                matrix[i][j] = 0;
            }
        }
    }
}
// tc = o(2*n*m)
// sc = o(n+m)

void optimal(vector<vector<int>> &matrix, int n, int m){
    bool row0 = false;
    bool col0 = false;
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) row0 = true;
    }
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) col0 = true;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if (row0 == true){
        for (int j = 0; j < m; j++) {
            matrix[0][j] == 0;
        }
    }
    if (col0 == true){
        for (int i = 0; i < n; i++) {
            matrix[i][0] == 0;
        }
    }
}

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
    bruteforce(matrix,n,m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    better(matrix,n,m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    optimal(matrix,n,m);
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