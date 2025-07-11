#include <stdio.h>
#include <string.h>
#include "main.h"


int main(void) {
    struct Data entries [30] ; //contains data read from txt file //read_bibliography (bibliofile.txt , entries);
    int choice= read_menu(); // read menu

    switch (choice) {

         char name[100];
         char title[100];
         int year1;
         int from;
         int to;
                case 1 : //search by author name
                printf("Type the author name \n");
                scanf("%s",name);
                by_Author_name(entries , name);
            break;
                case 2: // search by title
                printf("Type the title \n");
                scanf("%s",title );
                by_title(entries, title);
            break;
                case 3: // Display all publications
                printf("list of all publications Author,Title,Type and Year of publication \n");
                Display_publications( entries );
            break;
                 case 4: // authors_names_list
                 printf("list of authors name organized alphabetically \n");
                 authors_names_list( entries );
            break;
                 case 5: // duplicate_detector
                 duplicate_detector( entries );
            break;
                 case 6: //UWE_Harvard reference all publications
                     printf("All publications in UWE Harvard reference: \n");
                 UWE_Harvard( entries );
            break;
                 case 7: //missing_info
            break;
                 case 8:// add_bibliography
            break;
                 case 9: // search by year of publish
                 printf("enter the year \n");
                 scanf("%d", &year1);
                 printf("publications released in that year \n");
                 by_Single_year(entries, year1);
            break;
                  case 10: // search by range of years of publish
                  printf("enter the range of years from to:  \n");
                  scanf("%d %d",&from, &to);
                  printf("publications released in these years \n");
                  by_Range_years(entries, from, to);
            break;
}
return 0;
}


int read_menu() {
   FILE *fptr;
   int choice;
   fptr = fopen("menu.txt", "r");
   char myString[100];
   while(fgets(myString, 100, fptr)) {printf("%s", myString);
   }
   fclose(fptr);
   scanf("%d",&choice);
   return choice;
}

void by_Author_name(struct Data *entries , char *authorName)
{
    for ( int i =0 ; i < 30 ; i++ )
    {
        if ( strstr (entries[i].author     , authorName) )
        {
            //print data
            printf("Author: %s \n" , entries[i].author);
            printf("Title: %s \n" , entries[i].title);
            printf("Type: %s \n" , entries[i].type);
            printf("Year: %s \n" , entries[i].year);
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
            printf("Author:%s \n" , entries[i].author);
            printf("Title: %s \n" , entries[i].title);
            printf("Type: %s \n" , entries[i].type);
            printf("Year: %s \n" , entries[i].year);
        }
    }
}

void Display_publications(struct Data *entries )
{
    for ( int i =0 ; i < 30 ; i++ ){
        // print all entries
        printf("%s \n" , entries[i].author);
        printf("%s \n" , entries[i].title);
        printf("%s \n" , entries[i].type);
        printf("%s \n" , entries[i].year);
        printf("------------------------- \n");
    }
}
void authors_names_list(struct Data *entries )
{
    for ( int i =0 ; i < 30 ; i++ ){
        // print all authors alphabetically
        printf("%s \n" , entries[i].author);
    }
}
void duplicate_detector(struct Data *entries ) // should we compare each entry?
{
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if ( // compare entries
                strcmp(entries[i].author, entries[j].author) == 0 &&
                strcmp(entries[i].title, entries[j].title) == 0 &&
                strcmp(entries[i].type, entries[j].type) == 0 &&
                strcmp(entries[i].year, entries[j].year) == 0
                ); // print true
            printf("Author: %s \n" , entries[i].author);
            printf("Title: %s \n" , entries[i].title);
            printf("Type: %s \n" , entries[i].type);
            printf("Year: %s \n" , entries[i].year);
            printf("------------------------- \n");
        }
    }

}

void by_Single_year(struct Data *entries, int year1)
{
    for ( int i =0 ; i < 30 ; i++ ){
        if ( entries[i].year == year1){
            // print data
            printf("Author: %s \n" , entries[i].author);
            printf("Title: %s \n" , entries[i].title);
            printf("Type: %s \n" , entries[i].type);
            printf("Year: %s \n" , entries[i].year);
            printf("------------------------- \n");
        }
    }

}

void by_Range_years(struct Data *entries ,int from , int to) {
    for (int x = from; x <= to; x++) {
        for (int i = 0; i < 30; i++) {
           if (entries[i].year == x){
               //print data
               printf("Author: %s \n" , entries[i].author);
               printf("Title: %s \n" , entries[i].title);
               printf("Type: %s \n" , entries[i].type);
               printf("Year: %s \n" , entries[i].year);
               printf("------------------------- \n");
           }
        }
    }
}
void UWE_Harvard(struct Data *entries ) { // function to display a UWE Harvard reference for a given publication
    for (int i = 0; i < 30; i++) {
        printf("- %s. (%s) %s[online].%s. vol %s. %s. Available from: %s \n", entries[i].author, entries[i].year,
               entries[i].title, entries[i].issue, entries[i].vol, entries[i].publisher, entries[i].url);
    }// Author surname, initials. (Year of publication) Title [online]. Edition (if not first edition). Place of publication: Publisher. [Accessed DD Month YYYY].
    // if info missing replace with Anon
}

//void missing_info(struct Data *entries ); // function to display missing information from a given publication

//void add_bibliography(struct Data *entries ); // function that allows the user to add a bibliography

//void read_bibliography(struct Data *entries ); // function to read entries in the given bibliography