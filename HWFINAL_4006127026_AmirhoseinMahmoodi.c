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
void password_equallity_check(char defined_password[41], char password_cheker[41]);
void User_data(char username[41]);
void Graphic_profile_initialize();
int NID_check(char NID[11]);
int PhoneNumber_check(char phoneNumber[10]);
int User_Profile();
void Income(char User[41]);
void Expense(char User[41]);
void user_settings(User[41]);

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
    int loop_counter ;
    FILE *Holder;
    Holder = fopen("Hold.txt", "r");
    fscanf(Holder, "%d",&Hold);
    fclose(Holder);
    if(Hold == 1)
    {
        fopen("Hold.txt", "w");
        for(loop_counter = 0 ; loop_counter < 300000 ; loop_counter++)
        {
            Sleep(1000);
            system("cls");
            printf("you have entered wrong password 5 times so the program will be banned for 5 minutes\nATTENTION - Do not restart the program ");
            printf("otherwise the timer will be reset.");
            printf("%d:%d",(300000-loop_counter)/60000,(300000-loop_counter)%60);
        }
        Hold = 0 ;
        fprintf(Holder, "%d",Hold);
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
    } NewUser ;//Defining a structure for collecting the information of user to sign up //
    int loop_counter ;
    FILE *user_opener , *user_counter ;//Defining pointers *user_opener to users.txt and *user_counter to usercount.txt //
    printf("Please enter your username up to 40 characters:");//Reading the username of user
    scanf("%40s",NewUser.username);                          //up to 40 charachters//
    fflush(stdin);
    printf("please enter your name:\n");                                            //Collecting
    scanf("%40s",NewUser.Name);                                                    //
    fflush(stdin);
    printf("surname?\n");                                                           //          some
    scanf("%40s",NewUser.surname);                                                 //               other
    fflush(stdin);
    printf("Please enter your national ID code:\n");                                //
    int ID_check = 0;
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        scanf("%10s",NewUser.NID);                                                     //                    informations
        fflush(stdin);
        ID_check = NID_check(NewUser.NID);
        if(ID_check == 1)
        {
            loop_counter--;
        }
    }
    printf("Please enter your phone number:\n09");                                  //
    int Phone_check = 0;
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        scanf("%9s",NewUser.PhoneNumber);                                              //                                of
        fflush(stdin);
        Phone_check = PhoneNumber_check(NewUser.PhoneNumber);
        if(Phone_check == 1)
        {
            loop_counter--;
        }
    }
    printf("Please enter your Email:\n");                                           //
    scanf("%40s",NewUser.Email);                                                   //                                  the new
    fflush(stdin);
    printf("Well done.\nNow enter your password up to 40 characters\nTry to set a ");//
    printf("complicated password using capital and small letters and special characters:");//                                   user//
    scanf("%40s",NewUser.password);
    fflush(stdin);
    printf("enter your password again:");
    scanf("%40s",NewUser.pass_check);
    fflush(stdin);
    password_equallity_check(NewUser.password,NewUser.pass_check);
    user_opener = fopen("Users.txt", "a");
    fprintf(user_opener, "%s\n%s\n%s\n%s\n09%s\n%s\n%s\n",NewUser.username,NewUser.Name,NewUser.surname,NewUser.NID,NewUser.PhoneNumber,NewUser.Email,NewUser.password);
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
    int loop_counter , wrong = 0 , users_number ;
    FILE *user_opener , *Holder , *user_counter ;
    start = malloc(sizeof(struct user));
    end = malloc(sizeof(struct user));


    user_counter = fopen("usercount.txt", "r");

    fscanf(user_counter, "%d", &users_number);
    fclose(user_counter);

    user_opener = fopen("users.txt", "r");
    fscanf(user_opener, "%s",start->username);
    fscanf(user_opener, "%*s%*s%*s%*s%*s%s",start->password);
    start->Link = end ;

    fscanf(user_opener, "%s",end->username);
    fscanf(user_opener, "%*s%*s%*s%*s%*s%s",end->password);
    end->Link = NULL;

    for(loop_counter = 0 ; loop_counter < users_number - 2 ; loop_counter++)
    {
        temp = malloc(sizeof(struct user));
        fscanf(user_opener, "%s",temp->username);
        fscanf(user_opener, "%*s%*s%*s%*s%*s%s",temp->password);
        end->Link = temp;
        end = temp;
        end->Link = NULL;
    }

    printf("Please enter your username:\n");

    int wrong_username_input = 0 ;

    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        temp = start;
        scanf("%40s",user_identifier.username);
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
            loop_counter-- ;
            wrong_username_input = 0 ;
        }
    }
    sleep(1);
    system("cls");
    printf("Please enter your password:\n");
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        scanf("%40s",user_identifier.password);
        if(strcmp(user_identifier.password,temp->password) == 0 )
        {
            printf("youve successfully entered your account");
        }
        else
        {
            if( wrong == 4 )
            {
                Holder = fopen("Hold.txt", "w");
                Hold = 1;
                fprintf(Holder, "%d",Hold);
                printf("you have entered wrong password 5 times so the program will be banned for 5 minutes\nATTENTION - Do not restart the program ");
                printf("otherwise the timer will be reset.");
                fclose(Holder);
                Hold_func();
                Hold = 0;
                Holder = fopen("Hold.txt", "w");
                fprintf(Holder, "%d",Hold);
                fclose(Holder);
                wrong = 0;

            }
            printf("Wrong password!!\nEnter your password again");
            loop_counter--;
            wrong++;
        }
    }
    system("cls");
    Graphic_profile_initialize();
    User_data(user_identifier.username);
    system("cls");

}

void password_equallity_check(char defined_password[41], char password_cheker[41])
{
    int loop_counter ;
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        if(strcmp(defined_password,password_cheker) != 0)
        {
            printf("Passwords didnt match\n Try again:");
            scanf("%40s",password_cheker);
            loop_counter--;
        }
    }

}

void User_data(char username[41])
{
    int User_choice ;
    User_choice = User_Profile();
    if(User_choice == 1)
    {
       Income(username) ;
    }
    else if(User_choice == 2)
    {
        Expense(username);
    }
    else if(User_choice == 3)
    {

    }
    else if(User_choice == 4)
    {
        user_settings(username);
    }
}

void Graphic_profile_initialize()
{
    int loop_counter;
    for(loop_counter = 0 ; loop_counter < 3 ; loop_counter++)
    {
        printf("Initializing your profile");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        system("cls");
    }
}

int NID_check(char NID[11])
{
    int loop_counter , wrong_input = 0 ;
    for(loop_counter = 0 ; loop_counter < 11 ; loop_counter++)
    {
        if(NID[loop_counter] < 48 || NID[loop_counter] > 57)
        {
            if(NID[loop_counter] != '\0')
            {
                wrong_input++;
            }
        }
    }
    if(wrong_input > 0)
    {
        printf("Wrong input format\nReenter your national ID(Allowed input:(0 - 9):");
        return 1 ;
    }
    else
    {
        return 0;
    }
}

int PhoneNumber_check(char phoneNumber[10])
{
    int loop_counter , wrong_input = 0 ;
    for(loop_counter = 0 ; loop_counter < 10 ; loop_counter++)
    {
        if(phoneNumber[loop_counter] < 48 || phoneNumber[loop_counter] > 57)
        {
            if(phoneNumber[loop_counter] != '\0' || phoneNumber[loop_counter] == ' ')
            {
                wrong_input++;
            }
        }
    }
    if(wrong_input > 0)
    {
        printf("Wrong input format\nReenter PhoneNumber(Allowed input:0 - 9):\n09");
        return 1 ;
    }
    else
    {
        return 0;
    }
}

int User_Profile()
{
    int user_desicion ;
    system("cls");
    printf("Main menu\n1.Income\n2.Expenses\n3.Statistics\n4.Settings\n5.Sign out\n6.EXIT\n>>Please enter your choice:");
    scanf("%d",&user_desicion);
    fflush(stdin);
    return user_desicion ;
}

void Income(char User[41])
{
    system("cls");
    FILE *user_Data_File ;
    char user_File_Name[46];
    sprintf(user_File_Name, "%s.txt",User);
    user_Data_File = fopen(user_File_Name, "a");
    printf("You are entering your income information...\n\nPlease specify your income type\n");
    printf("1.Progrramming Salary\n2.YARANEH\n3.Pocket Money\n4.University grant\n>>Please enter your choice:");
    int income_type ;
    scanf("%d",&income_type);
    fflush(stdin);
    printf("Please enter the amount of your income in RIAL:");
    float amount ;
    scanf("%f",&amount);
    fflush(stdin);
    printf("Please enter the date of income(YYYY/MM/DD):");
    int year , month , day ;
    scanf("%d%*c%d%*c%d",&year,&month,&day);
    fflush(stdin);
    printf("Please enter a short description:");
    char description[71];
    gets(description);
    fprintf(user_Data_File, "%d\n%f\n%d/%d/%d\n%s\n" ,income_type ,amount ,year ,month ,day ,description );
    fclose(user_Data_File);
}

void Expense(char User[41])
{
    system("cls");
    FILE *user_Data_File ;
    char user_File_Name[46];
    sprintf(user_File_Name, "%s.txt",User);
    user_Data_File = fopen(user_File_Name, "a");
    printf("You are entering your expense information\nPlease specify your expense type:");
    printf("Please specify your expense type\n");
    printf("1.Wearings\n2.Transportasion\n3.Tuition fees\n4.Entertainment\n5.Mobile and Internet bill\n6.Medical expenses\n7.Charity donation");
    printf("\n\n>>Please enter your choice:");
    int expense_type ;
    scanf("%d",&expense_type);
    fflush(stdin);
    printf("Please enter the amount of your expense in RIAL:");
    float amount ;
    scanf("%f",&amount);
    fflush(stdin);
    printf("Please enter the date of income(YYYY/MM/DD):");
    int year , month , day ;
    scanf("%d%*c%d%*c%d",&year,&month,&day);
    fflush(stdin);
    printf("Please enter a short description:");
    char description[71];
    gets(description);
    fprintf(user_Data_File, "%d\n%f\n%d/%d/%d\n%s\n\n" ,expense_type ,-amount ,year ,month ,day ,description );
    fclose(user_Data_File);
}
