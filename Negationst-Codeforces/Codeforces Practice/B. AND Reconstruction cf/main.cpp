#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n],b[n-1];
    FOR(i,n-1){
        cin >> b[i];
    }
    a[0] = b[0];
    for(int i=1;i<n-1;i++){
        a[i] = b[i]|b[i-1];
    }
    a[n-1] = b[n-2];
    for(int i=0;i<n-1;i++){
        if(b[i] != (a[i]&a[i+1])){
            cout << -1 << endl;
            return;
        }
    }
    for(int x : a){
        cout << x << " ";
    }
    cout << endl;
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
