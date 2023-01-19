#include <cstdio>
#include <vector>

//int search(std::vector<int>& numbers, int begin, int target)
//{
//    int end = numbers.size() - 1;
//    int middle = -1;
//
//    while (begin <= end)
//    {
//        middle = begin + (end - begin) / 2;
//        if (numbers[middle] == target)
//        {
//            return middle;
//        }
//        if (numbers[middle] < target)
//        {
//            begin = middle + 1;
//        }
//        else
//        {
//            end = middle - 1;
//        }
//    }
//
//    return -1;
//}
//
//std::vector<int> twoSum(std::vector<int>& numbers, int target)
//{
//    int second;
//    for(int i = 0; i < numbers.size(); i += 1)
//    {
//        second = search(numbers, i + 1, target - numbers[i]);
//        if (second == -1)
//            continue;
//        return std::vector<int>({i + 1, second + 1});
//    }
//
//    return {};
//}

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
    int begin = 0;
    int end = numbers.size() - 1;
    int aux;

    while(begin < end)
    {
        aux = numbers[begin] + numbers[end];
        if (aux == target)
        {
            return std::vector<int>({begin + 1, end + 1});
        }
        else if (aux > target)
        {
            --end;
        }
        else
        {
            ++begin;
        }
    }

    return{};
}

int main(int argc, char** argv)
{
    std::vector<int> numbers = std::vector<int>({2,3,4});
    std::vector<int> result = twoSum(numbers, 6);

    for(int i : result)
    {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
