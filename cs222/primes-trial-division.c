#include <stdio.h>

int main(){
    int count=0;
    int i=2;
    int user_input=0;
    printf("How many prime #'s? ");
    scanf("%d",&user_input);

    while (count<user_input){
        int is_prime=1;
        for (int j=2;(j*j)<=i;j++){
           if (i%j==0){ 
            is_prime = 0;
            break;
        }
    }
    if (is_prime){
        printf("Prime: %d\n",i);
        count++;
    }
    i++;
}
return 0;
}


