#include <cstdio>
#include <vector>

void reverseString(std::vector<char>& s)
{
    int begin = 0;
    int end = s.size() - 1;
    char aux;

    while(begin < end)
    {
        aux = s[begin];
        s[begin] = s[end];
        s[end] = aux;
        ++begin;
        --end;
    }
}

int main(int argc, char** argv)
{
    std::vector<char> s = std::vector<char>({'h','e','l','l','o'});
    reverseString(s);

    for(char c : s)
    {
        printf("%c ", c);
    }
    printf("\n");

    return 0;
}
