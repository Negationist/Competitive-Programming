#include <bits/stdc++.h>
using namespace std;
int arr[55][55];

int main()
{
    int n; cin >> n;
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[1][0] = 3;
    arr[1][1] = 4;
    for(int i = 2; i <= n - 1; i++){
        for(int j = 0;  j <= i - 1; j++){
            arr[i][j] = 2 * i + 1;
        }
        for(int j = 0; j <= i; j++){
            arr[j][i] = 2 * i + 2;
        }
    }
    cout << "Yes\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}