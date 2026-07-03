#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

unordered_map<char,int> m1;
unordered_map<char,int> m2;

int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    FOR(i,a.size()){
        if (a[i]==' ') continue;
        m1[a[i]]++;
    }
    FOR(i,b.size()){
        if (b[i]==' ') continue;
        m2[b[i]]++;
    }
    for(auto it = m2.begin();it != m2.end(); it++){
        if (it->second > m1[it->first] || m1.find(it->first) == m1.end()){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
