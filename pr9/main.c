#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int min_steps(int x, int y) {
    // ����������� ������ dp
    int dp[y + 1];
    for (int i = 0; i <= y; ++i) {
        dp[i] = INT_MAX;
    }
    dp[x] = 0;

    // ���������� ������ dp
    for (int i = x; i <= y; ++i) {
        if (dp[i] != INT_MAX) {
            if (i + 1 <= y) {
                dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            }
            if (i * 2 <= y) {
                dp[i * 2] = min(dp[i * 2], dp[i] + 2);
            }
            if (i * 3 <= y) {
                dp[i * 3] = min(dp[i * 3], dp[i] + 3);
            }
        }
    }

    return dp[y];
}

int main() {
    int x, y;

    // ��� ������� x �� y
    scanf("%d %d", &x, &y);

    // ���������� �� ��������� �������� ������� �����
    int result = min_steps(x, y);
    printf("%d\n", result);

    return 0;
}
