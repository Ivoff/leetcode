#include <cstdio>
#include <vector>

void moveZeroes(std::vector<int>& nums)
{
    int size = nums.size();
    int zeroCount = 0;

    for(int i = 0; i < size; i += 1)
    {
        if (zeroCount != 0)
        {
            nums[i-zeroCount] = nums[i];
        }

        if (nums[i] == 0)
            ++zeroCount;
    }

    for(int i = size - zeroCount; i < size; i += 1)
    {
        nums[i] = 0;
    }
}

int main(int argc, char** argv)
{
    std::vector<int> nums = std::vector<int>({0,1,0,3,12});
    moveZeroes(nums);
    for(int i : nums)
    {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
