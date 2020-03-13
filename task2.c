//
// Created by victoria Sviridchik on 2020-03-13.
//

//Лабиринт. Лабиринт задан массивом a(n, n), в котором элемент a(k, m) = 0, если клетка (k, m) «проходима»,
//и a(k, m) = 1, если клетка «непроходима» (задается случайным образом). Начальное положение путника указывается
//в проходимой клетке (i, j). Путник может перемещаться по проходимым клеткам, имеющим общую сторону. Выяснить,
//может ли путник выйти из лабиринта (т.е. попасть в граничную клетку). Если да – распечатать путь.



#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

struct path{
    int x,y,index,step;
};
//const float RAND_MAX_F = RAND_MAX;
//
//float get_rand() {
//    return rand() / RAND_MAX_F;
//}



int from_str_to_int(const char s[125]) {
    if (s[0] == '-') {
        printf("%s", "Should be positive! EVERETHING\n");
        return -1;
    }
    int i = 0, sum = 0;
    while (s[i] != '\0') {
        if (s[i] <= '9' && s[i] >= '0' && sum < INT_MAX / 100) {
            sum = sum * 10 + (s[i] - '0');
            i++;
        } else {
            printf("%s", "Should be a NUMBER!\n");
            return -1;
        }
    }
    return sum;
}

int task2() {

    //const float RAND_MAX_F = RAND_MAX;
    char s1[125], s2[125];
    int n,m,count = 0,i,j,k,init_i,init_j,x1,y1,r,flag_finish=0;
    printf("Enter sizes:  \n");
    scanf("%s  %s", s1,s2);
    n = from_str_to_int(s1);
    m = from_str_to_int(s2);
    printf("Initial pos(i,j):  \n");
    scanf("%s  %s", s1,s2);
    init_i = from_str_to_int(s1);
    init_j = from_str_to_int(s2);


    int **labirint;
    labirint = (int **) malloc(n * sizeof(int *));
    for(i = 0; i < n; i++) {
        labirint[i] = (int *)malloc(m*sizeof(int));
    }


    //printf("%d  %d", n,m);
    //int labirint[n][m];

    struct path *progress;
    progress = (struct path *) malloc(n*m* sizeof(struct path));


//FILL RANDOM
    srand(time(NULL));
    for(i=0; i<n;i++){
        for(j=0;j<m;j++){
            int r = rand()%2;
            labirint[i][j] = r;
            //printf("%d   ",)
        }
    }
    for(i=0; i<n;i++){
        for(j=0;j<m;j++){
            printf("%d   ",labirint[i][j]);
        }
        printf("\n");
    }

    while (1){

        if(labirint[init_i][init_j]==1 || init_i>n ||init_j>m){
            printf("You are in a dead end or invalid data. Try again  \n");
            printf("Initial pos(i,j):  \n");
            scanf("%s  %s", s1,s2);
            init_i = from_str_to_int(s1);
            init_j = from_str_to_int(s2);
            ///CHECK
        } else{
            labirint[init_i][init_j] = 9;
            break;
        }
    }

    progress[0].x=init_i;
    progress[0].y = init_j;
    progress[0].index = -1;
    progress[0].step = 1;
    const int first_x[4] = {-1,1,0,0};
    const int first_y[4] = {0,0,-1,1};
    i = 0,j=1;

    if (init_i == 0 || init_i == n - 1 || init_j == 0 || init_j == m - 1) {
        flag_finish =1;
    }
    else{
        while (i!=j && !flag_finish) {
            for (r = 0; r < 4; r++) {
                int xx = progress[i].x + first_x[r];
                int yy = progress[i].y + first_y[r];


                if (labirint[xx][yy] == 0) {
                    progress[j].x = xx;
                    progress[j].y = yy;
                    progress[j].index = i;
                    progress[j].step = progress[i].step+1;
                    j++;
                    labirint[xx][yy] = 9;
                    if ((xx == 0 || xx == n - 1 || yy == 0 || yy == m - 1)) {
                        flag_finish = 1;
                        break;
                    }
                }
            }
            i++;
            x1 = i;
            y1 = j;
        }

    }


    for(i=0; i<n;i++){
        for(j=0;j<m;j++){
            if(labirint[i][j] == 9){
                labirint[i][j] = 0;
            } else if(labirint[i][j] == 1){
                labirint[i][j] = -1;
            }
        }
    }

    j = y1-1;
    while (j!=-1){
        labirint[progress[j].x][progress[j].y] = progress[j].step;
        j = progress[j].index;
    }

//OUT
printf("===========================================");
    if(flag_finish) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (labirint[i][j] == -1) {
                    printf("*   ");
                } else {
                    printf("%d   ", labirint[i][j]);
                }
            }
            printf("\n");
        }
    } else{
        printf("no way   ");
    }

    for(i = 0; i < n; i++) {
        free(labirint[i]);
    }
    free(labirint);
    return 0;
}