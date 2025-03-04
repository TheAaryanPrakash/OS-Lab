#include<stdio.h>
//Write a program in C to find the sum of the left diagonals of a matrix.
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
    int sum=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(i==j){
                sum+=m[i][j];
            }
        }
    }
    printf("The Sum is: %d",sum);
}
