#include <stdio.h>
#include <string.h>
void main()
{
    char *s="cate";
    int substringListIter=0;
    int length=strlen(s);
    int i,j,k;
    int numSubstring=(length*(length+1))/2;
    char substringList[numSubstring][length+1];
    for(i=0;i<length;i++)
    {
        for(j=0;j<length-i;j++)
        {
                int sslen=(length-j-i);
                int iter=0;
                char substring[sslen];
            for(k=i;k<length-j;k++)
            {
                printf("%c", s[k]);
                substring[iter]=s[k];
                substringList[substringListIter][iter]=s[k];
                iter++;
            }
            substringList[substringListIter][iter]='\0';
            printf("\t");
            puts(substringList[substringListIter]);
            substringListIter++;
            printf("\n");
        }
    }
    printf("Printing in alphabetical order");
    printf("\n");
    //printf("%d",substringListIter);
    int l=substringListIter;
    char temp[l];
    for (int j=0; j<l-1; j++) 
    { 
        for (int i=j+1; i<l; i++) 
        { 
            if (strcmp(substringList[j],substringList[i]) > 0) 
            { 
                strcpy(temp,substringList[j]); 
                strcpy(substringList[j],substringList[i]); 
                strcpy(substringList[i], temp); 
            } 
        } 
    } 
    //printf("%s",(substringList[1]));
    for (int i=0; i<l; i++) 
    {
        printf("%s ",(substringList[i]));
    }
}