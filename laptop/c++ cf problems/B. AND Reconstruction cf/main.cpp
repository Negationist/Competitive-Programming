#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n],b[n-1];
    for(int i=0;i<n-1;i++){
        cin >> b[i];
    }
    a[0] = b[0];
    for(int i=1;i<n;i++){
        a[i] = b[i]|b[i-1];
    }
    for(int i=0;i<n-1;i++){
        if(b[i] != ((a[1])&(a[i+1]))){
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
