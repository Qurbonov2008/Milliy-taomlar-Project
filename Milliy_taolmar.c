#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50], tami[30], halal[20];
    int price, time;
} Taomlar;

void Inputtaomlar(Taomlar *taom, int n);
void OutputTaomlar(Taomlar taomlar[], int n);
void MaxTaom(Taomlar *taomlar, int n);
void MinTaom(Taomlar *taomlar, int n);
int main()
{

    int a;
    int n = 0;
    int m = 1;
    Taomlar taomlar_royxati[100];

    while (m)
    {
        printf("\nMenu:\n 1) Taom kiritish. 2) Taom ko'rish. 3) Eng qimat taom 4) Eng arzon taom 5) Tugatish\n");
        printf("Amalni kiriting: ");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            printf("Nechta taom kiritmoqchisiz: ");
            scanf("%d", &n);

            Inputtaomlar(taomlar_royxati, n);
            break;

        case 2:
            if (n == 0)
            {
                printf("Xati taomlar mavjud emas: ");
            }
            else
            {
                OutputTaomlar(taomlar_royxati, n);
            }
            break;
        case 3:
            if (n == 0)
            {
                printf("Xali taomlar mavjud emas");
            }
            else
            {
                MaxTaom(taomlar_royxati, n);
            }
            break;
        case 4:
            if (n == 0)
            {
                printf("Xali taomlar mavjkud emas");
            }
            else
            {
                MinTaom(taomlar_royxati, n);
            }
            break;

        case 5:
            printf("Biznig taomlarga kelganingiz uchun raxmat!");
            m = 0;
            break;

        default:
            break;
        }
    }
}

void MinTaom(Taomlar *taomlar, int n)
{
    int min_price = taomlar[0].price;
    int  min_=0;
    for (int i = 0; i < n; i++)
    {
       if(taomlar[i].price<min_price)
       {
        min_price = taomlar[i].price;
        min_ = i;
       }
    }

    printf("Eng arzon taomlar: ");
    printf("Taom nomi:  %s \n", taomlar[min_].name);
    printf("Taom tami:  %s \n", taomlar[min_].tami);
    printf("Taom halolmi: %s\n", taomlar[min_].halal);
    printf("Taom narxi: %d \n", taomlar[min_].price);
    printf("Taom qanchada tayor bo'ladi %d", taomlar[min_].time);
}

void Inputtaomlar(Taomlar *taom, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("Taom nomini kiriting: ");
        getchar();
        fgets(taom[i].name, sizeof(taom[i].name), stdin);
        taom[i].name[strcspn(taom[i].name, "\n")] = '\0';

        printf("Taom tamini kiriting: ");
        scanf("%s", taom[i].tami);

        printf("Taom halolmi: (ha yoki yo'q)");
        scanf("%s", taom[i].halal);

        printf("Taom narxini kiriting: ");
        scanf("%d", &taom[i].price);

        printf("Taom qanchada tayor bo'ladi: ");
        scanf("%d", &taom[i].time);
    }
}

void OutputTaomlar(Taomlar taomlar[], int n)
{

    printf("Taomlar ro'yxati\n");
    for (int i = 0; i < n; i++)
    {
        printf("Taom nomi:  %s\n Taom tami:  %s \n Taom halolmi:  %s \n Taom narxi:  %d \n Taom Tayyor bolish vaqti: %d\n\n", taomlar[i].name, taomlar[i].tami, taomlar[i].halal, taomlar[i].price, taomlar[i].time);
    }
}

void MaxTaom(Taomlar *taomlar, int n)
{

    int max = 0;

    for (int i = 0; i < n; i++)
    {
        if (taomlar[i].price > taomlar[max].price)
        {
            max = i;
        }
    }

    printf("Eng qimmat taom\n");
    printf("Taom nomi: %s\n", taomlar[max].name);
    printf("Taom tami: %s\n", taomlar[max].tami);
    printf("Taom halolmi: %s\n", taomlar[max].halal);
    printf("Taom narxi: %d\n", taomlar[max].price);
    printf("Taom tayyor bo'lish vaqti: %d \n\n", taomlar[max].time);
}
