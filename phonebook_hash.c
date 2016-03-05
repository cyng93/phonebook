#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "phonebook_hash.h"


/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry **hashTable)
{
    /* TODO: implement */
    entry *pHead;

    pHead = hashTable[HASH(lastname)];

    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

void append(char lastName[], entry **hashTable)
{
    /* allocate memory for the new entry and put lastName */
    entry *e;
    int index;

    e = (entry *) malloc(sizeof(entry));
    strcpy(e->lastName, lastName);
    e->info = NULL;

    index = HASH(lastName);
    e->pNext = hashTable[index];
    hashTable[index] = e;
}

int hash_djb2(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % HASH_TABLE_SIZE;
}

/* This version of hash aimed to reduce overhead of hash */
int hash_26(char *str)
{
    return (int)str[0];
}
