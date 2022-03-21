#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    using Cell = std::pair<int, int>;
    int count = 0;
    std::unordered_map<std::string, int> map;
    
private:
    bool isVisited(const std::unordered_map<std::string, int>& map, int row, int col) {
        return map.find(std::to_string(row) + std::to_string(col)) != map.cend();
    }

    bool isFound(std::vector<std::vector<char>>& board, std::string word, Cell cell, bool is_enabled=false) {
        if (word.empty()) {
            return true;
        }
        
        auto row = cell.first;
        auto col = cell.second;

        auto left = cell.second - 1;
        auto right = cell.second + 1;
        auto bottom = cell.first + 1;
        char ch = word[0];

        // left
        if (!isVisited(map, cell.first, left) && left >= 0 && ch == board[cell.first][left]) {
            cell = std::make_pair(cell.first, left);
            if (is_enabled)
                map.emplace(std::to_string(cell.first) + std::to_string(left), count++);
        } 
        // right
        else if (!isVisited(map, cell.first, right) && right < board[0].size() && ch == board[cell.first][right]) {
            cell = std::make_pair(cell.first, right);
            if (is_enabled)
                map.emplace(std::to_string(cell.first) + std::to_string(right), count++);
        } 
        // bottom
        else if (!isVisited(map, bottom, cell.second) && bottom < board.size() && ch == board[bottom][cell.second]) {
            cell =std::make_pair(bottom, cell.second);
            if (is_enabled)
                map.emplace(std::to_string(bottom) + std::to_string(cell.second), count++);
        }
        
        if (cell.first != row || cell.second != col) {
            return isFound(board, word.substr(1), cell);
        }
        
        return false;
    }
    
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        if (word.empty()) {
            return false;
        }

        if (board.empty()) {
            return false;
        }
        
        Cell cell{-1, -1};
        
        // O[N]
        for (auto row = 0; row < board.size(); ++row) {
            auto found_col = -1;
            for (auto col = 0; col < board[row].size(); ++col) {
                if (word[0] == board[row][col] && isFound(board, word.substr(1, 2), std::make_pair(row, col), true)) {
                    found_col = col;
                    break;
                }
            }
            
            if (found_col >= 0) {
                cell = std::make_pair(row, found_col);
                break;
            }
        }
        
        if (cell.first == -1) {
            return false;
        }
        
        if (word.size() == 1) {
            return true;
        }
        map.emplace(std::to_string(cell.first) + std::to_string(cell.second), count++);
        return isFound(board, word.substr(1), cell);
    }
};

int main(void) {
    std::vector<std::vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    std::string word{"ABCCED"};

    bool is_present = Solution().exist(board, word);
    std::cout << "? present: " << is_present << std::endl;

    return EXIT_SUCCESS;
}
