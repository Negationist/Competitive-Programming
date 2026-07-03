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
using ld = long double;
void solve(){
    int n,l,r;
    cin >> n >> l >> r;
    vi a(n+7);
    vi pref(n+7);
    vi sum(n+7);
    sum[0] = 0;
    pref[0] = 0;
    int l_odd = -1;
    int l_index;
    for(int i=1;i<=n+5;i++){
        if(i<=n){
            cin >> a[i];
            pref[i] = pref[i-1]^a[i];
            sum[i] = sum[i-1]+a[i];
        } else{
            int last = i/2;
            a[i] = pref[last];
            pref[i] = pref[i-1]^a[i];
            sum[i] = sum[i-1]+a[i];
            if(i&1){
                l_odd = pref[i];
                l_index = i;
            }
        }
    }
    auto value = [&](auto self, int x){
        if(x<=n) return a[x];
        int last = x/2;
        if(last<=n+5){
            //cout << "here1\n";
            return pref[last];
        } else{
            if(last%2==1){
                //cout << "here2\n";
                return l_odd;
            } else{
                //cout << "here3\n";
                int val = self(self,last);
                return (l_odd^val);
            }
        }
    };
    auto sum = [&](auto self, int x){
        if(x<=n+5){
            return sum[x];
        } else{
            int res = 0;
            int last = x/2;
            while(last%4!=1 && last>=1){
                res+=value(last);
                --last;
            }
            if(last>1){
                if(last<=n+5){
                    res+=sum[last];
                } else{
                    res+=sum[l_index];
                    while(l_index%4!=2 && l_index<last){
                        res+=value(l_index);
                        l_index++;
                    }
                    int res2 = (last-l_index)/4;
                    res+=*(res2*l_odd);
                }
            }
        }
        return res;
    }
    cout << sum(r) - sum(l-1) << "\n";
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
