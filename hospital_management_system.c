#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
char ans=0;
int ok;
int b,valid=0;
//function declaration
void WelcomeScreen(void);
void Title(void);
void MainMenu(void);
void LoginScreen(void);
void Add_rec(void);
void func_list();
void Search_rec(void);
void Edit_rec(void);
void Dlt_rec(void);
void ex_it(void);
void SearchByDoctorName(void);
void gotoxy(short x, short y)
{
    COORD pos ={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
//list of global variable
struct patient
{
int Age;
char Gender;
char First_Name[20];
char Last_Name[20];
char Contact_No[13];
char Address[50];
char Email[30];
char Doctor_Name[20];
char Disease[20];
};
struct patient p,temp_c;
main(void)
{
    WelcomeScreen();
    Title();
    LoginScreen();
	return 0;
}
/*--------------------->welcome screen<------------------------------*/
void WelcomeScreen(void)
{
printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
printf("\n\t\t\t\t#\t\t Welcome To\t\t#");
printf("\n\t\t\t\t# AHMEDABAD HOSPITAL MANAGEMENT SYSTEM\t#");
printf("\n\t\t\t\t#########################################");
printf("\n\n\n\n\n Press Any Key To Continue.........\n");
getch();
system("cls");
}

/*------------------------->title screen<-------------------------*/
void Title(void)	
{
printf("\n\n\t\t-----------------------------------------------------------------------------");
printf("\n\t\t\t\t		AHMEDABAD HOSPITAL		");
printf("\n\n\t\t-----------------------------------------------------------------------------");
}
/*----------------------->main menu<-------------------------------*/
void MainMenu(void)
{
	system("cls");
	int choose;
	Title();
	printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
	printf("\n\t\t\t\t2. List Patients Record\n");
	printf("\n\t\t\t\t3. Search Patients Record\n");
	printf("\n\t\t\t\t4. Edit Patients Record\n");
	printf("\n\t\t\t\t5. Delete Patients Record\n");
	printf("\n\t\t\t\t6. Search Patients by Doctor Name\n");
	printf("\n\t\t\t\t7. Exit Patients Record\n");
	
	printf("\n\n\n\n\t\t\t\tChoose from 1 to 7:");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			Add_rec();
			break;
		case 2:
			func_list();
			break;	
		case 3:
			Search_rec();
			break;
		case 4:
			Edit_rec();
			break;
		case 5:
			Dlt_rec();
			break;
		case 6:
			SearchByDoctorName();
			break;
		case 7:
			ex_it();
			break;
		default:
			printf("\t\t\tInvalid entry. Please enter right Option :)");
			getch();
	}
}
/*------------------->exit screen<------------------------------*/
void ex_it(void)
{
	system("cls");
	Title();
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VSITING :)");
	getch();
}
/*----------------------->login screen<------------------------------*/
void LoginScreen(void)
{
    int e = 0;
    char Username[15];
    char Password[15];
    char original_Username[15] = "admin";
    char original_Password[15] = "1234";

    do
    {
        printf("\n\n\n\n\t\t\t\t Enter Your Username: ");
        scanf("%s", Username);
        printf("\n\n\n\t\t\t\t\t PASSWORD: ");
        int i = 0;
        while (1)
        {
            Password[i] = _getch();
            if (Password[i] == 13) // 13 is the ASCII code for Enter
            {
                Password[i] = '\0';
                break;
            }
            else
            {
                printf("*");
            }
            i++; 
        }

        if (strcmp(Username, original_Username) == 0 && strcmp(Password, original_Password) == 0)
        {
            printf("\n\n\n\t\t\t\t\t...Login Successful...");
            getch();
            MainMenu();
            break;
        }
        else
        {
            printf("\n\t\t\tPassword is incorrect. Try Again :)");
            e++;
            getch();
        }
    } while (e <= 2);

    if (e > 2)
    {
        printf("\nYou have crossed the limit. You cannot login. :(");
        getch();
        ex_it();
    }
    system("cls");
}

void Add_rec(void)
{
	system("cls");
	Title();
	//list of variable
	char ans;
	FILE *ek;//file pointer
	ek=fopen("Record2.dat","a");

	printf("\n\n\t\t\t!!!!!!!!!! Add Patients Record !!!!!!!!!!\n");
	//------------------->first name<-------------
	A:
	printf("\n\t\t\tFirst Name:");
	scanf("%s",p.First_Name);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto A;
	}
	else 
	{
		for(b=0;b<strlen(p.First_Name);b++)
		{
			if(isalpha(p.First_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name containt Invalid character :(  Enter Again :)");
			goto A;
		}
	}
	/*----------------------->last name<-----------------------*/
	B:
	printf("\n\t\t\tLast Name: ");
	scanf("%s",p.Last_Name);
	p.Last_Name[0]=toupper(p.Last_Name[0]);
	if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto B;
	}
	else 
	{
		for(b=0;b<strlen(p.Last_Name);b++)
		{
			if(isalpha(p.Last_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name containt Invalid character :(  Enter Again :)");
			goto B;
		}
	}
	/*-------------------->gender<---------------------------*/
	do
	{
		printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&p.Gender);
		if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
		{
			ok=1;
		}
		else
		{
			ok=0;
		}
		if(!ok)
		{
			printf("\n\t\t Gender containt Invalid character :(  Enter either F or M :)");
		}		
	}while(!ok);
	/*------------------------->age<---------------------*/
	printf("\n\t\t\tAge:");
	scanf("%i",&p.Age);
	/*------------------------>Address<--------------------*/
	do
	{
		C:
		printf("\n\t\t\tAddress: ");
		scanf("%s",p.Address);
		p.Address[0]=toupper(p.Address[0]);
		if(strlen(p.Address)>20||strlen(p.Address)<3)
		{
			printf("\n\t\t The max range of address is 20 and min range is 40 :)");
			goto C;
		}
	}while(!valid);
	/*---------------->contact no.<------------------------*/
	do
	{
		D:
		printf("\n\t\t\tContact no: ");
		scanf("%s",p.Contact_No);
		if(strlen(p.Contact_No)>10||strlen(p.Contact_No)!=10)
		{
			printf("\n\t Sorry :( Invalid. Contact n. must contain 10 numbers. Enter Again :)");
			goto D;
		}
		else
		{
			for(b=0; b<strlen(p.Contact_No);b++)
			{
				if(!isalpha(p.Contact_No[b]))
				{
					valid=1;
				}
				else
				{
					valid=0;
					break;
				}
			}
			if(!valid)
			{
				printf("\n\t\t Contact no. contain Invalid character :( Enter Again :)");
				goto D;
			}
		}
	}while(!valid);
	/*-------------------->email<------------------------------*/
	do
	{
		printf("\n\t\t\tEmail: ");
		scanf("%s",p.Email);
		if(strlen(p.Email)>30||strlen(p.Email)<8)
		{
			printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");
		}
	}while(strlen(p.Email)>30||strlen(p.Email)<8);
	/*------------------>problem<-------------------------*/
	E:
	printf("\n\t\t\tProblem: ");
	scanf("%s",p.Disease);
	p.Disease[0]=toupper(p.Disease[0]);
	if(strlen(p.Disease)>15||strlen(p.Disease)<3)
	{
		printf("\n\t Invalid :( \t The max range for problem is 15 and min range is 3 :)");
		goto E;
	}
	else
	{
		for(b=0;b<strlen(p.Disease);b++)
		{
			if(isalpha(p.Disease[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Problem contain Invalid character :( Enter Again :)");
			goto E;
		}
	}
	/*------------------->prescribed Doctor<---------------------------*/
	F:
	printf("\n\t\t\tPrescribed Doctor:");
	scanf("%s",p.Doctor_Name);
	p.Doctor_Name[0]=toupper(p.Doctor_Name[0]);
	if(strlen(p.Doctor_Name)>30||strlen(p.Doctor_Name)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 3 :)");
		goto F;
	}
	else 
	{
		for(b=0;b<strlen(p.Doctor_Name);b++)
		{
			if(isalpha(p.Doctor_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Doctor name containt Invalid character :(  Enter Again :)");
			goto F;
		}
	}
	fprintf(ek," %s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender,p.Age,p.Address,p.Contact_No,p.Email,p.Disease,p.Doctor_Name);
	printf("\n\n\t\t\t....Information Recoed Successful....");
	fclose(ek);
	sd:
	getch();
	printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
	scanf(" %c",&ans);
	if(toupper(ans)=='Y')
	{
		Add_rec();
	}
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank You :) :)");
		getch();
		MainMenu();
	}
	else
	{
		printf("\n\t\tInvalid Input\n");
		goto sd;
	}
}
/*------------------------------>view record<------------------------------*/
void func_list()
{
int row;
system("cls");
Title();
FILE*ek;
ek=fopen("Record2.dat","r");
printf("\n\n\t\t\t!!!!!!!!!!!! List Patients Records !!!!!!!!!!!!\n");
	gotoxy(1,15);
	printf("Full Name");
	gotoxy(20,15);
	printf("Gender");
	gotoxy(32,15);
	printf("Age");
	gotoxy(37,15);
	printf("Address");
	gotoxy(49,15);
	printf("Contact NO.");
	gotoxy(64,15);
	printf("Email");
	gotoxy(88,15);
	printf("Disease");
	gotoxy(98,15);
	printf("Prescribed Doctor\n");
	printf("====================================================================================================================\n");
	row=17;
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,&p.Gender,&p.Age,p.Address,p.Contact_No,p.Email,p.Disease,p.Doctor_Name)!=EOF)
	{
	gotoxy(1,row);
	printf("%s %s",p.First_Name,p.Last_Name);
	gotoxy(20,row);
	printf("%c",p.Gender);
	gotoxy(32,row);
	printf("%i",p.Age);
	gotoxy(37,row);
	printf("%s",p.Address);
	gotoxy(49,row);
	printf("%s",p.Contact_No);
	gotoxy(64,row);
	printf("%s",p.Email);
	gotoxy(88,row);
	printf("%s",p.Disease);
	gotoxy(98,row);
	printf("%s",p.Doctor_Name);
	row++;
	}
	fclose(ek);
	getch();
	MainMenu();
}
void Search_rec(void)
{
	char name[20];
	system("cls");
	Title();
	FILE*ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!! Search Patients Record !!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,&p.Gender,&p.Age,p.Address,p.Contact_No,p.Email,p.Disease,p.Doctor_Name)!=EOF)
	{
		if(strcmp(p.First_Name,name)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(25,15);
			printf("Gender");
			gotoxy(32,15);
			printf("Age");
			gotoxy(37,15);
			printf("Address");
			gotoxy(52,15);
			printf("Contact No.");
			gotoxy(64,15);
			printf("Email");
			gotoxy(80,15);
			printf("Disease");
			gotoxy(95,15);
			printf("Prescribed Doctor\n");
			printf("====================================================================================================================\n");
			gotoxy(1,18);
			printf("%s %s",p.First_Name,p.Last_Name);
			gotoxy(25,18);
			printf("%c",p.Gender);
			gotoxy(32,18);
			printf("%i",p.Age);
			gotoxy(37,18);
			printf("%s",p.Address);
			gotoxy(52,18);
			printf("%s",p.Contact_No);
			gotoxy(64,18);
			printf("%s",p.Email);
			gotoxy(80,18);
			printf("%s",p.Disease);
			gotoxy(95,18);
			printf("%s",p.Doctor_Name);
			printf("\n");
			break;
		}
	}
	if(strcmp(p.First_Name,name)!=0)
	{
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	}
	fclose(ek);
	L:
		getch();
		printf("\n\n\t\t\tDo you want to view more[Y/N]??");
		scanf("%c",&ans);
		if(toupper(ans)=='Y')
		{
			Search_rec();
		}
		else if (toupper(ans)=='N')
		{
			printf("\n\t\t Thank you :) :)");
			getch();
			MainMenu();
		}
		else
		{
			printf("\n\tInvalid Input.\n");
			goto L;
		}
}



void Edit_rec(void)
{
	FILE *ek, *ft;
	int i,b, valid=0;
	char ch;
	char name[20];
	system("cls");
	Title();
	ft=fopen("temp2.dat","w+");
	ek=fopen("Record2.dat","r");
	if(ek==NULL)
	{
		printf("\n\t Can not open file!! ");
		getch();
		MainMenu();
	}
	printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!!!! Edit Patient Record !!!!!!!!!!!!!!!!!!!!!!!!!\n");
	gotoxy(12,13);
	printf("Enter the first name of the patient  : ");
	scanf(" %s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	gotoxy(12,15);
	if(ft==NULL)
	{
		printf("\n can not open file");
		getch();
		MainMenu();
	}
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,&p.Gender,&p.Age,p.Address,p.Contact_No,p.Email,p.Disease,p.Doctor_Name)!=EOF)
	{
		if(strcmp(p.First_Name,name)==0)
		{
			valid=1;
			gotoxy(25,17);
			printf("*** Existing Record ***");
			gotoxy(10,19);
			printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s",p.First_Name,p.Last_Name,p.Gender,p.Age,p.Address,p.Contact_No,p.Email,p.Disease,p.Doctor_Name);
			gotoxy(12,22);
			printf("Enter New First Name: ");
			scanf("%s",p.First_Name);
			gotoxy(12,24);
			printf("Enter Last Name: ");
			scanf("%s",p.Last_Name);
			gotoxy(12,26);
			printf("Enter Gender: ");
			scanf(" %c",&p.Gender);
			p.Gender=toupper(p.Gender);
			gotoxy(12,28);
			printf("Enter Age: ");
			scanf(" %i",&p.Age);
			gotoxy(12,30);
			printf("Enter Addres: ");
			scanf("%s",p.Address);
			p.Address[0]=toupper(p.Address[0]);
			gotoxy(12,32);
			printf("Enter Contact no: ");
			scanf("%s",p.Contact_No);
			gotoxy(12,34);
			printf("Enter New Email: ");
			scanf("%s",p.Email);
			gotoxy(12,36);
			printf("Enter Disease: ");
			scanf("%s",p.Disease);
			p.Disease[0]=toupper(p.Disease[0]);
			gotoxy(12,38);
			printf("Enter Doctor: ");
			scanf("%s",p.Doctor_Name);
			p.Doctor_Name[0]=toupper(p.Doctor_Name[0]);
			printf("\nPress U character for the Updating operation : ");
			ch=getch();
			if(ch=='u' || ch=='U')
			{
				fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender,p.Age,p.Address,p.Contact_No,p.Email,p.Disease,p.Doctor_Name);
				printf("\n\n\t\t\tPatient record updated successfuly.....");
			}
		}
		else
		{
			fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender,p.Age,p.Address,p.Contact_No,p.Email,p.Disease,p.Doctor_Name);	
		}
	}
	if(!valid)
	{
		printf("\n\t\tNO RECORD FOUND....");
	}
	fclose(ft);
	fclose(ek);
	remove("Record2.dat");
	rename("temp2.dat","Record2.dat");
	getch();
	MainMenu();
}
   void Dlt_rec()
{
    char name[20];
    int found = 0;
    system("cls");
    Title();
    FILE* ek;
    FILE* ft;
    ft = fopen("temp_file2.dat", "w");
    ek = fopen("Record2.dat", "r");

    printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!! Delete Patients Record !!!!!!!!!!!!!!!!!!!!!!!\n");
    gotoxy(12, 8);
    printf("Enter Patient Name to delete: ");
    fflush(stdin);
    gets(name);
    name[0] = toupper(name[0]);

    while (fscanf(ek, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.Age, p.Address, p.Contact_No, p.Email, p.Disease, p.Doctor_Name) != EOF)
    {
        if (strcmp(p.First_Name, name) != 0)
        {
            fprintf(ft, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.Age, p.Address, p.Contact_No, p.Email, p.Disease, p.Doctor_Name);
        }
        else
        {
            found = 1;
        }
    }

    fclose(ek);
    fclose(ft);

    if (found == 0)
    {
        printf("\n\n\t\t\t Record not found....");
        getch();
        MainMenu();
    }
    else
    {
        remove("Record2.dat");
        rename("temp_file2.dat", "Record2.dat");
        printf("\n\n\t\t\t Record deleted successfully  :) ");
        getch();
        MainMenu();
    }
}


void SearchByDoctorName(void)
{
    char doctorName[20];
    int found = 0;
    system("cls");
    Title();
    FILE* ek;
    ek = fopen("Record2.dat", "r");

    printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!!! Search Patients by Doctor Name !!!!!!!!!!!!!!!!!!!!!\n");
    gotoxy(12, 8);
    printf("Enter Doctor's Name to search for patients: ");
    fflush(stdin);
    gets(doctorName);
    doctorName[0] = toupper(doctorName[0]);

    printf("\nSearch Results:\n");
    printf("====================================================================================================================\n");
    printf("Full Name\tGender\tAge\tAddress\tContact No.\tEmail\tDisease\tPrescribed Doctor\n");
    printf("====================================================================================================================\n");

    while (fscanf(ek, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.Age, p.Address, p.Contact_No, p.Email, p.Disease, p.Doctor_Name) != EOF)
    {
        if (strcmp(p.Doctor_Name, doctorName) == 0)
        {
            printf("%s %s\t%c\t%i\t%s\t%s\t%s\t%s\t%s\n", p.First_Name, p.Last_Name, p.Gender, p.Age, p.Address, p.Contact_No, p.Email, p.Disease, p.Doctor_Name);
            found = 1;
        }
    }

    fclose(ek);

    if (found == 0)
    {
        printf("\n\n\t\t\t No records found for the specified doctor's name.");
    }

    printf("\n\nPress any key to return to the main menu.");
    getch();
    MainMenu();
}

