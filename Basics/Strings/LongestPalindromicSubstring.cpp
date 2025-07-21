#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int n=s.size()-1;
    int l=0;

    while (l<n) {
        if (s[l]!=s[n]) {
            return false;
        }
            l++; n--;
    }

    return true;
}

string longestPalindromicSubstring_Better(string s) {
    int n=s.size();
    if (n==0) return "";
    int start =0; int maxLen=1;

    for (int center =0; center<2*n-1;center++) {
        int l=center/2;
        int r=l+(center%2);

        while (l>=0 && r<n && s[l]==s[r] ) {
            if (r-l+1 > maxLen) {
                start =l;
                maxLen = r-l+1;
            }
            l--;r++;
        }
    }

    return s.substr(start,maxLen);

}

string longestPalindromicSubstring_Brute(string s) {
    int n=s.size(); string res= ""; int maxLen=0;
    string ans="";

    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            res += s[j];
            if (isPalindrome(res) && res.size()>maxLen) {
                ans = res;
            }
        }
    }

    return ans;
}

string longestPalindrome(string s) {
    // 1. Transform string
    string t = "^";
    for (char c : s) {
        t += "#" + string(1, c);
    }
    t += "#$";

    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;

    for (int i=1; i<n-1; i++) {
        int mirror = 2*center - i;

        if (i < right)
            p[i] = min(right - i, p[mirror]);

        // Try to expand palindrome centered at i
        while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
            p[i]++;

        // Update center and right boundary if needed
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    // Find the longest palindrome in p[]
    int maxLen=0, centerIndex=0;
    for (int i=1; i<n-1; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    // Extract from original string
    int start = (centerIndex - maxLen) / 2;  // because of added chars
    return s.substr(start, maxLen);
}


int main() {
    string  s ="babbcd";
    cout<<longestPalindromicSubstring_Brute(s);
}