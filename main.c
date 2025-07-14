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
                by_Author_name(entries , name, entryNumbers);
            break;
                case 2: // search by title // correct and tested // there is an error
                printf("Type the title \n");
                scanf("%s",title );
                by_title(entries, title, entryNumbers);
            break;
                case 3: // Display all publications // correct and tested
                printf("list of all publications Author,Title,Type and Year of publication \n");
                Display_publications( entries ,entryNumbers );
            break;
                 case 4: // authors_names_list // correct and tested
                 authors_names_list( entries , entryNumbers);
            break;
                 case 5: // duplicate_detector // correct and tested
                 duplicate_detector( entries ,entryNumbers );
            break;
                 case 6: //UWE_Harvard reference all publications // correct and tested
                 printf("All publications in UWE Harvard reference: \n");
                 UWE_Harvard( entries ,entryNumbers);
            break;
                 case 7: //missing_info // not done yet
                 printf("functions with missing information's: \n");
            break;
                 case 8:// add_bibliography // not done yet
                     add_bibliography(entries,&entryNumbers);
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

void by_Author_name(struct Data *entries , char *name, int entryNumbers)
{
    for ( int i =0 ; i < entryNumbers ; i++ )
    {
        if ( strstr (entries[i].author     , name) )
        {
            //print data
            printf("Author: %s \n" , entries[i].author);
            printf("Title: %s \n" , entries[i].title);
            printf("Type: %s \n" , entries[i].type);
            printf("Year: %d \n" , entries[i].year);
        }
    }
}
void by_title(struct Data *entries ,char *title , int entryNumbers) // function to search by title
{
    for ( int i =0 ; i < entryNumbers ; i++ )
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

void Display_publications(struct Data *entries , int entryNumbers ) {

    int A = 0, T = 0, I = 0, M = 0; // to count types

        for (int i = 0; i < entryNumbers; i++) {
            // Print all publication
            printf("%d \n", i + 1);
            printf("%s \n", entries[i].author);
            printf("%s \n", entries[i].title);
            printf("%s \n", entries[i].type);
            printf("%d \n", entries[i].year);
            printf("--------------------------------------------------------- \n");
            // count types
            if (strcmp(entries[i].type, "article") == 0) {
                A++;
            } else if (strcmp(entries[i].type, "techReport") == 0) {
                T++;
            } else if (strcmp(entries[i].type, "inproceedings") == 0) {
                I++;
            } else if (strcmp(entries[i].type, "misc") == 0) {
                M++;
            }
        } // print the count
        printf("article in text: %d\n", A);
        printf("techReport in text: %d\n", T);
        printf("inproceedings in text: %d\n", I);
        printf("misc in text: %d\n", M);
    }

void authors_names_list(struct Data *entries , int entryNumbers) {
    for (int i = 0; i < entryNumbers - 1; i++) { // compare authors
        for (int j = i + 1; j < entryNumbers; j++) {
            if (strcmp(entries[i].author, entries[j].author) > 0) {
                struct Data temp = entries[i]; // change entry structure
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
    printf("Authors in alphabetical order:\n"); // Print sorted authors
    for (int i = 0; i < entryNumbers; i++) {
            printf("%s\n", entries[i].author);
        }
    }
void duplicate_detector(struct Data *entries , int entryNumbers )
{
    for (int i = 0; i < entryNumbers-1; i++) {
        for (int j = i+1; j < entryNumbers; j++) {
            if ( // compare entries
                    strcmp(entries[i].author, entries[j].author) == 0 &&
                    strcmp(entries[i].title, entries[j].title) == 0 &&
                    strcmp(entries[i].type, entries[j].type) == 0 &&
                    entries[i].year == entries[j].year
                    ) {// print true
                printf("There is a duplicate of:  \n");
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
void UWE_Harvard(struct Data *entries , int entryNumbers ) { // function to display a UWE Harvard reference for a given publication
    for (int i = 0; i < entryNumbers; i++) {
        printf("- %s. (%d) %s[online].%d. vol %d. %s. Available from: %s \n", entries[i].author, entries[i].year,
               entries[i].title, entries[i].issue, entries[i].vol, entries[i].publisher, entries[i].url);
    }// Author surname, initials. (Year of publication) Title [online]. Edition (if not first edition). Place of publication: Publisher. [Accessed DD Month YYYY].
    // if info missing replace with Anon
}
void add_bibliography(struct Data *entries , int *entryNumber ) // function that allows the user to add a bibliography//send by ref , send by value
{   *entryNumber++; // not complete
    printf("Enter type \n");
    scanf("%s",entries[*entryNumber].type);

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
