Sure! Here are some examples of how you can implement permutations and combinations in C++:

Permutations

To generate permutations, you can use the next_permutation function from the C++ Standard Library.

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3};

    std::sort(nums.begin(), nums.end());
    do {
        for (int num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(nums.begin(), nums.end()));

    return 0;
}

Combinations

To generate combinations, you can use a recursive approach or the std::bitset for a more elegant solution. Here’s an example using recursion:

#include <iostream>
#include <vector>

void combinations(std::vector<int>& nums, std::vector<int>& comb, int start, int k) {
    if (k == 0) {
        for (int num : comb) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = start; i <= nums.size() - k; ++i) {
        comb.push_back(nums[i]);
        combinations(nums, comb, i + 1, k - 1);
        comb.pop_back();
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    int k = 2;
    std::vector<int> comb;

    combinations(nums, comb, 0, k);

    return 0;
}

Using STL for Combinations

Alternatively, you can use the std::bitset to generate combinations:

#include <iostream>
#include <vector>
#include <bitset>

void printCombination(const std::vector<int>& nums, const std::bitset<32>& bitset) {
    for (size_t i = 0; i < nums.size(); ++i) {
        if (bitset[i]) {
            std::cout << nums[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    int k = 2;
    int n = nums.size();
    std::bitset<32> bitset;

    for (int i = 0; i < k; ++i) {
        bitset.set(i);
    }

    do {
        printCombination(nums, bitset);
    } while (std::prev_permutation(bitset.to_string().begin(), bitset.to_string().end()));

    return 0;
}


These examples should help you get started with permutations and combinations in C++. If you have any specific requirements or need further assistance, feel free to ask!

https://www.geeksforgeeks.org/permutations-and-combinations/
https://www.geeksforgeeks.org/permutation-and-combination-in-python/

