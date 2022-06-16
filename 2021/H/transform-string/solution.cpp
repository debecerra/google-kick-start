#include <bits/stdc++.h>

using namespace std;

const int INF = 100000;

int left(int i) {
    return ((i - 1) + 26) % 26;
}

int right(int i) {
    return (i + 1) % 26;
}

int solve(string s, string t) {
    vector<int> dist_from_t(26, INF);
    queue<int> q;

    // O(1) since alphabet has 26 characters
    for (char c : t) {
        dist_from_t[c - 'a'] = 0;
        q.push(c - 'a');
    }

    // O(1) since every item in t will be pushed into queue at most once
    while (q.size() > 0) {
        int i = q.front();
        q.pop();

        if (dist_from_t[left(i)] > dist_from_t[i] + 1) {
            dist_from_t[left(i)] = dist_from_t[i] + 1;
            q.push(left(i));
        } 

        if (dist_from_t[right(i)] > dist_from_t[i] + 1) {
            dist_from_t[right(i)] = dist_from_t[i] + 1;
            q.push(right(i));
        }
    }

    // O(|s|)
    int total = 0;
    for (char c : s) {
        total += dist_from_t[c - 'a'];
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s, t;
        cin >> s >> t;
        int res = solve(s, t);
        cout << "Case #" << i << ": " << res << endl;
    }
}
