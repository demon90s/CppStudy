/* Determines air mileage from New York to other cities */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct city_info {
    char *city;
    int miles;
};

int compare_city(const void *key_ptr, const void *element_ptr);

int main()
{
    char city_name[80];
    struct city_info *ptr;
    const struct city_info mileage[] = {
        {"Acapulco", 2260}, {"Amsterdam", 3639},
        {"Antigua", 1783}, {"Aruba", 1963}
    };

    printf("Enter city name: ");
    scanf("%80[^\n]", city_name);
    ptr = bsearch(city_name, mileage, sizeof(mileage)/sizeof(mileage[0]), sizeof(mileage[0]), compare_city);
    if (ptr != NULL)
        printf("%s is %d miles from New York City.\n", city_name, ptr->miles);
    else
        printf("%s wasn't found.\n", city_name);

    return 0;
}

int compare_city(const void *key_ptr, const void *element_ptr)
{
    return strcmp((char*)key_ptr, ((struct city_info*)element_ptr)->city);
}