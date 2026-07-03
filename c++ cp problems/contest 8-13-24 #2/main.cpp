#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    bool failed = false;
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    int f;
    cin >> f;
    arr[f-1]=1;
    for (int i=0; i<n-1;i++){
        int x;
        cin >> x;
        if (x==1){
            if(arr[x]==1){
                arr[x-1]=1;
            } else{
                failed = true;
            }
            continue;
        }
        if (x==n){
            if(arr[x-2]==1){
                arr[x-1]=1;
            } else{
                failed = true;
            }
            continue;
        }
        if(arr[x-2]==1 || arr[x]==1){
            arr[x-1] = 1;
        } else{
            failed = true;
        }
    }
    if(failed){
        cout << "NO" << endl;
    } else{
        cout << "YES" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
