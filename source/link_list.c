/*
** PERSONAL PROJECT; 2021
** Authors: Albert VALENTIN
** Project Folder: Project
** File description:
** link_list.c
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/link_list.h"

class_t *CreateList(void)
{
    class_t *This = malloc(sizeof(class_t));

    if (This == NULL)
        return NULL;

    InitList(This);

    return This;
}

int InitList(class_t *This)
{
    (*This).begin = NULL;
    (*This).Free = FreeList;
    (*This).PushBegin = PushToBeginList;
    (*This).PushEnd = PushToEndList;
    (*This).PopBegin = PopBeginList;
    (*This).PopEnd = PopEndList;
    (*This).Print = PrintList;
    (*This).Length = GetLength;
    (*This).length = 0;

    return EXIT_SUCCESS;
}

int PrintList(class_t *This)
{
    list_t *tmp = (*This).begin;

    while(tmp) {
        printf("%p\n", (*tmp).value);
        tmp = (*tmp).next;
    }

    return EXIT_SUCCESS;
}

int PushToBeginList(class_t *This, void *NewValue)
{
    list_t *new_node = malloc(sizeof(list_t));

    if(!new_node)
        return EXIT_FAILURE;

    (*new_node).value = NewValue;
    (*new_node).next = (*This).begin;
    (*This).begin = new_node;
    (*This).length = (*This).length + 1;

    return EXIT_SUCCESS;
}

int PushToEndList(class_t *This, void *NewValue)
{
    list_t *NewNode = (*This).begin;

    while ((*NewNode).next != NULL) {
        NewNode = (*NewNode).next;
    }

    (*NewNode).next = malloc(sizeof(list_t));
    (*(*NewNode).next).value = NewValue;
    (*(*NewNode).next).next = NULL;
    (*This).length = (*This).length + 1;

    return 0;
}

int FreeList(class_t *This)
{
    list_t *tmp = {0};

    while((*This).begin) {
        tmp = (*(*This).begin).next;
        free((*This).begin);
        (*This).begin = tmp;
    }

    (*This).length = 0;

    return 0;
}

int Free(void *type)
{
    free(*(void **)type);

    return 0;
}

void *PopBeginList(class_t *This)
{
    void *return_value = 0;
    list_t *next_node = NULL;

    if ((*This).begin == NULL) {
        return (void *)EXIT_FAILURE;
    }

    next_node = (*(*This).begin).next;
    return_value = (*(*This).begin).value;
    free((*This).begin);
    (*This).begin = next_node;
    (*This).length = (*This).length - 1;

    return return_value;
}

void *PopEndList(class_t *This)
{
    void *return_value = 0;
    list_t *new_list = (*This).begin;

    if ((*(*This).begin).next == NULL) {
        return_value = (*new_list).value;
        free((*This).begin);
        return return_value;
    }

    while ((*(*new_list).next).next != NULL) {
        new_list = (*new_list).next;
    }

    return_value = (*(*new_list).next).value;
    free((*new_list).next);
    (*new_list).next = NULL;
    (*This).length = (*This).length - 1;

    return return_value;
}

int GetLength(class_t *This)
{
    return (*This).length;
}