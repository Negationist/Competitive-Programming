#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;
void solve(){
    int n,q;
    cin >> n >> q;

    string a,b;
    cin >> a >> b;

    vector<vector<int>> pA(n+1,vector<int>(26,0));
    vector<vector<int>> pB(n+1,vector<int>(26,0));

    for(int i=0;i<n;i++){
        pA[i+1] = pA[i];
        pB[i+1] = pB[i];
        pA[i+1][a[i] - 'a']++;
        pB[i+1][b[i] - 'a']++;
    }

    while(q--){
       int l,r,z=0;
       cin >> l >> r;
       for (char i = 0;i<=25;i++){
        int countA = pA[r][i]-pA[l-1][i];
        int countB = pB[r][i]-pB[l-1][i];
        z+=min(countA,countB);
       }
       cout << (r-l+1-z) << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
