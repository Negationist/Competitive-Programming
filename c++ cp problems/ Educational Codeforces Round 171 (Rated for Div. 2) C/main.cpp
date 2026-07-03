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
    string s;
    cin >> n >> s;
    set<int> left;
    for(int i=1;i<=n;i++){
        left.insert(i);
    }
    set<int> use;
    int ans = 0;
    int bad = 0;
    int extra = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i] == '1'){
            while(bad--){
                if(use.size()==0) break;
                left.erase(*use.begin());
                use.erase(use.begin());
            }
            bad=0;
            use.insert(i+1); //insert to the use set
        }
        if(s[i]=='0'){
            left.erase(i+1); //this is for sure gone
            ans+=(i+1); //add to ans
            bad++;
        }
    }
    while(bad--){
        if(use.size()==0) break;
        left.erase(*use.begin());
        use.erase(use.begin());
    }
    int cnt = left.size();
    cnt = (cnt+1)/2;
    while(cnt){
        ans+=*left.begin();
        left.erase(left.begin());
        cnt--;
    }
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
