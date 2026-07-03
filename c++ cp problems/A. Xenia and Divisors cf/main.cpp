#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

unordered_map<int,int> s;

int main()
{
    int n,arr1=0, arr2=0, arr3=0;
    cin >> n;
    FOR(i,n){
        int a;
        cin >> a;
        s[a]++;
    }
    if(s[1]!=n/3){
        cout << -1;
        return 0;
    }

    for(;s[4]>0;){
        s[1]--;
        s[2]--;
        s[4]--;
        arr1++;
    }
    for(;s[3]>0;){
        s[1]--;
        s[3]--;
        s[6]--;
        arr2++;
    }
    for(;s[6]>0;){
        s[1]--;
        s[2]--;
        s[6]--;
        arr2++;
    }
    for(auto it=s.begin();it!=s.end();it++){
        if((it->second)!=0){
            cout << -1;
            return 0;
        }
    }
    FOR(i,arr1){
        cout << "1 2 4" << endl;
    }
    FOR(i,arr2){
        cout << "1 3 6" << endl;
    }
    FOR(i,arr3){
        cout << "1 2 6" << endl;
    }
    return 0;
}
