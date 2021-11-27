/*
** PERSONAL PROJECT; 2021
** Authors: Albert VALENTIN
** Project Folder: Project
** File description:
** bitshift.c
*/

#include <stdio.h>

int integer = 0;

static void bin(unsigned n)
{
    unsigned int i = 0;

    for (i = 1 << 15; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    printf("\n");
}


/*
 * This function can concat binaries of two char to int
 */
int *special_number(void)
{
    char first_part = 0b000011111;
    char second_part = 0b001010100;

    /*******************************************************
     * You can uncomment to debug program or view changement
     *******************************************************/
    bin(integer);
    //bin(first_part);
    //bin(second_part);
    integer = (first_part << 7) + second_part;
    bin(integer);

    return &integer;
}