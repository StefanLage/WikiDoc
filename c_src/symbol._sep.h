/* This C header file is generated by NIT to compile modules and programs that requires ../lib/symbol. */
#ifndef symbol_sep
#define symbol_sep
#include "standard._sep.h"
#include <nit_common.h>

extern const classtable_elt_t VFT_symbol___Symbol[];
extern const char LOCATE_symbol[];
extern const int SFT_symbol[];
#define CALL_symbol___String___to_symbol(recv) ((symbol___String___to_symbol_t)CALL((recv), (SFT_symbol[0] + 0)))
#define ID_symbol___Symbol (SFT_symbol[1])
#define COLOR_symbol___Symbol (SFT_symbol[2])
#define ATTR_symbol___Symbol____string(recv) ATTR(recv, (SFT_symbol[3] + 0))
#define INIT_TABLE_POS_symbol___Symbol (SFT_symbol[4] + 0)
#define CALL_symbol___Symbol___init(recv) ((symbol___Symbol___init_t)CALL((recv), (SFT_symbol[4] + 1)))
val_t symbol___String___to_symbol(val_t p0);
typedef val_t (*symbol___String___to_symbol_t)(val_t p0);
val_t NEW_String_standard___string___String___with_native(val_t p0, val_t p1);
val_t NEW_String_standard___string___String___from_cstring(val_t p0);
val_t symbol___Symbol___to_s(val_t p0);
typedef val_t (*symbol___Symbol___to_s_t)(val_t p0);
void symbol___Symbol___init(val_t p0, val_t p1, int* init_table);
typedef void (*symbol___Symbol___init_t)(val_t p0, val_t p1, int* init_table);
val_t NEW_Symbol_symbol___Symbol___init(val_t p0);
#endif
