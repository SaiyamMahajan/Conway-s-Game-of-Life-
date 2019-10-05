/*
 ============================================================================
 Name        : Conway's Game of Life.c
 Author      : Saiyam Mahajan
 Version     : Version 1.0
 Copyright   : Your copyright notice
 Description : Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * I kept in mind the following rules while making the following code for Performance Project:
 *
 * At each step, the number of each cells neighbors that are alive are counted, and
 * a. Any live cell with fewer than 2 live neighbors dies
 * b. Any live cell with more than three neighbors dies.
 * c. Any live cell with 2 or 3 live neighbors lives on.
 * d. Any dead cell with exactly three live neighbors becomes alive, and otherwise stays dead.
 *
 */

int main(){

    int WIDTH = 5;  // This portion specifies the width of the CGOL.
    int HEIGHT = 5;  // This portion specifies the height of the CGOL.
    int CYCLES = 3;  // This portion specifies the cycles/times the CGOL will run.

    int grid[HEIGHT][WIDTH];
    int temp[HEIGHT][WIDTH];

    int row;
    int col;
    for(row = 0; row < HEIGHT; row++){
        for(col = 0; col < WIDTH; col++){
            grid[row][col] = 0;
        }
    }

    int i;
    int x;
    int y;
    int neighbors;
    for(i = 0; i < CYCLES; i++)   // Here I used 'for' iterative statement.
    {
        for(row = 0; row < HEIGHT; row++){
            for(col = 0; col < WIDTH; col++){
                temp[row][col] = 0;
            }
        }
        for(row = 0; row < HEIGHT; row++){
            for(col = 0; col < WIDTH; col++){
                neighbors = 0;
                for(y = -1; y < 2; y++){
                    for(x = -1; x < 2; x++){
                        if(x != 0 && y != 0 && grid[(row + y) % HEIGHT][(col + x) % WIDTH] == 1)
                        {
                            neighbors++;
                        }
                    }
                }
                if(grid[row][col] == 1){
                    if(neighbors < 2 || neighbors > 3){
                        temp[row][col] = 0;
                    }else{
                        temp[row][col] = 1;
                    }
                }else if(grid[row][col] == 0){
                    if(neighbors == 3){
                        temp[row][col] = 0;
                    }else{
                        temp[row][col] = 1;
                    }
                }
            }
        }

        for(row = 0; row < HEIGHT; row++){
            for(col = 0; col < WIDTH; col++){
                grid[row][col] = temp[row][col];
                printf("%d", grid[row][col]);
            }
            printf("\n"); // For leaving a space between the next cycle
        }
        printf("\n");
    }
    printf("Author: Saiyam Mahajan"); // Author's name

    return 0;
}

/*
 *  Output: The first cycle shows all the cells are alive.
 *  After the first cycle, the rules written at the beginning of the document
 *  are followed.
 *  This is repeated till the no. of cycles entered by the user are completed.
 */
