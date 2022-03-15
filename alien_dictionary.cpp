#include <bits/stdc++.h>

bool findInDict(char ch, const std::string& dict) {
    return dict.find(ch) != std::string::npos;
}

int findIdxOf(char ch, const std::string& dict) {
    return dict.find(ch);
}

void insertTo(char ch, std::string& dict, int pos) {
    dict.insert(pos, 1, ch);
}

std::string alienOrder(std::vector<std::string> &words) {
    std::string dict{words.front()};

    for (auto i = 0; i < words.size() - 1; ++i) {
        std::string w1{words[i]};
        for (auto j = i + 1; j < words.size(); ++j) {
            std::string w2{words[j]};
            size_t min_size = std::min(w1.size(), w2.size());
            for (auto k = 0; k < min_size; ++k) {
                if (w1[k] != w2[k]) {
                    if (!findInDict(w2[k], dict)) {
                        int idx = findIdxOf(w1[k], dict);
                        insertTo(w2[k], dict, idx + 1);
                    }
                }
            }
            if (w2.size() > w1.size()) {
                int start_idx = w2.size() - w1.size() - 1;
                for (auto k = start_idx; k < w2.size(); ++k) {
                    if (!findInDict(w2[k], dict)) {
                        dict += w2[k];
                    }
                }
            }
        }
    }
    return dict;
}

// O[N*N*(M + M / 2)]

/*

    input:

    latin alphabet
    order of letters -> unknown
    words sorted, lexicographically

    * lowercase
    * invalid if ab or ba
    * if invalid, return ""
    * return sorted string

    ex:

    wrt wrf er ett rftt

    wrt;wrf -> t < f
    wrt;er -> w < e
    er;ett -> r < t
    ett;rftt -> e < r

    r < t and t < f -> r < t < f
    e < r < t < f
    w < e < r < t < f

    wertf

    it 1:

    compare wrt to each else of the words as it exceeds them

    wrt - wrf
    wrt - er
    wrt - ett
    wrt - rftt

    wrf - er
    wrf - ett
    wrf - rftt

    er - ett
    er - rftt

    ett - rftt

    ------------------------------

    'wrt'

    w - w yes
    r - r yes
    t - f yes

    'wrtf'

    w - e
    r - r
    t - 

    the letters are at the same index i

    for each w, compare to next w:
        for i in min(w1.size, w2.size):
            if w1[i] != w2[i]:
                if w2[i] not in dict:
                    find the idx of w1[i] in dict and
                    insert w2[i] after w1[i] in original dict, after idx
    
        if w2.size > w1.size:
            insert at the end the rest of w2 if letters are not found in dict

        repeat until we exhaust the word comparisons
    return dict"er","ett","rftt"

            

    pseudo:

    function alienOrder(words):
        dict = words[0]
        for i=0 to N-2:
            w1 = words[i]
            for j = i + 1 to N-1:
                w2 = words[j]
                size = min(w1.size, w2.size)
                for k=0 to size - 1:
                    if w1[k] != w2[k]:
                        if w2[k] not in dict:
                            idx = findIdxOf(w1[k], dict)
                            insert(w2[k], idx + 1, dict)
                if w2.size() > w1.size:
                    if the remaining letters are not already in dict:
                        append(w2[w2.size - w1.size - 1 :], dict)
        return dict

*/

int main(void) {
    std::vector<std::string> words1 = { "wrt","wrf","er","ett","rftt" };
    std::string expected1 = "wertf";
    std::string output1 = alienOrder(words1);
    std::cout << output1 << std::endl;
    std::cout << "Same? " << (expected1 == output1) << std:: endl;

    std::vector<std::string> words2 = { "z","x" };
    std::string expected2 = "zx";
    std::string output2 = alienOrder(words2);
    std::cout << output2 << std::endl;
    std::cout << "Same? " << (expected2 == output2) << std:: endl;

    return EXIT_SUCCESS;
}
