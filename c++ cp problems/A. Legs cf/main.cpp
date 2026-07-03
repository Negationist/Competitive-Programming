#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    int a;
    cin >> a;
    if (a%4==0){
        cout << a/4 << endl;
    } else{
        cout << a/4+1 << endl;
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
