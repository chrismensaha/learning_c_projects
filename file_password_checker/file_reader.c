#include "password-checker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    Password* password=malloc(STARTING_SIZE*sizeof(password));
    char* str=malloc(STARTING_SIZE*sizeof(char));
    FILE *file = fopen("initial.txt","r");
    

    
    if (file==NULL){
        printf("Error Opening File!");
        return 1;
    }

   
    fgets(str,STARTING_SIZE,file);
    str[strcspn(str, "\n")] = 0;
    password_checker(str,password);

    FILE *file_ptr = fopen("filtered.txt","w");
    for (int i=0;file_ptr!=NULL;i++){
        fprintf(file_ptr,"%s\n",str);
    }
    
    
    char ch;
    while (( ch = fgetc(file)) != EOF){
    putchar(ch);
    }

    fclose(file);
    return 0;
}