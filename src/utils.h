#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <map>

std::map<int, std::string> keyboard = {
    {0, ""},
    {1, ""},
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"}
};

/* The function return partial permutation of possible word,
 * which relevant to the input numbers as T9 keyboard
 * Usage:
 *       std::vector<int> v{3, 4};
 *       std::vector<std::string> res;
 *       permutation(v, res);
 * So this case we get vector of 9 elements, stored at res vector.
 * The result vector will contain: "dg", "dh", "di", "eg", "eh", "ei", "fg", "fh", "fi"
 */
void permutation(std::vector<int> numbers,
                 std::vector<std::string> &result,
                 std::string str = "",
                 size_t lvl = 0)
{
    if (numbers.size() == lvl) {
       result.push_back(str);
       return;
    }

    std::string chars = keyboard[numbers.at(lvl)];
    for (auto &ch : chars) {
        permutation(numbers, result, str + ch, lvl+1);
    }
}

/* The function is overhead the permutation() which decribed above
 * Usage:
 *       std::vector<int> v{3, 4};
 *       std::vector<std::string> res = permutation(v);
 */
std::vector<std::string> permutation(std::vector<int> numbers)
{
    std::vector<std::string> res;
    permutation(numbers, res);
    return res;
}

#endif // UTILS_H
