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
    string a,b;
    cin >> a >> b;
    int n = a.size();
    int cnt1 = 1;
    int cnt2 = 1;
    vi c,d;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
           c.pb(cnt1);
           cnt1 = 1;
        } else{
            ++cnt1;
        }
        if(b[i]!=b[i-1]){
           d.pb(cnt2);
           cnt2 = 1;
        } else{
            ++cnt2;
        }
    }
    c.pb(cnt1);
    d.pb(cnt2);
    int ans = 0;
    if(a[0]!=b[0]){
        if(c.size()>1){
            vi temp;
            temp.pb(c[1]);
            temp.pb(c[0]+(c.size()>2?c[2]:0));
            for(int i=3;i<c.size();i++){
                temp.pb(c[i]);
            }
            c = temp;
            ++ans;
        } else{
            cout << "-1\n";
            return;
        }
    }
    int index = 0;
    for(int i=0;i<d.size();i+=2){
        if(i==d.size()-1){
            if(c[index]!=d[i]){
                cout << "-1\n";
                return;
            }
        }
        int x = d[i];
        if(x==c[index]){
            ++index;
            --i;
            continue;
        }
        int y = d[i+1];
        int num = 0;
        bool up = true;
        while(index<c.size()){
            if(up){
                x-=c[index];
            } else{
                y-=c[index];
            }
            ++index;
            ++num;
            up = !up;
            if(!x && !y){
                break;
            }
        }
        if(!x && !y){
            if(num%2==0){
                ans+=((num+1)/2-1);
            } else{
                if(i==d.size()-2){
                    ans+=((num+1)/2-1);
                } else{
                    cout << "-1\n";
                    return;
                }
            }
        } else{
            cout << "-1\n";
            return;
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
