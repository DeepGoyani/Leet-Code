class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        unordered_set<string> validBusiness = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        vector<pair<string, string>> valid;

        for (int i = 0; i < code.size(); i++) {

            // must be active
            if (!isActive[i]) continue;

            // code must not be empty
            if (code[i].empty()) continue;

            // valid business line
            if (validBusiness.find(businessLine[i]) == validBusiness.end())
                continue;

            // code validation (FIXED)
            bool ok = true;
            for (char c : code[i]) {
                if (!(isalnum(c) || c == '_')) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            valid.push_back({businessLine[i], code[i]});
        }

        // sort by businessLine, then code
        sort(valid.begin(), valid.end());

        vector<string> result;
        for (auto &p : valid) {
            result.push_back(p.second);
        }

        return result;
    }
};
