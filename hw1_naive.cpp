#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;
const int n_ = 1e7 + 100;
int n, m, s, t, a, b, c, d, x, y;
char S[n_], T[n_];
void solve() {

	FILE* sf, * tf, * rf;
	sf = fopen("string.txt", "r");
	tf = fopen("pattern.txt", "r");
	if (sf != NULL && tf != NULL) {
		fgets(S, n_, sf);
		fgets(T, n_, tf);
		n = strlen(S); m = strlen(T);
		if (S[n - 1] == '\n')n--;
		if (T[m - 1] == '\n')m--;
		vector<int>ans;
		rf = fopen("result_naive.txt", "w");
		cout << "Result saved to result_naive.txt" << '\n';
		for (int i = 0; i < n; i++) {
			a = 1;
			for (int j = 0; j < m; j++) {
				if (S[i + j] != T[j]) {
					a = 0;
					break;
				}
			}
			if (a)ans.push_back(i);
		}
		fprintf(rf, "%d\n", (int)ans.size());
		for (int i = 0; i < (int)ans.size(); i++)fprintf(rf, "%d ", ans[i]);
		fprintf(rf, "\n");
		fclose(rf);
	}
	else cout << "The string file does not exist" << '\n';
	if (sf)fclose(sf);
	if (tf)fclose(tf);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int tc = 1;
	while (tc--)solve();
	return 0;
}
