
class Solution {

    // Hash based on character frequency

    string hash(string s) {

        vector<int> generated(26, 0);


        for(int i = 0; i < s.size(); i++) {
            
            generated[s[i] - 'a']++;

        }

        string key = "";

        for(int i = 0; i < 26; i++) {
            key += to_string(generated[i]) + "#";
        }

        return key;
    }

    vector<string> arrangedValues;
    vector<vector<string>> getRes;

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        getRes.clear();
        arrangedValues.clear();

        for(int i = 0; i < strs.size(); i++) {

            string generated = hash(strs[i]);

            bool found = false;

            for(int j = 0; j < arrangedValues.size(); j++) {

                if(arrangedValues[j] == generated) {
                    getRes[j].push_back(strs[i]);
                    found = true;
                    break;
                }
            }

            if(!found) {
                arrangedValues.push_back(generated);

                vector<string> temp;
                temp.push_back(strs[i]);

                getRes.push_back(temp);
            }
        }

        return getRes;
    }
};
