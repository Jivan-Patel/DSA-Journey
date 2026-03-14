class Solution {
public:
    bool is_good(int n) {
        string s = to_string(n);
        if (s.length() <= 1)
            return true;
        bool inc = true, dec = true;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] <= s[i - 1])
                inc = false;
            if (s[i] >= s[i - 1])
                dec = false;
        }
        return inc || dec;
    }
    int sum_digits(long long n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    long long countFancy(long long l, long long r) {
        long long morvaxelin = l + r;
        bool good_sum[150];
        for (int i = 0; i < 150; ++i) {
            good_sum[i] = is_good(i);
        }
        vector<long long> good_numbers;
        for (int i = 1; i < (1 << 9); ++i) {
            long long num = 0;
            for (int j = 0; j < 9; ++j) {
                if (i & (1 << j)) {
                    num = num * 10 + (j + 1);
                }
            }
            good_numbers.push_back(num);
        }
        for (int i = 1; i < (1 << 10); ++i) {
            long long num = 0;
            for (int j = 9; j >= 0; --j) {
                if (i & (1 << j)) {
                    num = num * 10 + j;
                }
            }
            good_numbers.push_back(num);
        }
        sort(good_numbers.begin(), good_numbers.end());
        good_numbers.erase(unique(good_numbers.begin(), good_numbers.end()),
                           good_numbers.end());

        long long dp[18][150];
        auto solve = [&](long long R) -> long long {
            if (R == 0)
                return 0;
            string S = to_string(R);
            memset(dp, -1, sizeof(dp));
            function<long long(int, int, bool)> dfs =
                [&](int idx, int sum, bool tight) -> long long {
                if (idx == S.length()) {
                    return good_sum[sum] ? 1 : 0;
                }
                int rem_len = S.length() - idx;
                if (!tight && dp[rem_len][sum] != -1) {
                    return dp[rem_len][sum];
                }
                int limit = tight ? (S[idx] - '0') : 9;
                long long res = 0;
                for (int d = 0; d <= limit; ++d) {
                    res += dfs(idx + 1, sum + d, tight && (d == limit));
                }
                if (!tight) {
                    dp[rem_len][sum] = res;
                }
                return res;
            };
            long long ans = dfs(0, 0, true) - 1;
            for (long long x : good_numbers) {
                if (x >= 1 && x <= R) {
                    if (!good_sum[sum_digits(x)]) {
                        ans++;
                    }
                } else if (x > R) {
                    break;
                }
            }

            return ans;
        };
        return solve(r) - solve(l - 1);
    }
};