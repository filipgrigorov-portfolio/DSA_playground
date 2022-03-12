#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string>

/*
    Input: n = [-1, 0, 1, 2, -1] and s = 0
    Output: ni, nj, nk s.t. ni + nj + nk = 0 and i != j != k

    naive:
        if n.size < 3:
            return []

        results <- new array
        for i <- 0 to (n.size - 1):
            triplet <- new array
            for j <- 0 to (n.size - 1):
                if j == i:
                    skip to next iteration
                for k <- 0 to (n.size - 1):
                    if k == j:
                        skip to next iteration
                    if n[i] + n[j] + n[k] == 0:
                        triplet.append(n[i])
                        triplet.append(n[j])
                        triplet.append(n[k])
            results.append(triplet)

    O[n] * O[n] * O[n] = O[n3]

    other: ni + nj = -nk

        if n is less than 3 items, return empty array

        for each item in n
            add each item in n
                see if the sum equals the negative of any item in n where none of the items are at the same index

        if n.size < 3:
            return []

        res <- new set
        for i <- 0 to n.size - 1:
            for j <- 0 t n.size - 1:
                nk <- -(ni + nj)
                binary search for such nk:
                    if found:
                        res.append(triplet)
*/

bool findIfRepeated(const std::vector<int>& triplet, const std::vector<std::vector<int>>& list) {
    for (const auto& item : list) {
        int nequals = 0;
        std::vector<int> visited_indices;
        for (auto i = 0; i < triplet.size(); ++i) {
            for (auto j = 0; j < item.size(); ++j) {
                if (item[j] == triplet[i] && std::find(visited_indices.cbegin(), visited_indices.cend(), j) == visited_indices.cend()) {
                    visited_indices.push_back(j);
                    nequals += 1;
                }
            }
        }
        
        if (nequals == 3) {
            return true;
        }
    }

    return false;
}

bool binarySearch(int x, std::vector<int>& nums) {
    /*
        divide the nums in two halves
        go recursively, until we hit a leaf, check if the leaf is equal to x
        if the leaf is equal to x, exit/return
    */
    if (nums.size() == 1) {
        return (nums.front() == x) ? true : false;
    }

    auto half_size = std::max(0, int(0.5 * (nums.size() - 1)));

    auto left = std::vector<int>(nums.cbegin(), nums.cbegin() + half_size + 1);
    if (binarySearch(x, left)) {
        return true;
    }

    if (nums[half_size] == x) {
        return true;
    }

    auto right = std::vector<int>(nums.cbegin() + half_size + 1, nums.cend());
    if (binarySearch(x, right)) {
        return true;
    }
    return false;
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    if (nums.size() < 3) {
        return std::vector<std::vector<int>>();
    }

    std::set<std::vector<int>> triplet_hashes;
    for (auto i = 0; i < nums.size(); ++i) {
        for (auto j = 0; j < nums.size(); ++j) {
            if (j == i) {
                continue;
            }

            const auto n_k = -(nums[i] + nums[j]);
            if (binarySearch(n_k, nums)) {
                std::vector<int> triplet = {
                    nums[i],
                    nums[j],
                    n_k
                };

                std::sort(triplet.begin(), triplet.end(), std::less<int>());
                triplet_hashes.insert(triplet);
            }
        }
    }

    std::vector<std::vector<int>> triplets;
    for (auto triplet : triplet_hashes) {
        std::vector<int> triple = {
            triplet[0],
            triplet[1],
            triplet[2]
        };
        triplets.push_back(triple);
    }

    std::cout << "num triplets= " << triplets.size() << std::endl;

    return triplets;
}

int main(){
    std::vector<int> n = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    auto res = threeSum(n);
    for (const auto& n : res) {
        std::cout << "[";
        for (const auto& item : n) {
            std::cout << item << " ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}
