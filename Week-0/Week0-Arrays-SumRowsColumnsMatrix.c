#include<stdio.h>
//Write a program in C to find the sum of rows and columns of a matrix.
void main(){
    int m[3][3];
    printf("Enter Elements of the Matrix: \n");
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            scanf("%d",&m[i][j]);
        }
    }
    printf("The Matrix is: \n");
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf("%d \t",m[i][j]);
        }
        printf("\n");
    }
    //Sum of Columns
    int sum=0;
    for(int i=0;i<3;i++){
        sum=m[0][i]+m[1][i]+m[2][i];
        printf("Sum of Column %d is: %d\n",i,sum);
    }
    for(int i=0;i<3;i++){
        sum=m[i][0]+m[i][1]+m[i][2];
        printf("Sum of Row %d is: %d\n",i,sum);
    }
}
