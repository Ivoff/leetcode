#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

bool checkInclusion(std::string s1, std::string s2)
{
    if (s1.size() > s2.size())
        return false;

    int begin = 0;
    int end = s1.size()-1;
    std::vector<int> frequenceS1 = std::vector<int>(26, 0);
    std::vector<int> frequenceWindow = std::vector<int>(26, 0);

    for(char c : s1)
        ++frequenceS1[c-'a'];

    for(int i = 0; i <= end; i += 1)
        ++frequenceWindow[s2[i] - 'a'];

    while(end < s2.size())
    {
        if(frequenceS1 == frequenceWindow)
            return true;

        --frequenceWindow[s2[begin++] - 'a'];
        if (++end < s2.size())
            ++frequenceWindow[s2[end] - 'a'];
    }

    return false;
}

int main(int agc, char** argv)
{
    printf("%d\n", checkInclusion("abcddefg", "zkkaaabddddegadebfdc"));
    return 0;
}
