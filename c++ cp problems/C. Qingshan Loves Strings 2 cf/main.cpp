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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int check = 0;
    for(int i=0;i<s.size();i++){
        check+=(s[i]=='1' ? 1: -1);
    }
    if(check){
        cout << "-1\n";
        return;
    }
    int l=0,r=s.size()-1;
    vi ans;
    while(l<r){
        if(s[l]!=s[r]){
            l++;
            r--;
        } else if(s[l]=='0'){
            ans.pb(r+1);
            s.insert(r+1, "01");
            l++;
            r++;
        } else{
            ans.pb(l);
            s.insert(l, "01");
            l++;
            r++;
        }
    }
    cout << ans.size() << "\n";
    for(int x : ans){
        cout << x << " ";
    }
    cout << "\n";
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
