/* This C file is generated by NIT to compile module global___reachable_as_init. */
#include "global___reachable_as_init._sep.h"
static const char LOCATE_global___reachable_as_init___Program___rai[] = "reachable_as_init::Program::rai";
val_t global___reachable_as_init___Program___rai(val_t p0){
  struct {struct stack_frame_t me;} fra;
  val_t tmp;
  fra.me.prev = stack_frame_head; stack_frame_head = &fra.me;
  fra.me.file = LOCATE_global___reachable_as_init;
  fra.me.line = 24;
  fra.me.meth = LOCATE_global___reachable_as_init___Program___rai;
  fra.me.has_broke = 0;
  fra.me.REG_size = 1;
  fra.me.nitni_local_ref_head = NULL;
  fra.me.REG[0] = NIT_NULL;
  fra.me.REG[0] = p0;
  /* global/reachable_as_init.nit:24 */
  fra.me.REG[0] = ATTR_global___reachable_as_init___Program____rai(fra.me.REG[0]);
  stack_frame_head = fra.me.prev;
  return fra.me.REG[0];
}
static const char LOCATE_global___reachable_as_init___Program___rai__eq[] = "reachable_as_init::Program::rai=";
void global___reachable_as_init___Program___rai__eq(val_t p0, val_t p1){
  struct {struct stack_frame_t me; val_t MORE_REG[1];} fra;
  val_t tmp;
  fra.me.prev = stack_frame_head; stack_frame_head = &fra.me;
  fra.me.file = LOCATE_global___reachable_as_init;
  fra.me.line = 24;
  fra.me.meth = LOCATE_global___reachable_as_init___Program___rai__eq;
  fra.me.has_broke = 0;
  fra.me.REG_size = 2;
  fra.me.nitni_local_ref_head = NULL;
  fra.me.REG[0] = NIT_NULL;
  fra.me.REG[1] = NIT_NULL;
  fra.me.REG[0] = p0;
  fra.me.REG[1] = p1;
  /* global/reachable_as_init.nit:24 */
  ATTR_global___reachable_as_init___Program____rai(fra.me.REG[0]) = fra.me.REG[1];
  stack_frame_head = fra.me.prev;
  return;
}
static const char LOCATE_global___reachable_as_init___Program___dump_reachable_as_init_methods[] = "reachable_as_init::Program::dump_reachable_as_init_methods";
void global___reachable_as_init___Program___dump_reachable_as_init_methods(val_t p0, val_t p1){
  struct {struct stack_frame_t me; val_t MORE_REG[3];} fra;
  val_t REGB0;
  val_t tmp;
  static val_t once_value_1; /* Once value */
  static val_t once_value_2; /* Once value */
  static val_t once_value_3; /* Once value */
  fra.me.prev = stack_frame_head; stack_frame_head = &fra.me;
  fra.me.file = LOCATE_global___reachable_as_init;
  fra.me.line = 27;
  fra.me.meth = LOCATE_global___reachable_as_init___Program___dump_reachable_as_init_methods;
  fra.me.has_broke = 0;
  fra.me.REG_size = 4;
  fra.me.nitni_local_ref_head = NULL;
  fra.me.REG[0] = NIT_NULL;
  fra.me.REG[1] = NIT_NULL;
  fra.me.REG[2] = NIT_NULL;
  fra.me.REG[3] = NIT_NULL;
  fra.me.REG[0] = p0;
  fra.me.REG[1] = p1;
  /* global/reachable_as_init.nit:29 */
  REGB0 = TAG_Int(5);
  fra.me.REG[2] = NEW_Array_standard___collection___array___Array___with_capacity(REGB0);
  if (!once_value_1) {
    fra.me.REG[3] = BOX_NativeString("");
    REGB0 = TAG_Int(0);
    fra.me.REG[3] = NEW_String_standard___string___String___with_native(fra.me.REG[3], REGB0);
    once_value_1 = fra.me.REG[3];
    register_static_object(&once_value_1);
  } else fra.me.REG[3] = once_value_1;
  fra.me.REG[3] = fra.me.REG[3];
  CALL_standard___collection___abstract_collection___SimpleCollection___add(fra.me.REG[2])(fra.me.REG[2], fra.me.REG[3]);
  CALL_standard___collection___abstract_collection___SimpleCollection___add(fra.me.REG[2])(fra.me.REG[2], fra.me.REG[1]);
  if (!once_value_2) {
    fra.me.REG[1] = BOX_NativeString("/");
    REGB0 = TAG_Int(1);
    fra.me.REG[1] = NEW_String_standard___string___String___with_native(fra.me.REG[1], REGB0);
    once_value_2 = fra.me.REG[1];
    register_static_object(&once_value_2);
  } else fra.me.REG[1] = once_value_2;
  fra.me.REG[1] = fra.me.REG[1];
  CALL_standard___collection___abstract_collection___SimpleCollection___add(fra.me.REG[2])(fra.me.REG[2], fra.me.REG[1]);
  fra.me.REG[1] = CALL_program___Program___main_module(fra.me.REG[0])(fra.me.REG[0]);
  fra.me.REG[1] = CALL_metamodel___abstractmetamodel___MMModule___name(fra.me.REG[1])(fra.me.REG[1]);
  fra.me.REG[1] = CALL_standard___string___Object___to_s(fra.me.REG[1])(fra.me.REG[1]);
  CALL_standard___collection___abstract_collection___SimpleCollection___add(fra.me.REG[2])(fra.me.REG[2], fra.me.REG[1]);
  if (!once_value_3) {
    fra.me.REG[1] = BOX_NativeString(".reachable_methods_as_init.log");
    REGB0 = TAG_Int(30);
    fra.me.REG[1] = NEW_String_standard___string___String___with_native(fra.me.REG[1], REGB0);
    once_value_3 = fra.me.REG[1];
    register_static_object(&once_value_3);
  } else fra.me.REG[1] = once_value_3;
  fra.me.REG[1] = fra.me.REG[1];
  CALL_standard___collection___abstract_collection___SimpleCollection___add(fra.me.REG[2])(fra.me.REG[2], fra.me.REG[1]);
  fra.me.REG[2] = CALL_standard___string___Object___to_s(fra.me.REG[2])(fra.me.REG[2]);
  fra.me.REG[2] = NEW_OFStream_standard___file___OFStream___open(fra.me.REG[2]);
  CALL_program___Program___with_each_live_local_classes(fra.me.REG[0])(fra.me.REG[0], (&(fra.me)), ((fun_t)OC_global___reachable_as_init___Program___dump_reachable_as_init_methods_4));
  /* global/reachable_as_init.nit:40 */
  CALL_standard___stream___IOS___close(fra.me.REG[2])(fra.me.REG[2]);
  stack_frame_head = fra.me.prev;
  return;
}
  void OC_global___reachable_as_init___Program___dump_reachable_as_init_methods_4(struct stack_frame_t *closctx, val_t p0){
    struct {struct stack_frame_t me;} fra;
    val_t tmp;
    /* global/reachable_as_init.nit:30 */
    fra.me.prev = stack_frame_head; stack_frame_head = &fra.me;
    fra.me.file = LOCATE_global___reachable_as_init;
    fra.me.line = 30;
    fra.me.meth = LOCATE_global___reachable_as_init___Program___dump_reachable_as_init_methods;
    fra.me.has_broke = 0;
    fra.me.REG_size = 1;
    fra.me.nitni_local_ref_head = NULL;
    fra.me.REG[0] = NIT_NULL;
    fra.me.REG[0] = p0;
    closctx->REG[1] = fra.me.REG[0];
    /* global/reachable_as_init.nit:31 */
    fra.me.REG[0] = CALL_metamodel___abstractmetamodel___MMLocalClass___global_properties(closctx->REG[1])(closctx->REG[1]);
    CALL_standard___collection___abstract_collection___Collection___iterate(fra.me.REG[0])(fra.me.REG[0], closctx, ((fun_t)OC_global___reachable_as_init___Program___dump_reachable_as_init_methods_5));
    stack_frame_head = fra.me.prev;
    return;
  }
    void OC_global___reachable_as_init___Program___dump_reachable_as_init_methods_5(struct stack_frame_t *closctx, val_t p0, struct stack_frame_t *closctx_param, fun_t clos_fun0){
      struct {struct stack_frame_t me; val_t MORE_REG[2];} fra;
      val_t REGB0;
      fun_t CREG[1];
      val_t tmp;
        static val_t once_value_7; /* Once value */
        static val_t once_value_8; /* Once value */
      fra.me.prev = stack_frame_head; stack_frame_head = &fra.me;
      fra.me.file = LOCATE_global___reachable_as_init;
      fra.me.line = 0;
      fra.me.meth = LOCATE_global___reachable_as_init___Program___dump_reachable_as_init_methods;
      fra.me.has_broke = 0;
      fra.me.REG_size = 3;
      fra.me.nitni_local_ref_head = NULL;
      fra.me.REG[0] = NIT_NULL;
      fra.me.REG[1] = NIT_NULL;
      fra.me.REG[2] = NIT_NULL;
      fra.me.closure_ctx = closctx_param;
      fra.me.closure_funs = CREG;
      fra.me.REG[0] = p0;
      CREG[0] = clos_fun0;
      /* global/reachable_as_init.nit:32 */
      fra.me.REG[0] = CALL_metamodel___abstractmetamodel___MMLocalClass_____bra(closctx->REG[1])(closctx->REG[1], fra.me.REG[0]);
      /* global/reachable_as_init.nit:33 */
      fra.me.REG[1] = CALL_metamodel___abstractmetamodel___MMLocalProperty___global(fra.me.REG[0])(fra.me.REG[0]);
      REGB0 = CALL_metamodel___abstractmetamodel___MMGlobalProperty___is_init_for(fra.me.REG[1])(fra.me.REG[1], closctx->REG[1]);
      REGB0 = TAG_Bool(!UNTAG_Bool(REGB0));
      if (UNTAG_Bool(REGB0)) {
        goto label6;
      }
      /* global/reachable_as_init.nit:34 */
      REGB0 = TAG_Bool(VAL_ISA(fra.me.REG[0], COLOR_metamodel___abstractmetamodel___MMMethod, ID_metamodel___abstractmetamodel___MMMethod)) /*cast MMMethod*/;
      if (UNTAG_Bool(REGB0)) {
      } else {
        nit_abort("Assert failed", NULL, LOCATE_global___reachable_as_init, 34);
      }
      /* global/reachable_as_init.nit:35 */
      fra.me.REG[1] = CALL_global___reachable_as_init___Program___rai(closctx->REG[0])(closctx->REG[0]);
      REGB0 = TAG_Bool(fra.me.REG[1]==NIT_NULL);
      if (UNTAG_Bool(REGB0)) {
        nit_abort("Reciever is null", NULL, LOCATE_global___reachable_as_init, 35);
      }
      REGB0 = CALL_global___reachable_as_init___ReachableAsInitAnalysis___is_method_reachable_as_init(fra.me.REG[1])(fra.me.REG[1], fra.me.REG[0], closctx->REG[1]);
      if (UNTAG_Bool(REGB0)) {
        /* global/reachable_as_init.nit:36 */
        REGB0 = TAG_Int(3);
        fra.me.REG[1] = NEW_Array_standard___collection___array___Array___with_capacity(REGB0);
        if (!once_value_7) {
          fra.me.REG[2] = BOX_NativeString("");
          REGB0 = TAG_Int(0);
          fra.me.REG[2] = NEW_String_standard___string___String___with_native(fra.me.REG[2], REGB0);
          once_value_7 = fra.me.REG[2];
          register_static_object(&once_value_7);
        } else fra.me.REG[2] = once_value_7;
        fra.me.REG[2] = fra.me.REG[2];
        CALL_standard___collection___abstract_collection___SimpleCollection___add(fra.me.REG[1])(fra.me.REG[1], fra.me.REG[2]);
        fra.me.REG[0] = CALL_metamodel___abstractmetamodel___MMLocalProperty___full_name(fra.me.REG[0])(fra.me.REG[0]);
        CALL_standard___collection___abstract_collection___SimpleCollection___add(fra.me.REG[1])(fra.me.REG[1], fra.me.REG[0]);
        if (!once_value_8) {
          fra.me.REG[0] = BOX_NativeString("\n");
          REGB0 = TAG_Int(1);
          fra.me.REG[0] = NEW_String_standard___string___String___with_native(fra.me.REG[0], REGB0);
          once_value_8 = fra.me.REG[0];
          register_static_object(&once_value_8);
        } else fra.me.REG[0] = once_value_8;
        fra.me.REG[0] = fra.me.REG[0];
        CALL_standard___collection___abstract_collection___SimpleCollection___add(fra.me.REG[1])(fra.me.REG[1], fra.me.REG[0]);
        fra.me.REG[1] = CALL_standard___string___Object___to_s(fra.me.REG[1])(fra.me.REG[1]);
        CALL_standard___stream___OStream___write(closctx->REG[2])(closctx->REG[2], fra.me.REG[1]);
      }
      label6: while(0);
      stack_frame_head = fra.me.prev;
      return;
    }
static const char LOCATE_global___reachable_as_init___ReachableAsInitAnalysis___is_method_reachable_as_init[] = "reachable_as_init::ReachableAsInitAnalysis::is_method_reachable_as_init";
val_t global___reachable_as_init___ReachableAsInitAnalysis___is_method_reachable_as_init(val_t p0, val_t p1, val_t p2){
  struct {struct stack_frame_t me;} fra;
  val_t tmp;
  fra.me.prev = stack_frame_head; stack_frame_head = &fra.me;
  fra.me.file = LOCATE_global___reachable_as_init;
  fra.me.line = 49;
  fra.me.meth = LOCATE_global___reachable_as_init___ReachableAsInitAnalysis___is_method_reachable_as_init;
  fra.me.has_broke = 0;
  fra.me.REG_size = 0;
  fra.me.nitni_local_ref_head = NULL;
  /* global/reachable_as_init.nit:49 */
  nit_abort("Deferred method called", NULL, LOCATE_global___reachable_as_init, 49);
  stack_frame_head = fra.me.prev;
  return NIT_NULL;
}
static const char LOCATE_global___reachable_as_init___DefaultReachableAsInitAnalysis___is_method_reachable_as_init[] = "reachable_as_init::DefaultReachableAsInitAnalysis::(reachable_as_init::ReachableAsInitAnalysis::is_method_reachable_as_init)";
val_t global___reachable_as_init___DefaultReachableAsInitAnalysis___is_method_reachable_as_init(val_t p0, val_t p1, val_t p2){
  struct {struct stack_frame_t me; val_t MORE_REG[2];} fra;
  val_t REGB0;
  val_t REGB1;
  val_t tmp;
  fra.me.prev = stack_frame_head; stack_frame_head = &fra.me;
  fra.me.file = LOCATE_global___reachable_as_init;
  fra.me.line = 55;
  fra.me.meth = LOCATE_global___reachable_as_init___DefaultReachableAsInitAnalysis___is_method_reachable_as_init;
  fra.me.has_broke = 0;
  fra.me.REG_size = 3;
  fra.me.nitni_local_ref_head = NULL;
  fra.me.REG[0] = NIT_NULL;
  fra.me.REG[1] = NIT_NULL;
  fra.me.REG[2] = NIT_NULL;
  fra.me.REG[0] = p0;
  fra.me.REG[1] = p1;
  fra.me.REG[2] = p2;
  /* global/reachable_as_init.nit:56 */
  fra.me.REG[0] = CALL_metamodel___abstractmetamodel___MMLocalProperty___global(fra.me.REG[1])(fra.me.REG[1]);
  REGB0 = CALL_metamodel___abstractmetamodel___MMGlobalProperty___is_init(fra.me.REG[0])(fra.me.REG[0]);
  if (UNTAG_Bool(REGB0)) {
    fra.me.REG[1] = CALL_metamodel___abstractmetamodel___MMLocalProperty___global(fra.me.REG[1])(fra.me.REG[1]);
    REGB0 = CALL_metamodel___abstractmetamodel___MMGlobalProperty___is_init_for(fra.me.REG[1])(fra.me.REG[1], fra.me.REG[2]);
  } else {
    REGB1 = TAG_Bool(0);
    REGB0 = REGB1;
  }
  if (UNTAG_Bool(REGB0)) {
    REGB0 = TAG_Bool(1);
    goto label1;
  }
  /* global/reachable_as_init.nit:57 */
  REGB1 = TAG_Bool(0);
  REGB0 = REGB1;
  goto label1;
  label1: while(0);
  stack_frame_head = fra.me.prev;
  return REGB0;
}
static const char LOCATE_global___reachable_as_init___DefaultReachableAsInitAnalysis___init[] = "reachable_as_init::DefaultReachableAsInitAnalysis::init";
void global___reachable_as_init___DefaultReachableAsInitAnalysis___init(val_t p0, int* init_table){
  int itpos0 = VAL2OBJ(p0)->vft[INIT_TABLE_POS_global___reachable_as_init___DefaultReachableAsInitAnalysis].i;
  struct {struct stack_frame_t me;} fra;
  val_t tmp;
  if (init_table[itpos0]) return;
  fra.me.prev = stack_frame_head; stack_frame_head = &fra.me;
  fra.me.file = LOCATE_global___reachable_as_init;
  fra.me.line = 60;
  fra.me.meth = LOCATE_global___reachable_as_init___DefaultReachableAsInitAnalysis___init;
  fra.me.has_broke = 0;
  fra.me.REG_size = 1;
  fra.me.nitni_local_ref_head = NULL;
  fra.me.REG[0] = NIT_NULL;
  fra.me.REG[0] = p0;
  stack_frame_head = fra.me.prev;
  init_table[itpos0] = 1;
  return;
}
