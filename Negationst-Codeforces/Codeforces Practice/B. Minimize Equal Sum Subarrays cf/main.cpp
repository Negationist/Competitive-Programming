#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        for(int i=1;i<n;i++){
            cout << arr[i] << " ";
        }
        cout << arr[0] << endl;
    }
    return 0;
}
