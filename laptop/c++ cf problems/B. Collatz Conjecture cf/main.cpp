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
    int x,y,k;
    cin >> x >> y >> k;
    k--;
    x++;
    while(x%y==0){
        x/=y;
    }
    while(true){
        int num = (y-x%y)%y;
        if(x<y){
            if(k<num){
                cout << x+k << endl;
                return;
            } else{
                k-=num;
                x=1;
                break;
            }
        }
        if(num>=k){
            x+=k;
            while(x%y==0){
                x/=y;
            }
            cout << x << endl;
            return;
        } else{
            k-=num;
            x+=num;
            while(x%y==0){
                x/=y;
            }
        }
    }
    int ans = 1+k%(y-1);
    cout << ans << endl;
}

signed main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
