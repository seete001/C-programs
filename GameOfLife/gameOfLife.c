/*
 * Code Script of Game Of Life a simple programming practice working with matrix and nested loops 
*/

//including stdio.h as a main library and stdlib for rand func

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>


//draw function to first make them visual on the screen
void draw(void *u ,int h, int w){

    char(*world)[w] = u;
    printf("\33[H");
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            printf(world[y][x] ? "@" : " ");
        }
        printf("\n");
    }
}


// creating evolution function to make the game alivei
void evolution(void *u, int w, int h){

    
    char(*world)[w] = u;
    //declaring a copy trying to avoid mistakes by counting
    char new[h][w];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
        
            int lives = 0;
            for(int x = i - 1; x <= i + 1; x++){
                for(int y = j - 1; y <= j; y++){
                    if (world[(x + h) % h][(y + w) % w])
                        lives++;
                }
            }
            if(world[i][j]) lives--;

            new[i][j] = (lives == 3 || lives == 2 && world[i][j]);
        }
    }
//make the original world from the copy of that
    for(int x = 0; x < h; x++){
        for(int y = 0; y < w; y++){
            world[x][y] = new[x][y];
        }    
    }
}


/* the main function where we try to build the first world and declare the height and width of it, then we put the above finctions draw and evolution in the while loop with tautolgical condition to let the program live, besides we added a usleep to control the flow for visualization.*/

int main(){

    printf("Welcome to the Game of Life!\nWould you like to start?(y,n)");
    char ans[8];
    fgets(ans, sizeof(ans), stdin);
    if (ans[0] == 'n'){
        printf("okay, bye :)");
        return 0;
    }
    int w = 30;
    int h = 30;
    char world[w][h];

    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            world[i][j] = rand() < RAND_MAX / 10 ? 1 : 0;
    
    while(1){
    draw(world, h, w);
    evolution(world, h, w);
    usleep(1000000);
    }

    return 0;
        }
    }
}
