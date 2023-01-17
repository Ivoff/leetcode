#include <cstdio>
#include <vector>

//void rotate(std::vector<int>& nums, int k)
//{
//    int size = nums.size();
//    std::vector<int>& result = *(new std::vector<int>(size));
//    for(int i = 0; i < size; i += 1)
//    {
//        result[(i + k) % size] = nums[i];
//    }
//
//    nums = result;
//}

//void reverse(std::vector<int>& nums, int begin, int end)
//{
//    int aux;
//    while(begin < end)
//    {
//        aux = nums[begin];
//        nums[begin] = nums[end];
//        nums[end] = aux;
//        ++begin;
//        --end;
//    }
//}
//
//void rotate(std::vector<int>& nums, int k)
//{
//    int size = nums.size();
//    int localK = k % size;
//
//    reverse(nums, 0, size - 1 - localK);
//    reverse(nums, size - localK, size - 1);
//    reverse(nums, 0, size - 1);
//}

void rotate(std::vector<int>& nums, int k)
{
    int size = nums.size();
    k = k % size;
    int i = 0;
    int currentIndex = 0;
    int innerIndex;
    int innerNextIndex;
    int innerAuxCurrent;
    int innerAuxNext;

    while(i < size)
    {
        innerIndex = currentIndex;
        innerAuxCurrent = nums[currentIndex];

        do
        {
            innerNextIndex = (innerIndex + k) % size;
            innerAuxNext = nums[innerNextIndex];
            nums[innerNextIndex] = innerAuxCurrent;
            innerAuxCurrent = innerAuxNext;
            innerIndex = innerNextIndex;

            ++i;
        }
        while(currentIndex != innerIndex);

        ++currentIndex;
    }
}

int main(int argc, char** argv)
{
    std::vector<int>& nums = *(new std::vector<int>({1,2,3,4,5,6,7}));
    rotate(nums, 3);

    for(int i : nums)
    {
        printf("%d\n", i);
    }

    return 0;
}