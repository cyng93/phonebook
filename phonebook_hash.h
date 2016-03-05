#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH_TABLE_SIZE 26
#define HASH hash_26


/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1

typedef struct __ENTRY_INFO {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} entry_info;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct entry_info *info;

    struct __PHONE_BOOK_ENTRY *pNext;
} entry;


entry *findName(char lastname[], entry **hashTable);
void append(char lastName[], entry **hashTable);
int hash_djb2(char *str);
int hash_26(char *str);


#endif
