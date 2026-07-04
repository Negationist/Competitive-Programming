#include <bits/stdc++.h>
//yo
using namespace std;

void solve(){
    string a,b;
    int most = 0;
    cin >> a >> b;
    int index;
    for(int i=0;i<b.size();i++){
            int sum = 0;
            index = i;
        for(int j=0;j<a.size();j++){
            if(b[index]==a[j]){
                index++;
                sum++;
            }
        }
        most = max(sum,most);
    }
    cout << a.size()+b.size()-most << endl;
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
