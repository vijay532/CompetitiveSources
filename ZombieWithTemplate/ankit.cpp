#include <bits/stdc++.h>

#define ll long long int
#define lf double
#define sf scanf
#define pf printf
#define etc(t) scd(t);while(t--)
#define sclld(a) ll a; sf("%lld", &a)
#define scd(a) int a; sf("%d", &a)
#define sclf(a) double a; sf("%lf", &a)
#define oscd(a) sf("%d", a)
#define oslld(a) sf("%lld", a)
#define oslf(a) sf("%lf", a)
#define ptlld(a) pf("%lld\n", a)
#define ptd(a) pf("%d\n", a)
#define ptlf(a) pf("%lf\n", a)
#define sford(a, n) for(int i = 0; i<n; i++) sf("%d", a+i)
#define sforlld(a, n) for(int i = 0; i<n; i++) sf("%lld", a+i)
#define sforlf(a, n) for(int i = 0; i<n; i++) sf("%lf", a+i)
#define forl(n, i) for(int i = 0; i<n; i++)
#define forl1(n, i) for(int i = 1; i<=n; i++)
#define pb push_back
#define mp make_pair
#define u_m unordered_map
#define MAX 100005
#define MOD 1000000007

using namespace std;

typedef pair<int, int> ip;
typedef pair<ll, ll> llp;
typedef pair<lf, lf> lfp;
typedef vector< int > row;
typedef vector< ll > llrow;
typedef vector< lf > lfrow;
typedef vector< row > matrix;
typedef vector< llrow > llmatrix;
typedef vector< lfrow > lfmatrix;

int get_path(matrix &graph, int start_node, int reach_here) {
	if(start_node == reach_here)
		return 0;
	row visited(graph.size(), 0);
	visited[start_node] = -1;
	queue < int > queue;
	queue.push(start_node);
	while(! queue.empty()) {
		int elem = queue.front();
		queue.pop();
		forl(graph[elem].size(), i) {
			if(graph[elem][i] == reach_here) {
				int ans = 1;
				while( elem != start_node) {
					elem = visited[elem];
					ans++;
				}
				return ans;
			}
			if(! visited[graph[elem][i]]) {
				visited[graph[elem][i]] = elem;
				queue.push(graph[elem][i]);
			}
		}
	}
	return -1;
}

int main()
{
	etc(t) {
		scd(h);scd(k);scd(m);scd(z);scd(r);
		assert(h <= 10000 && h >= 1);
		assert(k <= 10000 && k >= 1);
		assert(z <= 10000 && z >= 1);
		assert(m <= 10000 && m >= 1);
		assert(r <= 100000 && r >= 1);
		matrix graph(10005);
		forl(r, i) {
			scd(a);scd(b);
			assert(a <= 10000 && a >= 1);
			assert(b <= 10000 && b >= 1);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		int p1 = get_path(graph, k, m);
		int p2 = get_path(graph, k, h);
		int p3 = get_path(graph, m, h);
		int p4 = 2 * get_path(graph, z, h);

		if(p1 < 0 || p2 < 0 || p3 < 0 || p4 < 0) {
			printf("-1\n");
		} else if(p1 + p3 <= p4) {
			printf("With\n");
		} else if(p2 <= p4) {
			printf("Without\n");
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
