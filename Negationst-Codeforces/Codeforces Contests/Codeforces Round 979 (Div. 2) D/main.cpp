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
    int n,q;
    cin >> n >> q;
    vi a(n);
    int mx[n];
    int mn[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        mx[i] = -1;
        mn[i] = LLONG_MAX;
    }
    for(int i=0;i<n;i++){
        if(i==0) mx[i] = a[i];
        else mx[i] = max(mx[i-1],a[i]);
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1) mn[i] = a[i];
        else mn[i] = min(mn[i+1],a[i]);
    }
    string s;
    cin >> s;
    int bad = 0;
    for(int i=0;i<n-1;i++){
        if(s[i]=='L' && s[i+1]=='R'){
            if(mx[i]>mn[i+1]) bad++;
        }
    }
    while(q--){
        int z;
        cin >> z;
        z--;
        if(s[z]=='L'){
            s[z] = 'R';
        } else{
            s[z] = 'L';
        }
        if(s[z]=='L'){
            if(s[z+1]=='R'){
                if(mx[z]>mn[z+1]) bad++;
            }
            if(s[z-1]=='L'){
                if(mx[z-1]>mn[z]) bad--;
            }
        }
        if(s[z]=='R'){
            if(s[z-1]=='L'){
                if(mx[z-1]>mn[z]) bad++;
            }
            if(s[z+1]=='R'){
                if(mx[z]>mn[z+1]) bad--;
            }
        }
        if(bad==0){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
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
