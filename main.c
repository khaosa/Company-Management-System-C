#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int day;
    int month;
    int year;
} birthdate;
typedef struct
{
    int id;
    char lname[30];
    char fname[30];
    float salary;
    birthdate bd;
    char address[35];
    int phone[11];
    char email[30];

} emp;
////////////////////////////////////////////SORT BY LAST NAME//////////////////
emp h;//global variable
emp SortByLN(emp x[],int n) //bubble sort alphabetically
{
    int i,p,s;

    for(p=0; p<(n)-1; p++)
    {
        for(i=0; i<(n)-p-1; i++)
        {
            if(strcasecmp(x[i].lname,x[i+1].lname)>0)
            {
                h=x[i];
                x[i]=x[i+1];
                x[i+1]=h;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        printf("The sorted information of Employee no.%d :\nID: %d\nLast name: %s\nFirst name:%s\nSalary: %.2f\n",i+1,x[i].id,x[i].lname,x[i].fname,x[i].salary);
        printf("Day:  %d\nMonth: %d\nYear: %d\nAddress: %s\nPhone Number: %s\nEmail: %s\n\n",x[i].bd.day,x[i].bd.month,x[i].bd.year,x[i].address,x[i].phone,x[i].email);
    }
}
///////////////////////////////////////////////////////sort by SALARY/////////////////
emp SortByS(emp x[],int n) //bubble sort from least salary
{
    int i,p,s;
    for(p=0; p<n-1; p++)

        for(i=0; i<n-p-1; i++)
        {
            if(x[i].salary>x[i+1].salary)
            {
                h=x[i];
                x[i]=x[i+1];
                x[i+1]=h;
            }
        }
    for(i=0; i<n; i++)
    {
        printf("The sorted information of Employee no.%d :\nID: %d\nLast name: %s\nFirst name:%s\nSalary: %.2f\n",i+1,x[i].id,x[i].lname,x[i].fname,x[i].salary);
        printf("Day:  %d\nMonth: %d\nYear: %d\nAddress: %s\nPhone Number: %s\nEmail: %s\n\n",x[i].bd.day,x[i].bd.month,x[i].bd.year,x[i].address,x[i].phone,x[i].email);


    }

}
///////////////////////////////////////////////////////SORT BY DATE OF BIRTH/////////////////
emp SortByBD(emp x[],int n) //bubble sort from older to younger
{
    int i,p,s;
    for(p=0; p<(n)-1; p++)
    {

        for(i=0; i<(n)-p-1; i++)
        {
            if(x[i].bd.year>x[i+1].bd.year)
            {
                h=x[i];
                x[i]=x[i+1];
                x[i+1]=h;

            }
            else if(x[i].bd.year==x[i+1].bd.year &&  x[i].bd.month>x[i+1].bd.month)
            {
                h=x[i];
                x[i]=x[i+1];
                x[i+1]=h;

            }
            else if(x[i].bd.year==x[i+1].bd.year&&x[i].bd.month==x[i+1].bd.month && x[i].bd.day>x[i+1].bd.day)
            {
                h=x[i];
                x[i]=x[i+1];
                x[i+1]=h;

            }

        }
    }
    for(i=0; i<n; i++)
    {
        printf("The sorted information of Employee no.%d :\nID: %d\nLast name: %s\nFirst name:%s\nSalary: %.2f\n",i+1,x[i].id,x[i].lname,x[i].fname,x[i].salary);
        printf("Day:  %d\nMonth: %d\nYear: %d\nAddress: %s\nPhone Number: %s\nEmail: %s\n\n",x[i].bd.day,x[i].bd.month,x[i].bd.year,x[i].address,x[i].phone,x[i].email);


    }
}
///////////////////////////////////////////////////////MODIFY/////////////////////////////
void modify(emp x[],int n)
{
    int i,flag=0;
    char first[10],ID[10],second[10],address[100],phone[20],email[100],newid[10],newsalary[10],y[10];
    char day[2],month[2],year[4];
    printf("Enter the employee's ID:\n");
    scanf("%s",ID);

    for(i=0; i<n; i++)
    {
        itoa(x[i].id,y,10);
        if(!strcmp(ID,y))
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        printf("There is no employee with id: %s \n",ID);
        return 0;
    }
    printf("Enter the new id:\n");
    scanf("%s",newid);
    while(!intValid(newid))
    {
        printf("Invalid id\n");
        printf("Enter id:\n");
        scanf(" %s",newid);
    }
    x[i].id= atoi( newid);//convert string to integer
    printf("Employee's last name is %s.\nEnter the new last name:\n",x[i].lname);
    scanf("%s",&second);
    while(!namevalid(second))
    {
        printf("Invalid name\n");
        printf("Enter last name:\n");
        scanf(" %s",second);
    }
    strcpy(x[i].lname,second);
    getchar();
    printf("Employee's first name is %s.\nEnter the new first name:\n",x[i].fname);
    scanf("%s",&first);
    while(!namevalid(first))
    {
        printf("Invalid name.\n");
        printf("Enter first name:\n");
        scanf(" %s",first);
    }
    strcpy(x[i].fname,first);
    getchar();
    printf("Employee's salary is %.2f \nEnter the new salary:\n",x[i].salary);
    scanf("%s",newsalary);
    while(!salvalid(newsalary))
    {
        printf("Invalid salary\n");
        printf("Enter salary:\n");
        scanf(" %s",newsalary);
    }
    x[i].salary= atof( newsalary);
    printf("Employee's birth day is %d \nEnter birth day(DD):\n",x[i].bd.day);
    scanf("%s",day);
    x[i].bd.day= atoi( day);
    while(!intValid(day)||x[i].bd.day > 31 || x[i].bd.day<1)
    {
        printf("Invalid birthday\n");
        printf("Enter birth day(DD):\n");
        scanf("%s",day);
        x[i].bd.day= atoi( day);
    }
    printf("Employee's birth month is %d\nEnter month(MM):\n",x[i].bd.month);
    scanf("%s",month);
    x[i].bd.month= atoi( month);
    while(!intValid(month)||x[i].bd.month > 12 ||x[i].bd.month<1 )
    {
        printf("Invalid birth month.\n");
        printf("Month(MM):\n ");
        scanf("%s",month);
        x[i].bd.month= atoi(month);
    }
    printf("Employee's birth year is %d.\nEnter year(YYYY):\n",x[i].bd.year);
    scanf("%s",year);
    x[i].bd.year= atoi(year);
    while(!intValid(year)||x[i].bd.year < 1905||x[i].bd.year>2022)
    {
        printf("Invalid birth year.\n");
        printf("Year(YYYY):\n");
        scanf("%s",year);
        x[i].bd.year= atoi(year);
    }
    getchar();
    printf("Employee's address is %s \nEnter the new address:\n",x[i].address);
    gets(address);
    strcpy(x[i].address,address);
    printf("Employee's phone is %s \nEnter the new phone:\n",x[i].phone);
    scanf("%s",phone);
    while(!NumValid(phone))
    {
        printf("Invalid Number\n");
        printf("Enter new employee number: ");
        scanf("%s",phone);
    }
    strcpy(x[i].phone,phone);
    printf("Employee's email is %s \nEnter the new email:\n",x[i].email);
    scanf("%s",email);
    while(!EmValid(email))
    {
        printf("Invalid Email\n");
        printf("Enter new employee email: ");
        scanf("%s",email);
    }
    strcpy(x[i].email,email);

    printf("The data of employee is successfully updated.\n");

}
///////////////////////////////////////////////////////READ/////////////////////////////
int read(emp x[])
{
    int i=0,n=0;
    FILE *f = fopen("project.txt", "r");
    if(f == NULL)
    {
        printf("Error in opening the file!");
        exit(1);
    }

    while(!feof(f))
    {
        fscanf(f,"%d,",&x[i].id);
        fscanf(f,"%[^,],",x[i].lname);
        fscanf(f,"%[^,],",x[i].fname);
        fscanf(f,"%f,",&x[i].salary);
        fscanf(f,"%d-",&x[i].bd.day);
        fscanf(f,"%d-",&x[i].bd.month);
        fscanf(f,"%d,",&x[i].bd.year);
        fscanf(f,"%[^,],",x[i].address);
        fscanf(f,"%[^,],",&x[i].phone);
        fscanf(f,"%s\n",x[i].email);
        i++;
        n++;
    }
    fclose(f);
    return n;
}
/////////////////////////////////////////SEARCH//////////////////////////////////
void search(emp x[],int n)
{
    int i;
    int flag =0;
    char Lname[10];
    printf("Enter employee's last name: ");
    getchar();
    gets(Lname);
    for(i=0; i<n; i++)
    {
        if(strcasecmp(Lname,x[i].lname)==0)
        {
            flag=1;
            printf("\n");
            printf("ID: %d\n",x[i].id);
            printf("Last name: %s\n",x[i].lname);
            printf("First name: %s\n",x[i].fname);
            printf("Salary: %.2f\n",x[i].salary);
            printf("Date of birth: %d-",x[i].bd.day);
            printf("%d-",x[i].bd.month);
            printf("%d\n",x[i].bd.year);
            printf("Address: %s\n",x[i].address);
            printf("Phone number: %s\n",x[i].phone);
            printf("Email address: %s\n\n",x[i].email);
        }
    }
    if(!flag)
        printf("There is no employee with last name %s\n", Lname);
}
/////////////////////////////////////////VALIDATION/////////////////////
int NumValid(char *n)
{
    int i;
    for(i=0; n[i]; i++)
    {
        if(n[i]>57 || n[i]<48) //check if the entered element in the string is number (ASCII code of numbers 0~9 is 48~57)
            return 0;
    }
    if(i!=11) //check if they are exactly 11 numbers
        return 0;
    return 1;
}
int EmValid (char s[])
{
    char *p1,*p,p2[15],p3[10];
    int i,j,k,count=0;
    for(p1=s; *p1; p1++)//pointer to make sure there is @ and words before it
    {
        if(*p1=='@')
        {
            i=p1-s;
            break;
        }
        if((*p1>=65&&*p1<=90)||(*p1>97&&*p1<122))
            count++;

    }
    if(count<6)//at least 6 characters
        return 0;
    if(!i)
        return 0;
    for(j=0,k=0; *(p1+1); j++)//check the presence of '.'
    {
        p2[j]=*(p1+1);
        p1++;
        if(p2[j]=='.')
            p=&p2[j];
    }
    p2[j]='\0';
    if(!strcasecmp(p2,".com"))//check the presence of .com
        return 0;
    for(k=0; *p; k++)
    {
        p3[k]=*p;
        p++;
    }
    p3[k]='\0';
    if(strcasecmp(p3,".com"))
        return 0;
    return 1;
}
int intValid(char *n)
{
    int i;
    for(i=0; n[i]; i++)
    {
        if(n[i]>57 || n[i]<48) //check if the entered element in the string is number (ASCII code of numbers 0~9 is 48~57)
            return 0;
    }
    return 1;
}
int salvalid(char *n){
    int i;
    for(i=0; n[i]; i++)
    {
        if( !(n[i]<57 || n[i]>48||n[i]=='.') ||  n[0]=='-' ) //check if the entered element in the string is number (ASCII code of numbers 0~9 is 48~57)
            return 0;
    }
    return 1;

}
int namevalid(char *n)
{
    char *p1;
    int x=0,i=0;
    for(p1=n; *p1; p1++)
    {
        if((*p1>='a'&&*p1<='z')||(*p1>='A'&&*p1<='Z')||*p1==' '||*p1=='-'||*p1=='_')//check if the entered string all letters
            x++;
        else if(*p1=='\0')
            break;
        i++;
    }
    if(x!=i)
        return 0;
    return 1;
}
///////////////////////////////////////////ADD////////////////////////////
int add(emp x[],int n)
{   int i=0;
    char ID[10],VID[10],salary[10],day[2],month[2],year[4],choice[4];
    printf("Enter id:\n");
    scanf(" %s",ID);
    while(!intValid(ID))
    {
        printf("Invalid id\n");
        printf("Enter id:\n");
        scanf(" %s",ID);
    }
    while(i<n)
    {
        itoa(x[i].id,VID,10);
        if(strcasecmp(ID,VID)==0){
         printf("The ID %s is already taken.\nDo you want to enter a new ID?\nEnter command (Yes/No): ",ID);
          scanf("%s",choice);
        if( strcasecmp(choice,"yes") == 0){
                printf("ID:");
            scanf("%s",ID);
    while(!intValid(ID))
    {
        printf("Invalid id\n");
        printf("Enter id:\n");
        scanf("%s",ID);
    }
    i=0;
    continue;}
       else if(strcasecmp(choice,"no") == 0)
            return 0 ;
      else{ printf("Invalid answer\n"); return 0;
        }
    }
    ++i;}
    x[n].id= atoi(ID);

    printf("Enter last name:\n");

    scanf("%s",&x[n].lname);
    while(!namevalid(x[n].lname))
    {
        printf("Invalid name\n");
        printf("Enter last name:\n");
        scanf(" %s",&x[n].lname);
    }
    printf("Enter first name:\n");
    scanf("%s",&x[n].fname);
    while(!namevalid(x[n].fname))
    {
        printf("Invalid name\n");
        printf("Enter first name:\n");
        scanf(" %s",&x[n].fname);
    }

    printf("Enter salary:\n");
    scanf("%s",salary);
    while(!salvalid(salary))
    {
        printf("Invalid salary\n");
        printf("Enter salary:\n");
        scanf(" %s",salary);
    }

    x[n].salary= atof( salary);
    printf("Enter birth day(DD):\n");
    scanf("%s",day);
    x[n].bd.day= atoi( day);
    while(!intValid(day)||x[n].bd.day > 31 || x[n].bd.day<1)
    {
        printf("Invalid birthday\n");
        printf("Enter birth day(DD):\n");
        scanf("%s",day);
        x[n].bd.day= atoi( day);
    }
    printf("Month(MM):\n");
    scanf("%s",month);
    x[n].bd.month= atoi( month);
    while(!intValid(month)||x[n].bd.month > 12 ||x[n].bd.month<1 )
    {
        printf("Invalid birth month\n");
        printf("Month(MM):\n ");
        scanf("%s",month);
        x[n].bd.month= atoi(month);
    }
    printf("Year(YYYY):\n");
    scanf("%s",year);
    x[n].bd.year= atoi(year);
    while(!intValid(year)||x[n].bd.year < 1905||x[n].bd.year>2022)
    {
        printf("Invalid birth year\n");
        printf("Year(YYYY):\n");
        scanf("%s",year);
        x[n].bd.year= atoi(year);
    }

    getchar();
    printf("Enter address:\n");
    gets(x[n].address);


    printf("Enter number:\n");
    scanf("%s",&x[n].phone);
    while(!NumValid(x[n].phone))
    {
        printf("Invalid Number\n");
        printf("Enter number: ");
        scanf("%s",x[n].phone);
    }
    printf("Enter email:\n");
    scanf("%s",&x[n].email);
    while(!EmValid(x[n].email))
    {
        printf("Invalid Email\n");
        printf("Enter email: \n");
        scanf("%s",x[n].email);
    }
    printf("The new employee is successfully added.\n");
    return 1;
}
void Print(emp x[],int n)
{
    int c;
    printf("1.Sort by last name\n2.Sort by salary\n3.Sort by birthdate\n");
    scanf("%d",&c);
    getchar();
    if(c!=1&&c!=2&&c!=3)
    {
        printf("Invalid choice\n");
        printf("1.Sort by last name\n2.Sort by salary\n3.Sort by birthdate\n");
        scanf("%d",&c);
    }
    if(c==1)
        return SortByLN(x,n);
    else if(c==2)
        return SortByS(x,n);
    else if(c==3)
        return SortByBD(x,n);
}
int save(emp x[], int n)  // n = number of records
{
    int i;
    FILE *f=fopen("project.txt", "w");
     if(f == NULL)
    {
        printf("Error in opening the file!");
        exit(1);
    }
    for(i=0; i<n; i++) // data of each struct is written into a text file
    {
        fprintf(f,"%d,%s,%s,%.2f,%d-%d-%d,%s,%s,%s\n", x[i].id, x[i].lname, x[i].fname,
                x[i].salary, x[i].bd.day, x[i].bd.month, x[i].bd.year, x[i].address, x[i].phone, x[i].email);
    }
    fclose(f);
    printf("File has been saved successfully.\n");
    return 1;
}
void quit(int s)
{
    char status[20];
    if(!s)//if the file is not saved
    {
        printf("Are you sure you want to quit?\n");
        printf("All of your unsaved changes will be discarded.\n");
         printf("Enter command (Yes/No): ");
        scanf("%s", status);
        if( strcasecmp(status, "yes") == 0)
            exit(-1);
        if(strcasecmp(status, "yes") == 0)
            return ;
    }
    if(s)
    {
        printf("GOODBYE.");
        exit(0);
    }
}
int dele(emp x[],int n)
{
    char f[20],l[20];
    int c,i,counter=0,flag=0;
    printf("Enter the first name:\n");
    scanf("%s",f);
    printf("Enter the last name:\n");
    scanf("%s",l);
    for(i=0; i<n; i++)
    {
        if( strcasecmp(f, x[i].fname)==0  && strcasecmp(l, x[i].lname )==0)
        {
            flag=1;
            counter=counter+1;
            for(c=i; c<n; c++)
            {
                x[c]=x[c+1];
            }
            i--;
            }}
    if(!flag)
    {
        printf("No employee with name %s %s\n",f,l);
    }
    else printf("The employee was deleted successfully.\n");
    return counter;
}
int main()
{
    int q, option,deleted,added,s=0;
    emp x[20];

    FILE *f=fopen("project.txt","r");
    if(f == NULL)
    {
        printf("Error in opening the file!");
        exit(1);
    }
    q=read(x);//by default

    do
    {
        printf("Select from menu:\n-----------------\n");
        printf("1.Search \n2.Add \n3.Delete\n4.Modify\n5.Sort\n6.Save\n7.Quit\n");
        printf("Enter command: ");
        scanf("%d",&option);

        switch(option)
        {
        case 1 :
            search(x,q);
            break;
        case 2 :
        {
            added=add(x,q);
            if(added)
                q+=1;
        }
        break;
        case 3 :
        {
            deleted = dele(x,q);
            if(deleted)
                q=q-deleted;
        }
        break;
        case 4 :
            modify(x,q);
            break;
        case 5 :
            Print(x,q);
            break;
        case 6 :
            s=save(x,q);
            break;
        case 7 :
            quit(s);
            break;
        default :
            printf("Invalid choice");
            break;
        }
    }
    while (option);
    fclose(f);
    return 0;
}
