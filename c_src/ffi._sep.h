/* This C header file is generated by NIT to compile modules and programs that requires ./ffi/ffi. */
#ifndef ffi_sep
#define ffi_sep
#include "ffi___c._sep.h"
#include <nit_common.h>
extern const char LOCATE_ffi[];
extern const int SFT_ffi[];
#define CALL_SUPER_ffi___MMSrcModule___compile_separate_module(recv) ((ffi___MMSrcModule___compile_separate_module_t)CALL((recv), (SFT_ffi[0] + 0)))
#define CALL_ffi___FFIVisitor___compile(recv) ((ffi___FFIVisitor___compile_t)CALL((recv), (SFT_ffi[1] + 0)))
void ffi___MMSrcModule___compile_separate_module(val_t p0, val_t p1);
typedef void (*ffi___MMSrcModule___compile_separate_module_t)(val_t p0, val_t p1);
val_t NEW_MMSrcModule_syntax___syntax_base___MMSrcModule___init(val_t p0, val_t p1, val_t p2, val_t p3, val_t p4);
val_t NEW_MMLocalClass_metamodel___abstractmetamodel___MMLocalClass___init(val_t p0, val_t p1, val_t p2);
void ffi___FFIVisitor___compile(val_t p0);
typedef void (*ffi___FFIVisitor___compile_t)(val_t p0);
val_t NEW_FFIVisitor_ffi___ffi_base___FFIVisitor___init(val_t p0, val_t p1);
#endif
