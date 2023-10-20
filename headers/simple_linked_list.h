#pragma once

typedef struct sll_cell
{
    int val;
    struct sll_cell *next;
} sll_cell;

typedef struct simple_linked_list
{
    sll_cell* head;
} sll_list;

sll_cell *SLL_createCell(int value);
sll_list SLL_createEmptyList();

void SLL_addCellToHead(sll_list *list, sll_cell *cell_to_add);
void SLL_addCellToTail(sll_list *list, sll_cell *cell_to_add);
void SLL_addCellAtIndex(sll_list *list, sll_cell *cell_to_add, int index);

void SLL_deleteHead(sll_list *list);
void SLL_deleteTail(sll_list *list);
void SLL_deleteFromIndex(sll_list *list, int index);

void SLL_displayList(sll_list list);
int SLL_isEmpty(sll_list list); 
int SLL_getSizeOfList(sll_list list);

int SLL_indexOfValueInList(sll_list list, int value);
sll_cell *SLL_ptrOfValue(sll_list list, int value);