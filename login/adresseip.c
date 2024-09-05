#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "adresseip.h"


int main()
{
    char *title="Adressse IP";
    
    
    head(title);
    head_of_body();
    int number_of_character=0;
    number_of_character=strlen(getenv("QUERY_STRING"));
    last_test(number_of_character);    
    
    foot_of_body();
    return (0);
}

void last_test(int number_of_character)
{
    int chaine=0;
    char recovery_ip[16];
    if(number_of_character<=18)
    {
        strcpy(recovery_ip, getenv("QUERY_STRING"));
        chaine=chainecarac(recovery_ip);
        main_main(recovery_ip, chaine);
    }
    else
    {
        printf("                <p>Vous n'avez pas suivi l'instruction. Recommencez</p>\n");

    }
}

void main_main(char *recovery_ip, int chaine_ip)
{
    int *adresse_reseau=NULL;
    int *a=NULL;
    char tab_ip_1[4];
    char tab_ip_2[4];
    char tab_ip_3[4];
    char tab_ip_4[4];
    a=(int*)malloc(4*sizeof(int));
    int verification=0;
    int verification_2=0;
    int *msr_default=NULL;
    int *adresse_broadcast=NULL;
    int number_of_machine=0;
    if(chaine_ip == 1)
    {
        sscanf(recovery_ip, "ip=%[^.].%[^.].%[^.].%[^.]", tab_ip_1, tab_ip_2, tab_ip_3, tab_ip_4);
        verification_2=verification_verification(tab_ip_1, tab_ip_2, tab_ip_3, tab_ip_4);

        if(verification_2 == 0)
        {
            verification=testing_adresss(tab_ip_1, tab_ip_2, tab_ip_3, tab_ip_4);
            type_of_adress(verification, tab_ip_1, tab_ip_2, tab_ip_3, tab_ip_4);
            // a=changing_type(tab_ip_1, tab_ip_2, tab_ip_3, tab_ip_4);
        }
        else 
        {
            printf("                <p>Vous avez tapez des lettres au lieu de nombre. Recommencez</p>\n");
            goto RESTART;
        }
    }
    else
    {
        printf("                <p>Vous n'avez pas suivi l'instruction. Recommencez</p>\n");
    }
RESTART:
}

int verification_verification(char* tab_ip_1, char* tab_ip_2, char* tab_ip_3, char* tab_ip_4)
{
    int verification_2=0;
    if(!atoi(tab_ip_1))
    {
        verification_2=1;
    }
    else if(!atoi(tab_ip_2))
    {
        verification_2=1;
    }
    else if(!atoi(tab_ip_3))
    {
        verification_2=1;
    }
    else if(!atoi(tab_ip_4))
    {
        verification_2=1;
    }
    return (verification_2);

}

int* changing_type(char* tab_ip_1, char* tab_ip_2, char* tab_ip_3, char* tab_ip_4)
{
    int* a=NULL;
    a=(int*)malloc(4*sizeof(int));
    a[0]=atoi(tab_ip_1);
    a[1]=atoi(tab_ip_2);
    a[2]=atoi(tab_ip_3);
    a[3]=atoi(tab_ip_4);
    return (a);
    
}


int chainecarac(char* recovery_ip)
{
    int chaine=0;
    int i;
    for(i=0; i<16;i++)
    {
        if(recovery_ip[i] == '.')
        {
            chaine=1;
        }
    }
    return (chaine);
}

int control_error(char *tab_ip_1, char *tab_ip_2, char *tab_ip_3, char *tab_ip_4)
{
    char *tab_ip=NULL;
    int i;
    int *a;
    int verify=0;
    a=(int*)malloc(4*sizeof(int));
    a[0]=strlen(tab_ip_1);
    a[1]=strlen(tab_ip_2);
    a[2]=strlen(tab_ip_3);
    a[3]=strlen(tab_ip_4);
    for(i=0; i<4; i++)
    {
        if(a[i] > 3)
        {
            verify=1;
            printf("        <p>Vous avez faits une erreur. Recommencez</p>\n");
        }
    }
    return (verify);
}

void foot_of_body()
{
    printf("        <p>\n");
    printf("            Cliquez sur le bouton retour pour reesayer et sur logout pour se deconnecter\n");
    printf("            <form action=\"adresseip.html\" method=\"post\">\n");
    printf("                <input type=\"submit\" value=\"Retour\"/>\n");
    printf("            </form>\n");
    printf("            <form action=\"logout.cgi\" method=\"get\">\n");
    printf("                <input type=\"submit\" value=\"Logout\"/>\n");
    printf("            </form>\n");

    printf("        </p>\n");
    printf("    </body>\n");
    printf("</html>\n");
}

void head_of_body()
{
    printf("    <body>\n");
    printf("        <h1>Adresse IP</h1>\n");
}


void head(char *title)
{
    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("    <head>\n");
    printf("        <title>%s</title>\n", title);
    printf("        <meta charset=\"utf-8\"/>\n");
    printf("        <link rel=\"stylesheet\" href=\"adresseip.css\"/>\n");
    printf("    </head>\n");
}

void type_of_adress(int verification, char *tab_ip_1,  char *tab_ip_2, char *tab_ip_3, char *tab_ip_4)
{
    int value_1=0;
    value_1=atoi(tab_ip_1);
    int verify=0;
    verify=control_error(tab_ip_1, tab_ip_2, tab_ip_3, tab_ip_4);
    if(verify == 1)
    {
        goto QUIT;
    }
    else
    {
        if(verification == 1)
        {
            printf("            <p>Ce que vous avez entrez n'est pas un adresse IP</p>\n");
        }
        else
        {
            if (value_1 < 128)
            {
                printf("            <p>Vous avez entrez un adresse IP de type A</p>\n");
            }
            else if(value_1 < 192)
            {
                printf("            <p>Vous avez entrez un adresse IP de type B</p>\n");
                
            }            
                
            else if(value_1 < 224)
            {
                printf("            <p>Vous avez entrez un adresse IP de type C</p>\n");

            }  
            else if(value_1 <240)
            {
                printf("            <p>Vous avez entrez un adresse IP de type D</p>\n");

            }
            else
            {
                printf("            <p>Vous avez entrez un adresse IP de type E</p>\n");

            }
        
        }
    }
QUIT:
}

int testing_adresss(char *tab_ip_1, char *tab_ip_2, char *tab_ip_3, char *tab_ip_4)
{
    int *tab_ip;
    int i;
    int verification=0;
    tab_ip=(int*)malloc(4*sizeof(int));
    tab_ip[0]=atoi(tab_ip_1);
    tab_ip[1]=atoi(tab_ip_2);
    tab_ip[2]=atoi(tab_ip_3);
    tab_ip[3]=atoi(tab_ip_4);
    for(i=0; i<4; i++)
    {
        if(tab_ip[i] > 255)
        {
            verification=1;
        }
    }
    return (verification);


}

