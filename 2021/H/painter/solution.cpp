#include <bits/stdc++.h>

using namespace std;

set<char> yellow = {'Y', 'O', 'G', 'A'};
set<char> red = {'R', 'O', 'P', 'A'};
set<char> blue = {'B', 'P', 'G', 'A'};
vector<set<char>> colors = {yellow, red, blue};

int solve(string painting) {
    int total = 0;
    // O(1) iterations since number of base colors constant
    for (set<char> color : colors) {
        bool stroke = false;
        // O(n) to iterate through painting
        for (char c : painting) {
            if (color.count(c) > 0 && !stroke) {
                stroke = true;
                total++;
            } else if (color.count(c) == 0 && stroke) {
                stroke = false;
            }
        }
    }
    return total;
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int n;
        string p;
        cin >> n >> p;
        int res = solve(p);
        cout << "Case #" << i << ": " << res << endl;
    }
}
