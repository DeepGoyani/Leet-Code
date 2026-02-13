class Solution {
public:
    int maxFreqSum(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int maxFreqVowel = 0,maxFreqCons=0;
        vector<int> mp(26,0);
        for(auto &ch:s){
            if(vowels.find(ch)!=vowels.end()) {
                maxFreqVowel=max(maxFreqVowel,++mp[ch-'a']);
            }else{
                maxFreqCons=max(maxFreqCons,++mp[ch-'a']);
            }
        }
        return maxFreqVowel + maxFreqCons;
    }
};