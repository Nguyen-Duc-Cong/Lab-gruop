#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <stireg.h>
#include <math.h>

struct Airl
{
    char firstName[20];
    char lastName[20];
    char deCity[100];
    char frCity[100];
    int dayLeave;
    int dayback;
    int seats;
};

void menu();
int validattion(int min, int max);
int main(int argc, char const *argv[])
{
//-----------------------------------------
   char str2[20], str3[20];
    int year;
    FILE *fp;
    char filename[50];
    int days;  
    int count = 0;
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
    Airl VietAirl[days];
    do
    {
        if (feof(fp))
        {
            break;
        }
        fscanf(fp, "%s %s %d",str2, str3, &year);

    } while (1);
    fclose(fp);
//---------------------------------------------------------
    while (true)
    {
        //---------------------------------
        int count = 0 menu();
        int chosse = validattion(1, 3);
        //---------------------------------
        while (chosse)
        {
        case 1:
        {
            //------------------------------------
            printf("What is your name, first followed by last?");
            {
                char name[40];
                gets(name);
                char *token = strtok(name, "- _");
                VietAirl[count].lastName = token;
                token = strtok(NULL, NULL);
                VietAirl[count].firstName = token;
            }
            printf("From which city do you want to fly?");
            fflush(stdin);
            gets(VietAirl[count].frCity);
            printf("What is your destination city?");
            fflush(stdin);
            gets(VietAirl[count].deCity);
            prinf("What day do you want to leave?");
            scanf("%d", VietAirl[count].dayLeave);
            printf("What day do you want to come back?");
            scanf("%d", VietAirl[count].dayback);
            printf("How many seats do you want?");
            VietAirl[count].seats = validattion(4, 400);
            //---------------------------------------
            printf("Thank! Your reservation has been make.")
        }
        }
    }
    system("pause");
    return 0;
}

void menu()
{
    printf("#######################################################################################\n");
    printf("#\t1.	⦁	Make a reservation                     \t#\n");
    printf("#\t2.	⦁	Print out a listing of all flights                         \t#\n");
    printf("#\t3.	⦁	Quit                                                            \t#\n");
    printf("#######################################################################################\n");
}
int validattion(int min, int max)
{
    int a;
    do
    {
        printf("Choice number(%d - %d ): ", min, max);
        scanf("%d", &a);
    } while (a < min || a > max);
    return a;
}
void reservation()
{
}
void print(int count)
{
}