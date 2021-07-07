#include<bits/stdc++.h>
using namespace std;
int board[10][10];
//print the solution
void print(int n) {
    for (int i = 0;i < n; i++) {
        for (int j = 0;j < n; j++) {

                cout <<board[i][j]<< " ";

        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

bool isSafe(int col, int row, int n) {
  //check for same column
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }
    //check for upper left diagonal
    for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) {
        if (board[i][j]) {
            return false;
        }
    }
    //check for upper right diagonal
    for (int i = row, j = col; i>=0 && j<n; j++,i--){
        if (board[i][j]) {
            return false;
        }
    }
    return true;
}

bool solve (int n, int row) {
    if (n == row) {
        print(n);
        return true;
    }

    bool res = false;
    for (int i = 0;i <=n-1;i++){
        if (isSafe(i, row, n)){
            board[row][i] = 1;
            res = solve(n, row+1) || res;

            board[row][i] = 0;
        }
    }
    return res;
}
int main()
{
        int n;
        cin >> n;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                board[i][j] = 0;
            }
        }
        bool res = solve(n, 0);
        if(res == false) {
            cout << "no possible solution" << endl; //if there is no possible solution
        } else {
            cout << endl;
        }
  return 0;
}
