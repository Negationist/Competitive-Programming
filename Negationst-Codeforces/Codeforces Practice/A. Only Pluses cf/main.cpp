#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int arr[3];
        FOR(i,3){
            cin >> arr[i];
        }
        FOR(i,5){
            sort(arr,arr+3);
            arr[0]++;
        }
        cout << arr[0]*arr[1]*arr[2] << endl;

    }
    return 0;
}
