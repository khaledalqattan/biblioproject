#include <stdio.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>

int main(void) {
    struct Data entries [30] ; //contains data read from txt file //read_bibliography (bibliofile.txt , entries);
    int entryNumbers=read_bibliography( entries );
    int choice= read_menu(); // read menu // correct and tested
    switch (choice) {

         char name[100];
         char title[100];
         int year1;
         int from;
         int to;

                case 1 : //search by author name // correct and tested
                printf("Type the author name \n");
                scanf("%s",name);
                by_Author_name(entries , name);
            break;
                case 2: // search by title // correct and tested
                printf("Type the title \n");
                scanf("%s",title );
                by_title(entries, title);
            break;
                case 3: // Display all publications // should be able to count types
                printf("list of all publications Author,Title,Type and Year of publication \n");
                Display_publications( entries ,entryNumbers );
            break;
                 case 4: // authors_names_list
                 printf("list of authors name organized alphabetically \n");
                 authors_names_list( entries );
            break;
                 case 5: // duplicate_detector // not correct
                 duplicate_detector( entries ,entryNumbers );
            break;
                 case 6: //UWE_Harvard reference all publications // approximately correct
                 printf("All publications in UWE Harvard reference: \n");
                 UWE_Harvard( entries ,entryNumbers);
            break;
                 case 7: //missing_info
                 printf("functions with missing information's: \n");
                 missing_info( entries );
            break;
                 case 8:// add_bibliography
                     add_bibliography(&entries,&entryNumbers);
            break;
                 case 9: // search by year of publish // correct and tested
                 printf("enter the year \n");
                 scanf("%d", &year1);
                 printf("publications released in that year \n");
                 by_Single_year(entries, year1);
            break;
                  case 10: // search by range of years of publish // correct and tested
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
            printf("Year: %d \n" , entries[i].year);
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
            printf("Year: %d \n" , entries[i].year);
        }
    }
}

void Display_publications(struct Data *entries , int entryNumbers )
{
    for ( int i =0 ; i < entryNumbers ; i++ ){
        // print all entries
        printf("%d \n" , i+1); // count // but need to stop
        printf("%s \n" , entries[i].author);
        printf("%s \n" , entries[i].title);
        printf("%s \n" , entries[i].type);
        printf("%d \n" , entries[i].year);
        printf("--------------------------------------------------------- \n");
    }
}

void authors_names_list(struct Data *entries )
{
    for ( int i =0 ; i < 30 ; i++ ){
        // print all authors alphabetically
        printf("%s \n" , entries[i].author);
    }
}
void duplicate_detector(struct Data *entries , int entriesNumber ) // should we compare each entry?
{
    for (int i = 0; i < entriesNumber-1; i++) {
        for (int j = i+1; j < entriesNumber; j++) {
            if ( // compare entries
                    strcmp(entries[i].author, entries[j].author) == 0 &&
                    strcmp(entries[i].title, entries[j].title) == 0 &&
                    strcmp(entries[i].type, entries[j].type) == 0 &&
                    entries[i].year == entries[j].year
                    ) {// print true
                printf("Duplications here : \n");
                printf("Author: %s \n", entries[i].author);
                printf("Title: %s \n", entries[i].title);
                printf("Type: %s \n", entries[i].type);
                printf("Year: %d \n", entries[i].year);
                printf("------------------------------------------------------------ \n");
            }
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
            printf("Year: %d \n" , entries[i].year);
            printf("-------------------------------------------------------------- \n");
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
               printf("Year: %d \n" , entries[i].year);
               printf("-------------------------------------------------------------- \n");
           }
        }
    }
}
void UWE_Harvard(struct Data *entries , int entriesNumber ) { // function to display a UWE Harvard reference for a given publication
    for (int i = 0; i < entriesNumber; i++) {
        printf("- %s. (%d) %s[online].%d. vol %d. %s. Available from: %s \n", entries[i].author, entries[i].year,
               entries[i].title, entries[i].issue, entries[i].vol, entries[i].publisher, entries[i].url);
    }// Author surname, initials. (Year of publication) Title [online]. Edition (if not first edition). Place of publication: Publisher. [Accessed DD Month YYYY].
    // if info missing replace with Anon
}
void add_bibliography(struct Data *entries , int *entriesNumber ) // function that allows the user to add a bibliography//send by ref , send by value
{   *entriesNumber++; // not complete
    printf("Enter type \n");
    scanf("%s",entries[*entriesNumber].type);






    //update file
    FILE *file = fopen("bibliofile.txt", "a");

    fprintf(file,"@%s{,\n");
}
// void missing_info(struct Data *entries )// function to display missing information from a given publication

//void read_bibliography(struct Data *entries ); // function to read entries in the given bibliography

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// just for practise

void clean_value(char *value) {
    // Removes braces, commas, newlines, tabs, and spaces at the beginning
    char *src = value, *dst = value;
    while (*src) {
        if (*src != '{' && *src != '}' && *src != ',' && *src != '\n' && *src != '\r')
            *dst++ = *src;
        src++;
    }
    *dst = '\0';
}

int read_bibliography(struct Data *entries) {
    FILE *file = fopen("bibliofile.txt", "r");
    if (!file) {
        perror("Error opening bibliofile.txt");
        return -1;
    }

    char line[500];
    int entryIndex = -1;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "@")) {
            entryIndex++;
            if (entryIndex >= 30) break; // prevent overflow
            memset(&entries[entryIndex], 0, sizeof(struct Data)); // reset struct

            if (strstr(line, "@article")) strcpy(entries[entryIndex].type, "article");
            else if (strstr(line, "@techReport")) strcpy(entries[entryIndex].type, "techReport");
            else if (strstr(line, "@inproceedings")) strcpy(entries[entryIndex].type, "inproceedings");
            else if (strstr(line, "@misc")) strcpy(entries[entryIndex].type, "misc");
            continue;
        }

        char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");

        if (!key || !value) continue;

        // Clean up spaces
        while (*value == ' ' || *value == '\t') value++;

        clean_value(value); // fix for incorrect values

        if (strstr(key, "author")) strcpy(entries[entryIndex].author, value);
        else if (strstr(key, "title")) strcpy(entries[entryIndex].title, value);
        else if (strstr(key, "year")) entries[entryIndex].year = atoi(value);  // corrected year parsing
        else if (strstr(key, "issue")) strcpy(entries[entryIndex].issue, value);
        else if (strstr(key, "publisher")) strcpy(entries[entryIndex].publisher, value);
        else if (strstr(key, "url")) strcpy(entries[entryIndex].url, value);
        else if (strstr(key, "volume")) entries[entryIndex].vol = atoi(value);
    }

    fclose(file);
    return entryIndex+1;
}
