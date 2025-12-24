priority_queue <pll, vector<pll>, greater<pll>> pq;

memset(dis, 63, sizeof dis);
dis[1] = 0;
q.push({0, 1});

while (pq.size()) {
    auto k = pq.top();
    int v = k.S;
    pq.pop();
    for (auto u: adj[v]) {
        if (dis[v] + u.S < dis[u.F]) {
            dis[u.F] = dis[v] + u.S;
            pq.push({dis[u.F], u.F});
        }
    }
}
