#include <bits/stdc++.h>

using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            if (s[l] == s[r - 1]) {
                if (s[l + 1] == s[r])
                    return l;
                else
                    return r;
            }
            else
                return l;
        }
    }
    return -1;
}

int main()
{
    string s;
    int n = 0;
    cin >> n;
    while (n--) {
        cin >> s;
        cout << palindromeIndex(s) << endl;
    }
    return 0;
}
