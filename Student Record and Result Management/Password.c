#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 1000

struct pass
{
    char user[10];
    char pass[10];
};

struct pass m_pass;

void pass_g()
{
    FILE *fp;
    fp=fopen("Pass.txt","wb");
    if(fp==NULL)
        exit(0);
    else
    {
        printf("Enter Username: ");
        gets(m_pass.user);
        printf("Enter Password: ");
        gets(m_pass.pass);
        fwrite(&m_pass, sizeof(m_pass), 1, fp);
    }
    fclose(fp);
}

int main()
{
    pass_g();
    return 0;
}
