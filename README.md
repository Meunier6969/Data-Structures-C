# Data Structures in C
This repository contains implementations in C of multiple data structures used at [EFREI](https://www.efrei.fr/).\
The implentations presented here might slightly differ from what is precisely asked at EFREI.

## ⚠️ Warning
This code is provided for educational purpose only. You should not copy anything found here word-for-word, EFREI will find you. 

## ✅ Implemented
- Simple Linked List (`int`)
- Double Linked List (`char*`)
- Stacks using array (`float`)
- Queues using array (`int`)
- Binary Trees (`int`)

## 🔜 TODO
- `BT_deleteNode`, Breadth-first visit, and rotations
- `BT_isAVL`
- Add return values for most `void` functions
- `SLL_addCellAtIndex()` in `simple_linked_list.c`

## 🆘 Notes
If you find any bugs, please feel free to let me know.\
If I don't know how to fix it and you do, please help 👍
### Known bugs that I don't know how to fix currently
- In `double_linked_list.c`, leaving `free(cell)` makes the code crash when deleting at the head or the tail.
