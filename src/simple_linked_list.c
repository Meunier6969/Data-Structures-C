#include <stdio.h>
#include <stdlib.h>

#include "../headers/simple_linked_list.h"

sll_cell *SLL_createCell(int value)
{
    sll_cell *cell = malloc(sizeof(sll_cell));

    cell->val = value;
    cell->next = NULL;

    return cell;
}

sll_list SLL_createEmptyList()
{
    sll_list newList;
    newList.head = NULL;
    return newList;
}

void SLL_addCellToHead(sll_list *list, sll_cell *cell_to_add)
{
    cell_to_add->next = list->head;
    list->head = cell_to_add;
}

void SLL_addCellToTail(sll_list *list, sll_cell *cell_to_add)
{
    // Get to last cell
    sll_cell *currentCell = list->head;
    
    while (currentCell->next != NULL)
        currentCell = currentCell->next;

    currentCell->next = cell_to_add;
}

void SLL_addCellAtIndex(sll_list *list, sll_cell *cell_to_add, int index)
{
    // Check if head
    // Check if tail
    // Get to index 1 before
    // Set newCell next to currentCell next
    // Set currentCell next to newCell
}

void SLL_deleteHead(sll_list *list)
{
    if (SLL_isEmpty(*list)) 
        return;

    sll_cell *original_head = list->head;
    
    list->head = list->head->next;

    free(original_head);
}

void SLL_deleteTail(sll_list *list)
{
    if (SLL_isEmpty(*list))
        return;

    // If list has only one cell
    if (list->head->next == NULL)
    {
        free(list->head);
        list->head = NULL;
        return;
    }

    // Get to second-to-last cell
    sll_cell *currentCell = list->head;
    while (currentCell->next->next != NULL)
        currentCell = currentCell->next;

    free(currentCell->next);

    currentCell->next = NULL;
    
}

void SLL_deleteFromIndex(sll_list *list, int index)
{
    if (index <= 0)
    {
        SLL_deleteHead(list);
        return;
    }

    if (index == SLL_getSizeOfList(*list) - 1)
    {
        SLL_deleteTail(list);
        return;
    }

    if (index >= SLL_getSizeOfList(*list))
        return;

    int crawler = 0;

    sll_cell *currentCell = list->head;
    sll_cell *toDelete = NULL;

    while (crawler < index - 1)
    {
        currentCell = currentCell->next;
        crawler++;
    }

    toDelete = currentCell->next;

    currentCell->next = toDelete->next;
    free(toDelete);
}

void SLL_displayList(sll_list list)
{
    if (SLL_isEmpty(list))
    {
        printf("Empty list\n");
        return;
    }

    sll_cell *currentCell = list.head;

    do
    {
        printf("[%d]->", currentCell->val);
        currentCell = currentCell->next;
    } while (currentCell != NULL);
    
    printf("NULL\n");
}

int SLL_isEmpty(sll_list list)
{
    return (list.head == NULL);
}

int SLL_getSizeOfList(sll_list list)
{
    sll_cell *currentCell = list.head;
    int size = 0;

    while (currentCell != NULL)
    {
        currentCell = currentCell->next;
        size++;
    }

    return size;
}

int SLL_indexOfValueInList(sll_list list, int value)
{
    sll_cell *currentCell = list.head;
    int index = 0;

    while (currentCell != NULL)
    {
        if (currentCell->val == value) 
            return index;

        currentCell = currentCell->next;
        index++;
    }

    return -1;
}

sll_cell *SLL_ptrOfValue(sll_list list, int value)
{
    sll_cell *currentCell = list.head;

    while (currentCell != NULL)
    {
        if (currentCell->val == value) 
            return currentCell;

        currentCell = currentCell->next;
    }

    return NULL;  
}