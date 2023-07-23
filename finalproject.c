#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void createrecord();
void viewrecord();
void editrecord();
void deleterecord();
void searchrecord();
void allrecord();
int getTotalScoreOfPlayer(int id);
int getTotalMactchPlayed(int id);

void mainpage();
FILE*fp;
FILE*tp;
struct players
{
    int id,age,jno;
    char fname[20],lname[20],nation[20],place[20],address[20],sex[20],tname[20];
}s;

struct score{
    int pid,match,run,day,mnth,year;
    char place[20];
}a;
void main()
{
    int ch=3,i,pw;
  char user[10]="admin",pass[10]="password",username[10],password[10];
  top:
  printf("\t\t#################### WELCOME TO CRICKET PLAYERS DATA MANAGEMENT SYSTEM ####################\n\n\n");
  printf("\t\t\t\t\tUSERNAME:");
  gets(username);
  printf("\t\t\t\t\tPASSWORD:");
  for(i=0;i<8;i++)
  {
    pw=getch();
  	password[i]=pw;
  	pw='*';
  	printf("%c",pw);
  }
  getch();
  password[i]='\0';
  if(strcmp(username,user)==0 && strcmp(password,pass)==0)
  {
       system("cls");
         printf("\t\t\t\t------------------------------------------------------\n");
         printf("\t\t\t\t----------------LOGIN SUCCESSFULL----------------------\n");
         printf("\t\t\t\t-------------------------------------------------------\n\n");
         mainpage();
    }
    else
    {
      system("cls");
      printf("\n");
      printf("\t\t\t\tINVALID USERNAME OR PASSWORD!\n\n");


      while(ch<=0)
        {
            printf("\n");
            printf("\t\t\t\tSORRY YOUR REMAINING TIME COMPLETED!!!!\n\n");
            exit(1);
        }
        printf("You have %d times remaining:\n\n",ch);
         ch--;
        getch();
        system("cls");
        goto top;
  }
}
void mainpage()
{
    int ch;
    printf("\n\n\t\t\t\tYOUR CHOICE ARE AVAILABLE HERE:\n\n");
    printf("\t\t\t\tpress 1 for create record\n");
    printf("\t\t\t\tpress 2 for create all record\n");
    printf("\t\t\t\tpress 3 for view record\n");
    printf("\t\t\t\tpress 4 for edit record\n");
    printf("\t\t\t\tpress 5 for delete record\n");
    printf("\t\t\t\tpress 6 for search result\n");
    printf("\t\t\t\tpress 7 for exit program\n\n");
    printf("\t\t\t\tEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            {
                system("cls");
                printf("\t\t\t\tCREATE RECORD IS AVAILABLE HERE!!!\n\n");
                createrecord();
                printf("\t\t\t\tRECORD CREATE SUCCESSFULLY!!!\n\n");
                getch();
                system("cls");
                mainpage();
                break;
            }
        case 2:
            {
                system("cls");
                allrecord();
                break;
            }
        case 3:
            {
                system("cls");
                 viewrecord();

                break;
            }
        case 4:
            {
                system("cls");
               editrecord();
                break;
            }
        case 5:
            {
                system("cls");
                deleterecord();

                break;
            }
        case 6:
            {
                system("cls");
                 printf("\t\t\t\tSEARCH RECORD IS AVAILABLE HERE!!!\n\n");
                searchrecord();

                break;
            }
        case 7:
	     	{
			system("cls");
			 exit(1);
			 break;
			}

       default:
         {
           system("cls");
           printf("\n\n\t\t\t\twrong choice!!!\n\n");
           mainpage();
         }
    }
}
void createrecord()
{
    int playid,no;
    FILE *fp3;
    fp3=fopen("cricket.txt","a+");
    printf("Enter id of player:");
    scanf("%d",&playid);
    if(playid<0)
       {
          printf("SORRY ID SHOULDNOT BE NEGATIVE!!\n");
          createrecord();
       }
    while(fread(&s,sizeof(s),1,fp3))
    {


        if(s.id==playid)
        {
            printf("\nThis id already entered!!\n");
            getch();
            system("cls");
            mainpage();
        }

    }
    s.id=playid;
    a.pid=playid;

    printf("\nFirst name:");
    scanf("%s",&s.fname);

    printf("\nLast name:");
    scanf("%s",&s.lname);
    top:
    printf("\nAge:");
    scanf("%d",&s.age);

    if(s.age<18||s.age>35)
    {
        printf("\nSORRY IT STORES ONLY 18 T0 35 AGE OF PLAYERS!!\n\n");
        goto top;
    }
    printf("\nSex:");
    scanf("%s",&s.sex);
    printf("\nNationality:");
    scanf("%s",&s.nation);
    printf("\nAddress:");
    scanf("%s",&s.address);
    printf("\nTeam name:");
    scanf("%s",&s.tname);
    p:
    printf("\nJursi no:");
    scanf("%d",&no);
    if(no<0)
    {
    	printf("JURSEY NO. SHOULD NOT BE NEGATIVE!!\n");
    	goto p;
	}

	if(duplicatejno(no)!=0)
	{
		printf("SORRY THIS JERSI NUMBER AREADY ENTERED!!\n");
	   	goto p;

	}
	s.jno=no;
    fwrite(&s,sizeof(s),1,fp3);
    fclose(fp3);
}
void allrecord()
{
			int playerid,flag=0;

			FILE *test1;
			FILE *test2;
	      	test1=fopen("players.txt","a+");
	      	test2=fopen("cricket.txt","r");

            printf("Enter the id 0f player:");
            scanf("%d",&playerid);
            while(fread(&s,sizeof(s),1,test2))
		    {

            if(playerid==s.id)
		          			 {
		          			 	printf("\t\t\t\tYOUR RECORD:\n");
					        	printf("\t\t\t\t===========\n\n");
					       	    printf("ID\t\tFULL NAME\t\tNATIONALITY\tAGE\tSEX\tJURSEY NO.");
					            printf("\n-----------------------------------------------------------------------------------\n");
					            printf("%d\t\t%s %s\t\t%s\t\t%d\t%s\t  %d\t\t",s.id,s.fname,s.lname,s.nation,s.age,s.sex,s.jno);
		          			     flag=1;
		          			 }

		   }
		   fclose(test2);

		   if(flag==1){

					           	printf("\n\n\t\tENTER ALL DETAIL:");
					           	printf("\n\t\t=================\n");
					            a.pid=playerid;
					            printf("\nPlace of match:");
					            scanf("%s",a.place);
					           	printf("\nMatch date:\n");
					            day:
					           	printf("\tDay:");
					           	scanf("%d",&a.day);
					          	if(a.day>32)
					          		{
					            		printf("CHECK YOUR DAY AGAIN!!\n\n");
					            		goto day;
					          		}
					        	mnth:
					         	printf("\tMonth:");
					         	scanf("%d",&a.mnth);
					         	if(a.mnth>12)
					          	{
					            	printf("CHECK YOUR MONTH AGAIN!!\n");
					             	goto mnth;
					           }
					          year:
					          printf("\tYear:");
					          scanf("%d",&a.year);
					          if(a.year>2019)
					          {
					            printf("CHECK YOUR ENTERED YEAR AGAIN AND REMEMBER IT STORES ENGLISH DATE ONLY!!\n\n");
					            goto year;
					          }
					          run:
						      printf("\nRun scored:");
						      scanf("%d",&a.run);
					          if(a.run<0)
					           {
					             printf("RUN DOES NOT EXISTS!!\n\n");
					             goto run;
					           }

					         fwrite(&a,sizeof(a),1,test1);
					         fclose(test1);
					         printf("\n\n\t\t\t\tALL RECORD CREATED SUCCESSFULLY!!\n");
		     }
		     else
		     {
		     	flag=0;
		     }
   getch();
   system("cls");
   mainpage();
}

 int duplicatejno(int jersiNo){
     struct players x;

	fp= fopen("cricket.txt","r");
	int result=0;
	while(fread(&x,sizeof(x),1,fp)){
		if(jersiNo==x.jno){
			result=1;
		}
	}
	fclose(fp);
	return result;
}


void viewrecord()
{
  fp=fopen("cricket.txt","r");
  printf("\t\t\t\tVIEW RECORD IS AVAILABLE HERE!!!\n\n");
  printf("ID\t\tFULL NAME\t\tNATIONALITY\tAGE\tSEX\tJURSEY NO.\tMATCH PLAYED\tTOTAL RUN SCORED\n\n");
  printf("-----------------------------------------------------------------------------------------------------------------------\n");
  if(fp==NULL)
        {
            printf("The file does not exist\n");

        }
   while(fread(&s,sizeof(s),1,fp))
   {
          printf("%d\t\t%s %s\t\t%s\t\t%d\t%s\t  %d\t\t   %d\t\t   %d\n",s.id,s.fname,s.lname,s.nation,s.age,s.sex,s.jno,getTotalMactchPlayed(s.id), getTotalScoreOfPlayer(s.id));
          printf("-----------------------------------------------------------------------------------------------------------------------\n");
    }

    fclose(fp);
    getch();
    system("cls");
    mainpage();
}
void editrecord()
{

        int playerid,found=0,no;
        FILE*temp;
        fp=fopen("cricket.txt","r");
        temp=fopen("temp.txt","a");
        if(fp==NULL)
        {
            printf("File does not exist:");
        }
      printf("\t\t\t\tEDIT RECORD IS AVAILABLE HERE:\n\n");
      printf("Enter the id of player whose record you are going to edit:");
      scanf("%d",&playerid);
      if(playerid<0)
      {
          printf("SORRY ID SHOULD NOT BE NEGATIVE!!\n");
          editrecord();
      }
      while(fread(&s,sizeof(s),1,fp))

          if(playerid==s.id)
          {
            printf("YOUR OLD RECORD IS:\n");
            printf("ID\t\tFULL NAME\t\tNATIONALITY\tAGE\tSEX\tJURSEY NO.");
            printf("\n-----------------------------------------------------------------------------------\n");
            printf("%d\t\t%s %s\t\t%s\t\t%d\t%s\t  %d\t\t",s.id,s.fname,s.lname,s.nation,s.age,s.sex,s.jno);
            printf("\n\n\t\t\t\tNew Record:\n");
            printf("\t\t\t\t-----------\n\n");
            printf("\nFirst name:");
            scanf("%s",s.fname);
            printf("\nLast name:");
            scanf("%s",s.lname);
            printf("\nNationality:");
            scanf("%s",s.nation);
            printf("\nAddress:");
            scanf("%s",s.address);
            printf("\nSex:");
            scanf("%s",s.sex);
            top:
            printf("\nAge:");
            scanf("%d",&s.age);
             if(s.age<18||s.age>35)
                {
                 printf("\nSORRY IT STORES ONLY 18 T0 35 AGE OF PLAYERS!!\n\n");
                 goto top;
                }
          	printf("\nTeam name:");
            scanf("%s",s.tname);
            p:
            printf("\nJursi no:");
            scanf("%d",&no);
             if(no<0)
               {
             	printf("JURSEY NO. SHOULD NOT BE NEGATIVE!!\n");
            	goto p;
            	}
            fwrite(&s,sizeof(s),1,temp);
            found=1;

            }
             else
             {
             fwrite(&s,sizeof(s),1,temp);

             }
             if(found==0)
              {
               printf("ID DOESNOT EXIST\n");
              }
             else
             {
            fclose(fp);
            fclose(temp);
            remove("cricket.txt");
            rename("temp.txt","cricket.txt");
            }
        printf("\n\t\t\tRecord update successfully!!!\n");
        getch();
        system("cls");
        mainpage();

}
void deleterecord()
{
int playerid;
     printf("\t\t\t\tDELETE RECORD IS AVAILABLE HERE!!!\n\n");
     FILE*temp;
     FILE*tmp;
     tp=fopen("players.txt","r");
     fp=fopen("cricket.txt","r");
     temp=fopen("temp.txt","a");
     tmp=fopen("delete.txt","a");
     printf("Enter the id of player whose record you want to delete:");
     scanf("%d",&playerid);
     if(playerid<0)
     {
         printf("SORRY ID DOES NOT FOUND!!\n");
         deleterecord();
     }

     while((fread(&s,sizeof(s),1,fp)))
     {
        if(playerid!=s.id)
       {
         fwrite(&s,sizeof(s),1,temp);
        }
    }
       while(fread(&a,sizeof(a),1,tp))
       {
       	if(playerid!=a.pid)
       	{
            fwrite(&a,sizeof(a),1,tmp);
        }

       }



     printf("\n\n\t\t\t\t\tRECORD DELETED!!!\n\n");
     getch();
     system("cls");
     fclose(fp);
     fclose(temp);
     fclose(tmp);
     fclose(tp);
     remove("cricket.txt");
     rename("temp.txt","cricket.txt");

     remove("players.txt");
     rename("delete.txt","players.txt");
     mainpage();
}
void searchrecord()
{
       int playerid;
       fp=fopen("cricket.txt","r");
       tp=fopen("players.txt","r");
       printf("Enter the id of players which you want to look:");
       scanf("%d",&playerid);
       if(playerid<0)
       {
           printf("SORRY ID DOESNOT FOUND!!\n");
           searchrecord();
       }
       printf("\n");
       while(fread(&s,sizeof(s),1,fp))
       {
           if(playerid==s.id)
           {
               printf("\t\t\t\tYOUR RECORD IS:\n");
               printf("\t\t\t\t--------------\n\n");
               printf("ID\t\tFULL NAME\t\tNATIONALITY\tAGE\tMATCH PLAYED\tTOTAL RUN SCORED\n");
               printf("%d\t\t%s %s\t\t%s\t\t%d\n\n",s.id,s.fname,s.lname,s.nation,s.age);
               printf("\n\n");
               printf("\t\tFULL DETAIL:\n");
               printf("\t\t------------\n\n");
               printf("\n\nID:\t\t\t\t%d\n",s.id);
               printf("----------------------------------------\n");
               printf("First name:\t\t\t%s\n",s.fname);
               printf("----------------------------------------\n");
               printf("Last name:\t\t\t%s\n",s.lname);
               printf("----------------------------------------\n");
               printf("Sex:\t\t\t\t%s\n",s.sex);
               printf("----------------------------------------\n");
               printf("Nationality:\t\t\t%s\n",s.nation);
               printf("----------------------------------------\n");
               printf("Address:\t\t\t%s\n",s.address);
               printf("----------------------------------------\n");
               printf("Age:\t\t\t\t%d\n",s.age);
               printf("----------------------------------------\n");
               printf("Team name:\t\t\t%s\n",s.tname);
               printf("----------------------------------------\n");
               printf("Jursi no:\t\t\t%d\n",s.jno);
               printf("----------------------------------------\n");
               printf("\n\n");
               while(fread(&a,sizeof(a),1,tp))
               {
               	 if(playerid==a.pid)
               	 {
                     printf("Date of match:\t\t\t%d/%d/%d\n",a.day,a.mnth,a.year);
                     printf("----------------------------------------\n");
                     printf("Run scored:\t\t\t%d\n",a.run);
                     printf("----------------------------------------\n");
                     printf("Place of match:\t\t\t%s\n",a.place);
                     printf("----------------------------------------\n");
                     printf("\n\n");

                 }
			    }
			   fclose(tp);

           }
       }
       fclose(fp);
       getch();
       system("cls");
       mainpage();
}


int getTotalScoreOfPlayer(int id){
	tp=fopen("players.txt","r");
	int score=0;
	while(fread(&a,sizeof(a),1,tp)){
		if(id==a.pid){
			score+=a.run;
		}
	}
	fclose(tp);
	return score;
}

int getTotalMactchPlayed(int id){
	tp=fopen("players.txt","r");
	int count=0;
	while(fread(&a,sizeof(a),1,tp)){
		if(id==a.pid){
			count+=1;
		}
	}
	fclose(tp);
	return count;
}
