#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int arr[2] = {0};
    for(int i=0;i<s.size();i++){
        arr[s[i]-'0']++;
    }
    double z = sqrt(arr[0]);
    if(z != round(z)){
        cout << "No" << endl;
        return;
    }
    else{
        z+=2;
    }
    if(arr[1] == 4*(z-1)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
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
