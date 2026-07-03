#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    set<int> s;
    int MOD;
    int n,avg,i=0;
    cin >> n;
    FOR(i,n){
        int a;
        cin >> a;
        if(i==0){
            MOD = a%2;
        } else{
            if (a%2 != MOD){
                cout << -1 << endl;
                return;
            }
        }
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
