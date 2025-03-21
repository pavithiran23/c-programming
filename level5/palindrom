#include<stdio.h>
#include<string.h>
int strln(char a[]){
    int i=0,value,b=0;
    char copy[100];
    while(a[i]!='\0'){
       i++;
    }
    for(int j=i-1; j>=0; j--){
        copy[j]=a[b];
        b++;
    }
    copy[i]='\0';
    if(strcmp(a,copy)==0){
        value=2;
    }
    else{
        value=3;
    }
    return value;
}
int main(){
    char a[100];
    scanf("%[^\n]s",a);
    int len=strln(a);
    if(len==2){
        printf("palindrom");
    }
    else if(len==3){
        printf("not a palindrom");
    }
}
