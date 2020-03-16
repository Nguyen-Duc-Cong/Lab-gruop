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
    char deCity[400];
    char frCity[400];
    int dayLeave;
    int dayback;
    int seats;
} VietAirl[100];

void menu();
int validattion(int min, int max);
int main(int argc, char const *argv[])
{
    char filename[50];
    printf("Enter the name of the file with the flight data");
    scanf("%s", filename);
    f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Can't open file !!!\n");
        return 0;
    }
    printf("File content: \n");
    fread(filename, buffer, 1, f);
    while (true)
    {
        int count = 0 menu();
        int chosse = validattion(1, 3);
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
            scanf("%d",VietAirl[count].dayLeave);
            printf("What day do you want to come back?");
            scanf("%d",VietAirl[count].dayback);
            printf("How many seats do you want?");
            scanf("%d",VietAirl[count].seats);
            //---------------------------------------
            printf("Thank! Your reservation has been make.")
        }
        }
    }

    fclose(f);
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
    printf("What is your name, first followed by last?");
    scanf();
    printf("From which city do you want to fly?");
    scanf();
    printf("What is your destination city?");
    scanf();
    prinf("What day do you want to leave?");
    scanf();
    printf("What day do you want to come back?");
    scanf();
    printf("How many seats do you want?");
    scanf();
    printf("Thank! Your reservation has been make.")
}
void print(int count)
{
}