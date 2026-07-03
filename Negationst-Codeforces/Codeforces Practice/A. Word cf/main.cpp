#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string input;
    getline(cin, input);
    int i=0,u=0,l=0;
    for (; i<input.size();){
        if (islower(input[i])){
            l++;
            i++;
        } else if (isupper(input[i])){
            u++;
            i++;
        }
    }
    if (l>=u){
        for(int a=0; a<input.size();){
            input[a] = tolower(input[a]);
            a++;
        }
    } else if(l<u){
            for(int a=0; a<input.size();){
            input[a] = toupper(input[a]);
            a++;
            }
        }
    cout << input;
    return 0;
}
