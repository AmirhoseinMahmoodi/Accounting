#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>

void intro();
void mainmenu();


void main()
{
    intro();
    mainmenu();




}
void intro()
{
    int desing_count;

    printf("\t\t\t\tWELCOME\n%c",0xC9);

    for(desing_count=0 ; desing_count < 73 ; desing_count++)
    {
        printf("%c",0xCD);
    }
    printf("%c\n%cThis is an accounting program made by Amirhosein Mahmoodi student at IKIU%c\n%c",0xBB,0xBA,0xBA,0xC8);

    for(desing_count=0 ; desing_count < 73 ; desing_count++)
    {
        printf("%c",0xCD);
    }
    printf("%c",0xBC);
}

void mainmenu()
{
    Sleep(5000);
    system("cls");

    int main_menu_value ;
    printf("choose what you want to do with this program.\n");
    printf("1)log in\n2)sign up\n3)EXIT\n");
    scanf("%d",&main_menu_value);

    int wrong_number = 0 ;
    while(main_menu_value <= 0 || main_menu_value > 3)
    {
        printf("Pleae just enter numbers 1 to 3.\n");
        scanf("%d",&main_menu_value);
        wrong_number += 1 ;
        if(wrong_number == 3)
        {
            system("cls");
            printf("choose what you want to do with this program.\n");
            printf("1)log in\n2)sign up\n3)EXIT\n");
            wrong_number = 0 ;
        }
    }
    system("cls");
}
