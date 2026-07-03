#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

const int inf = 1LL<<60;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    vector<int> ans;
    vector<int> mx(n, -1);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
        mx[a[i]] = max(mx[a[i]],i);
    }
    for(int i=0;i<n;i++){
        if(mx[i]==-1){
            mx[i] = inf;
        }
    }
    multiset<int> left;
    for(int x: mx){
        left.insert(x);
    }
    int l = *left.begin();
    int r = 0;
    int i = 0;
    set<int> taken;
    set<pii> odd; // most
    set<pii> even; // least
    while(l!=inf){
        while(i<=l){
            odd.insert({-a[i],i});
            even.insert({a[i],i});
            i++;
        }
        if(ans.size()%2==0){ //looking for odd
            int x,y;
            while(true){
                x = odd.begin()->ff;
                y = odd.begin()->ss;
                if(taken.find(-x)==taken.end()) break;
                else{
                    odd.erase({x,y});
                }
            }
            taken.insert(-x);
            ans.pb(-x);
            while(r<=y){
                odd.erase({-a[r],r});
                even.erase({a[r],r});
                r++;
            }
            left.erase(mx[-x]);
            left.insert(inf);
        } else{
            int x,y;
            while(true){
                x = even.begin()->ff;
                y = even.begin()->ss;
                if(taken.find(x)==taken.end()) break;
                else even.erase({x,y});
            }
            taken.insert(x);
            ans.pb(x);
            while(r<=y){
                odd.erase({-a[r],r});
                even.erase({a[r],r});
                r++;
            }
            left.erase(mx[x]);
            left.insert(inf);
        }
        l = *left.begin();
    }
    cout << ans.size() << "\n";
    for(int x : ans){
        cout << x+1 << " ";
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
