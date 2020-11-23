#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count=0;

struct student
{
    char name[30];
    char Class[2];
    char ID[10];
    char mobile[12];
    //char z;
};

struct student stu;

struct employee{
char f_name[10];
char l_name[10];
char e_pass[10];
int id;
char e_time[11];
char e_date[12];
};

struct employee emp;

void counter()
{
    FILE *fp;
    fp=fopen("8_class.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1) count++;
    fclose(fp);
}

void main()
{
    counter();
    printf("%d",count);
}
