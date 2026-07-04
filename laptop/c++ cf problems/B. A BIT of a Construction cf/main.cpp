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
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> a;
        int num = 0;
        if(n==1){
            cout << k << endl;
            continue;
        }
        for(int i=18;i>=0;i--){
            if(1LL<< i & (k+1)){
                num++;
            }
        }
        if(num==1){
            cout << k << " ";
            n--;
            while(n--){
                cout << "0 ";
            }
        } else{
            for(int i=18;i>=0;i--){
            if(1LL << i & k){
                cout << ((1LL<<i) -1) << " " << k-((1LL<<i) -1) << " ";
                n-=2;
                while(n--){
                    cout << "0 ";
                }
                break;
            }
        }
        }
        cout << endl;
    }
    return 0;
}
