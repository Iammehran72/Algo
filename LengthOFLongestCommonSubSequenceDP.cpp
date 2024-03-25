#include <iostream>
#include <cstring>

using namespace std;

int lcsOf3(string X, string Y, string Z) {
    int m = X.length(), n = Y.length(), o = Z.length();
    int dp[m + 1][n + 1][o + 1];

    // Initialize the dp array
    memset(dp, 0, sizeof(dp));

    // Build the dp array
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= o; ++k) {
                if (X[i - 1] == Y[j - 1] && Y[j - 1] == Z[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
                }
            }
        }
    }

    return dp[m][n][o];
}

int main() {
    string X = "ABZK13";
    string Y = "CDK12A";
    string Z = "99KBC";

    cout << "Length of LCS of three sequences: " << lcsOf3(X, Y, Z) << endl;

    return 0;
}
