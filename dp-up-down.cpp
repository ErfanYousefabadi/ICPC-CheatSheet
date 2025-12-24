ll n, dp[N][2];
vector <int> adj[N];

void dfs_up(int v, int p = 0) {
	for(int u : adj[v]) {
		if(u == p)
			continue;
		dfs_up(u, v);
		dp[v][0] += dp[u][0];
	}
}




void dfs_down(int v, int p = 0) {
	ll sum = 0;
	for(int u : adj[v]) {
		if(u == p)
			continue;
		sum += dp[u][0];
	}
	
	for(int u : adj[v]) {
		if(u == p)
			continue;
		dp[u][1] = dp[v][1] + sum - dp[u][0];
		dfs_down(u, v);
	}
}
