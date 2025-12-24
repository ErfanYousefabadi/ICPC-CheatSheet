priority_queue <pll, vector<pll>, greater<pll>> pq;

memset(dis, 63, sizeof dis);
dis[1] = 0;
pq.push({0, 1});
while (pq.size()) {
    int v = pq.top().S;
    pq.pop();
    if (mark[v]) continue;
    mark[v] = true;
    for (auto u: adj[v])
    if (dis[u.F] > dis[v] + u.S) {
        dis[u.F] = dis[v] + u.S;
        pq.push({dis[u.F], u.F});
    }
}