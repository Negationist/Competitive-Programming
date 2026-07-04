#include <bits/stdc++.h>

using namespace std;

void solve(){
    int MOD;
    vector<int> operations;
        for(int i=29;i>=0;i--){
            operations.push_back(1 << i);
        }
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            if(i==0){
                MOD = a%2;
            } else{
                if (a%2 != MOD) {
                    cout << -1 << endl;
                    return;
                }
            }
        }
        if (MOD == 0){
            operations.push_back(1);
        }
        cout << operations.size() << endl;
        for(int item : operations){
            cout << item << " ";
        }
        cout << endl;
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
