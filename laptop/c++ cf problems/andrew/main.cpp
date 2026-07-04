#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int run(string s1, string s2){
    int good = true;
    int n = s1.size();
    int cnt = 0;
    int ans = -1;
    for(int i=0;i<n;i++){
        if(s1[i]=='T' && s2[i]=='A'){
            cnt++;
        }
        if(s1[i]=='A' && s2[i]=='T'){
            cnt++;
        }
        if(s1[i]=='G' && s2[i]=='C'){
            cnt++;
        }
        if(s1[i]=='C' && s2[i]=='G'){
            cnt++;
        }
        cnt = 0;
        ans = max(ans,cnt);
    }
    return ans;
}

void solve(){
    vector<string> s(2);
    cin >> s[0] >> s[1];
    cout << "Longest run was: " << run(s[0],s[1]);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
