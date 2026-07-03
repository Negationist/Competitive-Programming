#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    int d=0;
    bool lucky = true;
    cin >> n;
    for (int i = 0; i<n.size(); i++){
        if (n[i] == '4' || n[i] == '7'){
            d++;
        }
    }
    string b = to_string(d);
     for (int i = 0; i<b.size(); i++){
        if (!(b[i] == '4') && !(b[i] == '7')){
            lucky = false;
        }
        if(!lucky){
            break;
        }
    }
    if (lucky){
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
