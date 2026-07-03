#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    int as[26] = {0},bs[26] = {0},index1=0,diff1=0,index2=0,diff2=0;
    string a,b;
    cin >> a >> b;
    int ans = a.size();
    for(int i=0;i<a.size();i++){
        if (b[index1]==a[i]){
            diff1++;
            index1++;
        }
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<a.size();i++){
        if (b[index2]==a[i]){
            diff2++;
            index2++;
        }
    }
    int z = max(diff1,diff2);
    cout << ans+(b.size()-z) << endl;
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
