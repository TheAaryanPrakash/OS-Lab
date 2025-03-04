#include<stdio.h>
//Write a program in C to delete an element at a desired position from an array.
void main(){
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d",&n);
    int arr[n],d;
    for(int i=0; i<n;i++){
        printf("\nEnter Element %d: ",i);
        scanf("%d",&d);
        arr[i]=d;
    }
    printf("\nArray is: \n");
    for(int i=0; i<n;i++){
        printf("%d\t",arr[i]);
    }
    int pos;
    printf("\nEnter Position: ");
    scanf("%d",&pos);
    for(int i=pos;i<n;i++){
        arr[i]=arr[i+1];
    }
    n--;
    printf("Array is: \n");
    for(int i=0; i<n;i++){
        printf("%d\t",arr[i]);
    }
}
