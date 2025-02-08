#include <stdio.h>
#include "puzzle.h"
// #define MAIN

void initPuzzle(Puzzle *puzzle, int grid[4][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            puzzle->grid[i][j] = grid[i][j];
            if (grid[i][j] == 0)
            {
                puzzle->empty_r = i;
                puzzle->empty_c = j;
            }
        }
}
void movePiece(Puzzle *puzzle, char direction)
{
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int dir;
    if (direction == 'U')
        dir = 0;
    else if (direction == 'D')
        dir = 1;
    else if (direction == 'L')
        dir = 2;
    else
        dir = 3;
    int new_r = puzzle->empty_r + dr[dir];
    int new_c = puzzle->empty_c + dc[dir];
    if (new_r < 0 || new_r > 3 || new_c < 0 || new_c > 3)
    {
        printf("Invalid move\n");
        return;
    }
    puzzle->grid[puzzle->empty_r][puzzle->empty_c] = puzzle->grid[new_r][new_c];
    puzzle->grid[new_r][new_c] = 0;
    puzzle->empty_r = new_r;
    puzzle->empty_c = new_c;
    for (int i = 0; i < 4; i++)
    {
        printf("%d", puzzle->grid[i][0]);
        for (int j = 1; j < 4; j++)
            printf(" %d", puzzle->grid[i][j]);
        printf("\n");
    }
    return;
}

#ifdef MAIN 
int main(void) {
    int grid[4][4] = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    Puzzle puzzle;
    initPuzzle(&puzzle, grid);
    int numMoves;
    scanf("%d", &numMoves);
    char move;
    for (int i = 0; i < numMoves; i++) {
        scanf(" %c", &move);
        movePiece(&puzzle, move);
    }
    return 0;
}
#endif