#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int solve(int n){
    if(n==1){
        return 1;
    }
    int cur=32;
    while(cur>1){
        int divisor = 0;
    for(int i=0;i<6;i++){
        if(cur & (1<<i)){
            int addend = 1;
            int copyI = i;
            while(copyI--){
                addend*=10;
            }
            divisor+=addend;
        }
    }
        if(n%divisor==0){
            return solve(n/divisor);
        }
        cur--;
    }
    return 2;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(solve(n)==1){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    return 0;
}
