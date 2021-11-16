/*
** OnsagerHe PROJECT, 2021
** Project
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/link_list.h"

int main(void)
{
    class_t *This __attribute__((__cleanup__(Free))) = CreateList();

    (*This).PushBegin(This, 1);
    (*This).PushBegin(This, 2);
    //(*This).PopBegin(This);
    (*This).Print(This);
    (*This).Length(This);
    printf("--------------\n");
    (*This).PopEnd(This);
    (*This).PushEnd(This, 5);
    (*This).PushEnd(This, 4);
    (*This).PushEnd(This, 3);
    (*This).Print(This);
    (*This).Free(This);
    return 0x00;
}