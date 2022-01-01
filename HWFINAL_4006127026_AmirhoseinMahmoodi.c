#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>

void intro();
int mainmenu();
void user_choice(int user_decision);
void access_limitation();
void log_in();
void sign_up();
int Hold;
void Hold_func();

void main()
{
    int user_decision;
    intro();
    Hold_func();
    user_decision = mainmenu();
    printf("%d",user_decision);
//    user_choice(user_decision);
    if(user_decision == 1)
    {
        void log_in();
    }
    if (user_decision == 2)
    {
        sign_up();
    }


}
void intro()
{
    int desing_count;

    printf("\t\t\t\tWELCOME\n%c",0xC9);

    for(desing_count=0 ; desing_count < 75 ; desing_count++)
    {
        printf("%c",0xCD);
    }
    printf("%c\n%cThis is an accounting program made by Amirhosein Mahmoodi , student at IKIU%c\n%c",0xBB,0xBA,0xBA,0xC8);

    for(desing_count=0 ; desing_count < 75 ; desing_count++)
    {
        printf("%c",0xCD);
    }
    printf("%c",0xBC);
}

int mainmenu()
{
    if(Hold == 0)
    {
        Sleep(5000);
    }
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
    return main_menu_value ;
}

void Hold_func()
{
    if(Hold == 1)
    {
        printf("\nDo not restart the program!!\nOtherwise the hold timer will reset");
        sleep(300000);
        Hold = 0;
    }
}

void sign_up()
{
    char username[40] , password[40] ;
    FILE *password_opener , *username_opener;
    puts("Please enter your username up to 40 characters");
    scanf("%s",username);
    puts("Well done.\nNow enter your password up to 40 characters");
    scanf("%s",password);
    username_opener = fopen("username.txt", "a");
    password_opener = fopen("Password.txt", "a");
    fputs(username,username_opener);
    fputs(password,password_opener);
    fclose(username_opener);
    fclose(password_opener);

}

void log_in()
{

}
