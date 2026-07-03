#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    vi x(100);
    int a = 24693, c = 3517, K = (1LL<<17);
    x[0] = 1000;
    for(int i=1;i<100;i++){
        x[i] = (a*x[i-1]+c)%K;
        cout << "u [" << i << "] is " << (double)x[i]/K << "\n";
    }
    //0 - busy, 1 unavailable, 2 - available
    vector<double> f(3);
    f[0] = 0.2; f[1] = 0.5; f[2] = 1;
    string dict[3] = {"busy!", "unavailable!", "available!"};
    //example of the function
    for(int i=0;i<100;i++){
        int pos = lower_bound(f.begin(),f.end(),(double)x[i]/K)-f.begin();
        cout << dict[pos] << "\n";
    }
}
void compute(){
    int x = 1000,a = 24693, c = 3517, k = (1<<17);
    cout << fixed << setprecision(10);
    double u;
    auto run = [&]()->void{
        for(int i=0;i<30;i++){
            x = (a*x+c)%k;
        }
        u = (double)(x)/k;
    };
    vector<double> w;
    vector<double> f(3);
    f[0] = 0.2; f[1] = 0.5; f[2] = 1;
    for(int i=0;i<500;i++){
        int inc = 0;
        double val = 0;
        while(inc<4){
            run();
            val+=7; //6 to start a call + 1 to end it = 7
            int pos = lower_bound(f.begin(),f.end(),u)-f.begin();
            if(pos==0){
                val+=3;
                ++inc;
            } else if(pos==1){
                val+=25;
                ++inc;
            } else{
                run();
                double X = -12*log(1-u);
                if(X>25){
                    val+=25;
                    ++inc;
                } else{
                    val+=X;
                    break;
                }
            }
        }
        w.pb(val);
    }
    sort(w.begin(),w.end());
    double mean = 0;
    for(double p : w) mean+=p;
    mean/=500;
    double first = (w[124]+w[125])/2;
    double median = (w[249]+w[250])/2;
    double third = (w[374]+w[375])/2;
    cout << "mean is " << mean << "\n";
    cout << "first quartile is " << first << "\n";
    cout << "median quartile is " << median << "\n";
    cout << "third quartile is " << third << "\n";
    while(true){
        int z;
        cin >> z;
        if(!z){
            break;
        }
        int more;
        cin >> more;
        double tot = 0;
        for(double num : w){
            if(num<=z){
                tot+=(!more);
            } else{
                tot+=more;
            }
        }
        tot/=500;
        cout << "P(W " << (more?"> ":"<= ") << z << ") is " << tot << "\n";
    }
    for(double num : w){
        cout << num << "\n";
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    compute();
    return 0;
}
