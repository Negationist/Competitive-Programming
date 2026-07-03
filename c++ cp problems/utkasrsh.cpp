int n,q,m,k;
    cin >> n >> q >> m >> k;
    vector<vector<mint>> hashes(n);
    for(int i=0;i<n;i++){
        string s; cin >> s;
        hashes[i] = get_hash(s);
        /*for(auto temp : hashes[i]){
            cout << temp.x << " ";
        }*/
        cout << "\n";
    }
    while(q--){
        string s; cin >> s;
        vector<mint> cur_hash = get_hash(s);
        int ans = 0;
        for(int i=0;i<n;i++){
            int l = 1, cnt = 0;
            while(l<=n && cnt<k && hash_interval(l,m,hashes[i]).x != hash_interval(l,m,cur_hash).x){
                int lo = l, hi = m;
                while(lo<=hi){
                    int mid = lo+(hi-lo)/2;
                    int x = hash_interval(l,mid,hashes[i]).x, y = hash_interval(l,mid,cur_hash).x;
                    if(x!=y){
                        hi = mid-1;
                    } else{
                        lo = mid+1;
                    }
                }
                cnt++;
                l = lo+1;
            }
            if(cnt<=k){
                ++ans;
            }
        }
        cout << ans << "\n";
    }