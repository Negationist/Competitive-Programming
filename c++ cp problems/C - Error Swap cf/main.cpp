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
    int n;
    cin >> n;
    vi a(n),b(n);
    int sum = 0;
    for(int i=0;i<n;i++) {cin >> a[i]; sum+=a[i];}
    for(int i=0;i<n;i++) {cin >> b[i]; sum-=b[i];}
    if(sum){
        cout << "No\n";
        return;
    }
    vii ops;
    auto _swap = [&](int x, int y)->void{
        ops.pb({1,y+1});
        ops.pb({1,x+1});
        ops.pb({1,y+1});
        assert((int)ops.size()<=31000);
        swap(a[x],a[y]);
    };
    auto _op = [&](int x, int y)->void{
        ops.pb({x+1,y+1});
        swap(a[x],a[y]);
        a[x]-=1;
        a[y]+=1;
        assert((int)ops.size()<=31000);
    };
    if(n==2){
        if(a==b){
            cout << "Yes\n0\n";
            return;
        }
        swap(a[0],a[1]);
        a[0]-=1; a[1]+=1;
        if(a==b){
            cout << "Yes\n1\n1 2\n";
            return;
        }
        cout << "No\n";
    } else{
        if((a[n-1]-1)<=b[0]){
            while((a[n-1]-1)!=b[0]){
                _swap(n-2,n-1);
                _op(n-2,n-1);
            }
        } else{
            while((a[n-1]-1)!=b[0]){
                _op(n-2,n-1);
                _swap(n-2,n-1);
            }
        }
        _op(0,n-1);
        for(int i=2;i<n-1;i++){
            if(a[i]<=b[i]){
                while(a[i]!=b[i]){
                    _op(i,n-1);
                    _swap(i,n-1);
                }
            } else{
                while(a[i]!=b[i]){
                    _swap(i,n-1);
                    _op(i,n-1);
                }
            }
        }
        cout << "Yes\n";
        cout << ops.size() << "\n";
        for(auto [x,y] : ops){
            cout << x << " " << y << "\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
