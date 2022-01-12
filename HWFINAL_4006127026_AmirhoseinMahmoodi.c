#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>

void intro();
int mainmenu();
void user_choice(int user_decision);
int log_in();
void sign_up();
int Hold;
int user_count;
void Hold_func();
void password_equallity_check(char defined_password[41], char password_cheker[41]);
int User_menu(char username[41] , char password[41]);
void Graphic_profile_initialize();
int NID_check(char NID[11]);
int PhoneNumber_check(char phoneNumber[10]);
int User_Profile();
void Income(char User[41]);
void Expense(char User[41]);
void user_settings(char User[41] , char password[41]);
int statistics(char User[41]);

void main()
{
    int Hold;
    int user_decision;
    intro();
    Main_Menu_Label:
    Hold_func();
    user_decision = mainmenu();
    int loop_counter , log_in_value;
    if(user_decision == 1)
    {
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            log_in_value = log_in();
            if(log_in_value == 5)
            {
                loop_counter--;
                system("cls");
            }
        }
    }
    if (user_decision == 2)
    {
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            sign_up();
            loop_counter--;
            goto Main_Menu_Label;
        }
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
    printf("\n\nPlease enter your choice:");
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
    fflush(stdin);
    printf("For all parts use _ instead of space character(' ')\n");
    printf("Please enter your username up to 40 characters:");//Reading the username of user
    gets(NewUser.username);
    fflush(stdin);
    printf("please enter your name:\n");                                            //Collecting
    gets(NewUser.Name);
    fflush(stdin);
    printf("surname?\n");                                                           //          some
    gets(NewUser.surname);
    fflush(stdin);
    printf("Please enter your national ID code:\n");                                //
    int ID_check = 0;
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        gets(NewUser.NID);
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
        gets(NewUser.PhoneNumber);
        fflush(stdin);
        Phone_check = PhoneNumber_check(NewUser.PhoneNumber);
        if(Phone_check == 1)
        {
            loop_counter--;
        }
    }
    printf("Please enter your Email:\n");                                           //
    gets(NewUser.Email);
    fflush(stdin);
    printf("Well done.\nNow enter your password up to 40 characters\nTry to set a ");//
    printf("complicated password using capital and small letters and special characters:");//                                   user//
    gets(NewUser.password);
    fflush(stdin);
    printf("enter your password again:");
    gets(NewUser.pass_check);
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



int log_in()
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
    if(user_opener == NULL)
    {
        printf("No users yet.");
    }
    fscanf(user_opener, "%s",start->username);
    fscanf(user_opener, "%*s%*s%*s%*s%*s%s",start->password);
    start->Link = end ;
    printf("%s",start->username);
    fscanf(user_opener, "%s",end->username);
    fscanf(user_opener, "%*s%*s%*s%*s%*s%s",end->password);
    end->Link = NULL;
    printf("\n%s",end->username);
    for(loop_counter = 0 ; loop_counter < users_number - 2 ; loop_counter++)
    {
        temp = malloc(sizeof(struct user));
        fscanf(user_opener, "%s",temp->username);
        fscanf(user_opener, "%*s%*s%*s%*s%*s%s",temp->password);
        printf("\n%s",temp->username);
        end->Link = temp;
        end = temp;
        end->Link = NULL;
    }

    printf("Please enter your username:\n");
    fflush(stdin);

    int wrong_username_input = 0 ;

    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        temp = start;
        gets(user_identifier.username);
        fflush(stdin);
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
    Sleep(1);
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
    int User_menu_value ;
    User_menu_value = User_menu(user_identifier.username,user_identifier.password);
    if(User_menu_value == 5)
    {
        fclose(user_opener);
        return User_menu_value ;
    }
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

int User_menu(char username[41] , char password[41])
{
    int User_choice , loop_counter ;
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        User_choice = User_Profile();
        if(User_choice == 1)
        {
            Income(username) ;
            loop_counter--;
        }
        else if(User_choice == 2)
        {
            Expense(username);
            loop_counter--;
        }
        else if(User_choice == 3)
        {
            statistics(username);
        }
        else if(User_choice == 4)
        {
            user_settings(username,password);
            loop_counter--;
        }
        else if(User_choice == 5)
        {
            return User_choice ;
            break;
        }
    }

}

void Graphic_profile_initialize()
{
    int loop_counter;
    for(loop_counter = 0 ; loop_counter < 5 ; loop_counter++)
    {
        printf("Initializing your profile");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
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
    fprintf(user_Data_File, "%d\n%f\n%d/%d/%d\n%s\n\n" ,-expense_type ,-amount ,year ,month ,day ,description );
    fclose(user_Data_File);
}

void user_settings(char User[41] , char password[41])
{
    system("cls");
    int user_desicion ;
    printf("Please choose what you want to change about your profile\n");
    printf("1.Username\n2.Name & Surname\n3.NID\n4.PhoneNumber\n5.Email\n6.Password\n7.All infos\n\n");
    printf("Please enter your choice>>");
    scanf("%d",&user_desicion);
    struct user{
        char username[41] ;
        char password[41] ;
        char name[41] ;
        char surname[41] ;
        char NID[11] ;
        char phonenumber[10] ;
        char Email[41] ;
        struct user *Link ;
    };
    char user_Current_Pass_Check[41] ;
    char user_New_Pass_Check[41] ;
    struct user *start , *end , *temp ;
    int loop_counter , wrong = 0 , users_number ;
    FILE *user_opener , *Holder , *user_counter ;
    start = malloc(sizeof(struct user));
    end = malloc(sizeof(struct user));


    user_counter = fopen("usercount.txt", "r");
    fscanf(user_counter, "%d", &users_number);
    fclose(user_counter);

    user_opener = fopen("users.txt", "r");
    fscanf(user_opener, "%s%s%s%s%*c%*c%s%s%s",start->username ,start->name ,start->surname ,start->NID ,start->phonenumber ,start->Email ,start->password);
    start->Link = end ;

    fscanf(user_opener, "%s%s%s%s%*c%*c%s%s%s",end->username ,end->name ,end->surname ,end->NID ,end->phonenumber ,end->Email ,end->password);
    end->Link = NULL;

    for(loop_counter = 0 ; loop_counter < users_number - 2 ; loop_counter++)
    {
        temp = malloc(sizeof(struct user));
        fscanf(user_opener, "%s%s%s%s%s%s%s",temp->username ,temp->name ,temp->surname ,temp->NID ,temp->phonenumber ,temp->Email ,temp->password);
        end->Link = temp;
        end = temp;
        end->Link = NULL;
    }
    fclose(user_opener);

    if(user_desicion == 1)
    {
        temp = start ;

        do
        {
            if(strcmp(temp->username,User) == 0)
            {
                printf("Please enter your new Username:");
                scanf("%40s",temp->username);
                break ;
            }
            else
            {
                temp=temp->Link;
            }
        }while(temp != NULL);
    }
    else if(user_desicion == 2)
    {
        temp = start ;

        do
        {
            if(strcmp(temp->username,User) == 0)
            {
                break ;
            }
            else
            {
                temp=temp->Link;
            }
        }while(temp != NULL);

        printf("Please enter your name:");
        scanf("%40s",temp->name);
        printf("surname?");
        scanf("%40s",temp->surname);
    }
    else if(user_desicion == 3)
    {
        temp = start ;

        do
        {
            if(strcmp(temp->username,User) == 0)
            {
                break ;
            }
            else
            {
                temp=temp->Link;
            }
        }while(temp != NULL);

        printf("Please enter your new national ID:");
        scanf("%10s",temp->NID);
    }
    else if(user_desicion == 4)
    {
        temp = start ;

        do
        {
            if(strcmp(temp->username,User) == 0)
            {
                break ;
            }
            else
            {
                temp=temp->Link;
            }
        }while(temp != NULL);

        printf("Please enter your new PhoneNumber:\n09");
        scanf("%9s",temp->phonenumber);
    }
    else if(user_desicion == 5)
    {
        temp = start ;

        do
        {
            if(strcmp(temp->username,User) == 0)
            {
            break ;
            }
            else
            {
                temp=temp->Link;
            }
        }while(temp != NULL);

        printf("Please enter your new Email:");
        scanf("%40s",temp->Email);
    }
    else if(user_desicion == 6)
    {
        temp = start ;

        int wrong_Pass_Input = 0 ;
        do
        {
            if(strcmp(temp->username,User) == 0)
            {
                break ;
            }
            else
            {
                temp=temp->Link;
            }
        }while(temp != NULL);

        printf("Please enter your current password:");
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            scanf("%40s",user_Current_Pass_Check);
            if(strcmp(password,user_Current_Pass_Check) != 0 )
            {
                if(wrong_Pass_Input == 4)
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
                    wrong_Pass_Input = 0 ;
                }
                else
                {
                    system("cls");
                    printf("Wrong password.\nReenter your password:");
                    Sleep(2000);
                    loop_counter--;
                    wrong_Pass_Input++;
                }
            }
            else
            {
                printf("Please enter your new password:");
                scanf("%40s",temp->password);
                fflush(stdin);

                Sleep(2000);
                system("cls");

                printf("Please enter your password again:");
                scanf("%40s",user_New_Pass_Check);

                password_equallity_check(temp->password,user_New_Pass_Check);

                printf("ALL DONE!");
                Sleep(2000);
                system("cls");
            }
        }
    }
    else if(user_desicion == 7)
    {
        temp = start ;

        int wrong_Pass_Input = 0 ;
        while(temp != NULL)
        {
            if(strcmp(temp->username,User) == 0)
            {
                break ;
            }
            else
            {
                temp=temp->Link;
            }
        }

        printf("Please use underline character('_') instead of space character(' ') in all parts.\n");
        printf("Please enter your new Username:");
        fflush(stdin);
        gets(temp->username);
        fflush(stdin);

        printf("Please enter your new name:");
        gets(temp->name);
        fflush(stdin);

        printf("Surname?");
        gets(temp->surname);
        fflush(stdin);

        printf("Please enter your new national Id:");
        gets(temp->NID);
        fflush(stdin);

        printf("Please enter your new PhoneNumber:\n09");
        gets(temp->phonenumber);
        fflush(stdin);

        printf("Please enter your new Email:");
        gets(temp->Email);
        fflush(stdin);

        Sleep(1000);
        system("cls");

        printf("Please enter your current password:");

        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            scanf("%40s",user_Current_Pass_Check);
            if(strcmp(password,user_Current_Pass_Check) != 0)
            {
                if(wrong_Pass_Input == 4)
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
                    wrong_Pass_Input = 0 ;
                }
                printf("You have entered your current password WRONG!\nTry again:");
                loop_counter--;
                wrong_Pass_Input++;
            }
            else
            {
                printf("Please enter your new password:");
                fflush(stdin);
                gets(temp->password);
                fflush(stdin);

                printf("Please enter your nwe password again:");
                gets(user_New_Pass_Check);
                fflush(stdin);

                password_equallity_check(temp->password,user_New_Pass_Check);

                printf("ALL DONE!");
                Sleep(2000);
                system("cls");
            }
        }
    }

    user_opener = fopen("users.txt", "w");
    temp = start ;
    do
    {
        fprintf(user_opener , "%s\n%s\n%s\n%s\n09%s\n%s\n%s\n",temp->username ,temp->name ,temp->surname ,temp->NID ,temp->phonenumber ,temp->Email , temp->password);
        temp=temp->Link ;
    }while(temp != NULL);
    fclose(user_opener);
}

int statistics(char User[41])
{
    system("cls");
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    int user_Choice;
    sprintf(user_Data_File_Name, "%s.txt",User);

    printf("Choose what statistics you want:\n\n");
    printf("1.Current account balance\t\t\t2.Specific year incomes\n\n3.Specific year expenses\t\t\t4.Incomes in a time interval\n\n");
    printf("5.Expenses in a time interval\t\t\t6.Specific income in a time interval\n\n7.Specific expense in a time interval\t\t8.Revenue share");
    printf("9.Cost share\t\t\n\n10.Details of income in a time interval\t\t11.DEtails of expense in a time interval\t\n\n12.Largest revenue figure\t\t\t");
    printf("13.Largest cost figure\n\n14.Search income descriptions for a word\t15.Search expense descriptions for a word\n\nPlease enter your choice:");
    scanf("%d",&user_Choice);
    fflush(stdin);
}
