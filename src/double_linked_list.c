#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../headers/double_linked_list.h"

dll_cell* DLL_createCell(char* text)
{
    dll_cell* cell = (dll_cell*) malloc(sizeof(dll_cell*));
    cell->value = (char*) malloc(DLL_CHAR_MAX * sizeof(char));

    strcpy(cell->value, text);
    cell->next = NULL;
    cell->previous = NULL;
    
    return cell;
}

dll_list DLL_createEmptyList()
{
    dll_list list;
    list.head = NULL;
    return list;
}

void DLL_printList(dll_list list)
{
    if (list.head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    dll_cell* currentCell = list.head;

    printf("list->");
    do
    {
        printf("[%s]<->", currentCell->value);
        currentCell = currentCell->next;
    } while (currentCell != NULL);
    printf("NULL\n");

}

void DLL_insertCellAtHead(dll_list* list, char* text)
{
    dll_cell* newCell = DLL_createCell(text);

    if (list->head != NULL)
        list->head->previous = newCell;
    
    newCell->next = list->head;
    list->head = newCell;

}

void DLL_insertCellAtTail(dll_list* list, char* text)
{
    dll_cell* newCell = DLL_createCell(text);
    dll_cell* currentCell = list->head;

    if (list->head == NULL)
    {
        DLL_insertCellAtHead(list, text);
        return;
    }
    
    while (currentCell->next != NULL)
        currentCell = currentCell->next;

    currentCell->next = newCell;
    newCell->previous = currentCell;
}

dll_cell* DLL_searchCell(dll_list* list, char* text)
{
    dll_cell* currentCell = list->head;

    while (currentCell != NULL)
    {
        if (strcmp(currentCell->value, text) == 0)
            return currentCell;

        currentCell = currentCell->next;
    }
    
    return NULL;
}

void DLL_deleteCell(dll_list* list, dll_cell* cell)
{
    // no such cell
    if (cell == NULL)
        return;

    // only cell
    if (cell->previous == NULL && cell->next == NULL)
    {
        list->head = NULL;
    }
    // at head
    else if (cell->previous == NULL)
    {
        cell->next->previous = NULL;
        list->head = cell->next;
    }
    // at tail
    else if (cell->next == NULL)
    {
        cell->previous->next = NULL;
    }
    // otherwise
    else
    {
        cell->next->previous = cell->previous;
        cell->previous->next = cell->next;
    }

    // free(cell);
}

void DLL_insertCellInOrder(dll_list* list, char* text)
{
    dll_cell* currentCell = list->head;

    if (currentCell == NULL)
    {
        DLL_insertCellAtHead(list, text);
        return;
    }

    // go through the list until finding the correct place
    // can probably be better written
    do
    {
        if (strcmp(currentCell->value, text) < 0)
            break;
        
        currentCell = currentCell->next;
    } while (currentCell != NULL);

    // if first in list
    if (currentCell == list->head)
    {
        DLL_insertCellAtHead(list, text);
    }
    // if last in list
    else if (currentCell == NULL)
    {
        DLL_insertCellAtTail(list, text);
    }
    // otherwise
    else
    {
        dll_cell* newCell = DLL_createCell(text);
        newCell->next = currentCell;
        newCell->previous = currentCell->previous;
        currentCell->previous->next = newCell;
        currentCell->previous = newCell;
    }
}
