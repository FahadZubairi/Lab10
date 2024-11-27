#include<stdio.h>
int sumofdigits(int num){
    if (num==0){
        return 0;
    }
        return (num%10)+ sumofdigits(num/10);

}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    int sum = sumofdigits(num); 
    printf("The sum of digits is %d ",sum);
    
}