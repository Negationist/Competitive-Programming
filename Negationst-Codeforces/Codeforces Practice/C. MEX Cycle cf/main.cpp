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
    int n,x,y;
    cin >> n >> x >> y;
    if(n==3){
        cout << "0 1 2\n";
    } else if(n==4){
        if(x==1 && y==3){
            cout << "0 1 2 1\n";
        } else{
            cout << "1 2 1 0\n";
        }
    } else{
        vi ans(n);
        x--;
        y--;
        int num1 = y-x-1;
        int num2 = n-num1-2;
        if(num1%2==0 && num2%2==0){
            int cur = 0;
            for(int i=0;i<n;i++){
                ans[i] = cur;
                cur = 1 - cur;
            }
        } else if (num1%2==1 && num2%2==0){
            ans[x] = 0;
            ans[y] = 1;
            if(num1==1){
                ans[x+1] = 2;
            } else{
                ans[x+1] = 1;
                ans[x+2] = 2;
                ans[x+3] = 0;
                int cur = 1;
                for(int i=x+4;i<y;i++){
                    ans[i] = cur;
                    cur = 1 - cur;
                }
            }
            int cur = 0;
            for(int i = y+1;(i%n)!=x;i++){
                ans[(i%n)] = cur;
                cur = 1 - cur;
            }
        } else if(num1%2==0 && num2%2==1){
            int cur = 0;
            for(int i=x;i<=y;i++){
                ans[i] = cur;
                cur = 1 - cur;
            }
            if(num2==1){
                ans[(y+1)%n] = 2;
            } else{
                ans[(y+1)%n] = 2;
                ans[(y+2)%n] = 0;
                ans[(y+3)%n] = 1;
            }
            cur = 0;
            for(int i = y+4;(i%n)!=x;i++){
                ans[(i%n)] = cur;
                cur = 1 - cur;
            }
        }
        else{
            ans[x] = 0;
            ans[y] = 1;
            if(num1==1){
                ans[x+1] = 2;
            } else{
                ans[x+1] = 1;
                ans[x+2] = 2;
                ans[x+3] = 0;
                if(ans[(x+4)%n]==2){
                    ans[x+1] = 2;
                    ans[x+2] = 1;
                }
                int cur = 1;
                for(int i=x+4;i<y;i++){
                    ans[i] = cur;
                    cur = 1 - cur;
                }
            }
            if(num2==1){
                ans[(y+1)%n] = 2;
            } else{
                ans[(y+1)%n] = 2;
                ans[(y+2)%n] = 0;
                ans[(y+3)%n] = 1;
            }
            int cur = 0;
            for(int i = y+4;(i%n)!=x;i++){
                ans[(i%n)] = cur;
                cur = 1 - cur;
            }
            if(ans[(y-1)%n]==2){
                ans[(y+1)%n] = 0;
                ans[(y+2)%n] = 2;
            }
        }
        for(int x : ans){
            cout << x << " ";
        }
        cout << "\n";
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
