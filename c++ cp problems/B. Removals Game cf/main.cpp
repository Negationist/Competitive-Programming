#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n),b(n);
    FOR(i,n){
        cin >> a[i];
    }
    FOR(i,n){
        cin >> b[i];
    }
    if(a==b){
        cout << "Bob" << endl;
        return;
    }
    reverse(a.begin(),a.end());
    if(a==b){
        cout << "Bob" << endl;
        return;
    }
    cout << "Alice" << endl;
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
