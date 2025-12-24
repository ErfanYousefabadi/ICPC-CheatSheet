void prim(){
	fill(d, d + n, inf);
	set<pair<int,int> > s;
	for(int i = 0;i < n;i ++)
		s.insert({d[i],i});
	int v;
	while(!s.empty()){
		v = s.begin() -> second;
		s.erase(s.begin());
		for(auto p : adj[v]){
			int u = p.first, w = p.second;  
			if(d[u] > w){
				s.erase({d[u], u});
				d[u] = w;
				s.insert({d[u], u});
			}
		}
	}
}