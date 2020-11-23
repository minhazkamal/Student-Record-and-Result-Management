#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 1000

int id_i=0,id_c=0,w=0;

void print_head()
{
    printf("   Student Record and Result");
    printf("\n      Management System");
    printf("\n             of");
    printf("\n       ABC High School");
    printf("\n      Dhaka, Bangladesh\n\n");
}

struct pass
{
    char user[10];
    char pass[10];
};

struct pass m_pass;

void pass_g()
{
    FILE *fp;
    fp=fopen("Pass.txt","ab+");
    if(fp==NULL)
        exit(0);
    else
    {
        gets(m_pass.user);
        gets(m_pass.pass);
        fwrite(&m_pass, sizeof(m_pass), 1, fp);
    }
    fclose(fp);
}

void option()
{
    printf("\tEnter your option: ");
}

struct student
{
    char name[30];
    char Class[5];
    char ID[10];
    char mobile[12];
    //char z;
};

struct student stu;

struct teacher
{
    char name[30];
    char ID[10];
    char mobile[12];
};

struct teacher teach;

void admin()
{
    system("CLS");
    print_head();
    printf("\n\t1.Add Teacher\n\t2.Add Student\n\t3.Search Student\n\t4.Search Teacher\n\t5.Update Records\n\t6.Delete Record\n\t7.Assign Subject\n\t8.Assign Class Teacher\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m); getchar();
    switch(m)
    {
    case 1:
        add_teacher();
        break;
    case 2:
        add_student();
        break;
    case 3:
        search_student();
        break;
    case 4:
        search_teacher();
        break;
    case 5:
        mod_records();
        break;
    case 6:
        delete_records();
        break;
    case 7:
        sub_input();
        break;
        case 8:
        assign_teacher();
        break;
    case 0:
        main();
        break;
    default:
        admin();
    }
}

void add_student()
{
    system("CLS");
    print_head();
    printf("Add Student's Record\n");
    char f[20];
    FILE *fp,*fs;
    fp=fopen("student.txt","ab+");
    if(fp==NULL)
    {
        printf("Error!!!");
        exit(0);
    }
    else
    {
        fflush(stdin);
        printf("Name: ");
        gets(stu.name);
        printf("ID: ");
        gets(stu.ID);
        printf("Class: ");
        gets(stu.Class);
        printf("Mobile: ");
        gets(stu.mobile);
        fwrite(&stu, sizeof(stu), 1, fp);
        printf("\nThe record is successfully added\n");
    }
    fclose(fp);
    printf("\n\t1.Add Another\n\t0.Back\n");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        add_student();
        break;
    case 0:
        admin();
    }
}

void add_teacher()
{
    system("CLS");
    print_head();
    printf("Add Teacher's Record\n");
    FILE *fp,*fs;
    fp=fopen("teacher.txt","ab+");
    if(fp==NULL)
    {
        printf("Error!!!");
        exit(0);
    }
    else
    {
        fflush(stdin);
        printf("Name: ");
        gets(teach.name);
        printf("ID: ");
        gets(teach.ID);
        printf("Mobile: ");
        gets(teach.mobile);
        fwrite(&teach, sizeof(teach), 1, fp);
        printf("\nThe record is successfully added\n");
    }
    fclose(fp);
    printf("\n\t1.Add Another\n\t0.Back\n");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        add_teacher();
        break;
    case 0:
        admin();
    }
}

void search_student()
{
    system("CLS");
    print_head();
    printf("Search Student\n");
    char s_id[10],c[5];
    int isfound = 0;
    printf("Enter Class: ");
    fflush(stdin);
    gets(c);
    printf("Enter id to search: ");
    gets(s_id);
    FILE *fp;
    fp = fopen("student.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1)
    {
        if(strcmp(c,stu.Class)==0&&strcmp(s_id,stu.ID) == 0)
        {
            isfound = 1;
            break;
        }
    }
    if(isfound == 1)
    {
        printf("The record is found\n");
        printf("Name: ");
        puts(stu.name);
        printf("ID: ");
        puts(stu.ID);
        printf("Class: ");
        puts(stu.Class);
        printf("Mobile: ");
        puts(stu.mobile);
    }
    else
        printf("\nNo record found in database!!!\n");
    fclose(fp);
    printf("\n\t1.Search Again\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        search_student();
    case 0:
        admin();
    }
}

void search_teacher()
{
    system("CLS");
    print_head();
    printf("Search Teacher\n");
    char t_id[10];
    int isfound = 0;
    printf("Enter id to search: ");
    fflush(stdin);
    gets(t_id);
    FILE *fp;
    fp = fopen("teacher.txt","rb");
    while(fread(&teach,sizeof(teach),1,fp) == 1)
    {
        if(strcmp(t_id,teach.ID) == 0)
        {
            isfound = 1;
            break;
        }
    }
    if(isfound == 1)
    {
        printf("The record is found\n");
        printf("Name: ");
        puts(teach.name);
        printf("ID: ");
        puts(teach.ID);
        printf("Mobile: ");
        puts(teach.mobile);
    }
    else
        printf("\nNo record found in database!!!\n");
    fclose(fp);
    printf("\n\t1.Search Again\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        search_teacher();
    case 0:
        admin();
    }
}

void mod_student()
{
    system("CLS");
    print_head();
    printf("Modify Record\n");
    char s_id[15],c[5];
    int isFound = 0;
    printf("Enter Class: ");
    fflush(stdin);
    gets(c);
    printf("Enter ID to Modify: ");
    gets(s_id);
    FILE *fp,*fs;
    fp = fopen("student.txt","rb+");
    //fs = fopen("student.doc","rb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1)
    {
        if(strcmp(c,stu.Class)==0&&strcmp(s_id,stu.ID) == 0)
        {
            fflush(stdin);
            printf("Name: ");
            gets(stu.name);
            printf("ID: ");
            gets(stu.ID);
            printf("Class: ");
            gets(stu.Class);
            printf("Mobile: ");
            gets(stu.mobile);
            fseek(fp,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound)
    {
        printf("\nNo Record Found\n");
    }
    fclose(fp);
    printf("\n\t1.Modify Another\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        mod_student();
        break;
    case 0:
        mod_records();
    }
}

void mod_teacher()
{
    system("CLS");
    print_head();
    printf("Modify Record\n");
    char t_id[15];
    int isFound = 0;
    printf("Enter ID to Modify: ");
    fflush(stdin);
    gets(t_id);
    FILE *fp,*fs;
    fp = fopen("teacher.txt","rb+");
    while(fread(&teach, sizeof(teach),1,fp) == 1)
    {
        if(strcmp(t_id, teach.ID) == 0)
        {
            fflush(stdin);
            printf("Name: ");
            gets(teach.name);
            printf("ID: ");
            gets(teach.ID);
            printf("Mobile: ");
            gets(teach.mobile);
            fseek(fp,-sizeof(teach), SEEK_CUR);
            fwrite(&teach,sizeof(teach), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound)
    {
        printf("\nNo Record Found\n");
    }
    fclose(fp);
    printf("\n\t1.Modify Another\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        mod_teacher();
        break;
    case 0:
        mod_records();
    }
}

void mod_records()
{
    system("CLS");
    print_head();
    printf("\n\t1.Update Teacher\n\t2.Update Student\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        mod_teacher();
        break;
    case 2:
        mod_student();
        break;
    case 0:
        admin();
        break;
    default:
        break;
    }
}

void delete_student()
{
    system("CLS");
    print_head();
    printf("Delete Record\n");
    char s_id[15],c[5];
    int isFound = 0;
    printf("Enter Class: ");
    fflush(stdin);
    gets(c);
    printf("Enter ID to Delete: ");
    gets(s_id);
    FILE *fp, *temp1, *fs, *temp2;
    fp = fopen("student.txt","rb");
    temp1 = fopen("temp1.txt", "wb");
    while(fread(&stu, sizeof(stu),1,fp) == 1)
    {
        if(strcmp(c,stu.Class)==0&&strcmp(s_id,stu.ID) == 0)
        {
            isFound=1;
        }
        else
        {
            fwrite(&stu,sizeof(stu),1,temp1);
        }
    }
    fclose(fp);
    fclose(temp1);
    remove("student.txt");
    rename("temp1.txt","student.txt");
    if(isFound==1)
        printf("\nThe record is sucessfully deleted\n");
    else
        printf("\nNo record is found\n");
    printf("\n\t1.Delete Another\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        delete_student();
        break;
    case 0:
        delete_records();
    }
}


void delete_teacher()
{
    system("CLS");
    print_head();
    printf("Delete Record\n");
    char t_id[15];
    int isFound = 0;
    printf("Enter ID to Delete: ");
    fflush(stdin);
    gets(t_id);
    FILE *fp, *temp1, *fs, *temp2;
    fp = fopen("teacher.txt","rb");
    temp1 = fopen("temp1.txt", "wb");
    while(fread(&teach, sizeof(teach),1,fp) == 1)
    {
        if(strcmp(t_id, teach.ID) == 0)
        {
            isFound=1;
        }
        else
        {
            fwrite(&teach,sizeof(teach),1,temp1);
        }
    }
    fclose(fp);
    fclose(temp1);
    remove("teacher.txt");
    rename("temp1.txt","teacher.txt");
    if(isFound==1)
        printf("\nThe record is sucessfully deleted\n");
    else
        printf("\nNo record is found\n");
    printf("\n\t1.Delete Another\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        delete_teacher();
        break;
    case 0:
        delete_records();
    }
}

void delete_records()
{
    system("CLS");
    print_head();
    printf("\n\t1.Delete Teacher\n\t2.Delete Student\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        delete_teacher();
        break;
    case 2:
        delete_student();
        break;
    case 0:
        admin();
        break;
    default:
        break;
    }
}

void password()
{
    char t_user[10],t_pass[10];
    int i;
    printf("Enter Username: ");
    scanf("%s",&t_user);
    printf("Enter Password: ");
    for(i=0; i<10; i++)
    {
        t_pass[i]=getch();
        if(t_pass[i]==13)
            break;
        else
            printf("*");
    }
    t_pass[i]='\0';
    FILE *fp;
    fp=fopen("Pass.txt","rb+");
    while(fread(&m_pass,sizeof(m_pass),1,fp) == 1)
    {
        if(strcmp(t_user,m_pass.user) == 0&&strcmp(t_pass,m_pass.pass)==0)
            admin();
        else
        {
            system("CLS");
            printf("Username or Password is incorrect!!!\n");
            password();
        }
        fclose(fp);
    }
}




void sort_student()
{
    FILE *fp,*temp,*fs,*fg;
    char Class[5],f[20];
    int count=0,c=0,i,j,k,l=0;
    printf("Enter the Class: ");
    fflush(stdin);
    gets(Class);
    strcpy(f,Class);
    strcat(f,"_class.txt");
    fg = fopen(f,"wb+");
    fs = fopen("student.txt","rb");
    while(fread(&stu,sizeof(stu),1,fs) == 1)
    {
        if(strcmp(Class,stu.Class) == 0)
        {
            fwrite(&stu,sizeof(stu),1,fg);
        }
    }
    fclose(fs);
    fclose(fg);
    fp = fopen(f,"rb+");
    long int id[max],t;

    while (fread(&stu, sizeof(stu), 1, fp)==1)
    {
        id[c] = atoi(stu.ID);
        c++;
    }
    count=c;
    for (i = 0; i<count - 1; i++)
    {
        for (j = i + 1; j<count; j++)
        {
            if (id[i]>id[j])
            {
                t = id[i];
                id[i] = id[j];
                id[j] = t;
            }
        }
    }
    k=c;
    temp=fopen("temp.txt","wb");
    for (i = 0; i<k; i++)
    {
        rewind(fp);
        while (fread(&stu, sizeof(stu), 1, fp))
        {
            if (id[i] == atoi(stu.ID))
            {
                fwrite(&stu,sizeof(stu), 1, temp);
            }
        }
    }
    fclose(fp);
    fclose(temp);
    remove(f);
    rename("temp.txt",f);
    printf("\n\tThe list of student is sorted successfully");
    printf("\n\t1.Create Student List for Another Class\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        sort_student();
        break;
    case 0:
        teacher();
        break;
    }

}


struct subject
{
    char Class[2];
    char sub_no[3];
    char sub[10][20];
};

struct subject sub;

void sub_input()
{
    system("CLS");
    print_head();
    int i;
    printf("\n\tEnter The Class: ");
    scanf("%s",&sub.Class);
    printf("\n\tHow many subjects are in this Class?");
    scanf("%d",&i);
    getchar();
    itoa(i,sub.sub_no,10);
    printf("\n\tEnter the subject name:\n");
    for(int j=0; j<i; j++)
    {
        printf("\n\t%d. ",j+1);
        gets(sub.sub[j]);
    }
    FILE *fp=fopen("Subject.txt","ab+");
    fwrite(&sub,sizeof(sub),1,fp);
    printf("\n\tSubjects added successfully");
    fclose(fp);
    printf("\n\t1.Add Subjects for Another Class\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        sub_input();
        break;
    case 0:
        main();
        break;
    }
}

struct res
{
    char name[20];
    char ID[10];
    char marks[10][4];
    char total[5];
    char gpa[4];
};

struct res reslt;

float gpa(int m)
{
    if(m>=80)
        return 5.00;
    else if(m<=79&&m>=70)
        return 4.00;
    else if(m<=69&&m>=60)
        return 3.50;
    else if(m<=59&&m>=50)
        return 3.00;
    else if(m<=49&&m>=40)
        return 2.00;
    else if(m<=39&&m>=33)
        return 1.00;
    else
        return 0.00;
}

void result()
{
    char c[5],f[20],d[20],e[10];
    FILE *fp,*fq,*fs;
    int i,j,total,m,count;
    double gp;
    getchar();
    printf("Enter Class: ");
    gets(c);
    strcpy(f,c);
    strcat(f,"_class.txt");
    strcpy(d,c);
    strcat(d,"_result.txt");
    printf("Initial ID: ");
    int id;
    scanf("%d",&id);
    getchar();
    fs=fopen(f,"rb+");
    while(fread(&stu,sizeof(stu),1,fs))
        count++;
    fclose(fs);
cr:
    system("CLS");
    total=0;
    gp=0.00;
    count=0;
    fp=fopen(d,"ab+");
    fs=fopen(f,"rb+");
    fq=fopen("Subject.txt","rb");
    while(fread(&sub,sizeof(sub),1,fq))
    {
        if(strcmp(c,sub.Class)==0)
        {
            j=atoi(sub.sub_no);
            itoa(id,e,10);
            while(fread(&stu,sizeof(stu),1,fs))
            {
                if(strcmp(e,stu.ID)==0)
                {
                    strcpy(reslt.ID,e);
                    printf("Enter the marks for \n");
                    printf("ID = %s\tName = %s",stu.ID,stu.name);
                    strcpy(reslt.name,stu.name);
                    for(i=0; i<j; i++)
                    {
                        printf("\nMarks of %s = ",sub.sub[i]);
                        gets(reslt.marks[i]);
                        m=atoi(reslt.marks[i]);
                        if(gpa(m)==0.00) count=1;
                        gp=gp+gpa(m);
                        total=total+m;
                        itoa(m,reslt.marks[i],10);
                    }
                    if(count==1) gp=0.00;
                    else gp=gp/j;
                    gcvt(gp,3,reslt.gpa);
                    itoa(total,reslt.total,10);
                }
            }
            fwrite(&reslt,sizeof(reslt),1,fp);
        }
    }
    fclose(fp);
    fclose(fq);
    fclose(fs);
    if(id<count)
    {
        printf("\n\t1.Enter Marks for ID: %d\n\t0.Back",id+1);
        int n;
        printf("\n\tEnter your option: ");
        scanf("%d",&n);
        getchar();
        switch(n)
        {
        case 1:
        {
            id++;
            goto cr;
        }
        case 0:
            teacher();
        default:
            break;
        }
    }
    else
    {
        printf("\n\tThanks for entering marks");
        printf("\n\tPress any key to go back on admin panel");
        getchar();
        main();
    }
}

void mod_marks()
{
    system("CLS");
    print_head();
    printf("Modify Marks\n");
    char s_id[15],c[5],f[20],e[10];
    int i,j,total=0,m=0,count=0;
    int gp = 0,isFound=0;
    printf("Enter Class: ");
    fflush(stdin);
    gets(c);
    printf("Enter ID: ");
    gets(s_id);
    FILE *fp,*fs;
    strcpy(f,c);
    strcat(f,"_result.txt");
    fp=fopen(f,"rb+");
    fs=fopen("Subject.txt","rb+");
    while(fread(&sub,sizeof(sub),1,fs))
    {
        if(strcmp(c,sub.Class)==0)
        {
            fflush(stdin);
            j=atoi(sub.sub_no);
            //itoa(id,e,10);
            while(fread(&reslt,sizeof(reslt),1,fp))
            {
                if(strcmp(s_id,reslt.ID)==0)
                {
                    //strcpy(reslt.ID,e);
                    printf("Enter the marks for \n");
                    printf("ID = %s\tName = %s",reslt.ID,reslt.name);
                    //strcpy(reslt.name,stu.name);
                    for(i=0; i<j; i++)
                    {
                        printf("\nMarks of %s = ",sub.sub[i]);
                        gets(reslt.marks[i]);
                        m=atoi(reslt.marks[i]);
                        if(gpa(m)==0.00) count=1;
                        gp=gp+gpa(m);
                        total=total+m;
                        itoa(m,reslt.marks[i],10);
                    }
                    if(count==1) gp=0.00;
                    else gp=gp/j;
                    gcvt(gp,3,reslt.gpa);
                    itoa(total,reslt.total,10);
                    isFound=1;
                    fseek(fp,-sizeof(reslt), SEEK_CUR);
                    fwrite(&reslt,sizeof(reslt),1,fp);
                    break;
                }

            }

        }
    }
    if(!isFound)
    {
        printf("\nNo Record Found\n");
    }
    fclose(fp);
    fclose(fs);
    printf("\n\t1.Modify Another\n\t0.Back\n\t");
    int q;
    option();
    scanf("%d",&q);
    switch(q)
    {
    case 1:
        mod_marks();
        break;
    case 0:
        teacher();
    }
}


struct asn_teach{
    char name[30];
    char ID[10];
    char Class[2];
};

struct asn_teach assgn_teach;

void assign_teacher()
{
    system("CLS");
    print_head();
    printf("Search Teacher\n");
    char t_id[10],c[2];
    int isfound = 0;
    printf("Enter ID to search teacher: ");
    fflush(stdin);
    gets(t_id);
    FILE *fp,*fs;
    fp = fopen("teacher.txt","rb");
    fs = fopen("assign_teacher.txt","ab+");
    while(fread(&teach,sizeof(teach),1,fp) == 1)
    {
        if(strcmp(t_id,teach.ID) == 0)
        {
            isfound = 1;
            break;
        }
    }
    if(isfound == 1)
    {
        printf("The record is found\n");
        printf("Name: ");
        puts(teach.name);
        printf("ID: ");
        puts(teach.ID);
        printf("Mobile: ");
        puts(teach.mobile);
        printf("\nEnter the class in which the teacher should be assigned: ");
        gets(c);
        strcpy(assgn_teach.name,teach.name);
        strcpy(assgn_teach.ID,teach.ID);
        strcpy(assgn_teach.Class,c);
        fwrite(&assgn_teach,sizeof(assgn_teach),1,fs);
    }
    else
        printf("\nNo record found in database!!!\n");
    fclose(fp);
    fclose(fs);
        printf("\n\t1.Assign Another\n\t2.Go Back\n\t");
        int n;
        option();
        scanf("%d",&n);
        getchar();
        switch(n)
        {
        case 1:
            assign_teacher();
            break;
        case 2:
            admin();
            break;
        default:
            break;
}
}


void teacher()
{
    system("CLS");
    print_head();
    char t_id[10],c[2];
    int isfound = 0;
    printf("Enter Class: ");
    fflush(stdin);
    gets(c);
    printf("\nEnter Teacher ID: ");
    gets(t_id);
    FILE *fp;
    fp = fopen("assign_teacher.txt","rb");
    while(fread(&assgn_teach,sizeof(assgn_teach),1,fp) == 1)
    {
        if((strcmp(t_id,assgn_teach.ID) == 0)&&strcmp(c,assgn_teach.Class)==0)
        {
            isfound = 1;
            break;
        }
    }
    fclose(fp);
    if(isfound==1)
    {
        system("CLS");
        print_head();
        printf("\n\tYou have been assigned as Class Teacher of Class %s\n",assgn_teach.Class);
        printf("\n\t1.Create Sorted Student List\n\t2.Enter Marks of The Students\n\t3.Modify Marks\n\t0.Back\n\t");
        int n;
        option();
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            sort_student();
            break;
        case 2:
            result();
            break;
        case 3:
            mod_marks();
            break;
        case 0:
            main();
            break;
        default:
            break;
        }
    }
    else
    {
        printf("\n\t The teacher is not assigned!!!!\n");
        printf("\n\t1.Try Again\n\t2.Go Back\n\t");
        int n;
        option();
        scanf("%d",&n);
        getchar();
        switch(n)
        {
        case 1:
            teacher();
            break;
        case 2:
            main();
            break;
        default:
            break;
        }
    }
}

void student()
{
    system("CLS");
    print_head();
    printf("\n\t1.Combined Result\n\t2.Result by Roll\n\t0.Back\n\t");
    int n;
    option();
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        com_res();
        break;
    case 2:
        res_roll();
        break;
    case 0:
        main();
        break;
    default:
        break;
    }
}

void com_res()
{
    system("CLS");
    print_head();
    FILE *fp,*temp,*fs,*fg;
    char Class[5],f[20];
    int count=0,c=0,i,j,k,l=0,pos=1;
    printf("Enter the Class: ");
    fflush(stdin);
    gets(Class);
    strcpy(f,Class);
    strcat(f,"_result.txt");
    fp = fopen(f,"rb+");
    double gp[max],t,g_p_a;

    while (fread(&reslt, sizeof(reslt), 1, fp)==1)
    {
        gp[c] = atof(reslt.gpa);
        c++;
    }
    count=c;
    for (i = 0; i<count - 1; i++)
    {
        for (j = i + 1; j<count; j++)
        {
            if (gp[i]<gp[j])
            {
                t = gp[i];
                gp[i] = gp[j];
                gp[j] = t;
            }
        }
    }
    k=c;
    temp=fopen("temp.txt","wb");
    for (i = 0; i<k; i++)
    {
        rewind(fp);
        while (fread(&reslt, sizeof(reslt), 1, fp))
        {
            if (gp[i] == atof(reslt.gpa))
            {
                fwrite(&reslt,sizeof(reslt), 1, temp);
            }
        }
    }
    fclose(fp);
    fclose(temp);
    remove(f);
    rename("temp.txt",f);

    fg=fopen(f,"rb");
    printf("\n         \tResult of Class %s\n",Class);
    printf("        \t------------------\n");
    printf("\nPosition\tName   \t\t\t  ID\tGPA\n");
    printf("......................................................\n");
    while (fread(&reslt, sizeof(reslt), 1, fg))
    {
        g_p_a=atof(reslt.gpa);
        printf("%4d\t\t%s\t%20s\t%2.2lf\n",pos,reslt.name,reslt.ID,g_p_a);
        pos++;
    }

    printf("\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 0:
        student();
        break;
    }
}

void res_roll()
{
    system("CLS");
    print_head();
    printf("Result by ID\n");
    char s_id[10],c[5],f[20];
    int isfound = 0,i,j,k;
    double g_p_a;
    printf("Enter Class: ");
    fflush(stdin);
    gets(c);
    printf("Enter ID: ");
    gets(s_id);
    strcpy(f,c);
    strcat(f,"_result.txt");
    FILE *fp,*fg;
    fp = fopen(f,"rb");
    fg = fopen("Subject.txt","rb");
    while(fread(&sub,sizeof(sub),1,fg))
    {
        if(strcmp(c,sub.Class)==0)
        {
            j=atoi(sub.sub_no);
            while(fread(&reslt,sizeof(reslt),1,fp) == 1)
            {
                if(strcmp(s_id,reslt.ID) == 0)
                {
                    printf("\n\tHere is your result\n");
                    printf("\t.....................\n");
                    printf("Name: %s\t ID: %s\t Class: %s\n\n",reslt.name,reslt.ID,c);
                    for(i=0; i<j; i++)
                    {
                        //printf("1\n");
                        printf("%20s = %s\n",sub.sub[i],reslt.marks[i]);
                    }
                    g_p_a=atof(reslt.gpa);
                    printf("\n\n\tTotal Marks = %s \t\t GPA = %.2lf\n",reslt.total, g_p_a);
                    isfound = 1;
                    break;
                }
            }
        }
    }
    if(isfound != 1)
        printf("\nYour Result has not been created. Contact with your teacher!!!\n");
    fclose(fp);
    fclose(fg);
    printf("\n\t1.Search Again\n\t0.Back\n\t");
    int m;
    option();
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        res_roll();
    case 0:
        student();
    }
}

void print_developer()
{
    system("CLS");
    print_head();
    printf("\n\tDeveloped By: \n");
    printf("\n\t1. Md. Sajid Altaf(180041203)\n");
    printf("\n\t2. Minhaz Kamal(180041231)\n");
    printf("\n\t3. Chowdhury Mohammad Abdullah(180041239)\n");
    printf("\n\n\tPress any key to continue");
    getch();
}


void main()
{
    if(w==0)
    print_developer();
    w++;
    system("CLS");
    print_head();
    printf("\n\t1.Admin\n\t2.Teacher\n\t3.Student\n\t4.Exit\n\t");
    int n;
    while(1)
    {
        option();
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            password();
            break;
        case 2:
            teacher();
            break;
        case 3:
            student();
            break;
        case 4:
            exit(0);
            break;
        default:
            break;

        }
    }
}

