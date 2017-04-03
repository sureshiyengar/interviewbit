/// Problem link: https://www.interviewbit.com/problems/commutable-islands/
/// Author: Suresh Iyengar
///

/*
Essentially the problem boils down to finding a minimum spanning tree. Below is one implementation of Prim's algrithm to find MST using heap.
P.S. It is not the most optimum heap implementation. I will leave it upto you to figure it out.
*/

#include <vector>
#include <map>
#include <iostream>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

struct edge
{
	int to;
	int weight;

	public:
		edge(int t, int w)
		{
			to = t;
			weight = w;
		}
};

void MST(map<int, vector<edge>>& G)
{
	int n = G.size();
	int *dist = (int *)malloc(n * sizeof(int));
	int *prev = (int *)malloc(n * sizeof(int));
	int *visited = (int *)malloc(n * sizeof(int));

	std::fill_n(dist, n, INT_MAX);
	std::fill_n(prev, n, -1);
	std::fill_n(visited, n, 0);

	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<std::pair<int, int>>> Q;
	
	int src = 0;
	dist[src] = 0;
	Q.push(make_pair(0, src));

	while (false == Q.empty())
	{
		int u = Q.top().second;
		Q.pop();
		visited[u] = 1;

		vector<edge> edges = G[u];

		for (edge e : edges)
		{
			int v = e.to;
			int weight = e.weight;

			if (false == visited[v] && dist[v] > weight)
			{
				dist[v] = weight;
				Q.push(make_pair(dist[v], v));
				prev[v] = u;
			}
		}
	}

	size_t sum = 0;
	for (int i = 0; i < n; i++)
		sum += dist[i];

	cout << sum << endl;

	free(dist);
	free(prev);
	free(visited);
}

/*
Sample input:
5
1 2 1
2 3 4
1 4 3
4 3 2
1 3 10

Soln: 5
*/

int main()
{
	map<int, vector<edge>> G;

	int e;
	cin >> e;

	int a, b, w;

	// 1-based input, converting it to 0-based
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> w;
		a -= 1;
		b -= 1;
		G[a].emplace_back(b, w);
		G[b].emplace_back(a, w);
	}

	MST(G);

    return 0;
}

