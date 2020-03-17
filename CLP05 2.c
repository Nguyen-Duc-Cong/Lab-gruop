#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <stireg.h>
#include <math.h>

struct client
{
    char firstName[20];
    char lastName[20];
    char deCity[100];
    char frCity[100];
    int dayLeave;
    int dayback;
    int seats;
} VietAirl[100];

void menu();
int validattion(int min, int max);
int main(int argc, char const *argv[])
{

    char str2[20], str3[20];
    int year;
    FILE *fp;
    char filename[50];
    int days;  
    printf("Enter the name of the file with the flight data: ");
    fflush(stdin);
    gets(filename);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Can't open file !!!\n");
        return 0;
    }
    rewind(fp);
    fscanf(fp,"%d",&days);
    do
    {
        if (feof(fp))
        {
            break;
        }
        fscanf(fp, "%s %s %d",str2, str3, &year);
        printf(" %s %s %d\n",str2, str3, year);

    } while (1);
   

    fclose(fp);
    system("pause");
    return 0;
}