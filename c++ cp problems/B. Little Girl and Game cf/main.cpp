#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

unordered_map<char,int> s;

int main()
{
    bool fW = true,eExists;
    int o = 0;
    string  m;
    cin >> m;
    FOR(i,m.size()){
        s[m[i]]++;
    }

    while(true){
            o = 0;
    eExists = false;
    for(auto it = s.begin();it != s.end();it++){
        if((it->second)%2==1){
            o++;
        }
    }
    if (o<=1){
        if(fW){
            cout << "First";
            return 0;
        } else{
            cout << "Second";
            return 0;
        }
    } else{
        fW = !fW;
    }

    for(auto it = s.begin();it != s.end();it++){
        if (it->second%2==0&&it->second>0){
            it->second--;
            eExists = true;
            break;
        }
    }
    if(eExists) continue;
        for(auto it = s.begin();it != s.end();it++){
            if(it->second > 0){
                it->second--;
                break;
            }
        }
    }
    return 0;
}
