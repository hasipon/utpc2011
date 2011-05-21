#include <iostream>
#include <vector>
using namespace std;

struct edge { int to, cap, cost, rev; };

const int MAX_V = 20010;
const int INF = 1<<16;

int V;
vector<edge> G[MAX_V];
long long dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost) {
	//cerr << from << " " << to << " " << cap << " " << cost << endl;
	G[from].push_back((edge){to, cap, cost, G[to].size()});
	G[to].push_back((edge){from, 0, -cost, G[from].size()-1});
}

long long min_cost_flow(int s, int t, int f) {
	long long res = 0;
	while (f > 0) {
		fill(dist, dist+V, 1LL<<60);
		dist[s] = 0;
		bool update = true;
		while (update) {
			update = false;
			for (int v = 0; v < V; v++) {
				if (dist[v] == 1<<29) continue;
				for (int i = 0; i < G[v].size(); i++) {
					edge& e = G[v][i];
					if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}
		}
		if (dist[t] == 1LL<<60) return 0;
		
		int d = f;
		for (int v = t; v != s; v = prevv[v]) {
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += d * dist[t];
		for (int v = t; v != s; v = prevv[v]) {
			edge& e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}

int main() {
	int M, N, K;
	cin >> M >> N >> K;
	vector<int> w(N);
	for (int i = 0; i < N; ++ i) {
		cin >> w[i];
	}
	vector<int> a;
	for (int i = 0; i < K; ++ i) {
		int ai;
		cin >> ai;
		-- ai;
		if (i == 0 || ai != a.back()) a.push_back(ai);
	}
	
	long long r = 0;
	vector<int> b(N, -1);
	vector<pair<int,pair<int,int> > > c;
	for (int i = 0; i < a.size(); ++ i) {
		r += w[a[i]];
		if (b[a[i]] >= 0) {
			c.push_back(make_pair(w[a[i]], make_pair(b[a[i]], i)));
		}
		b[a[i]] = i+1;
	}
	
	V = a.size()+1;
	for (int i = 0; i < a.size(); ++ i) {
		add_edge(i, i+1, M+1, INF);
	}
	for (int i = 0; i < c.size(); ++ i) {
		int s = c[i].second.first;
		int t = c[i].second.second;
		add_edge(s, t, 1, (t-s)*INF-c[i].first);
	}
	
	r -= (long long)(M-1)*a.size()*INF - min_cost_flow(0, a.size(), M-1);
	cout << r << endl;
}
