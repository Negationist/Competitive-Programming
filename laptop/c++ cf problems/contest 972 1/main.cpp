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
        cin >> n;
        int a[5] = {0};
        for(int i=0;i<n;i++){
            int cur = i%5;
            a[cur]++;
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<a[i];j++){
                if(i==0) cout << 'a';
                else if(i==1) cout << 'e';
                else if(i==2) cout << 'i';
                else if(i==3) cout << 'o';
                else cout << 'u';
            }
        }
        cout << "\n";
    }
    return 0;
}
