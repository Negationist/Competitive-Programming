#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<char> e;
    for(int i=0;i<n;i++){
        string input;
        cin >> input;
        if(i%k==0){
            FOR(a,n){
                if (a%k==0){
                    e.push_back(input[a]);
                }
            }
        }
    }
    for (int i=0;i<(n/k)*(n/k);i++){
        cout << e[i];
        if ((i+1)%(n/k)==0){
            cout << endl;
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
