#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        string sR = s;
        reverse(sR.begin(),sR.end());
        int i=0;
        while(i<s.size()){
            if(sR[i] > s[i]){
                break;
            } else if(sR[i] < s[i]){
                cout << sR;
                break;
            }
            i++;
        }
        cout << s << "\n";
    }
    return 0;
}
