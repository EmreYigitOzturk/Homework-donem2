#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int zar1,zar2,sum,tur=1,puan;
    srand(time(NULL));
    while(1)
    {
        zar1 = 1+rand()%6;
        zar2 = 1+rand()%6;
        printf("\nzar1=%d\nzar2=%d\n",zar1,zar2);
        sum=zar1+zar2;
        if((tur == 1) && (sum==7 || sum==11))
        {
            printf("Oyunu Kazandiniz!");
            break;
        }
        else if((tur == 1) && (sum == 2 || sum ==3 || sum==12))
        {
            printf("Oyunu Kaybettiniz!");
            break;
        }
        else if(tur == 1)
        {
            puan=sum;
            printf("Puaniniz = %d",puan);

        }
        else if(sum == puan)
        {
            printf("Oyunu %d.Turda Kazandiniz!",tur);
            break;
        }
        tur++;
    }

    return 0;
}
