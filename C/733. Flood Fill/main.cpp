#include <cstdio>
#include <vector>

void printImage(std::vector<std::vector<int>>& image)
{
    for(const std::vector<int>& row : image)
    {
        for(int column : row)
        {
            printf("%d ", column);
        }
        printf("\n");
    }
    printf("\n");
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
{
    if (color == image[sr][sc])
        return image;

    int aux = image[sr][sc];
    image[sr][sc] = color;

    if (sr-1 >= 0 && image[sr-1][sc] == aux)
        floodFill(image, sr-1, sc, color);
    if (sr+1 < image.size() && image[sr+1][sc] == aux)
        floodFill(image, sr+1, sc, color);
    if (sc-1 >= 0 && image[sr][sc-1] == aux)
        floodFill(image, sr, sc-1, color);
    if (sc+1 < image[sr].size() && image[sr][sc+1] == aux)
        floodFill(image, sr, sc+1, color);

    return image;
}

int main()
{
    std::vector<std::vector<int>> image = std::vector<std::vector<int>>({
        std::vector<int>({1,1,1}),
        std::vector<int>({1,1,0}),
        std::vector<int>({1,0,1})
    });

    printImage(image);

    floodFill(image, 1, 1, 2);

    printImage(image);

    return 0;
}
