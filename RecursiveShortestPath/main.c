#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define row 6
#define max 12
void func(int dizi[row][max],int i ,int c)
{
    if(dizi[i][c]==1)
    {
        dizi[i][c]=2;
    }
    if(dizi[i][c]==0)
    {
        c--;
        i++;
        if(dizi[i][c]==1)
        {
            dizi[i][c]=2;
        }
        if(dizi[i][c]==0)
        {
            while(dizi[i][c]!=1)
            {
                c--;
                if(c==0)
                    break;
            }
            if(dizi[i][c]==1)
            {
                dizi[i][c]=2;
            }
            else
                return;
        }
    }
    func(dizi,i,c+1);

}



int main()
{
    int rastgele_sayi,i,c;
    /*printf("enter the horizontal and vertical values\n");
    scanf("%d%d",&a,&b);*/
    int dizi[6][12] = {
    {1,0,1,1,1,0,0,1,0,1,1,0},
    {1,0,1,1,1,1,1,0,1,0,0,0},
    {1,1,1,1,1,1,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1,1,1,1,1},
    {0,1,0,1,1,1,1,1,0,0,0,1},
    {1,1,1,0,1,1,1,1,1,1,1,1}
    };
    //srand(time(NULL));
    /*for(i=0;i<row;i++)
    {
        for(c=0;c<max;c++)
        {
            rastgele_sayi = rand() %2;
            dizi[i][c]=rastgele_sayi;
        }
    }*/
    dizi[0][0]=1;
    dizi[row-1][max-1]=1;
    //önceki hali check
    for (i = 0; i < row; i++)
    {
        for (c = 0; c < max; c++)
        {
            printf("%3d", dizi[i][c]);
        }
        printf("\n");
    }
    printf("\n");
    i=0,c=0;
    //cizgileri oluþturma
    func(dizi,i,c);
    //dizi son hali yazdýrma
    for (i = 0; i < row; i++)
    {
        for (c = 0; c < max; c++)
        {
            printf("%3d", dizi[i][c]);
        }
        printf("\n");
    }

    return 0;
}
