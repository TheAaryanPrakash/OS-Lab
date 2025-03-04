#include <stdio.h>
//Write a program in C to find the second smallest element in an array.
void main(){
    int arr[10],d;
    for(int i=0; i<10;i++){
        printf("\nEnter Element %d: ",i);
        scanf("%d",&d);
        arr[i]=d;
    }
    printf("Array is: \n");
    for(int i=0; i<10;i++){
        printf("%d\t",arr[i]);
    }
    int b=arr[0]; //B is smallest element
    for(int i=0; i<10;i++){
        if (arr[i]<b){
            b=arr[i];
        }
    }
    printf("\nThe Smallest Element is: %d",b);
    int c;
    if(arr[0]!=b){
        c=arr[0];
    }else{
        c=arr[1];
    }
    for(int i=0; i<10;i++){
        if (arr[i]<c&&arr[i]!=b){
            c=arr[i];
        }
    }
    printf("\nThe Second Smallest Element is: %d",c);
}
