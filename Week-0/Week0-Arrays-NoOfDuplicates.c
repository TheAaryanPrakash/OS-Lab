#include<stdio.h>
//Write a program in C to count the total number of duplicate elements in an array.
void main(){
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("\nEnter Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    int count=0;
    for(int i=0;i<n;i++){
        int isDuplicate=0;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                isDuplicate=1;
                break;
            }
        }
        if(isDuplicate) continue;
        int occurrences=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                occurrences++;
            }
        }
        if(occurrences>1){
            count++;
        }
    }
    printf("\nNumber of Duplicate Elements: %d\n", count);
}
