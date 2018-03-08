// https://www.hackerrank.com/contests/world-codesprint-8/challenges/climbing-the-leaderboard/submissions/code/1306405882

using namespace std;

vector <int> climbingLeaderboard(vector <int> scores, vector <int> alice) {
	vector <int> result;

	sort(begin(scores), end(scores), greater<int>());
	scores.erase(unique(begin(scores), end(scores)), end(scores));

	auto locate = [](vector <int>& _scores, int _newScore) {
		auto itr = lower_bound(begin(_scores), end(_scores), _newScore, greater<int>());
		return distance(begin(_scores), itr) + 1;
	};

	for (auto newScore : alice)
	{
		result.push_back(locate(scores, newScore));
	}

	return result;
}

int main() {
	int n;
	cin >> n;
	vector<int> scores(n);
	for (int scores_i = 0; scores_i < n; scores_i++) {
		cin >> scores[scores_i];
	}
	int m;
	cin >> m;
	vector<int> alice(m);
	for (int alice_i = 0; alice_i < m; alice_i++) {
		cin >> alice[alice_i];
	}
	vector <int> result = climbingLeaderboard(scores, alice);
	for (ssize_t i = 0; i < result.size(); i++) {
		cout << result[i] << (i != result.size() - 1 ? "\n" : "");
	}
	cout << endl;


	return 0;
}
