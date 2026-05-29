#include <stdio.h>
void demo(){
    printf("This is an on demand statement");
}
void add(int a, int b){
    printf("%d", a*b);

}
void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int factorial(int n){
    int i, f = 1;
    for(i = 1; i <= n; i++){
    f = f * i;
    }
    return f;
}
int largest(int nums[],int count){
    int largest = nums[0];
    for(int i=1; i<count; i++){
        if(nums[i]>largest){
            largest=nums[i];
        }
    }
    return largest;
}
int sum(int nums[],int size){
    int sum=0;
    for(int i=0; i<size; i++){
        sum=sum+nums[i];
    }
    return sum;
}
int avg(int nums[],int size){
    int sum=0;
    for(int i=0; i<size; i++){
        sum=sum+nums[i];
    }
    return sum/size;
}
int indexof(int nums[],int size,int value){
    for(int i=0;i<size;i++){
        if(value==nums[i]){
            return i;
        }
    }
    return -1;
}
int lastindexof(int nums[],int size,int value){
    int index=-1;
    for(int i=0;i<size;i++){
        if(value==nums[i]){
            index=i;
        }
    }
    return index;
}
int contains(int nums[],int size,int value){
    for(int i=0;i<size;i++){
        if(value==nums[i]){
            return true;
        }
    }
    return false;
}
int smallest(int nums[],int count){
    int smallest = nums[0];
    for(int i=1; i<count; i++){
        if(nums[i]<smallest){
            smallest=nums[i];
        }
    }
    return smallest;
}
void asc(int nums[], int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(nums[j]<nums[j+1]){
                temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
}
void dsc(int nums[], int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(nums[j]>nums[j+1]){
                temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
}
void right(int nums[],int size){
    int temp=nums[size-1];
    for(int i=0; i<size-1;i-- ){
        nums[i]=nums[i-1];
    }
    nums[0]=temp;
}
void left(int nums[],int n){
    int temp=nums[0];
    for(int i=0; i<n-1;i++){
        nums[i]=nums[i+1]; 
    }
    nums[n-1]=temp;
}
int len(char* str){
    int count = 0;
    while(str[count] != '\0'){
        count++;
    }
    return count-1;
}
int compare(char* str1, char* str2){
    int res = 0;
    for (int i = 0; i < len(str1); i++){
        if(str1[i]-str2[i]==0 ){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
float sqrt(float n){
    float x=n;
    float y=1;
    float e=0.000001;

    while(x - y > e){
        x = (x + y)/2;
        y = n/x;
    }
    return x;
}
int factors(int x){
    int s;
}