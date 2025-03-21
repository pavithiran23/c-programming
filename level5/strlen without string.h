#include<stdio.h>
int strln(char a[]){
    int i=0;
    while(a[i]!='\0'){
       i++;
    }
    return i;
}
int main(){
    char a[100];
    scanf("%[^\n]s",a);
    int len=strln(a);
    printf("%d",len);
}
