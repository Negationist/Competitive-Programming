#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    long long l,r;
    cin >> l >> r;
    long long diff = r-l;
    long long L = 1; long long R = 50000;
    while(L<=R){
        long long mid = (R+L)/2;
        long long val = mid*(mid+1)/2;
        if (val <= diff){
            L = mid+1;
        } else{
            R = mid-1;
        }
    }
    cout << R+1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
