/*
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
*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;
        vector<string> keys;

        for(int i = 0; i < strs.size(); i++) {

            string s = strs[i]; // take strng and sort out each and every strng 
            sort(s.begin(), s.end());

            bool found = false;

            for(int j = 0; j < keys.size(); j++) {

                if(keys[j] == s) {
                    result[j].push_back(strs[i]);
                    found = true;
                    break;
                }
            }

            if(!found) {
                keys.push_back(s);
                result.push_back({strs[i]});
            }
        }

        return result;
    }
};
