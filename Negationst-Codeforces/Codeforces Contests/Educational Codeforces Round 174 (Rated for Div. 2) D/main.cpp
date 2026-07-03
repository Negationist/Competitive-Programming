#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vi badl,badr;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-1-i]){
            badl.pb(i);
            badr.pb(n-1-i);
        }
    }
    if(badl.size()==0){
        cout << 0 << "\n";
        return;
    }
    //check if min is sufficient
    reverse(badr.begin(),badr.end());
    multiset<char> leftset,rightset;
    for(int i=badl[0];i<=badl.back();i++){
        leftset.insert(s[i]);
    }
    for(int i=badr[0];i<=badr.back();i++){
        rightset.insert(s[i]);
    }
    if(leftset==rightset){
        cout << badl.back()-badl[0]+1 << "\n";
        return;
    }
    int ans;
    set<int> bad;
    map<char,int> leftcnt,rightcnt;
    int j = badl.back();
    for(int i=badl[0];i<=j;i++){
        ++leftcnt[s[i]];
    }
    for(int i=j+1;i<=badr.back();i++){
        ++rightcnt[s[i]];
    }
    for(auto x : rightcnt){
        if(x.ss>leftcnt[x.ff]){
            bad.insert(x.ff);
        }
    }
    while(bad.size()){
        ++j;
        ++leftcnt[s[j]];
        --rightcnt[s[j]];
        if(leftcnt[s[j]]>=rightcnt[s[j]]){
            bad.erase(s[j]);
        }
    }
    ans = j-badl[0]+1;
    set<int> bad2;
    map<char,int> leftcnt2,rightcnt2;
    int j2 = badr[0];
    for(int i=badl[0];i<=j2-1;i++){
        ++leftcnt2[s[i]];
    }
    for(int i=j2;i<=badr.back();i++){
        ++rightcnt2[s[i]];
    }
    for(auto x : leftcnt2){
        if(x.ss>rightcnt2[x.ff]){
            bad2.insert(x.ff);
        }
    }
    while(bad2.size()){
        --j2;
        --leftcnt2[s[j2]];
        ++rightcnt2[s[j2]];
        if(rightcnt2[s[j2]]>=leftcnt2[s[j2]]){
            bad2.erase(s[j2]);
        }
    }
    ans = min(ans,badr.back()-j2+1);
    cout << ans << "\n";
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
