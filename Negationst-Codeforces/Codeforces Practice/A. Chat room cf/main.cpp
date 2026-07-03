#include <bits/stdc++.h>

using namespace std;

int main()
{
    string n;
    cin >> n;
    int scope = 0;
    if (n.size()<5){
        cout << "NO";
        return 0;
    }
    for (int i=0;i<n.size();i++){
        if (n[i] == 'h'){
            scope = i+1;
            break;
        }
        else if(i==n.size()-5){
            cout << "NO";
            return 0;
        }
    }
    for (int i=scope;i<n.size();i++){
        if (n[i] == 'e'){
            scope = i+1;
            break;
        }
        else if(i==n.size()-4){
            cout << "NO";
            return 0;
        }
    }
    for (int i=scope;i<n.size();i++){
        if (n[i] == 'l'){
            scope = i+1;
            break;
        }
        else if(i==n.size()-3){
            cout << "NO";
            return 0;
        }
    }
    for (int i=scope;i<n.size();i++){
        if (n[i] == 'l'){
            scope = i+1;
            break;
        }
        else if(i==n.size()-2){
            cout << "NO";
            return 0;
        }
    }
    for (int i=scope;i<n.size();i++){
        if (n[i] == 'o'){
            cout << "YES";
            break;
        }
        else if(i==n.size()-1){
            cout << "NO";
            return 0;
        }
    }

    return 0;
}
