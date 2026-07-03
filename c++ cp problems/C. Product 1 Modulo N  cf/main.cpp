#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
   set<int> ans;
   ans.insert(1);
   int n;
   cin >> n;
   int og = n;
   set<int> factors;
   for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            factors.insert(i);
            n/=i;
        }
   }
   if(n>1) factors.insert(n);
   int prod = 1;
   for(int i=2;i<og;i++){
        bool good = true;
        for(int x : factors){
            if(i%x==0){
                 good = false;
                 break;
            }
        }
        if(good){
            prod*=i;
            prod%=og;
            ans.insert(i);
        }
   }
   if(prod!=1){
        ans.erase(prod);
   }
   cout << ans.size() << "\n";
   for(int x : ans){
        cout << x << " ";
   }
   cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
