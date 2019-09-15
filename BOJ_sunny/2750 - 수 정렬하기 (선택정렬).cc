#include <stdio.h>
int array[1001];
int main(void){
    int num,i,j,min,index,temp;
    scanf("%d",&num);
    for(i=0;i<num;i++)
        scanf("%d",&array[i]);
    for(i=0;i<num;i++){
        min=1001;
        for(j=i;j<num;j++){
            if(min>array[j]){
                min=array[j];
                index=j;
            }
        }
        temp=array[i];
        array[i]=array[index];
        array[index]=temp;
    }
    for(i=0;i<num;i++){
        printf("%d\n",array[i]);
    }
}