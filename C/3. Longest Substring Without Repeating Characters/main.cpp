#include <cstdio>
#include <string>
#define ARRAY_SIZE 256

bool repeated(const std::pair<bool, int> currentLetters[ARRAY_SIZE], char target, int* found)
{
    *found = currentLetters[target].second;
    return currentLetters[target].first;
}

void clear(std::pair<bool, int> currentLetters[ARRAY_SIZE], int target)
{
    currentLetters[target].first = false;
    currentLetters[target].second = 0;
}

int lengthOfLongestSubstring(std::string s)
{
    std::pair<bool, int> currentLetters[ARRAY_SIZE];
    std::fill_n(currentLetters, ARRAY_SIZE, std::make_pair(false, 0));

    int begin = 0;
    int end = 0;
    int found;
    int bigger = 0;

    while(end < s.size())
    {
        while(repeated(currentLetters, s[end], &found) == false && end < s.size())
        {
            currentLetters[s[end]].first = true;
            currentLetters[s[end]].second = end;
            ++end;
        }

        currentLetters[s[end]].second = end;

        if (end - begin > bigger)
        {
            bigger = end - begin;
        }

        for(int i = begin; i <= found; i += 1)
        {
            clear(currentLetters, s[i]);
        }

        // Depois de limpar todos os caracteres entre o início da sequência
        // e o caracter repetido, adicionar o caracter repetido no array de repeditos
        // porque a instância do caracter agora está em outra posição
        currentLetters[s[end]].first = true;
        currentLetters[s[end]].second = end;

        begin = found + 1;
        ++end;
    }

    return bigger;
}

int main(int argc, char** argv)
{
    std::string s = "abcabcbb";
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}
