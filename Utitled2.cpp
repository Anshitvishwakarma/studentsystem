#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
struct student  {
    int id;
    char name[50];
    float marks;
};
struct student students[max];
int count = 0; 
void addstudent();
void displaystudents();
void searchstudent();
void updatestudent();
void deletestudent();
void exitprogram();
void saveToFile();
 void loadFromFile();
int main() {
    int choice;
    loadFromFile();
while(1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addstudent(); break;
            case 2: displaystudents(); break;
            case 3: searchstudent(); break;
           case 4: updatestudent(); break;
          case 5: deletestudent(); break;
            case 6: exitprogram();
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
void addstudent(){
    if(count >=100){
        printf("student list full");
        return ;
    }
       printf("enter id:");
       scanf("%d",&students[count].id);
       getchar();
      printf("enter name:");
        fgets(students[count].name, sizeof(students[count].name), stdin);
    students[count].name[strcspn(students[count].name, "\n")] = '\0';
      printf("enter marks:");
       scanf("%f",&students[count].marks);
       count++;
       saveToFile();
       printf("student added sucessfull\n\n");
}
void displaystudents() {
    if(count == 0) {
        printf("No students to display!\n");
        return;
    }

    printf("\nID\tName\tMarks\n");
    printf("----------------------------------------\n");
    for(int i=0; i<count; i++){
         printf("%d\t%s\t\t%.2f\t\n", students[i].id, students[i].name, students[i].marks);
    }
}
void searchstudent(){
    if(count==0){
        printf("not search student\n");
        return;
    }
    int ID;
      printf("enter id:");
       scanf("%d",&ID);
           for(int i=0; i<count; i++) {
        if(students[i].id == ID) {
            printf("ID: %d\nName: %s\nMarks: %.2f\n", students[i].id, students[i].name, students[i].marks);
            return;
       }
           }
       printf("Student not found!\n");



}
void updatestudent(){
    int ID;
     if(count==0){
        printf("no student update\n");
        return;
    }
    printf("enter update id\n");
    scanf("%d",&ID);
      getchar();
    for(int i=0; i<count; i++) {
        if(students[i].id == ID) {
              printf("enter new name:");
        fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
      printf("enter new marks:");
       scanf("%f",&students[i].marks);
              saveToFile();

       printf("update sucessfull");
       return;
    }
    }
    printf("Student with ID %d not found!\n", ID);
}
void deletestudent(){
int ID;
         if(count==0){
        printf("not delete student");
        return;
    }
      printf("enter id:");
       scanf("%d",&ID);
        for(int i=0; i<count; i++){
            if(students[i].id == ID) {
            	
                 for(int j=i; j<count-1; j++) {
                students[j] = students[j+1];
            }
              count--;
                     saveToFile();

        }
            printf("deleted sucessfull");
            return;
              
        }
            printf("Student with ID %d not found!\n", ID);
}
void exitprogram(){
	  saveToFile();
    printf(" exit program ||thankyou !!!!");
    exit(0);
}
// FILE HANDLING FUNCTIONS
void saveToFile() {
    FILE *fp = fopen("student.txt", "w");
    if(fp == NULL) {
        printf("Error saving to file!\n");
        return;
    }
    if(count == 0){
    	fclose(fp);
    	return ;
	}
    for(int i=0; i<count; i++) {
        fprintf(fp, " %d,    %s,     %.2f\n", students[i].id     ,          students[i].name    ,    students[i].marks);
    }
    fclose(fp);
}
void loadFromFile() {
    FILE *fp = fopen("student.txt", "r");
    if(fp == NULL) {
        return; 
    }
    while(fscanf(fp, "%d,%49[^,],%f\n", &students[count].id   ,   students[count].name    ,   &students[count].marks) == 3) {
        count++;
    }
    fclose(fp);
}
