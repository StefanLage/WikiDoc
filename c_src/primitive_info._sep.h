/* This C header file is generated by NIT to compile modules and programs that requires ./primitive_info. */
#ifndef primitive_info_sep
#define primitive_info_sep
#include "metamodel._sep.h"
#include <nit_common.h>

extern const classtable_elt_t VFT_primitive_info___PrimitiveInfo[];
extern const char LOCATE_primitive_info[];
extern const int SFT_primitive_info[];
#define ATTR_primitive_info___MMLocalClass____primitive_info_cache(recv) ATTR(recv, (SFT_primitive_info[0] + 0))
#define ATTR_primitive_info___MMLocalClass____primitive_info_b(recv) ATTR(recv, (SFT_primitive_info[0] + 1))
#define CALL_primitive_info___MMLocalClass___extern_c_type(recv) ((primitive_info___MMLocalClass___extern_c_type_t)CALL((recv), (SFT_primitive_info[1] + 0)))
#define CALL_primitive_info___MMLocalClass___primitive_info(recv) ((primitive_info___MMLocalClass___primitive_info_t)CALL((recv), (SFT_primitive_info[1] + 1)))
#define CALL_primitive_info___MMLocalClass___primitive_ctypes(recv) ((primitive_info___MMLocalClass___primitive_ctypes_t)CALL((recv), (SFT_primitive_info[1] + 2)))
#define ID_primitive_info___PrimitiveInfo (SFT_primitive_info[2])
#define COLOR_primitive_info___PrimitiveInfo (SFT_primitive_info[3])
#define ATTR_primitive_info___PrimitiveInfo____name(recv) ATTR(recv, (SFT_primitive_info[4] + 0))
#define ATTR_primitive_info___PrimitiveInfo____tagged(recv) ATTR(recv, (SFT_primitive_info[4] + 1))
#define ATTR_primitive_info___PrimitiveInfo____cname(recv) ATTR(recv, (SFT_primitive_info[4] + 2))
#define INIT_TABLE_POS_primitive_info___PrimitiveInfo (SFT_primitive_info[5] + 0)
#define CALL_primitive_info___PrimitiveInfo___name(recv) ((primitive_info___PrimitiveInfo___name_t)CALL((recv), (SFT_primitive_info[5] + 1)))
#define CALL_primitive_info___PrimitiveInfo___tagged(recv) ((primitive_info___PrimitiveInfo___tagged_t)CALL((recv), (SFT_primitive_info[5] + 2)))
#define CALL_primitive_info___PrimitiveInfo___cname(recv) ((primitive_info___PrimitiveInfo___cname_t)CALL((recv), (SFT_primitive_info[5] + 3)))
#define CALL_primitive_info___PrimitiveInfo___init(recv) ((primitive_info___PrimitiveInfo___init_t)CALL((recv), (SFT_primitive_info[5] + 4)))
#define CALL_primitive_info___MMType___cname(recv) ((primitive_info___MMType___cname_t)CALL((recv), (SFT_primitive_info[6] + 0)))
#define CALL_primitive_info___MMType___is_tagged(recv) ((primitive_info___MMType___is_tagged_t)CALL((recv), (SFT_primitive_info[6] + 1)))
#define CALL_primitive_info___MMType___default_cvalue(recv) ((primitive_info___MMType___default_cvalue_t)CALL((recv), (SFT_primitive_info[6] + 2)))
#define CALL_primitive_info___MMType___boxtype(recv) ((primitive_info___MMType___boxtype_t)CALL((recv), (SFT_primitive_info[6] + 3)))
#define CALL_primitive_info___MMType___unboxtype(recv) ((primitive_info___MMType___unboxtype_t)CALL((recv), (SFT_primitive_info[6] + 4)))
#define CALL_primitive_info___MMMethod___default_extern_name(recv) ((primitive_info___MMMethod___default_extern_name_t)CALL((recv), (SFT_primitive_info[7] + 0)))
#define CALL_primitive_info___MMMethod___friendly_extern_name(recv) ((primitive_info___MMMethod___friendly_extern_name_t)CALL((recv), (SFT_primitive_info[7] + 1)))
val_t primitive_info___MMLocalClass___extern_c_type(val_t p0);
typedef val_t (*primitive_info___MMLocalClass___extern_c_type_t)(val_t p0);
val_t primitive_info___MMLocalClass___primitive_info(val_t p0);
typedef val_t (*primitive_info___MMLocalClass___primitive_info_t)(val_t p0);
val_t primitive_info___MMLocalClass___primitive_ctypes(val_t p0);
typedef val_t (*primitive_info___MMLocalClass___primitive_ctypes_t)(val_t p0);
val_t NEW_MMLocalClass_metamodel___abstractmetamodel___MMLocalClass___init(val_t p0, val_t p1, val_t p2);
val_t primitive_info___PrimitiveInfo___name(val_t p0);
typedef val_t (*primitive_info___PrimitiveInfo___name_t)(val_t p0);
val_t primitive_info___PrimitiveInfo___tagged(val_t p0);
typedef val_t (*primitive_info___PrimitiveInfo___tagged_t)(val_t p0);
val_t primitive_info___PrimitiveInfo___cname(val_t p0);
typedef val_t (*primitive_info___PrimitiveInfo___cname_t)(val_t p0);
void primitive_info___PrimitiveInfo___init(val_t p0, val_t p1, val_t p2, val_t p3, int* init_table);
typedef void (*primitive_info___PrimitiveInfo___init_t)(val_t p0, val_t p1, val_t p2, val_t p3, int* init_table);
val_t NEW_PrimitiveInfo_primitive_info___PrimitiveInfo___init(val_t p0, val_t p1, val_t p2);
val_t primitive_info___MMType___cname(val_t p0);
typedef val_t (*primitive_info___MMType___cname_t)(val_t p0);
val_t primitive_info___MMType___is_tagged(val_t p0);
typedef val_t (*primitive_info___MMType___is_tagged_t)(val_t p0);
val_t primitive_info___MMType___default_cvalue(val_t p0);
typedef val_t (*primitive_info___MMType___default_cvalue_t)(val_t p0);
val_t primitive_info___MMType___boxtype(val_t p0, val_t p1);
typedef val_t (*primitive_info___MMType___boxtype_t)(val_t p0, val_t p1);
val_t primitive_info___MMType___unboxtype(val_t p0, val_t p1);
typedef val_t (*primitive_info___MMType___unboxtype_t)(val_t p0, val_t p1);
val_t NEW_MMType_metamodel___static_type___MMType___init();
val_t primitive_info___MMMethod___default_extern_name(val_t p0);
typedef val_t (*primitive_info___MMMethod___default_extern_name_t)(val_t p0);
val_t primitive_info___MMMethod___friendly_extern_name(val_t p0, val_t p1);
typedef val_t (*primitive_info___MMMethod___friendly_extern_name_t)(val_t p0, val_t p1);
val_t NEW_MMMethod_metamodel___abstractmetamodel___MMLocalProperty___init(val_t p0, val_t p1);
#endif
