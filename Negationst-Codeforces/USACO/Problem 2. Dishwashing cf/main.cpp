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
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<stack<int>> s(1);
    vector<int> mx(1);
    s[0].push(a[0]);
    mx[0] = a[0];
    int ans = 1;
    int frnt = 0;
    int mn = -1;
    for(int i=1;i<n;i++){
        if(a[i]<mn){
            break;
        }
        int l = frnt, r = s.size()-1;
        if(a[i]>s[r].top()){ //real big
            stack<int> temp;
            temp.push(a[i]);
            s.pb(temp);
            mx.pb(a[i]);
        } else if(a[i]<s[frnt].top()){ //real small
            s[frnt].push(a[i]);
        } else{
            while(l<=r){
                int mid = l+(r-l)/2;
                if(s[mid].top()>a[i]){
                    r = mid-1;
                } else{
                    l = mid+1;
                }
            }
            if(mx[l-1]<a[i]){
                s[l].push(a[i]);
            } else{
                while(s[frnt].top()<a[i]){
                    mn = s[frnt].top();
                    s[frnt].pop();
                    if(s[frnt].size()==0){
                        if(r>frnt){
                            frnt++;
                        } else{
                            break;
                        }
                    }
                }
                s[frnt].push(a[i]);
            }
        }
        ans++;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("dishes.in","r",stdin);
    //freopen("dishes.out", "w", stdout);
    solve();
    return 0;
}
