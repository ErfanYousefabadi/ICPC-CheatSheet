int mark[N];
void seive(int n) {
	for(int i = 2; i <= n; i++) {
		mark[i] = i;
		for(int j = i * i; j <= n; j += i)
			mark[j] = i;
	}
}
