#include <cstdio>
#include <iostream>
#include <vector>

//int search(std::vector<int>& nums, int target)
//{
//    int begin = 0;
//    int end = nums.size() - 1;
//    int middle;
//
//    while(begin <= end)
//    {
//        middle = begin + (end - begin) / 2;
//        if (nums[middle] == target)
//            return middle;
//        else if (nums[middle] < target)
//            begin = middle + 1;
//        else
//            end = middle - 1;
//    }
//
//    return end + 1;
//}

std::vector<int> sortedSquares(std::vector<int>& nums)
{
    std::vector<int>& resultVector = *(new std::vector<int>(nums.size()));
//    int closestToZeroIndex = search(nums, 0);
    int size = nums.size();
    int resultIndex = size - 1;
    int begin = 0;
    int end = size - 1;
    int auxBegin;
    int auxEnd;

    while(resultIndex >= 0)
    {
        auxBegin = nums[begin]*nums[begin];
        auxEnd = nums[end]*nums[end];

        if (auxEnd > auxBegin)
        {
            resultVector[resultIndex--] = auxEnd;
            --end;
        }
        else
        {
            resultVector[resultIndex--] = auxBegin;
            ++begin;
        }
    }

    return resultVector;
}

int main(int arc, char** argv)
{
    std::vector<int>& collection = *(new std::vector<int>({-4,-1,0,3,10}));
    for(auto i : sortedSquares(collection))
    {
        printf("%d\n", i);
    }
    return 0;
}
