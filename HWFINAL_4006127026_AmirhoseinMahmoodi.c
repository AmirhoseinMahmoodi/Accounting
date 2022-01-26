#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>

int  mainmenu();
int  log_in();
int  Hold;
int  user_count;
int  User_menu(char username[41] , char password[41]);
int  NID_check(char NID[11]);
int  PhoneNumber_check(char phoneNumber[10]);
int  User_Profile();
int  user_settings(char User[41] , char password[41]);
int  statistics(char User[41]);
int  email_Check(char Email[41]);
int  password_Complexity_check(char password[41]);
int  non_Space_Check(char object[41]);
int  username_Validity_Check(char username[41]);
void intro();
void user_choice(int user_decision);
void sign_up();
void Hold_func();
void password_equallity_check(char defined_password[41], char password_cheker[41]);
void Graphic_profile_initialize();
void Income(char User[41]);
void Expense(char User[41]);
void Account_Balance(char User[41]);
void Specific_Year_Income(char User[41]);
void Specific_Year_Expense(char User[41]);
void Timed_Income(char User[41]);
void Timed_Expense(char User[41]);
void Specific_Timed_Income(char User[41]);
void Specific_Timed_Expense(char User[41]);
void Revenue_Share(char User[41]);
void Cost_Share(char User[41]);
void Timed_Income_Detail(char User[41]);
void Timed_Expense_Detail(char User[41]);
void Largest_Revenue(char User[41]);
void Largest_Cost(char User[41]);
void Search_income_descriptions(char User[41]);
void Search_expense_descriptions(char User[41]);

void main()
{
    int Hold;
    int user_decision;
    int loop_counter , log_in_value;
    intro();
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        Hold_func();
        user_decision = mainmenu();
        if(user_decision == 1)
        {
            log_in_value = log_in();
            if(log_in_value == 5)
            {
                system("cls");
                loop_counter--;
            }
        }

        if (user_decision == 2)
        {
                sign_up();
                loop_counter--;
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
    printf("%c\n\n",0xBC);

    printf("ATTENTION                                              ATTENTION\n");
    printf("         **For better experience maximize the window**");
    Sleep(5000);
}

int mainmenu()
{
    int loop_counter ;

    system("cls");
    char main_menu_value ;
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        printf("choose what you want to do with this program.\n");
        printf("1)log in\n2)sign up\n3)EXIT\n");
        printf("\n\nPlease enter your choice:");
        scanf("%d",&main_menu_value);
        fflush(stdin);

        if(main_menu_value != 1 && main_menu_value != 2 && main_menu_value != 3)
        {
            system("cls");
            printf("Pleae just enter numbers 1 to 3.\n");
            loop_counter--;
        }
    }

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
        for(loop_counter = 0 ; loop_counter < 300000 ; loop_counter++)
        {
            Sleep(1000);
            system("cls");
            printf("you have entered wrong password 5 times so the program will be banned for 5 minutes\nATTENTION - Do not restart the program ");
            printf("otherwise the timer will be reset.");
            printf("%d:%d",(300000-loop_counter)/60000,(300000-loop_counter)%60);
        }
        fopen("Hold.txt", "w");
        Hold = 0 ;
        fprintf(Holder, "%d",Hold);
        fclose(Holder);
    }
}

void sign_up()
{
    system("cls");
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

    struct username{
        char username[41] ;
        struct user *Link ;
    };
    struct username *start , *end , *temp ;

    FILE *user_opener , *user_counter ;

    user_counter = fopen("usercount.txt", "r");
    fscanf(user_counter, "%d",&user_count);
    fclose(user_counter);

    user_opener = fopen("Users.txt", "r");

    if(user_counter != NULL)
    {
        start = malloc(sizeof(struct username));
        fscanf(user_opener , "%s", start->username);
        start->Link = NULL ;

        if(user_count > 1)
        {
            end = malloc(sizeof(struct username));
            start->Link = end ;
            fscanf(user_opener , "%*s%*s%*s%*s%*s%*s%s", end->username);
            end->Link = NULL ;
        }
    }
    else
    {
        temp = NULL ;
    }

    int loop_counter ;
    if(user_count > 2)
    {
        for(loop_counter = 0 ; loop_counter < user_count - 2 ; loop_counter++)
        {
            temp = malloc(sizeof(struct username));
            end->Link = temp ;
            fscanf(user_opener , "%*s%*s%*s%*s%*s%*s%s", temp->username);
            printf("\n%s",temp->username);
            temp->Link = NULL ;
            end = temp ;
        }
    }
    fflush(stdin);


    printf("For all parts use underline ('_') instead of space character(' ')\n");
    printf("Please enter your username up to 40 characters:");
    int non_Space_Check_Value ;
    int username_Validity_Check_Value ;
    if(temp != NULL)
    {
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            gets(NewUser.username);
            non_Space_Check_Value = non_Space_Check(NewUser.username);
            if(non_Space_Check_Value == 1)
            {
                loop_counter--;
                continue ;
            }
            else
            {
                username_Validity_Check_Value = username_Validity_Check(NewUser.username);
                if(username_Validity_Check_Value == 1)
                {
                    loop_counter--;
                    continue ;
                }
            }
            temp = start ;
            while(temp != NULL)
            {
                if(strcmp(NewUser.username,temp->username) == 0)
                {
                    system("cls");
                    printf("For all parts use underline ('_') instead of space character(' ')\n");
                    printf("This username is taken already try another one:\n");
                    loop_counter-- ;
                    break ;
                }
                else
                {
                    temp=temp->Link ;
                }
            }
        }
    }
    else
    {
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            gets(NewUser.username);
            non_Space_Check_Value = non_Space_Check(NewUser.username);
            if(non_Space_Check_Value == 1)
            {
                loop_counter--;
            }
        }
    }

    fflush(stdin);
    printf("please enter your name:\n");
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        gets(NewUser.Name);
        fflush(stdin);
        non_Space_Check_Value = non_Space_Check(NewUser.Name);
        if(non_Space_Check_Value == 1)
        {
            loop_counter--;
        }
    }
    printf("surname?\n");
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        gets(NewUser.surname);
        fflush(stdin);
        non_Space_Check_Value = non_Space_Check(NewUser.surname);
        if(non_Space_Check_Value == 1)
        {
            loop_counter--;
        }
    }
    printf("Please enter your national ID code:\n");
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
    printf("Please enter your phone number:\n09");
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
    printf("Please enter your Email:\n");
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        gets(NewUser.Email);
        fflush(stdin);
        non_Space_Check_Value = non_Space_Check(NewUser.Email);
        if(non_Space_Check_Value == 1)
        {
            loop_counter--;
        }
    }
    system("cls");

    char pass_Char ;
    int   pass_Counter = 0 , loop_counter1 = 0;
    int   loop_counter2 ;
    int coplexity_Value ;
    for(loop_counter2 = 0 ; loop_counter2 < 1 ; loop_counter2++)
    {
        printf("Enter your password up to 40 characters\nTry to set a ");
        printf("complicated password using numbers , capital and small letters , and special characters(At least 8 characters):");
        loop_counter = 0 ;
        while ((pass_Char = _getch()) != 13 )
        {
            if(pass_Char == 8)
            {
                loop_counter--;
                if(pass_Counter != 0)
                {
                    pass_Counter--;
                }
                system("cls");
                printf("Enter your password up to 40 characters\nTry to set a ");
                printf("complicated password using numbers , capital and small letters , and special characters(At least 8 characters):");
                for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                {
                    printf("*");
                }
            }
            else
            {
                pass_Counter++;
                NewUser.password[loop_counter] = pass_Char ;
                system("cls");
                printf("Enter your password up to 40 characters\nTry to set a ");
                printf("complicated password using numbers , capital and small letters , and special characters(At least 8 characters):");
                for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                {
                    printf("*");
                }
                loop_counter++;
            }
        }
        NewUser.password[loop_counter] = '\0';
        fflush(stdin);

        non_Space_Check_Value = non_Space_Check(NewUser.password);
        if(non_Space_Check_Value == 1)
        {
            loop_counter2--;
            pass_Counter = 0 ;
        }
        else
        {
            coplexity_Value = password_Complexity_check(NewUser.password);
            if(coplexity_Value == 1)
            {
                loop_counter2--;
                pass_Counter = 0 ;
            }
        }
    }

    system("cls");
    printf("Enter your password again:");
    char pass_Check_Char ;
    int pass_Check_Counter = 0 ;
    loop_counter1 = 0 ;
    loop_counter = 0 ;
    while ((pass_Check_Char = _getch()) != 13 )
    {
        if(pass_Check_Char == 8)
        {
            loop_counter--;
            pass_Check_Counter--;
            system("cls");
            printf("Enter your password again:");
            for (loop_counter1 = 0 ; loop_counter1 < pass_Check_Counter ; loop_counter1++)
            {
                printf("*");
            }
        }
        else
        {
            pass_Check_Counter++;
            NewUser.pass_check[loop_counter] = pass_Check_Char ;
            system("cls");
            printf("Enter your password again:");
            for (loop_counter1 = 0 ; loop_counter1 < pass_Check_Counter ; loop_counter1++)
            {
                printf("*");
            }
            loop_counter++;
        }
    }
    NewUser.pass_check[loop_counter] = '\0';

    password_equallity_check(NewUser.password,NewUser.pass_check);
    user_opener = fopen("Users.txt", "a");
    fprintf(user_opener, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n",NewUser.username,NewUser.Name,NewUser.surname,NewUser.NID,NewUser.PhoneNumber,NewUser.Email,NewUser.password);
    user_counter = fopen("usercount.txt", "w");
    fprintf(user_counter,"%d",user_count+1);
    fclose(user_counter);
    fclose(user_opener);
}

int log_in()
{
    system("cls");
    struct user{
        char username[41] ;
        char password[41] ;
        struct user *Link ;
    }user_identifier;

    struct user *start , *end , *temp ;
    int loop_counter , wrong_Password_Input = 0 , users_number ;
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
        Sleep(2000);
        return 5;
    }
    fscanf(user_opener, "%s",start->username);
    fscanf(user_opener, "%*s%*s%*s%*s%*s%s",start->password);
    start->Link = NULL;
    if(users_number > 1)
    {
        start->Link = end;
        fscanf(user_opener, "%s",end->username);
        fscanf(user_opener, "%*s%*s%*s%*s%*s%s",end->password);
        end->Link = NULL;
    }
    for(loop_counter = 0 ; loop_counter < users_number - 2 ; loop_counter++)
    {
        printf("111");
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
    Sleep(1000);
    system("cls");
    printf("Please enter your password:\n");
    char pass_Char ;
    int  pass_Counter = 0 , loop_counter2 = 0 , loop_counter1;
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        pass_Counter = 0 ;
        loop_counter2 = 0 ;
        while ((pass_Char = _getch()) != 13 )
        {
            if(pass_Char == 8)
            {
                loop_counter2--;
                if(pass_Counter != 0)
                {
                    pass_Counter--;
                }
                system("cls");
                printf("Please enter your password:\n");
                for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                {
                        printf("*");
                }
            }
            else
            {
                pass_Counter++;
                user_identifier.password[loop_counter2] = pass_Char ;
                system("cls");
                printf("Please enter your password:\n");
                for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                {
                    printf("*");
                }
                loop_counter2++;
            }
        }
        user_identifier.password[loop_counter2] = '\0';

        if(strcmp(user_identifier.password,temp->password) != 0 )
        {
            if( wrong_Password_Input == 4 )
            {
                printf("\a");
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
                wrong_Password_Input = 0;

            }
            printf("Wrong password!!\nEnter your password again:\n");
            loop_counter--;
            wrong_Password_Input++;
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

int User_menu(char username[41] , char password[41])
{
    int User_choice , loop_counter ,stat_Value;
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
            stat_Value = statistics(username);
            if(stat_Value == 1)
            {
                loop_counter--;
            }
        }
        else if(User_choice == 4)
        {
            int settings_Value  ;
            settings_Value = user_settings(username,password);
            if(settings_Value == 0)
            {
                return 5 ;
            }
            else if(settings_Value == 1)
            {
                 loop_counter--;
            }
        }
        else if(User_choice == 5)
        {
            return User_choice ;
            break;
        }
    }
}

int User_Profile()
{
    int user_desicion ;
    int loop_counter ;
    system("cls");

    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        printf("Main menu\n1.Income\n2.Expenses\n3.Statistics\n4.Settings\n5.Sign out\n6.EXIT\n>>Please enter your choice:");
        scanf("%d",&user_desicion);
        fflush(stdin);
        if(user_desicion != 1 && user_desicion != 2 && user_desicion!=3 && user_desicion != 4 && user_desicion != 5 && user_desicion!= 6)
        {
            loop_counter--;
            system("cls");
            printf("Please just enter numbers 1 to 6.\n");
        }
    }

    fflush(stdin);
    return user_desicion ;
}

int username_Validity_Check(char username[41])
{
    int loop_counter = 0 ;
    int loop_counter2;
    int not_allowed[9] = {34,42,47,58,60,62,63,92,124};
    while(username[loop_counter] != '\0')
    {
        for(loop_counter2 = 0 ; loop_counter2 <= 8 ; loop_counter2++)
        {
            if(not_allowed[loop_counter2] == username[loop_counter])
            {
                printf("\nA username can not contain any of the following charactes:(\\/:*?<>|)\n");
                return 1 ;
            }
        }
        loop_counter++;
    }
    return 0 ;
}

int non_Space_Check(char object[41])
{
    int loop_counter ;
    while(object[loop_counter] != '\0')
    {
        if(object[loop_counter] == 32)
        {
            printf("Wrong.input.please use no spaces.\ntry again:\n");
            return 1 ;
        }
        loop_counter++;
    }
    return 0 ;
}

void password_equallity_check(char defined_password[41], char password_cheker[41])
{
    system("cls");

    int loop_counter ;
    char pass_Char ;
    int  pass_Counter ;
    int loop_counter1 = 0 ;
    int loop_counter2 ;

    for(loop_counter2 = 0 ; loop_counter2 < 1 ; loop_counter2++)
    {
        loop_counter = 0 ;
        pass_Counter = 0 ;
        if(strcmp(defined_password,password_cheker) != 0)
        {
            system("cls");
            printf("Passwords did not match\n Try again:");
            while ((pass_Char = _getch()) != 13 )
            {
                if(pass_Char == 8)
                {
                    loop_counter--;
                    if(pass_Counter != 0)
                    {
                        pass_Counter--;
                    }
                    system("cls");
                    printf("Passwords did not match\n Try again:");
                    for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                    {
                        printf("*");
                    }
                }
                else
                {
                    pass_Counter++;
                    password_cheker[loop_counter] = pass_Char ;
                    system("cls");
                    printf("Passwords did not match\n Try again:");
                    for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                    {
                        printf("*");
                    }
                    loop_counter++;
                }
            }
            password_cheker[loop_counter] = '\0';
            loop_counter2--;
        }
    }

}

int  password_Complexity_check(char password[41])
{
    int loop_counter ;
    int special_Character_Count = 0 ;
    int capital_Word_Count = 0 ;
    int small_Word_Count = 0 ;
    int number_Count = 0 ;
    int digit_Count = 1 ;
    int ascii ;
    for(loop_counter = 0 ; loop_counter < 40 ; loop_counter++)
    {
        if(password[loop_counter] == '\0')
        {
            break ;
        }
        ascii = password[loop_counter];
        if(ascii >= 48 && ascii <= 57)
        {
            number_Count++;
            digit_Count++;
        }
        else if(ascii >= 65 && ascii <=90)
        {
            capital_Word_Count++;
            digit_Count++;
        }
        else if(ascii >= 97 && ascii <= 122)
        {
            small_Word_Count++;
            digit_Count++;
        }
        else if((ascii >= 33 && ascii <= 47) || (ascii >= 58 && ascii <= 64) || (ascii >= 91 && ascii <= 96) || (ascii >= 123 && ascii <= 126))
        {
            special_Character_Count++;
            digit_Count++;
        }
    }
    if(special_Character_Count == 0 || small_Word_Count == 0 || capital_Word_Count == 0 || number_Count == 0 || digit_Count < 8)
    {
        system("cls");
        printf("\nNot complicated enough.try another one.\n");
        return 1 ;
    }
}

void Graphic_profile_initialize()
{
    int loop_counter;
    for(loop_counter = 0 ; loop_counter < 3 ; loop_counter++)
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
            if(NID[loop_counter] != '\0' || NID[loop_counter] == ' ')
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

void Income(char User[41])
{
    system("cls");
    FILE *user_Data_File ;
    char user_File_Name[46];
    int loop_counter ;
    int income_type ;
    sprintf(user_File_Name, "%s.txt",User);
    user_Data_File = fopen(user_File_Name, "a");
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        printf("You are entering your income information...\n\nPlease specify your income type\n");
        printf("1.Progrramming Salary\n2.YARANEH\n3.Pocket Money\n4.University grant\n>>Please enter your choice:");
        scanf("%d",&income_type);
        fflush(stdin);
        if(income_type != 1 && income_type != 2 && income_type != 3 && income_type != 4)
        {
            system("cls");
            printf("Wrong input.try again.\n\n");
            loop_counter--;
        }
    }
    float amount ;
    printf("Please enter the amount of your income in RIAL:");
    scanf("%f",&amount);
    fflush(stdin);
    printf("Please enter the date of income(YYYY/MM/DD):");
    int year , month , day ;
    scanf("%d%*c%d%*c%d",&year,&month,&day);
    fflush(stdin);
    printf("Please enter a short description:");
    char description[71];
    gets(description);
    fprintf(user_Data_File, "%d\n%s\n%d/%d/%d\n%f\n" ,income_type ,description ,year ,month ,day ,amount );
    fclose(user_Data_File);
}

void Expense(char User[41])
{
    system("cls");
    FILE *user_Data_File ;
    char user_File_Name[46];
    int loop_counter ;
    int expense_type ;
    sprintf(user_File_Name, "%s.txt",User);
    user_Data_File = fopen(user_File_Name, "a");
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        printf("You are entering your expense information\nPlease specify your expense type:");
        printf("Please specify your expense type\n");
        printf("1.Wearings\n2.Transportation\n3.Tuition fees\n4.Entertainment\n5.Mobile and Internet bill\n6.Medical expenses\n7.Charity donation");
        printf("\n\n>>Please enter your choice:");
        scanf("%d",&expense_type);
        fflush(stdin);
        if(expense_type != 1 && expense_type != 2 && expense_type != 3 && expense_type != 4 && expense_type != 5 && expense_type != 6 && expense_type != 7)
        {
            system("cls");
            printf("Wrong input.try again.\n");
            loop_counter--;
        }
    }
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
    fprintf(user_Data_File, "%d\n%s\n%d/%d/%d\n%f\n\n" ,-expense_type ,description ,year ,month ,day ,-amount );
    fclose(user_Data_File);
}

int user_settings(char User[41] , char password[41])
{
    int loop_counter2 ;
    int complexity_Value ;
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);
    system("cls");
    int user_desicion ;
    int loop_counter ;
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        printf("Please choose what you want to change about your profile\n");
        printf("1.Username\n2.Name & Surname\n3.NID\n4.PhoneNumber\n5.Email\n6.Password\n7.All infos\n8.Exit\n");
        printf("Please enter your choice:");
        scanf("%d",&user_desicion);
        if(user_desicion != 1 && user_desicion != 2 && user_desicion != 3 && user_desicion != 4 && user_desicion != 5 && user_desicion != 6 && user_desicion != 7 && user_desicion != 8)
        {
            system("cls");
            printf("Please just enter numbers 1 to 8.\n");
            loop_counter--;
        }
    }

    struct user
    {
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
    struct user *start , *end , *temp , *temp2;
    int wrong = 0 , users_number ;
    FILE *user_opener , *Holder , *user_counter ;

    user_counter = fopen("usercount.txt", "r");
    fscanf(user_counter, "%d", &users_number);
    fclose(user_counter);

    user_opener = fopen("users.txt", "r");

    fflush(stdin);
    start = malloc(sizeof(struct user));
    fscanf(user_opener, "%40s" , start->username);
    fscanf(user_opener, "%40s" , start->name);
    fscanf(user_opener, "%40s" , start->surname);
    fscanf(user_opener, "%10s" , start->NID);
    fscanf(user_opener, "%9s"  , start->phonenumber);
    fscanf(user_opener, "%40s" , start->Email);
    fscanf(user_opener, "%40s" , start->password);
    start->Link = NULL ;

    if(users_number > 1)
    {
        end = malloc(sizeof(struct user));
        start->Link = end ;
        fscanf(user_opener, "%40s" , end->username);
        fscanf(user_opener, "%40s" , end->name);
        fscanf(user_opener, "%40s" , end->surname);
        fscanf(user_opener, "%10s" , end->NID);
        fscanf(user_opener, "%9s"  , end->phonenumber);
        fscanf(user_opener, "%40s" , end->Email);
        fscanf(user_opener, "%40s" , end->password);
        end->Link = NULL;

        for(loop_counter = 0 ; loop_counter < users_number - 2 ; loop_counter++)
        {
            temp = malloc(sizeof(struct user));
            end->Link = temp;
            fscanf(user_opener, "%40s" , temp->username);
            fscanf(user_opener, "%40s" , temp->name);
            fscanf(user_opener, "%40s" , temp->surname);
            fscanf(user_opener, "%10s" , temp->NID);
            fscanf(user_opener, "%9s"  , temp->phonenumber);
            fscanf(user_opener, "%40s" , temp->Email);
            fscanf(user_opener, "%40s" , temp->password);
            end = temp ;
            end->Link = NULL ;
        }
    }
    fclose(user_opener);

    int non_Space_Check_Value ;

    fflush(stdin);

    if(user_desicion == 1)
    {
        char new_Username[41] ;
        int username_Validity_Check_Value ;

        temp = start ;

        do
        {
            if(strcmp(temp->username,User) == 0)
            {
                printf("Please use underline character('_') instead of space character(' ').\n");
                printf("Please enter your new Username:");
                for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
                {
                    gets(new_Username);
                    fflush(stdin);
                    non_Space_Check_Value = non_Space_Check(new_Username);
                    if(non_Space_Check_Value == 1)
                    {
                        loop_counter--;
                        continue ;
                    }
                    else
                    {
                        username_Validity_Check_Value = username_Validity_Check(new_Username);
                        if(username_Validity_Check_Value == 1)
                        {
                            loop_counter--;
                            continue ;
                        }
                    }
                    temp2 = start ;
                    while(temp2 != NULL)
                    {
                        if(strcmp(new_Username,temp2->username) == 0)
                        {
                            printf("This username is taken already try another one:\n");
                            loop_counter-- ;
                            break ;
                        }
                        else
                        {
                            temp2=temp2->Link ;
                        }
                    }
                }
                strcpy(temp->username,new_Username);
                break ;
            }
            else
            {
                temp=temp->Link;
            }
        }while(temp != NULL);

        char user_New_Data_File_Name[46] ;
        int rename_value ;
        sprintf(user_New_Data_File_Name, "%s.txt",temp->username);
        rename_value = rename(user_Data_File_Name,user_New_Data_File_Name);
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
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            gets(temp->name);
            fflush(stdin);
            non_Space_Check_Value = non_Space_Check(temp->name);
            if(non_Space_Check_Value == 1)
            {
                loop_counter--;
            }
        }
        printf("surname?");
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            gets(temp->surname);
            fflush(stdin);
            non_Space_Check_Value = non_Space_Check(temp->surname);
            if(non_Space_Check_Value == 1)
            {
                loop_counter--;
            }
        }

    }
    else if(user_desicion == 3)
    {
        char NID_Temp[11];
        temp = start ;
        for(loop_counter =  0 ; loop_counter < 1 ; loop_counter++)
        {
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
            fflush(stdin);
            gets(NID_Temp);
            if(NID_check(NID_Temp) == 1)
            {
                loop_counter--;
            }
            else
            {
                strcpy(temp->NID,NID_Temp);
            }
        }
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
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            gets(temp->Email);
            fflush(stdin);
            non_Space_Check_Value = non_Space_Check(temp->Email);
            if(non_Space_Check_Value == 1)
            {
                loop_counter--;
            }
        }
    }
    else if(user_desicion == 6)
    {
        int coplexity_Value ;
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

        system("cls");
        printf("Please enter your current password:");
        char pass_Char ;
        int  pass_Counter = 0 , loop_counter2 = 0 , loop_counter1;
        int loop_counter3 ;
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            pass_Counter = 0 ;
            loop_counter2 = 0 ;
            while ((pass_Char = _getch()) != 13 )
            {
                if(pass_Char == 8)
                {
                    loop_counter2--;
                    if(pass_Counter != 0)
                    {
                        pass_Counter--;
                    }
                    system("cls");
                    if(wrong_Pass_Input != 0)
                    {
                        printf("Wrong password.\nReenter your password:");
                    }
                    else
                    {
                        printf("Please enter your current password:");
                    }
                    for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                    {
                        printf("*");
                    }
                }
                else
                {
                    pass_Counter++;
                    user_Current_Pass_Check[loop_counter2] = pass_Char ;
                    system("cls");
                    if(wrong_Pass_Input != 0)
                    {
                        printf("Wrong password.\nReenter your password:");
                    }
                    else
                    {
                        printf("Please enter your current password:");
                    }
                    for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                    {
                        printf("*");
                    }
                    loop_counter2++;
                }
            }
            user_Current_Pass_Check[loop_counter2] = '\0';
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
                    Sleep(4000);
                    loop_counter--;
                    wrong_Pass_Input++;
                }
            }
            else
            {
                system("cls");
                printf("Please enter your new password:");
                for(loop_counter3 = 0 ; loop_counter3 < 1 ; loop_counter3++)
                {
                    pass_Counter = 0 ;
                    loop_counter2 = 0 ;
                    while ((pass_Char = _getch()) != 13 )
                    {
                        if(pass_Char == 8)
                        {
                            loop_counter2--;
                            if(pass_Counter != 0)
                            {
                                pass_Counter--;
                            }
                            system("cls");
                            printf("Please enter your new password:");
                            for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                            {
                                printf("*");
                            }
                        }
                        else
                        {
                            pass_Counter++;
                            temp->password[loop_counter2] = pass_Char ;
                            system("cls");
                            printf("Please enter your new password:");
                            for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                            {
                                printf("*");
                            }
                            loop_counter2++;
                        }
                    }
                    temp->password[loop_counter2] = '\0';
                    fflush(stdin);

                    non_Space_Check_Value = non_Space_Check(temp->password);
                    if(non_Space_Check_Value == 1)
                    {
                        loop_counter3-- ;
                        pass_Counter = 0 ;
                    }
                    else
                    {
                        coplexity_Value = password_Complexity_check(temp->password);
                        if(coplexity_Value == 1)
                        {
                            loop_counter3-- ;
                            pass_Counter = 0 ;
                        }
                    }
                }
                Sleep(1000);
                system("cls");

                printf("Please enter your password again:");
                pass_Counter = 0 ;
                loop_counter2 = 0 ;
                while ((pass_Char = _getch()) != 13 )
                {
                    if(pass_Char == 8)
                    {
                        loop_counter2--;
                        if(pass_Counter != 0)
                        {
                            pass_Counter--;
                        }
                        system("cls");
                        printf("Please enter your password again:");
                        for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                        {
                            printf("*");
                        }
                    }
                    else
                    {
                        pass_Counter++;
                        user_New_Pass_Check[loop_counter2] = pass_Char ;
                        system("cls");
                        printf("Please enter your password again:");
                        for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                        {
                            printf("*");
                        }
                        loop_counter2++;
                    }
                }
                user_New_Pass_Check[loop_counter2] = '\0';

                password_equallity_check(temp->password,user_New_Pass_Check);

                printf("ALL DONE!");
                Sleep(2000);
                system("cls");
            }
        }
    }
    else if(user_desicion == 7)
    {
        int  coplexity_Value ;
        int  username_Validity_Check_Value ;
        int  rename_value ;
        int  wrong_Pass_Input = 0 ;
        int  pass_Counter ;
        int  loop_counter1 ;
        int  loop_counter ;
        int  loop_counter2 ;
        int  loop_counter3 ;
        char pass_Char ;
        char user_New_Data_File_Name[46] ;
        char new_Username[41] ;

        temp = start ;
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
        fflush(stdin);

        printf("Please use underline character('_') instead of space character(' ') in all parts.\n");
        printf("Please enter your new Username:");
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            gets(new_Username);
            temp2 = start ;
            while(temp2 != NULL)
            {
                if(strcmp(new_Username,temp2->username) == 0)
                {
                    printf("This username is taken already try another one:\n");
                    loop_counter--;
                    break;
                }
                temp2 = temp2->Link ;
            }

            non_Space_Check_Value = non_Space_Check(new_Username);
            if(non_Space_Check_Value != 1)
            {
                username_Validity_Check_Value = username_Validity_Check(new_Username);
                if(username_Validity_Check_Value != 1)
                {
                    strcpy(temp->username,new_Username);
                }
                else
                {
                    loop_counter--;
                }
            }
        }


        printf("Please enter your new name:");
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            gets(temp->name);
            fflush(stdin);
            non_Space_Check_Value = non_Space_Check(temp->name);
            if(non_Space_Check_Value == 1)
            {
                loop_counter--;
            }
        }

        printf("Surname?");
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            gets(temp->surname);
            fflush(stdin);
            non_Space_Check_Value = non_Space_Check(temp->surname);
            if(non_Space_Check_Value == 1)
            {
                loop_counter--;
            }
        }

        int NID_Check_Value ;
        printf("Please enter your new national Id:");
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            gets(temp->NID);
            NID_Check_Value = NID_check(temp->NID);
            if(NID_Check_Value == 1)
            {
                loop_counter--;
            }
        }
        fflush(stdin);

        printf("Please enter your new PhoneNumber:\n09");
        int PhoneNumber_check_value ;
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            gets(temp->phonenumber);
            fflush(stdin);
            PhoneNumber_check_value = PhoneNumber_check(temp->phonenumber);

            if(PhoneNumber_check_value == 1)
            {
                loop_counter--;
                system("cls");
            }
        }


        printf("Please enter your new Email:");
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            gets(temp->Email);
            fflush(stdin);
            non_Space_Check_Value = non_Space_Check(temp->Email);
            if(non_Space_Check_Value == 1)
            {
                loop_counter--;
            }
        }

        Sleep(1000);

        system("cls");
        printf("Please enter your current password:");
        for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
        {
            pass_Counter = 0 ;
            loop_counter2 = 0 ;
            while ((pass_Char = _getch()) != 13 )
            {
                if(pass_Char == 8)
                {
                    loop_counter2--;
                    if(pass_Counter != 0)
                    {
                        pass_Counter--;
                    }
                    system("cls");
                    if(wrong_Pass_Input != 0)
                    {
                        printf("You have entered your current password WRONG!\nTry again:");
                    }
                    else
                    {
                        printf("Please enter your current password:");
                    }
                    for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                    {
                        printf("*");
                    }
                }
                else
                {
                    pass_Counter++;
                    user_Current_Pass_Check[loop_counter2] = pass_Char ;
                    if(wrong_Pass_Input != 0)
                    {
                        system("cls");
                        printf("You have entered your current password WRONG!\nTry again:");
                    }
                    else
                    {
                        system("cls");
                        printf("Please enter your current password:");
                    }
                    for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                    {
                        printf("*");
                    }
                    loop_counter2++;
                }
            }
            user_Current_Pass_Check[loop_counter2] = '\0';

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
                system("cls");
                printf("You have entered your current password WRONG!\nTry again:");
                loop_counter--;
                wrong_Pass_Input++;
            }
        }
        system("cls");
        for(loop_counter3 = 0 ; loop_counter3 < 1 ; loop_counter3++)
        {
            printf("Please enter your new password:");
            fflush(stdin);
            pass_Counter = 0 ;
            loop_counter2 = 0 ;
            while ((pass_Char = _getch()) != 13 )
            {
                if(pass_Char == 8)
                {
                    loop_counter2--;
                    if(pass_Counter != 0)
                    {
                        pass_Counter--;
                    }
                    system("cls");
                    printf("Please enter your new password:");
                    for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                    {
                        printf("*");
                    }
                }
                else
                {
                    pass_Counter++;
                    temp->password[loop_counter2] = pass_Char ;
                    system("cls");
                    printf("Please enter your new password:");
                    for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                    {
                        printf("*");
                    }
                    loop_counter2++;
                }
            }
            temp->password[loop_counter2] = '\0';
            non_Space_Check_Value = non_Space_Check(temp->password);
            if(non_Space_Check_Value == 1)
            {
                loop_counter3--;
            }
            else
            {
                complexity_Value = password_Complexity_check(temp->password);
                if(complexity_Value == 1)
                {
                    loop_counter3--;
                }
                fflush(stdin);
            }
        }
        system("cls");
        printf("Please enter your new password again:");
        pass_Counter = 0 ;
        loop_counter2 = 0 ;
        while ((pass_Char = _getch()) != 13 )
        {
            if(pass_Char == 8)
            {
                loop_counter2--;
                if(pass_Counter != 0)
                {
                    pass_Counter--;
                }
                system("cls");
                printf("Please enter your new password again:");
                for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                {
                    printf("*");
                }
            }
            else
            {
                pass_Counter++;
                user_New_Pass_Check[loop_counter2] = pass_Char ;
                system("cls");
                printf("Please enter your new password again:");
                for (loop_counter1 = 0 ; loop_counter1 < pass_Counter ; loop_counter1++)
                {
                    printf("*");
                }
                loop_counter2++;
            }
        }
        user_New_Pass_Check[loop_counter2] = '\0';
        fflush(stdin);
        sprintf(user_New_Data_File_Name, "%s.txt",temp->username);
        rename_value = rename(user_Data_File_Name,user_New_Data_File_Name);
    }
    else if(user_desicion == 8)
    {
        return 1 ;
    }

    user_opener = fopen("users.txt", "w");
    temp = start ;
    do
    {
        fprintf(user_opener , "%s\n%s\n%s\n%s\n%s\n%s\n%s\n",temp->username ,temp->name ,temp->surname ,temp->NID ,temp->phonenumber ,temp->Email , temp->password);
        temp=temp->Link ;
    }while(temp != NULL);

    fclose(user_opener);
    system("cls");
    printf("ALL DONE!");
    Sleep(1000);
    system("cls");
    return 0 ;
}

int statistics(char User[41])
{
    system("cls");

    int loop_counter , user_Choice ;
    for(loop_counter = 0 ; loop_counter < 1 ; loop_counter++)
    {
        printf("Choose what statistics you want:\n\n");
        printf("1.Current account balance\t\t\t2.Specific year incomes\n\n3.Specific year expenses\t\t\t4.Incomes in a time interval\n\n");
        printf("5.Expenses in a time interval\t\t\t6.Specific income in a time interval\n\n7.Specific expense in a time interval\t\t8.Revenue share\n\n");
        printf("9.Cost share\t\t\t\t\t10.Details of income in a time interval\t\t\n\n11.Details of expense in a time interval\t12.Largest revenue figure\t\t\t\n\n");
        printf("13.Largest cost figure\t\t\t\t14.Search income descriptions for a word\n\n15.Search expense descriptions for a word\n\n16.EXIT\n\nPlease enter your choice:");
        scanf("%d",&user_Choice);
        fflush(stdin);

        if(user_Choice < 1 || user_Choice >16)
        {
            system("cls");
            printf("Wrong input\n");
            loop_counter--;
        }
        else if(user_Choice == 1)
        {
            Account_Balance(User);
            loop_counter--;
        }
        else if(user_Choice == 2)
        {
            Specific_Year_Income(User);
            loop_counter--;
        }
        else if(user_Choice == 3)
        {
            Specific_Year_Expense(User);
            loop_counter--;
        }
        else if(user_Choice == 4)
        {
            Timed_Income(User);
            loop_counter--;
        }
        else if(user_Choice == 5)
        {
            Timed_Expense(User);
            loop_counter--;
        }
        else if(user_Choice == 6)
        {
            Specific_Timed_Income(User);
            loop_counter--;
        }
        else if(user_Choice == 7)
        {
            Specific_Timed_Expense(User);
            loop_counter--;
        }
        else if(user_Choice == 8)
        {
            Revenue_Share(User);
            loop_counter--;
        }
        else if(user_Choice == 9)
        {
            Cost_Share(User);
            loop_counter--;
        }
        else if(user_Choice == 10)
        {
            Timed_Income_Detail(User);
            loop_counter--;
        }
        else if(user_Choice == 11)
        {
            Timed_Expense_Detail(User);
            loop_counter--;
        }
        else if(user_Choice == 12)
        {
            Largest_Revenue(User);
            loop_counter--;
        }
        else if(user_Choice == 13)
        {
            Largest_Cost(User);
            loop_counter--;
        }
        else if(user_Choice == 14)
        {
            Search_income_descriptions(User);
            loop_counter--;
        }
        else if(user_Choice == 15)
        {
            Search_expense_descriptions(User);
            loop_counter--;
        }
        else if(user_Choice == 16)
        {
            return 1 ;
        }
    }
}

void Account_Balance(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    float account_balance = 0 ;
    temp = start ;
    while(temp != NULL)
    {
        account_balance = account_balance + temp->money_Amount ;
        temp = temp->Link ;
    }
    system("cls");
    printf("Your account balance is :%f\n",account_balance) ;
}

void Specific_Year_Income(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    int specific_Year ;
    float Total ;
    printf("Please enter the specific year:");
    scanf("%d",&specific_Year);
    fflush(stdin);
    temp = start ;
    while(temp != NULL)
    {
        if(temp->money_Type > 0)
        {
            if(temp->year == specific_Year)
            {
                Total += temp->money_Amount ;
            }
        }
        temp = temp->Link ;
    }
    system("cls");
    printf("Your total income of year %d is:%f\n",specific_Year ,Total); ;
}

void Specific_Year_Expense(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    int specific_Year ;
            float Total ;
            printf("Please enter the specific year:");
            scanf("%d",&specific_Year);
            fflush(stdin);
            temp = start ;
            while(temp != NULL)
            {
                if(temp->money_Type < 0)
                {
                    if(temp->year == specific_Year)
                    {
                        Total += temp->money_Amount ;
                    }
                }
                temp = temp->Link ;
            }
            system("cls");
            printf("Your total expense of year %d is:%f\n",specific_Year ,Total); ;
}

void Timed_Income(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    int B_year ,B_month ,B_day ;
            printf("Please enter the beginning of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&B_year ,&B_month ,&B_day );
            fflush(stdin);

            int E_year ,E_month ,E_day ;
            printf("Please enter the end of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&E_year ,&E_month ,&E_day);
            fflush(stdin);

            temp = start;
            float Total = 0 ;
            while(temp != NULL)
            {
                if(temp->money_Type > 0)
                {
                    if(temp->year == B_year)
                    {
                        if(temp->month > B_month)
                        {
                            Total += temp->money_Amount ;
                        }
                        else if(B_month == temp->month)
                        {
                            if(temp->day >= B_day)
                            {
                                Total += temp->money_Amount ;
                            }
                        }
                    }
                    else if(temp->year == E_year)
                    {
                        if(temp->month < E_month)
                        {
                            Total += temp->money_Amount ;
                        }
                        else if(temp->month == E_month)
                        {
                            if(temp->day <= E_day)
                            {
                                Total += temp->money_Amount ;
                            }
                        }
                    }
                    else if(temp->year > B_year && temp->year < E_year)
                    {
                        Total += temp->money_Amount ;
                    }
                }
                temp = temp->Link ;
            }
            system("cls");
            printf("The total income in the interval is:%f\n",Total);
}

void Timed_Expense(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    int B_year ,B_month ,B_day ;
            printf("Please enter the beginning of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&B_year ,&B_month ,&B_day );
            fflush(stdin);

            int E_year ,E_month ,E_day ;
            printf("Please enter the end of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&E_year ,&E_month ,&E_day);
            fflush(stdin);

            temp = start;
            float Total = 0 ;
            while(temp != NULL)
            {
                if(temp->money_Type < 0)
                {
                    if(temp->year == B_year)
                    {
                        if(temp->month > B_month)
                        {
                            Total += temp->money_Amount ;
                        }
                        else if(B_month == temp->month)
                        {
                            if(temp->day >= B_day)
                            {
                                Total += temp->money_Amount ;
                            }
                        }
                    }
                    else if(temp->year == E_year)
                    {
                        if(temp->month < E_month)
                        {
                            Total += temp->money_Amount ;
                        }
                        else if(temp->month == E_month)
                        {
                            if(temp->day <= E_day)
                            {
                                Total += temp->money_Amount ;
                            }
                        }
                    }
                    else if(temp->year > B_year && temp->year < E_year)
                    {
                        Total += temp->money_Amount ;
                    }
                }
                temp = temp->Link ;
            }
            system("cls");
            printf("The total expense in the interval is:%f\n",Total);
}

void Specific_Timed_Income(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    int B_year ,B_month ,B_day ,income_Type ;
            printf("Please enter the beginning of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&B_year ,&B_month ,&B_day );
            fflush(stdin);

            int E_year ,E_month ,E_day ;
            printf("Please enter the end of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&E_year ,&E_month ,&E_day);
            fflush(stdin);

            system("cls");
            printf("Please specify the income type:\n");
            printf("1.Programming Salary\n2.YARANEH\n3.Pocket Money\n4.University grant\n>>Please enter your choice:");
            scanf("%d",&income_Type);

            temp = start;
            float Total = 0 ;
            while(temp != NULL)
            {
                if(temp->money_Type == income_Type)
                {
                    if(temp->year == B_year)
                    {
                        if(temp->month > B_month)
                        {
                            Total += temp->money_Amount ;
                        }
                        else if(B_month == temp->month)
                        {
                            if(temp->day >= B_day)
                            {
                                Total += temp->money_Amount ;
                            }
                        }
                    }
                    else if(temp->year == E_year)
                    {
                        if(temp->month < E_month)
                        {
                            Total += temp->money_Amount ;
                        }
                        else if(temp->month == E_month)
                        {
                            if(temp->day <= E_day)
                            {
                                Total += temp->money_Amount ;
                            }
                        }
                    }
                    else if(temp->year > B_year && temp->year < E_year)
                    {
                        Total += temp->money_Amount ;
                    }
                }
                temp = temp->Link ;
            }
            system("cls");
            printf("The total income in the interval of that type is:%f\n",Total);
}

void Specific_Timed_Expense(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    int B_year ,B_month ,B_day ,expense_Type ;
            printf("Please enter the beginning of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&B_year ,&B_month ,&B_day );
            fflush(stdin);

            int E_year ,E_month ,E_day ;
            printf("Please enter the end of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&E_year ,&E_month ,&E_day);
            fflush(stdin);

            system("cls");
            printf("Please specify the expense type:\n");
            printf("1.Wearings\n2.Transportation\n3.Tuition fees\n4.Entertainment\n5.Mobile and Internet bill\n6.Medical expenses\n7.Charity donation");
            printf("\n\n>>Please enter your choice:");
            scanf("%d",&expense_Type);

            temp = start;
            float Total = 0 ;
            while(temp != NULL)
            {
                if(temp->money_Type == -expense_Type)
                {
                    if(temp->year == B_year)
                    {
                        if(temp->month > B_month)
                        {
                            Total += temp->money_Amount ;
                        }
                        else if(B_month == temp->month)
                        {
                            if(temp->day >= B_day)
                            {
                                Total += temp->money_Amount ;
                            }
                        }
                    }
                    else if(temp->year == E_year)
                    {
                        if(temp->month < E_month)
                        {
                            Total += temp->money_Amount ;
                        }
                        else if(temp->month == E_month)
                        {
                            if(temp->day <= E_day)
                            {
                                Total += temp->money_Amount ;
                            }
                        }
                    }
                    else if(temp->year > B_year && temp->year < E_year)
                    {
                        Total += temp->money_Amount ;
                    }
                }
                temp = temp->Link ;
            }
            system("cls");
            printf("The total expense in the interval of that type is:%f\n",-Total);
}

void Revenue_Share(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    int B_year ,B_month ,B_day ;
            printf("Please enter the beginning of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&B_year ,&B_month ,&B_day );
            fflush(stdin);

            int E_year ,E_month ,E_day ;
            printf("Please enter the end of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&E_year ,&E_month ,&E_day);
            fflush(stdin);

            temp = start;
            float Total = 0 ;
            while(temp != NULL)
            {
                if(temp->money_Type > 0)
                {
                    if(temp->year == B_year)
                    {
                        if(temp->month > B_month)
                        {
                            Total += temp->money_Amount ;
                        }
                        else if(B_month == temp->month)
                        {
                            if(temp->day >= B_day)
                            {
                                Total += temp->money_Amount ;
                            }
                        }
                    }
                    else if(temp->year == E_year)
                    {
                        if(temp->month < E_month)
                        {
                            Total += temp->money_Amount ;
                        }
                        else if(temp->month == E_month)
                        {
                            if(temp->day <= E_day)
                            {
                                Total += temp->money_Amount ;
                            }
                        }
                    }
                    else if(temp->year > B_year && temp->year < E_year)
                    {
                        Total += temp->money_Amount ;
                    }
                }
                temp = temp->Link ;
            }
            float total_Salary ;
            temp = start ;
            while(temp != NULL)
            {
                if(temp->money_Type == 1)
                {
                    total_Salary += temp->money_Amount ;
                }
                temp = temp->Link ;
            }
            float total_Yaraneh ;
            temp = start ;
            while(temp != NULL)
            {
                if(temp->money_Type == 2)
                {
                    total_Yaraneh += temp->money_Amount ;
                }
                temp = temp->Link ;
            }
            float total_Pocket_Money ;
            temp = start ;
            while(temp != NULL)
            {
                if(temp->money_Type == 3)
                {
                    total_Pocket_Money += temp->money_Amount ;
                }
                temp = temp->Link ;
            }
            float total_Grant ;
            temp = start ;
            while(temp != NULL)
            {
                if(temp->money_Type == 4)
                {
                    total_Grant += temp->money_Amount ;
                }
                temp = temp->Link ;
            }
            system("cls");
            printf("The revenues share is:\n1.Programming salary:%f %%\t2.YARANEH:%f %%\n3.Pocket money:%f %%\t4.University grant:%f %%\n\n",((total_Salary/Total)*100) ,((total_Yaraneh/Total)*100) ,((total_Pocket_Money/Total)*100) ,((total_Grant/Total)*100));
}

void Cost_Share(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    int B_year ,B_month ,B_day ;
            printf("Please enter the beginning of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&B_year ,&B_month ,&B_day );
            fflush(stdin);

            int E_year ,E_month ,E_day ;
            printf("Please enter the end of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&E_year ,&E_month ,&E_day);
            fflush(stdin);

            temp = start;
            float Total = 0 ;
            while(temp != NULL)
            {
                if(temp->money_Type < 0)
                {
                    if(temp->year == B_year)
                    {
                        if(temp->month > B_month)
                        {
                            Total += -temp->money_Amount ;
                        }
                        else if(B_month == temp->month)
                        {
                            if(temp->day >= B_day)
                            {
                                Total += -temp->money_Amount ;
                            }
                        }
                    }
                    else if(temp->year == E_year)
                    {
                        if(temp->month < E_month)
                        {
                            Total += -temp->money_Amount ;
                        }
                        else if(temp->month == E_month)
                        {
                            if(temp->day <= E_day)
                            {
                                Total += -temp->money_Amount ;
                            }
                        }
                    }
                    else if(temp->year > B_year && temp->year < E_year)
                    {
                        Total += -temp->money_Amount ;
                    }
                }
                temp = temp->Link ;
            }
            float total_Wearing ;
            temp = start ;
            while(temp != NULL)
            {
                if(temp->money_Type == -1)
                {
                    total_Wearing += -temp->money_Amount ;
                }
                temp = temp->Link ;
            }
            float total_Transport ;
            temp = start ;
            while(temp != NULL)
            {
                if(temp->money_Type == -2)
                {
                    total_Transport += -temp->money_Amount ;
                }
                temp = temp->Link ;
            }
            float total_Tuition ;
            temp = start ;
            while(temp != NULL)
            {
                if(temp->money_Type == -3)
                {
                    total_Tuition += -temp->money_Amount ;
                }
                temp = temp->Link ;
            }
            float total_Entertainment ;
            temp = start ;
            while(temp != NULL)
            {
                if(temp->money_Type == -4)
                {
                    total_Entertainment += -temp->money_Amount ;
                }
                temp = temp->Link ;
            }
            float total_Mobile_Bill ;
            temp = start ;
            while(temp != NULL)
            {
                if(temp->money_Type == -5)
                {
                    total_Mobile_Bill += -temp->money_Amount ;
                }
                temp = temp->Link ;
            }
            float total_Medical ;
            temp = start ;
            while(temp != NULL)
            {
                if(temp->money_Type == -6)
                {
                    total_Medical += -temp->money_Amount ;
                }
                temp = temp->Link ;
            }
            float total_Charity ;
            temp = start ;
            while(temp != NULL)
            {
                if(temp->money_Type == -7)
                {
                    total_Charity += -temp->money_Amount ;
                }
                temp = temp->Link ;
            }
            system("cls");
            printf("The revenues share is:\n1.WEarings:%f %%\t\t\t\t2.Transportations:%f %%\n\n3.Tuition fees:%f %%\t\t\t4.Entertainment:%f %%",((total_Wearing/Total)*100) ,((total_Transport/Total)*100) ,((total_Tuition/Total)*100) ,((total_Entertainment/Total)*100));
            printf("\n\n5.Mobile and Internet bill:%f %%\t\t6.Medical expenses:%f %%\n\n\t\t\t7.Charity:%f %%\n\n",((total_Mobile_Bill/Total)*100) ,((total_Medical/Total)*100) ,((total_Charity/Total)*100));
}

void Timed_Income_Detail(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    int B_year ,B_month ,B_day ;
            printf("Please enter the beginning of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&B_year ,&B_month ,&B_day );
            fflush(stdin);

            int E_year ,E_month ,E_day ;
            printf("Please enter the end of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&E_year ,&E_month ,&E_day);
            fflush(stdin);

            system("cls");

            temp = start;
            while(temp != NULL)
            {
                if(temp->money_Type > 0)
                {
                    if(temp->year == B_year)
                    {
                        if(temp->month > B_month)
                        {
                            if(temp->money_Type == 1)
                            {
                                printf("Programming Salary\n");
                            }
                            else if(temp->money_Type == 2)
                            {
                                printf("YARANRH\n");
                            }
                            else if(temp->money_Type == 3)
                            {
                                printf("Pocket money\n");
                            }
                            else if(temp->money_Type == 4)
                            {
                                printf("University Grant\n");
                            }
                            printf("Description: %s",temp->description);
                            printf("Date:%d/%d/%d\n",temp->year ,temp->month ,temp->day);
                            printf("Money amount:%f RIAL\n\n",temp->money_Amount);
                        }
                        else if(B_month == temp->month)
                        {
                            if(temp->day >= B_day)
                            {
                            if(temp->money_Type == 1)
                            {
                                printf("Programming Salary\n");
                            }
                            else if(temp->money_Type == 2)
                            {
                                printf("YARANRH\n");
                            }
                            else if(temp->money_Type == 3)
                            {
                                printf("Pocket money\n");
                            }
                            else if(temp->money_Type == 4)
                            {
                                printf("University Grant\n");
                            }
                            printf("Description: %s",temp->description);
                            printf("Date:%d/%d/%d\n",temp->year ,temp->month ,temp->day);
                            printf("Money amount:%f RIAL\n\n",temp->money_Amount);
                            }
                        }
                    }
                    else if(temp->year == E_year)
                    {
                        if(temp->month < E_month)
                        {
                            if(temp->money_Type == 1)
                            {
                                printf("Programming Salary\n");
                            }
                            else if(temp->money_Type == 2)
                            {
                                printf("YARANRH\n");
                            }
                            else if(temp->money_Type == 3)
                            {
                                printf("Pocket money\n");
                            }
                            else if(temp->money_Type == 4)
                            {
                                printf("University Grant\n");
                            }
                            printf("Description: %s",temp->description);
                            printf("Date:%d/%d/%d\n",temp->year ,temp->month ,temp->day);
                            printf("Money amount:%f RIAL\n\n",temp->money_Amount);
                        }
                        else if(temp->month == E_month)
                        {
                            if(temp->day <= E_day)
                            {
                                if(temp->money_Type == 1)
                                {
                                    printf("Programming Salary\n");
                                }
                                else if(temp->money_Type == 2)
                                {
                                    printf("YARANRH\n");
                                }
                                else if(temp->money_Type == 3)
                                {
                                    printf("Pocket money\n");
                                }
                                else if(temp->money_Type == 4)
                                {
                                    printf("University Grant\n");
                                }
                                printf("Description: %s",temp->description);
                                printf("Date:%d/%d/%d\n",temp->year ,temp->month ,temp->day);
                                printf("Money amount:%f RIAL\n\n",temp->money_Amount);
                            }
                        }
                    }
                    else if(temp->year > B_year && temp->year < E_year)
                    {
                        if(temp->money_Type == 1)
                        {
                            printf("Programming Salary\n");
                        }
                        else if(temp->money_Type == 2)
                        {
                            printf("YARANRH\n");
                        }
                        else if(temp->money_Type == 3)
                        {
                            printf("Pocket money\n");
                        }
                        else if(temp->money_Type == 4)
                        {
                            printf("University Grant\n");
                        }
                        printf("Description: %s",temp->description);
                        printf("Date:%d/%d/%d\n",temp->year ,temp->month ,temp->day);
                        printf("Money amount:%f RIAL\n\n",temp->money_Amount);
                    }
                }
                temp = temp->Link ;
            }
}

void Timed_Expense_Detail(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    int B_year ,B_month ,B_day ;
            printf("Please enter the beginning of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&B_year ,&B_month ,&B_day );
            fflush(stdin);

            int E_year ,E_month ,E_day ;
            printf("Please enter the end of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&E_year ,&E_month ,&E_day);
            fflush(stdin);

            system("cls");

            temp = start;
            while(temp != NULL)
            {
                if(temp->money_Type < 0)
                {
                    if(temp->year == B_year)
                    {
                        if(temp->month > B_month)
                        {
                            if(temp->money_Type == -1)
                            {
                                printf("Wearings\n");
                            }
                            else if(temp->money_Type == -2)
                            {
                                printf("Transportation\n");
                            }
                            else if(temp->money_Type == -3)
                            {
                                printf("Tuition fees\n");
                            }
                            else if(temp->money_Type == -4)
                            {
                                printf("Entertainment\n");
                            }
                            else if(temp->money_Type == -5)
                            {
                                printf("Mobile and Internet bill\n");
                            }
                            else if(temp->money_Type == -6)
                            {
                                printf("Medical expenses\n");
                            }
                            else if(temp->money_Type == -7)
                            {
                                printf("Charity donation\n");
                            }
                            printf("Description: %s",temp->description);
                            printf("Date:%d/%d/%d\n",temp->year ,temp->month ,temp->day);
                            printf("Money amount:%f RIAL\n\n",-temp->money_Amount);
                        }
                        else if(B_month == temp->month)
                        {
                            if(temp->day >= B_day)
                            {
                                if(temp->money_Type == -1)
                                {
                                    printf("Wearings\n");
                                }
                                else if(temp->money_Type == -2)
                                {
                                    printf("Transportation\n");
                                }
                                    else if(temp->money_Type == -3)
                                {
                                    printf("Tuition fees\n");
                                }
                                else if(temp->money_Type == -4)
                                {
                                    printf("Entertainment\n");
                                }
                                else if(temp->money_Type == -5)
                                {
                                    printf("Mobile and Internet bill\n");
                                }
                                else if(temp->money_Type == -6)
                                {
                                    printf("Medical expenses\n");
                                }
                                else if(temp->money_Type == -7)
                                {
                                    printf("Charity donation\n");
                                }
                                printf("Description: %s",temp->description);
                                printf("Date:%d/%d/%d\n",temp->year ,temp->month ,temp->day);
                                printf("Money amount:%f RIAL\n\n",-temp->money_Amount);
                            }
                        }
                    }
                    else if(temp->year == E_year)
                    {
                        if(temp->month < E_month)
                        {
                            if(temp->money_Type == -1)
                            {
                                printf("Wearings\n");
                            }
                            else if(temp->money_Type == -2)
                            {
                                printf("Transportation\n");
                            }
                            else if(temp->money_Type == -3)
                            {
                                printf("Tuition fees\n");
                            }
                            else if(temp->money_Type == -4)
                            {
                                printf("Entertainment\n");
                            }
                            else if(temp->money_Type == -5)
                            {
                                printf("Mobile and Internet bill\n");
                            }
                            else if(temp->money_Type == -6)
                            {
                                printf("Medical expenses\n");
                            }
                            else if(temp->money_Type == -7)
                            {
                                printf("Charity donation\n");
                            }
                            printf("Description: %s",temp->description);
                            printf("Date:%d/%d/%d\n",temp->year ,temp->month ,temp->day);
                            printf("Money amount:%f RIAL\n\n",-temp->money_Amount);
                        }
                        else if(temp->month == E_month)
                        {
                            if(temp->day <= E_day)
                            {
                                if(temp->money_Type == -1)
                                {
                                    printf("Wearings\n");
                                }
                                else if(temp->money_Type == -2)
                                {
                                    printf("Transportation\n");
                                }
                                else if(temp->money_Type == -3)
                                {
                                    printf("Tuition fees\n");
                                }
                                else if(temp->money_Type == -4)
                                {
                                    printf("Entertainment\n");
                                }
                                else if(temp->money_Type == -5)
                                {
                                    printf("Mobile and Internet bill\n");
                                }
                                else if(temp->money_Type == -6)
                                {
                                    printf("Medical expenses\n");
                                }
                                else if(temp->money_Type == -7)
                                {
                                    printf("Charity donation\n");
                                }
                                printf("Description: %s",temp->description);
                                printf("Date:%d/%d/%d\n",temp->year ,temp->month ,temp->day);
                                printf("Money amount:%f RIAL\n\n",-temp->money_Amount);
                            }
                        }
                    }
                    else if(temp->year > B_year && temp->year < E_year)
                    {
                            if(temp->money_Type == -1)
                            {
                                printf("Wearings\n");
                            }
                            else if(temp->money_Type == -2)
                            {
                                printf("Transportation\n");
                            }
                            else if(temp->money_Type == -3)
                            {
                                printf("Tuition fees\n");
                            }
                            else if(temp->money_Type == -4)
                            {
                                printf("Entertainment\n");
                            }
                            else if(temp->money_Type == -5)
                            {
                                printf("Mobile and Internet bill\n");
                            }
                            else if(temp->money_Type == -6)
                            {
                                printf("Medical expenses\n");
                            }
                            else if(temp->money_Type == -7)
                            {
                                printf("Charity donation\n");
                            }
                            printf("Description: %s",temp->description);
                            printf("Date:%d/%d/%d\n",temp->year ,temp->month ,temp->day);
                            printf("Money amount:%f RIAL\n\n",-temp->money_Amount);
                    }
                }
                temp = temp->Link ;
            }
}

void Largest_Revenue(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    int B_year ,B_month ,B_day ;
            printf("Please enter the beginning of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&B_year ,&B_month ,&B_day );
            fflush(stdin);

            int E_year ,E_month ,E_day ;
            printf("Please enter the end of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&E_year ,&E_month ,&E_day);
            fflush(stdin);

            temp = start;
            float Maximum = 0 ;
            while(temp != NULL)
            {
                if(temp->money_Type > 0)
                {
                    if(temp->year == B_year)
                    {
                        if(temp->month > B_month)
                        {
                            if(temp->money_Amount > Maximum)
                            {
                                Maximum = temp->money_Amount ;
                            }
                        }
                        else if(B_month == temp->month)
                        {
                            if(temp->day >= B_day)
                            {
                                if(temp->money_Amount > Maximum)
                                {
                                    Maximum = temp->money_Amount ;
                                }
                            }
                        }
                    }
                    else if(temp->year == E_year)
                    {
                        if(temp->month < E_month)
                        {
                            if(temp->money_Amount > Maximum)
                            {
                                Maximum = temp->money_Amount ;
                            }
                        }
                        else if(temp->month == E_month)
                        {
                            if(temp->day <= E_day)
                            {
                                if(temp->money_Amount > Maximum)
                                {
                                    Maximum = temp->money_Amount ;
                                }
                            }
                        }
                    }
                    else if(temp->year > B_year && temp->year < E_year)
                    {
                        if(temp->money_Amount > Maximum)
                        {
                            Maximum = temp->money_Amount ;
                        }
                    }
                }
                temp = temp->Link ;
            }
            system("cls");
            printf("The Maximum amount of the incomes in the interval is: %f RIAL\n\n",Maximum);
}

void Largest_Cost(char User[41])
{
    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    int B_year ,B_month ,B_day ;
            printf("Please enter the beginning of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&B_year ,&B_month ,&B_day );
            fflush(stdin);

            int E_year ,E_month ,E_day ;
            printf("Please enter the end of the interval(YYYY/MM/DD):");
            scanf("%d%*c%d%*c%d",&E_year ,&E_month ,&E_day);
            fflush(stdin);

            temp = start;
            float Maximum = 0 ;
            while(temp != NULL)
            {
                if(temp->money_Type < 0)
                {
                    if(temp->year == B_year)
                    {
                        if(temp->month > B_month)
                        {
                            if(-temp->money_Amount > Maximum)
                            {
                                Maximum = temp->money_Amount ;
                            }
                        }
                        else if(B_month == temp->month)
                        {
                            if(temp->day >= B_day)
                            {
                                if(-temp->money_Amount > Maximum)
                                {
                                    Maximum = temp->money_Amount ;
                                }
                            }
                        }
                    }
                    else if(temp->year == E_year)
                    {
                        if(temp->month < E_month)
                        {
                            if(-temp->money_Amount > Maximum)
                            {
                                Maximum = temp->money_Amount ;
                            }
                        }
                        else if(temp->month == E_month)
                        {
                            if(temp->day <= E_day)
                            {
                                if(-temp->money_Amount > Maximum)
                                {
                                    Maximum = temp->money_Amount ;
                                }
                            }
                        }
                    }
                    else if(temp->year > B_year && temp->year < E_year)
                    {
                        if(-temp->money_Amount > Maximum)
                        {
                            Maximum = temp->money_Amount ;
                        }
                    }
                }
                temp = temp->Link ;
            }
            system("cls");
            printf("The Maximum amount of the expenses in the interval is: %f RIAL\n\n",-Maximum);
}

void Search_income_descriptions(char User[41])
{
    system("cls");

    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    char Word[11];
    int Word_counter ;
    printf("Please enter the word you want to search for(from 2 to 10 characters):");
    scanf("%10s",Word);
    fflush(stdin);

    Word_counter = strlen(Word);
    int loop_counter ;
    int loop_counter2 = 0 ;
    int same ;
    temp = start;
    do
    {
        same = 0 ;
        for(loop_counter = 0 ; loop_counter < Word_counter ; loop_counter++)
        {
            if(temp->description[loop_counter2] == Word[loop_counter])
            {
                same++;
            }
            else
            {
                same = 0 ;
                loop_counter--;
            }
            loop_counter2++;
        }
        if(same == strlen(Word))
        {
            if(temp->money_Type > 0)
            {
                printf("\nMoney type:");
                if(temp->money_Type == 1)
                {
                    printf("Programming Salary\n");
                }
                else if(temp->money_Type == 2)
                {
                    printf("YARANRH\n");
                }
                else if(temp->money_Type == 3)
                {
                    printf("Pocket money\n");
                }
                else if(temp->money_Type == 4)
                {
                    printf("University Grant\n");
                }
                printf("Description:%sMoney amount:%f\nDate:%d\\%d\\%d\n\n",temp->description ,temp->money_Amount ,temp->year ,temp->month ,temp->day);
            }
        }
        temp=temp->Link ;
        loop_counter2 = 0 ;
    }while(temp != NULL);
}

void Search_expense_descriptions(char User[41])
{
    system("cls");

    FILE *user_Data_File ;
    char user_Data_File_Name[46];
    sprintf(user_Data_File_Name, "%s.txt",User);

    struct IE
    {
        int money_Type ;
        float money_Amount ;
        int year ;
        int month ;
        int day ;
        char description[41] ;
        struct IE *Link ;
    };

    struct IE *start , *end , *temp ;
    start = malloc(sizeof(struct IE)) ;
    end = malloc(sizeof(struct IE)) ;

    user_Data_File = fopen(user_Data_File_Name , "r") ;

    fscanf(user_Data_File, "%d",&start->money_Type);
    fgets(start->description , 40 , user_Data_File);
    fgets(start->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&start->year ,&start->month ,&start->day ,&start->money_Amount);
    start->Link = end ;

    fscanf(user_Data_File, "%d",&end->money_Type);
    fgets(end->description , 40 , user_Data_File);
    fgets(end->description , 40 , user_Data_File);
    fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&end->year ,&end->month ,&end->day ,&end->money_Amount);
    end->Link = NULL;


    do
    {
        temp = malloc(sizeof(struct IE));
        fscanf(user_Data_File, "%d",&temp->money_Type);
        if(temp->money_Type > 4 || temp->money_Type < -7)
        {
            break ;
        }
        else if(temp->money_Type < 1 && temp->money_Type > -1)
        {
            break ;
        }
        fgets(temp->description , 40 , user_Data_File);
        fgets(temp->description , 40 , user_Data_File);
        fscanf(user_Data_File, "%d%*c%d%*c%d%f" ,&temp->year ,&temp->month ,&temp->day ,&temp->money_Amount);
        end->Link = temp;
        end = temp;
        end->Link = NULL;

    }while(1);

    char Word[11];
    int Word_counter ;
    printf("Please enter the word you want to search for(from 2 to 10 characters):");
    scanf("%10s",Word);
    fflush(stdin);

    Word_counter = strlen(Word);
    int loop_counter ;
    int loop_counter2 = 0 ;
    int same ;
    temp = start;
    do
    {
        same = 0 ;
        for(loop_counter = 0 ; loop_counter < Word_counter ; loop_counter++)
        {
            if(temp->description[loop_counter2] == Word[loop_counter])
            {
                same++;
            }
            else
            {
                same = 0 ;
                loop_counter--;
            }
            loop_counter2++;
        }
        if(same == strlen(Word))
        {
            if(temp->money_Type < 0)
            {
                printf("\nExpense type:");
                if(temp->money_Type == -1)
                {
                    printf("Wearings\n");
                }
                else if(temp->money_Type == -2)
                {
                    printf("Transportation\n");
                }
                else if(temp->money_Type == -3)
                {
                    printf("Tuition fees\n");
                }
                else if(temp->money_Type == -4)
                {
                    printf("Entertainment\n");
                }
                else if(temp->money_Type == -5)
                {
                    printf("Mobile and Internet bill\n");
                }
                else if(temp->money_Type == -6)
                {
                    printf("Medical expenses\n");
                }
                else if(temp->money_Type == -7)
                {
                    printf("Charity donation\n");
                }
                printf("Description:%sExpense amount:%f\nDate:%d\\%d\\%d\n\n",temp->description ,temp->money_Amount ,temp->year ,temp->month ,temp->day);
            }
        }
        temp=temp->Link ;
        loop_counter2 = 0 ;
    }while(temp != NULL);
}
