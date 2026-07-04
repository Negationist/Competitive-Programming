#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

const int maxA = 1e6+5, maxN = 1e4+5;
int a[maxN],b[maxN];
int cnt[maxA] = {};
ll n,sum;

bool check(int k){
    for(int i=0;i<n;i++){
        ++cnt[a[i]%k];
    }
    bool flag = true;
    for(int i=0;i<n;i++){
        if(--cnt[b[i]]<0){
            flag = false;
        }
    }
    for(int i=0;i<n;i++){
        cnt[a[i]%k] = 0;
        cnt[b[i]] = 0;
    }
    return flag;
}

void solve(){
    sum = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        sum-=b[i];
    }
    if(sum==0){
        cout << (check((int)(1e8))?(int)(1e8):-1) << "\n";
        return;
    } else{
        for(int i=1;i*i<=sum;i++){
            if(sum%i==0){
                if(check(i)){
                    cout << i << "\n";
                    return;
                }
                if(check(sum/i)){ //why?
                    cout << sum/i << "\n";
                    return;
                }
            }
        }
    }
    cout << "-1\n";
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
