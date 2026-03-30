class Solution {
public:
    bool checkStrings(string s, string p) {
        string se, so, pe, po;

        for(int i = 0; i < s.size(); i++) {
            if(i % 2 == 0) {
                se += s[i];
                pe += p[i];
            } else {
                so += s[i];
                po += p[i];
            }
        }

        sort(se.begin(), se.end());
        sort(so.begin(), so.end());
        sort(pe.begin(), pe.end());
        sort(po.begin(), po.end());

        return se == pe && so == po;
    }
};