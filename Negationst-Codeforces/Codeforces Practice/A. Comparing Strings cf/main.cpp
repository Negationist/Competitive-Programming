#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

unordered_map<char,int> m1;
unordered_map<char,int> m2;

int main()
{
    string a,b;
    cin >> a >> b;
    int c = 0;
    FOR(i,a.size()){
        m1[a[i]]++;
    }
    FOR(i,b.size()){
        m2[b[i]]++;
    }

    if(m1.size()!=m2.size()){
        cout << "NO";
        return 0;
    }

    for(auto it = m1.begin(); it!=m1.end();it++){
        if(it->second != m2[it->first]){
            cout << "NO";
            return 0;
        }
    }

    if(a.size()!=b.size()){
        cout << "NO";
        return 0;
    }

    FOR(i,a.size()){
        if(a[i] != b[i]){
           c++;
        }
        if (c>2){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
