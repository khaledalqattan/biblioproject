// Created by K AlQattan on 7/9/2025.
#ifndef BIBLIOPROJECT_MAIN_H
#define BIBLIOPROJECT_MAIN_H

struct Data { // structure for entries
    char title [100];
    char type [100];
    char author [100];
    int year;
    char issue[100];
    char publisher [100];
    char url [100];
    int vol;
};
int read_menu(); // function to read the menu.txt file
void by_Author_name(struct Data *entries , char *name, int entryNumbers ); // function to search by author name
void by_title(struct Data *entries ,char *title, int entryNumbers ); // function to search by title
void Display_publications(struct Data *entries ,int entryNumbers ); // function to display publications
void authors_names_list(struct Data *entries, int entryNumbers ); // function to list authors by name
void duplicate_detector(struct Data *entries , int entriesNumbers ); // function to display duplicates
void UWE_Harvard(struct Data *entries , int entriesNumbers ); // function to display a UWE Harvard reference for a given publication
void missing_info(struct Data *entries, int entriesNumbers ); // function to display missing information from a given publication
void add_bibliography(struct Data *entries ,int *entriesNumbers ); // function that allows the user to add a bibliography
int read_bibliography(struct Data *entries ); // function to read entries in the given bibliography
void by_Single_year(struct Data *entries, int signYear); // function to search by year of publication
void by_Range_years(struct Data *entries ,int start , int end); // function to search by a range of years
void clean_value(char *value);// function to clean up the syntax in bibliofile.txt

#endif
