int parent[MAX_N][20];
// 2^0, 2^1, ..., 2^19

// O(log(N))

void dfs(int a) {
	for(int b : edges[a]) {
		if(b == parent[a][0]) {
			continue;
		}
		parent[b][0] = a;
		for(int k = 1; k <= 19; ++k) {
      parent[b][k] = parent[ parent[b][k-1] ][k-1];
		}
		depth[b] = depth[a] + 1;
		dfs(b);
	}
}

int lca(int a, int b) {
	if(depth[a] < depth[b]) {
		swap(a, b);
	}
	// difference = 1
	// ..., 64, 32, 16, 8, 4, 2, 1
	for(int k = 19; k >= 0; k--) {
		if(depth[a] - depth[b] >= (1 << k)) {
			a = parent[a][k];
		}
	}
	if(a == b) {
		return a;
	}
	// depth[a] == depth[b]
	for(int k = 19; k >= 0; k--) {
		if(parent[a][k] != parent[b][k]) {
			a = parent[a][k];
			b = parent[b][k];
		}
	}
	// a and b are both children of the same LCA
	return parent[a][0];
}
