#include <bits/stdc++.h>

using namespace std;

class Dragon{
public:
    int strength;
    int bonus;
    Dragon(int a,int b): strength(a), bonus(b){}
};

vector<Dragon*> dragons;

bool compareByStrength(const Dragon*a, const Dragon*b){
return a->strength > b->strength;
}

int main()
{
    vector<Dragon*>::iterator targets;
    int s,n;
    cin >> s >> n;
    for (int i=0; i<n; i++){ //O(n)
        int a,b;
        cin >> a >> b;
        Dragon* obj = new Dragon(a,b);
        dragons.push_back(obj);
    }
    sort(dragons.begin(), dragons.end(), compareByStrength); //O(nlogn) [dominant?]

    while (true){ //if loop runs m time then O(nm) where m<=n [dominant if m>logn]
    if (s>dragons.front()->strength||dragons.size()==0){ //O(1)
        cout << "YES";
        return 0;
    } else if(s<=dragons.back()->strength){
        cout << "NO";
        return 0;
    }
    for (auto it=dragons.begin()+1;it!=dragons.end();it++){ // O(n)
        if (s>(*it)->strength){
            targets = it;
            break;
        }
    }
    for (auto it = targets; it!=dragons.end();it++){
        s+=(*it)->bonus;
    }
    dragons.resize(targets-dragons.begin());
    }
    return 0;
}
