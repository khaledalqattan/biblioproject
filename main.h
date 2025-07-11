//
// Created by K AlQattan on 7/9/2025.
//

#ifndef BIBLIOPROJECT_MAIN_H
#define BIBLIOPROJECT_MAIN_H

struct Data { // should we add the rest of entries to use later?
    char title [100];
    char type [100];
    char author [100];
    int year;
};
int read_menu(); // function to read the menu.txt file
void by_Author_name(struct Data *entries , char *autherName); // function to search by author name
void by_title(struct Data *entries ,char *title); // function to search by title
void Display_publications(struct Data *entries ); // function to display publications
void authors_names_list(struct Data *entries ); // function to list authors by name
void duplicate_detector(struct Data *entries ); // function to display duplicates
void UWE_Harvard(struct Data *entries ); // function to display a UWE Harvard reference for a given publication
void missing_info(struct Data *entries ); // function to display missing information from a given publication
void add_bibliography(struct Data *entries ); // function that allows the user to add a bibliography
void read_bibliography(struct Data *entries ); // function to read entries in the given bibliography
void by_Single_year(struct Data *entries, int signYear); // function to search by year of publication
void by_Range_years(struct Data *entries ,int start , int end); // function to search by a range of years
#endif
