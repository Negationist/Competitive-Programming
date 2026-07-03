#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void stringxor(string &a, string &b){
    int n = a.size();
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            a[i] = '1';
        } else{
            a[i] = '0';
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<string> a(n);
    string b;
    int ans = 0;
    while(b.size()!=n-1){
        b.pb('0');
    }
    for(int i=0;i<n-1;i++){
        cin >> a[i];
        a[i] = b.substr(0,n-1-a[i].size())+a[i];
    }
    a[n-1] = b;
    for(int i=n-1;i>=0;i--){
        string cur = b;
        for(int j=0;j<n-1;j++){
            if(a[i][j] != cur[j]){
                ans++;
                cur[j] = a[i][j];
                stringxor(cur,a[j+1]);
            }
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
