#include <bits/stdc++.h>
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
bool flag = false;
int ask(int l, int r){
    if(l==r){
        return 0LL;
    }
    cout << "? " << l+1  << " " << r+1 << "\n";
    cout.flush();
    int z;
    cin >> z;
    return z;
}

void solve(){
    int n;
    cin >> n;
    if(n==-1){
        flag = true;
        return;
    }
    int close[n];
    int num = n;
    for(int i=0;i<n;i++){
        close[i] = i+1;
    }
    while(num>1){
        int mn = LLONG_MAX, l;
        for(int i=0;i<n-1;i++){
            if(close[i]==-1){
                continue;
            }
            int temp = close[i]-i;
            if(temp<mn){
                mn = temp;
                l = i;
            }
        }
        int r = close[l];
        int small = ask(l,r-1);
        int large = ask(l,r);
        if(large==small){ //remove l
            for(int j=l-1;j>=0;j--){
                if(close[j]!=-1){
                    close[j] = r;
                    break;
                }
            }
            close[l] = -1;
        } else{ //remove r
            for(int j=r+1;j<n;j++){
                if(close[j]!=-1){
                    close[l] = j;
                    break;
                }
            }
            if(close[l]==r) close[l] = LLONG_MAX;
            close[r] = -1;
        }
        --num;
    }
    for(int i=0;i<n;i++){
        if(close[i]!=-1){
            cout << "! " << i+1 << "\n";
            cout.flush();
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
        if(flag){
            return 0;
        }
        solve();
    }
    return 0;
}
