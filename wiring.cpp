// IOI 2017, day 1, wiring
#include <bits/stdc++.h>
using namespace std;
// #include "wiring.h"

// O(N^2) -> O(N) + O(N*log(N)) for sorting

const int INF = 1e9 + 5;

long long min_total_length(vector<int> r, vector<int> b) {
	vector<pair<int,int>> all;
	for(int x : r) {
		all.push_back(make_pair(x, 0));
	}
	for(int x : b) {
		all.push_back(make_pair(x, 1));
	}
	sort(all.begin(), all.end());
	int n = all.size();
	vector<long long> dp(n + 1);
	// dp[0] is for empty prefix
	// dp[1] is for first element
	// dp[n] is for all n elements
	for(int i = 0; i < n; ++i) {
		int my_x = all[i].first;
		int my_type = all[i].second;
		int single = INF; // c[i]
		for(pair<int,int> p : all) {
			if(p.second != my_type) {
				single = min(single, abs(my_x - p.first));
			}
		}
		dp[i+1] = dp[i] + single;
		
		
		// BBBBBAAAAA
		
		int cnt = 1;
		int j = i;
		while(j >= 1 && all[j-1].second == my_type) {
			--j;
			++cnt;
		}
		bool ok = true;
		for(int k = 1; k <= cnt; ++k) {
			// j-1, j-2, ..., j-cnt
			if(j - k < 0 || all[j-k].second == my_type) {
				ok = false;
				break;
			}
		}
		if(ok) {
			long long maybe = dp[i-2*cnt+1];
			for(int k = 1; k <= cnt; ++k) {
				maybe -= all[j-k].first;
				maybe += all[j-1+k].first;
			}
			dp[i+1] = min(dp[i+1], maybe);
		}
	}
	return dp[n];
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> r, b;
	for(int i = 0; i < n; ++i) {
		...
	}
		vector<int> r{1,2,3,24};
	vector<int> b{21,22,23};
	cout << min_total_length(r, b);
}
