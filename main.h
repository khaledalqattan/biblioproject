//
// Created by K AlQattan on 7/9/2025.
//

#ifndef BIBLIOPROJECT_MAIN_H
#define BIBLIOPROJECT_MAIN_H

struct Data {
    char title [100];
    char type [100];
    char auther [100];
    int year;
};
int read_menu(); // function to read the menu.txt file
void by_Auther_name(struct Data *entries , char *autherName); // function to search by author name
void by_title(struct Data *entries ,char *title); // function to search by title
void Display_publications(struct Data *entries ); // function to display publications
void authers_names_list(struct Data *entries ); // function to list authors by name
void dublicate_didecter(struct Data *entries ); // function to display duplicates
void UWE_Harvard(struct Data *entries ); // function to display a UWE Harvard reference for a given publication
void missing_info(struct Data *entries ); // function to display missing information from a given publication
void add_bibliography(struct Data *entries ); // function that allows the user to add a bibliography
void read_bibliography(struct Data *entries );
void by_Single_year(struct Data *entries, int signYear);
void by_Range_years(struct Data *entries ,int start , int end);
#endif //BIBLIOPROJECT_MAIN_H
