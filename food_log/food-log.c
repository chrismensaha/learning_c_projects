#include <stdio.h>

#define STARTING_SIZE 100

typedef struct expense{
    char* item_name;
    double price;
} Expense;

int main(){
    Expense* expense=malloc(sizeof(Expense));
    char* item_name=malloc(STARTING_SIZE*sizeof(char));
    char* file_name=malloc(STARTING_SIZE*sizeof(char));
    printf("File Name: ");
    fgets(file_name,STARTING_SIZE,stdin);
    file_name[strcspn(file_name, "\n")]=0; 

    char* file_line=malloc(STARTING_SIZE*sizeof(char));
    FILE* file=fopen(file_name,"w");

    if (file==NULL){
        free(expense);
        free(file_line);
        free(file_name);
    }

    int item_number=0;
    printf("# of Items to Store: ");
    scanf("%d",&item_number);
    while (getchar() != '\n');

    for (int i=0;i<=item_number;i++){
        printf("Enter Item Name: ");
        fgets(expense->item_name,STARTING_SIZE,stdin);
        file_line[strcspn(file_line, "\n")] = 0;

        printf("Enter Item Price: ");
        scanf("%.2f",&expense->price);
        while (getchar() != '\n');

        fprintf(file,"%s: ",expense->item_name);
        fprintf(file,"$%.2f\n",expense->price);

        }
    fclose(file);
    FILE* file_ptr=fopen("expenses.txt","r");
    if (file_ptr==NULL){
        fclose(file);
        free(expense);
        free(file_line);
        free(file_name);
    }
   
    double total_cost=0.0;
    int i=1;
    while(fgets(file_line,STARTING_SIZE,file)!=NULL){
        file_line[strcspn(file_line, "\n")]=0;       
        total_cost+=expense->price;

        printf("%s: $%.2f\n",expense->item_name,expense->price);       
        i++;
    }
    printf("$%.2f\n",total_cost);

    fclose(file);
    fclose(file_ptr);
    free(expense);
    free(file_line);
    free(file_name);
    return 0;

}