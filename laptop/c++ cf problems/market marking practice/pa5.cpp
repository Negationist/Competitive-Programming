#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct PushRelabel {
	struct Edge {
		int dest, back;
		ll f, c;
	};
	vector<vector<Edge>> g;
	vector<ll> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void addEdge(int s, int t, ll cap, ll rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}

	void addFlow(Edge& e, ll f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	ll calc(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		for (Edge& e : g[s]) addFlow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					addFlow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

signed main() {
    //cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int need = 0;
    vector<tuple<set<int>,int,int,int>> nodes; //{location, job, type(0 is place, 1 is worker), W}
    int b; cin >> b;
    map<string, int> place_number;
    map<string, int> job_number;
    int place_inc = 0, job_inc = 0;
    for(int i=0;i<b;i++){
        string location;
        cin >> location >> location;
        if(place_number[location] == 0){
            place_number[location] = ++place_inc;
        }
        string jobs;
        cin.ignore();
        getline(cin, jobs);
        string cur;
        for(int j=0;j<jobs.size();j++){
            if(jobs[j] == ' '){
                if(job_number[cur] == 0){
                    job_number[cur] = ++job_inc;
                }
                ++need;
                nodes.push_back({set<int>{place_number[location]}, job_number[cur], 0, -1});
                //cout << "got {" << location << ", " << cur << "}\n";
                cur.clear();
            }
            else{
                cur.push_back(jobs[j]);
            }
        }
        if(cur.size()){
            if(job_number[cur] == 0){
                job_number[cur] = ++job_inc;
            }
            ++need;
            nodes.push_back({set<int>{place_number[location]}, job_number[cur], 0, -1});
            //cout << "got {" << location << ", " << cur << "}\n";
        }
    }
    int c; cin >> c;
    for(int i=0;i<c;i++){
        string trash; cin >> trash;
        int p,w; cin >> p >> w;
        string job; cin >> job;
        if(job_number[job] == 0){
            job_number[job] = ++job_inc;
        }
        set<int> locations;
        set<string> locations_names;
        for(int j=0;j<p;j++){
            string location; cin >> location;
            if(place_number[location] == 0){
                place_number[location] = ++place_inc;
            }
            locations.insert(place_number[location]);
            locations_names.insert(location);
        }
        nodes.push_back({locations, job_number[job], 1, w});
        // cout << "got: " << "\n" << "locations: ";
        // for(string name : locations_names){
        //     cout << name << " ";
        // }
        // cout << "\n";
        // cout << "job is " << job << "\n";
        // cout << "w number is " << w << "\n";

    }
    int source = (int)nodes.size(), sink = source+1;
    auto test = [&](int days){
        PushRelabel graph((int)(nodes.size())+5);
        for(int i=0;i<nodes.size();i++){
            auto [locations1, job1, type1, w1] = nodes[i];
            if(type1 == 0){ //this is a place, connect it to to the sink
                graph.addEdge(i, sink, 1);
            } else{ //connect to the source
                graph.addEdge(source, i, w1*days);
            }
            for(int j=i+1;j<nodes.size();j++){
                auto [locations2, job2, type2, w2] = nodes[j];
                if(type1 != type2){ //must be a 0 to a 1
                    int location1 = *locations1.begin();
                    bool reachable = (locations2.find(location1) != locations2.end());
                    bool workable = (job1 == job2);
                    if(reachable && workable){
                        graph.addEdge(j, i, 1); //later one is worker
                    }
                }
            }
        }
        return graph.calc(source, sink);
    };
    int lo = 1, hi = 1e9;
    bool flag = false;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(test(mid) == need){
            flag = true;
            hi = mid-1;
        } else{
            lo = mid+1;
        }
    }
    if(flag){
        cout << lo << " days\n";
    } else{
        cout << "impossible\n";
    }
}