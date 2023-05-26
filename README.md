# FT_MALLOC
## _All in One!_
[![C Language](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)]()

> ft_malloc provides flexible memory allocation and management
> with the ability to store all allocated pointers to be destroyed at will.

## Features

- Proper allocation and disposal of memory when needed.
- Calculation and display of memory reserved.
- Implemented with proper memory management etiquette.
- Ability to destroy a single or all pointers allocated by ft_malloc.
- Coded with 42's norminette in mind for it to be used by students.


## Function Prototype
```c
void		*ft_malloc(unsigned int size, void *free_ptr, int type, uint32_t *t_size);
```

## Guide
***Warning:***
    Make sure to change the name of the author and email in 42's Header.

ft_malloc relies on a list of types to achieve different goals.

- [ALLOC] - This type allows ft_malloc to allocate memory for a single pointer returns it
and stores it in a linked list.
```c
    USAGE: char *ptr = ft_malloc(42, NULL, ALLOC, NULL);
```
- [FREE] - Frees the free_ptr pointer and destroys the node associated with it.
```c
    USAGE: ft_malloc(0, ptr, FREE, NULL);
```
- [FREE_ALL] - Frees and nullifies all pointers allocated by ft_malloc.
```c
    USAGE: ft_malloc(0, NULL, FREE_ALL, NULL);
```
- [T_SIZE] - Displays the current size of all bytes allocated by ft_malloc.
```
    USAGE: 
        unsigned int size = 0;
        ft_malloc(0, NULL, T_SIZE, &size);
```

Please note that ft_malloc will not count any pointers allocated by other functions (malloc(), calloc() or any memory allocation functions).
Also it will malfunction if you use free(), instead of the builtin [FREE] type that this library has.

## Mechanism of Action

* ft_malloc relies heavily on the static linked list inside it to function, each time you allocate using ft_malloc a new node is created and points
to the newly allocated pointer for it to be later freed, Once you use the [FREE_ALL] type, all pointers held by ft_malloc will be destoryed.

## Bugs
* Since this is the first version of this library it is prone to bugs and issues.
while the initial testing was successful, there might be issues that lie within.
I'll appreciate any kind of feedback at my discord account ***SHM#5112***


[//]: # (Comments)

   [T_SIZE]: <https://en.wikipedia.org/wiki/C_dynamic_memory_allocation#Differences_between_malloc()_and_calloc()>
   [FREE_ALL]: <https://en.wikipedia.org/wiki/C_dynamic_memory_allocation#Differences_between_malloc()_and_calloc()>
   [ALLOC]: <https://en.wikipedia.org/wiki/C_dynamic_memory_allocation>
   [FREE]: <https://en.wikipedia.org/wiki/C_dynamic_memory_allocation#Differences_between_malloc()_and_calloc()>
