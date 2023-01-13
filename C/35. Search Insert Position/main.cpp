#include <cstdio>
#include <vector>

int searchInsert(std::vector<int>& nums, int target)
{
    int begin = 0;
    int end = nums.size() - 1;
    int middle = -1;

    while(begin <= end)
    {
        middle = begin + (end - begin) / 2;
        if (nums[middle] == target)
        {
            return middle;
        }
        else if (begin == end)
        {
            if (nums[middle] < target)
                return middle + 1;
            else
                return middle;
        }
        else if (nums[middle] < target)
        {
            begin = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }

    return middle;
}

int main(int argc, char** argv)
{
    std::vector<int>& nums = *(new std::vector<int>({3,5,7,9,10}));
    printf("%d\n", searchInsert(nums, 8));
    return 0;
}
