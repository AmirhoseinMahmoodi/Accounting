#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>

void intro();
int mainmenu();
void user_choice(int user_decision);
void log_in();
void sign_up();
int Hold;
int user_count;
void Hold_func();

void main()
{
    int Hold;
    int user_decision;
    intro();
    Hold_func();
    user_decision = mainmenu();
    if(user_decision == 1)
    {
        log_in();
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
    FILE *Holder;
    Holder = fopen("Hold.txt", "r");
    fscanf(Holder, "%d",&Hold);
    if(Hold == 1)
    {
        printf("\nDo not restart the program!!\nOtherwise the hold timer will reset");
        Sleep(300000);
        Hold = 0;
    }
}

void sign_up()
{
    struct user{
        char username[41] ;
        char password[41] ;
        char pass_check[41] ;
        char Name[41] ;
        char surname[41] ;
        char NID[11] ;
        char PhoneNumber[10] ;
        char Email[41] ;
        struct user *Link ;
    } TempUser ;
    int loopcounter1 ;
    FILE *user_opener , *user_counter ;
    printf("Please enter your username up to 40 characters:");
    scanf("%40s",TempUser.username);
    printf("please enter your name:\n");
    scanf("%40s",TempUser.Name);
    printf("surname?\n");
    scanf("%40s",TempUser.surname);
    printf("Please enter your national ID code:\n");
    scanf("%10s",TempUser.NID);
    printf("Please enter your phone number:\n09");
    scanf("%9s",TempUser.PhoneNumber);
    printf("Please enter your Email:\n");
    scanf("%40s",TempUser.Email);
    printf("Well done.\nNow enter your password up to 40 characters\nTry to set a complicated password using capital and small letters and special characters:");
    scanf("%40s",TempUser.password);
    printf("enter your password again:");
    scanf("%40s",TempUser.pass_check);
    for(loopcounter1 = 0; loopcounter1 <= 1 ; loopcounter1++)
    {
        if(strcmp(TempUser.password,TempUser.pass_check) != 0)
        {
            printf("Passwords didnt match\n Try again:");
            loopcounter1-=1 ;
            scanf("%40s",TempUser.pass_check);
        }
        else
        {
            break;
        }
    }
    user_opener = fopen("Users.txt", "a");
    fprintf(user_opener, "%s\n%s\n%s\n%s\n09%s\n%s\n%s\n",TempUser.username,TempUser.Name,TempUser.surname,TempUser.NID,TempUser.PhoneNumber,TempUser.Email,TempUser.password);
    user_counter = fopen("usercount.txt", "r");
    fscanf(user_counter, "%d",&user_count);
    fclose(user_counter);
    user_counter = fopen("usercount.txt", "w");
    fprintf(user_counter,"%d",user_count+1);
    fclose(user_counter);
    fclose(user_opener);

}

void log_in()
{
    struct user{
        char username[41] ;
        char password[41] ;
        struct user *Link ;
    }user_identifier;

    struct user *start , *end , *temp ;
    int loop_counter1 , loop_counter2 , loop_counter3 , wrong = 0 , users_number , loop_counter4 ;
    FILE *user_opener , *Holder , *user_counter ;
    start = malloc(sizeof(struct user));
    end = malloc(sizeof(struct user));
    user_opener = fopen("users.txt", "r");
    user_counter = fopen("usercount.txt", "r");
    fscanf(user_counter, "%d", &users_number);
    fclose(user_counter);
    fscanf(user_opener, "%s",start->username);
    start->Link = end ;
    fscanf(user_opener, "%*s%*s%*s%*s%*s%*s%s",end->username);
    end->Link = NULL;
    for(loop_counter3 = 0 ; loop_counter3 < users_number - 2 ; loop_counter3++)
    {
        temp = malloc(sizeof(struct user));
        fscanf(user_opener , "%*s%*s%*s%*s%*s%*s%s",temp->username);
        end->Link = temp;
        end = temp;
        end->Link = NULL;
    }
    printf("Please enter your username:");
    int wrong_username_input = 0 ;
    for(loop_counter4 = 0 ; loop_counter4 < 1 ; loop_counter4++)
    {
        temp = start;
        scanf("%s",user_identifier.username);
        do
        {
            if(strcmp(user_identifier.username,temp->username) == 0)
            {
                printf("correct");
                break;
            }
            else
            {
                wrong_username_input++ ;
            }
            temp=temp->Link;
        }while(temp != NULL);
        if(wrong_username_input == users_number )
        {
            printf("There is not such username.\nTry reentering your username:");
            loop_counter4-- ;
            wrong_username_input = 0 ;
        }
    }
//    printf("Please enter your username:");
//    for(loop_counter1 = 0;loop_counter1 <= 1; loop_counter1++)
//    {
//        scanf("%40s",username_user);
//        if(strcmp(username_user,username) != 0)
//        {
//            printf("There is not anyone with this username\nTry again:");
//            loop_counter1-=1;
//        }
//        else
//        {
//            break;
//        }
//    }
//    printf("Please enter your password:");
//    for(loop_counter2 = 0;loop_counter2 <= 1; loop_counter2++)
//    {
//        scanf("%40s",password_user);
//        if(strcmp(password_user,password) != 0)
//        {
//            printf("Incorrect password\n");
//            if(wrong == 4)
//            {
//                Holder = fopen("Hold.txt", "w");
//                Hold = 1;
//                fprintf(Holder, "%d",Hold);
//                printf("you have entered wrong password 5 times so the program will be banned for 5 minutes\nATTENTION - Do not restart the program otherwise the timer will be reset.");
//                fclose(Holder);
//                Sleep(300000);
//                Hold = 0;
//                Holder = fopen("Hold.txt", "w");
//                fprintf(Holder, "%d",Hold);
//                fclose(Holder);
//                wrong = 0;
//            }
//            printf("\nTry again:");
//            loop_counter2-=1;
//            wrong+=1;
//        }
//        else
//        {
//            break;
//        }
//    }
//    printf("you have entered successfully");
}
