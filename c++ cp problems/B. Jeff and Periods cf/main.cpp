#include <bits/stdc++.h>

#define FOR(n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    stringstream sso;
    int countt = 0;
    multimap<int,int> s;
    multiset<int> h;
    set<int> j;
    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        int b;
        cin >> b;
        j.insert(b);
        h.insert(b);
        s.insert({b,i});
    }
    for (auto entry : j){
        if(h.count(entry)==1){
            sso << entry << " 0" <<endl;
            countt++;
            continue;
        }
        bool passed = true;
        auto range = s.equal_range(entry);
        int intRange = distance(range.first,range.second);
        int arr[intRange];
        int d=0;
        for (auto it = range.first; it != range.second;d++){
            arr[d] = it->second;
            it++;
        }
        int diff = arr[1]-arr[0];
        for (int i=0;i<intRange-1;i++){
            if (arr[i+1]-arr[i]!=diff){
                passed = false;
            }
        }
        if (passed){
            sso << entry << " " << diff << endl;
            countt++;
        }
    }
    cout << countt << endl;
    string out = sso.str();
    cout << out;
    return 0;
}
