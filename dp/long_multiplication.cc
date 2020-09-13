#include <bits/stdc++.h>
using namespace std;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class LongMulitply {
  public:
    void add(vi a1, vi a2, vi& res) {
        int s = min(a1.size(), a2.size());
        if (a1.size() > a2.size()) {
            res.resize(a1.size());
            res.assign(a1.begin(), a1.end());
            int j = a1.size() - 1;
            for (int i = s - 1; i >= 0; i--) {
                res[j] = res[j] + a2[i];
                if (res[j] >= 10) {
                    int car = res[j] / 10;
                    res[j] %= 10;
                    res[j - 1] += car;
                }
                j--;
            }
        }
        else {
            res.resize(a2.size());
            res.assign(a2.begin(), a2.end());
            int j = a2.size() - 1;
            for (int i = s - 1; i >= 0; i--) {
                res[j] = res[j] + a1[i];
                if (res[j] >= 10) {
                    int car = res[j] / 10;
                    res[j] %= 10;
                    res[j - 1] += car;
                }
                j--;
            }
        }
               
    }
    void multiply(vi m1, vi m2, vi& res) {
        int s = max(m1.size(), m2.size());
        res.resize(2 * s);
        vvi temp;
        temp.resize(m2.size());
        int c = 0;
        for (int i = m2.size() - 1; i >= 0; i--) {
            temp[c].resize(2 * s);
            temp[c].assign(2 * s, 0);
            int t = (2 * s) - c - 1;
            for (int j = m1.size() - 1; j >= 0; j--) {
                int mul = (m2[i] * m1[j]) + temp[c][t];
                if (mul >= 10) {
                    int mul_t = mul % 10;
                    temp[c][t] = mul_t;
                    mul = mul / 10;
                    temp[c][t-1] = mul;
                } else {
                    temp[c][t] = mul;
                }
                res[t] += temp[c][t];
                if (!j) res[t-1] += temp[c][t-1];
                if (res[t] >= 10) {
                    int car = res[t] / 10;
                    res[t] %= 10;
                    res[t - 1] += car;
                }
                // for (auto i : res)
                //     printf("%d", i);
                // printf("\n");
                t--;
            }
            c++;
        }
        auto it = res.begin();
        while (it != res.end()) {
            if ((*it) == 0) it = res.erase(it);
            else break;
        }
        if (it == res.end()) {
            res.clear();
            res.push_back(0);
        }
    }
};

int main() {
    int n = 0, m = 0, k = 0;
    scanf("%d %d %d", &n, &m, &k);
    vi m1, m2, res;
    while (n > 0) {
        m1.push_back(n % 10);
        n /= 10;
    }
    std::reverse(m1.begin(), m1.end());
    while (m > 0) {
        m2.push_back(m % 10);
        m /= 10;
    }
    std::reverse(m2.begin(), m2.end());
    
    LongMulitply lm;
    lm.multiply(m1, m2, res);
    for (auto i : res)
        printf("%d", i);
    printf("\n");
    lm.add(m1, m2, res);
    for (auto i : res)
        printf("%d", i);
    printf("\n");
    return 0;
}