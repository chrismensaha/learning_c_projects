/*Write the student names and grades to a file (e.g., Students.txt).
Close and reopen the file for reading.
Ask the user for a name to find.
Loop through the file. 
If you find a match, print their grade and whether they passed (Grade $\ge$ 60).
If you get to the end of the file and haven't found them, print "Student not found."*/

#include <stdio.h>
#include <stdlib.h>
#define STARTING_SIZE 100

typedef struct student{
    char* name;
    double grade;
}Student;

int main(){
    Student* student=malloc(sizeof(Student));
       
    char* filename=malloc(STARTING_SIZE*sizeof(char));  
    char* fileline=malloc(STARTING_SIZE*sizeof(char)); 
    char* name=malloc(STARTING_SIZE*sizeof(char));
    student->name=name;

    printf("Enter Student Name: ");  
    fgets(name,STARTING_SIZE,stdin);
        name[strcspn(name, "\n")] = 0;
    printf("Enter Student Grade: "); 
    scanf("%lf",student->grade);
        while (getchar() != '\n');
    printf("Enter File Name: ");
    fgets(filename,STARTING_SIZE,stdin);  
        filename[strcspn(filename, "\n")] = 0;

    FILE* file = fopen(filename,"w");

    if (file==NULL){
        free(student);
        free(filename);
        free(name);
        return 1;
    }

    while(fgets(fileline,STARTING_SIZE,file)!=NULL){
        student->name[strcspn(student->name, "\n")] = 0;
        fprintf(file,"%s\n",student->name);
        fprintf(file,"%lf\n",student->grade);
    }

    fclose(file);
    FILE* fileptr = fopen(filename,"r");

    if (fileptr==NULL){
        free(student);
        free(filename);
        free(name);
        return 1;
    }

    while(fgets(fileline,STARTING_SIZE,fileptr)!=NULL){
        if (sscanf());
    }

    free(name);
    free(student);
    free(filename);
    fclose(fileptr);
    return 0;
}