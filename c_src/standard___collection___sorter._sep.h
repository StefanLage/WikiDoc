/* This C header file is generated by NIT to compile modules and programs that requires ../lib/standard/collection/sorter. */
#ifndef standard___collection___sorter_sep
#define standard___collection___sorter_sep
#include "standard___collection___array._sep.h"
#include <nit_common.h>

extern const classtable_elt_t VFT_standard___collection___sorter___AbstractSorter[];

extern const classtable_elt_t VFT_standard___collection___sorter___ComparableSorter[];
extern const char LOCATE_standard___collection___sorter[];
extern const int SFT_standard___collection___sorter[];
#define ID_standard___collection___sorter___AbstractSorter (SFT_standard___collection___sorter[0])
#define COLOR_standard___collection___sorter___AbstractSorter (SFT_standard___collection___sorter[1])
#define INIT_TABLE_POS_standard___collection___sorter___AbstractSorter (SFT_standard___collection___sorter[2] + 0)
#define CALL_standard___collection___sorter___AbstractSorter___compare(recv) ((standard___collection___sorter___AbstractSorter___compare_t)CALL((recv), (SFT_standard___collection___sorter[2] + 1)))
#define CALL_standard___collection___sorter___AbstractSorter___sort(recv) ((standard___collection___sorter___AbstractSorter___sort_t)CALL((recv), (SFT_standard___collection___sorter[2] + 2)))
#define CALL_standard___collection___sorter___AbstractSorter___sub_sort(recv) ((standard___collection___sorter___AbstractSorter___sub_sort_t)CALL((recv), (SFT_standard___collection___sorter[2] + 3)))
#define CALL_standard___collection___sorter___AbstractSorter___quick_sort(recv) ((standard___collection___sorter___AbstractSorter___quick_sort_t)CALL((recv), (SFT_standard___collection___sorter[2] + 4)))
#define CALL_standard___collection___sorter___AbstractSorter___bubble_sort(recv) ((standard___collection___sorter___AbstractSorter___bubble_sort_t)CALL((recv), (SFT_standard___collection___sorter[2] + 5)))
#define ID_standard___collection___sorter___ComparableSorter (SFT_standard___collection___sorter[3])
#define COLOR_standard___collection___sorter___ComparableSorter (SFT_standard___collection___sorter[4])
#define INIT_TABLE_POS_standard___collection___sorter___ComparableSorter (SFT_standard___collection___sorter[5] + 0)
#define CALL_standard___collection___sorter___ComparableSorter___init(recv) ((standard___collection___sorter___ComparableSorter___init_t)CALL((recv), (SFT_standard___collection___sorter[5] + 1)))
val_t standard___collection___sorter___AbstractSorter___compare(val_t p0, val_t p1, val_t p2);
typedef val_t (*standard___collection___sorter___AbstractSorter___compare_t)(val_t p0, val_t p1, val_t p2);
void standard___collection___sorter___AbstractSorter___sort(val_t p0, val_t p1);
typedef void (*standard___collection___sorter___AbstractSorter___sort_t)(val_t p0, val_t p1);
void standard___collection___sorter___AbstractSorter___sub_sort(val_t p0, val_t p1, val_t p2, val_t p3);
typedef void (*standard___collection___sorter___AbstractSorter___sub_sort_t)(val_t p0, val_t p1, val_t p2, val_t p3);
void standard___collection___sorter___AbstractSorter___quick_sort(val_t p0, val_t p1, val_t p2, val_t p3);
typedef void (*standard___collection___sorter___AbstractSorter___quick_sort_t)(val_t p0, val_t p1, val_t p2, val_t p3);
void standard___collection___sorter___AbstractSorter___bubble_sort(val_t p0, val_t p1, val_t p2, val_t p3);
typedef void (*standard___collection___sorter___AbstractSorter___bubble_sort_t)(val_t p0, val_t p1, val_t p2, val_t p3);
val_t standard___collection___sorter___ComparableSorter___compare(val_t p0, val_t p1, val_t p2);
typedef val_t (*standard___collection___sorter___ComparableSorter___compare_t)(val_t p0, val_t p1, val_t p2);
void standard___collection___sorter___ComparableSorter___init(val_t p0, int* init_table);
typedef void (*standard___collection___sorter___ComparableSorter___init_t)(val_t p0, int* init_table);
val_t NEW_ComparableSorter_standard___collection___sorter___ComparableSorter___init();
#endif
