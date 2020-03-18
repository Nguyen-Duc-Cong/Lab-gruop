#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
struct student
{
	char code[25];
	char name[30];
	char date[30];
	char point[35];
};
struct student stu;
void add_student()
{ //enter new student
	int c;
	printf("Enter new student: \n");
	FILE *fp;
	fp = fopen("Student.txt", "a");
	if (fp == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else
	{
		do
		{
			fflush(stdin);
			printf("Student code: ");
			gets(stu.code);
			fflush(stdin);
			printf("Student name: ");
			gets(stu.name);
			fflush(stdin);
			printf("Date of birth: ");
			gets(stu.date);
			fflush(stdin);
			printf("Learning point: ");
			gets(stu.point);
			fflush(stdin);
			fwrite(&stu, sizeof(stu), 1, fp);
			printf("This student is sucessfully added\n");
			printf("Press any key to continue,ESC to return the main menu\n\n");
			c = getch();
		} while (c != 27);
	}
	fclose(fp);
	return;
}
void search_student()
{ // look up student base on student name
	char s_nam[20];
	int c;
	FILE *fp;
	fp = fopen("Student.txt", "r");
	while (c != 27)
	{
		printf("\nPlease enter student name: ");
		fflush(stdin);
		gets(s_nam);
		while (fread(&stu, sizeof(stu), 1, fp) == 1)
		{
			if (strcmp(s_nam, stu.name) == 0)
			{
				printf("Student code: %s\n", stu.code);
				printf("Student name: %s\n", stu.name);
				printf("Date of birth: %s\n", stu.date);
				printf("Learning point: %s\n", stu.point);
				rewind(fp);
				break;
			}
		}
		if (strcmp(s_nam, stu.name) != 0)
		{
			printf("Not have this student.\n");
			break;
		}
		printf("Press any key to continue,ESC to return the main menu\n\n");
		c = getch();
	}
	fclose(fp);
	return;
}
void display_student()
{ // display student list
	int c;
	FILE *fp;
	fp = fopen("Student.txt", "r");
	printf("Student list:\n---------------------------------------------------------------------------------------------------\n");
	printf("Student code             Student name                  Date of birth                 Learning point\n\n");
	do
	{
		c = fgetc(fp);
		printf("%c", c);
	} while (c != EOF);
	fclose(fp);
	printf("\n\nPress any key to countinue.\n");
	getch();
}
int main()
{
	int choice;
	do
	{
		printf("---------------------------------------------------------------------------------------------------\n");
		printf("\t1. Enter student list\n");
		printf("\t2. Look up student\n");
		printf("\t3. Display student list\n");
		printf("\t4. Exit\n");
		printf("Please choose menu (1 - 4): ");
		fflush(stdin);
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			add_student();
			break;
		case 2:
			search_student();
			break;
		case 3:
			display_student();
			break;
		case 4:
			printf("Goodbye~");
			break;
		default:
			printf("Wrong choice!\n");
			printf("Please choice again\n");
		}
	} while (choice != 4);
	return 0;
}
