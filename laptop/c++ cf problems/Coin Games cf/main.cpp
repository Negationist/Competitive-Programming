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
        int n,num=0;
        cin >> n;
        string s;
        cin >> s;
        for(int i=0;i<n;i++){
            if(s[i]=='U'){
                num++;
            }
        }
        if(num%2==1){
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
    }
    return 0;
}
