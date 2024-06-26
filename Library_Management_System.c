#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

//Access Passwords.
char password[10]="library";
char passmain[10]="libpass";

//Structure for Books.

struct book
{
    int id;
    char name[20];
    char author[20];
    int copies;
    int copiesleft;
    float price;
}b,bc,be;

//Structure for Date.

struct date
{
    int dd,mm,yy;
};

//Structure for Users.

struct user
{
    int id;
    char name[20];
    int bookid;
    struct date issue;
    struct date due;
}u,uc;

FILE *pb,*pu;

//Declearation of Functions used.

void ascii_art(void);
void main_menu(void);
void admin(void);
void user(void);
void validexit(void);
void bookmenu(void);
void addbook(void);
void editbook(void);
void deletebook(int);
void usermenu(void);
void adduser(void);
void edituser(void);
void deleteuser(int);
void listbook(void);
void listuser(void);
void issuebook(void);
void collectbook(void);
void searchbook(void);
void userinfo(void);
int validbid(int);
int validuid(int);
int validdatecheck(struct date);
void duedate(void);
int fine(struct date,int);
void passesmain(void);
void exiting(void);
void lines(void);
void gotoxy(int,int);
int t(void);
int main(void);

//ASCII ART (LOGO) & Author Name.

void ascii_art()
{
printf("\n");
printf(" _     _ _                           ___  ___                                                  _     _____           _                 \n");
printf("| |   (_) |                          |  \\/  |                                                 | |   /  ___|         | |                \n");
printf("| |    _| |__  _ __ __ _ _ __ _   _  | .  . | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  \\ `--. _   _ ___| |_ ___ _ __ ___  \n");
printf("| |   | | '_ \\| '__/ _` | '__| | | | | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|  `--. \\ | | / __| __/ _ \\ '_ ` _ \\ \n");
printf("| |___| | |_) | | | (_| | |  | |_| | | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_  /\\__/ / |_| \\__ \\ ||  __/ | | | | |\n");
printf("\\_____/_|_.__/|_|  \\__,_|_|   \\__, | \\_|  |_/\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| \\____/ \\__, |___/\\__\\___|_| |_| |_|\n");
printf("                               __/ |                            __/ |                                       __/ |                      \n");
printf("                              |___/                            |___/                                       |___/                       \n");
printf("\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\tAuthor-  SAYAN MALAKAR.(V2.0)\n");
printf("____________________________________________________________________________________________________________________________________________\n");
}

//X and Y coordinates

COORD coord = {0, 0};

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Lines used.

void lines()
{
	gotoxy(30,13);
    printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
    gotoxy(30,14);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");

    gotoxy(30,52);
    printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
    gotoxy(30,53);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
}


//For TIME

int t(void)
{
    time_t t;
    time(&t);
    gotoxy(115,12);
    printf("%s\n",ctime(&t));
    return 0;
}

// Shows the exit screen

void exiting(void)  
{
	system("cls");
    ascii_art();

lines();
t();
gotoxy(70,7);
printf("\nLibrary Management System");
gotoxy(30,22);
printf("\t\tAuthor - SAYAN MALAKAR");
gotoxy(70,7);
gotoxy(30,20);
printf(" \n-------------------------------------------Exiting program----------------------------------------------");
Sleep(3000);
system("cls");
exit(0);
}

//Password checker to enter program.

void passesmain(void)
{
    int count =0;
    x:
    count++;
    system("cls");
    ascii_art();
    gotoxy(75,10);

    printf("LIBRARY");
    lines();
    t();
 
    gotoxy(80,215);

    printf("\nAtempts left: %d",3-count);

    gotoxy(65,20);

    printf("\nEnter Password: ");
    char str1[20];
    char ch;
    int i=0;

    gotoxy(83,20);

    while((ch=getch())!='\r' && i<20)
    {
        putch('*');
        str1[i++]=ch;
    }
    str1[i]='\0';


        if(strcmp(str1,passmain)==0)
        {
            
            gotoxy(101,29);

            printf("\nAuthentication Successful !");

            gotoxy(101,30);

            printf("\tPress any key to continue.");
            getch();
        }

        else
        {
            gotoxy(101,29);

            printf("\nInvalid Password !");

            gotoxy(101,30);

            printf("\tPress any key to re-enter password.");
            if(getch())
            if(count<3)
               goto x;

            exiting();
        }
        main_menu();
}

//Main Menu function to access.

void main_menu(void)
{
    int choice;
    do
    {
        system("cls");
        ascii_art();
        lines();
        t();

        gotoxy(75,10);

        printf("\nMain Menu");

        gotoxy(75,16);

        printf("\n1.Administrator ");

        gotoxy(75,18);

        printf("\t2.User ");

        gotoxy(75,20);

        printf("\t\t3.Exit ");

        gotoxy(70,25);

        printf("\t\tEnter your choice : \n");
        scanf("%d",&choice);


        switch(choice)
        {
            case 1: admin();
                    break;
            case 2: user();
                    break;
            case 3: validexit();
                    break;
            default:
            {
                gotoxy(101,30);

                printf("\nInvalid Choice !");
                getch();
            }


        }
    } while (1);
    getch();
    
}

// ADMINISTRATOR menu

void admin(void)  
{
    	int count=0;
    x:
	count++;
    system("cls");
    ascii_art();
    lines();
    t();
    
    gotoxy(75,7);

    printf("ADMINISTRATOR");
    
    gotoxy(105,11);

	printf("Attempt left : %d",3-count);
	
    gotoxy(65,20);

    printf("Enter password : ");
    char str[20];
    char ch;int i=0;

    gotoxy(83,20);

    while((ch=getch())!='\r'&&i<20)
    {
        putch('*');
        str[i++]=ch;
    }
    str[i]='\0';
    if(strcmp(str,password)==0)
        {
        	gotoxy(101,29);

            printf("Authentication successful");

            gotoxy(101,30);

            printf("Press any key to continue");
            getch();
        }
    else
        {
            gotoxy(101,29);

			printf("Invalid Password");

            gotoxy(101,30);

            printf("Press any key to re-enter password");
            if(getch())
            if(count<3)
            goto x;

            return;
        }

    int choice;
    do
    {
    system("cls");
    ascii_art();
    lines();
	t();
    
    gotoxy(75,7);

    printf("ADMINISTRATOR");

    gotoxy(75,12);

    printf("1. Add/Edit Book");
 
    gotoxy(75,14);

	printf("2. Add/Edit User");
	
    gotoxy(75,16);

	printf("3. List Books");

    gotoxy(75,18);

	printf("4. List Users");

    gotoxy(75,20);

	printf("5. Issue Book");

    gotoxy(75,22);

	printf("6. Collect Book");

    gotoxy(75,24);

	printf("7. Main Menu");

    gotoxy(75,26);

	printf("8. Exit");

    gotoxy(75,28);

	printf("Enter your choice : ");
    scanf("%d",&choice);


    switch(choice)
        {
            case 1: bookmenu();
                        break;
            case 2: usermenu();
                        break;
            case 3: listbook();
                        break;
            case 4: listuser();
                        break;
            case 5: issuebook();
                        break;
            case 6: collectbook();
                        break;
            case 7: return;
            case 8: validexit();
                        break;
            default:
			{
	
            gotoxy(101,30);

			printf("Invalid Choice ");
                    getch();
            }
        }
    }while(1);
}

//Book Menu function

void bookmenu(void) 
{
    int choice;
    do
    {
        system("cls");
        ascii_art();
		lines();
	    t();
		
        gotoxy(75,7);

        printf("BOOK MENU");
        
        gotoxy(75,12);

        printf("1. Add Book");
		
        gotoxy(75,14);

		printf("2. Edit Book Details");
		
        gotoxy(75,16);

		printf("3. Delete Book");
		
        gotoxy(75,18);

		printf("4. Administrator Menu");
		
        gotoxy(75,20);

		printf("5. Exit");
        
        gotoxy(75,24);

		printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:addbook();
                        break;
            case 2:editbook();
                        break;
            case 3:deletebook(0);
                        break;
            case 4:return;
            case 5:validexit();
                        break;
            default:
			{
			
            gotoxy(101,30);

			printf("Invalid Choice ");
                    getch();
            }
        }
    }while(1);
}

//Function to add books

void addbook(void) 
{

    char ch;

        label:
        pb=fopen("Books.txt","a");
        system("cls");
        ascii_art();
        lines();
	    t();

        gotoxy(75,7);

        printf("ADD BOOK");
       
        gotoxy(65,12);

		printf("Enter the following details : ");
  
        gotoxy(65,14);

		printf("BookId : ");
        scanf("%d",&b.id);
        if(validbid(b.id)==0)
        {
     
            gotoxy(65,16);

            printf("Book Name : ");
            scanf(" %[^\n]s",b.name);
        
            gotoxy(65,18);

			printf("Author Name : ");
            scanf(" %[^\n]s",b.author);
     
            gotoxy(65,20);

			printf("Number of copies :");
            scanf("%d",&b.copies);
    
            gotoxy(65,22);

            printf("Price :");
            scanf("%f",&b.price);

			b.copiesleft=b.copies;
            fwrite(&b,sizeof(struct book),1,pb);
       
            gotoxy(101,30);

			printf("Book Successfully added");

        }

        else
        {
            gotoxy(101,30);

            printf("BookId already exists ");
            getch();
            goto label;
        }
    fclose(pb);
 
        gotoxy(65,28);

			printf("Do you want to enter details of another book? (Y/N) : ");
            scanf(" %c",&ch);
            if(ch=='y')
            goto label;
    return;
}

//Function to check valid book id

int validbid(int id) 
{
    FILE *b;
    int i=0;
    b=fopen("Books.txt","r");
    while(!feof(b))
    {
        if(fread(&bc,sizeof(struct book),1,b)==1)
            if(bc.id==id)
        {
            i=1;
            break;
        }
    }
    fclose(b);
    return i;
}

//Function to edit book

void editbook(void) 
{
    int id,choice;
    char ch;
    system("cls");
    ascii_art();
    lines();
	t();
	
    gotoxy(75,7);

    printf("EDIT BOOK DETAILS");
   
    gotoxy(60,20);

    printf("Enter Book ID to edit : ");
    scanf("%d",&id);
    
    gotoxy(101,30);

	if(validbid(id)==1)
    {
        deletebook(id);
        struct book be;
        be=bc;
        l2:
        system("cls");
        ascii_art();
        lines();
        t();
        

        gotoxy(75,7);

        printf("Edit Book Details");

        gotoxy(60,14);

        printf("Existing Book Information : ");

        gotoxy(60,16);

		printf("BookId : %d ",be.id);

		gotoxy(60,18);

		printf("1. Book Name : %s",be.name);

		gotoxy(60,20);

		printf("2. Author : %s ",be.author);

		gotoxy(60,22);

		printf("3. Number of copies : %d ",be.copies);

        gotoxy(60,24);

		printf("4. Price : %.2f",be.price);

		gotoxy(60,26);

		printf("Enter the field to edit : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                
                gotoxy(60,28);

			    printf("Enter the new book name : ");
                scanf(" %[^\n]s",be.name);
                   break;

            case 2:

                gotoxy(60,28);

				printf("Enter the new author name : ");
                scanf(" %[^\n]s",be.author);
                break;

            case 3:

                gotoxy(60,28);

			    printf("Enter the new number of copies : ");
                int temp;
                temp=be.copies;
                    scanf("%d",&be.copies);
                    be.copiesleft=be.copiesleft+be.copies-temp;
                    break;

            case 4:
            
                gotoxy(60,28);

			    printf("Enter New Price : ");
			    scanf("%f",&be.price);
                break;

			default:
			      
                    gotoxy(101,30);

					printf("Invalid choice");
                    getch();
                    goto l2;
        }
       
        gotoxy(60,29);

        printf("Do you want to edit anything else ? (Y/N) : ");
        scanf(" %c",&ch);
        if(ch=='Y'||ch=='y')
                goto l2;
        pb=fopen("Books.txt","a");
        fwrite(&be,sizeof(struct book),1,pb);
        fclose(pb);
   
        gotoxy(101,30);

		printf("Book Successfully updated ");
        getch();
    }

    else
    {
        gotoxy(101,30);

        printf("Book ID does not exist");
        getch();
    }
    return;
}

//Function to delete book

void deletebook(int id) 
{
    FILE *temp;
    int flag=0;
    temp=fopen("temp.txt","w");
    if(id==0)
    {
        flag=1;
        label:
        system("cls");
        ascii_art();
        lines();
        t();

        gotoxy(75,7);

		printf("DELETE BOOK");
   
        gotoxy(60,20);

		printf("Enter Book ID to delete : ");
        scanf("%d",&id);

        if(validbid(id)==0)
        {          
            gotoxy(101,30);

			printf("Book ID does not exist");
            getch();
            goto label;
        }
    }

    pb=fopen("Books.txt","r");
    while(!feof(pb))
    {
        if(fread(&b,sizeof(struct book),1,pb)==1)
            if(b.id!=id)
                fwrite(&b,sizeof(struct book),1,temp);
    }

    fclose(pb);
    fclose(temp);
    remove("Books.txt");
    rename("temp.txt","Books.txt");

    if(flag)
    {
        gotoxy(101,30);

	    printf("Book successfully deleted");
        getch();
    }
    return;
}

//Function for user menu

void usermenu(void) 
{
    int choice;
    do
    {
        system("cls");
        ascii_art();
        lines();
        t();
     
        gotoxy(75,7);

        printf("USER MENU");

        gotoxy(60,12);

        printf("1. Add User ");

		gotoxy(60,14);

		printf("2. Edit User Details");

		gotoxy(60,16);

		printf("3. Delete User");

		gotoxy(60,18);

		printf("4. Administrator Menu");

		gotoxy(60,20);

		printf("5. Exit");

		gotoxy(60,22);

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:adduser();
                        break;
            case 2:edituser();
                        break;
            case 3:deleteuser(0);
                        break;
            case 4:return;
            case 5:validexit();
                        break;
            default:
                    
                    gotoxy(101,30);

			        printf("Invalid Choice");
                    getch();
        }
    }while(1);
}

//Function to add user

void adduser(void) 
{
    pu=fopen("Users.txt","a");
    char ch;
    do
    {
        label:
        system("cls");
        ascii_art();
        lines();
        t();
        
        gotoxy(75,7);

        printf("ADD USER");
   
        gotoxy(60,12);

        printf("Enter the following details : ");
        
        gotoxy(60,14);

        printf("User ID : ");
        scanf("%d",&u.id);

        if(validuid(u.id)==0)
        {
            gotoxy(60,16);

            printf("Name : ");
            scanf(" %[^\n]s",u.name);
            u.bookid=0;
            u.issue.dd=u.issue.mm=u.issue.yy=u.due.dd=u.due.mm=u.due.yy=0;
            fwrite(&u,sizeof(struct user),1,pu);

            gotoxy(101,30);

			printf("User Successfully added");
       
            gotoxy(60,22);

			printf("Do you want to add another user? (Y/N) : ");
            scanf(" %c",&ch);
        }

        else
        {
        	gotoxy(101,30);

            printf("User ID already exists");
            getch();
            goto label;
        }
    }while(ch=='Y'||ch=='y');
    fclose(pu);
    return;
}

//Function to check valid user id

int validuid(int id) 
{
    FILE *u;
    int i=0;
    u=fopen("Users.txt","r");
    while(!feof(u))
    {
        if(fread(&uc,sizeof(struct user),1,u)==1)
            if(uc.id==id)
        {
            i=1;
            break;
        }
    }
    fclose(u);
    return i;
}

//Function to edit user

void edituser(void) 
{
    int id,choice;
    char ch;
    system("cls");
    ascii_art();
    lines();
    t();
    printf("EDIT USER DETAILS");
   
    gotoxy(60,12);

    printf("Enter User ID to edit : ");
    scanf("%d",&id);
    if(validuid(id)==1)
    {
        deleteuser(id);
        struct user ue;
        ue=uc;
        l2:
 
        gotoxy(60,14);

        printf("Existing User Information : ");
 
        gotoxy(60,16);

		printf("1. User ID : %d ",ue.id);
	
        gotoxy(60,18);

		printf("2. User Name : %s ",ue.name);

        gotoxy(60,22);

		printf("Enter the field to edit : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: l1:
                    gotoxy(60,24);

                    printf("Enter the new userid : ");
                    scanf("%d",&ue.id);
                    if(validuid(ue.id)==1)
                    {   
                        gotoxy(101,30);

                        printf("User ID already exists");
                        getch();
                        goto l1;
                    }
                    break;

            case 2:
                    gotoxy(60,24);

				    printf("Enter the new user name");
                    scanf(" %[^\n]s",ue.name);
                    break;

            default:
                    gotoxy(101,30);
			
                    printf("Invalid choice");
                     getch();
                     goto l2;
        }
        gotoxy(60,26);

        printf("Do you want to edit anything else ? (Y/N) : ");
        scanf(" %c",&ch);
        if(ch=='Y'||ch=='y')
                goto l2;
        pu=fopen("Users.txt","a");
        fwrite(&ue,sizeof(struct user),1,pu);
        fclose(pu);

        gotoxy(101,30);

		printf("User Successfully updated ");
        getch();
    }

    else
    {
    	gotoxy(101,30);

        printf("User ID does not exist");
        getch();
    }
    return;
}

//Function to delete users

void deleteuser(int id) 
{
    FILE *temp;
    int flag=0;
    temp=fopen("temp.txt","w");
    if(id==0)
    {
        flag=1;
        label:
        system("cls");
        ascii_art();
        lines();
        t();
      
        gotoxy(75,7);

        printf("DElETE USER");
  
        gotoxy(60,20);

		printf("Enter the User ID to be deleted : ");
        scanf("%d",&id);

        if(validuid(id)==0)
        {
            gotoxy(101,30);

			printf("User ID does not exist");
            getch();
            goto label;
        }
    }
    pu=fopen("Users.txt","r");
    while(!feof(pu))
    {
        if(fread(&u,sizeof(struct user),1,pu)==1)
            if(u.id!=id)
                fwrite(&u,sizeof(struct user),1,temp);
    }
    fclose(pu);
    fclose(temp);
    remove("Users.txt");
    rename("temp.txt","Users.txt");
    
    if(flag)
    {
        gotoxy(101,30);

		printf("User deleted successfully");
        getch();
    }
    return;
}

//Function to view books

void listbook(void) 
{
    int i=0;
    pb=fopen("Books.txt","r");
    system("cls");
    ascii_art();
    t();

    gotoxy(30,9);

    printf(" ----------------------------------------------------------------------------------------------------------");

    gotoxy(30,11);

	printf(" ----------------------------------------------------------------------------------------------------------");

    gotoxy(75,7);

    printf("BOOK RECORD");

    gotoxy(40,10);

    printf("%5s   %20s   %20s   %5s    %12s   %11s","Id","Book Name","Author Name","Price","No.of Copies","Copies Left");

	while(!feof(pb))
    {
        if(fread(&b,sizeof(struct book),1,pb)==1)
        {
            gotoxy(40,13+i);

	printf("%5d   %20s   %20s   %.2f   %12d   %11d",b.id,b.name,b.author,b.price,b.copies,b.copiesleft);
		i++;
	    }
    }
    fclose(pb);
  
    gotoxy(115,30);

    printf("Press any key to continue");
    getch();
    return;
}

//Function to view users

void listuser(void) 
{
	int i=0;
    pu=fopen("Users.txt","r");
    system("cls");
    ascii_art();
    t();

    gotoxy(30,9);

    printf(" ----------------------------------------------------------------------------------------------------------");

    gotoxy(30,11);

	printf(" ----------------------------------------------------------------------------------------------------------");

    gotoxy(75,7);

    printf("USER RECORD");

    gotoxy(40,10);

	printf("%5s   %20s   %6s     %11s     %11s","Id","Name","BookId","Issue Date ","Due Date   ");
    while(!feof(pu))
    {
        if(fread(&u,sizeof(struct user),1,pu)==1)
        {
	
        gotoxy(40,13+i);

        printf("%5d   %20s   %6d     %2d-%2d-%4d     %2d-%2d-%4d",u.id,u.name,u.bookid,u.issue.dd,u.issue.mm,u.issue.yy,u.due.dd,u.due.mm,u.due.yy);
        i++;
	    }
	}
    fclose(pu);

    gotoxy(115,30);

	printf("Press any key to continue");
    getch();
    return;
    //return;
}

//Function to issue books

void issuebook(void) 
{
    system("cls");
    ascii_art();
    lines();
    t();
   
    gotoxy(75,7);

    printf("ISSUE BOOK");

    gotoxy(60,12);

	printf("Enter User ID : ");
    int idb,uid;
    scanf("%d",&uid);
    if(validuid(uid)==1)
    {
        if(uc.bookid>0)
        {
            gotoxy(101,30);

            printf("Maximum book availed");
            getch();
        }
        else
        {
        	gotoxy(60,14);

            printf("Enter Book ID to issue : ");
            scanf("%d",&idb);
            if(validbid(idb)==1)
            {
                if(bc.copiesleft==0)
                {
                    gotoxy(101,30);

                    printf("Book Unavailable");
                    getch();
                }
                else
                {
                    do
                    {
                        gotoxy(60,16);

                        printf("Enter date of issue : (dd-mm-yyyy) : ");
                        scanf("%d-%d-%d",&uc.issue.dd,&uc.issue.mm,&uc.issue.yy);
                        if(validdatecheck(uc.issue))
                            break;
                   
                        gotoxy(101,30);

						printf("Enter a valid date");
                        getch();
                    }while(1);
                    duedate();
         
                    gotoxy(60,18);

                    printf("Due date : %d-%d-%d ",uc.due.dd,uc.due.mm,uc.due.yy);
                    deleteuser(uc.id);
                    pu=fopen("Users.txt","a");
                    uc.bookid=idb;
                    fwrite(&uc,sizeof(struct user),1,pu);
                    fclose(pu);
                    deletebook(bc.id);
                    pb=fopen("Books.txt","a");
                    bc.copiesleft--;
                    fwrite(&bc,sizeof(struct book),1,pb);
                    fclose(pb);
           
                    gotoxy(101,30);

                    printf("Book Issued Successfully");
                    getch();
                }
            }
            else
            {
                gotoxy(101,30);

                printf("Book ID does not exist");
                getch();
            }
        }
    }
    else
    {
        gotoxy(101,30);

		printf("User ID does not exist");
        getch();
    }
    return;
}

//Function to check date

int validdatecheck(struct date a) 
{
    if((a.dd>=1)&&(a.dd<=30)&&(a.mm>=1)&&(a.mm<=12)&&(a.yy>2000))
        return 1;
    else
        return 0;
}

//Function to issue due date

void duedate(void) 
{
    uc.due=uc.issue;
    uc.due.dd+=15;
    if(uc.due.dd>15)
    {
        uc.due.dd-=15;
        uc.due.mm++;
        if(uc.due.mm>12)
        {
            uc.due.mm-=12;
            uc.due.yy++;
        }
    }
    return;
}

//Function to collect book

void collectbook(void) 
{
    system("cls");
    ascii_art();
    lines();
    t();
    
    gotoxy(75,7);

    printf("COLLECT BOOK");
    int uid;

    gotoxy(60,14);

    printf("Enter User ID : ");
    scanf("%d",&uid);

    if(validuid(uid)==0)
    {
        gotoxy(101,30);

		printf("User ID does not exist");
        getch();
    }

    else
    {
        if(uc.bookid==0)
        {
            gotoxy(101,30);

            printf("No book issued to User ID : d",uid);
            getch();
        }

        else
        {
            struct date r;
            int f;
            do
            {
                do
                {
                    gotoxy(60,16);

                    printf("Enter date of return : (dd-mm-yy) : ");
                    scanf("%d-%d-%d",&r.dd,&r.mm,&r.yy);
                    
                    if(validdatecheck(r))
                        break;
        
                    gotoxy(101,30);

					printf("Enter a valid date");
                    getch();
                }while(1);
                f=fine(r,0);
               
                if(f>0)
                {
                    gotoxy(60,18);

                    printf("Due date : %d-%d-%d",uc.due.dd,uc.due.mm,uc.due.yy);

                    gotoxy(60,20);

					printf("Fine : %d",f);
                    getch();
                    break;
                }
                
                else if(f<0)
                {
                    if(fine(r,1)<0)
                    {
                        gotoxy(101,29);
                        
                        printf("The issue date is %d-%d-%d",uc.issue.dd,uc.issue.mm,uc.issue.yy);
                
                        gotoxy(101,30);

						printf("Enter a date after the issue date");
                        getch();
                    }
                    
                    else
                        break;
                }
            }while(1);

            validbid(uc.bookid);
            bc.copiesleft++;
            deletebook(uc.bookid);
            pb=fopen("Books.txt","a");
            fwrite(&bc,sizeof(struct book),1,pb);
            fclose(pb);
            deleteuser(uid);
            uc.bookid=0;
            uc.issue.dd=uc.issue.mm=uc.issue.yy=uc.due.dd=uc.due.mm=uc.due.yy=0;
            pu=fopen("Users.txt","a");
            fwrite(&uc,sizeof(struct book),1,pu);
            fclose(pu);

            gotoxy(101,30);

            printf("Book Returned Successfully");
            getch();
        }
    }
    return;
}

//Function to check the fine

int fine(struct date r,int i) 
{
    int f;
    if(i)
    {
        f=(uc.issue.yy-r.yy)*360+(uc.issue.mm-r.mm)*30+uc.issue.dd-r.dd;
        return -f*3;
    }
    else
    {
        f=(uc.due.yy-r.yy)*360+(uc.due.mm-r.mm)*30+uc.due.dd-r.dd;
        return -f*3;
    }
}

//USER function

void user(void) 
{
    int choice;
    do
    {
        system("cls");
        ascii_art();
        lines();
        t();
     
        gotoxy(75,7);

        printf("USER MENU");
     
        gotoxy(60,12);

		printf("1. Search Book ");
	
        gotoxy(60,14);

		printf("2. UserInfo");
	
        gotoxy(60,16);

		printf("3. Main Menu");
	
        gotoxy(60,18);

		printf("4. Exit");

		gotoxy(60,20);

		printf("Enter your Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: searchbook();
                        break;
            case 2: userinfo();
                        break;
            case 3: main_menu();
                        break;
            case 4: validexit();
                        break;
            default:
                    gotoxy(101,30);

				    printf("Invalid Choice");
                    getch();
        }
    }while(1);
}

//Function to search book

void searchbook(void) 
{
    pb=fopen("Books.txt","r");
    char ch,name[20];int i;
    do
    {
        system("cls");
        ascii_art();
        lines();
        t();
        i=0;
        rewind(pb);
  
        gotoxy(75,7);

        printf("BOOK SEARCH ");
 
        gotoxy(60,12);

		printf("Enter the name of the book to search : ");
        scanf(" %[^\n]s",name);
        while(!feof(pb))
        {
            if(fread(&b,sizeof(struct book),1,pb)==1)
            if(strcmpi(b.name,name)==0)
            {
                i++;

                gotoxy(60,14);

                printf("Search Result : %d",i);

                gotoxy(60,16);

				printf("BookId : %d ",b.id);

				gotoxy(60,18);

				printf("Book Name : %s ",b.name);

				gotoxy(60,20);

				printf("Author : %s ",b.author);

				gotoxy(60,22);

				printf("Price : %.2f",b.price);

				gotoxy(60,24);

				printf("Number of copies : %d ",b.copies);

				gotoxy(60,26);

				printf("Number of copies left : %d",b.copiesleft);
            }
        }

    if(i==0)
    {
        gotoxy(101,30);

		printf("No such book found");
	}

    gotoxy(60,28);

    printf("Do you want to search for another book ? (Y/N) : ");
    scanf(" %c",&ch);
    }while(ch=='Y'||ch=='y');
    fclose(pb);
    return;
}

//Function to show user info

void userinfo(void) 
{
    pu=fopen("Users.txt","r");
    char ch;int id,i;
    do
    {
        system("cls");
        ascii_art();
        i=0;
        rewind(pu);
        lines();
        t();
      
        gotoxy(75,7);

        printf("USER INFORMATION");
      
        gotoxy(60,12);

		printf("Enter User ID : ");
        scanf(" %d",&id);
        while(!feof(pu))
        {
            if(fread(&u,sizeof(struct user),1,pu)==1)
            if(u.id==id)
            {
                i++;

                gotoxy(101,30);

                printf("Search Successful ");

                gotoxy(60,14);

				printf("UserId : %d ",u.id);

				gotoxy(60,16);

				printf("Name : %s",u.name);

				gotoxy(60,18);

				printf("Book Id : %d ",u.bookid);

				gotoxy(60,18);

				printf("Issue date : %d-%d-%d ",u.issue.dd,u.issue.mm,u.issue.yy);

				gotoxy(60,20);

				printf("Due Date : %d-%d-%d ",u.due.dd,u.due.mm,u.due.yy);
            }
        }
    if(i==0)
    {
        gotoxy(101,30);

        printf("No such user found");
    }

    gotoxy(60,28);

	printf("Do you want to search for another user ? (Y/N) : ");
    scanf(" %c",&ch);
    }while(ch=='Y'||ch=='y');
    fclose(pu);
    return;
}

//Function to validate the exit

void validexit(void) 
{
    system("cls");
    lines();
    t();
   
    gotoxy(60,20);

    printf("Do you want to exit ?(Y/N) : ");
    char ch;
    scanf(" %c",&ch);
    if(ch=='Y'||ch=='y')
    exiting();
    return;
}

//Main Function

int main(void)
{
    //system("mode con COLS=650");
    //ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
    //SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000);
    system("COLOR B0");
    system("cls");
    passesmain();
    return 0;
}