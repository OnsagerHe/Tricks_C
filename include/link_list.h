/*
** PERSONAL PROJECT; 2021
** Authors: Albert VALENTIN
** Project Folder: Project
** File description:
** link_list.h
*/


#ifndef POO_LINK_LIST_H
#define POO_LINK_LIST_H

typedef struct list_s {
    void *value;
    struct list_s *next;
} list_t;

typedef struct class_s {
    int (*PushEnd)(struct class_s *, void *);
    int (*PushBegin)(struct class_s *, void *);
    void *(*PopBegin)(struct class_s *);
    void *(*PopEnd)(struct class_s *);
    int (*Print)(struct class_s *);
    int (*Length)(struct class_s *);
    int (*Free)(struct class_s *);

    int length;
    list_t *begin;
} class_t;

class_t *CreateList(void);
int InitList(class_t *);

int PushToBeginList(class_t *This, void *NewValue);
int PushToEndList(class_t *This, void *NewValue);
void *PopBeginList(class_t *This);
void *PopEndList(class_t *This);
int PrintList(class_t *This);
int GetLength(class_t *This);
int FreeList(class_t *This);

int Free(void *type);

#endif //POO_LINK_LIST_H