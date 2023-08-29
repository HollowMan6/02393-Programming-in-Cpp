#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int levenshteinDistance(const std::string& u, const std::string& v) {
    int m = u.size();
    int n = v.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else {
                dp[i][j] = std::min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (u[i-1] != v[j-1])});
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::string u, v;
    std::cin >> u >> v;

    int distance = levenshteinDistance(u, v);

    std::cout << distance << std::endl;

    return 0;
}
