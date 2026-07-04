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
    int n,k;
    cin >> n >> k;
    int mx = 0;
    for(int i=0;i<n;i++){
        mx+=abs((1+i)-(n-i));
    }
    if(k%2==1 || k>mx){
        cout << "No\n";
        return;
    } else{
        cout << "Yes\n";
        int a[n+1];
        int addable = 2*(n-1);
        int index = 1;
        for(int i=1;i<=n;i++){
            a[i] = i;
        }
        while(k>addable){
            swap(a[index],a[n+1-index]);
            k-=addable;
            addable-=4;
            index++;
        }
        if(k==0){
            for(int i=1;i<=n;i++){
                cout << a[i] << " ";
            }
            cout << "\n";
            return;
        }
            int l = n/2;
            int r = l+1;
            k-=2;
            int cur = 1;
            while(k>0){
                if(cur){
                    r++;
                    k-=2;
                } else{
                    l--;
                    k-=2;
                }
                cur = 1 - cur;
            }
            swap(a[l],a[r]);
            for(int i=1;i<=n;i++){
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
