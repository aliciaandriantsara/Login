#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_account.h"


void foot()
{
    printf("</html>\n");
}

void body()
{
    printf("    <body>\n");
    printf("        <h1>New account</h1>\n");
    printf("        <form action=\"saving.cgi\" method=\"get\">\n");
    printf("            Username : <input type=\"text\" name=\"user_name\"/>\n");
    printf("            </br>\n");
    printf("            Password : <input type=\"password\" name=\"user_password\"/>\n");
    printf("            </br>\n");
    printf("            <input type=\"submit\" value=\"Create a new account\" />\n");
    printf("        </form>\n");
    printf("    </body>\n");
}

void head()
{
    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("    <head>\n");
    printf("        <title>Newaccount</title>\n");
    printf("        <meta charset=\"utf-8\"/>\n");
    printf("        <link rel=\"stylesheet\" href=\"new_account.css\"/>\n");
    printf("    </head>\n");
}