/* This C header file is generated by NIT to compile modules and programs that requires ../lib/standard/collection/hash_collection. */
#ifndef standard___collection___hash_collection_sep
#define standard___collection___hash_collection_sep
#include "standard___collection___array._sep.h"
#include "standard___hash._sep.h"
#include <nit_common.h>

extern const classtable_elt_t VFT_standard___collection___hash_collection___HashCollection[];

extern const classtable_elt_t VFT_standard___collection___hash_collection___HashNode[];

extern const classtable_elt_t VFT_standard___collection___hash_collection___HashMap[];

extern const classtable_elt_t VFT_standard___collection___hash_collection___HashMapKeys[];

extern const classtable_elt_t VFT_standard___collection___hash_collection___HashMapValues[];

extern const classtable_elt_t VFT_standard___collection___hash_collection___HashMapNode[];

extern const classtable_elt_t VFT_standard___collection___hash_collection___HashMapIterator[];

extern const classtable_elt_t VFT_standard___collection___hash_collection___HashSet[];

extern const classtable_elt_t VFT_standard___collection___hash_collection___HashSetNode[];

extern const classtable_elt_t VFT_standard___collection___hash_collection___HashSetIterator[];
extern const char LOCATE_standard___collection___hash_collection[];
extern const int SFT_standard___collection___hash_collection[];
#define ID_standard___collection___hash_collection___HashCollection (SFT_standard___collection___hash_collection[0])
#define COLOR_standard___collection___hash_collection___HashCollection (SFT_standard___collection___hash_collection[1])
#define ATTR_standard___collection___hash_collection___HashCollection____array(recv) ATTR(recv, (SFT_standard___collection___hash_collection[2] + 0))
#define ATTR_standard___collection___hash_collection___HashCollection____capacity(recv) ATTR(recv, (SFT_standard___collection___hash_collection[2] + 1))
#define ATTR_standard___collection___hash_collection___HashCollection____length(recv) ATTR(recv, (SFT_standard___collection___hash_collection[2] + 2))
#define ATTR_standard___collection___hash_collection___HashCollection____first_item(recv) ATTR(recv, (SFT_standard___collection___hash_collection[2] + 3))
#define ATTR_standard___collection___hash_collection___HashCollection____last_item(recv) ATTR(recv, (SFT_standard___collection___hash_collection[2] + 4))
#define ATTR_standard___collection___hash_collection___HashCollection____last_accessed_key(recv) ATTR(recv, (SFT_standard___collection___hash_collection[2] + 5))
#define ATTR_standard___collection___hash_collection___HashCollection____last_accessed_node(recv) ATTR(recv, (SFT_standard___collection___hash_collection[2] + 6))
#define INIT_TABLE_POS_standard___collection___hash_collection___HashCollection (SFT_standard___collection___hash_collection[3] + 0)
#define CALL_standard___collection___hash_collection___HashCollection___first_item(recv) ((standard___collection___hash_collection___HashCollection___first_item_t)CALL((recv), (SFT_standard___collection___hash_collection[3] + 1)))
#define CALL_standard___collection___hash_collection___HashCollection___index_at(recv) ((standard___collection___hash_collection___HashCollection___index_at_t)CALL((recv), (SFT_standard___collection___hash_collection[3] + 2)))
#define CALL_standard___collection___hash_collection___HashCollection___node_at(recv) ((standard___collection___hash_collection___HashCollection___node_at_t)CALL((recv), (SFT_standard___collection___hash_collection[3] + 3)))
#define CALL_standard___collection___hash_collection___HashCollection___node_at_idx(recv) ((standard___collection___hash_collection___HashCollection___node_at_idx_t)CALL((recv), (SFT_standard___collection___hash_collection[3] + 4)))
#define CALL_standard___collection___hash_collection___HashCollection___store(recv) ((standard___collection___hash_collection___HashCollection___store_t)CALL((recv), (SFT_standard___collection___hash_collection[3] + 5)))
#define CALL_standard___collection___hash_collection___HashCollection___remove_node(recv) ((standard___collection___hash_collection___HashCollection___remove_node_t)CALL((recv), (SFT_standard___collection___hash_collection[3] + 6)))
#define CALL_standard___collection___hash_collection___HashCollection___raz(recv) ((standard___collection___hash_collection___HashCollection___raz_t)CALL((recv), (SFT_standard___collection___hash_collection[3] + 7)))
#define CALL_standard___collection___hash_collection___HashCollection___enlarge(recv) ((standard___collection___hash_collection___HashCollection___enlarge_t)CALL((recv), (SFT_standard___collection___hash_collection[3] + 8)))
#define CALL_standard___collection___hash_collection___HashCollection___init(recv) ((standard___collection___hash_collection___HashCollection___init_t)CALL((recv), (SFT_standard___collection___hash_collection[3] + 9)))
#define ID_standard___collection___hash_collection___HashNode (SFT_standard___collection___hash_collection[4])
#define COLOR_standard___collection___hash_collection___HashNode (SFT_standard___collection___hash_collection[5])
#define ATTR_standard___collection___hash_collection___HashNode____key(recv) ATTR(recv, (SFT_standard___collection___hash_collection[6] + 0))
#define ATTR_standard___collection___hash_collection___HashNode____next_item(recv) ATTR(recv, (SFT_standard___collection___hash_collection[6] + 1))
#define ATTR_standard___collection___hash_collection___HashNode____prev_item(recv) ATTR(recv, (SFT_standard___collection___hash_collection[6] + 2))
#define ATTR_standard___collection___hash_collection___HashNode____prev_in_bucklet(recv) ATTR(recv, (SFT_standard___collection___hash_collection[6] + 3))
#define ATTR_standard___collection___hash_collection___HashNode____next_in_bucklet(recv) ATTR(recv, (SFT_standard___collection___hash_collection[6] + 4))
#define INIT_TABLE_POS_standard___collection___hash_collection___HashNode (SFT_standard___collection___hash_collection[7] + 0)
#define VTID_standard___collection___hash_collection___HashNode___N(recv) (VAL2VFT(recv)[SFT_standard___collection___hash_collection[7] + 1].i)
#define VTCOLOR_standard___collection___hash_collection___HashNode___N(recv) (VAL2VFT(recv)[SFT_standard___collection___hash_collection[7] + 2].i)
#define CALL_standard___collection___hash_collection___HashNode___next_item(recv) ((standard___collection___hash_collection___HashNode___next_item_t)CALL((recv), (SFT_standard___collection___hash_collection[7] + 3)))
#define CALL_standard___collection___hash_collection___HashNode___next_item__eq(recv) ((standard___collection___hash_collection___HashNode___next_item__eq_t)CALL((recv), (SFT_standard___collection___hash_collection[7] + 4)))
#define CALL_standard___collection___hash_collection___HashNode___prev_item(recv) ((standard___collection___hash_collection___HashNode___prev_item_t)CALL((recv), (SFT_standard___collection___hash_collection[7] + 5)))
#define CALL_standard___collection___hash_collection___HashNode___prev_item__eq(recv) ((standard___collection___hash_collection___HashNode___prev_item__eq_t)CALL((recv), (SFT_standard___collection___hash_collection[7] + 6)))
#define CALL_standard___collection___hash_collection___HashNode___init(recv) ((standard___collection___hash_collection___HashNode___init_t)CALL((recv), (SFT_standard___collection___hash_collection[7] + 7)))
#define ID_standard___collection___hash_collection___HashMap (SFT_standard___collection___hash_collection[8])
#define COLOR_standard___collection___hash_collection___HashMap (SFT_standard___collection___hash_collection[9])
#define ATTR_standard___collection___hash_collection___HashMap_____atkeys(recv) ATTR(recv, (SFT_standard___collection___hash_collection[10] + 0))
#define ATTR_standard___collection___hash_collection___HashMap_____atvalues(recv) ATTR(recv, (SFT_standard___collection___hash_collection[10] + 1))
#define INIT_TABLE_POS_standard___collection___hash_collection___HashMap (SFT_standard___collection___hash_collection[11] + 0)
#define CALL_standard___collection___hash_collection___HashMap___init(recv) ((standard___collection___hash_collection___HashMap___init_t)CALL((recv), (SFT_standard___collection___hash_collection[11] + 1)))
#define CALL_standard___collection___hash_collection___HashMap___keys__eq(recv) ((standard___collection___hash_collection___HashMap___keys__eq_t)CALL((recv), (SFT_standard___collection___hash_collection[11] + 2)))
#define CALL_standard___collection___hash_collection___HashMap___values__eq(recv) ((standard___collection___hash_collection___HashMap___values__eq_t)CALL((recv), (SFT_standard___collection___hash_collection[11] + 3)))
#define ID_standard___collection___hash_collection___HashMapKeys (SFT_standard___collection___hash_collection[12])
#define COLOR_standard___collection___hash_collection___HashMapKeys (SFT_standard___collection___hash_collection[13])
#define ATTR_standard___collection___hash_collection___HashMapKeys_____atmap(recv) ATTR(recv, (SFT_standard___collection___hash_collection[14] + 0))
#define INIT_TABLE_POS_standard___collection___hash_collection___HashMapKeys (SFT_standard___collection___hash_collection[15] + 0)
#define CALL_standard___collection___hash_collection___HashMapKeys___map(recv) ((standard___collection___hash_collection___HashMapKeys___map_t)CALL((recv), (SFT_standard___collection___hash_collection[15] + 1)))
#define CALL_standard___collection___hash_collection___HashMapKeys___map__eq(recv) ((standard___collection___hash_collection___HashMapKeys___map__eq_t)CALL((recv), (SFT_standard___collection___hash_collection[15] + 2)))
#define CALL_standard___collection___hash_collection___HashMapKeys___init(recv) ((standard___collection___hash_collection___HashMapKeys___init_t)CALL((recv), (SFT_standard___collection___hash_collection[15] + 3)))
#define ID_standard___collection___hash_collection___HashMapValues (SFT_standard___collection___hash_collection[16])
#define COLOR_standard___collection___hash_collection___HashMapValues (SFT_standard___collection___hash_collection[17])
#define ATTR_standard___collection___hash_collection___HashMapValues_____atmap(recv) ATTR(recv, (SFT_standard___collection___hash_collection[18] + 0))
#define INIT_TABLE_POS_standard___collection___hash_collection___HashMapValues (SFT_standard___collection___hash_collection[19] + 0)
#define CALL_standard___collection___hash_collection___HashMapValues___map(recv) ((standard___collection___hash_collection___HashMapValues___map_t)CALL((recv), (SFT_standard___collection___hash_collection[19] + 1)))
#define CALL_standard___collection___hash_collection___HashMapValues___map__eq(recv) ((standard___collection___hash_collection___HashMapValues___map__eq_t)CALL((recv), (SFT_standard___collection___hash_collection[19] + 2)))
#define CALL_standard___collection___hash_collection___HashMapValues___init(recv) ((standard___collection___hash_collection___HashMapValues___init_t)CALL((recv), (SFT_standard___collection___hash_collection[19] + 3)))
#define ID_standard___collection___hash_collection___HashMapNode (SFT_standard___collection___hash_collection[20])
#define COLOR_standard___collection___hash_collection___HashMapNode (SFT_standard___collection___hash_collection[21])
#define ATTR_standard___collection___hash_collection___HashMapNode____value(recv) ATTR(recv, (SFT_standard___collection___hash_collection[22] + 0))
#define INIT_TABLE_POS_standard___collection___hash_collection___HashMapNode (SFT_standard___collection___hash_collection[23] + 0)
#define CALL_standard___collection___hash_collection___HashMapNode___init(recv) ((standard___collection___hash_collection___HashMapNode___init_t)CALL((recv), (SFT_standard___collection___hash_collection[23] + 1)))
#define ID_standard___collection___hash_collection___HashMapIterator (SFT_standard___collection___hash_collection[24])
#define COLOR_standard___collection___hash_collection___HashMapIterator (SFT_standard___collection___hash_collection[25])
#define ATTR_standard___collection___hash_collection___HashMapIterator____map(recv) ATTR(recv, (SFT_standard___collection___hash_collection[26] + 0))
#define ATTR_standard___collection___hash_collection___HashMapIterator____node(recv) ATTR(recv, (SFT_standard___collection___hash_collection[26] + 1))
#define INIT_TABLE_POS_standard___collection___hash_collection___HashMapIterator (SFT_standard___collection___hash_collection[27] + 0)
#define CALL_standard___collection___hash_collection___HashMapIterator___init(recv) ((standard___collection___hash_collection___HashMapIterator___init_t)CALL((recv), (SFT_standard___collection___hash_collection[27] + 1)))
#define ID_standard___collection___hash_collection___HashSet (SFT_standard___collection___hash_collection[28])
#define COLOR_standard___collection___hash_collection___HashSet (SFT_standard___collection___hash_collection[29])
#define INIT_TABLE_POS_standard___collection___hash_collection___HashSet (SFT_standard___collection___hash_collection[30] + 0)
#define CALL_standard___collection___hash_collection___HashSet___init(recv) ((standard___collection___hash_collection___HashSet___init_t)CALL((recv), (SFT_standard___collection___hash_collection[30] + 1)))
#define ID_standard___collection___hash_collection___HashSetNode (SFT_standard___collection___hash_collection[31])
#define COLOR_standard___collection___hash_collection___HashSetNode (SFT_standard___collection___hash_collection[32])
#define INIT_TABLE_POS_standard___collection___hash_collection___HashSetNode (SFT_standard___collection___hash_collection[33] + 0)
#define CALL_standard___collection___hash_collection___HashSetNode___init(recv) ((standard___collection___hash_collection___HashSetNode___init_t)CALL((recv), (SFT_standard___collection___hash_collection[33] + 1)))
#define ID_standard___collection___hash_collection___HashSetIterator (SFT_standard___collection___hash_collection[34])
#define COLOR_standard___collection___hash_collection___HashSetIterator (SFT_standard___collection___hash_collection[35])
#define ATTR_standard___collection___hash_collection___HashSetIterator____set(recv) ATTR(recv, (SFT_standard___collection___hash_collection[36] + 0))
#define ATTR_standard___collection___hash_collection___HashSetIterator____node(recv) ATTR(recv, (SFT_standard___collection___hash_collection[36] + 1))
#define INIT_TABLE_POS_standard___collection___hash_collection___HashSetIterator (SFT_standard___collection___hash_collection[37] + 0)
#define CALL_standard___collection___hash_collection___HashSetIterator___init(recv) ((standard___collection___hash_collection___HashSetIterator___init_t)CALL((recv), (SFT_standard___collection___hash_collection[37] + 1)))
val_t standard___collection___hash_collection___HashCollection___first_item(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashCollection___first_item_t)(val_t p0);
val_t standard___collection___hash_collection___HashCollection___index_at(val_t p0, val_t p1);
typedef val_t (*standard___collection___hash_collection___HashCollection___index_at_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashCollection___node_at(val_t p0, val_t p1);
typedef val_t (*standard___collection___hash_collection___HashCollection___node_at_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashCollection___node_at_idx(val_t p0, val_t p1, val_t p2);
typedef val_t (*standard___collection___hash_collection___HashCollection___node_at_idx_t)(val_t p0, val_t p1, val_t p2);
void standard___collection___hash_collection___HashCollection___store(val_t p0, val_t p1, val_t p2);
typedef void (*standard___collection___hash_collection___HashCollection___store_t)(val_t p0, val_t p1, val_t p2);
void standard___collection___hash_collection___HashCollection___remove_node(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashCollection___remove_node_t)(val_t p0, val_t p1);
void standard___collection___hash_collection___HashCollection___raz(val_t p0);
typedef void (*standard___collection___hash_collection___HashCollection___raz_t)(val_t p0);
void standard___collection___hash_collection___HashCollection___enlarge(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashCollection___enlarge_t)(val_t p0, val_t p1);
void standard___collection___hash_collection___HashCollection___init(val_t p0, int* init_table);
typedef void (*standard___collection___hash_collection___HashCollection___init_t)(val_t p0, int* init_table);
val_t NEW_HashCollection_standard___collection___hash_collection___HashCollection___init();
val_t standard___collection___hash_collection___HashNode___next_item(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashNode___next_item_t)(val_t p0);
void standard___collection___hash_collection___HashNode___next_item__eq(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashNode___next_item__eq_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashNode___prev_item(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashNode___prev_item_t)(val_t p0);
void standard___collection___hash_collection___HashNode___prev_item__eq(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashNode___prev_item__eq_t)(val_t p0, val_t p1);
void standard___collection___hash_collection___HashNode___init(val_t p0, val_t p1, int* init_table);
typedef void (*standard___collection___hash_collection___HashNode___init_t)(val_t p0, val_t p1, int* init_table);
val_t NEW_HashNode_standard___collection___hash_collection___HashNode___init(val_t p0);
val_t standard___collection___hash_collection___HashMap_____bra(val_t p0, val_t p1);
typedef val_t (*standard___collection___hash_collection___HashMap_____bra_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashMap___iterator(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMap___iterator_t)(val_t p0);
typedef void (*CLOS_standard___collection___hash_collection___HashMap___iterate_0)(struct stack_frame_t *, val_t, val_t);
void standard___collection___hash_collection___HashMap___iterate(val_t p0, struct stack_frame_t *closctx_param, fun_t clos_fun0);
typedef void (*standard___collection___hash_collection___HashMap___iterate_t)(val_t p0, struct stack_frame_t *closctx_param, fun_t clos_fun0);
val_t standard___collection___hash_collection___HashMap___length(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMap___length_t)(val_t p0);
val_t standard___collection___hash_collection___HashMap___is_empty(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMap___is_empty_t)(val_t p0);
void standard___collection___hash_collection___HashMap_____braeq(val_t p0, val_t p1, val_t p2);
typedef void (*standard___collection___hash_collection___HashMap_____braeq_t)(val_t p0, val_t p1, val_t p2);
void standard___collection___hash_collection___HashMap___clear(val_t p0);
typedef void (*standard___collection___hash_collection___HashMap___clear_t)(val_t p0);
void standard___collection___hash_collection___HashMap___init(val_t p0, int* init_table);
typedef void (*standard___collection___hash_collection___HashMap___init_t)(val_t p0, int* init_table);
val_t NEW_HashMap_standard___collection___hash_collection___HashMap___init();
val_t standard___collection___hash_collection___HashMap___keys(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMap___keys_t)(val_t p0);
void standard___collection___hash_collection___HashMap___keys__eq(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashMap___keys__eq_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashMap___values(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMap___values_t)(val_t p0);
void standard___collection___hash_collection___HashMap___values__eq(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashMap___values__eq_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashMapKeys___map(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapKeys___map_t)(val_t p0);
void standard___collection___hash_collection___HashMapKeys___map__eq(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashMapKeys___map__eq_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashMapKeys___count(val_t p0, val_t p1);
typedef val_t (*standard___collection___hash_collection___HashMapKeys___count_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashMapKeys___first(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapKeys___first_t)(val_t p0);
val_t standard___collection___hash_collection___HashMapKeys___has(val_t p0, val_t p1);
typedef val_t (*standard___collection___hash_collection___HashMapKeys___has_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashMapKeys___has_only(val_t p0, val_t p1);
typedef val_t (*standard___collection___hash_collection___HashMapKeys___has_only_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashMapKeys___is_empty(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapKeys___is_empty_t)(val_t p0);
val_t standard___collection___hash_collection___HashMapKeys___length(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapKeys___length_t)(val_t p0);
val_t standard___collection___hash_collection___HashMapKeys___iterator(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapKeys___iterator_t)(val_t p0);
void standard___collection___hash_collection___HashMapKeys___clear(val_t p0);
typedef void (*standard___collection___hash_collection___HashMapKeys___clear_t)(val_t p0);
void standard___collection___hash_collection___HashMapKeys___remove(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashMapKeys___remove_t)(val_t p0, val_t p1);
void standard___collection___hash_collection___HashMapKeys___remove_all(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashMapKeys___remove_all_t)(val_t p0, val_t p1);
void standard___collection___hash_collection___HashMapKeys___init(val_t p0, val_t p1, int* init_table);
typedef void (*standard___collection___hash_collection___HashMapKeys___init_t)(val_t p0, val_t p1, int* init_table);
val_t NEW_HashMapKeys_standard___collection___hash_collection___HashMapKeys___init(val_t p0);
val_t standard___collection___hash_collection___HashMapValues___map(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapValues___map_t)(val_t p0);
void standard___collection___hash_collection___HashMapValues___map__eq(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashMapValues___map__eq_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashMapValues___count(val_t p0, val_t p1);
typedef val_t (*standard___collection___hash_collection___HashMapValues___count_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashMapValues___first(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapValues___first_t)(val_t p0);
val_t standard___collection___hash_collection___HashMapValues___has(val_t p0, val_t p1);
typedef val_t (*standard___collection___hash_collection___HashMapValues___has_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashMapValues___has_only(val_t p0, val_t p1);
typedef val_t (*standard___collection___hash_collection___HashMapValues___has_only_t)(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashMapValues___is_empty(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapValues___is_empty_t)(val_t p0);
val_t standard___collection___hash_collection___HashMapValues___length(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapValues___length_t)(val_t p0);
val_t standard___collection___hash_collection___HashMapValues___iterator(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapValues___iterator_t)(val_t p0);
void standard___collection___hash_collection___HashMapValues___clear(val_t p0);
typedef void (*standard___collection___hash_collection___HashMapValues___clear_t)(val_t p0);
void standard___collection___hash_collection___HashMapValues___remove(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashMapValues___remove_t)(val_t p0, val_t p1);
void standard___collection___hash_collection___HashMapValues___remove_all(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashMapValues___remove_all_t)(val_t p0, val_t p1);
void standard___collection___hash_collection___HashMapValues___init(val_t p0, val_t p1, int* init_table);
typedef void (*standard___collection___hash_collection___HashMapValues___init_t)(val_t p0, val_t p1, int* init_table);
val_t NEW_HashMapValues_standard___collection___hash_collection___HashMapValues___init(val_t p0);
void standard___collection___hash_collection___HashMapNode___init(val_t p0, val_t p1, val_t p2, int* init_table);
typedef void (*standard___collection___hash_collection___HashMapNode___init_t)(val_t p0, val_t p1, val_t p2, int* init_table);
val_t NEW_HashMapNode_standard___collection___hash_collection___HashMapNode___init(val_t p0, val_t p1);
val_t standard___collection___hash_collection___HashMapIterator___is_ok(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapIterator___is_ok_t)(val_t p0);
val_t standard___collection___hash_collection___HashMapIterator___item(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapIterator___item_t)(val_t p0);
val_t standard___collection___hash_collection___HashMapIterator___key(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashMapIterator___key_t)(val_t p0);
void standard___collection___hash_collection___HashMapIterator___next(val_t p0);
typedef void (*standard___collection___hash_collection___HashMapIterator___next_t)(val_t p0);
void standard___collection___hash_collection___HashMapIterator___init(val_t p0, val_t p1, int* init_table);
typedef void (*standard___collection___hash_collection___HashMapIterator___init_t)(val_t p0, val_t p1, int* init_table);
val_t NEW_HashMapIterator_standard___collection___hash_collection___HashMapIterator___init(val_t p0);
val_t standard___collection___hash_collection___HashSet___length(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashSet___length_t)(val_t p0);
val_t standard___collection___hash_collection___HashSet___is_empty(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashSet___is_empty_t)(val_t p0);
val_t standard___collection___hash_collection___HashSet___first(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashSet___first_t)(val_t p0);
val_t standard___collection___hash_collection___HashSet___has(val_t p0, val_t p1);
typedef val_t (*standard___collection___hash_collection___HashSet___has_t)(val_t p0, val_t p1);
void standard___collection___hash_collection___HashSet___add(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashSet___add_t)(val_t p0, val_t p1);
void standard___collection___hash_collection___HashSet___remove(val_t p0, val_t p1);
typedef void (*standard___collection___hash_collection___HashSet___remove_t)(val_t p0, val_t p1);
void standard___collection___hash_collection___HashSet___clear(val_t p0);
typedef void (*standard___collection___hash_collection___HashSet___clear_t)(val_t p0);
val_t standard___collection___hash_collection___HashSet___iterator(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashSet___iterator_t)(val_t p0);
void standard___collection___hash_collection___HashSet___init(val_t p0, int* init_table);
typedef void (*standard___collection___hash_collection___HashSet___init_t)(val_t p0, int* init_table);
val_t NEW_HashSet_standard___collection___hash_collection___HashSet___init();
void standard___collection___hash_collection___HashSetNode___init(val_t p0, val_t p1, int* init_table);
typedef void (*standard___collection___hash_collection___HashSetNode___init_t)(val_t p0, val_t p1, int* init_table);
val_t NEW_HashSetNode_standard___collection___hash_collection___HashSetNode___init(val_t p0);
val_t standard___collection___hash_collection___HashSetIterator___is_ok(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashSetIterator___is_ok_t)(val_t p0);
val_t standard___collection___hash_collection___HashSetIterator___item(val_t p0);
typedef val_t (*standard___collection___hash_collection___HashSetIterator___item_t)(val_t p0);
void standard___collection___hash_collection___HashSetIterator___next(val_t p0);
typedef void (*standard___collection___hash_collection___HashSetIterator___next_t)(val_t p0);
void standard___collection___hash_collection___HashSetIterator___init(val_t p0, val_t p1, int* init_table);
typedef void (*standard___collection___hash_collection___HashSetIterator___init_t)(val_t p0, val_t p1, int* init_table);
val_t NEW_HashSetIterator_standard___collection___hash_collection___HashSetIterator___init(val_t p0);
#endif
