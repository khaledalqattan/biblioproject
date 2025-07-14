// Created by K AlQattan on 7/9/2025.
#ifndef BIBLIOPROJECT_MAIN_H
#define BIBLIOPROJECT_MAIN_H

struct Data { // should we add the rest of entries to use later?
    char title [100];
    char type [100];
    char author [100];
    int year;
    char issue[100]; //should be int but missing_information not working
    char publisher [100];
    char url [100];
    int vol;
};
int read_menu(); // function to read the menu.txt file
void by_Author_name(struct Data *entries , char *name, int entryNumbers ); // function to search by author name
void by_title(struct Data *entries ,char *title, int entryNumbers ); // function to search by title
void Display_publications(struct Data *entries ,int entryNumbers ); // function to display publications
void authors_names_list(struct Data *entries, int entryNumbers ); // function to list authors by name
void duplicate_detector(struct Data *entries , int entriesNumber ); // function to display duplicates
void UWE_Harvard(struct Data *entries , int entriesNumber ); // function to display a UWE Harvard reference for a given publication
void missing_info(struct Data *entries ); // function to display missing information from a given publication
void add_bibliography(struct Data *entries ,int *entriesNumber ); // function that allows the user to add a bibliography
int read_bibliography(struct Data *entries ); // function to read entries in the given bibliography
void by_Single_year(struct Data *entries, int signYear); // function to search by year of publication
void by_Range_years(struct Data *entries ,int start , int end); // function to search by a range of years
// for practice
void clean_value(char *value);

#endif
