#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <stireg.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
struct Airl
{
    char deCity[50];
    char frCity[50];
    int seats;
};

int countCurrent(FILE *fp);

void makeRes(Airl VAirl[], Airl VNAirl[], int count);
void display(Airl VAirl[], Airl VNAirl[], int count, int days);
void menu();
int validattion(int min, int max);
int main(int argc, char const *argv[])
{
    int year;
    FILE *fp;
    int days;
    char filename[50];
    printf("Enter the name of the file with the flight data: ");
    fflush(stdin);
    gets(filename);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Can't open file !!!\n");
        system("pause");
        return 0;
    }
    int count = 0;
    rewind(fp);
    fscanf(fp, "%d", days);
    char buff[500];
    while (fgets(buff, 500, fp))
    {
        count++;
    }
    Airl VAirl[count];
    count = 0;
    rewind(fp);
    fscanf(fp, "%d", &days);
    do
    {
        if (feof(fp))
            break;
        fscanf(fp, "%s %s %d", VAirl[count].frCity, VAirl[count].deCity, &VAirl[count].seats);
        count++;
    } while (1);
    fclose(fp);
    Airl VNAirl[count * days];
    for (int i = 0; i < days; i++)
        for (int j = 0; j < count; j++)
        {
            strcpy(VNAirl[i * count + j].frCity, VAirl[j].frCity);
            strcpy(VNAirl[i * count + j].deCity, VAirl[j].deCity);
            VNAirl[i * count + j].seats = VAirl[j].seats;
        }

    while (true)
    {
        //---------------------------------
        menu();
        int chosse = validattion(1, 3);
        //---------------------------------
        switch (chosse)
        {
        case 1:
        {
            makeRes(VAirl, VNAirl, count);
            break;
        }
        case 2:
        {
            display(VAirl, VNAirl, count, days);
        }
        }
        system("pause");
    }

    return 0;
}

void menu()
{
    printf("#######################################################################################\n");
    printf("#\t1.	Make a reservation                                             \t#\n");
    printf("#\t2.	Print out a listing of all flights                             \t#\n");
    printf("#\t3.	Quit                                                           \t#\n");
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
void makeRes(Airl VAirl[], Airl VNAirl[], int count)
{
    int chuyen = -1;
    char name[50];
    char CFly[50], CDes[50];
    int dLeave, dBack, mSeats;
    printf("What is your name, first followed by last?\n");
    fflush(stdin);
    gets(name);
    printf("From which city do you want to fly?\n");
    fflush(stdin);
    gets(CFly);
    printf("What is your destination city?\n");
    fflush(stdin);
    gets(CDes);
    for (int i = 0; i < count; i++)
    {
        if (0 == strcmp(VAirl[i].frCity, CFly) && 0 == strcmp(VAirl[i].deCity, CDes))
        {
            chuyen = i;
        }
    }
    if (chuyen == -1)
    {
        printf("No flight between those cities\n");
        return;
    }
    printf("What day do you want to leave?\n");
    scanf("%d", &dLeave);
    printf("What day do you want to come back?\n");
    scanf("%d", &dBack);
    if (dLeave < 0 || dLeave > 9 || dBack < 0 || dBack > 9)
    {
        printf("Error one of the days is invalid\n");
        return;
    }
    printf("How many seats do you want?\n");
    scanf("%d", &mSeats);
    if (mSeats > 400 || mSeats < 3)
    {
        printf("Error the number of seats of a flight is in between 4 and 400\n");
        return;
    }
    else if (mSeats > VNAirl[(dLeave - 1) * count + chuyen].seats || mSeats > VNAirl[(dBack - 1) * count + chuyen].seats)
    {
        printf("Error at least one of the flights being requested does not have the number of seats the user requires.\n");
        return;
    }
    VNAirl[(dLeave - 1) * count + chuyen].seats -= mSeats;
    VNAirl[(dBack - 1) * count + chuyen].seats -= mSeats;
    printf("Thank! Your reservation has been make.\n");
}
void display(Airl VAirl[], Airl VNAirl[], int count, int days)
{
    for (int i = 0; i < days; i++)
    {
        printf("%d\n", i + 1);
        for (int j = 0; j < count; j++)
            printf("To: %s From: %s Available Seats: %d\n", VNAirl[i * count + j].frCity, VNAirl[i * count + j].deCity, VNAirl[i * count + j].seats);
    }
}
