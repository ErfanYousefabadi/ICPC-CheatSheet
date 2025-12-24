mt19937 Rnd;
int Rand(int l, int r)
{
    return (Rnd() % (r - l + 1) + l);
}
Rnd.seed(time(0));
// ya
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int x = rng()
