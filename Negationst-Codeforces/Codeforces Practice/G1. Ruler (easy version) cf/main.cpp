#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    int l=0, r=1000;
    while(l<r){
    int mid = l + (r-l)/2;
    cout << "? " << mid << " " << mid << endl << flush;
    int ans; cin >> ans;
    if(ans == mid*mid){
        l = mid+1;
    } else if(ans == (mid+1)*(mid+1)){
        r = mid;
    }
    }
    cout << "! " << l << endl << flush;
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
