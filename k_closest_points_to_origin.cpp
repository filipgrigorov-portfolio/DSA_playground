#include <iostream>
#include <random>
#include <vector>

using Pnt = std::vector<int>;
using Vec = std::vector<Pnt>;

int sqrtDistToOrigin(const Pnt& pnt) {
    return pnt.front() * pnt.front() + pnt.back() * pnt.back();
}

bool isBiggerOrEqual(const Pnt& pnt1, const Pnt& pnt2) {
    return sqrtDistToOrigin(pnt1) >= sqrtDistToOrigin(pnt2);
}

bool isSmallerOrEqual(const Pnt& pnt1, const Pnt& pnt2) {
    return sqrtDistToOrigin(pnt1) <= sqrtDistToOrigin(pnt2);
}

int rand(int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(low, high);
    return dist(gen);
}

void quicksort(Vec& pnts, Vec& sorted) {
    // Base case
    if (pnts.size() == 2) {
        if (isBiggerOrEqual(pnts[0], pnts[1])) {
            std::swap(pnts[0], pnts[1]);
        }
        sorted.push_back(pnts[0]);
        sorted.push_back(pnts[1]);
        return;
    }

    int pvt = pnts.size() -1;

    if (pnts.size() == 1) {
        sorted.push_back(pnts[0]);
        return;
    }

    if (pnts.empty()) {
        return;
    }

    Vec left, right;
    Pnt pvt_pnt = pnts[pvt];
    for (auto idx = 0; idx < pvt; ++idx) {
        if (isBiggerOrEqual(pnts[idx], pvt_pnt)) {
            right.push_back(pnts[idx]);
        }
        
        if (isSmallerOrEqual(pnts[idx], pvt_pnt)) {
            left.push_back(pnts[idx]);
        }
    }

    quicksort(left, sorted);
    sorted.push_back(pnts[pvt]);
    quicksort(right, sorted);
}

void quicksort_int(std::vector<int>& nums, std::vector<int>& sorted) {
    // Base case
    if (nums.size() == 2) {
        if (nums[0] > nums[1]) {
            std::swap(nums[0], nums[1]);
        }
        sorted.push_back(nums[0]);
        sorted.push_back(nums[1]);
        return;
    }

    int pvt = nums.size() -1;

    if (nums.size() == 1) {
        sorted.push_back(nums[0]);
        return;
    }

    std::vector<int> left, right;
    int pvt_num = nums[pvt];
    for (auto idx = 0; idx < pvt; ++idx) {
        if (nums[idx] >= pvt_num) {
            right.push_back(nums[idx]);
        }
        
        if (nums[idx] <= pvt_num) {
            left.push_back(nums[idx]);
        }
    }

    quicksort_int(left, sorted);
    sorted.push_back(nums[pvt]);
    quicksort_int(right, sorted);
}

Vec kClosest(Vec& pnts, int k) {
    Vec closest;
    
    // Sort by distance (O[n2] to O[nlogn])
    quicksort(pnts, closest);
    
    // Take k closest (sorted already) (O[k])
    if (k > pnts.size() - 1) {
        return closest;
    }

    return Vec(closest.cbegin(), closest.cbegin() + k);
}

int main()
{
    Vec pnts = {
        { 1, 3 },
        { 2, 1 },
        { -1, -1 },
        { 4, -3 }
    };

    /*std::vector<int> nums = {9, -3, 5, 2, 6, 8, -6, 1, 3};
    std::vector<int> sorted;
    quicksort_int(nums, sorted);*/
    /*Vec sorted;
    quicksort(pnts, sorted);

    for (const auto& pnt : sorted) {
        std::cout << "(" << pnt.front() << ", " << pnt.back() << ") = " << sqrtDistToOrigin(pnt) << std::endl;
    }*/

    int k = 3;
    auto closest = kClosest(pnts, k);

    for (const auto& pnt : closest) {
        std::cout << "(" << pnt.front() << ", " << pnt.back() << ") = " << sqrtDistToOrigin(pnt) << std::endl;
    }

    return 0;
}
