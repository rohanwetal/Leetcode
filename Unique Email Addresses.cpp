#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> normalized;

        for (const string& email : emails) {
            string local;
            bool ignore = false; 

            for (const char c : email) {
                if (c == '@') {
                    ignore = false; 
                }

                if (ignore || c == '.') {
                    continue; 
                }

                if (c == '+') {
                    ignore = true; 
                    continue;
                }

                local += c;
            }

            string atDomain = email.substr(email.find('@'));
            normalized.insert(local + atDomain);
        }

        return normalized.size();
    }
};
