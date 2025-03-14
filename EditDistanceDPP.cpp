#include <iostream>

using namespace std;

int min(int x, int y, int z) {
    return min(min(x, y), z);
}

int editDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
    string str1 = "cacac";
    string str2 = "ababa";
    cout << "Edit distance between '" << str1 << "' and '" << str2 << "' is " << editDistance(str1, str2) << endl;
    return 0;
}

