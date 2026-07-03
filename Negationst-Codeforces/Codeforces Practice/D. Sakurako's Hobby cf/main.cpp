#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

string s;
vector<int> arr;
vector<int> memo;
set<int> Set;

int F(int i){
    if(Set.find(i) != Set.end()){
        Set.insert(i);
    } else{
        Set.clear();
        return 0;
    }
    if (memo[i] != -1) return memo[i];
    int ans = 0;
    if (s[i]=='0') ans++;
    int next = arr[i]-1;
    ans += F(next);
    memo[i] = ans;
    return ans;
}

void solve(){
    int n;
    cin >> n;
    arr.resize(n);
    memo.resize(n);
    FOR(i,n){
        int a;
        cin >> a;
        arr[a] = i;
        memo[a] = -1;
    }
    cin >> s;
    FOR(i,n){
        cout << F(i) << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
