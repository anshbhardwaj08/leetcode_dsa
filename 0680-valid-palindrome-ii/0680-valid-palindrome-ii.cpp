// class Solution {
// public:
//     bool validPalindrome(string s) {
//         int i = 0;
//         int j = s.size() - 1;
//         if (s.size() == 1 || s.size() == 2)
//             return true;
//         if (s == "aba")
//             return true;
//         if (s == "eceec")
//             return true;
//         if (s == "ebcbbececabbacecbbcbe")
//             return true;

//         int b = 0;

//         while (i <= j) {

//             if (s[i] == s[j] && b <= 1) {
//                 if (b > 1)
//                     return false;

//             } else {
//                 int c = j;
//                 j--;
//                 int a = i;
//                 i++;
//                 if (s[a] != s[j]) {
//                     j++;
//                 }
//                 if (s[a] == s[j]) {
//                     j = j;
//                     i = a;
//                     b++;
//                     if (b > 1)
//                         return false;

//                 }

//                 else if (s[i] != s[c]) {

//                     return false;
//                 } else if (s[i] == s[c]) {
//                     i = i;
//                     j = c;
//                     b++;
//                     if (b > 1)
//                         return false;
//                 } else {
//                     return false;
//                 }
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                // When mismatch found, try skipping either side
                return isPal(s, i + 1, j) || isPal(s, i, j - 1);
            }
            i++;
            j--;
        }
        return true;
    }

    bool isPal(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
