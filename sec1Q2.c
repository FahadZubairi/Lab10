//Write a recursive function that takes a string as input and returns the reversed string.
#include<stdio.h>
#include<string.h>
void reversestring(char str[],int start,int end){
     if (start >= end) {
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reversestring(str, start + 1, end - 1);
}

int main(){
    char str[20];
    printf("Enter a string: ");
    fgets(str,20,stdin);
    str[strcspn(str,"\n")] = '\0';
    int length = strlen(str);
    reversestring(str,0,length -1);
    printf("The reversed string is %s",str);
    return 0;
}