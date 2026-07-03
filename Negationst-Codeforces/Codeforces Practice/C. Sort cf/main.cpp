#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    string a,b;
    int n,q;
    cin >> n >> q;
    cin >> a >> b;
    vector<vector<int>> pA(n,vector<int>(26,0));
    vector<vector<int>> pB(n,vector<int>(26,0));
    pA[0][a[0]-'a']++;
    pB[0][b[0]-'a']++;
    for(int i=1;i<n;i++){
        pA[i]=pA[i-1];
        pA[i][a[i]-'a']++;
    }
    for(int i=1;i<n;i++){
        pB[i]=pB[i-1];
        pB[i][b[i]-'a']++;
    }
    while(q--){
    int l,r;
    cin >> l >> r;
    l--;
    r--;
    vector<int> freqA(26,0);
    vector<int> freqB(26,0);
    for(int i=0; i<26;i++){
        freqA[i] = pA[r][i]-pA[l][i];
        freqB[i] = pB[r][i]-pB[l][i];
    }
    int z=0;
    for(int i=0; i<26;i++){
        z+=min(freqA[i],freqB[i]);
    }
    cout << r << endl;

    cout << (r-l+1)-z << endl;
}
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
