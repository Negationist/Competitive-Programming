#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    int a,b;
    cin >> a >> b;
    if (a%2==1){
        cout << "NO" << endl;
        return;
    } else if(a==0 && b%2==1){
        cout << "NO" << endl;
        return;
    } else{
        cout << "YES" << endl;
        return;
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
