#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    int index;
    cin >> n >> m;
    vector<string*> strings;
    for (int i=0; i<n; i++){
        string a;
        cin >> a;
        strings.push_back(new string(a));
    }
    for (int i=0;i<n; i++){
        int index = i;
        for (int a=0;a<m;a++){
            index++;
            if ((*strings[i])[a]=='.'){
                if (index%2==1){
                    (*strings[i])[a] = 'W';
                } else if(index%2==0){
                    (*strings[i])[a] = 'B';
                }
            }
        }
    }


    for (auto item : strings){
        cout << *item << endl;
    }
    return 0;
}
