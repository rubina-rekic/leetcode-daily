#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<string> s1_candidates = get_candidates(s1);
        vector<string> s2_candidates = get_candidates(s2);

        set<string> seen;
        for (vector<string>::size_type i = 0; i < s1_candidates.size(); ++i) {
            seen.insert(s1_candidates[i]);
        }

        for (vector<string>::size_type i = 0; i < s2_candidates.size(); ++i) {
            if (seen.find(s2_candidates[i]) != seen.end()) {
                return true;
            }
        }

        return false;
    }

private:
    vector<string> get_candidates(string s) {
        vector<string> res;
        res.push_back(s);

        string c1 = s;
        swap(c1[0], c1[2]);
        res.push_back(c1);

        string c2 = s;
        swap(c2[1], c2[3]);
        res.push_back(c2);

        string c3 = s;
        swap(c3[0], c3[2]);
        swap(c3[1], c3[3]);
        res.push_back(c3);

        return res;
    }
};