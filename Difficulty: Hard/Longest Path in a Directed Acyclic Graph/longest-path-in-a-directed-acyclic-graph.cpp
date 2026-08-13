class Solution {
	public:
	vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
		// code here
		// at each edge what is the max weight that can be take from this edge
		// distance[edge] = max weight from src to that edge
		// using bfs when reach edge with cumulated weight do distance[edge] =
		// max(distance[edge],cw)
		
		vector<vector<pair<int, int>> > adj(V);
		for (vector<int> edge : edges) {
			adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
		}
		
		queue<pair<int, int>> q;
		q.push(make_pair(src, 0));
		
		vector<int> distance(V, INT_MIN);
		while (!q.empty()) {
			auto[ed, cw] = q.front();
			q.pop();
			
			if(cw <= distance[ed]) continue;
			
			distance[ed] = cw;
			
			for (pair<int, int> e : adj[ed]) {
			    if(cw + e.second <= distance[e.first]) continue;
				q.push(make_pair(e.first, cw + e.second));
			}
			
		}
		
		return distance;
	}
};