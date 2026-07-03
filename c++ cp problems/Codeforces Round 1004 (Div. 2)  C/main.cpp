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
int num9[18];
int pow10[18];

void compute(){
    num9[0]=0;
    num9[1]=9;
    int add=9;
    for(int i=2;i<18;i++){
        add*=10;
        num9[i]=num9[i-1]+add;
    }
    pow10[0]= 1;
    for(int i=1;i<18;i++){
        pow10[i]=pow10[i-1]*10;
    }
}

void solve(){
    auto getxth=[&](int num,int x){
        num/=pow10[x-1];
        return num%10;
    };
    int n;
    cin >> n;
    string s = to_string(n);
    s = "00"+s;
    int x = s.size();
    int ans = LLONG_MAX;
    int place = 0;
    int last = n%10;
    for(int i=x-1;i>=0;i--){
        ++place;
        if(i!=x-1){
            int temp=n;
            for(int j=1;j<=20;j++){
                temp+=num9[place-1];
                if(getxth(temp,place)==7){
                    ans=min(ans,j);
                    break;
                }
            }
        }else{
            if(last>=7){
                ans=min(ans,last-7);
            }else{
                ans=min(ans,10-(7-last));
            }
        }
        int cur = getxth(n,place);
        if(cur==8){
            ans=min(ans,1+last);
        }
        if(cur==7){
            ans=0;
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
