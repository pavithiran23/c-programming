#include<stdio.h>
int countev(int size,int arr[]){
    int count=0;
    for(int j=0; j<size; j++){
        if(arr[j]%2==0){
            count++;
        }
    }
    return count;
}
int main(){
    int num;
    scanf("%d",&num);
    int arr[num];
    for(int i=0; i<num; i++){
        scanf("%d",&arr[i]);
    }
    int eve=countev(num,arr);
    printf("%d",eve);
}
