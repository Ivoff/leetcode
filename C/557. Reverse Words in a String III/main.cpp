#include <cstdio>
#include <string>

std::string reverseWords(std::string s)// copy here
{
    int begin = 0;
    int end;

    for(int i = 0; i <= s.size(); i += 1)
    {
        if (s[i] == ' ' || i == s.size())
        {
            end = i - 1;
            while(begin < end)
            {
                std::swap(s[begin], s[end]);
                ++begin;
                --end;
            }
            begin = i + 1;
        }
    }

    return s;
}

int main(int argc, char** argv)
{
    std::string s = "Let's take LeetCode contest";
    printf("%s\n", reverseWords(s).c_str());

    return 0;
}
