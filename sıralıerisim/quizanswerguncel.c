#include <stdio.h>
#include <stdlib.h>

int main()
{
    char p;
    char name[20];
    char surname[20];
    FILE *studentname;
    printf("enter press w or r\n");
    scanf("%c", &p);

    if ((studentname = fopen("studentname.dat", "a+")) == NULL)
        printf("Dosya Acilmadi\n");
    else if (p == 'w')
    {
        printf("enter name and surname\n");
        printf("for close enter eof key\n"); // eof key = ctrl +z

        scanf("%s%s", name, surname);

        while (!feof(stdin))
        {
            fprintf(studentname, "%s %s\n", name, surname);
            printf("? ");
            scanf("%s%s", name, surname);
        }
    }
    else if (p == 'r')
    {
        fseek(studentname, 0, SEEK_SET);
        printf("%-13s %-13s\n", "name", "surname");
        fscanf(studentname, "%s%s", name, surname);

        while (!feof(studentname))
        {
            printf("%-13s %-13s\n", name, surname);
            fscanf(studentname, "%s%s", name, surname);
        }
    }

    fclose(studentname);
    return 0;
}

