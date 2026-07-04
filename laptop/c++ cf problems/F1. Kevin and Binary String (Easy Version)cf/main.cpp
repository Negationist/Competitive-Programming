#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    string a,b;
    cin >> a >> b;
    int n = a.size();
    vi c,d;
    int cnt1 = 1, cnt2 = 1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            if(a[i-1]=='0'){
                c.pb(cnt1);
            } else{
                c.pb(-cnt1);
            }
            cnt1 = 1;
        } else{
            cnt1++;
        }
        if(b[i]!=b[i-1]){
            if(b[i-1]=='0'){
                d.pb(cnt2);
            } else{
                d.pb(-cnt2);
            }
            cnt2 = 1;
        } else{
            cnt2++;
        }
    }
    if(a[n-1]=='0'){
        c.pb(cnt1);
    } else{
        c.pb(-cnt1);
    }
    if(b[n-1]=='0'){
        d.pb(cnt2);
    } else{
        d.pb(-cnt2);
    }
    for(int x : c){
        cout << x << " ";
    }
    cout << "\n";
    for(int x : d){
        cout << x << " ";
    }
    cout << "\n";
    int ans = 0;
    int index = 0;
    for(int i=0;i<d.size();i+=2){
        if(c[index]==d[i]){
            --i;
            ++index;
            continue;
        }
        int tot = 0;
        if(i==d.size()-1){
            if(index!=c.size()-1 || c[index]!=d[i]){
                cout << "-1\n";
                return;
            }
        } else{
            int extra = (c[index]/abs(c[index])!=d[i]/abs(d[i]));
            int x = d[i];
            int y = d[i+1];
            if(x>y){
                swap(x,y);
            }
            for(;index<c.size();index++){
                if(c[index]<0){
                    if(d[i]<0){
                        ++tot;
                    }
                    x-=c[index];
                } else{
                    if(d[i]>0){
                        ++tot;
                    }
                    y-=c[index];
                }
                if(!x && !y){
                    ++index;
                    break;
                }
            }
            if(x || y){
                cout << "-1\n";
                return;
            }
            ans+=(tot-1);
            ans+=extra;
            //cout << tot << "  " << extra << "!\n";
        }
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
