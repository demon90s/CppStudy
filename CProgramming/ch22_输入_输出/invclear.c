/* Modifies a file of part records by setting the quantity on hand to zero */

#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts;

int main()
{
    FILE *fp;
    int i;

    if ((fp = fopen("invent.dat", "rb+")) == NULL) {
        fprintf(stderr, "Can't open inventory file\n");
        return 1;
    }

    num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, fp);
    for (i = 0; i < num_parts; i++) {
        inventory[i].on_hand = 0;
    }

    rewind(fp);
    fwrite(inventory, sizeof(struct part), num_parts, fp);
    fclose(fp);

    return 0;
}