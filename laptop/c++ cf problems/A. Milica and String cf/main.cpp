#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n,k;
    string s;
    cin >> n >> k >> s;
    int pref[n+1];
    pref[0] = 0;
    for(int i=0;i<n;i++){
        pref[i+1] = (s[i]=='B' ? 1 : 0) + pref[i];
    }
    if(pref[n]<k){
        int need = k -pref[n];
        for(int i=0;i<n;i++){
            if((i+1) - pref[i+1]== need){
                cout << "1\n" << i+1 << " B\n";
                return;
            }
        }
    } else if(pref[n]>k){
        int need = pref[n] - k;
        for(int i=0;i<n;i++){
            if(pref[i+1] == need){
                cout << "1\n" << i+1 << " A\n";
                return;
            }
        }
    } else cout << "0\n";
}

signed main()
{
    ios::sync_with_stdio(0);

    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
