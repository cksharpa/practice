#include <stdio.h>
#include <string.h>

int find(int row, int col, const char** matrix, int R, int C, const char* target, int index)
{
    if(row >= R || col >= C) return 0;
    if(matrix[row][col] == target[index]){
        if(target[index+1] == '\0') return 1;
        return find(row, col+1, matrix, R, C, target, index+1) +
               find(row+1, col, matrix, R, C, target, index+1) +
               find(row+1, col+1, matrix, R, C, target, index+1);
    }
    return 0;
}
int findWord(const char** matrix, int R, int C, const char* target)
{
    int i, j, count = 0;
    for(i = 0; i < R; ++i){
        for(j = 0; j < C; ++j){
            if(matrix[i][j] == target[0]){
                count += find(i, j, matrix, R, C, target, 0);
            }
        }
    }
    return count;
}

int main()
{
    const char* matrix[] = {
                            "wsrtgg",
                            "aachin",
                            "kchujj",
                            "ohinyq"
                           };
    const char* target = "sachin";
    printf("%s occurs %d times in the matrix\n", target,
           findWord(matrix, sizeof(matrix)/sizeof(char*), strlen(matrix[0]), target)
           );
    
    return 0;
}
