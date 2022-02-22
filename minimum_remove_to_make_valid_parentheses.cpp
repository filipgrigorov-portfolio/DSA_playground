#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

std::string minRemoveToMakeValid(std::string s) {
    // find 1st of ) then count ( before; take the last one of ( before
    // if no matches are found -> replace ) with ' '
    // else replace the pair ( and ) with ' '
    // repeat until we find no more pairs (end of string)
    
    // replace remaining ( with ' ' and fill in the indices of the found pairs
    // remove ' '

    std::vector<std::pair<int, int>> found;
    while (1) {
        std::pair<int, int> match(-1, -1);
        
        // find )
        for (auto i = 0; i < s.size(); ++i) {
            if (')' == s[i]) {
                match.second = i;
                break;
            }
        }

        // if no ) is found
        if (match.second == -1) {
            for (auto i = 0; i < s.size(); ++i) {
                // clean leftovers
                if (s[i] == '(') {
                    s[i] = ' ';
                }
            }

            for (const auto& match : found) {
                s[match.first] = '(';
                s[match.second] = ')';
            }

            // clean (, if any
            // clean ' ', if any
            /*for (auto i = 0; i < s.size(); ++i) {
                // clean leftovers
                if (s[i] == ' ') {
                    s.erase(i, 1);
                }
            }*/

            s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

            /*if (std::count(s.begin(), s.end(), ' ') == s.size()) {
                return "";
            }*/

            return s;
        }

        // find (
        std::vector<int> found_left_parentheses;
        for (auto i = 0; i < match.second; ++i) {
            if ('(' == s[i]) {
                found_left_parentheses.push_back(i);
            }
        }

        // if no ( is found
        if (found_left_parentheses.empty()) {
            s[match.second] = ' ';
        } else {
            match.first = found_left_parentheses.back();
            s[match.first] = ' ';
            s[match.second] = ' ';
            found.push_back(match);
        }
    }
}

int main(void)
{
    std::vector<std::string> test_cases = {
        "a(b(c(d)e)",
        "lee(t(c)o)de)",
        "a)b(c)d",
        "))((",
        "())()((("
    };

    for (auto idx = 0; idx < test_cases.size(); ++idx) {
        std::string filtered = minRemoveToMakeValid(test_cases[idx]);
        std::cout << "\"" << test_cases[idx] << "\"" << " -> " << "\"" << filtered << "\"" << std::endl;
    }

    return 0;
}
