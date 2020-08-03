#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int a[26] = {0}; int uniq = 0;
    unordered_set<int> us;
    for (int i = 0; i < s.length(); i++)
        a[s[i] - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (a[i] && us.find(a[i]) == us.end()) {
            cout << i + 'a' << " " << a[i] << endl;
            us.insert(a[i]);
            uniq++;
        }
    }
    if (uniq > 2) {
        return "NO";
    }
    else if (uniq == 2) {
        auto it = us.begin();
        int l = *it, r = *(next(it));
        int cntl = 0, cntr = 0;
        for (int i = 0; i < 26; i++) {
            if (a[i] == l)
                cntl++;
            else if (a[i] == r)
                cntr++;
        }
        if ((cntl == 1 || cntr == 1))
            return "YES";
        else
            return "NO";
    }
    return "YES";
}

int main() {
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}
