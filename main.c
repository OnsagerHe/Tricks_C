/*
** PERSONAL PROJECT; 2021
** Authors: Albert VALENTIN
** Project Folder: Project
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/special_number.h"
#include "./include/link_list.h"

int start(void)
{
    class_t *This __attribute__((__cleanup__(Free))) = CreateList();

    (*This).PushBegin(This, (void *)1);
    (*This).PushBegin(This, (void *)2);
    (*This).PopEnd(This);
    (*This).Print(This);
    (*This).Length(This);
    printf("--------------\n");
    (*This).PushEnd(This, (void *)special_number());
    (*This).PushEnd(This, (void *)4);
    (*This).PushEnd(This, (void *)3);
    (*This).Print(This);
    (*This).Free(This);
    return 0x00;
}