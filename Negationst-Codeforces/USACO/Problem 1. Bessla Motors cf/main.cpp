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
    int l,r,g;
    cin >> l >> r >> g;
    int x = (l/g)*g;
    x+=(x<l)*g;
    int y = (r/g)*g;
    //cout << "x is " << x << "\n y is " << y << "\n";
    if(x>=l && x<=r && y>=l && y<=r && x<y){
        //cout << "here\n";
        int num = y-x;
        while(num>0){
            for(int i=x;i+num<=y;i+=g){
                //cout << i << " " << num << "\n";
                if(gcd(i,num)==g){
                    cout << i << " " << i+num << "\n";
                    return;
                }
            }
            num-=g;
        }

    } else if(x==y && g==x){
        cout << x << " " << x << "\n";
    }
    else{
        cout << "-1 -1\n";
    }
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
