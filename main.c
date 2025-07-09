#include <stdio.h>
#include <string.h>
#include "main.h"


int main(void) {
        struct Data entries [30] ; //contains data read from txt file
        //read_bibliography(bibliofile.txt , entries);
       int choice= read_menu(); // read menu
         switch (choice)
                {
               char name[100];
               char title[100];
               case 1 :
                printf("Type the author name \n");
                scanf("%s",name);
                by_Auther_name(entries , name);
            break;
            case 2:
                printf("Type the title \n");
                scanf("%s",title );
                by_Auther_name(entries , name);
                by_title(entries, title);
            break;
            case 3:
           // Display_publications();
            break;
            case 4:
           // authers_names_list();
            break;
            case 5:
           // dublicate_didecter();
            break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
}
return 0;
}


int read_menu() {
FILE *fptr;
int choice;
fptr = fopen("menu.txt", "r");
char myString[100];
while(fgets(myString, 100, fptr)) {
    printf("%s", myString);
}
fclose(fptr);
scanf("%d",&choice);
    return choice;
}

void by_Auther_name(struct Data *entries , char *autherName)
{
    for ( int i =0 ; i < 30 ; i++ )
    {
        if ( strstr (   entries[i].auther     , autherName) )
        {
            //print data
        }
    }
}
void by_title(struct Data *entries ,char *title) // function to search by title
{
    for ( int i =0 ; i < 30 ; i++ )
    {
        if ( strstr (   entries[i].title     , title) )
        {
            //print data
        }
    }
}

void Display_publications(struct Data *entries ) // function to display publications
{

}
void authers_names_list(struct Data *entries ) // function to list authors by name
{

}
void dublicate_didecter(struct Data *entries ) // function to display duplicates
{

}



void by_Single_year(struct Data *entries, int signYear)
{

}

void by_Range_years(struct Data *entries ,int start , int end){

}
