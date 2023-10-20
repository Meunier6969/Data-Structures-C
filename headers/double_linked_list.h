#pragma once

#define DLL_CHAR_MAX 50

typedef struct dll_cell
{
    char* value;
    struct dll_cell *next;
    struct dll_cell *previous;
} dll_cell;

typedef struct double_linked_list
{
    dll_cell* head;
} dll_list;

dll_cell* DLL_createCell(char* text);

dll_list DLL_createEmptyList();
void DLL_printList(dll_list list);

void DLL_insertCellAtHead(dll_list* list, char* text);
void DLL_insertCellAtTail(dll_list* list, char* text);
dll_cell* DLL_searchCell(dll_list* list, char* text);
void DLL_deleteCell(dll_list* list, dll_cell* cell);

void DLL_insertCellInOrder(dll_list* list, char* text);