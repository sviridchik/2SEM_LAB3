//
// Created by victoria Sviridchik on 2020-03-13.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>

int from_str_to_int1(const char s[125]) {
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

int iosif(int n, int m, int circle[]){
    int i, index = 0,j = 0, count_alive = 0,count=0,balance =0;
    count_alive = n;

    for (i = 0; i < n; i++) {
        circle[i] = 1;
    }
    while (count_alive>1){
        //index = start;
        balance = m%count_alive;
        if( balance== 0){
            balance = count_alive;
        }
        while (1){
            if(circle[index]!=0){
                count++;
            }
            if(count>=balance){
                break;
            }
            index= (index+1)%n;
        }
        circle[index] -=1;
        count_alive--;
        count = 0;
    }
    for (i = 0; i <= n; i++) {
        //printf("%d:  %d\n ",i,circle[i]);
        if(circle[i]!=0){
            return i+1;
            // printf("The answer is:  %d",i+1);

        }
    }
}


//check krainie case

int task1() {
    int n = 8, m=0, i, index = 0,j = 0,answer,temp;
    printf("%s","Enter amount of people: \n");
    char tmp[125];
    scanf("%s",tmp);
    n = from_str_to_int1(tmp);
    char tmp2[125];

    printf("Do you want to enter number of the victum?(0-no,1-yes)\n");
    scanf("%d",&answer);
    int *circle;
    circle = (int *) malloc(n * sizeof(int));
    if(answer== 1) {
        printf("%s","Enter number of the victum: \n");
        scanf("%s",tmp2);
        m = from_str_to_int1(tmp2);



        printf("This player stay alive: %d", iosif(n, m, circle));

    } else if(answer==0){
        m=1;
        while (1){
            temp = iosif(n, m, circle);
            if(temp == 1){
                printf("First player stay alive with number of the victum:  %d\n",m);
                break;
            } else{
                m++;
            }
        }
    } else{
        printf("Wrong answer!");
    }
    free(circle);



//while (1){
//    //
//
//}


    return 0;
}