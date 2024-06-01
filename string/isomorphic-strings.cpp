class Solution {
public:
    bool is_digits(string& str) {
        for (char ch : str) {
            int v = ch; // ASCII Val converted
            if (!(ch >= 48 && ch <= 57)) {
                return false;
            }
        }

        return true;
    }
    bool isChar(char ch) {
        if (ch >= '0' && ch <= '9') {
            return false;
        }
        return true;
    }
    string replaceWithNum(string s) {
        int num = 1;
        for (int i = 0; i < s.length(); i++) {
            char temp = s[i];

            if (isChar(s[i])) {
                // replace with num all occurance
                for (int j = 0; j < s.length(); j++) {
                    if (s[j] == temp) {
                        s.replace(j, 1, to_string(num));
                    }
                }
                num++;
            }
        }
        return s;
    }
    string replaceWithChar(string s) {
        char ch = 0;
        for (int i = 0; i < s.length(); i++) {
            char temp = s[i];

            if (!isChar(s[i])) {
                for (int j = i; j < s.length(); j++) {
                    if (s[j] == temp) {
                        s[j] = ch;
                    }
                }
                ch++;
            }
        }
        return s;
    }
    bool isIsomorphic(string s, string t) {
        if (is_digits(s) && is_digits(t)) {
            s = replaceWithChar(s);
            t = replaceWithChar(t);

            if (s == t) {
                return true;
            }
            return false;
        }
        s = replaceWithNum(s);
        t = replaceWithNum(t);

        if (s == t) {
            return true;
        }
        return false;
    }
};