// ./wabt/out/clang/Debug/wasm2c ../given/alien_tech.wasm -o source_from_wasm2c.c
// gcc -c  -o bin_from_wasm2c source_from_wasm2c.c -I wasm2c
#ifndef WASM_H_GENERATED_
#define WASM_H_GENERATED_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "wasm-rt.h"

#ifndef WASM_RT_MODULE_PREFIX
#define WASM_RT_MODULE_PREFIX
#endif

#define WASM_RT_PASTE_(x, y) x ## y
#define WASM_RT_PASTE(x, y) WASM_RT_PASTE_(x, y)
#define WASM_RT_ADD_PREFIX(x) WASM_RT_PASTE(WASM_RT_MODULE_PREFIX, x)

/* TODO(binji): only use stdint.h types in header */
typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef int64_t s64;
typedef float f32;
typedef double f64;

extern void WASM_RT_ADD_PREFIX(init)(void);

/* import: 'wasi_snapshot_preview1' 'fd_write' */
extern u32 (*Z_wasi_snapshot_preview1Z_fd_writeZ_iiiii)(u32, u32, u32, u32);
/* import: 'env' 'emscripten_resize_heap' */
extern u32 (*Z_envZ_emscripten_resize_heapZ_ii)(u32);
/* import: 'env' 'emscripten_memcpy_big' */
extern u32 (*Z_envZ_emscripten_memcpy_bigZ_iiii)(u32, u32, u32);
/* import: 'env' '__handle_stack_overflow' */
extern void (*Z_envZ___handle_stack_overflowZ_vv)(void);
/* import: 'env' 'setTempRet0' */
extern void (*Z_envZ_setTempRet0Z_vi)(u32);
/* import: 'env' 'memory' */
extern wasm_rt_memory_t (*Z_envZ_memory);
/* import: 'env' 'table' */
extern wasm_rt_table_t (*Z_envZ_table);

/* export: '__wasm_call_ctors' */
extern void (*WASM_RT_ADD_PREFIX(Z___wasm_call_ctorsZ_vv))(void);
/* export: 'malloc' */
extern u32 (*WASM_RT_ADD_PREFIX(Z_mallocZ_ii))(u32);
/* export: 'free' */
extern void (*WASM_RT_ADD_PREFIX(Z_freeZ_vi))(u32);
/* export: 'main' */
extern u32 (*WASM_RT_ADD_PREFIX(Z_mainZ_iii))(u32, u32);
/* export: '__errno_location' */
extern u32 (*WASM_RT_ADD_PREFIX(Z___errno_locationZ_iv))(void);
/* export: 'fflush' */
extern u32 (*WASM_RT_ADD_PREFIX(Z_fflushZ_ii))(u32);
/* export: 'setThrew' */
extern void (*WASM_RT_ADD_PREFIX(Z_setThrewZ_vii))(u32, u32);
/* export: '__data_end' */
extern u32 (*WASM_RT_ADD_PREFIX(Z___data_endZ_i));
/* export: '__set_stack_limit' */
extern void (*WASM_RT_ADD_PREFIX(Z___set_stack_limitZ_vi))(u32);
/* export: 'stackSave' */
extern u32 (*WASM_RT_ADD_PREFIX(Z_stackSaveZ_iv))(void);
/* export: 'stackAlloc' */
extern u32 (*WASM_RT_ADD_PREFIX(Z_stackAllocZ_ii))(u32);
/* export: 'stackRestore' */
extern void (*WASM_RT_ADD_PREFIX(Z_stackRestoreZ_vi))(u32);
/* export: '__growWasmMemory' */
extern u32 (*WASM_RT_ADD_PREFIX(Z___growWasmMemoryZ_ii))(u32);
/* export: 'dynCall_iidiiii' */
extern u32 (*WASM_RT_ADD_PREFIX(Z_dynCall_iidiiiiZ_iiidiiii))(u32, u32, f64, u32, u32, u32, u32);
/* export: 'dynCall_vii' */
extern void (*WASM_RT_ADD_PREFIX(Z_dynCall_viiZ_viii))(u32, u32, u32);
/* export: 'dynCall_ii' */
extern u32 (*WASM_RT_ADD_PREFIX(Z_dynCall_iiZ_iii))(u32, u32);
/* export: 'dynCall_iiii' */
extern u32 (*WASM_RT_ADD_PREFIX(Z_dynCall_iiiiZ_iiiii))(u32, u32, u32, u32);
/* export: 'dynCall_jiji' */
extern u32 (*WASM_RT_ADD_PREFIX(Z_dynCall_jijiZ_iiiiii))(u32, u32, u32, u32, u32);
#ifdef __cplusplus
}
#endif

#endif  /* WASM_H_GENERATED_ */
#include <math.h>
#include <string.h>

#include "wasm.h"
#define UNLIKELY(x) __builtin_expect(!!(x), 0)
#define LIKELY(x) __builtin_expect(!!(x), 1)

#define TRAP(x) (wasm_rt_trap(WASM_RT_TRAP_##x), 0)

#define FUNC_PROLOGUE                                            \
  if (++wasm_rt_call_stack_depth > WASM_RT_MAX_CALL_STACK_DEPTH) \
    TRAP(EXHAUSTION)

#define FUNC_EPILOGUE --wasm_rt_call_stack_depth

#define UNREACHABLE TRAP(UNREACHABLE)

#define CALL_INDIRECT(table, t, ft, x, ...)          \
  (LIKELY((x) < table.size && table.data[x].func &&  \
          table.data[x].func_type == func_types[ft]) \
       ? ((t)table.data[x].func)(__VA_ARGS__)        \
       : TRAP(CALL_INDIRECT))

#define MEMCHECK(mem, a, t)  \
  if (UNLIKELY((a) + sizeof(t) > mem->size)) TRAP(OOB)

#define DEFINE_LOAD(name, t1, t2, t3)              \
  static inline t3 name(wasm_rt_memory_t* mem, u64 addr) {   \
    MEMCHECK(mem, addr, t1);                       \
    t1 result;                                     \
    memcpy(&result, &mem->data[addr], sizeof(t1)); \
    return (t3)(t2)result;                         \
  }

#define DEFINE_STORE(name, t1, t2)                           \
  static inline void name(wasm_rt_memory_t* mem, u64 addr, t2 value) { \
    MEMCHECK(mem, addr, t1);                                 \
    t1 wrapped = (t1)value;                                  \
    memcpy(&mem->data[addr], &wrapped, sizeof(t1));          \
  }

DEFINE_LOAD(i32_load, u32, u32, u32);
DEFINE_LOAD(i64_load, u64, u64, u64);
DEFINE_LOAD(f32_load, f32, f32, f32);
DEFINE_LOAD(f64_load, f64, f64, f64);
DEFINE_LOAD(i32_load8_s, s8, s32, u32);
DEFINE_LOAD(i64_load8_s, s8, s64, u64);
DEFINE_LOAD(i32_load8_u, u8, u32, u32);
DEFINE_LOAD(i64_load8_u, u8, u64, u64);
DEFINE_LOAD(i32_load16_s, s16, s32, u32);
DEFINE_LOAD(i64_load16_s, s16, s64, u64);
DEFINE_LOAD(i32_load16_u, u16, u32, u32);
DEFINE_LOAD(i64_load16_u, u16, u64, u64);
DEFINE_LOAD(i64_load32_s, s32, s64, u64);
DEFINE_LOAD(i64_load32_u, u32, u64, u64);
DEFINE_STORE(i32_store, u32, u32);
DEFINE_STORE(i64_store, u64, u64);
DEFINE_STORE(f32_store, f32, f32);
DEFINE_STORE(f64_store, f64, f64);
DEFINE_STORE(i32_store8, u8, u32);
DEFINE_STORE(i32_store16, u16, u32);
DEFINE_STORE(i64_store8, u8, u64);
DEFINE_STORE(i64_store16, u16, u64);
DEFINE_STORE(i64_store32, u32, u64);

#define I32_CLZ(x) ((x) ? __builtin_clz(x) : 32)
#define I64_CLZ(x) ((x) ? __builtin_clzll(x) : 64)
#define I32_CTZ(x) ((x) ? __builtin_ctz(x) : 32)
#define I64_CTZ(x) ((x) ? __builtin_ctzll(x) : 64)
#define I32_POPCNT(x) (__builtin_popcount(x))
#define I64_POPCNT(x) (__builtin_popcountll(x))

#define DIV_S(ut, min, x, y)                                 \
   ((UNLIKELY((y) == 0)) ?                TRAP(DIV_BY_ZERO)  \
  : (UNLIKELY((x) == min && (y) == -1)) ? TRAP(INT_OVERFLOW) \
  : (ut)((x) / (y)))

#define REM_S(ut, min, x, y)                                \
   ((UNLIKELY((y) == 0)) ?                TRAP(DIV_BY_ZERO) \
  : (UNLIKELY((x) == min && (y) == -1)) ? 0                 \
  : (ut)((x) % (y)))

#define I32_DIV_S(x, y) DIV_S(u32, INT32_MIN, (s32)x, (s32)y)
#define I64_DIV_S(x, y) DIV_S(u64, INT64_MIN, (s64)x, (s64)y)
#define I32_REM_S(x, y) REM_S(u32, INT32_MIN, (s32)x, (s32)y)
#define I64_REM_S(x, y) REM_S(u64, INT64_MIN, (s64)x, (s64)y)

#define DIVREM_U(op, x, y) \
  ((UNLIKELY((y) == 0)) ? TRAP(DIV_BY_ZERO) : ((x) op (y)))

#define DIV_U(x, y) DIVREM_U(/, x, y)
#define REM_U(x, y) DIVREM_U(%, x, y)

#define ROTL(x, y, mask) \
  (((x) << ((y) & (mask))) | ((x) >> (((mask) - (y) + 1) & (mask))))
#define ROTR(x, y, mask) \
  (((x) >> ((y) & (mask))) | ((x) << (((mask) - (y) + 1) & (mask))))

#define I32_ROTL(x, y) ROTL(x, y, 31)
#define I64_ROTL(x, y) ROTL(x, y, 63)
#define I32_ROTR(x, y) ROTR(x, y, 31)
#define I64_ROTR(x, y) ROTR(x, y, 63)

#define FMIN(x, y)                                          \
   ((UNLIKELY((x) != (x))) ? NAN                            \
  : (UNLIKELY((y) != (y))) ? NAN                            \
  : (UNLIKELY((x) == 0 && (y) == 0)) ? (signbit(x) ? x : y) \
  : (x < y) ? x : y)

#define FMAX(x, y)                                          \
   ((UNLIKELY((x) != (x))) ? NAN                            \
  : (UNLIKELY((y) != (y))) ? NAN                            \
  : (UNLIKELY((x) == 0 && (y) == 0)) ? (signbit(x) ? y : x) \
  : (x > y) ? x : y)

#define TRUNC_S(ut, st, ft, min, max, maxop, x)                             \
   ((UNLIKELY((x) != (x))) ? TRAP(INVALID_CONVERSION)                       \
  : (UNLIKELY((x) < (ft)(min) || (x) maxop (ft)(max))) ? TRAP(INT_OVERFLOW) \
  : (ut)(st)(x))

#define I32_TRUNC_S_F32(x) TRUNC_S(u32, s32, f32, INT32_MIN, INT32_MAX, >=, x)
#define I64_TRUNC_S_F32(x) TRUNC_S(u64, s64, f32, INT64_MIN, INT64_MAX, >=, x)
#define I32_TRUNC_S_F64(x) TRUNC_S(u32, s32, f64, INT32_MIN, INT32_MAX, >,  x)
#define I64_TRUNC_S_F64(x) TRUNC_S(u64, s64, f64, INT64_MIN, INT64_MAX, >=, x)

#define TRUNC_U(ut, ft, max, maxop, x)                                    \
   ((UNLIKELY((x) != (x))) ? TRAP(INVALID_CONVERSION)                     \
  : (UNLIKELY((x) <= (ft)-1 || (x) maxop (ft)(max))) ? TRAP(INT_OVERFLOW) \
  : (ut)(x))

#define I32_TRUNC_U_F32(x) TRUNC_U(u32, f32, UINT32_MAX, >=, x)
#define I64_TRUNC_U_F32(x) TRUNC_U(u64, f32, UINT64_MAX, >=, x)
#define I32_TRUNC_U_F64(x) TRUNC_U(u32, f64, UINT32_MAX, >,  x)
#define I64_TRUNC_U_F64(x) TRUNC_U(u64, f64, UINT64_MAX, >=, x)

#define DEFINE_REINTERPRET(name, t1, t2)  \
  static inline t2 name(t1 x) {           \
    t2 result;                            \
    memcpy(&result, &x, sizeof(result));  \
    return result;                        \
  }

DEFINE_REINTERPRET(f32_reinterpret_i32, u32, f32)
DEFINE_REINTERPRET(i32_reinterpret_f32, f32, u32)
DEFINE_REINTERPRET(f64_reinterpret_i64, u64, f64)
DEFINE_REINTERPRET(i64_reinterpret_f64, f64, u64)


static u32 func_types[23];

static void init_func_types(void) {
  func_types[0] = wasm_rt_register_func_type(1, 1, WASM_RT_I32, WASM_RT_I32);
  func_types[1] = wasm_rt_register_func_type(3, 1, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32);
  func_types[2] = wasm_rt_register_func_type(1, 0, WASM_RT_I32);
  func_types[3] = wasm_rt_register_func_type(0, 1, WASM_RT_I32);
  func_types[4] = wasm_rt_register_func_type(2, 1, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32);
  func_types[5] = wasm_rt_register_func_type(0, 0);
  func_types[6] = wasm_rt_register_func_type(2, 0, WASM_RT_I32, WASM_RT_I32);
  func_types[7] = wasm_rt_register_func_type(6, 1, WASM_RT_I32, WASM_RT_F64, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32);
  func_types[8] = wasm_rt_register_func_type(3, 1, WASM_RT_I32, WASM_RT_I64, WASM_RT_I32, WASM_RT_I64);
  func_types[9] = wasm_rt_register_func_type(3, 0, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32);
  func_types[10] = wasm_rt_register_func_type(4, 0, WASM_RT_I32, WASM_RT_I64, WASM_RT_I64, WASM_RT_I32);
  func_types[11] = wasm_rt_register_func_type(4, 1, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32);
  func_types[12] = wasm_rt_register_func_type(5, 1, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32);
  func_types[13] = wasm_rt_register_func_type(2, 1, WASM_RT_I64, WASM_RT_I32, WASM_RT_I32);
  func_types[14] = wasm_rt_register_func_type(4, 0, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32);
  func_types[15] = wasm_rt_register_func_type(5, 0, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32);
  func_types[16] = wasm_rt_register_func_type(7, 1, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32);
  func_types[17] = wasm_rt_register_func_type(7, 1, WASM_RT_I32, WASM_RT_I32, WASM_RT_F64, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32);
  func_types[18] = wasm_rt_register_func_type(3, 1, WASM_RT_I64, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32);
  func_types[19] = wasm_rt_register_func_type(4, 1, WASM_RT_I32, WASM_RT_I32, WASM_RT_I64, WASM_RT_I32, WASM_RT_I64);
  func_types[20] = wasm_rt_register_func_type(1, 1, WASM_RT_F64, WASM_RT_I64);
  func_types[21] = wasm_rt_register_func_type(2, 1, WASM_RT_I64, WASM_RT_I64, WASM_RT_F64);
  func_types[22] = wasm_rt_register_func_type(2, 1, WASM_RT_F64, WASM_RT_I32, WASM_RT_F64);
}

static u32 f5(void);
static void __wasm_call_ctors(void);
static u32 f7(u32, u32, u32);
static void f8(void);
static u32 f9(u32, u32);
static u32 main(u32, u32);
static u32 f11(u32, u32, u32);
static u32 __errno_location(void);
static u32 f13(u32);
static u32 f14(u32, u32, u32);
static u32 f15(u32);
static u32 f16(void);
static u32 f17(u32, u32, u32);
static u32 f18(void);
static u32 f19(u32, u32);
static u32 f20(u32, u32, u32);
static f64 f21(f64, u32);
static void f22(u32, u64, u64, u32);
static void f23(u32, u64, u64, u32);
static f64 f24(u64, u64);
static u32 f25(u32, u32, u32, u32, u32);
static u32 f26(u32, u32, u32, u32, u32, u32, u32);
static void f27(u32, u32, u32);
static u32 f28(u32);
static void f29(u32, u32, u32, u32);
static void f30(u32, u32, u32, u32, u32);
static u32 f31(u64, u32);
static u32 f32_0(u64, u32, u32);
static u32 f33(u64, u32);
static u32 f34(u32, u32, u32);
static u32 f35(u32, f64, u32, u32, u32, u32);
static void f36(u32, u32);
static u64 f37(f64);
static u32 malloc(u32);
static void free(u32);
static u32 f40(u32);
static u32 f41(u32, u32, u32);
static u32 f42(u32, u32, u32);
static void f43(u32);
static void f44(u32);
static u32 f45(void);
static void f46(void);
static u32 f47(u32);
static u32 f48(u32, u32, u32);
static u32 f49(u32);
static u64 f50(u32, u64, u32);
static u32 f51(u32, u32);
static u32 f52(u32);
static void f53(u32);
static u32 f54(u32);
static void setThrew(u32, u32);
static u32 fflush(u32);
static u32 f57(u32);
static void __set_stack_limit(u32);
static u32 stackSave(void);
static u32 stackAlloc(u32);
static void stackRestore(u32);
static u32 __growWasmMemory(u32);
static u32 dynCall_iidiiii(u32, u32, f64, u32, u32, u32, u32);
static void dynCall_vii(u32, u32, u32);
static u32 dynCall_ii(u32, u32);
static u32 dynCall_iiii(u32, u32, u32, u32);
static u64 f67(u32, u32, u64, u32);
static u32 dynCall_jiji(u32, u32, u32, u32, u32);

static u32 g0;
static u32 __data_end;
static u32 g2;

static void init_globals(void) {
  g0 = 5246544u;
  __data_end = 3664u;
  g2 = 0u;
}

static u32 f5(void) {
  FUNC_PROLOGUE;
  u32 i0;
  i0 = 3664u;
  FUNC_EPILOGUE;
  return i0;
}

static void __wasm_call_ctors(void) {
  FUNC_PROLOGUE;
  FUNC_EPILOGUE;
}

static u32 f7(u32 p0, u32 p1, u32 p2) {
  u32 l3 = 0, l4 = 0, l5 = 0, l6 = 0, l7 = 0, l8 = 0, l9 = 0, l10 = 0, 
      l11 = 0, l12 = 0, l13 = 0, l14 = 0, l15 = 0, l16 = 0, l17 = 0, l18 = 0, 
      l19 = 0, l20 = 0, l21 = 0, l22 = 0, l23 = 0, l24 = 0, l25 = 0, l26 = 0, 
      l27 = 0, l28 = 0, l29 = 0, l30 = 0, l31 = 0, l32 = 0, l33 = 0, l34 = 0, 
      l35 = 0, l36 = 0, l37 = 0, l38 = 0, l39 = 0, l40 = 0, l41 = 0, l42 = 0, 
      l43 = 0, l44 = 0, l45 = 0, l46 = 0, l47 = 0, l48 = 0, l49 = 0, l50 = 0, 
      l51 = 0, l52 = 0, l53 = 0, l54 = 0, l55 = 0, l56 = 0, l57 = 0, l58 = 0, 
      l59 = 0, l60 = 0, l61 = 0, l62 = 0, l63 = 0, l64 = 0, l65 = 0, l66 = 0, 
      l67 = 0, l68 = 0, l69 = 0, l70 = 0, l71 = 0, l72 = 0, l73 = 0, l74 = 0, 
      l75 = 0, l76 = 0, l77 = 0, l78 = 0, l79 = 0, l80 = 0, l81 = 0, l82 = 0, 
      l83 = 0, l84 = 0, l85 = 0, l86 = 0, l87 = 0, l88 = 0, l89 = 0, l90 = 0, 
      l91 = 0, l92 = 0, l93 = 0, l94 = 0, l95 = 0, l96 = 0, l97 = 0, l98 = 0, 
      l99 = 0, l100 = 0, l101 = 0, l102 = 0, l103 = 0, l104 = 0, l105 = 0, l106 = 0, 
      l107 = 0, l108 = 0, l109 = 0, l110 = 0, l111 = 0, l112 = 0, l113 = 0, l114 = 0, 
      l115 = 0, l116 = 0, l117 = 0, l118 = 0, l119 = 0, l120 = 0, l121 = 0, l122 = 0, 
      l123 = 0, l124 = 0, l125 = 0, l126 = 0, l127 = 0, l128 = 0, l129 = 0, l130 = 0, 
      l131 = 0, l132 = 0, l133 = 0, l134 = 0, l135 = 0, l136 = 0, l137 = 0, l138 = 0, 
      l139 = 0, l140 = 0, l141 = 0, l142 = 0, l143 = 0, l144 = 0, l145 = 0, l146 = 0, 
      l147 = 0, l148 = 0, l149 = 0, l150 = 0, l151 = 0, l152 = 0, l153 = 0, l154 = 0, 
      l155 = 0, l156 = 0, l157 = 0, l158 = 0, l159 = 0, l160 = 0, l161 = 0, l162 = 0, 
      l163 = 0, l164 = 0, l165 = 0, l166 = 0, l167 = 0, l168 = 0, l169 = 0, l170 = 0, 
      l171 = 0, l172 = 0, l173 = 0, l174 = 0, l175 = 0, l176 = 0, l177 = 0, l178 = 0, 
      l179 = 0, l180 = 0, l181 = 0, l182 = 0, l183 = 0, l184 = 0, l185 = 0, l186 = 0, 
      l187 = 0, l188 = 0, l189 = 0, l190 = 0, l191 = 0, l192 = 0, l193 = 0, l194 = 0, 
      l195 = 0, l196 = 0, l197 = 0, l198 = 0, l199 = 0, l200 = 0, l201 = 0, l202 = 0, 
      l203 = 0, l204 = 0, l205 = 0, l206 = 0, l207 = 0, l208 = 0, l209 = 0, l210 = 0, 
      l211 = 0, l212 = 0, l213 = 0, l214 = 0, l215 = 0, l216 = 0, l217 = 0, l218 = 0, 
      l219 = 0, l220 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  i0 = g0;
  l3 = i0;
  i0 = 304u;
  l4 = i0;
  i0 = l3;
  i1 = l4;
  i0 -= i1;
  l5 = i0;
  i0 = l5;
  l219 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l219;
  g0 = i0;
  i0 = 0u;
  l6 = i0;
  i0 = 32u;
  l7 = i0;
  i0 = l5;
  i1 = l7;
  i0 += i1;
  l8 = i0;
  i0 = l8;
  l9 = i0;
  i0 = l5;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 296), i1);
  i0 = l5;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 292), i1);
  i0 = l5;
  i1 = p2;
  i32_store(Z_envZ_memory, (u64)(i0 + 288), i1);
  i0 = l5;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = 256u;
  l10 = i0;
  i0 = 128u;
  l11 = i0;
  i0 = l9;
  i1 = l11;
  i2 = l10;
  i0 = f42(i0, i1, i2);
  i0 = l5;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  L3: 
    i0 = 64u;
    l12 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l13 = i0;
    i0 = l13;
    l14 = i0;
    i0 = l12;
    l15 = i0;
    i0 = l14;
    i1 = l15;
    i0 = i0 < i1;
    l16 = i0;
    i0 = 1u;
    l17 = i0;
    i0 = l16;
    i1 = l17;
    i0 &= i1;
    l18 = i0;
    i0 = l18;
    i0 = !(i0);
    if (i0) {goto B2;}
    i0 = 32u;
    l19 = i0;
    i0 = l5;
    i1 = l19;
    i0 += i1;
    l20 = i0;
    i0 = l20;
    l21 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l22 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l23 = i0;
    i0 = l23;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1024));
    l24 = i0;
    i0 = 255u;
    l25 = i0;
    i0 = l24;
    i1 = l25;
    i0 &= i1;
    l26 = i0;
    i0 = l21;
    i1 = l26;
    i0 += i1;
    l27 = i0;
    i0 = l27;
    i1 = l22;
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l28 = i0;
    i0 = 1u;
    l29 = i0;
    i0 = l28;
    i1 = l29;
    i0 += i1;
    l30 = i0;
    i0 = l5;
    i1 = l30;
    i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
    goto L3;
  UNREACHABLE;
  B2:;
  i0 = 0u;
  l31 = i0;
  i0 = 0u;
  l32 = i0;
  i0 = l5;
  i1 = l32;
  i32_store8(Z_envZ_memory, (u64)(i0 + 93), i1);
  i0 = l5;
  i1 = l31;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l5;
  i1 = l31;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  L5: 
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l33 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 292));
    l34 = i0;
    i0 = l33;
    l35 = i0;
    i0 = l34;
    l36 = i0;
    i0 = l35;
    i1 = l36;
    i0 = i0 < i1;
    l37 = i0;
    i0 = 1u;
    l38 = i0;
    i0 = l37;
    i1 = l38;
    i0 &= i1;
    l39 = i0;
    i0 = l39;
    i0 = !(i0);
    if (i0) {goto B4;}
    i0 = 128u;
    l40 = i0;
    i0 = 32u;
    l41 = i0;
    i0 = l5;
    i1 = l41;
    i0 += i1;
    l42 = i0;
    i0 = l42;
    l43 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 296));
    l44 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l45 = i0;
    i0 = l44;
    i1 = l45;
    i0 += i1;
    l46 = i0;
    i0 = l46;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
    l47 = i0;
    i0 = 255u;
    l48 = i0;
    i0 = l47;
    i1 = l48;
    i0 &= i1;
    l49 = i0;
    i0 = l43;
    i1 = l49;
    i0 += i1;
    l50 = i0;
    i0 = l50;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
    l51 = i0;
    i0 = 255u;
    l52 = i0;
    i0 = l51;
    i1 = l52;
    i0 &= i1;
    l53 = i0;
    i0 = l53;
    l54 = i0;
    i0 = l40;
    l55 = i0;
    i0 = l54;
    i1 = l55;
    i0 = i0 != i1;
    l56 = i0;
    i0 = 1u;
    l57 = i0;
    i0 = l56;
    i1 = l57;
    i0 &= i1;
    l58 = i0;
    i0 = l58;
    i0 = !(i0);
    if (i0) {goto B6;}
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
    l59 = i0;
    i0 = 1u;
    l60 = i0;
    i0 = l59;
    i1 = l60;
    i0 += i1;
    l61 = i0;
    i0 = l5;
    i1 = l61;
    i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
    B6:;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l62 = i0;
    i0 = 1u;
    l63 = i0;
    i0 = l62;
    i1 = l63;
    i0 += i1;
    l64 = i0;
    i0 = l5;
    i1 = l64;
    i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
    goto L5;
  UNREACHABLE;
  B4:;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l65 = i0;
  i0 = l65;
  i0 = !(i0);
  if (i0) {goto B9;}
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l66 = i0;
  i0 = 3u;
  l67 = i0;
  i0 = l66;
  i1 = l67;
  i0 &= i1;
  l68 = i0;
  i0 = l68;
  i0 = !(i0);
  if (i0) {goto B8;}
  B9:;
  i0 = 0u;
  l69 = i0;
  i0 = l5;
  i1 = l69;
  i32_store(Z_envZ_memory, (u64)(i0 + 300), i1);
  goto B7;
  B8:;
  i0 = 0u;
  l70 = i0;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l71 = i0;
  i0 = 2u;
  l72 = i0;
  i0 = l71;
  i1 = l72;
  i0 >>= (i1 & 31);
  l73 = i0;
  i0 = 3u;
  l74 = i0;
  i0 = l73;
  i1 = l74;
  i0 *= i1;
  l75 = i0;
  i0 = l5;
  i1 = l75;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
  l76 = i0;
  i0 = l76;
  i0 = malloc(i0);
  l77 = i0;
  i0 = l5;
  i1 = l77;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  i0 = l5;
  i1 = l77;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 28));
  l78 = i0;
  i0 = l78;
  l79 = i0;
  i0 = l70;
  l80 = i0;
  i0 = l79;
  i1 = l80;
  i0 = i0 == i1;
  l81 = i0;
  i0 = 1u;
  l82 = i0;
  i0 = l81;
  i1 = l82;
  i0 &= i1;
  l83 = i0;
  i0 = l83;
  i0 = !(i0);
  if (i0) {goto B10;}
  i0 = 0u;
  l84 = i0;
  i0 = l5;
  i1 = l84;
  i32_store(Z_envZ_memory, (u64)(i0 + 300), i1);
  goto B7;
  B10:;
  i0 = 0u;
  l85 = i0;
  i0 = l5;
  i1 = l85;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l5;
  i1 = l85;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  L12: 
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l86 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 292));
    l87 = i0;
    i0 = l86;
    l88 = i0;
    i0 = l87;
    l89 = i0;
    i0 = l88;
    i1 = l89;
    i0 = i0 < i1;
    l90 = i0;
    i0 = 1u;
    l91 = i0;
    i0 = l90;
    i1 = l91;
    i0 &= i1;
    l92 = i0;
    i0 = l92;
    i0 = !(i0);
    if (i0) {goto B11;}
    i0 = 128u;
    l93 = i0;
    i0 = 32u;
    l94 = i0;
    i0 = l5;
    i1 = l94;
    i0 += i1;
    l95 = i0;
    i0 = l95;
    l96 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 296));
    l97 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l98 = i0;
    i0 = l97;
    i1 = l98;
    i0 += i1;
    l99 = i0;
    i0 = l99;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
    l100 = i0;
    i0 = 255u;
    l101 = i0;
    i0 = l100;
    i1 = l101;
    i0 &= i1;
    l102 = i0;
    i0 = l96;
    i1 = l102;
    i0 += i1;
    l103 = i0;
    i0 = l103;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
    l104 = i0;
    i0 = l5;
    i1 = l104;
    i32_store8(Z_envZ_memory, (u64)(i0 + 19), i1);
    i0 = l5;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 19));
    l105 = i0;
    i0 = 255u;
    l106 = i0;
    i0 = l105;
    i1 = l106;
    i0 &= i1;
    l107 = i0;
    i0 = l107;
    l108 = i0;
    i0 = l93;
    l109 = i0;
    i0 = l108;
    i1 = l109;
    i0 = i0 == i1;
    l110 = i0;
    i0 = 1u;
    l111 = i0;
    i0 = l110;
    i1 = l111;
    i0 &= i1;
    l112 = i0;
    i0 = l112;
    i0 = !(i0);
    if (i0) {goto B14;}
    goto B13;
    B14:;
    i0 = 61u;
    l113 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 296));
    l114 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l115 = i0;
    i0 = l114;
    i1 = l115;
    i0 += i1;
    l116 = i0;
    i0 = l116;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
    l117 = i0;
    i0 = 255u;
    l118 = i0;
    i0 = l117;
    i1 = l118;
    i0 &= i1;
    l119 = i0;
    i0 = l119;
    l120 = i0;
    i0 = l113;
    l121 = i0;
    i0 = l120;
    i1 = l121;
    i0 = i0 == i1;
    l122 = i0;
    i0 = 1u;
    l123 = i0;
    i0 = l122;
    i1 = l123;
    i0 &= i1;
    l124 = i0;
    i0 = l124;
    i0 = !(i0);
    if (i0) {goto B15;}
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l125 = i0;
    i0 = 1u;
    l126 = i0;
    i0 = l125;
    i1 = l126;
    i0 += i1;
    l127 = i0;
    i0 = l5;
    i1 = l127;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    B15:;
    i0 = 4u;
    l128 = i0;
    i0 = 20u;
    l129 = i0;
    i0 = l5;
    i1 = l129;
    i0 += i1;
    l130 = i0;
    i0 = l130;
    l131 = i0;
    i0 = l5;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 19));
    l132 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
    l133 = i0;
    i0 = l131;
    i1 = l133;
    i0 += i1;
    l134 = i0;
    i0 = l134;
    i1 = l132;
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
    l135 = i0;
    i0 = 1u;
    l136 = i0;
    i0 = l135;
    i1 = l136;
    i0 += i1;
    l137 = i0;
    i0 = l5;
    i1 = l137;
    i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
    l138 = i0;
    i0 = l138;
    l139 = i0;
    i0 = l128;
    l140 = i0;
    i0 = l139;
    i1 = l140;
    i0 = i0 == i1;
    l141 = i0;
    i0 = 1u;
    l142 = i0;
    i0 = l141;
    i1 = l142;
    i0 &= i1;
    l143 = i0;
    i0 = l143;
    i0 = !(i0);
    if (i0) {goto B16;}
    i0 = 0u;
    l144 = i0;
    i0 = l5;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 20));
    l145 = i0;
    i0 = 255u;
    l146 = i0;
    i0 = l145;
    i1 = l146;
    i0 &= i1;
    l147 = i0;
    i0 = 2u;
    l148 = i0;
    i0 = l147;
    i1 = l148;
    i0 <<= (i1 & 31);
    l149 = i0;
    i0 = l5;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 21));
    l150 = i0;
    i0 = 255u;
    l151 = i0;
    i0 = l150;
    i1 = l151;
    i0 &= i1;
    l152 = i0;
    i0 = 4u;
    l153 = i0;
    i0 = l152;
    i1 = l153;
    i0 = (u32)((s32)i0 >> (i1 & 31));
    l154 = i0;
    i0 = l149;
    i1 = l154;
    i0 |= i1;
    l155 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
    l156 = i0;
    i0 = 1u;
    l157 = i0;
    i0 = l156;
    i1 = l157;
    i0 += i1;
    l158 = i0;
    i0 = l5;
    i1 = l158;
    i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
    i0 = l156;
    i1 = l155;
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    i0 = l5;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 21));
    l159 = i0;
    i0 = 255u;
    l160 = i0;
    i0 = l159;
    i1 = l160;
    i0 &= i1;
    l161 = i0;
    i0 = 4u;
    l162 = i0;
    i0 = l161;
    i1 = l162;
    i0 <<= (i1 & 31);
    l163 = i0;
    i0 = l5;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 22));
    l164 = i0;
    i0 = 255u;
    l165 = i0;
    i0 = l164;
    i1 = l165;
    i0 &= i1;
    l166 = i0;
    i0 = 2u;
    l167 = i0;
    i0 = l166;
    i1 = l167;
    i0 = (u32)((s32)i0 >> (i1 & 31));
    l168 = i0;
    i0 = l163;
    i1 = l168;
    i0 |= i1;
    l169 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
    l170 = i0;
    i0 = 1u;
    l171 = i0;
    i0 = l170;
    i1 = l171;
    i0 += i1;
    l172 = i0;
    i0 = l5;
    i1 = l172;
    i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
    i0 = l170;
    i1 = l169;
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    i0 = l5;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 22));
    l173 = i0;
    i0 = 255u;
    l174 = i0;
    i0 = l173;
    i1 = l174;
    i0 &= i1;
    l175 = i0;
    i0 = 6u;
    l176 = i0;
    i0 = l175;
    i1 = l176;
    i0 <<= (i1 & 31);
    l177 = i0;
    i0 = l5;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 23));
    l178 = i0;
    i0 = 255u;
    l179 = i0;
    i0 = l178;
    i1 = l179;
    i0 &= i1;
    l180 = i0;
    i0 = l177;
    i1 = l180;
    i0 |= i1;
    l181 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
    l182 = i0;
    i0 = 1u;
    l183 = i0;
    i0 = l182;
    i1 = l183;
    i0 += i1;
    l184 = i0;
    i0 = l5;
    i1 = l184;
    i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
    i0 = l182;
    i1 = l181;
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    i0 = l5;
    i1 = l144;
    i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l185 = i0;
    i0 = l185;
    i0 = !(i0);
    if (i0) {goto B17;}
    i0 = 1u;
    l186 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l187 = i0;
    i0 = l187;
    l188 = i0;
    i0 = l186;
    l189 = i0;
    i0 = l188;
    i1 = l189;
    i0 = i0 == i1;
    l190 = i0;
    i0 = 1u;
    l191 = i0;
    i0 = l190;
    i1 = l191;
    i0 &= i1;
    l192 = i0;
    i0 = l192;
    i0 = !(i0);
    if (i0) {goto B19;}
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
    l193 = i0;
    i0 = 4294967295u;
    l194 = i0;
    i0 = l193;
    i1 = l194;
    i0 += i1;
    l195 = i0;
    i0 = l5;
    i1 = l195;
    i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
    goto B18;
    B19:;
    i0 = 2u;
    l196 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l197 = i0;
    i0 = l197;
    l198 = i0;
    i0 = l196;
    l199 = i0;
    i0 = l198;
    i1 = l199;
    i0 = i0 == i1;
    l200 = i0;
    i0 = 1u;
    l201 = i0;
    i0 = l200;
    i1 = l201;
    i0 &= i1;
    l202 = i0;
    i0 = l202;
    i0 = !(i0);
    if (i0) {goto B21;}
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
    l203 = i0;
    i0 = 4294967294u;
    l204 = i0;
    i0 = l203;
    i1 = l204;
    i0 += i1;
    l205 = i0;
    i0 = l5;
    i1 = l205;
    i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
    goto B20;
    B21:;
    i0 = 0u;
    l206 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 28));
    l207 = i0;
    i0 = l207;
    free(i0);
    i0 = l5;
    i1 = l206;
    i32_store(Z_envZ_memory, (u64)(i0 + 300), i1);
    goto B7;
    B20:;
    B18:;
    goto B11;
    B17:;
    B16:;
    B13:;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l208 = i0;
    i0 = 1u;
    l209 = i0;
    i0 = l208;
    i1 = l209;
    i0 += i1;
    l210 = i0;
    i0 = l5;
    i1 = l210;
    i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
    goto L12;
  UNREACHABLE;
  B11:;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
  l211 = i0;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 28));
  l212 = i0;
  i0 = l211;
  i1 = l212;
  i0 -= i1;
  l213 = i0;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 288));
  l214 = i0;
  i0 = l214;
  i1 = l213;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 28));
  l215 = i0;
  i0 = l5;
  i1 = l215;
  i32_store(Z_envZ_memory, (u64)(i0 + 300), i1);
  B7:;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 300));
  l216 = i0;
  i0 = 304u;
  l217 = i0;
  i0 = l5;
  i1 = l217;
  i0 += i1;
  l218 = i0;
  i0 = l218;
  l220 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l220;
  g0 = i0;
  i0 = l216;
  goto Bfunc;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static void f8(void) {
  u32 l0 = 0, l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0, l6 = 0, l7 = 0, 
      l8 = 0, l9 = 0, l10 = 0, l11 = 0, l12 = 0, l13 = 0, l14 = 0, l15 = 0, 
      l16 = 0, l17 = 0, l18 = 0, l19 = 0, l20 = 0, l21 = 0, l22 = 0, l23 = 0, 
      l24 = 0, l25 = 0, l26 = 0, l27 = 0, l28 = 0, l29 = 0, l30 = 0, l31 = 0, 
      l32 = 0, l33 = 0, l34 = 0, l35 = 0, l36 = 0, l37 = 0, l38 = 0, l39 = 0, 
      l40 = 0, l41 = 0, l42 = 0, l43 = 0, l44 = 0, l45 = 0, l46 = 0, l47 = 0, 
      l48 = 0, l49 = 0, l50 = 0, l51 = 0, l52 = 0, l53 = 0, l54 = 0, l55 = 0, 
      l56 = 0, l57 = 0, l58 = 0, l59 = 0, l60 = 0, l61 = 0, l62 = 0, l63 = 0, 
      l64 = 0, l65 = 0, l66 = 0, l67 = 0, l68 = 0, l69 = 0, l70 = 0, l71 = 0, 
      l72 = 0, l73 = 0, l74 = 0, l75 = 0, l76 = 0, l77 = 0, l78 = 0, l79 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1;
  i0 = 0u;
  l0 = i0;
  i0 = l0;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1648));
  l1 = i0;
  i0 = 24u;
  l2 = i0;
  i0 = l1;
  i1 = l2;
  i0 <<= (i1 & 31);
  l3 = i0;
  i0 = l3;
  i1 = l2;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  l4 = i0;
  i0 = 222u;
  l5 = i0;
  i0 = l4;
  i1 = l5;
  i0 ^= i1;
  l6 = i0;
  i0 = 0u;
  l7 = i0;
  i0 = l7;
  i1 = l6;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1648), i1);
  i0 = 0u;
  l8 = i0;
  i0 = l8;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1649));
  l9 = i0;
  i0 = 24u;
  l10 = i0;
  i0 = l9;
  i1 = l10;
  i0 <<= (i1 & 31);
  l11 = i0;
  i0 = l11;
  i1 = l10;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  l12 = i0;
  i0 = 73u;
  l13 = i0;
  i0 = l12;
  i1 = l13;
  i0 ^= i1;
  l14 = i0;
  i0 = 0u;
  l15 = i0;
  i0 = l15;
  i1 = l14;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1649), i1);
  i0 = 0u;
  l16 = i0;
  i0 = l16;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1650));
  l17 = i0;
  i0 = 24u;
  l18 = i0;
  i0 = l17;
  i1 = l18;
  i0 <<= (i1 & 31);
  l19 = i0;
  i0 = l19;
  i1 = l18;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  l20 = i0;
  i0 = 5u;
  l21 = i0;
  i0 = l20;
  i1 = l21;
  i0 ^= i1;
  l22 = i0;
  i0 = 0u;
  l23 = i0;
  i0 = l23;
  i1 = l22;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1650), i1);
  i0 = 0u;
  l24 = i0;
  i0 = l24;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1651));
  l25 = i0;
  i0 = 24u;
  l26 = i0;
  i0 = l25;
  i1 = l26;
  i0 <<= (i1 & 31);
  l27 = i0;
  i0 = l27;
  i1 = l26;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  l28 = i0;
  i0 = 88u;
  l29 = i0;
  i0 = l28;
  i1 = l29;
  i0 ^= i1;
  l30 = i0;
  i0 = 0u;
  l31 = i0;
  i0 = l31;
  i1 = l30;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1651), i1);
  i0 = 0u;
  l32 = i0;
  i0 = l32;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1652));
  l33 = i0;
  i0 = 24u;
  l34 = i0;
  i0 = l33;
  i1 = l34;
  i0 <<= (i1 & 31);
  l35 = i0;
  i0 = l35;
  i1 = l34;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  l36 = i0;
  i0 = 125u;
  l37 = i0;
  i0 = l36;
  i1 = l37;
  i0 ^= i1;
  l38 = i0;
  i0 = 0u;
  l39 = i0;
  i0 = l39;
  i1 = l38;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1652), i1);
  i0 = 0u;
  l40 = i0;
  i0 = l40;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1653));
  l41 = i0;
  i0 = 24u;
  l42 = i0;
  i0 = l41;
  i1 = l42;
  i0 <<= (i1 & 31);
  l43 = i0;
  i0 = l43;
  i1 = l42;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  l44 = i0;
  i0 = 114u;
  l45 = i0;
  i0 = l44;
  i1 = l45;
  i0 ^= i1;
  l46 = i0;
  i0 = 0u;
  l47 = i0;
  i0 = l47;
  i1 = l46;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1653), i1);
  i0 = 0u;
  l48 = i0;
  i0 = l48;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1654));
  l49 = i0;
  i0 = 24u;
  l50 = i0;
  i0 = l49;
  i1 = l50;
  i0 <<= (i1 & 31);
  l51 = i0;
  i0 = l51;
  i1 = l50;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  l52 = i0;
  i0 = 113u;
  l53 = i0;
  i0 = l52;
  i1 = l53;
  i0 ^= i1;
  l54 = i0;
  i0 = 0u;
  l55 = i0;
  i0 = l55;
  i1 = l54;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1654), i1);
  i0 = 0u;
  l56 = i0;
  i0 = l56;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1655));
  l57 = i0;
  i0 = 24u;
  l58 = i0;
  i0 = l57;
  i1 = l58;
  i0 <<= (i1 & 31);
  l59 = i0;
  i0 = l59;
  i1 = l58;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  l60 = i0;
  i0 = 101u;
  l61 = i0;
  i0 = l60;
  i1 = l61;
  i0 ^= i1;
  l62 = i0;
  i0 = 0u;
  l63 = i0;
  i0 = l63;
  i1 = l62;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1655), i1);
  i0 = 0u;
  l64 = i0;
  i0 = l64;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1656));
  l65 = i0;
  i0 = 24u;
  l66 = i0;
  i0 = l65;
  i1 = l66;
  i0 <<= (i1 & 31);
  l67 = i0;
  i0 = l67;
  i1 = l66;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  l68 = i0;
  i0 = 109u;
  l69 = i0;
  i0 = l68;
  i1 = l69;
  i0 ^= i1;
  l70 = i0;
  i0 = 0u;
  l71 = i0;
  i0 = l71;
  i1 = l70;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1656), i1);
  i0 = 0u;
  l72 = i0;
  i0 = l72;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1657));
  l73 = i0;
  i0 = 24u;
  l74 = i0;
  i0 = l73;
  i1 = l74;
  i0 <<= (i1 & 31);
  l75 = i0;
  i0 = l75;
  i1 = l74;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  l76 = i0;
  i0 = 125u;
  l77 = i0;
  i0 = l76;
  i1 = l77;
  i0 ^= i1;
  l78 = i0;
  i0 = 0u;
  l79 = i0;
  i0 = l79;
  i1 = l78;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1657), i1);
  goto Bfunc;
  Bfunc:;
  FUNC_EPILOGUE;
}

static u32 f9(u32 p0, u32 p1) {
  u32 l2 = 0, l3 = 0, l4 = 0, l5 = 0, l6 = 0, l7 = 0, l8 = 0, l9 = 0, 
      l10 = 0, l11 = 0, l12 = 0, l13 = 0, l14 = 0, l15 = 0, l16 = 0, l17 = 0, 
      l18 = 0, l19 = 0, l20 = 0, l21 = 0, l22 = 0, l23 = 0, l24 = 0, l25 = 0, 
      l26 = 0, l27 = 0, l28 = 0, l29 = 0, l30 = 0, l31 = 0, l32 = 0, l33 = 0, 
      l34 = 0, l35 = 0, l36 = 0, l37 = 0, l38 = 0, l39 = 0, l40 = 0, l41 = 0, 
      l42 = 0, l43 = 0, l44 = 0, l45 = 0, l46 = 0, l47 = 0, l48 = 0, l49 = 0, 
      l50 = 0, l51 = 0, l52 = 0, l53 = 0, l54 = 0, l55 = 0, l56 = 0, l57 = 0, 
      l58 = 0, l59 = 0, l60 = 0, l61 = 0, l62 = 0, l63 = 0, l64 = 0, l65 = 0, 
      l66 = 0, l67 = 0, l68 = 0, l69 = 0, l70 = 0, l71 = 0, l72 = 0, l73 = 0, 
      l74 = 0, l75 = 0, l76 = 0, l77 = 0, l78 = 0, l79 = 0, l80 = 0, l81 = 0, 
      l82 = 0, l83 = 0, l84 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  i0 = g0;
  l2 = i0;
  i0 = 48u;
  l3 = i0;
  i0 = l2;
  i1 = l3;
  i0 -= i1;
  l4 = i0;
  i0 = l4;
  l83 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l83;
  g0 = i0;
  i0 = 1648u;
  l5 = i0;
  i0 = 10u;
  l6 = i0;
  i0 = 32u;
  l7 = i0;
  i0 = l4;
  i1 = l7;
  i0 += i1;
  l8 = i0;
  i0 = l8;
  l9 = i0;
  i0 = 255u;
  l10 = i0;
  i0 = l4;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 40), i1);
  i0 = l4;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 36), i1);
  i0 = l4;
  i1 = l10;
  i32_store(Z_envZ_memory, (u64)(i0 + 32), i1);
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 40));
  l11 = i0;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 40));
  l12 = i0;
  i0 = l12;
  i0 = f54(i0);
  l13 = i0;
  i0 = l11;
  i1 = l13;
  i2 = l9;
  i0 = f7(i0, i1, i2);
  l14 = i0;
  i0 = l4;
  i1 = l14;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 36));
  l15 = i0;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 36));
  l16 = i0;
  i0 = l16;
  i0 = f54(i0);
  l17 = i0;
  i0 = l15;
  i1 = l17;
  i2 = l9;
  i0 = f7(i0, i1, i2);
  l18 = i0;
  i0 = l4;
  i1 = l18;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
  l19 = i0;
  i0 = l19;
  i1 = l5;
  i2 = l6;
  i0 = f11(i0, i1, i2);
  l20 = i0;
  i0 = l4;
  i1 = l20;
  i32_store(Z_envZ_memory, (u64)(i0 + 20), i1);
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 20));
  l21 = i0;
  i0 = l21;
  i0 = !(i0);
  if (i0) {goto B3;}
  i0 = 4294967294u;
  l22 = i0;
  i0 = l4;
  i1 = l22;
  i32_store(Z_envZ_memory, (u64)(i0 + 44), i1);
  goto B2;
  B3:;
  i0 = 10u;
  l23 = i0;
  i0 = 1u;
  l24 = i0;
  i0 = l4;
  i1 = l24;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = l4;
  i1 = l23;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 28));
  l25 = i0;
  i0 = l25;
  i0 = f54(i0);
  l26 = i0;
  i0 = l4;
  i1 = l26;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
  l27 = i0;
  i0 = l27;
  i0 = f54(i0);
  l28 = i0;
  i0 = l4;
  i1 = l28;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  L4: 
    i0 = 0u;
    l29 = i0;
    i0 = l4;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l30 = i0;
    i0 = l4;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
    l31 = i0;
    i0 = l30;
    l32 = i0;
    i0 = l31;
    l33 = i0;
    i0 = l32;
    i1 = l33;
    i0 = i0 < i1;
    l34 = i0;
    i0 = 1u;
    l35 = i0;
    i0 = l34;
    i1 = l35;
    i0 &= i1;
    l36 = i0;
    i0 = l29;
    l37 = i0;
    i0 = l36;
    i0 = !(i0);
    if (i0) {goto B5;}
    i0 = l4;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l38 = i0;
    i0 = l4;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
    l39 = i0;
    i0 = l38;
    l40 = i0;
    i0 = l39;
    l41 = i0;
    i0 = l40;
    i1 = l41;
    i0 = i0 < i1;
    l42 = i0;
    i0 = l42;
    l37 = i0;
    B5:;
    i0 = l37;
    l43 = i0;
    i0 = 1u;
    l44 = i0;
    i0 = l43;
    i1 = l44;
    i0 &= i1;
    l45 = i0;
    i0 = l45;
    i0 = !(i0);
    if (i0) {goto B6;}
    i0 = l4;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 28));
    l46 = i0;
    i0 = l4;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l47 = i0;
    i0 = l46;
    i1 = l47;
    i0 += i1;
    l48 = i0;
    i0 = l48;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
    l49 = i0;
    i0 = 24u;
    l50 = i0;
    i0 = l49;
    i1 = l50;
    i0 <<= (i1 & 31);
    l51 = i0;
    i0 = l51;
    i1 = l50;
    i0 = (u32)((s32)i0 >> (i1 & 31));
    l52 = i0;
    i0 = l4;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
    l53 = i0;
    i0 = l4;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l54 = i0;
    i0 = l53;
    i1 = l54;
    i0 += i1;
    l55 = i0;
    i0 = l55;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
    l56 = i0;
    i0 = 24u;
    l57 = i0;
    i0 = l56;
    i1 = l57;
    i0 <<= (i1 & 31);
    l58 = i0;
    i0 = l58;
    i1 = l57;
    i0 = (u32)((s32)i0 >> (i1 & 31));
    l59 = i0;
    i0 = l52;
    l60 = i0;
    i0 = l59;
    l61 = i0;
    i0 = l60;
    i1 = l61;
    i0 = i0 != i1;
    l62 = i0;
    i0 = 1u;
    l63 = i0;
    i0 = l62;
    i1 = l63;
    i0 &= i1;
    l64 = i0;
    i0 = l64;
    i0 = !(i0);
    if (i0) {goto B7;}
    goto B6;
    B7:;
    i0 = l4;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
    l65 = i0;
    i0 = 1u;
    l66 = i0;
    i0 = l65;
    i1 = l66;
    i0 += i1;
    l67 = i0;
    i0 = l4;
    i1 = l67;
    i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
    i0 = l4;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
    l68 = i0;
    i0 = 1u;
    l69 = i0;
    i0 = l68;
    i1 = l69;
    i0 += i1;
    l70 = i0;
    i0 = l4;
    i1 = l70;
    i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
    goto L4;
    B6:;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  l71 = i0;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l72 = i0;
  i0 = l71;
  l73 = i0;
  i0 = l72;
  l74 = i0;
  i0 = l73;
  i1 = l74;
  i0 = i0 == i1;
  l75 = i0;
  i0 = 1u;
  l76 = i0;
  i0 = l75;
  i1 = l76;
  i0 &= i1;
  l77 = i0;
  i0 = l77;
  i0 = !(i0);
  if (i0) {goto B8;}
  i0 = 4294967295u;
  l78 = i0;
  i0 = l4;
  i1 = l78;
  i32_store(Z_envZ_memory, (u64)(i0 + 44), i1);
  goto B2;
  B8:;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
  l79 = i0;
  i0 = l4;
  i1 = l79;
  i32_store(Z_envZ_memory, (u64)(i0 + 44), i1);
  B2:;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 44));
  l80 = i0;
  i0 = 48u;
  l81 = i0;
  i0 = l4;
  i1 = l81;
  i0 += i1;
  l82 = i0;
  i0 = l82;
  l84 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l84;
  g0 = i0;
  i0 = l80;
  goto Bfunc;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static u32 main(u32 p0, u32 p1) {
  u32 l2 = 0, l3 = 0, l4 = 0, l5 = 0, l6 = 0, l7 = 0, l8 = 0, l9 = 0, 
      l10 = 0, l11 = 0, l12 = 0, l13 = 0, l14 = 0, l15 = 0, l16 = 0, l17 = 0, 
      l18 = 0, l19 = 0, l20 = 0, l21 = 0, l22 = 0, l23 = 0, l24 = 0, l25 = 0, 
      l26 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1;
  i0 = g0;
  l2 = i0;
  i0 = 32u;
  l3 = i0;
  i0 = l2;
  i1 = l3;
  i0 -= i1;
  l4 = i0;
  i0 = l4;
  l25 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l25;
  g0 = i0;
  i0 = 3u;
  l5 = i0;
  i0 = 0u;
  l6 = i0;
  i0 = l4;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  i0 = l4;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  i0 = l4;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 20), i1);
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
  l7 = i0;
  i0 = l7;
  l8 = i0;
  i0 = l5;
  l9 = i0;
  i0 = l8;
  i1 = l9;
  i0 = (u32)((s32)i0 < (s32)i1);
  l10 = i0;
  i0 = 1u;
  l11 = i0;
  i0 = l10;
  i1 = l11;
  i0 &= i1;
  l12 = i0;
  i0 = l12;
  i0 = !(i0);
  if (i0) {goto B3;}
  i0 = 1u;
  l13 = i0;
  i0 = l4;
  i1 = l13;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  goto B2;
  B3:;
  f8();
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 20));
  l14 = i0;
  i0 = l14;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
  l15 = i0;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 20));
  l16 = i0;
  i0 = l16;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l17 = i0;
  i0 = l15;
  i1 = l17;
  i0 = f9(i0, i1);
  l18 = i0;
  i0 = l4;
  i1 = l18;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
  l19 = i0;
  i0 = l4;
  i1 = l19;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = 1089u;
  l20 = i0;
  i0 = l20;
  i1 = l4;
  i0 = f51(i0, i1);
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
  l21 = i0;
  i0 = l4;
  i1 = l21;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  B2:;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 28));
  l22 = i0;
  i0 = 32u;
  l23 = i0;
  i0 = l4;
  i1 = l23;
  i0 += i1;
  l24 = i0;
  i0 = l24;
  l26 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l26;
  g0 = i0;
  i0 = l22;
  goto Bfunc;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f11(u32 p0, u32 p1, u32 p2) {
  u32 l3 = 0, l4 = 0, l5 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1;
  i0 = p2;
  if (i0) {goto B0;}
  i0 = 0u;
  goto Bfunc;
  B0:;
  i0 = 0u;
  l3 = i0;
  i0 = p0;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
  l4 = i0;
  i0 = !(i0);
  if (i0) {goto B1;}
  L3: 
    i0 = l4;
    i1 = 255u;
    i0 &= i1;
    i1 = p1;
    i1 = i32_load8_u(Z_envZ_memory, (u64)(i1));
    l5 = i1;
    i0 = i0 != i1;
    if (i0) {goto B2;}
    i0 = p2;
    i1 = 4294967295u;
    i0 += i1;
    p2 = i0;
    i0 = !(i0);
    if (i0) {goto B2;}
    i0 = l5;
    i0 = !(i0);
    if (i0) {goto B2;}
    i0 = p1;
    i1 = 1u;
    i0 += i1;
    p1 = i0;
    i0 = p0;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1));
    l4 = i0;
    i0 = p0;
    i1 = 1u;
    i0 += i1;
    p0 = i0;
    i0 = l4;
    if (i0) {goto L3;}
    goto B1;
  UNREACHABLE;
  B2:;
  i0 = l4;
  l3 = i0;
  B1:;
  i0 = l3;
  i1 = 255u;
  i0 &= i1;
  i1 = p1;
  i1 = i32_load8_u(Z_envZ_memory, (u64)(i1));
  i0 -= i1;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static u32 __errno_location(void) {
  FUNC_PROLOGUE;
  u32 i0;
  i0 = 2048u;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f13(u32 p0) {
  FUNC_PROLOGUE;
  u32 i0, i1;
  i0 = p0;
  if (i0) {goto B0;}
  i0 = 0u;
  goto Bfunc;
  B0:;
  i0 = __errno_location();
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = 4294967295u;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f14(u32 p0, u32 p1, u32 p2) {
  u32 l3 = 0, l4 = 0, l5 = 0, l6 = 0, l7 = 0, l8 = 0, l9 = 0, l10 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3, i4, i5;
  u64 j1;
  i0 = g0;
  i1 = 32u;
  i0 -= i1;
  l3 = i0;
  l9 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l9;
  g0 = i0;
  i0 = l3;
  i1 = p0;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 28));
  l4 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 20));
  l5 = i0;
  i0 = l3;
  i1 = p2;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  i0 = l3;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  i0 = l3;
  i1 = l5;
  i2 = l4;
  i1 -= i2;
  p1 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 20), i1);
  i0 = p1;
  i1 = p2;
  i0 += i1;
  l5 = i0;
  i0 = 2u;
  l6 = i0;
  i0 = l3;
  i1 = 16u;
  i0 += i1;
  p1 = i0;
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 60));
  i1 = l3;
  i2 = 16u;
  i1 += i2;
  i2 = 2u;
  i3 = l3;
  i4 = 12u;
  i3 += i4;
  i0 = (*Z_wasi_snapshot_preview1Z_fd_writeZ_iiiii)(i0, i1, i2, i3);
  i0 = f13(i0);
  if (i0) {goto B5;}
  L6: 
    i0 = l5;
    i1 = l3;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 12));
    l4 = i1;
    i0 = i0 == i1;
    if (i0) {goto B4;}
    i0 = l4;
    i1 = 4294967295u;
    i0 = (u32)((s32)i0 <= (s32)i1);
    if (i0) {goto B3;}
    i0 = p1;
    i1 = 8u;
    i0 += i1;
    i1 = p1;
    i2 = l4;
    i3 = p1;
    i3 = i32_load(Z_envZ_memory, (u64)(i3 + 4));
    l7 = i3;
    i2 = i2 > i3;
    l8 = i2;
    i0 = i2 ? i0 : i1;
    p1 = i0;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1));
    i2 = l4;
    i3 = l7;
    i4 = 0u;
    i5 = l8;
    i3 = i5 ? i3 : i4;
    i2 -= i3;
    l7 = i2;
    i1 += i2;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    i0 = p1;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 4));
    i2 = l7;
    i1 -= i2;
    i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
    i0 = l5;
    i1 = l4;
    i0 -= i1;
    l5 = i0;
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 60));
    i1 = p1;
    i2 = l6;
    i3 = l8;
    i2 -= i3;
    l6 = i2;
    i3 = l3;
    i4 = 12u;
    i3 += i4;
    i0 = (*Z_wasi_snapshot_preview1Z_fd_writeZ_iiiii)(i0, i1, i2, i3);
    i0 = f13(i0);
    i0 = !(i0);
    if (i0) {goto L6;}
  B5:;
  i0 = l3;
  i1 = 4294967295u;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l5;
  i1 = 4294967295u;
  i0 = i0 != i1;
  if (i0) {goto B3;}
  B4:;
  i0 = p0;
  i1 = p0;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 44));
  p1 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  i0 = p0;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 20), i1);
  i0 = p0;
  i1 = p1;
  i2 = p0;
  i2 = i32_load(Z_envZ_memory, (u64)(i2 + 48));
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = p2;
  l4 = i0;
  goto B2;
  B3:;
  i0 = 0u;
  l4 = i0;
  i0 = p0;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  i0 = p0;
  j1 = 0ull;
  i64_store(Z_envZ_memory, (u64)(i0 + 16), j1);
  i0 = p0;
  i1 = p0;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  i2 = 32u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l6;
  i1 = 2u;
  i0 = i0 == i1;
  if (i0) {goto B2;}
  i0 = p2;
  i1 = p1;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 4));
  i0 -= i1;
  l4 = i0;
  B2:;
  i0 = l3;
  i1 = 32u;
  i0 += i1;
  l10 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l10;
  g0 = i0;
  i0 = l4;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f15(u32 p0) {
  FUNC_PROLOGUE;
  u32 i0, i1;
  i0 = p0;
  i1 = 4294967248u;
  i0 += i1;
  i1 = 10u;
  i0 = i0 < i1;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f16(void) {
  FUNC_PROLOGUE;
  u32 i0;
  i0 = 1660u;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f17(u32 p0, u32 p1, u32 p2) {
  u32 l3 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  i0 = 1u;
  l3 = i0;
  i0 = p0;
  i0 = !(i0);
  if (i0) {goto B1;}
  i0 = p1;
  i1 = 127u;
  i0 = i0 <= i1;
  if (i0) {goto B0;}
  i0 = f18();
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 176));
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  if (i0) {goto B3;}
  i0 = p1;
  i1 = 4294967168u;
  i0 &= i1;
  i1 = 57216u;
  i0 = i0 == i1;
  if (i0) {goto B0;}
  i0 = __errno_location();
  i1 = 25u;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  goto B2;
  B3:;
  i0 = p1;
  i1 = 2047u;
  i0 = i0 > i1;
  if (i0) {goto B4;}
  i0 = p0;
  i1 = p1;
  i2 = 63u;
  i1 &= i2;
  i2 = 128u;
  i1 |= i2;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1), i1);
  i0 = p0;
  i1 = p1;
  i2 = 6u;
  i1 >>= (i2 & 31);
  i2 = 192u;
  i1 |= i2;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = 2u;
  goto Bfunc;
  B4:;
  i0 = p1;
  i1 = 55296u;
  i0 = i0 < i1;
  if (i0) {goto B6;}
  i0 = p1;
  i1 = 4294959104u;
  i0 &= i1;
  i1 = 57344u;
  i0 = i0 != i1;
  if (i0) {goto B5;}
  B6:;
  i0 = p0;
  i1 = p1;
  i2 = 63u;
  i1 &= i2;
  i2 = 128u;
  i1 |= i2;
  i32_store8(Z_envZ_memory, (u64)(i0 + 2), i1);
  i0 = p0;
  i1 = p1;
  i2 = 12u;
  i1 >>= (i2 & 31);
  i2 = 224u;
  i1 |= i2;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  i2 = 6u;
  i1 >>= (i2 & 31);
  i2 = 63u;
  i1 &= i2;
  i2 = 128u;
  i1 |= i2;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1), i1);
  i0 = 3u;
  goto Bfunc;
  B5:;
  i0 = p1;
  i1 = 4294901760u;
  i0 += i1;
  i1 = 1048575u;
  i0 = i0 > i1;
  if (i0) {goto B7;}
  i0 = p0;
  i1 = p1;
  i2 = 63u;
  i1 &= i2;
  i2 = 128u;
  i1 |= i2;
  i32_store8(Z_envZ_memory, (u64)(i0 + 3), i1);
  i0 = p0;
  i1 = p1;
  i2 = 18u;
  i1 >>= (i2 & 31);
  i2 = 240u;
  i1 |= i2;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  i2 = 6u;
  i1 >>= (i2 & 31);
  i2 = 63u;
  i1 &= i2;
  i2 = 128u;
  i1 |= i2;
  i32_store8(Z_envZ_memory, (u64)(i0 + 2), i1);
  i0 = p0;
  i1 = p1;
  i2 = 12u;
  i1 >>= (i2 & 31);
  i2 = 63u;
  i1 &= i2;
  i2 = 128u;
  i1 |= i2;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1), i1);
  i0 = 4u;
  goto Bfunc;
  B7:;
  i0 = __errno_location();
  i1 = 25u;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  B2:;
  i0 = 4294967295u;
  l3 = i0;
  B1:;
  i0 = l3;
  goto Bfunc;
  B0:;
  i0 = p0;
  i1 = p1;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = 1u;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f18(void) {
  FUNC_PROLOGUE;
  u32 i0;
  i0 = f16();
  FUNC_EPILOGUE;
  return i0;
}

static u32 f19(u32 p0, u32 p1) {
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  i0 = p0;
  if (i0) {goto B0;}
  i0 = 0u;
  goto Bfunc;
  B0:;
  i0 = p0;
  i1 = p1;
  i2 = 0u;
  i0 = f17(i0, i1, i2);
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f20(u32 p0, u32 p1, u32 p2) {
  u32 l3 = 0, l4 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  i0 = p2;
  i1 = 0u;
  i0 = i0 != i1;
  l3 = i0;
  i0 = p2;
  i0 = !(i0);
  if (i0) {goto B3;}
  i0 = p0;
  i1 = 3u;
  i0 &= i1;
  i0 = !(i0);
  if (i0) {goto B3;}
  i0 = p1;
  i1 = 255u;
  i0 &= i1;
  l4 = i0;
  L4: 
    i0 = p0;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
    i1 = l4;
    i0 = i0 == i1;
    if (i0) {goto B2;}
    i0 = p0;
    i1 = 1u;
    i0 += i1;
    p0 = i0;
    i0 = p2;
    i1 = 4294967295u;
    i0 += i1;
    p2 = i0;
    i1 = 0u;
    i0 = i0 != i1;
    l3 = i0;
    i0 = p2;
    i0 = !(i0);
    if (i0) {goto B3;}
    i0 = p0;
    i1 = 3u;
    i0 &= i1;
    if (i0) {goto L4;}
  B3:;
  i0 = l3;
  i0 = !(i0);
  if (i0) {goto B1;}
  B2:;
  i0 = p0;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
  i1 = p1;
  i2 = 255u;
  i1 &= i2;
  i0 = i0 == i1;
  if (i0) {goto B0;}
  i0 = p2;
  i1 = 4u;
  i0 = i0 < i1;
  if (i0) {goto B6;}
  i0 = p1;
  i1 = 255u;
  i0 &= i1;
  i1 = 16843009u;
  i0 *= i1;
  l4 = i0;
  L7: 
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    i1 = l4;
    i0 ^= i1;
    l3 = i0;
    i1 = 4294967295u;
    i0 ^= i1;
    i1 = l3;
    i2 = 4278124287u;
    i1 += i2;
    i0 &= i1;
    i1 = 2155905152u;
    i0 &= i1;
    if (i0) {goto B5;}
    i0 = p0;
    i1 = 4u;
    i0 += i1;
    p0 = i0;
    i0 = p2;
    i1 = 4294967292u;
    i0 += i1;
    p2 = i0;
    i1 = 3u;
    i0 = i0 > i1;
    if (i0) {goto L7;}
  B6:;
  i0 = p2;
  i0 = !(i0);
  if (i0) {goto B1;}
  B5:;
  i0 = p1;
  i1 = 255u;
  i0 &= i1;
  l3 = i0;
  L8: 
    i0 = p0;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
    i1 = l3;
    i0 = i0 == i1;
    if (i0) {goto B0;}
    i0 = p0;
    i1 = 1u;
    i0 += i1;
    p0 = i0;
    i0 = p2;
    i1 = 4294967295u;
    i0 += i1;
    p2 = i0;
    if (i0) {goto L8;}
  B1:;
  i0 = 0u;
  goto Bfunc;
  B0:;
  i0 = p0;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static f64 f21(f64 p0, u32 p1) {
  u32 l2 = 0;
  u64 l3 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  u64 j0, j1;
  f64 d0, d1;
  d0 = p0;
  j0 = i64_reinterpret_f64(d0);
  l3 = j0;
  j1 = 52ull;
  j0 >>= (j1 & 63);
  i0 = (u32)(j0);
  i1 = 2047u;
  i0 &= i1;
  l2 = i0;
  i1 = 2047u;
  i0 = i0 == i1;
  if (i0) {goto B0;}
  i0 = l2;
  if (i0) {goto B1;}
  d0 = p0;
  d1 = 0;
  i0 = d0 != d1;
  if (i0) {goto B3;}
  i0 = 0u;
  l2 = i0;
  goto B2;
  B3:;
  d0 = p0;
  d1 = 1.8446744073709552e+19;
  d0 *= d1;
  i1 = p1;
  d0 = f21(d0, i1);
  p0 = d0;
  i0 = p1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  i1 = 4294967232u;
  i0 += i1;
  l2 = i0;
  B2:;
  i0 = p1;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  d0 = p0;
  goto Bfunc;
  B1:;
  i0 = p1;
  i1 = l2;
  i2 = 4294966274u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  j0 = l3;
  j1 = 9227875636482146303ull;
  j0 &= j1;
  j1 = 4602678819172646912ull;
  j0 |= j1;
  d0 = f64_reinterpret_i64(j0);
  p0 = d0;
  B0:;
  d0 = p0;
  Bfunc:;
  FUNC_EPILOGUE;
  return d0;
}

static void f22(u32 p0, u64 p1, u64 p2, u32 p3) {
  u64 l4 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  u64 j0, j1, j2;
  i0 = p3;
  i1 = 64u;
  i0 &= i1;
  i0 = !(i0);
  if (i0) {goto B1;}
  j0 = p1;
  i1 = p3;
  i2 = 4294967232u;
  i1 += i2;
  j1 = (u64)(i1);
  j0 <<= (j1 & 63);
  p2 = j0;
  j0 = 0ull;
  p1 = j0;
  goto B0;
  B1:;
  i0 = p3;
  i0 = !(i0);
  if (i0) {goto B0;}
  j0 = p1;
  i1 = 64u;
  i2 = p3;
  i1 -= i2;
  j1 = (u64)(i1);
  j0 >>= (j1 & 63);
  j1 = p2;
  i2 = p3;
  j2 = (u64)(i2);
  l4 = j2;
  j1 <<= (j2 & 63);
  j0 |= j1;
  p2 = j0;
  j0 = p1;
  j1 = l4;
  j0 <<= (j1 & 63);
  p1 = j0;
  B0:;
  i0 = p0;
  j1 = p1;
  i64_store(Z_envZ_memory, (u64)(i0), j1);
  i0 = p0;
  j1 = p2;
  i64_store(Z_envZ_memory, (u64)(i0 + 8), j1);
  FUNC_EPILOGUE;
}

static void f23(u32 p0, u64 p1, u64 p2, u32 p3) {
  u64 l4 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  u64 j0, j1, j2;
  i0 = p3;
  i1 = 64u;
  i0 &= i1;
  i0 = !(i0);
  if (i0) {goto B1;}
  j0 = p2;
  i1 = p3;
  i2 = 4294967232u;
  i1 += i2;
  j1 = (u64)(i1);
  j0 >>= (j1 & 63);
  p1 = j0;
  j0 = 0ull;
  p2 = j0;
  goto B0;
  B1:;
  i0 = p3;
  i0 = !(i0);
  if (i0) {goto B0;}
  j0 = p2;
  i1 = 64u;
  i2 = p3;
  i1 -= i2;
  j1 = (u64)(i1);
  j0 <<= (j1 & 63);
  j1 = p1;
  i2 = p3;
  j2 = (u64)(i2);
  l4 = j2;
  j1 >>= (j2 & 63);
  j0 |= j1;
  p1 = j0;
  j0 = p2;
  j1 = l4;
  j0 >>= (j1 & 63);
  p2 = j0;
  B0:;
  i0 = p0;
  j1 = p1;
  i64_store(Z_envZ_memory, (u64)(i0), j1);
  i0 = p0;
  j1 = p2;
  i64_store(Z_envZ_memory, (u64)(i0 + 8), j1);
  FUNC_EPILOGUE;
}

static f64 f24(u64 p0, u64 p1) {
  u32 l2 = 0, l3 = 0, l4 = 0, l5 = 0;
  u64 l6 = 0, l7 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3, i4;
  u64 j0, j1, j2, j3;
  f64 d0;
  i0 = g0;
  i1 = 32u;
  i0 -= i1;
  l2 = i0;
  l4 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l4;
  g0 = i0;
  j0 = p1;
  j1 = 9223372036854775807ull;
  j0 &= j1;
  l6 = j0;
  j1 = 14123006956457164800ull;
  j0 += j1;
  j1 = l6;
  j2 = 13547109154107162624ull;
  j1 += j2;
  i0 = j0 >= j1;
  if (i0) {goto B3;}
  j0 = p0;
  j1 = 60ull;
  j0 >>= (j1 & 63);
  j1 = p1;
  j2 = 4ull;
  j1 <<= (j2 & 63);
  j0 |= j1;
  l6 = j0;
  j0 = p0;
  j1 = 1152921504606846975ull;
  j0 &= j1;
  p0 = j0;
  j1 = 576460752303423489ull;
  i0 = j0 < j1;
  if (i0) {goto B4;}
  j0 = l6;
  j1 = 4611686018427387905ull;
  j0 += j1;
  l7 = j0;
  goto B2;
  B4:;
  j0 = l6;
  j1 = 4611686018427387904ull;
  j0 += j1;
  l7 = j0;
  j0 = p0;
  j1 = 576460752303423488ull;
  j0 ^= j1;
  j1 = 0ull;
  i0 = j0 != j1;
  if (i0) {goto B2;}
  j0 = l7;
  j1 = 1ull;
  j0 &= j1;
  j1 = l7;
  j0 += j1;
  l7 = j0;
  goto B2;
  B3:;
  j0 = p0;
  i0 = !(j0);
  j1 = l6;
  j2 = 9223090561878065152ull;
  i1 = j1 < j2;
  j2 = l6;
  j3 = 9223090561878065152ull;
  i2 = j2 == j3;
  i0 = i2 ? i0 : i1;
  if (i0) {goto B5;}
  j0 = p0;
  j1 = 60ull;
  j0 >>= (j1 & 63);
  j1 = p1;
  j2 = 4ull;
  j1 <<= (j2 & 63);
  j0 |= j1;
  j1 = 2251799813685247ull;
  j0 &= j1;
  j1 = 9221120237041090560ull;
  j0 |= j1;
  l7 = j0;
  goto B2;
  B5:;
  j0 = 9218868437227405312ull;
  l7 = j0;
  j0 = l6;
  j1 = 4899634919602388991ull;
  i0 = j0 > j1;
  if (i0) {goto B2;}
  j0 = 0ull;
  l7 = j0;
  j0 = l6;
  j1 = 48ull;
  j0 >>= (j1 & 63);
  i0 = (u32)(j0);
  l3 = i0;
  i1 = 15249u;
  i0 = i0 < i1;
  if (i0) {goto B2;}
  i0 = l2;
  i1 = 16u;
  i0 += i1;
  j1 = p0;
  j2 = p1;
  j3 = 281474976710655ull;
  j2 &= j3;
  j3 = 281474976710656ull;
  j2 |= j3;
  l6 = j2;
  i3 = l3;
  i4 = 4294952063u;
  i3 += i4;
  f22(i0, j1, j2, i3);
  i0 = l2;
  j1 = p0;
  j2 = l6;
  i3 = 15361u;
  i4 = l3;
  i3 -= i4;
  f23(i0, j1, j2, i3);
  i0 = l2;
  j0 = i64_load(Z_envZ_memory, (u64)(i0));
  l6 = j0;
  j1 = 60ull;
  j0 >>= (j1 & 63);
  i1 = l2;
  i2 = 8u;
  i1 += i2;
  j1 = i64_load(Z_envZ_memory, (u64)(i1));
  j2 = 4ull;
  j1 <<= (j2 & 63);
  j0 |= j1;
  l7 = j0;
  j0 = l6;
  j1 = 1152921504606846975ull;
  j0 &= j1;
  i1 = l2;
  j1 = i64_load(Z_envZ_memory, (u64)(i1 + 16));
  i2 = l2;
  i3 = 16u;
  i2 += i3;
  i3 = 8u;
  i2 += i3;
  j2 = i64_load(Z_envZ_memory, (u64)(i2));
  j1 |= j2;
  j2 = 0ull;
  i1 = j1 != j2;
  j1 = (u64)(i1);
  j0 |= j1;
  l6 = j0;
  j1 = 576460752303423489ull;
  i0 = j0 < j1;
  if (i0) {goto B6;}
  j0 = l7;
  j1 = 1ull;
  j0 += j1;
  l7 = j0;
  goto B2;
  B6:;
  j0 = l6;
  j1 = 576460752303423488ull;
  j0 ^= j1;
  j1 = 0ull;
  i0 = j0 != j1;
  if (i0) {goto B2;}
  j0 = l7;
  j1 = 1ull;
  j0 &= j1;
  j1 = l7;
  j0 += j1;
  l7 = j0;
  B2:;
  i0 = l2;
  i1 = 32u;
  i0 += i1;
  l5 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l5;
  g0 = i0;
  j0 = l7;
  j1 = p1;
  j2 = 9223372036854775808ull;
  j1 &= j2;
  j0 |= j1;
  d0 = f64_reinterpret_i64(j0);
  FUNC_EPILOGUE;
  return d0;
}

static u32 f25(u32 p0, u32 p1, u32 p2, u32 p3, u32 p4) {
  u32 l5 = 0, l6 = 0, l7 = 0, l8 = 0, l9 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3, i4, i5, i6;
  i0 = g0;
  i1 = 208u;
  i0 -= i1;
  l5 = i0;
  l8 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l8;
  g0 = i0;
  i0 = l5;
  i1 = p2;
  i32_store(Z_envZ_memory, (u64)(i0 + 204), i1);
  i0 = 0u;
  p2 = i0;
  i0 = l5;
  i1 = 160u;
  i0 += i1;
  i1 = 0u;
  i2 = 40u;
  i0 = f42(i0, i1, i2);
  i0 = l5;
  i1 = l5;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 204));
  i32_store(Z_envZ_memory, (u64)(i0 + 200), i1);
  i0 = 0u;
  i1 = p1;
  i2 = l5;
  i3 = 200u;
  i2 += i3;
  i3 = l5;
  i4 = 80u;
  i3 += i4;
  i4 = l5;
  i5 = 160u;
  i4 += i5;
  i5 = p3;
  i6 = p4;
  i0 = f26(i0, i1, i2, i3, i4, i5, i6);
  i1 = 0u;
  i0 = (u32)((s32)i0 >= (s32)i1);
  if (i0) {goto B3;}
  i0 = 4294967295u;
  p1 = i0;
  goto B2;
  B3:;
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 76));
  i1 = 0u;
  i0 = (u32)((s32)i0 < (s32)i1);
  if (i0) {goto B4;}
  i0 = p0;
  i0 = f52(i0);
  p2 = i0;
  B4:;
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l6 = i0;
  i0 = p0;
  i0 = i32_load8_s(Z_envZ_memory, (u64)(i0 + 74));
  i1 = 0u;
  i0 = (u32)((s32)i0 > (s32)i1);
  if (i0) {goto B5;}
  i0 = p0;
  i1 = l6;
  i2 = 4294967263u;
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  B5:;
  i0 = l6;
  i1 = 32u;
  i0 &= i1;
  l6 = i0;
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 48));
  i0 = !(i0);
  if (i0) {goto B7;}
  i0 = p0;
  i1 = p1;
  i2 = l5;
  i3 = 200u;
  i2 += i3;
  i3 = l5;
  i4 = 80u;
  i3 += i4;
  i4 = l5;
  i5 = 160u;
  i4 += i5;
  i5 = p3;
  i6 = p4;
  i0 = f26(i0, i1, i2, i3, i4, i5, i6);
  p1 = i0;
  goto B6;
  B7:;
  i0 = p0;
  i1 = 80u;
  i32_store(Z_envZ_memory, (u64)(i0 + 48), i1);
  i0 = p0;
  i1 = l5;
  i2 = 80u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = p0;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  i0 = p0;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 20), i1);
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 44));
  l7 = i0;
  i0 = p0;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 44), i1);
  i0 = p0;
  i1 = p1;
  i2 = l5;
  i3 = 200u;
  i2 += i3;
  i3 = l5;
  i4 = 80u;
  i3 += i4;
  i4 = l5;
  i5 = 160u;
  i4 += i5;
  i5 = p3;
  i6 = p4;
  i0 = f26(i0, i1, i2, i3, i4, i5, i6);
  p1 = i0;
  i0 = l7;
  i0 = !(i0);
  if (i0) {goto B6;}
  i0 = p0;
  i1 = 0u;
  i2 = 0u;
  i3 = p0;
  i3 = i32_load(Z_envZ_memory, (u64)(i3 + 36));
  i0 = CALL_INDIRECT((*Z_envZ_table), u32 (*)(u32, u32, u32), 1, i3, i0, i1, i2);
  i0 = p0;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 48), i1);
  i0 = p0;
  i1 = l7;
  i32_store(Z_envZ_memory, (u64)(i0 + 44), i1);
  i0 = p0;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  i0 = p0;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 20));
  p3 = i0;
  i0 = p0;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 20), i1);
  i0 = p1;
  i1 = 4294967295u;
  i2 = p3;
  i0 = i2 ? i0 : i1;
  p1 = i0;
  B6:;
  i0 = p0;
  i1 = p0;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  p3 = i1;
  i2 = l6;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = 4294967295u;
  i1 = p1;
  i2 = p3;
  i3 = 32u;
  i2 &= i3;
  i0 = i2 ? i0 : i1;
  p1 = i0;
  i0 = p2;
  i0 = !(i0);
  if (i0) {goto B2;}
  i0 = p0;
  f53(i0);
  B2:;
  i0 = l5;
  i1 = 208u;
  i0 += i1;
  l9 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l9;
  g0 = i0;
  i0 = p1;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f26(u32 p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6) {
  u32 l7 = 0, l8 = 0, l9 = 0, l10 = 0, l11 = 0, l12 = 0, l13 = 0, l14 = 0, 
      l15 = 0, l16 = 0, l17 = 0, l18 = 0, l19 = 0, l20 = 0, l21 = 0, l22 = 0, 
      l23 = 0;
  u64 l24 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3, i4, i5, i6;
  u64 j0, j1, j2;
  f64 d1;
  i0 = g0;
  i1 = 80u;
  i0 -= i1;
  l7 = i0;
  l22 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l22;
  g0 = i0;
  i0 = l7;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 76), i1);
  i0 = l7;
  i1 = 55u;
  i0 += i1;
  l8 = i0;
  i0 = l7;
  i1 = 56u;
  i0 += i1;
  l9 = i0;
  i0 = 0u;
  l10 = i0;
  i0 = 0u;
  l11 = i0;
  i0 = 0u;
  p1 = i0;
  L4: 
    i0 = l11;
    i1 = 0u;
    i0 = (u32)((s32)i0 < (s32)i1);
    if (i0) {goto B5;}
    i0 = p1;
    i1 = 2147483647u;
    i2 = l11;
    i1 -= i2;
    i0 = (u32)((s32)i0 <= (s32)i1);
    if (i0) {goto B6;}
    i0 = __errno_location();
    i1 = 61u;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    i0 = 4294967295u;
    l11 = i0;
    goto B5;
    B6:;
    i0 = p1;
    i1 = l11;
    i0 += i1;
    l11 = i0;
    B5:;
    i0 = l7;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 76));
    l12 = i0;
    p1 = i0;
    i0 = l12;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
    l13 = i0;
    i0 = !(i0);
    if (i0) {goto B20;}
    L22: 
      i0 = l13;
      i1 = 255u;
      i0 &= i1;
      l13 = i0;
      if (i0) {goto B25;}
      i0 = p1;
      l13 = i0;
      goto B24;
      B25:;
      i0 = l13;
      i1 = 37u;
      i0 = i0 != i1;
      if (i0) {goto B23;}
      i0 = p1;
      l13 = i0;
      L26: 
        i0 = p1;
        i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1));
        i1 = 37u;
        i0 = i0 != i1;
        if (i0) {goto B24;}
        i0 = l7;
        i1 = p1;
        i2 = 2u;
        i1 += i2;
        l14 = i1;
        i32_store(Z_envZ_memory, (u64)(i0 + 76), i1);
        i0 = l13;
        i1 = 1u;
        i0 += i1;
        l13 = i0;
        i0 = p1;
        i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 2));
        l15 = i0;
        i0 = l14;
        p1 = i0;
        i0 = l15;
        i1 = 37u;
        i0 = i0 == i1;
        if (i0) {goto L26;}
      B24:;
      i0 = l13;
      i1 = l12;
      i0 -= i1;
      p1 = i0;
      i0 = p0;
      i0 = !(i0);
      if (i0) {goto B27;}
      i0 = p0;
      i1 = l12;
      i2 = p1;
      f27(i0, i1, i2);
      B27:;
      i0 = p1;
      if (i0) {goto L4;}
      i0 = 4294967295u;
      l16 = i0;
      i0 = 1u;
      l13 = i0;
      i0 = l7;
      i0 = i32_load(Z_envZ_memory, (u64)(i0 + 76));
      i0 = i32_load8_s(Z_envZ_memory, (u64)(i0 + 1));
      i0 = f15(i0);
      l14 = i0;
      i0 = l7;
      i0 = i32_load(Z_envZ_memory, (u64)(i0 + 76));
      p1 = i0;
      i0 = l14;
      i0 = !(i0);
      if (i0) {goto B28;}
      i0 = p1;
      i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 2));
      i1 = 36u;
      i0 = i0 != i1;
      if (i0) {goto B28;}
      i0 = p1;
      i0 = i32_load8_s(Z_envZ_memory, (u64)(i0 + 1));
      i1 = 4294967248u;
      i0 += i1;
      l16 = i0;
      i0 = 1u;
      l10 = i0;
      i0 = 3u;
      l13 = i0;
      B28:;
      i0 = l7;
      i1 = p1;
      i2 = l13;
      i1 += i2;
      p1 = i1;
      i32_store(Z_envZ_memory, (u64)(i0 + 76), i1);
      i0 = 0u;
      l13 = i0;
      i0 = p1;
      i0 = i32_load8_s(Z_envZ_memory, (u64)(i0));
      l17 = i0;
      i1 = 4294967264u;
      i0 += i1;
      l15 = i0;
      i1 = 31u;
      i0 = i0 <= i1;
      if (i0) {goto B30;}
      i0 = p1;
      l14 = i0;
      goto B29;
      B30:;
      i0 = p1;
      l14 = i0;
      i0 = 1u;
      i1 = l15;
      i0 <<= (i1 & 31);
      l15 = i0;
      i1 = 75913u;
      i0 &= i1;
      i0 = !(i0);
      if (i0) {goto B29;}
      L31: 
        i0 = l7;
        i1 = p1;
        i2 = 1u;
        i1 += i2;
        l14 = i1;
        i32_store(Z_envZ_memory, (u64)(i0 + 76), i1);
        i0 = l15;
        i1 = l13;
        i0 |= i1;
        l13 = i0;
        i0 = p1;
        i0 = i32_load8_s(Z_envZ_memory, (u64)(i0 + 1));
        l17 = i0;
        i1 = 4294967264u;
        i0 += i1;
        l15 = i0;
        i1 = 31u;
        i0 = i0 > i1;
        if (i0) {goto B29;}
        i0 = l14;
        p1 = i0;
        i0 = 1u;
        i1 = l15;
        i0 <<= (i1 & 31);
        l15 = i0;
        i1 = 75913u;
        i0 &= i1;
        if (i0) {goto L31;}
      B29:;
      i0 = l17;
      i1 = 42u;
      i0 = i0 != i1;
      if (i0) {goto B33;}
      i0 = l14;
      i0 = i32_load8_s(Z_envZ_memory, (u64)(i0 + 1));
      i0 = f15(i0);
      i0 = !(i0);
      if (i0) {goto B35;}
      i0 = l7;
      i0 = i32_load(Z_envZ_memory, (u64)(i0 + 76));
      l14 = i0;
      i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 2));
      i1 = 36u;
      i0 = i0 != i1;
      if (i0) {goto B35;}
      i0 = l14;
      i0 = i32_load8_s(Z_envZ_memory, (u64)(i0 + 1));
      i1 = 2u;
      i0 <<= (i1 & 31);
      i1 = p4;
      i0 += i1;
      i1 = 4294967104u;
      i0 += i1;
      i1 = 10u;
      i32_store(Z_envZ_memory, (u64)(i0), i1);
      i0 = l14;
      i1 = 3u;
      i0 += i1;
      p1 = i0;
      i0 = l14;
      i0 = i32_load8_s(Z_envZ_memory, (u64)(i0 + 1));
      i1 = 3u;
      i0 <<= (i1 & 31);
      i1 = p3;
      i0 += i1;
      i1 = 4294966912u;
      i0 += i1;
      i0 = i32_load(Z_envZ_memory, (u64)(i0));
      l18 = i0;
      i0 = 1u;
      l10 = i0;
      goto B34;
      B35:;
      i0 = l10;
      if (i0) {goto B3;}
      i0 = 0u;
      l10 = i0;
      i0 = 0u;
      l18 = i0;
      i0 = p0;
      i0 = !(i0);
      if (i0) {goto B36;}
      i0 = p2;
      i1 = p2;
      i1 = i32_load(Z_envZ_memory, (u64)(i1));
      p1 = i1;
      i2 = 4u;
      i1 += i2;
      i32_store(Z_envZ_memory, (u64)(i0), i1);
      i0 = p1;
      i0 = i32_load(Z_envZ_memory, (u64)(i0));
      l18 = i0;
      B36:;
      i0 = l7;
      i0 = i32_load(Z_envZ_memory, (u64)(i0 + 76));
      i1 = 1u;
      i0 += i1;
      p1 = i0;
      B34:;
      i0 = l7;
      i1 = p1;
      i32_store(Z_envZ_memory, (u64)(i0 + 76), i1);
      i0 = l18;
      i1 = 4294967295u;
      i0 = (u32)((s32)i0 > (s32)i1);
      if (i0) {goto B32;}
      i0 = 0u;
      i1 = l18;
      i0 -= i1;
      l18 = i0;
      i0 = l13;
      i1 = 8192u;
      i0 |= i1;
      l13 = i0;
      goto B32;
      B33:;
      i0 = l7;
      i1 = 76u;
      i0 += i1;
      i0 = f28(i0);
      l18 = i0;
      i1 = 0u;
      i0 = (u32)((s32)i0 < (s32)i1);
      if (i0) {goto B3;}
      i0 = l7;
      i0 = i32_load(Z_envZ_memory, (u64)(i0 + 76));
      p1 = i0;
      B32:;
      i0 = 4294967295u;
      l19 = i0;
      i0 = p1;
      i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
      i1 = 46u;
      i0 = i0 != i1;
      if (i0) {goto B37;}
      i0 = p1;
      i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1));
      i1 = 42u;
      i0 = i0 != i1;
      if (i0) {goto B38;}
      i0 = p1;
      i0 = i32_load8_s(Z_envZ_memory, (u64)(i0 + 2));
      i0 = f15(i0);
      i0 = !(i0);
      if (i0) {goto B39;}
      i0 = l7;
      i0 = i32_load(Z_envZ_memory, (u64)(i0 + 76));
      p1 = i0;
      i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 3));
      i1 = 36u;
      i0 = i0 != i1;
      if (i0) {goto B39;}
      i0 = p1;
      i0 = i32_load8_s(Z_envZ_memory, (u64)(i0 + 2));
      i1 = 2u;
      i0 <<= (i1 & 31);
      i1 = p4;
      i0 += i1;
      i1 = 4294967104u;
      i0 += i1;
      i1 = 10u;
      i32_store(Z_envZ_memory, (u64)(i0), i1);
      i0 = p1;
      i0 = i32_load8_s(Z_envZ_memory, (u64)(i0 + 2));
      i1 = 3u;
      i0 <<= (i1 & 31);
      i1 = p3;
      i0 += i1;
      i1 = 4294966912u;
      i0 += i1;
      i0 = i32_load(Z_envZ_memory, (u64)(i0));
      l19 = i0;
      i0 = l7;
      i1 = p1;
      i2 = 4u;
      i1 += i2;
      p1 = i1;
      i32_store(Z_envZ_memory, (u64)(i0 + 76), i1);
      goto B37;
      B39:;
      i0 = l10;
      if (i0) {goto B3;}
      i0 = p0;
      if (i0) {goto B41;}
      i0 = 0u;
      l19 = i0;
      goto B40;
      B41:;
      i0 = p2;
      i1 = p2;
      i1 = i32_load(Z_envZ_memory, (u64)(i1));
      p1 = i1;
      i2 = 4u;
      i1 += i2;
      i32_store(Z_envZ_memory, (u64)(i0), i1);
      i0 = p1;
      i0 = i32_load(Z_envZ_memory, (u64)(i0));
      l19 = i0;
      B40:;
      i0 = l7;
      i1 = l7;
      i1 = i32_load(Z_envZ_memory, (u64)(i1 + 76));
      i2 = 2u;
      i1 += i2;
      p1 = i1;
      i32_store(Z_envZ_memory, (u64)(i0 + 76), i1);
      goto B37;
      B38:;
      i0 = l7;
      i1 = p1;
      i2 = 1u;
      i1 += i2;
      i32_store(Z_envZ_memory, (u64)(i0 + 76), i1);
      i0 = l7;
      i1 = 76u;
      i0 += i1;
      i0 = f28(i0);
      l19 = i0;
      i0 = l7;
      i0 = i32_load(Z_envZ_memory, (u64)(i0 + 76));
      p1 = i0;
      B37:;
      i0 = 0u;
      l14 = i0;
      L42: 
        i0 = l14;
        l15 = i0;
        i0 = 4294967295u;
        l20 = i0;
        i0 = p1;
        i0 = i32_load8_s(Z_envZ_memory, (u64)(i0));
        i1 = 4294967231u;
        i0 += i1;
        i1 = 57u;
        i0 = i0 > i1;
        if (i0) {goto B2;}
        i0 = l7;
        i1 = p1;
        i2 = 1u;
        i1 += i2;
        l17 = i1;
        i32_store(Z_envZ_memory, (u64)(i0 + 76), i1);
        i0 = p1;
        i0 = i32_load8_s(Z_envZ_memory, (u64)(i0));
        l14 = i0;
        i0 = l17;
        p1 = i0;
        i0 = l14;
        i1 = l15;
        i2 = 58u;
        i1 *= i2;
        i0 += i1;
        i1 = 1055u;
        i0 += i1;
        i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
        l14 = i0;
        i1 = 4294967295u;
        i0 += i1;
        i1 = 8u;
        i0 = i0 < i1;
        if (i0) {goto L42;}
      i0 = l14;
      i0 = !(i0);
      if (i0) {goto B2;}
      i0 = l14;
      i1 = 19u;
      i0 = i0 != i1;
      if (i0) {goto B46;}
      i0 = 4294967295u;
      l20 = i0;
      i0 = l16;
      i1 = 4294967295u;
      i0 = (u32)((s32)i0 <= (s32)i1);
      if (i0) {goto B45;}
      goto B2;
      B46:;
      i0 = l16;
      i1 = 0u;
      i0 = (u32)((s32)i0 < (s32)i1);
      if (i0) {goto B44;}
      i0 = p4;
      i1 = l16;
      i2 = 2u;
      i1 <<= (i2 & 31);
      i0 += i1;
      i1 = l14;
      i32_store(Z_envZ_memory, (u64)(i0), i1);
      i0 = l7;
      i1 = p3;
      i2 = l16;
      i3 = 3u;
      i2 <<= (i3 & 31);
      i1 += i2;
      j1 = i64_load(Z_envZ_memory, (u64)(i1));
      i64_store(Z_envZ_memory, (u64)(i0 + 64), j1);
      B45:;
      i0 = 0u;
      p1 = i0;
      i0 = p0;
      i0 = !(i0);
      if (i0) {goto L4;}
      goto B43;
      B44:;
      i0 = p0;
      i0 = !(i0);
      if (i0) {goto B7;}
      i0 = l7;
      i1 = 64u;
      i0 += i1;
      i1 = l14;
      i2 = p2;
      i3 = p6;
      f29(i0, i1, i2, i3);
      i0 = l7;
      i0 = i32_load(Z_envZ_memory, (u64)(i0 + 76));
      l17 = i0;
      B43:;
      i0 = l13;
      i1 = 4294901759u;
      i0 &= i1;
      l21 = i0;
      i1 = l13;
      i2 = l13;
      i3 = 8192u;
      i2 &= i3;
      i0 = i2 ? i0 : i1;
      l13 = i0;
      i0 = 0u;
      l20 = i0;
      i0 = 1093u;
      l16 = i0;
      i0 = l9;
      l14 = i0;
      i0 = l17;
      i1 = 4294967295u;
      i0 += i1;
      i0 = i32_load8_s(Z_envZ_memory, (u64)(i0));
      p1 = i0;
      i1 = 4294967263u;
      i0 &= i1;
      i1 = p1;
      i2 = p1;
      i3 = 15u;
      i2 &= i3;
      i3 = 3u;
      i2 = i2 == i3;
      i0 = i2 ? i0 : i1;
      i1 = p1;
      i2 = l15;
      i0 = i2 ? i0 : i1;
      p1 = i0;
      i1 = 4294967208u;
      i0 += i1;
      l17 = i0;
      i1 = 32u;
      i0 = i0 <= i1;
      if (i0) {goto B21;}
      i0 = p1;
      i1 = 4294967231u;
      i0 += i1;
      l15 = i0;
      i1 = 6u;
      i0 = i0 <= i1;
      if (i0) {goto B51;}
      i0 = p1;
      i1 = 83u;
      i0 = i0 != i1;
      if (i0) {goto B8;}
      i0 = l19;
      i0 = !(i0);
      if (i0) {goto B50;}
      i0 = l7;
      i0 = i32_load(Z_envZ_memory, (u64)(i0 + 64));
      l14 = i0;
      goto B48;
      B51:;
      i0 = l15;
      switch (i0) {
        case 0: goto B19;
        case 1: goto B8;
        case 2: goto B49;
        case 3: goto B8;
        case 4: goto B19;
        case 5: goto B19;
        case 6: goto B19;
        default: goto B19;
      }
      B50:;
      i0 = 0u;
      p1 = i0;
      i0 = p0;
      i1 = 32u;
      i2 = l18;
      i3 = 0u;
      i4 = l13;
      f30(i0, i1, i2, i3, i4);
      goto B47;
      B49:;
      i0 = l7;
      i1 = 0u;
      i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
      i0 = l7;
      i1 = l7;
      j1 = i64_load(Z_envZ_memory, (u64)(i1 + 64));
      i64_store32(Z_envZ_memory, (u64)(i0 + 8), j1);
      i0 = l7;
      i1 = l7;
      i2 = 8u;
      i1 += i2;
      i32_store(Z_envZ_memory, (u64)(i0 + 64), i1);
      i0 = 4294967295u;
      l19 = i0;
      i0 = l7;
      i1 = 8u;
      i0 += i1;
      l14 = i0;
      B48:;
      i0 = 0u;
      p1 = i0;
      L53: 
        i0 = l14;
        i0 = i32_load(Z_envZ_memory, (u64)(i0));
        l15 = i0;
        i0 = !(i0);
        if (i0) {goto B52;}
        i0 = l7;
        i1 = 4u;
        i0 += i1;
        i1 = l15;
        i0 = f19(i0, i1);
        l15 = i0;
        i1 = 0u;
        i0 = (u32)((s32)i0 < (s32)i1);
        l12 = i0;
        if (i0) {goto B54;}
        i0 = l15;
        i1 = l19;
        i2 = p1;
        i1 -= i2;
        i0 = i0 > i1;
        if (i0) {goto B54;}
        i0 = l14;
        i1 = 4u;
        i0 += i1;
        l14 = i0;
        i0 = l19;
        i1 = l15;
        i2 = p1;
        i1 += i2;
        p1 = i1;
        i0 = i0 > i1;
        if (i0) {goto L53;}
        goto B52;
        B54:;
      i0 = 4294967295u;
      l20 = i0;
      i0 = l12;
      if (i0) {goto B2;}
      B52:;
      i0 = p0;
      i1 = 32u;
      i2 = l18;
      i3 = p1;
      i4 = l13;
      f30(i0, i1, i2, i3, i4);
      i0 = p1;
      if (i0) {goto B55;}
      i0 = 0u;
      p1 = i0;
      goto B47;
      B55:;
      i0 = 0u;
      l15 = i0;
      i0 = l7;
      i0 = i32_load(Z_envZ_memory, (u64)(i0 + 64));
      l14 = i0;
      L56: 
        i0 = l14;
        i0 = i32_load(Z_envZ_memory, (u64)(i0));
        l12 = i0;
        i0 = !(i0);
        if (i0) {goto B47;}
        i0 = l7;
        i1 = 4u;
        i0 += i1;
        i1 = l12;
        i0 = f19(i0, i1);
        l12 = i0;
        i1 = l15;
        i0 += i1;
        l15 = i0;
        i1 = p1;
        i0 = (u32)((s32)i0 > (s32)i1);
        if (i0) {goto B47;}
        i0 = p0;
        i1 = l7;
        i2 = 4u;
        i1 += i2;
        i2 = l12;
        f27(i0, i1, i2);
        i0 = l14;
        i1 = 4u;
        i0 += i1;
        l14 = i0;
        i0 = l15;
        i1 = p1;
        i0 = i0 < i1;
        if (i0) {goto L56;}
      B47:;
      i0 = p0;
      i1 = 32u;
      i2 = l18;
      i3 = p1;
      i4 = l13;
      i5 = 8192u;
      i4 ^= i5;
      f30(i0, i1, i2, i3, i4);
      i0 = l18;
      i1 = p1;
      i2 = l18;
      i3 = p1;
      i2 = (u32)((s32)i2 > (s32)i3);
      i0 = i2 ? i0 : i1;
      p1 = i0;
      goto L4;
      B23:;
      i0 = l7;
      i1 = p1;
      i2 = 1u;
      i1 += i2;
      l14 = i1;
      i32_store(Z_envZ_memory, (u64)(i0 + 76), i1);
      i0 = p1;
      i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1));
      l13 = i0;
      i0 = l14;
      p1 = i0;
      goto L22;
    UNREACHABLE;
    B21:;
    i0 = l17;
    switch (i0) {
      case 0: goto B13;
      case 1: goto B8;
      case 2: goto B8;
      case 3: goto B8;
      case 4: goto B8;
      case 5: goto B8;
      case 6: goto B8;
      case 7: goto B8;
      case 8: goto B8;
      case 9: goto B19;
      case 10: goto B8;
      case 11: goto B17;
      case 12: goto B16;
      case 13: goto B19;
      case 14: goto B19;
      case 15: goto B19;
      case 16: goto B8;
      case 17: goto B16;
      case 18: goto B8;
      case 19: goto B8;
      case 20: goto B8;
      case 21: goto B8;
      case 22: goto B12;
      case 23: goto B15;
      case 24: goto B14;
      case 25: goto B8;
      case 26: goto B8;
      case 27: goto B18;
      case 28: goto B8;
      case 29: goto B11;
      case 30: goto B8;
      case 31: goto B8;
      case 32: goto B13;
      default: goto B13;
    }
    B20:;
    i0 = l11;
    l20 = i0;
    i0 = p0;
    if (i0) {goto B2;}
    i0 = l10;
    i0 = !(i0);
    if (i0) {goto B7;}
    i0 = 1u;
    p1 = i0;
    L58: 
      i0 = p4;
      i1 = p1;
      i2 = 2u;
      i1 <<= (i2 & 31);
      i0 += i1;
      i0 = i32_load(Z_envZ_memory, (u64)(i0));
      l13 = i0;
      i0 = !(i0);
      if (i0) {goto B57;}
      i0 = p3;
      i1 = p1;
      i2 = 3u;
      i1 <<= (i2 & 31);
      i0 += i1;
      i1 = l13;
      i2 = p2;
      i3 = p6;
      f29(i0, i1, i2, i3);
      i0 = 1u;
      l20 = i0;
      i0 = p1;
      i1 = 1u;
      i0 += i1;
      p1 = i0;
      i1 = 10u;
      i0 = i0 != i1;
      if (i0) {goto L58;}
      goto B2;
    UNREACHABLE;
    B57:;
    i0 = 1u;
    l20 = i0;
    i0 = p1;
    i1 = 9u;
    i0 = i0 > i1;
    if (i0) {goto B2;}
    L60: 
      i0 = p1;
      l13 = i0;
      i1 = 1u;
      i0 += i1;
      p1 = i0;
      i1 = 10u;
      i0 = i0 == i1;
      if (i0) {goto B59;}
      i0 = p4;
      i1 = p1;
      i2 = 2u;
      i1 <<= (i2 & 31);
      i0 += i1;
      i0 = i32_load(Z_envZ_memory, (u64)(i0));
      i0 = !(i0);
      if (i0) {goto L60;}
    B59:;
    i0 = 4294967295u;
    i1 = 1u;
    i2 = l13;
    i3 = 9u;
    i2 = i2 < i3;
    i0 = i2 ? i0 : i1;
    l20 = i0;
    goto B2;
    B19:;
    i0 = p0;
    i1 = l7;
    d1 = f64_load(Z_envZ_memory, (u64)(i1 + 64));
    i2 = l18;
    i3 = l19;
    i4 = l13;
    i5 = p1;
    i6 = p5;
    i0 = CALL_INDIRECT((*Z_envZ_table), u32 (*)(u32, f64, u32, u32, u32, u32), 7, i6, i0, d1, i2, i3, i4, i5);
    p1 = i0;
    goto L4;
    B18:;
    i0 = 0u;
    l20 = i0;
    i0 = l7;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 64));
    p1 = i0;
    i1 = 1103u;
    i2 = p1;
    i0 = i2 ? i0 : i1;
    l12 = i0;
    i1 = 0u;
    i2 = l19;
    i0 = f20(i0, i1, i2);
    p1 = i0;
    i1 = l12;
    i2 = l19;
    i1 += i2;
    i2 = p1;
    i0 = i2 ? i0 : i1;
    l14 = i0;
    i0 = l21;
    l13 = i0;
    i0 = p1;
    i1 = l12;
    i0 -= i1;
    i1 = l19;
    i2 = p1;
    i0 = i2 ? i0 : i1;
    l19 = i0;
    goto B8;
    B17:;
    i0 = l7;
    i1 = l7;
    j1 = i64_load(Z_envZ_memory, (u64)(i1 + 64));
    i64_store8(Z_envZ_memory, (u64)(i0 + 55), j1);
    i0 = 1u;
    l19 = i0;
    i0 = l8;
    l12 = i0;
    i0 = l9;
    l14 = i0;
    i0 = l21;
    l13 = i0;
    goto B8;
    B16:;
    i0 = l7;
    j0 = i64_load(Z_envZ_memory, (u64)(i0 + 64));
    l24 = j0;
    j1 = 18446744073709551615ull;
    i0 = (u64)((s64)j0 > (s64)j1);
    if (i0) {goto B61;}
    i0 = l7;
    j1 = 0ull;
    j2 = l24;
    j1 -= j2;
    l24 = j1;
    i64_store(Z_envZ_memory, (u64)(i0 + 64), j1);
    i0 = 1u;
    l20 = i0;
    i0 = 1093u;
    l16 = i0;
    goto B10;
    B61:;
    i0 = l13;
    i1 = 2048u;
    i0 &= i1;
    i0 = !(i0);
    if (i0) {goto B62;}
    i0 = 1u;
    l20 = i0;
    i0 = 1094u;
    l16 = i0;
    goto B10;
    B62:;
    i0 = 1095u;
    i1 = 1093u;
    i2 = l13;
    i3 = 1u;
    i2 &= i3;
    l20 = i2;
    i0 = i2 ? i0 : i1;
    l16 = i0;
    goto B10;
    B15:;
    i0 = 0u;
    l20 = i0;
    i0 = 1093u;
    l16 = i0;
    i0 = l7;
    j0 = i64_load(Z_envZ_memory, (u64)(i0 + 64));
    i1 = l9;
    i0 = f31(j0, i1);
    l12 = i0;
    i0 = l13;
    i1 = 8u;
    i0 &= i1;
    i0 = !(i0);
    if (i0) {goto B9;}
    i0 = l19;
    i1 = l9;
    i2 = l12;
    i1 -= i2;
    p1 = i1;
    i2 = 1u;
    i1 += i2;
    i2 = l19;
    i3 = p1;
    i2 = (u32)((s32)i2 > (s32)i3);
    i0 = i2 ? i0 : i1;
    l19 = i0;
    goto B9;
    B14:;
    i0 = l19;
    i1 = 8u;
    i2 = l19;
    i3 = 8u;
    i2 = i2 > i3;
    i0 = i2 ? i0 : i1;
    l19 = i0;
    i0 = l13;
    i1 = 8u;
    i0 |= i1;
    l13 = i0;
    i0 = 120u;
    p1 = i0;
    B13:;
    i0 = 0u;
    l20 = i0;
    i0 = 1093u;
    l16 = i0;
    i0 = l7;
    j0 = i64_load(Z_envZ_memory, (u64)(i0 + 64));
    i1 = l9;
    i2 = p1;
    i3 = 32u;
    i2 &= i3;
    i0 = f32_0(j0, i1, i2);
    l12 = i0;
    i0 = l13;
    i1 = 8u;
    i0 &= i1;
    i0 = !(i0);
    if (i0) {goto B9;}
    i0 = l7;
    j0 = i64_load(Z_envZ_memory, (u64)(i0 + 64));
    i0 = !(j0);
    if (i0) {goto B9;}
    i0 = p1;
    i1 = 4u;
    i0 >>= (i1 & 31);
    i1 = 1093u;
    i0 += i1;
    l16 = i0;
    i0 = 2u;
    l20 = i0;
    goto B9;
    B12:;
    i0 = 0u;
    p1 = i0;
    i0 = l15;
    i1 = 255u;
    i0 &= i1;
    l13 = i0;
    i1 = 7u;
    i0 = i0 > i1;
    if (i0) {goto L4;}
    i0 = l13;
    switch (i0) {
      case 0: goto B69;
      case 1: goto B68;
      case 2: goto B67;
      case 3: goto B66;
      case 4: goto B65;
      case 5: goto L4;
      case 6: goto B64;
      case 7: goto B63;
      default: goto B69;
    }
    B69:;
    i0 = l7;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 64));
    i1 = l11;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    goto L4;
    B68:;
    i0 = l7;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 64));
    i1 = l11;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    goto L4;
    B67:;
    i0 = l7;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 64));
    i1 = l11;
    j1 = (u64)(s64)(s32)(i1);
    i64_store(Z_envZ_memory, (u64)(i0), j1);
    goto L4;
    B66:;
    i0 = l7;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 64));
    i1 = l11;
    i32_store16(Z_envZ_memory, (u64)(i0), i1);
    goto L4;
    B65:;
    i0 = l7;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 64));
    i1 = l11;
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    goto L4;
    B64:;
    i0 = l7;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 64));
    i1 = l11;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    goto L4;
    B63:;
    i0 = l7;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 64));
    i1 = l11;
    j1 = (u64)(s64)(s32)(i1);
    i64_store(Z_envZ_memory, (u64)(i0), j1);
    goto L4;
    B11:;
    i0 = 0u;
    l20 = i0;
    i0 = 1093u;
    l16 = i0;
    i0 = l7;
    j0 = i64_load(Z_envZ_memory, (u64)(i0 + 64));
    l24 = j0;
    B10:;
    j0 = l24;
    i1 = l9;
    i0 = f33(j0, i1);
    l12 = i0;
    B9:;
    i0 = l13;
    i1 = 4294901759u;
    i0 &= i1;
    i1 = l13;
    i2 = l19;
    i3 = 4294967295u;
    i2 = (u32)((s32)i2 > (s32)i3);
    i0 = i2 ? i0 : i1;
    l13 = i0;
    i0 = l7;
    j0 = i64_load(Z_envZ_memory, (u64)(i0 + 64));
    l24 = j0;
    i0 = l19;
    if (i0) {goto B71;}
    j0 = l24;
    i0 = !(j0);
    i0 = !(i0);
    if (i0) {goto B71;}
    i0 = 0u;
    l19 = i0;
    i0 = l9;
    l12 = i0;
    goto B70;
    B71:;
    i0 = l19;
    i1 = l9;
    i2 = l12;
    i1 -= i2;
    j2 = l24;
    i2 = !(j2);
    i1 += i2;
    p1 = i1;
    i2 = l19;
    i3 = p1;
    i2 = (u32)((s32)i2 > (s32)i3);
    i0 = i2 ? i0 : i1;
    l19 = i0;
    B70:;
    i0 = l9;
    l14 = i0;
    B8:;
    i0 = p0;
    i1 = 32u;
    i2 = l20;
    i3 = l14;
    i4 = l12;
    i3 -= i4;
    l15 = i3;
    i4 = l19;
    i5 = l19;
    i6 = l15;
    i5 = (u32)((s32)i5 < (s32)i6);
    i3 = i5 ? i3 : i4;
    l17 = i3;
    i2 += i3;
    l14 = i2;
    i3 = l18;
    i4 = l18;
    i5 = l14;
    i4 = (u32)((s32)i4 < (s32)i5);
    i2 = i4 ? i2 : i3;
    p1 = i2;
    i3 = l14;
    i4 = l13;
    f30(i0, i1, i2, i3, i4);
    i0 = p0;
    i1 = l16;
    i2 = l20;
    f27(i0, i1, i2);
    i0 = p0;
    i1 = 48u;
    i2 = p1;
    i3 = l14;
    i4 = l13;
    i5 = 65536u;
    i4 ^= i5;
    f30(i0, i1, i2, i3, i4);
    i0 = p0;
    i1 = 48u;
    i2 = l17;
    i3 = l15;
    i4 = 0u;
    f30(i0, i1, i2, i3, i4);
    i0 = p0;
    i1 = l12;
    i2 = l15;
    f27(i0, i1, i2);
    i0 = p0;
    i1 = 32u;
    i2 = p1;
    i3 = l14;
    i4 = l13;
    i5 = 8192u;
    i4 ^= i5;
    f30(i0, i1, i2, i3, i4);
    goto L4;
    B7:;
  i0 = 0u;
  l20 = i0;
  goto B2;
  B3:;
  i0 = 4294967295u;
  l20 = i0;
  B2:;
  i0 = l7;
  i1 = 80u;
  i0 += i1;
  l23 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l23;
  g0 = i0;
  i0 = l20;
  FUNC_EPILOGUE;
  return i0;
}

static void f27(u32 p0, u32 p1, u32 p2) {
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  i0 = p0;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
  i1 = 32u;
  i0 &= i1;
  if (i0) {goto B0;}
  i0 = p1;
  i1 = p2;
  i2 = p0;
  i0 = f48(i0, i1, i2);
  B0:;
  FUNC_EPILOGUE;
}

static u32 f28(u32 p0) {
  u32 l1 = 0, l2 = 0, l3 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  i0 = 0u;
  l1 = i0;
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  i0 = i32_load8_s(Z_envZ_memory, (u64)(i0));
  i0 = f15(i0);
  i0 = !(i0);
  if (i0) {goto B0;}
  L1: 
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l2 = i0;
    i0 = i32_load8_s(Z_envZ_memory, (u64)(i0));
    l3 = i0;
    i0 = p0;
    i1 = l2;
    i2 = 1u;
    i1 += i2;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    i0 = l3;
    i1 = l1;
    i2 = 10u;
    i1 *= i2;
    i0 += i1;
    i1 = 4294967248u;
    i0 += i1;
    l1 = i0;
    i0 = l2;
    i0 = i32_load8_s(Z_envZ_memory, (u64)(i0 + 1));
    i0 = f15(i0);
    if (i0) {goto L1;}
  B0:;
  i0 = l1;
  FUNC_EPILOGUE;
  return i0;
}

static void f29(u32 p0, u32 p1, u32 p2, u32 p3) {
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  u64 j1;
  i0 = p1;
  i1 = 20u;
  i0 = i0 > i1;
  if (i0) {goto B0;}
  i0 = p1;
  i1 = 4294967287u;
  i0 += i1;
  p1 = i0;
  i1 = 9u;
  i0 = i0 > i1;
  if (i0) {goto B0;}
  i0 = p1;
  switch (i0) {
    case 0: goto B10;
    case 1: goto B9;
    case 2: goto B8;
    case 3: goto B7;
    case 4: goto B6;
    case 5: goto B5;
    case 6: goto B4;
    case 7: goto B3;
    case 8: goto B2;
    case 9: goto B1;
    default: goto B10;
  }
  B10:;
  i0 = p2;
  i1 = p2;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  p1 = i1;
  i2 = 4u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  goto Bfunc;
  B9:;
  i0 = p2;
  i1 = p2;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  p1 = i1;
  i2 = 4u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  j1 = i64_load32_s(Z_envZ_memory, (u64)(i1));
  i64_store(Z_envZ_memory, (u64)(i0), j1);
  goto Bfunc;
  B8:;
  i0 = p2;
  i1 = p2;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  p1 = i1;
  i2 = 4u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  j1 = i64_load32_u(Z_envZ_memory, (u64)(i1));
  i64_store(Z_envZ_memory, (u64)(i0), j1);
  goto Bfunc;
  B7:;
  i0 = p2;
  i1 = p2;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  i2 = 7u;
  i1 += i2;
  i2 = 4294967288u;
  i1 &= i2;
  p1 = i1;
  i2 = 8u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  j1 = i64_load(Z_envZ_memory, (u64)(i1));
  i64_store(Z_envZ_memory, (u64)(i0), j1);
  goto Bfunc;
  B6:;
  i0 = p2;
  i1 = p2;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  p1 = i1;
  i2 = 4u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  j1 = i64_load16_s(Z_envZ_memory, (u64)(i1));
  i64_store(Z_envZ_memory, (u64)(i0), j1);
  goto Bfunc;
  B5:;
  i0 = p2;
  i1 = p2;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  p1 = i1;
  i2 = 4u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  j1 = i32_load16_u(Z_envZ_memory, (u64)(i1));
  i64_store(Z_envZ_memory, (u64)(i0), j1);
  goto Bfunc;
  B4:;
  i0 = p2;
  i1 = p2;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  p1 = i1;
  i2 = 4u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  j1 = i64_load8_s(Z_envZ_memory, (u64)(i1));
  i64_store(Z_envZ_memory, (u64)(i0), j1);
  goto Bfunc;
  B3:;
  i0 = p2;
  i1 = p2;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  p1 = i1;
  i2 = 4u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  j1 = i64_load8_u(Z_envZ_memory, (u64)(i1));
  i64_store(Z_envZ_memory, (u64)(i0), j1);
  goto Bfunc;
  B2:;
  i0 = p2;
  i1 = p2;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  i2 = 7u;
  i1 += i2;
  i2 = 4294967288u;
  i1 &= i2;
  p1 = i1;
  i2 = 8u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  j1 = i64_load(Z_envZ_memory, (u64)(i1));
  i64_store(Z_envZ_memory, (u64)(i0), j1);
  goto Bfunc;
  B1:;
  i0 = p0;
  i1 = p2;
  i2 = p3;
  CALL_INDIRECT((*Z_envZ_table), void (*)(u32, u32), 6, i2, i0, i1);
  B0:;
  Bfunc:;
  FUNC_EPILOGUE;
}

static void f30(u32 p0, u32 p1, u32 p2, u32 p3, u32 p4) {
  u32 l5 = 0, l6 = 0, l7 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3, i4, i5;
  i0 = g0;
  i1 = 256u;
  i0 -= i1;
  l5 = i0;
  l6 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l6;
  g0 = i0;
  i0 = p2;
  i1 = p3;
  i0 = (u32)((s32)i0 <= (s32)i1);
  if (i0) {goto B2;}
  i0 = p4;
  i1 = 73728u;
  i0 &= i1;
  if (i0) {goto B2;}
  i0 = l5;
  i1 = p1;
  i2 = p2;
  i3 = p3;
  i2 -= i3;
  p2 = i2;
  i3 = 256u;
  i4 = p2;
  i5 = 256u;
  i4 = i4 < i5;
  p3 = i4;
  i2 = i4 ? i2 : i3;
  i0 = f42(i0, i1, i2);
  i0 = p3;
  if (i0) {goto B3;}
  L4: 
    i0 = p0;
    i1 = l5;
    i2 = 256u;
    f27(i0, i1, i2);
    i0 = p2;
    i1 = 4294967040u;
    i0 += i1;
    p2 = i0;
    i1 = 255u;
    i0 = i0 > i1;
    if (i0) {goto L4;}
  B3:;
  i0 = p0;
  i1 = l5;
  i2 = p2;
  f27(i0, i1, i2);
  B2:;
  i0 = l5;
  i1 = 256u;
  i0 += i1;
  l7 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l7;
  g0 = i0;
  FUNC_EPILOGUE;
}

static u32 f31(u64 p0, u32 p1) {
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  u64 j0, j1;
  j0 = p0;
  i0 = !(j0);
  if (i0) {goto B0;}
  L1: 
    i0 = p1;
    i1 = 4294967295u;
    i0 += i1;
    p1 = i0;
    j1 = p0;
    i1 = (u32)(j1);
    i2 = 7u;
    i1 &= i2;
    i2 = 48u;
    i1 |= i2;
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    j0 = p0;
    j1 = 3ull;
    j0 >>= (j1 & 63);
    p0 = j0;
    j1 = 0ull;
    i0 = j0 != j1;
    if (i0) {goto L1;}
  B0:;
  i0 = p1;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f32_0(u64 p0, u32 p1, u32 p2) {
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  u64 j0, j1;
  j0 = p0;
  i0 = !(j0);
  if (i0) {goto B0;}
  L1: 
    i0 = p1;
    i1 = 4294967295u;
    i0 += i1;
    p1 = i0;
    j1 = p0;
    i1 = (u32)(j1);
    i2 = 15u;
    i1 &= i2;
    i2 = 1584u;
    i1 += i2;
    i1 = i32_load8_u(Z_envZ_memory, (u64)(i1));
    i2 = p2;
    i1 |= i2;
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    j0 = p0;
    j1 = 4ull;
    j0 >>= (j1 & 63);
    p0 = j0;
    j1 = 0ull;
    i0 = j0 != j1;
    if (i0) {goto L1;}
  B0:;
  i0 = p1;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f33(u64 p0, u32 p1) {
  u32 l2 = 0, l3 = 0, l4 = 0;
  u64 l5 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3;
  u64 j0, j1, j2, j3;
  j0 = p0;
  j1 = 4294967296ull;
  i0 = j0 >= j1;
  if (i0) {goto B1;}
  j0 = p0;
  l5 = j0;
  goto B0;
  B1:;
  L2: 
    i0 = p1;
    i1 = 4294967295u;
    i0 += i1;
    p1 = i0;
    j1 = p0;
    j2 = p0;
    j3 = 10ull;
    j2 = DIV_U(j2, j3);
    l5 = j2;
    j3 = 10ull;
    j2 *= j3;
    j1 -= j2;
    i1 = (u32)(j1);
    i2 = 48u;
    i1 |= i2;
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    j0 = p0;
    j1 = 42949672959ull;
    i0 = j0 > j1;
    l2 = i0;
    j0 = l5;
    p0 = j0;
    i0 = l2;
    if (i0) {goto L2;}
  B0:;
  j0 = l5;
  i0 = (u32)(j0);
  l2 = i0;
  i0 = !(i0);
  if (i0) {goto B3;}
  L4: 
    i0 = p1;
    i1 = 4294967295u;
    i0 += i1;
    p1 = i0;
    i1 = l2;
    i2 = l2;
    i3 = 10u;
    i2 = DIV_U(i2, i3);
    l3 = i2;
    i3 = 10u;
    i2 *= i3;
    i1 -= i2;
    i2 = 48u;
    i1 |= i2;
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    i0 = l2;
    i1 = 9u;
    i0 = i0 > i1;
    l4 = i0;
    i0 = l3;
    l2 = i0;
    i0 = l4;
    if (i0) {goto L4;}
  B3:;
  i0 = p1;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f34(u32 p0, u32 p1, u32 p2) {
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3, i4;
  i0 = p0;
  i1 = p1;
  i2 = p2;
  i3 = 1u;
  i4 = 2u;
  i0 = f25(i0, i1, i2, i3, i4);
  FUNC_EPILOGUE;
  return i0;
}

static u32 f35(u32 p0, f64 p1, u32 p2, u32 p3, u32 p4, u32 p5) {
  u32 l6 = 0, l7 = 0, l8 = 0, l9 = 0, l10 = 0, l11 = 0, l12 = 0, l13 = 0, 
      l14 = 0, l15 = 0, l16 = 0, l17 = 0, l18 = 0, l19 = 0, l20 = 0, l21 = 0, 
      l22 = 0, l23 = 0;
  u64 l24 = 0, l25 = 0;
  f64 l26 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3, i4, i5;
  u64 j0, j1, j2, j3;
  f64 d0, d1, d2, d3, d4;
  i0 = g0;
  i1 = 560u;
  i0 -= i1;
  l6 = i0;
  l22 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l22;
  g0 = i0;
  i0 = l6;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 44), i1);
  d0 = p1;
  j0 = f37(d0);
  l24 = j0;
  j1 = 18446744073709551615ull;
  i0 = (u64)((s64)j0 > (s64)j1);
  if (i0) {goto B3;}
  i0 = 1u;
  l7 = i0;
  i0 = 1600u;
  l8 = i0;
  d0 = p1;
  d0 = -(d0);
  p1 = d0;
  j0 = f37(d0);
  l24 = j0;
  goto B2;
  B3:;
  i0 = p4;
  i1 = 2048u;
  i0 &= i1;
  i0 = !(i0);
  if (i0) {goto B4;}
  i0 = 1u;
  l7 = i0;
  i0 = 1603u;
  l8 = i0;
  goto B2;
  B4:;
  i0 = 1606u;
  i1 = 1601u;
  i2 = p4;
  i3 = 1u;
  i2 &= i3;
  l7 = i2;
  i0 = i2 ? i0 : i1;
  l8 = i0;
  B2:;
  j0 = l24;
  j1 = 9218868437227405312ull;
  j0 &= j1;
  j1 = 9218868437227405312ull;
  i0 = j0 != j1;
  if (i0) {goto B6;}
  i0 = p0;
  i1 = 32u;
  i2 = p2;
  i3 = l7;
  i4 = 3u;
  i3 += i4;
  l9 = i3;
  i4 = p4;
  i5 = 4294901759u;
  i4 &= i5;
  f30(i0, i1, i2, i3, i4);
  i0 = p0;
  i1 = l8;
  i2 = l7;
  f27(i0, i1, i2);
  i0 = p0;
  i1 = 1627u;
  i2 = 1631u;
  i3 = p5;
  i4 = 5u;
  i3 >>= (i4 & 31);
  i4 = 1u;
  i3 &= i4;
  l10 = i3;
  i1 = i3 ? i1 : i2;
  i2 = 1619u;
  i3 = 1623u;
  i4 = l10;
  i2 = i4 ? i2 : i3;
  d3 = p1;
  d4 = p1;
  i3 = d3 != d4;
  i1 = i3 ? i1 : i2;
  i2 = 3u;
  f27(i0, i1, i2);
  i0 = p0;
  i1 = 32u;
  i2 = p2;
  i3 = l9;
  i4 = p4;
  i5 = 8192u;
  i4 ^= i5;
  f30(i0, i1, i2, i3, i4);
  goto B5;
  B6:;
  i0 = l6;
  i1 = 16u;
  i0 += i1;
  l11 = i0;
  d0 = p1;
  i1 = l6;
  i2 = 44u;
  i1 += i2;
  d0 = f21(d0, i1);
  p1 = d0;
  d1 = p1;
  d0 += d1;
  p1 = d0;
  d1 = 0;
  i0 = d0 == d1;
  if (i0) {goto B10;}
  i0 = l6;
  i1 = l6;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 44));
  l10 = i1;
  i2 = 4294967295u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 44), i1);
  i0 = p5;
  i1 = 32u;
  i0 |= i1;
  l12 = i0;
  i1 = 97u;
  i0 = i0 != i1;
  if (i0) {goto B9;}
  goto B7;
  B10:;
  i0 = p5;
  i1 = 32u;
  i0 |= i1;
  l12 = i0;
  i1 = 97u;
  i0 = i0 == i1;
  if (i0) {goto B7;}
  i0 = 6u;
  i1 = p3;
  i2 = p3;
  i3 = 0u;
  i2 = (u32)((s32)i2 < (s32)i3);
  i0 = i2 ? i0 : i1;
  l13 = i0;
  i0 = l6;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 44));
  l14 = i0;
  goto B8;
  B9:;
  i0 = l6;
  i1 = l10;
  i2 = 4294967267u;
  i1 += i2;
  l14 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 44), i1);
  i0 = 6u;
  i1 = p3;
  i2 = p3;
  i3 = 0u;
  i2 = (u32)((s32)i2 < (s32)i3);
  i0 = i2 ? i0 : i1;
  l13 = i0;
  d0 = p1;
  d1 = 268435456;
  d0 *= d1;
  p1 = d0;
  B8:;
  i0 = l6;
  i1 = 48u;
  i0 += i1;
  i1 = l6;
  i2 = 336u;
  i1 += i2;
  i2 = l14;
  i3 = 0u;
  i2 = (u32)((s32)i2 < (s32)i3);
  i0 = i2 ? i0 : i1;
  l15 = i0;
  l16 = i0;
  L11: 
    d0 = p1;
    d1 = 4294967296;
    i0 = d0 < d1;
    d1 = p1;
    d2 = 0;
    i1 = d1 >= d2;
    i0 &= i1;
    i0 = !(i0);
    if (i0) {goto B13;}
    d0 = p1;
    i0 = I32_TRUNC_U_F64(d0);
    l10 = i0;
    goto B12;
    B13:;
    i0 = 0u;
    l10 = i0;
    B12:;
    i0 = l16;
    i1 = l10;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    i0 = l16;
    i1 = 4u;
    i0 += i1;
    l16 = i0;
    d0 = p1;
    i1 = l10;
    d1 = (f64)(i1);
    d0 -= d1;
    d1 = 1000000000;
    d0 *= d1;
    p1 = d0;
    d1 = 0;
    i0 = d0 != d1;
    if (i0) {goto L11;}
  i0 = l14;
  i1 = 1u;
  i0 = (u32)((s32)i0 >= (s32)i1);
  if (i0) {goto B15;}
  i0 = l16;
  l10 = i0;
  i0 = l15;
  l17 = i0;
  goto B14;
  B15:;
  i0 = l15;
  l17 = i0;
  L16: 
    i0 = l14;
    i1 = 29u;
    i2 = l14;
    i3 = 29u;
    i2 = (u32)((s32)i2 < (s32)i3);
    i0 = i2 ? i0 : i1;
    l14 = i0;
    i0 = l16;
    i1 = 4294967292u;
    i0 += i1;
    l10 = i0;
    i1 = l17;
    i0 = i0 < i1;
    if (i0) {goto B17;}
    i0 = l14;
    j0 = (u64)(i0);
    l25 = j0;
    j0 = 0ull;
    l24 = j0;
    L18: 
      i0 = l10;
      i1 = l10;
      j1 = i64_load32_u(Z_envZ_memory, (u64)(i1));
      j2 = l25;
      j1 <<= (j2 & 63);
      j2 = l24;
      j3 = 4294967295ull;
      j2 &= j3;
      j1 += j2;
      l24 = j1;
      j2 = l24;
      j3 = 1000000000ull;
      j2 = DIV_U(j2, j3);
      l24 = j2;
      j3 = 1000000000ull;
      j2 *= j3;
      j1 -= j2;
      i64_store32(Z_envZ_memory, (u64)(i0), j1);
      i0 = l10;
      i1 = 4294967292u;
      i0 += i1;
      l10 = i0;
      i1 = l17;
      i0 = i0 >= i1;
      if (i0) {goto L18;}
    j0 = l24;
    i0 = (u32)(j0);
    l10 = i0;
    i0 = !(i0);
    if (i0) {goto B17;}
    i0 = l17;
    i1 = 4294967292u;
    i0 += i1;
    l17 = i0;
    i1 = l10;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    B17:;
    L20: 
      i0 = l16;
      l10 = i0;
      i1 = l17;
      i0 = i0 <= i1;
      if (i0) {goto B19;}
      i0 = l10;
      i1 = 4294967292u;
      i0 += i1;
      l16 = i0;
      i0 = i32_load(Z_envZ_memory, (u64)(i0));
      i0 = !(i0);
      if (i0) {goto L20;}
    B19:;
    i0 = l6;
    i1 = l6;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 44));
    i2 = l14;
    i1 -= i2;
    l14 = i1;
    i32_store(Z_envZ_memory, (u64)(i0 + 44), i1);
    i0 = l10;
    l16 = i0;
    i0 = l14;
    i1 = 0u;
    i0 = (u32)((s32)i0 > (s32)i1);
    if (i0) {goto L16;}
  B14:;
  i0 = l14;
  i1 = 4294967295u;
  i0 = (u32)((s32)i0 > (s32)i1);
  if (i0) {goto B21;}
  i0 = l13;
  i1 = 25u;
  i0 += i1;
  i1 = 9u;
  i0 = I32_DIV_S(i0, i1);
  i1 = 1u;
  i0 += i1;
  l18 = i0;
  i0 = l12;
  i1 = 102u;
  i0 = i0 == i1;
  l19 = i0;
  L22: 
    i0 = 9u;
    i1 = 0u;
    i2 = l14;
    i1 -= i2;
    i2 = l14;
    i3 = 4294967287u;
    i2 = (u32)((s32)i2 < (s32)i3);
    i0 = i2 ? i0 : i1;
    l9 = i0;
    i0 = l17;
    i1 = l10;
    i0 = i0 < i1;
    if (i0) {goto B24;}
    i0 = l17;
    i1 = l17;
    i2 = 4u;
    i1 += i2;
    i2 = l17;
    i2 = i32_load(Z_envZ_memory, (u64)(i2));
    i0 = i2 ? i0 : i1;
    l17 = i0;
    goto B23;
    B24:;
    i0 = 1000000000u;
    i1 = l9;
    i0 >>= (i1 & 31);
    l20 = i0;
    i0 = 4294967295u;
    i1 = l9;
    i0 <<= (i1 & 31);
    i1 = 4294967295u;
    i0 ^= i1;
    l21 = i0;
    i0 = 0u;
    l14 = i0;
    i0 = l17;
    l16 = i0;
    L25: 
      i0 = l16;
      i1 = l16;
      i1 = i32_load(Z_envZ_memory, (u64)(i1));
      p3 = i1;
      i2 = l9;
      i1 >>= (i2 & 31);
      i2 = l14;
      i1 += i2;
      i32_store(Z_envZ_memory, (u64)(i0), i1);
      i0 = p3;
      i1 = l21;
      i0 &= i1;
      i1 = l20;
      i0 *= i1;
      l14 = i0;
      i0 = l16;
      i1 = 4u;
      i0 += i1;
      l16 = i0;
      i1 = l10;
      i0 = i0 < i1;
      if (i0) {goto L25;}
    i0 = l17;
    i1 = l17;
    i2 = 4u;
    i1 += i2;
    i2 = l17;
    i2 = i32_load(Z_envZ_memory, (u64)(i2));
    i0 = i2 ? i0 : i1;
    l17 = i0;
    i0 = l14;
    i0 = !(i0);
    if (i0) {goto B23;}
    i0 = l10;
    i1 = l14;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    i0 = l10;
    i1 = 4u;
    i0 += i1;
    l10 = i0;
    B23:;
    i0 = l6;
    i1 = l6;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 44));
    i2 = l9;
    i1 += i2;
    l14 = i1;
    i32_store(Z_envZ_memory, (u64)(i0 + 44), i1);
    i0 = l15;
    i1 = l17;
    i2 = l19;
    i0 = i2 ? i0 : i1;
    l16 = i0;
    i1 = l18;
    i2 = 2u;
    i1 <<= (i2 & 31);
    i0 += i1;
    i1 = l10;
    i2 = l10;
    i3 = l16;
    i2 -= i3;
    i3 = 2u;
    i2 = (u32)((s32)i2 >> (i3 & 31));
    i3 = l18;
    i2 = (u32)((s32)i2 > (s32)i3);
    i0 = i2 ? i0 : i1;
    l10 = i0;
    i0 = l14;
    i1 = 0u;
    i0 = (u32)((s32)i0 < (s32)i1);
    if (i0) {goto L22;}
  B21:;
  i0 = 0u;
  l16 = i0;
  i0 = l17;
  i1 = l10;
  i0 = i0 >= i1;
  if (i0) {goto B26;}
  i0 = l15;
  i1 = l17;
  i0 -= i1;
  i1 = 2u;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  i1 = 9u;
  i0 *= i1;
  l16 = i0;
  i0 = 10u;
  l14 = i0;
  i0 = l17;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  p3 = i0;
  i1 = 10u;
  i0 = i0 < i1;
  if (i0) {goto B26;}
  L27: 
    i0 = l16;
    i1 = 1u;
    i0 += i1;
    l16 = i0;
    i0 = p3;
    i1 = l14;
    i2 = 10u;
    i1 *= i2;
    l14 = i1;
    i0 = i0 >= i1;
    if (i0) {goto L27;}
  B26:;
  i0 = l13;
  i1 = 0u;
  i2 = l16;
  i3 = l12;
  i4 = 102u;
  i3 = i3 == i4;
  i1 = i3 ? i1 : i2;
  i0 -= i1;
  i1 = l13;
  i2 = 0u;
  i1 = i1 != i2;
  i2 = l12;
  i3 = 103u;
  i2 = i2 == i3;
  i1 &= i2;
  i0 -= i1;
  l14 = i0;
  i1 = l10;
  i2 = l15;
  i1 -= i2;
  i2 = 2u;
  i1 = (u32)((s32)i1 >> (i2 & 31));
  i2 = 9u;
  i1 *= i2;
  i2 = 4294967287u;
  i1 += i2;
  i0 = (u32)((s32)i0 >= (s32)i1);
  if (i0) {goto B28;}
  i0 = l14;
  i1 = 9216u;
  i0 += i1;
  p3 = i0;
  i1 = 9u;
  i0 = I32_DIV_S(i0, i1);
  l20 = i0;
  i1 = 2u;
  i0 <<= (i1 & 31);
  i1 = l15;
  i0 += i1;
  i1 = 4294963204u;
  i0 += i1;
  l9 = i0;
  i0 = 10u;
  l14 = i0;
  i0 = p3;
  i1 = l20;
  i2 = 9u;
  i1 *= i2;
  i0 -= i1;
  p3 = i0;
  i1 = 7u;
  i0 = (u32)((s32)i0 > (s32)i1);
  if (i0) {goto B29;}
  L30: 
    i0 = l14;
    i1 = 10u;
    i0 *= i1;
    l14 = i0;
    i0 = p3;
    i1 = 1u;
    i0 += i1;
    p3 = i0;
    i1 = 8u;
    i0 = i0 != i1;
    if (i0) {goto L30;}
  B29:;
  i0 = l9;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l20 = i0;
  i1 = l20;
  i2 = l14;
  i1 = DIV_U(i1, i2);
  l21 = i1;
  i2 = l14;
  i1 *= i2;
  i0 -= i1;
  p3 = i0;
  i0 = l9;
  i1 = 4u;
  i0 += i1;
  l18 = i0;
  i1 = l10;
  i0 = i0 != i1;
  if (i0) {goto B32;}
  i0 = p3;
  i0 = !(i0);
  if (i0) {goto B31;}
  B32:;
  d0 = 0.5;
  d1 = 1;
  d2 = 1.5;
  i3 = p3;
  i4 = l14;
  i5 = 1u;
  i4 >>= (i5 & 31);
  l19 = i4;
  i3 = i3 == i4;
  d1 = i3 ? d1 : d2;
  d2 = 1.5;
  i3 = l18;
  i4 = l10;
  i3 = i3 == i4;
  d1 = i3 ? d1 : d2;
  i2 = p3;
  i3 = l19;
  i2 = i2 < i3;
  d0 = i2 ? d0 : d1;
  l26 = d0;
  d0 = 9007199254740994;
  d1 = 9007199254740992;
  i2 = l21;
  i3 = 1u;
  i2 &= i3;
  d0 = i2 ? d0 : d1;
  p1 = d0;
  i0 = l7;
  i0 = !(i0);
  if (i0) {goto B33;}
  i0 = l8;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
  i1 = 45u;
  i0 = i0 != i1;
  if (i0) {goto B33;}
  d0 = l26;
  d0 = -(d0);
  l26 = d0;
  d0 = p1;
  d0 = -(d0);
  p1 = d0;
  B33:;
  i0 = l9;
  i1 = l20;
  i2 = p3;
  i1 -= i2;
  p3 = i1;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  d0 = p1;
  d1 = l26;
  d0 += d1;
  d1 = p1;
  i0 = d0 == d1;
  if (i0) {goto B31;}
  i0 = l9;
  i1 = p3;
  i2 = l14;
  i1 += i2;
  l16 = i1;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l16;
  i1 = 1000000000u;
  i0 = i0 < i1;
  if (i0) {goto B34;}
  L35: 
    i0 = l9;
    i1 = 0u;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    i0 = l9;
    i1 = 4294967292u;
    i0 += i1;
    l9 = i0;
    i1 = l17;
    i0 = i0 >= i1;
    if (i0) {goto B36;}
    i0 = l17;
    i1 = 4294967292u;
    i0 += i1;
    l17 = i0;
    i1 = 0u;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    B36:;
    i0 = l9;
    i1 = l9;
    i1 = i32_load(Z_envZ_memory, (u64)(i1));
    i2 = 1u;
    i1 += i2;
    l16 = i1;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    i0 = l16;
    i1 = 999999999u;
    i0 = i0 > i1;
    if (i0) {goto L35;}
  B34:;
  i0 = l15;
  i1 = l17;
  i0 -= i1;
  i1 = 2u;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  i1 = 9u;
  i0 *= i1;
  l16 = i0;
  i0 = 10u;
  l14 = i0;
  i0 = l17;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  p3 = i0;
  i1 = 10u;
  i0 = i0 < i1;
  if (i0) {goto B31;}
  L37: 
    i0 = l16;
    i1 = 1u;
    i0 += i1;
    l16 = i0;
    i0 = p3;
    i1 = l14;
    i2 = 10u;
    i1 *= i2;
    l14 = i1;
    i0 = i0 >= i1;
    if (i0) {goto L37;}
  B31:;
  i0 = l9;
  i1 = 4u;
  i0 += i1;
  l14 = i0;
  i1 = l10;
  i2 = l10;
  i3 = l14;
  i2 = i2 > i3;
  i0 = i2 ? i0 : i1;
  l10 = i0;
  B28:;
  L39: 
    i0 = l10;
    l14 = i0;
    i1 = l17;
    i0 = i0 > i1;
    if (i0) {goto B40;}
    i0 = 0u;
    l19 = i0;
    goto B38;
    B40:;
    i0 = l14;
    i1 = 4294967292u;
    i0 += i1;
    l10 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    i0 = !(i0);
    if (i0) {goto L39;}
  i0 = 1u;
  l19 = i0;
  B38:;
  i0 = l12;
  i1 = 103u;
  i0 = i0 == i1;
  if (i0) {goto B42;}
  i0 = p4;
  i1 = 8u;
  i0 &= i1;
  l21 = i0;
  goto B41;
  B42:;
  i0 = l16;
  i1 = 4294967295u;
  i0 ^= i1;
  i1 = 4294967295u;
  i2 = l13;
  i3 = 1u;
  i4 = l13;
  i2 = i4 ? i2 : i3;
  l10 = i2;
  i3 = l16;
  i2 = (u32)((s32)i2 > (s32)i3);
  i3 = l16;
  i4 = 4294967291u;
  i3 = (u32)((s32)i3 > (s32)i4);
  i2 &= i3;
  p3 = i2;
  i0 = i2 ? i0 : i1;
  i1 = l10;
  i0 += i1;
  l13 = i0;
  i0 = 4294967295u;
  i1 = 4294967294u;
  i2 = p3;
  i0 = i2 ? i0 : i1;
  i1 = p5;
  i0 += i1;
  p5 = i0;
  i0 = p4;
  i1 = 8u;
  i0 &= i1;
  l21 = i0;
  if (i0) {goto B41;}
  i0 = 9u;
  l10 = i0;
  i0 = l19;
  i0 = !(i0);
  if (i0) {goto B43;}
  i0 = 9u;
  l10 = i0;
  i0 = l14;
  i1 = 4294967292u;
  i0 += i1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l9 = i0;
  i0 = !(i0);
  if (i0) {goto B43;}
  i0 = 10u;
  p3 = i0;
  i0 = 0u;
  l10 = i0;
  i0 = l9;
  i1 = 10u;
  i0 = REM_U(i0, i1);
  if (i0) {goto B43;}
  L44: 
    i0 = l10;
    i1 = 1u;
    i0 += i1;
    l10 = i0;
    i0 = l9;
    i1 = p3;
    i2 = 10u;
    i1 *= i2;
    p3 = i1;
    i0 = REM_U(i0, i1);
    i0 = !(i0);
    if (i0) {goto L44;}
  B43:;
  i0 = l14;
  i1 = l15;
  i0 -= i1;
  i1 = 2u;
  i0 = (u32)((s32)i0 >> (i1 & 31));
  i1 = 9u;
  i0 *= i1;
  i1 = 4294967287u;
  i0 += i1;
  p3 = i0;
  i0 = p5;
  i1 = 32u;
  i0 |= i1;
  i1 = 102u;
  i0 = i0 != i1;
  if (i0) {goto B45;}
  i0 = 0u;
  l21 = i0;
  i0 = l13;
  i1 = p3;
  i2 = l10;
  i1 -= i2;
  l10 = i1;
  i2 = 0u;
  i3 = l10;
  i4 = 0u;
  i3 = (u32)((s32)i3 > (s32)i4);
  i1 = i3 ? i1 : i2;
  l10 = i1;
  i2 = l13;
  i3 = l10;
  i2 = (u32)((s32)i2 < (s32)i3);
  i0 = i2 ? i0 : i1;
  l13 = i0;
  goto B41;
  B45:;
  i0 = 0u;
  l21 = i0;
  i0 = l13;
  i1 = p3;
  i2 = l16;
  i1 += i2;
  i2 = l10;
  i1 -= i2;
  l10 = i1;
  i2 = 0u;
  i3 = l10;
  i4 = 0u;
  i3 = (u32)((s32)i3 > (s32)i4);
  i1 = i3 ? i1 : i2;
  l10 = i1;
  i2 = l13;
  i3 = l10;
  i2 = (u32)((s32)i2 < (s32)i3);
  i0 = i2 ? i0 : i1;
  l13 = i0;
  B41:;
  i0 = l13;
  i1 = l21;
  i0 |= i1;
  l12 = i0;
  i1 = 0u;
  i0 = i0 != i1;
  p3 = i0;
  i0 = p5;
  i1 = 32u;
  i0 |= i1;
  l20 = i0;
  i1 = 102u;
  i0 = i0 != i1;
  if (i0) {goto B47;}
  i0 = l16;
  i1 = 0u;
  i2 = l16;
  i3 = 0u;
  i2 = (u32)((s32)i2 > (s32)i3);
  i0 = i2 ? i0 : i1;
  l10 = i0;
  goto B46;
  B47:;
  i0 = l11;
  i1 = l16;
  i2 = l16;
  i3 = 31u;
  i2 = (u32)((s32)i2 >> (i3 & 31));
  l10 = i2;
  i1 += i2;
  i2 = l10;
  i1 ^= i2;
  j1 = (u64)(i1);
  i2 = l11;
  i1 = f33(j1, i2);
  l10 = i1;
  i0 -= i1;
  i1 = 1u;
  i0 = (u32)((s32)i0 > (s32)i1);
  if (i0) {goto B48;}
  L49: 
    i0 = l10;
    i1 = 4294967295u;
    i0 += i1;
    l10 = i0;
    i1 = 48u;
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    i0 = l11;
    i1 = l10;
    i0 -= i1;
    i1 = 2u;
    i0 = (u32)((s32)i0 < (s32)i1);
    if (i0) {goto L49;}
  B48:;
  i0 = l10;
  i1 = 4294967294u;
  i0 += i1;
  l18 = i0;
  i1 = p5;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = l10;
  i1 = 4294967295u;
  i0 += i1;
  i1 = 45u;
  i2 = 43u;
  i3 = l16;
  i4 = 0u;
  i3 = (u32)((s32)i3 < (s32)i4);
  i1 = i3 ? i1 : i2;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = l11;
  i1 = l18;
  i0 -= i1;
  l10 = i0;
  B46:;
  i0 = p0;
  i1 = 32u;
  i2 = p2;
  i3 = l7;
  i4 = l13;
  i3 += i4;
  i4 = p3;
  i3 += i4;
  i4 = l10;
  i3 += i4;
  i4 = 1u;
  i3 += i4;
  l9 = i3;
  i4 = p4;
  f30(i0, i1, i2, i3, i4);
  i0 = p0;
  i1 = l8;
  i2 = l7;
  f27(i0, i1, i2);
  i0 = p0;
  i1 = 48u;
  i2 = p2;
  i3 = l9;
  i4 = p4;
  i5 = 65536u;
  i4 ^= i5;
  f30(i0, i1, i2, i3, i4);
  i0 = l20;
  i1 = 102u;
  i0 = i0 != i1;
  if (i0) {goto B53;}
  i0 = l6;
  i1 = 16u;
  i0 += i1;
  i1 = 8u;
  i0 |= i1;
  l20 = i0;
  i0 = l6;
  i1 = 16u;
  i0 += i1;
  i1 = 9u;
  i0 |= i1;
  l16 = i0;
  i0 = l15;
  i1 = l17;
  i2 = l17;
  i3 = l15;
  i2 = i2 > i3;
  i0 = i2 ? i0 : i1;
  p3 = i0;
  l17 = i0;
  L54: 
    i0 = l17;
    j0 = i64_load32_u(Z_envZ_memory, (u64)(i0));
    i1 = l16;
    i0 = f33(j0, i1);
    l10 = i0;
    i0 = l17;
    i1 = p3;
    i0 = i0 == i1;
    if (i0) {goto B56;}
    i0 = l10;
    i1 = l6;
    i2 = 16u;
    i1 += i2;
    i0 = i0 <= i1;
    if (i0) {goto B55;}
    L57: 
      i0 = l10;
      i1 = 4294967295u;
      i0 += i1;
      l10 = i0;
      i1 = 48u;
      i32_store8(Z_envZ_memory, (u64)(i0), i1);
      i0 = l10;
      i1 = l6;
      i2 = 16u;
      i1 += i2;
      i0 = i0 > i1;
      if (i0) {goto L57;}
      goto B55;
    UNREACHABLE;
    B56:;
    i0 = l10;
    i1 = l16;
    i0 = i0 != i1;
    if (i0) {goto B55;}
    i0 = l6;
    i1 = 48u;
    i32_store8(Z_envZ_memory, (u64)(i0 + 24), i1);
    i0 = l20;
    l10 = i0;
    B55:;
    i0 = p0;
    i1 = l10;
    i2 = l16;
    i3 = l10;
    i2 -= i3;
    f27(i0, i1, i2);
    i0 = l17;
    i1 = 4u;
    i0 += i1;
    l17 = i0;
    i1 = l15;
    i0 = i0 <= i1;
    if (i0) {goto L54;}
  i0 = l12;
  i0 = !(i0);
  if (i0) {goto B58;}
  i0 = p0;
  i1 = 1635u;
  i2 = 1u;
  f27(i0, i1, i2);
  B58:;
  i0 = l17;
  i1 = l14;
  i0 = i0 >= i1;
  if (i0) {goto B52;}
  i0 = l13;
  i1 = 1u;
  i0 = (u32)((s32)i0 < (s32)i1);
  if (i0) {goto B52;}
  L59: 
    i0 = l17;
    j0 = i64_load32_u(Z_envZ_memory, (u64)(i0));
    i1 = l16;
    i0 = f33(j0, i1);
    l10 = i0;
    i1 = l6;
    i2 = 16u;
    i1 += i2;
    i0 = i0 <= i1;
    if (i0) {goto B60;}
    L61: 
      i0 = l10;
      i1 = 4294967295u;
      i0 += i1;
      l10 = i0;
      i1 = 48u;
      i32_store8(Z_envZ_memory, (u64)(i0), i1);
      i0 = l10;
      i1 = l6;
      i2 = 16u;
      i1 += i2;
      i0 = i0 > i1;
      if (i0) {goto L61;}
    B60:;
    i0 = p0;
    i1 = l10;
    i2 = l13;
    i3 = 9u;
    i4 = l13;
    i5 = 9u;
    i4 = (u32)((s32)i4 < (s32)i5);
    i2 = i4 ? i2 : i3;
    f27(i0, i1, i2);
    i0 = l13;
    i1 = 4294967287u;
    i0 += i1;
    l10 = i0;
    i0 = l17;
    i1 = 4u;
    i0 += i1;
    l17 = i0;
    i1 = l14;
    i0 = i0 >= i1;
    if (i0) {goto B51;}
    i0 = l13;
    i1 = 9u;
    i0 = (u32)((s32)i0 > (s32)i1);
    p3 = i0;
    i0 = l10;
    l13 = i0;
    i0 = p3;
    if (i0) {goto L59;}
    goto B51;
  UNREACHABLE;
  B53:;
  i0 = l13;
  i1 = 0u;
  i0 = (u32)((s32)i0 < (s32)i1);
  if (i0) {goto B62;}
  i0 = l14;
  i1 = l17;
  i2 = 4u;
  i1 += i2;
  i2 = l19;
  i0 = i2 ? i0 : i1;
  l20 = i0;
  i0 = l6;
  i1 = 16u;
  i0 += i1;
  i1 = 8u;
  i0 |= i1;
  l15 = i0;
  i0 = l6;
  i1 = 16u;
  i0 += i1;
  i1 = 9u;
  i0 |= i1;
  l14 = i0;
  i0 = l17;
  l16 = i0;
  L63: 
    i0 = l16;
    j0 = i64_load32_u(Z_envZ_memory, (u64)(i0));
    i1 = l14;
    i0 = f33(j0, i1);
    l10 = i0;
    i1 = l14;
    i0 = i0 != i1;
    if (i0) {goto B64;}
    i0 = l6;
    i1 = 48u;
    i32_store8(Z_envZ_memory, (u64)(i0 + 24), i1);
    i0 = l15;
    l10 = i0;
    B64:;
    i0 = l16;
    i1 = l17;
    i0 = i0 == i1;
    if (i0) {goto B66;}
    i0 = l10;
    i1 = l6;
    i2 = 16u;
    i1 += i2;
    i0 = i0 <= i1;
    if (i0) {goto B65;}
    L67: 
      i0 = l10;
      i1 = 4294967295u;
      i0 += i1;
      l10 = i0;
      i1 = 48u;
      i32_store8(Z_envZ_memory, (u64)(i0), i1);
      i0 = l10;
      i1 = l6;
      i2 = 16u;
      i1 += i2;
      i0 = i0 > i1;
      if (i0) {goto L67;}
      goto B65;
    UNREACHABLE;
    B66:;
    i0 = p0;
    i1 = l10;
    i2 = 1u;
    f27(i0, i1, i2);
    i0 = l10;
    i1 = 1u;
    i0 += i1;
    l10 = i0;
    i0 = l21;
    if (i0) {goto B68;}
    i0 = l13;
    i1 = 1u;
    i0 = (u32)((s32)i0 < (s32)i1);
    if (i0) {goto B65;}
    B68:;
    i0 = p0;
    i1 = 1635u;
    i2 = 1u;
    f27(i0, i1, i2);
    B65:;
    i0 = p0;
    i1 = l10;
    i2 = l14;
    i3 = l10;
    i2 -= i3;
    p3 = i2;
    i3 = l13;
    i4 = l13;
    i5 = p3;
    i4 = (u32)((s32)i4 > (s32)i5);
    i2 = i4 ? i2 : i3;
    f27(i0, i1, i2);
    i0 = l13;
    i1 = p3;
    i0 -= i1;
    l13 = i0;
    i0 = l16;
    i1 = 4u;
    i0 += i1;
    l16 = i0;
    i1 = l20;
    i0 = i0 >= i1;
    if (i0) {goto B62;}
    i0 = l13;
    i1 = 4294967295u;
    i0 = (u32)((s32)i0 > (s32)i1);
    if (i0) {goto L63;}
  B62:;
  i0 = p0;
  i1 = 48u;
  i2 = l13;
  i3 = 18u;
  i2 += i3;
  i3 = 18u;
  i4 = 0u;
  f30(i0, i1, i2, i3, i4);
  i0 = p0;
  i1 = l18;
  i2 = l11;
  i3 = l18;
  i2 -= i3;
  f27(i0, i1, i2);
  goto B50;
  B52:;
  i0 = l13;
  l10 = i0;
  B51:;
  i0 = p0;
  i1 = 48u;
  i2 = l10;
  i3 = 9u;
  i2 += i3;
  i3 = 9u;
  i4 = 0u;
  f30(i0, i1, i2, i3, i4);
  B50:;
  i0 = p0;
  i1 = 32u;
  i2 = p2;
  i3 = l9;
  i4 = p4;
  i5 = 8192u;
  i4 ^= i5;
  f30(i0, i1, i2, i3, i4);
  goto B5;
  B7:;
  i0 = l8;
  i1 = 9u;
  i0 += i1;
  i1 = l8;
  i2 = p5;
  i3 = 32u;
  i2 &= i3;
  l16 = i2;
  i0 = i2 ? i0 : i1;
  l13 = i0;
  i0 = p3;
  i1 = 11u;
  i0 = i0 > i1;
  if (i0) {goto B69;}
  i0 = 12u;
  i1 = p3;
  i0 -= i1;
  l10 = i0;
  i0 = !(i0);
  if (i0) {goto B69;}
  d0 = 8;
  l26 = d0;
  L70: 
    d0 = l26;
    d1 = 16;
    d0 *= d1;
    l26 = d0;
    i0 = l10;
    i1 = 4294967295u;
    i0 += i1;
    l10 = i0;
    if (i0) {goto L70;}
  i0 = l13;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
  i1 = 45u;
  i0 = i0 != i1;
  if (i0) {goto B71;}
  d0 = l26;
  d1 = p1;
  d1 = -(d1);
  d2 = l26;
  d1 -= d2;
  d0 += d1;
  d0 = -(d0);
  p1 = d0;
  goto B69;
  B71:;
  d0 = p1;
  d1 = l26;
  d0 += d1;
  d1 = l26;
  d0 -= d1;
  p1 = d0;
  B69:;
  i0 = l6;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 44));
  l10 = i0;
  i1 = l10;
  i2 = 31u;
  i1 = (u32)((s32)i1 >> (i2 & 31));
  l10 = i1;
  i0 += i1;
  i1 = l10;
  i0 ^= i1;
  j0 = (u64)(i0);
  i1 = l11;
  i0 = f33(j0, i1);
  l10 = i0;
  i1 = l11;
  i0 = i0 != i1;
  if (i0) {goto B72;}
  i0 = l6;
  i1 = 48u;
  i32_store8(Z_envZ_memory, (u64)(i0 + 15), i1);
  i0 = l6;
  i1 = 15u;
  i0 += i1;
  l10 = i0;
  B72:;
  i0 = l7;
  i1 = 2u;
  i0 |= i1;
  l21 = i0;
  i0 = l6;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 44));
  l17 = i0;
  i0 = l10;
  i1 = 4294967294u;
  i0 += i1;
  l20 = i0;
  i1 = p5;
  i2 = 15u;
  i1 += i2;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = l10;
  i1 = 4294967295u;
  i0 += i1;
  i1 = 45u;
  i2 = 43u;
  i3 = l17;
  i4 = 0u;
  i3 = (u32)((s32)i3 < (s32)i4);
  i1 = i3 ? i1 : i2;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = p4;
  i1 = 8u;
  i0 &= i1;
  l14 = i0;
  i0 = l6;
  i1 = 16u;
  i0 += i1;
  l17 = i0;
  L73: 
    i0 = l17;
    l10 = i0;
    d0 = p1;
    d0 = fabs(d0);
    d1 = 2147483648;
    i0 = d0 < d1;
    i0 = !(i0);
    if (i0) {goto B75;}
    d0 = p1;
    i0 = I32_TRUNC_S_F64(d0);
    l17 = i0;
    goto B74;
    B75:;
    i0 = 2147483648u;
    l17 = i0;
    B74:;
    i0 = l10;
    i1 = l17;
    i2 = 1584u;
    i1 += i2;
    i1 = i32_load8_u(Z_envZ_memory, (u64)(i1));
    i2 = l16;
    i1 |= i2;
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    d0 = p1;
    i1 = l17;
    d1 = (f64)(s32)(i1);
    d0 -= d1;
    d1 = 16;
    d0 *= d1;
    p1 = d0;
    i0 = l10;
    i1 = 1u;
    i0 += i1;
    l17 = i0;
    i1 = l6;
    i2 = 16u;
    i1 += i2;
    i0 -= i1;
    i1 = 1u;
    i0 = i0 != i1;
    if (i0) {goto B76;}
    i0 = l14;
    if (i0) {goto B77;}
    i0 = p3;
    i1 = 0u;
    i0 = (u32)((s32)i0 > (s32)i1);
    if (i0) {goto B77;}
    d0 = p1;
    d1 = 0;
    i0 = d0 == d1;
    if (i0) {goto B76;}
    B77:;
    i0 = l10;
    i1 = 46u;
    i32_store8(Z_envZ_memory, (u64)(i0 + 1), i1);
    i0 = l10;
    i1 = 2u;
    i0 += i1;
    l17 = i0;
    B76:;
    d0 = p1;
    d1 = 0;
    i0 = d0 != d1;
    if (i0) {goto L73;}
  i0 = p3;
  i0 = !(i0);
  if (i0) {goto B79;}
  i0 = l17;
  i1 = l6;
  i2 = 16u;
  i1 += i2;
  i0 -= i1;
  i1 = 4294967294u;
  i0 += i1;
  i1 = p3;
  i0 = (u32)((s32)i0 >= (s32)i1);
  if (i0) {goto B79;}
  i0 = p3;
  i1 = l11;
  i0 += i1;
  i1 = l20;
  i0 -= i1;
  i1 = 2u;
  i0 += i1;
  l10 = i0;
  goto B78;
  B79:;
  i0 = l11;
  i1 = l6;
  i2 = 16u;
  i1 += i2;
  i0 -= i1;
  i1 = l20;
  i0 -= i1;
  i1 = l17;
  i0 += i1;
  l10 = i0;
  B78:;
  i0 = p0;
  i1 = 32u;
  i2 = p2;
  i3 = l10;
  i4 = l21;
  i3 += i4;
  l9 = i3;
  i4 = p4;
  f30(i0, i1, i2, i3, i4);
  i0 = p0;
  i1 = l13;
  i2 = l21;
  f27(i0, i1, i2);
  i0 = p0;
  i1 = 48u;
  i2 = p2;
  i3 = l9;
  i4 = p4;
  i5 = 65536u;
  i4 ^= i5;
  f30(i0, i1, i2, i3, i4);
  i0 = p0;
  i1 = l6;
  i2 = 16u;
  i1 += i2;
  i2 = l17;
  i3 = l6;
  i4 = 16u;
  i3 += i4;
  i2 -= i3;
  l17 = i2;
  f27(i0, i1, i2);
  i0 = p0;
  i1 = 48u;
  i2 = l10;
  i3 = l17;
  i4 = l11;
  i5 = l20;
  i4 -= i5;
  l16 = i4;
  i3 += i4;
  i2 -= i3;
  i3 = 0u;
  i4 = 0u;
  f30(i0, i1, i2, i3, i4);
  i0 = p0;
  i1 = l20;
  i2 = l16;
  f27(i0, i1, i2);
  i0 = p0;
  i1 = 32u;
  i2 = p2;
  i3 = l9;
  i4 = p4;
  i5 = 8192u;
  i4 ^= i5;
  f30(i0, i1, i2, i3, i4);
  B5:;
  i0 = l6;
  i1 = 560u;
  i0 += i1;
  l23 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l23;
  g0 = i0;
  i0 = p2;
  i1 = l9;
  i2 = l9;
  i3 = p2;
  i2 = (u32)((s32)i2 < (s32)i3);
  i0 = i2 ? i0 : i1;
  FUNC_EPILOGUE;
  return i0;
}

static void f36(u32 p0, u32 p1) {
  u32 l2 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  u64 j1, j2;
  f64 d1;
  i0 = p1;
  i1 = p1;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  i2 = 15u;
  i1 += i2;
  i2 = 4294967280u;
  i1 &= i2;
  l2 = i1;
  i2 = 16u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = l2;
  j1 = i64_load(Z_envZ_memory, (u64)(i1));
  i2 = l2;
  j2 = i64_load(Z_envZ_memory, (u64)(i2 + 8));
  d1 = f24(j1, j2);
  f64_store(Z_envZ_memory, (u64)(i0), d1);
  FUNC_EPILOGUE;
}

static u64 f37(f64 p0) {
  FUNC_PROLOGUE;
  u64 j0;
  f64 d0;
  d0 = p0;
  j0 = i64_reinterpret_f64(d0);
  FUNC_EPILOGUE;
  return j0;
}

static u32 malloc(u32 p0) {
  u32 l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0, l6 = 0, l7 = 0, l8 = 0, 
      l9 = 0, l10 = 0, l11 = 0, l12 = 0, l13 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3, i4, i5;
  u64 j1;
  i0 = g0;
  i1 = 16u;
  i0 -= i1;
  l1 = i0;
  l12 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l12;
  g0 = i0;
  i0 = p0;
  i1 = 244u;
  i0 = i0 > i1;
  if (i0) {goto B13;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2116));
  l2 = i0;
  i1 = 16u;
  i2 = p0;
  i3 = 11u;
  i2 += i3;
  i3 = 4294967288u;
  i2 &= i3;
  i3 = p0;
  i4 = 11u;
  i3 = i3 < i4;
  i1 = i3 ? i1 : i2;
  l3 = i1;
  i2 = 3u;
  i1 >>= (i2 & 31);
  l4 = i1;
  i0 >>= (i1 & 31);
  p0 = i0;
  i1 = 3u;
  i0 &= i1;
  i0 = !(i0);
  if (i0) {goto B14;}
  i0 = p0;
  i1 = 4294967295u;
  i0 ^= i1;
  i1 = 1u;
  i0 &= i1;
  i1 = l4;
  i0 += i1;
  l3 = i0;
  i1 = 3u;
  i0 <<= (i1 & 31);
  l5 = i0;
  i1 = 2164u;
  i0 += i1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l4 = i0;
  i1 = 8u;
  i0 += i1;
  p0 = i0;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l6 = i0;
  i1 = l5;
  i2 = 2156u;
  i1 += i2;
  l5 = i1;
  i0 = i0 != i1;
  if (i0) {goto B16;}
  i0 = 0u;
  i1 = l2;
  i2 = 4294967294u;
  i3 = l3;
  i2 = I32_ROTL(i2, i3);
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2116), i1);
  goto B15;
  B16:;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2132));
  i1 = l6;
  i0 = i0 > i1;
  i0 = l6;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l5;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  B15:;
  i0 = l4;
  i1 = l3;
  i2 = 3u;
  i1 <<= (i2 & 31);
  l6 = i1;
  i2 = 3u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l4;
  i1 = l6;
  i0 += i1;
  l4 = i0;
  i1 = l4;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 4));
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  goto B2;
  B14:;
  i0 = l3;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2124));
  l7 = i1;
  i0 = i0 <= i1;
  if (i0) {goto B12;}
  i0 = p0;
  i0 = !(i0);
  if (i0) {goto B17;}
  i0 = p0;
  i1 = l4;
  i0 <<= (i1 & 31);
  i1 = 2u;
  i2 = l4;
  i1 <<= (i2 & 31);
  p0 = i1;
  i2 = 0u;
  i3 = p0;
  i2 -= i3;
  i1 |= i2;
  i0 &= i1;
  p0 = i0;
  i1 = 0u;
  i2 = p0;
  i1 -= i2;
  i0 &= i1;
  i1 = 4294967295u;
  i0 += i1;
  p0 = i0;
  i1 = p0;
  i2 = 12u;
  i1 >>= (i2 & 31);
  i2 = 16u;
  i1 &= i2;
  p0 = i1;
  i0 >>= (i1 & 31);
  l4 = i0;
  i1 = 5u;
  i0 >>= (i1 & 31);
  i1 = 8u;
  i0 &= i1;
  l6 = i0;
  i1 = p0;
  i0 |= i1;
  i1 = l4;
  i2 = l6;
  i1 >>= (i2 & 31);
  p0 = i1;
  i2 = 2u;
  i1 >>= (i2 & 31);
  i2 = 4u;
  i1 &= i2;
  l4 = i1;
  i0 |= i1;
  i1 = p0;
  i2 = l4;
  i1 >>= (i2 & 31);
  p0 = i1;
  i2 = 1u;
  i1 >>= (i2 & 31);
  i2 = 2u;
  i1 &= i2;
  l4 = i1;
  i0 |= i1;
  i1 = p0;
  i2 = l4;
  i1 >>= (i2 & 31);
  p0 = i1;
  i2 = 1u;
  i1 >>= (i2 & 31);
  i2 = 1u;
  i1 &= i2;
  l4 = i1;
  i0 |= i1;
  i1 = p0;
  i2 = l4;
  i1 >>= (i2 & 31);
  i0 += i1;
  l6 = i0;
  i1 = 3u;
  i0 <<= (i1 & 31);
  l5 = i0;
  i1 = 2164u;
  i0 += i1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l4 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  p0 = i0;
  i1 = l5;
  i2 = 2156u;
  i1 += i2;
  l5 = i1;
  i0 = i0 != i1;
  if (i0) {goto B19;}
  i0 = 0u;
  i1 = l2;
  i2 = 4294967294u;
  i3 = l6;
  i2 = I32_ROTL(i2, i3);
  i1 &= i2;
  l2 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2116), i1);
  goto B18;
  B19:;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2132));
  i1 = p0;
  i0 = i0 > i1;
  i0 = p0;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l5;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  B18:;
  i0 = l4;
  i1 = 8u;
  i0 += i1;
  p0 = i0;
  i0 = l4;
  i1 = l3;
  i2 = 3u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l4;
  i1 = l3;
  i0 += i1;
  l5 = i0;
  i1 = l6;
  i2 = 3u;
  i1 <<= (i2 & 31);
  l8 = i1;
  i2 = l3;
  i1 -= i2;
  l6 = i1;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l4;
  i1 = l8;
  i0 += i1;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l7;
  i0 = !(i0);
  if (i0) {goto B20;}
  i0 = l7;
  i1 = 3u;
  i0 >>= (i1 & 31);
  l8 = i0;
  i1 = 3u;
  i0 <<= (i1 & 31);
  i1 = 2156u;
  i0 += i1;
  l3 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2136));
  l4 = i0;
  i0 = l2;
  i1 = 1u;
  i2 = l8;
  i1 <<= (i2 & 31);
  l8 = i1;
  i0 &= i1;
  if (i0) {goto B22;}
  i0 = 0u;
  i1 = l2;
  i2 = l8;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2116), i1);
  i0 = l3;
  l8 = i0;
  goto B21;
  B22:;
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l8 = i0;
  B21:;
  i0 = l3;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l8;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l4;
  i1 = l3;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l4;
  i1 = l8;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  B20:;
  i0 = 0u;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 2136), i1);
  i0 = 0u;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 2124), i1);
  goto B2;
  B17:;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2120));
  l9 = i0;
  i0 = !(i0);
  if (i0) {goto B12;}
  i0 = l9;
  i1 = 0u;
  i2 = l9;
  i1 -= i2;
  i0 &= i1;
  i1 = 4294967295u;
  i0 += i1;
  p0 = i0;
  i1 = p0;
  i2 = 12u;
  i1 >>= (i2 & 31);
  i2 = 16u;
  i1 &= i2;
  p0 = i1;
  i0 >>= (i1 & 31);
  l4 = i0;
  i1 = 5u;
  i0 >>= (i1 & 31);
  i1 = 8u;
  i0 &= i1;
  l6 = i0;
  i1 = p0;
  i0 |= i1;
  i1 = l4;
  i2 = l6;
  i1 >>= (i2 & 31);
  p0 = i1;
  i2 = 2u;
  i1 >>= (i2 & 31);
  i2 = 4u;
  i1 &= i2;
  l4 = i1;
  i0 |= i1;
  i1 = p0;
  i2 = l4;
  i1 >>= (i2 & 31);
  p0 = i1;
  i2 = 1u;
  i1 >>= (i2 & 31);
  i2 = 2u;
  i1 &= i2;
  l4 = i1;
  i0 |= i1;
  i1 = p0;
  i2 = l4;
  i1 >>= (i2 & 31);
  p0 = i1;
  i2 = 1u;
  i1 >>= (i2 & 31);
  i2 = 1u;
  i1 &= i2;
  l4 = i1;
  i0 |= i1;
  i1 = p0;
  i2 = l4;
  i1 >>= (i2 & 31);
  i0 += i1;
  i1 = 2u;
  i0 <<= (i1 & 31);
  i1 = 2420u;
  i0 += i1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l5 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
  i1 = 4294967288u;
  i0 &= i1;
  i1 = l3;
  i0 -= i1;
  l4 = i0;
  i0 = l5;
  l6 = i0;
  L24: 
    i0 = l6;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
    p0 = i0;
    if (i0) {goto B25;}
    i0 = l6;
    i1 = 20u;
    i0 += i1;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    p0 = i0;
    i0 = !(i0);
    if (i0) {goto B23;}
    B25:;
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
    i1 = 4294967288u;
    i0 &= i1;
    i1 = l3;
    i0 -= i1;
    l6 = i0;
    i1 = l4;
    i2 = l6;
    i3 = l4;
    i2 = i2 < i3;
    l6 = i2;
    i0 = i2 ? i0 : i1;
    l4 = i0;
    i0 = p0;
    i1 = l5;
    i2 = l6;
    i0 = i2 ? i0 : i1;
    l5 = i0;
    i0 = p0;
    l6 = i0;
    goto L24;
  UNREACHABLE;
  B23:;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
  l10 = i0;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  l8 = i0;
  i1 = l5;
  i0 = i0 == i1;
  if (i0) {goto B26;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2132));
  i1 = l5;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 8));
  p0 = i1;
  i0 = i0 > i1;
  if (i0) {goto B27;}
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  i1 = l5;
  i0 = i0 != i1;
  B27:;
  i0 = p0;
  i1 = l8;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l8;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B3;
  B26:;
  i0 = l5;
  i1 = 20u;
  i0 += i1;
  l6 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  p0 = i0;
  if (i0) {goto B28;}
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
  p0 = i0;
  i0 = !(i0);
  if (i0) {goto B11;}
  i0 = l5;
  i1 = 16u;
  i0 += i1;
  l6 = i0;
  B28:;
  L29: 
    i0 = l6;
    l11 = i0;
    i0 = p0;
    l8 = i0;
    i1 = 20u;
    i0 += i1;
    l6 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    p0 = i0;
    if (i0) {goto L29;}
    i0 = l8;
    i1 = 16u;
    i0 += i1;
    l6 = i0;
    i0 = l8;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
    p0 = i0;
    if (i0) {goto L29;}
  i0 = l11;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  goto B3;
  B13:;
  i0 = 4294967295u;
  l3 = i0;
  i0 = p0;
  i1 = 4294967231u;
  i0 = i0 > i1;
  if (i0) {goto B12;}
  i0 = p0;
  i1 = 11u;
  i0 += i1;
  p0 = i0;
  i1 = 4294967288u;
  i0 &= i1;
  l3 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2120));
  l7 = i0;
  i0 = !(i0);
  if (i0) {goto B12;}
  i0 = 0u;
  l11 = i0;
  i0 = p0;
  i1 = 8u;
  i0 >>= (i1 & 31);
  p0 = i0;
  i0 = !(i0);
  if (i0) {goto B30;}
  i0 = 31u;
  l11 = i0;
  i0 = l3;
  i1 = 16777215u;
  i0 = i0 > i1;
  if (i0) {goto B30;}
  i0 = p0;
  i1 = p0;
  i2 = 1048320u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 8u;
  i1 &= i2;
  l4 = i1;
  i0 <<= (i1 & 31);
  p0 = i0;
  i1 = p0;
  i2 = 520192u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 4u;
  i1 &= i2;
  p0 = i1;
  i0 <<= (i1 & 31);
  l6 = i0;
  i1 = l6;
  i2 = 245760u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 2u;
  i1 &= i2;
  l6 = i1;
  i0 <<= (i1 & 31);
  i1 = 15u;
  i0 >>= (i1 & 31);
  i1 = p0;
  i2 = l4;
  i1 |= i2;
  i2 = l6;
  i1 |= i2;
  i0 -= i1;
  p0 = i0;
  i1 = 1u;
  i0 <<= (i1 & 31);
  i1 = l3;
  i2 = p0;
  i3 = 21u;
  i2 += i3;
  i1 >>= (i2 & 31);
  i2 = 1u;
  i1 &= i2;
  i0 |= i1;
  i1 = 28u;
  i0 += i1;
  l11 = i0;
  B30:;
  i0 = 0u;
  i1 = l3;
  i0 -= i1;
  l6 = i0;
  i0 = l11;
  i1 = 2u;
  i0 <<= (i1 & 31);
  i1 = 2420u;
  i0 += i1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l4 = i0;
  if (i0) {goto B34;}
  i0 = 0u;
  p0 = i0;
  i0 = 0u;
  l8 = i0;
  goto B33;
  B34:;
  i0 = l3;
  i1 = 0u;
  i2 = 25u;
  i3 = l11;
  i4 = 1u;
  i3 >>= (i4 & 31);
  i2 -= i3;
  i3 = l11;
  i4 = 31u;
  i3 = i3 == i4;
  i1 = i3 ? i1 : i2;
  i0 <<= (i1 & 31);
  l5 = i0;
  i0 = 0u;
  p0 = i0;
  i0 = 0u;
  l8 = i0;
  L35: 
    i0 = l4;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
    i1 = 4294967288u;
    i0 &= i1;
    i1 = l3;
    i0 -= i1;
    l2 = i0;
    i1 = l6;
    i0 = i0 >= i1;
    if (i0) {goto B36;}
    i0 = l2;
    l6 = i0;
    i0 = l4;
    l8 = i0;
    i0 = l2;
    if (i0) {goto B36;}
    i0 = 0u;
    l6 = i0;
    i0 = l4;
    l8 = i0;
    i0 = l4;
    p0 = i0;
    goto B32;
    B36:;
    i0 = p0;
    i1 = l4;
    i2 = 20u;
    i1 += i2;
    i1 = i32_load(Z_envZ_memory, (u64)(i1));
    l2 = i1;
    i2 = l2;
    i3 = l4;
    i4 = l5;
    i5 = 29u;
    i4 >>= (i5 & 31);
    i5 = 4u;
    i4 &= i5;
    i3 += i4;
    i4 = 16u;
    i3 += i4;
    i3 = i32_load(Z_envZ_memory, (u64)(i3));
    l4 = i3;
    i2 = i2 == i3;
    i0 = i2 ? i0 : i1;
    i1 = p0;
    i2 = l2;
    i0 = i2 ? i0 : i1;
    p0 = i0;
    i0 = l5;
    i1 = l4;
    i2 = 0u;
    i1 = i1 != i2;
    i0 <<= (i1 & 31);
    l5 = i0;
    i0 = l4;
    if (i0) {goto L35;}
  B33:;
  i0 = p0;
  i1 = l8;
  i0 |= i1;
  if (i0) {goto B37;}
  i0 = 2u;
  i1 = l11;
  i0 <<= (i1 & 31);
  p0 = i0;
  i1 = 0u;
  i2 = p0;
  i1 -= i2;
  i0 |= i1;
  i1 = l7;
  i0 &= i1;
  p0 = i0;
  i0 = !(i0);
  if (i0) {goto B12;}
  i0 = p0;
  i1 = 0u;
  i2 = p0;
  i1 -= i2;
  i0 &= i1;
  i1 = 4294967295u;
  i0 += i1;
  p0 = i0;
  i1 = p0;
  i2 = 12u;
  i1 >>= (i2 & 31);
  i2 = 16u;
  i1 &= i2;
  p0 = i1;
  i0 >>= (i1 & 31);
  l4 = i0;
  i1 = 5u;
  i0 >>= (i1 & 31);
  i1 = 8u;
  i0 &= i1;
  l5 = i0;
  i1 = p0;
  i0 |= i1;
  i1 = l4;
  i2 = l5;
  i1 >>= (i2 & 31);
  p0 = i1;
  i2 = 2u;
  i1 >>= (i2 & 31);
  i2 = 4u;
  i1 &= i2;
  l4 = i1;
  i0 |= i1;
  i1 = p0;
  i2 = l4;
  i1 >>= (i2 & 31);
  p0 = i1;
  i2 = 1u;
  i1 >>= (i2 & 31);
  i2 = 2u;
  i1 &= i2;
  l4 = i1;
  i0 |= i1;
  i1 = p0;
  i2 = l4;
  i1 >>= (i2 & 31);
  p0 = i1;
  i2 = 1u;
  i1 >>= (i2 & 31);
  i2 = 1u;
  i1 &= i2;
  l4 = i1;
  i0 |= i1;
  i1 = p0;
  i2 = l4;
  i1 >>= (i2 & 31);
  i0 += i1;
  i1 = 2u;
  i0 <<= (i1 & 31);
  i1 = 2420u;
  i0 += i1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  p0 = i0;
  B37:;
  i0 = p0;
  i0 = !(i0);
  if (i0) {goto B31;}
  B32:;
  L38: 
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
    i1 = 4294967288u;
    i0 &= i1;
    i1 = l3;
    i0 -= i1;
    l2 = i0;
    i1 = l6;
    i0 = i0 < i1;
    l5 = i0;
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
    l4 = i0;
    if (i0) {goto B39;}
    i0 = p0;
    i1 = 20u;
    i0 += i1;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l4 = i0;
    B39:;
    i0 = l2;
    i1 = l6;
    i2 = l5;
    i0 = i2 ? i0 : i1;
    l6 = i0;
    i0 = p0;
    i1 = l8;
    i2 = l5;
    i0 = i2 ? i0 : i1;
    l8 = i0;
    i0 = l4;
    p0 = i0;
    i0 = l4;
    if (i0) {goto L38;}
  B31:;
  i0 = l8;
  i0 = !(i0);
  if (i0) {goto B12;}
  i0 = l6;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2124));
  i2 = l3;
  i1 -= i2;
  i0 = i0 >= i1;
  if (i0) {goto B12;}
  i0 = l8;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
  l11 = i0;
  i0 = l8;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  l5 = i0;
  i1 = l8;
  i0 = i0 == i1;
  if (i0) {goto B40;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2132));
  i1 = l8;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 8));
  p0 = i1;
  i0 = i0 > i1;
  if (i0) {goto B41;}
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  i1 = l8;
  i0 = i0 != i1;
  B41:;
  i0 = p0;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l5;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B4;
  B40:;
  i0 = l8;
  i1 = 20u;
  i0 += i1;
  l4 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  p0 = i0;
  if (i0) {goto B42;}
  i0 = l8;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
  p0 = i0;
  i0 = !(i0);
  if (i0) {goto B10;}
  i0 = l8;
  i1 = 16u;
  i0 += i1;
  l4 = i0;
  B42:;
  L43: 
    i0 = l4;
    l2 = i0;
    i0 = p0;
    l5 = i0;
    i1 = 20u;
    i0 += i1;
    l4 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    p0 = i0;
    if (i0) {goto L43;}
    i0 = l5;
    i1 = 16u;
    i0 += i1;
    l4 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
    p0 = i0;
    if (i0) {goto L43;}
  i0 = l2;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  goto B4;
  B12:;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2124));
  p0 = i0;
  i1 = l3;
  i0 = i0 < i1;
  if (i0) {goto B44;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2136));
  l4 = i0;
  i0 = p0;
  i1 = l3;
  i0 -= i1;
  l6 = i0;
  i1 = 16u;
  i0 = i0 < i1;
  if (i0) {goto B46;}
  i0 = 0u;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 2124), i1);
  i0 = 0u;
  i1 = l4;
  i2 = l3;
  i1 += i2;
  l5 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2136), i1);
  i0 = l5;
  i1 = l6;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l4;
  i1 = p0;
  i0 += i1;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l4;
  i1 = l3;
  i2 = 3u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  goto B45;
  B46:;
  i0 = 0u;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 2136), i1);
  i0 = 0u;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 2124), i1);
  i0 = l4;
  i1 = p0;
  i2 = 3u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l4;
  i1 = p0;
  i0 += i1;
  p0 = i0;
  i1 = p0;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 4));
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  B45:;
  i0 = l4;
  i1 = 8u;
  i0 += i1;
  p0 = i0;
  goto B2;
  B44:;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2128));
  l5 = i0;
  i1 = l3;
  i0 = i0 <= i1;
  if (i0) {goto B47;}
  i0 = 0u;
  i1 = l5;
  i2 = l3;
  i1 -= i2;
  l4 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2128), i1);
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2140));
  p0 = i1;
  i2 = l3;
  i1 += i2;
  l6 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2140), i1);
  i0 = l6;
  i1 = l4;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = p0;
  i1 = l3;
  i2 = 3u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = p0;
  i1 = 8u;
  i0 += i1;
  p0 = i0;
  goto B2;
  B47:;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2588));
  i0 = !(i0);
  if (i0) {goto B49;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2596));
  l4 = i0;
  goto B48;
  B49:;
  i0 = 0u;
  j1 = 18446744073709551615ull;
  i64_store(Z_envZ_memory, (u64)(i0 + 2600), j1);
  i0 = 0u;
  j1 = 17592186048512ull;
  i64_store(Z_envZ_memory, (u64)(i0 + 2592), j1);
  i0 = 0u;
  i1 = l1;
  i2 = 12u;
  i1 += i2;
  i2 = 4294967280u;
  i1 &= i2;
  i2 = 1431655768u;
  i1 ^= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2588), i1);
  i0 = 0u;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 2608), i1);
  i0 = 0u;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 2560), i1);
  i0 = 4096u;
  l4 = i0;
  B48:;
  i0 = 0u;
  p0 = i0;
  i0 = l4;
  i1 = l3;
  i2 = 47u;
  i1 += i2;
  l7 = i1;
  i0 += i1;
  l2 = i0;
  i1 = 0u;
  i2 = l4;
  i1 -= i2;
  l11 = i1;
  i0 &= i1;
  l8 = i0;
  i1 = l3;
  i0 = i0 <= i1;
  if (i0) {goto B2;}
  i0 = 0u;
  p0 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2556));
  l4 = i0;
  i0 = !(i0);
  if (i0) {goto B50;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2548));
  l6 = i0;
  i1 = l8;
  i0 += i1;
  l9 = i0;
  i1 = l6;
  i0 = i0 <= i1;
  if (i0) {goto B2;}
  i0 = l9;
  i1 = l4;
  i0 = i0 > i1;
  if (i0) {goto B2;}
  B50:;
  i0 = 0u;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 2560));
  i1 = 4u;
  i0 &= i1;
  if (i0) {goto B7;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2140));
  l4 = i0;
  i0 = !(i0);
  if (i0) {goto B53;}
  i0 = 2564u;
  p0 = i0;
  L54: 
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l6 = i0;
    i1 = l4;
    i0 = i0 > i1;
    if (i0) {goto B55;}
    i0 = l6;
    i1 = p0;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 4));
    i0 += i1;
    i1 = l4;
    i0 = i0 > i1;
    if (i0) {goto B52;}
    B55:;
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
    p0 = i0;
    if (i0) {goto L54;}
  B53:;
  i0 = 0u;
  i0 = f40(i0);
  l5 = i0;
  i1 = 4294967295u;
  i0 = i0 == i1;
  if (i0) {goto B8;}
  i0 = l8;
  l2 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2592));
  p0 = i0;
  i1 = 4294967295u;
  i0 += i1;
  l4 = i0;
  i1 = l5;
  i0 &= i1;
  i0 = !(i0);
  if (i0) {goto B56;}
  i0 = l8;
  i1 = l5;
  i0 -= i1;
  i1 = l4;
  i2 = l5;
  i1 += i2;
  i2 = 0u;
  i3 = p0;
  i2 -= i3;
  i1 &= i2;
  i0 += i1;
  l2 = i0;
  B56:;
  i0 = l2;
  i1 = l3;
  i0 = i0 <= i1;
  if (i0) {goto B8;}
  i0 = l2;
  i1 = 2147483646u;
  i0 = i0 > i1;
  if (i0) {goto B8;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2556));
  p0 = i0;
  i0 = !(i0);
  if (i0) {goto B57;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2548));
  l4 = i0;
  i1 = l2;
  i0 += i1;
  l6 = i0;
  i1 = l4;
  i0 = i0 <= i1;
  if (i0) {goto B8;}
  i0 = l6;
  i1 = p0;
  i0 = i0 > i1;
  if (i0) {goto B8;}
  B57:;
  i0 = l2;
  i0 = f40(i0);
  p0 = i0;
  i1 = l5;
  i0 = i0 != i1;
  if (i0) {goto B51;}
  goto B6;
  B52:;
  i0 = l2;
  i1 = l5;
  i0 -= i1;
  i1 = l11;
  i0 &= i1;
  l2 = i0;
  i1 = 2147483646u;
  i0 = i0 > i1;
  if (i0) {goto B8;}
  i0 = l2;
  i0 = f40(i0);
  l5 = i0;
  i1 = p0;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  i2 = p0;
  i2 = i32_load(Z_envZ_memory, (u64)(i2 + 4));
  i1 += i2;
  i0 = i0 == i1;
  if (i0) {goto B9;}
  i0 = l5;
  p0 = i0;
  B51:;
  i0 = l3;
  i1 = 48u;
  i0 += i1;
  i1 = l2;
  i0 = i0 <= i1;
  if (i0) {goto B58;}
  i0 = p0;
  i1 = 4294967295u;
  i0 = i0 == i1;
  if (i0) {goto B58;}
  i0 = l7;
  i1 = l2;
  i0 -= i1;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2596));
  l4 = i1;
  i0 += i1;
  i1 = 0u;
  i2 = l4;
  i1 -= i2;
  i0 &= i1;
  l4 = i0;
  i1 = 2147483646u;
  i0 = i0 <= i1;
  if (i0) {goto B59;}
  i0 = p0;
  l5 = i0;
  goto B6;
  B59:;
  i0 = l4;
  i0 = f40(i0);
  i1 = 4294967295u;
  i0 = i0 == i1;
  if (i0) {goto B60;}
  i0 = l4;
  i1 = l2;
  i0 += i1;
  l2 = i0;
  i0 = p0;
  l5 = i0;
  goto B6;
  B60:;
  i0 = 0u;
  i1 = l2;
  i0 -= i1;
  i0 = f40(i0);
  goto B8;
  B58:;
  i0 = p0;
  l5 = i0;
  i0 = p0;
  i1 = 4294967295u;
  i0 = i0 != i1;
  if (i0) {goto B6;}
  goto B8;
  B11:;
  i0 = 0u;
  l8 = i0;
  goto B3;
  B10:;
  i0 = 0u;
  l5 = i0;
  goto B4;
  B9:;
  i0 = l5;
  i1 = 4294967295u;
  i0 = i0 != i1;
  if (i0) {goto B6;}
  B8:;
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2560));
  i2 = 4u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2560), i1);
  B7:;
  i0 = l8;
  i1 = 2147483646u;
  i0 = i0 > i1;
  if (i0) {goto B5;}
  i0 = l8;
  i0 = f40(i0);
  l5 = i0;
  i1 = 0u;
  i1 = f40(i1);
  p0 = i1;
  i0 = i0 >= i1;
  if (i0) {goto B5;}
  i0 = l5;
  i1 = 4294967295u;
  i0 = i0 == i1;
  if (i0) {goto B5;}
  i0 = p0;
  i1 = 4294967295u;
  i0 = i0 == i1;
  if (i0) {goto B5;}
  i0 = p0;
  i1 = l5;
  i0 -= i1;
  l2 = i0;
  i1 = l3;
  i2 = 40u;
  i1 += i2;
  i0 = i0 <= i1;
  if (i0) {goto B5;}
  B6:;
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2548));
  i2 = l2;
  i1 += i2;
  p0 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2548), i1);
  i0 = p0;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2552));
  i0 = i0 <= i1;
  if (i0) {goto B61;}
  i0 = 0u;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 2552), i1);
  B61:;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2140));
  l4 = i0;
  i0 = !(i0);
  if (i0) {goto B65;}
  i0 = 2564u;
  p0 = i0;
  L66: 
    i0 = l5;
    i1 = p0;
    i1 = i32_load(Z_envZ_memory, (u64)(i1));
    l6 = i1;
    i2 = p0;
    i2 = i32_load(Z_envZ_memory, (u64)(i2 + 4));
    l8 = i2;
    i1 += i2;
    i0 = i0 == i1;
    if (i0) {goto B64;}
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
    p0 = i0;
    if (i0) {goto L66;}
    goto B63;
  UNREACHABLE;
  B65:;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2132));
  p0 = i0;
  i0 = !(i0);
  if (i0) {goto B68;}
  i0 = l5;
  i1 = p0;
  i0 = i0 >= i1;
  if (i0) {goto B67;}
  B68:;
  i0 = 0u;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 2132), i1);
  B67:;
  i0 = 0u;
  p0 = i0;
  i0 = 0u;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2568), i1);
  i0 = 0u;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 2564), i1);
  i0 = 0u;
  i1 = 4294967295u;
  i32_store(Z_envZ_memory, (u64)(i0 + 2148), i1);
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2588));
  i32_store(Z_envZ_memory, (u64)(i0 + 2152), i1);
  i0 = 0u;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 2576), i1);
  L69: 
    i0 = p0;
    i1 = 3u;
    i0 <<= (i1 & 31);
    l4 = i0;
    i1 = 2164u;
    i0 += i1;
    i1 = l4;
    i2 = 2156u;
    i1 += i2;
    l6 = i1;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    i0 = l4;
    i1 = 2168u;
    i0 += i1;
    i1 = l6;
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    i0 = p0;
    i1 = 1u;
    i0 += i1;
    p0 = i0;
    i1 = 32u;
    i0 = i0 != i1;
    if (i0) {goto L69;}
  i0 = 0u;
  i1 = l2;
  i2 = 4294967256u;
  i1 += i2;
  p0 = i1;
  i2 = 4294967288u;
  i3 = l5;
  i2 -= i3;
  i3 = 7u;
  i2 &= i3;
  i3 = 0u;
  i4 = l5;
  i5 = 8u;
  i4 += i5;
  i5 = 7u;
  i4 &= i5;
  i2 = i4 ? i2 : i3;
  l4 = i2;
  i1 -= i2;
  l6 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2128), i1);
  i0 = 0u;
  i1 = l5;
  i2 = l4;
  i1 += i2;
  l4 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2140), i1);
  i0 = l4;
  i1 = l6;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l5;
  i1 = p0;
  i0 += i1;
  i1 = 40u;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2604));
  i32_store(Z_envZ_memory, (u64)(i0 + 2144), i1);
  goto B62;
  B64:;
  i0 = p0;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 12));
  i1 = 8u;
  i0 &= i1;
  if (i0) {goto B63;}
  i0 = l5;
  i1 = l4;
  i0 = i0 <= i1;
  if (i0) {goto B63;}
  i0 = l6;
  i1 = l4;
  i0 = i0 > i1;
  if (i0) {goto B63;}
  i0 = p0;
  i1 = l8;
  i2 = l2;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = 0u;
  i1 = l4;
  i2 = 4294967288u;
  i3 = l4;
  i2 -= i3;
  i3 = 7u;
  i2 &= i3;
  i3 = 0u;
  i4 = l4;
  i5 = 8u;
  i4 += i5;
  i5 = 7u;
  i4 &= i5;
  i2 = i4 ? i2 : i3;
  p0 = i2;
  i1 += i2;
  l6 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2140), i1);
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2128));
  i2 = l2;
  i1 += i2;
  l5 = i1;
  i2 = p0;
  i1 -= i2;
  p0 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2128), i1);
  i0 = l6;
  i1 = p0;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l4;
  i1 = l5;
  i0 += i1;
  i1 = 40u;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2604));
  i32_store(Z_envZ_memory, (u64)(i0 + 2144), i1);
  goto B62;
  B63:;
  i0 = l5;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2132));
  l8 = i1;
  i0 = i0 >= i1;
  if (i0) {goto B70;}
  i0 = 0u;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 2132), i1);
  i0 = l5;
  l8 = i0;
  B70:;
  i0 = l5;
  i1 = l2;
  i0 += i1;
  l6 = i0;
  i0 = 2564u;
  p0 = i0;
  L78: 
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    i1 = l6;
    i0 = i0 == i1;
    if (i0) {goto B77;}
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
    p0 = i0;
    if (i0) {goto L78;}
    goto B76;
  UNREACHABLE;
  B77:;
  i0 = p0;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 12));
  i1 = 8u;
  i0 &= i1;
  i0 = !(i0);
  if (i0) {goto B75;}
  B76:;
  i0 = 2564u;
  p0 = i0;
  L79: 
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l6 = i0;
    i1 = l4;
    i0 = i0 > i1;
    if (i0) {goto B80;}
    i0 = l6;
    i1 = p0;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 4));
    i0 += i1;
    l6 = i0;
    i1 = l4;
    i0 = i0 > i1;
    if (i0) {goto B74;}
    B80:;
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
    p0 = i0;
    goto L79;
  UNREACHABLE;
  B75:;
  i0 = p0;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p0;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 4));
  i2 = l2;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l5;
  i1 = 4294967288u;
  i2 = l5;
  i1 -= i2;
  i2 = 7u;
  i1 &= i2;
  i2 = 0u;
  i3 = l5;
  i4 = 8u;
  i3 += i4;
  i4 = 7u;
  i3 &= i4;
  i1 = i3 ? i1 : i2;
  i0 += i1;
  l11 = i0;
  i1 = l3;
  i2 = 3u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l6;
  i1 = 4294967288u;
  i2 = l6;
  i1 -= i2;
  i2 = 7u;
  i1 &= i2;
  i2 = 0u;
  i3 = l6;
  i4 = 8u;
  i3 += i4;
  i4 = 7u;
  i3 &= i4;
  i1 = i3 ? i1 : i2;
  i0 += i1;
  l5 = i0;
  i1 = l11;
  i0 -= i1;
  i1 = l3;
  i0 -= i1;
  p0 = i0;
  i0 = l11;
  i1 = l3;
  i0 += i1;
  l6 = i0;
  i0 = l4;
  i1 = l5;
  i0 = i0 != i1;
  if (i0) {goto B81;}
  i0 = 0u;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 2140), i1);
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2128));
  i2 = p0;
  i1 += i2;
  p0 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2128), i1);
  i0 = l6;
  i1 = p0;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  goto B72;
  B81:;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2136));
  i1 = l5;
  i0 = i0 != i1;
  if (i0) {goto B82;}
  i0 = 0u;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 2136), i1);
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2124));
  i2 = p0;
  i1 += i2;
  p0 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2124), i1);
  i0 = l6;
  i1 = p0;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l6;
  i1 = p0;
  i0 += i1;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  goto B72;
  B82:;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
  l4 = i0;
  i1 = 3u;
  i0 &= i1;
  i1 = 1u;
  i0 = i0 != i1;
  if (i0) {goto B83;}
  i0 = l4;
  i1 = 4294967288u;
  i0 &= i1;
  l7 = i0;
  i0 = l4;
  i1 = 255u;
  i0 = i0 > i1;
  if (i0) {goto B85;}
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  l3 = i0;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l2 = i0;
  i1 = l4;
  i2 = 3u;
  i1 >>= (i2 & 31);
  l9 = i1;
  i2 = 3u;
  i1 <<= (i2 & 31);
  i2 = 2156u;
  i1 += i2;
  l4 = i1;
  i0 = i0 == i1;
  if (i0) {goto B86;}
  i0 = l8;
  i1 = l2;
  i0 = i0 > i1;
  B86:;
  i0 = l3;
  i1 = l2;
  i0 = i0 != i1;
  if (i0) {goto B87;}
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2116));
  i2 = 4294967294u;
  i3 = l9;
  i2 = I32_ROTL(i2, i3);
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2116), i1);
  goto B84;
  B87:;
  i0 = l3;
  i1 = l4;
  i0 = i0 == i1;
  if (i0) {goto B88;}
  i0 = l8;
  i1 = l3;
  i0 = i0 > i1;
  B88:;
  i0 = l2;
  i1 = l3;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l3;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B84;
  B85:;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
  l9 = i0;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  l2 = i0;
  i1 = l5;
  i0 = i0 == i1;
  if (i0) {goto B90;}
  i0 = l8;
  i1 = l5;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 8));
  l4 = i1;
  i0 = i0 > i1;
  if (i0) {goto B91;}
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  i1 = l5;
  i0 = i0 != i1;
  B91:;
  i0 = l4;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l2;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B89;
  B90:;
  i0 = l5;
  i1 = 20u;
  i0 += i1;
  l4 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l3 = i0;
  if (i0) {goto B92;}
  i0 = l5;
  i1 = 16u;
  i0 += i1;
  l4 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l3 = i0;
  if (i0) {goto B92;}
  i0 = 0u;
  l2 = i0;
  goto B89;
  B92:;
  L93: 
    i0 = l4;
    l8 = i0;
    i0 = l3;
    l2 = i0;
    i1 = 20u;
    i0 += i1;
    l4 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l3 = i0;
    if (i0) {goto L93;}
    i0 = l2;
    i1 = 16u;
    i0 += i1;
    l4 = i0;
    i0 = l2;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
    l3 = i0;
    if (i0) {goto L93;}
  i0 = l8;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  B89:;
  i0 = l9;
  i0 = !(i0);
  if (i0) {goto B84;}
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 28));
  l3 = i0;
  i1 = 2u;
  i0 <<= (i1 & 31);
  i1 = 2420u;
  i0 += i1;
  l4 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  i1 = l5;
  i0 = i0 != i1;
  if (i0) {goto B95;}
  i0 = l4;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l2;
  if (i0) {goto B94;}
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2120));
  i2 = 4294967294u;
  i3 = l3;
  i2 = I32_ROTL(i2, i3);
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2120), i1);
  goto B84;
  B95:;
  i0 = l9;
  i1 = 16u;
  i2 = 20u;
  i3 = l9;
  i3 = i32_load(Z_envZ_memory, (u64)(i3 + 16));
  i4 = l5;
  i3 = i3 == i4;
  i1 = i3 ? i1 : i2;
  i0 += i1;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l2;
  i0 = !(i0);
  if (i0) {goto B84;}
  B94:;
  i0 = l2;
  i1 = l9;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
  l4 = i0;
  i0 = !(i0);
  if (i0) {goto B96;}
  i0 = l2;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = l4;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  B96:;
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 20));
  l4 = i0;
  i0 = !(i0);
  if (i0) {goto B84;}
  i0 = l2;
  i1 = 20u;
  i0 += i1;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l4;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  B84:;
  i0 = l7;
  i1 = p0;
  i0 += i1;
  p0 = i0;
  i0 = l5;
  i1 = l7;
  i0 += i1;
  l5 = i0;
  B83:;
  i0 = l5;
  i1 = l5;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 4));
  i2 = 4294967294u;
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l6;
  i1 = p0;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l6;
  i1 = p0;
  i0 += i1;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = 255u;
  i0 = i0 > i1;
  if (i0) {goto B97;}
  i0 = p0;
  i1 = 3u;
  i0 >>= (i1 & 31);
  l4 = i0;
  i1 = 3u;
  i0 <<= (i1 & 31);
  i1 = 2156u;
  i0 += i1;
  p0 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2116));
  l3 = i0;
  i1 = 1u;
  i2 = l4;
  i1 <<= (i2 & 31);
  l4 = i1;
  i0 &= i1;
  if (i0) {goto B99;}
  i0 = 0u;
  i1 = l3;
  i2 = l4;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2116), i1);
  i0 = p0;
  l4 = i0;
  goto B98;
  B99:;
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l4 = i0;
  B98:;
  i0 = p0;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l4;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l6;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l6;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B72;
  B97:;
  i0 = 0u;
  l4 = i0;
  i0 = p0;
  i1 = 8u;
  i0 >>= (i1 & 31);
  l3 = i0;
  i0 = !(i0);
  if (i0) {goto B100;}
  i0 = 31u;
  l4 = i0;
  i0 = p0;
  i1 = 16777215u;
  i0 = i0 > i1;
  if (i0) {goto B100;}
  i0 = l3;
  i1 = l3;
  i2 = 1048320u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 8u;
  i1 &= i2;
  l4 = i1;
  i0 <<= (i1 & 31);
  l3 = i0;
  i1 = l3;
  i2 = 520192u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 4u;
  i1 &= i2;
  l3 = i1;
  i0 <<= (i1 & 31);
  l5 = i0;
  i1 = l5;
  i2 = 245760u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 2u;
  i1 &= i2;
  l5 = i1;
  i0 <<= (i1 & 31);
  i1 = 15u;
  i0 >>= (i1 & 31);
  i1 = l3;
  i2 = l4;
  i1 |= i2;
  i2 = l5;
  i1 |= i2;
  i0 -= i1;
  l4 = i0;
  i1 = 1u;
  i0 <<= (i1 & 31);
  i1 = p0;
  i2 = l4;
  i3 = 21u;
  i2 += i3;
  i1 >>= (i2 & 31);
  i2 = 1u;
  i1 &= i2;
  i0 |= i1;
  i1 = 28u;
  i0 += i1;
  l4 = i0;
  B100:;
  i0 = l6;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  i0 = l6;
  j1 = 0ull;
  i64_store(Z_envZ_memory, (u64)(i0 + 16), j1);
  i0 = l4;
  i1 = 2u;
  i0 <<= (i1 & 31);
  i1 = 2420u;
  i0 += i1;
  l3 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2120));
  l5 = i0;
  i1 = 1u;
  i2 = l4;
  i1 <<= (i2 & 31);
  l8 = i1;
  i0 &= i1;
  if (i0) {goto B102;}
  i0 = 0u;
  i1 = l5;
  i2 = l8;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2120), i1);
  i0 = l3;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l6;
  i1 = l3;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  goto B101;
  B102:;
  i0 = p0;
  i1 = 0u;
  i2 = 25u;
  i3 = l4;
  i4 = 1u;
  i3 >>= (i4 & 31);
  i2 -= i3;
  i3 = l4;
  i4 = 31u;
  i3 = i3 == i4;
  i1 = i3 ? i1 : i2;
  i0 <<= (i1 & 31);
  l4 = i0;
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l5 = i0;
  L103: 
    i0 = l5;
    l3 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
    i1 = 4294967288u;
    i0 &= i1;
    i1 = p0;
    i0 = i0 == i1;
    if (i0) {goto B73;}
    i0 = l4;
    i1 = 29u;
    i0 >>= (i1 & 31);
    l5 = i0;
    i0 = l4;
    i1 = 1u;
    i0 <<= (i1 & 31);
    l4 = i0;
    i0 = l3;
    i1 = l5;
    i2 = 4u;
    i1 &= i2;
    i0 += i1;
    i1 = 16u;
    i0 += i1;
    l8 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l5 = i0;
    if (i0) {goto L103;}
  i0 = l8;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l6;
  i1 = l3;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  B101:;
  i0 = l6;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l6;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B72;
  B74:;
  i0 = 0u;
  i1 = l2;
  i2 = 4294967256u;
  i1 += i2;
  p0 = i1;
  i2 = 4294967288u;
  i3 = l5;
  i2 -= i3;
  i3 = 7u;
  i2 &= i3;
  i3 = 0u;
  i4 = l5;
  i5 = 8u;
  i4 += i5;
  i5 = 7u;
  i4 &= i5;
  i2 = i4 ? i2 : i3;
  l8 = i2;
  i1 -= i2;
  l11 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2128), i1);
  i0 = 0u;
  i1 = l5;
  i2 = l8;
  i1 += i2;
  l8 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2140), i1);
  i0 = l8;
  i1 = l11;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l5;
  i1 = p0;
  i0 += i1;
  i1 = 40u;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2604));
  i32_store(Z_envZ_memory, (u64)(i0 + 2144), i1);
  i0 = l4;
  i1 = l6;
  i2 = 39u;
  i3 = l6;
  i2 -= i3;
  i3 = 7u;
  i2 &= i3;
  i3 = 0u;
  i4 = l6;
  i5 = 4294967257u;
  i4 += i5;
  i5 = 7u;
  i4 &= i5;
  i2 = i4 ? i2 : i3;
  i1 += i2;
  i2 = 4294967249u;
  i1 += i2;
  p0 = i1;
  i2 = p0;
  i3 = l4;
  i4 = 16u;
  i3 += i4;
  i2 = i2 < i3;
  i0 = i2 ? i0 : i1;
  l8 = i0;
  i1 = 27u;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l8;
  i1 = 16u;
  i0 += i1;
  i1 = 0u;
  j1 = i64_load(Z_envZ_memory, (u64)(i1 + 2572));
  i64_store(Z_envZ_memory, (u64)(i0), j1);
  i0 = l8;
  i1 = 0u;
  j1 = i64_load(Z_envZ_memory, (u64)(i1 + 2564));
  i64_store(Z_envZ_memory, (u64)(i0 + 8), j1);
  i0 = 0u;
  i1 = l8;
  i2 = 8u;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2572), i1);
  i0 = 0u;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2568), i1);
  i0 = 0u;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 2564), i1);
  i0 = 0u;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 2576), i1);
  i0 = l8;
  i1 = 24u;
  i0 += i1;
  p0 = i0;
  L104: 
    i0 = p0;
    i1 = 7u;
    i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
    i0 = p0;
    i1 = 8u;
    i0 += i1;
    l5 = i0;
    i0 = p0;
    i1 = 4u;
    i0 += i1;
    p0 = i0;
    i0 = l6;
    i1 = l5;
    i0 = i0 > i1;
    if (i0) {goto L104;}
  i0 = l8;
  i1 = l4;
  i0 = i0 == i1;
  if (i0) {goto B62;}
  i0 = l8;
  i1 = l8;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 4));
  i2 = 4294967294u;
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l4;
  i1 = l8;
  i2 = l4;
  i1 -= i2;
  l2 = i1;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l8;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l2;
  i1 = 255u;
  i0 = i0 > i1;
  if (i0) {goto B105;}
  i0 = l2;
  i1 = 3u;
  i0 >>= (i1 & 31);
  l6 = i0;
  i1 = 3u;
  i0 <<= (i1 & 31);
  i1 = 2156u;
  i0 += i1;
  p0 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2116));
  l5 = i0;
  i1 = 1u;
  i2 = l6;
  i1 <<= (i2 & 31);
  l6 = i1;
  i0 &= i1;
  if (i0) {goto B107;}
  i0 = 0u;
  i1 = l5;
  i2 = l6;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2116), i1);
  i0 = p0;
  l6 = i0;
  goto B106;
  B107:;
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l6 = i0;
  B106:;
  i0 = p0;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l6;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l4;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l4;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B62;
  B105:;
  i0 = 0u;
  p0 = i0;
  i0 = l2;
  i1 = 8u;
  i0 >>= (i1 & 31);
  l6 = i0;
  i0 = !(i0);
  if (i0) {goto B108;}
  i0 = 31u;
  p0 = i0;
  i0 = l2;
  i1 = 16777215u;
  i0 = i0 > i1;
  if (i0) {goto B108;}
  i0 = l6;
  i1 = l6;
  i2 = 1048320u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 8u;
  i1 &= i2;
  p0 = i1;
  i0 <<= (i1 & 31);
  l6 = i0;
  i1 = l6;
  i2 = 520192u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 4u;
  i1 &= i2;
  l6 = i1;
  i0 <<= (i1 & 31);
  l5 = i0;
  i1 = l5;
  i2 = 245760u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 2u;
  i1 &= i2;
  l5 = i1;
  i0 <<= (i1 & 31);
  i1 = 15u;
  i0 >>= (i1 & 31);
  i1 = l6;
  i2 = p0;
  i1 |= i2;
  i2 = l5;
  i1 |= i2;
  i0 -= i1;
  p0 = i0;
  i1 = 1u;
  i0 <<= (i1 & 31);
  i1 = l2;
  i2 = p0;
  i3 = 21u;
  i2 += i3;
  i1 >>= (i2 & 31);
  i2 = 1u;
  i1 &= i2;
  i0 |= i1;
  i1 = 28u;
  i0 += i1;
  p0 = i0;
  B108:;
  i0 = l4;
  j1 = 0ull;
  i64_store(Z_envZ_memory, (u64)(i0 + 16), j1);
  i0 = l4;
  i1 = 28u;
  i0 += i1;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = 2u;
  i0 <<= (i1 & 31);
  i1 = 2420u;
  i0 += i1;
  l6 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2120));
  l5 = i0;
  i1 = 1u;
  i2 = p0;
  i1 <<= (i2 & 31);
  l8 = i1;
  i0 &= i1;
  if (i0) {goto B110;}
  i0 = 0u;
  i1 = l5;
  i2 = l8;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2120), i1);
  i0 = l6;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l4;
  i1 = 24u;
  i0 += i1;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  goto B109;
  B110:;
  i0 = l2;
  i1 = 0u;
  i2 = 25u;
  i3 = p0;
  i4 = 1u;
  i3 >>= (i4 & 31);
  i2 -= i3;
  i3 = p0;
  i4 = 31u;
  i3 = i3 == i4;
  i1 = i3 ? i1 : i2;
  i0 <<= (i1 & 31);
  p0 = i0;
  i0 = l6;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l5 = i0;
  L111: 
    i0 = l5;
    l6 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
    i1 = 4294967288u;
    i0 &= i1;
    i1 = l2;
    i0 = i0 == i1;
    if (i0) {goto B71;}
    i0 = p0;
    i1 = 29u;
    i0 >>= (i1 & 31);
    l5 = i0;
    i0 = p0;
    i1 = 1u;
    i0 <<= (i1 & 31);
    p0 = i0;
    i0 = l6;
    i1 = l5;
    i2 = 4u;
    i1 &= i2;
    i0 += i1;
    i1 = 16u;
    i0 += i1;
    l8 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l5 = i0;
    if (i0) {goto L111;}
  i0 = l8;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l4;
  i1 = 24u;
  i0 += i1;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  B109:;
  i0 = l4;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l4;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B62;
  B73:;
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  p0 = i0;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l3;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l6;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  i0 = l6;
  i1 = l3;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l6;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  B72:;
  i0 = l11;
  i1 = 8u;
  i0 += i1;
  p0 = i0;
  goto B2;
  B71:;
  i0 = l6;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  p0 = i0;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l6;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l4;
  i1 = 24u;
  i0 += i1;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l4;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l4;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  B62:;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2128));
  p0 = i0;
  i1 = l3;
  i0 = i0 <= i1;
  if (i0) {goto B5;}
  i0 = 0u;
  i1 = p0;
  i2 = l3;
  i1 -= i2;
  l4 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2128), i1);
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2140));
  p0 = i1;
  i2 = l3;
  i1 += i2;
  l6 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2140), i1);
  i0 = l6;
  i1 = l4;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = p0;
  i1 = l3;
  i2 = 3u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = p0;
  i1 = 8u;
  i0 += i1;
  p0 = i0;
  goto B2;
  B5:;
  i0 = __errno_location();
  i1 = 48u;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = 0u;
  p0 = i0;
  goto B2;
  B4:;
  i0 = l11;
  i0 = !(i0);
  if (i0) {goto B112;}
  i0 = l8;
  i1 = l8;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 28));
  l4 = i1;
  i2 = 2u;
  i1 <<= (i2 & 31);
  i2 = 2420u;
  i1 += i2;
  p0 = i1;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  i0 = i0 != i1;
  if (i0) {goto B114;}
  i0 = p0;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l5;
  if (i0) {goto B113;}
  i0 = 0u;
  i1 = l7;
  i2 = 4294967294u;
  i3 = l4;
  i2 = I32_ROTL(i2, i3);
  i1 &= i2;
  l7 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2120), i1);
  goto B112;
  B114:;
  i0 = l11;
  i1 = 16u;
  i2 = 20u;
  i3 = l11;
  i3 = i32_load(Z_envZ_memory, (u64)(i3 + 16));
  i4 = l8;
  i3 = i3 == i4;
  i1 = i3 ? i1 : i2;
  i0 += i1;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l5;
  i0 = !(i0);
  if (i0) {goto B112;}
  B113:;
  i0 = l5;
  i1 = l11;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  i0 = l8;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
  p0 = i0;
  i0 = !(i0);
  if (i0) {goto B115;}
  i0 = l5;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = p0;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  B115:;
  i0 = l8;
  i1 = 20u;
  i0 += i1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  p0 = i0;
  i0 = !(i0);
  if (i0) {goto B112;}
  i0 = l5;
  i1 = 20u;
  i0 += i1;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  B112:;
  i0 = l6;
  i1 = 15u;
  i0 = i0 > i1;
  if (i0) {goto B117;}
  i0 = l8;
  i1 = l6;
  i2 = l3;
  i1 += i2;
  p0 = i1;
  i2 = 3u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l8;
  i1 = p0;
  i0 += i1;
  p0 = i0;
  i1 = p0;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 4));
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  goto B116;
  B117:;
  i0 = l8;
  i1 = l3;
  i2 = 3u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l8;
  i1 = l3;
  i0 += i1;
  l5 = i0;
  i1 = l6;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l5;
  i1 = l6;
  i0 += i1;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l6;
  i1 = 255u;
  i0 = i0 > i1;
  if (i0) {goto B118;}
  i0 = l6;
  i1 = 3u;
  i0 >>= (i1 & 31);
  l4 = i0;
  i1 = 3u;
  i0 <<= (i1 & 31);
  i1 = 2156u;
  i0 += i1;
  p0 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2116));
  l6 = i0;
  i1 = 1u;
  i2 = l4;
  i1 <<= (i2 & 31);
  l4 = i1;
  i0 &= i1;
  if (i0) {goto B120;}
  i0 = 0u;
  i1 = l6;
  i2 = l4;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2116), i1);
  i0 = p0;
  l4 = i0;
  goto B119;
  B120:;
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l4 = i0;
  B119:;
  i0 = p0;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l4;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l5;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l5;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B116;
  B118:;
  i0 = l6;
  i1 = 8u;
  i0 >>= (i1 & 31);
  l4 = i0;
  if (i0) {goto B122;}
  i0 = 0u;
  p0 = i0;
  goto B121;
  B122:;
  i0 = 31u;
  p0 = i0;
  i0 = l6;
  i1 = 16777215u;
  i0 = i0 > i1;
  if (i0) {goto B121;}
  i0 = l4;
  i1 = l4;
  i2 = 1048320u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 8u;
  i1 &= i2;
  p0 = i1;
  i0 <<= (i1 & 31);
  l4 = i0;
  i1 = l4;
  i2 = 520192u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 4u;
  i1 &= i2;
  l4 = i1;
  i0 <<= (i1 & 31);
  l3 = i0;
  i1 = l3;
  i2 = 245760u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 2u;
  i1 &= i2;
  l3 = i1;
  i0 <<= (i1 & 31);
  i1 = 15u;
  i0 >>= (i1 & 31);
  i1 = l4;
  i2 = p0;
  i1 |= i2;
  i2 = l3;
  i1 |= i2;
  i0 -= i1;
  p0 = i0;
  i1 = 1u;
  i0 <<= (i1 & 31);
  i1 = l6;
  i2 = p0;
  i3 = 21u;
  i2 += i3;
  i1 >>= (i2 & 31);
  i2 = 1u;
  i1 &= i2;
  i0 |= i1;
  i1 = 28u;
  i0 += i1;
  p0 = i0;
  B121:;
  i0 = l5;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  i0 = l5;
  j1 = 0ull;
  i64_store(Z_envZ_memory, (u64)(i0 + 16), j1);
  i0 = p0;
  i1 = 2u;
  i0 <<= (i1 & 31);
  i1 = 2420u;
  i0 += i1;
  l4 = i0;
  i0 = l7;
  i1 = 1u;
  i2 = p0;
  i1 <<= (i2 & 31);
  l3 = i1;
  i0 &= i1;
  if (i0) {goto B125;}
  i0 = 0u;
  i1 = l7;
  i2 = l3;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2120), i1);
  i0 = l4;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l5;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  goto B124;
  B125:;
  i0 = l6;
  i1 = 0u;
  i2 = 25u;
  i3 = p0;
  i4 = 1u;
  i3 >>= (i4 & 31);
  i2 -= i3;
  i3 = p0;
  i4 = 31u;
  i3 = i3 == i4;
  i1 = i3 ? i1 : i2;
  i0 <<= (i1 & 31);
  p0 = i0;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l3 = i0;
  L126: 
    i0 = l3;
    l4 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
    i1 = 4294967288u;
    i0 &= i1;
    i1 = l6;
    i0 = i0 == i1;
    if (i0) {goto B123;}
    i0 = p0;
    i1 = 29u;
    i0 >>= (i1 & 31);
    l3 = i0;
    i0 = p0;
    i1 = 1u;
    i0 <<= (i1 & 31);
    p0 = i0;
    i0 = l4;
    i1 = l3;
    i2 = 4u;
    i1 &= i2;
    i0 += i1;
    i1 = 16u;
    i0 += i1;
    l2 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l3 = i0;
    if (i0) {goto L126;}
  i0 = l2;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l5;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  B124:;
  i0 = l5;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l5;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B116;
  B123:;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  p0 = i0;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l4;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l5;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  i0 = l5;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l5;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  B116:;
  i0 = l8;
  i1 = 8u;
  i0 += i1;
  p0 = i0;
  goto B2;
  B3:;
  i0 = l10;
  i0 = !(i0);
  if (i0) {goto B127;}
  i0 = l5;
  i1 = l5;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 28));
  l6 = i1;
  i2 = 2u;
  i1 <<= (i2 & 31);
  i2 = 2420u;
  i1 += i2;
  p0 = i1;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  i0 = i0 != i1;
  if (i0) {goto B129;}
  i0 = p0;
  i1 = l8;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l8;
  if (i0) {goto B128;}
  i0 = 0u;
  i1 = l9;
  i2 = 4294967294u;
  i3 = l6;
  i2 = I32_ROTL(i2, i3);
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2120), i1);
  goto B127;
  B129:;
  i0 = l10;
  i1 = 16u;
  i2 = 20u;
  i3 = l10;
  i3 = i32_load(Z_envZ_memory, (u64)(i3 + 16));
  i4 = l5;
  i3 = i3 == i4;
  i1 = i3 ? i1 : i2;
  i0 += i1;
  i1 = l8;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l8;
  i0 = !(i0);
  if (i0) {goto B127;}
  B128:;
  i0 = l8;
  i1 = l10;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  i0 = l5;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
  p0 = i0;
  i0 = !(i0);
  if (i0) {goto B130;}
  i0 = l8;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = p0;
  i1 = l8;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  B130:;
  i0 = l5;
  i1 = 20u;
  i0 += i1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  p0 = i0;
  i0 = !(i0);
  if (i0) {goto B127;}
  i0 = l8;
  i1 = 20u;
  i0 += i1;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = l8;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  B127:;
  i0 = l4;
  i1 = 15u;
  i0 = i0 > i1;
  if (i0) {goto B132;}
  i0 = l5;
  i1 = l4;
  i2 = l3;
  i1 += i2;
  p0 = i1;
  i2 = 3u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l5;
  i1 = p0;
  i0 += i1;
  p0 = i0;
  i1 = p0;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 4));
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  goto B131;
  B132:;
  i0 = l5;
  i1 = l3;
  i2 = 3u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l5;
  i1 = l3;
  i0 += i1;
  l6 = i0;
  i1 = l4;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l6;
  i1 = l4;
  i0 += i1;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l7;
  i0 = !(i0);
  if (i0) {goto B133;}
  i0 = l7;
  i1 = 3u;
  i0 >>= (i1 & 31);
  l8 = i0;
  i1 = 3u;
  i0 <<= (i1 & 31);
  i1 = 2156u;
  i0 += i1;
  l3 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2136));
  p0 = i0;
  i0 = 1u;
  i1 = l8;
  i0 <<= (i1 & 31);
  l8 = i0;
  i1 = l2;
  i0 &= i1;
  if (i0) {goto B135;}
  i0 = 0u;
  i1 = l8;
  i2 = l2;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2116), i1);
  i0 = l3;
  l8 = i0;
  goto B134;
  B135:;
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l8 = i0;
  B134:;
  i0 = l3;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l8;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = p0;
  i1 = l3;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = p0;
  i1 = l8;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  B133:;
  i0 = 0u;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 2136), i1);
  i0 = 0u;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 2124), i1);
  B131:;
  i0 = l5;
  i1 = 8u;
  i0 += i1;
  p0 = i0;
  B2:;
  i0 = l1;
  i1 = 16u;
  i0 += i1;
  l13 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l13;
  g0 = i0;
  i0 = p0;
  FUNC_EPILOGUE;
  return i0;
}

static void free(u32 p0) {
  u32 l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0, l6 = 0, l7 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3, i4;
  u64 j1;
  i0 = p0;
  i0 = !(i0);
  if (i0) {goto B0;}
  i0 = p0;
  i1 = 4294967288u;
  i0 += i1;
  l1 = i0;
  i1 = p0;
  i2 = 4294967292u;
  i1 += i2;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  l2 = i1;
  i2 = 4294967288u;
  i1 &= i2;
  p0 = i1;
  i0 += i1;
  l3 = i0;
  i0 = l2;
  i1 = 1u;
  i0 &= i1;
  if (i0) {goto B1;}
  i0 = l2;
  i1 = 3u;
  i0 &= i1;
  i0 = !(i0);
  if (i0) {goto B0;}
  i0 = l1;
  i1 = l1;
  i1 = i32_load(Z_envZ_memory, (u64)(i1));
  l2 = i1;
  i0 -= i1;
  l1 = i0;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2132));
  l4 = i1;
  i0 = i0 < i1;
  if (i0) {goto B0;}
  i0 = l2;
  i1 = p0;
  i0 += i1;
  p0 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2136));
  i1 = l1;
  i0 = i0 == i1;
  if (i0) {goto B2;}
  i0 = l2;
  i1 = 255u;
  i0 = i0 > i1;
  if (i0) {goto B3;}
  i0 = l1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  l5 = i0;
  i0 = l1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l6 = i0;
  i1 = l2;
  i2 = 3u;
  i1 >>= (i2 & 31);
  l7 = i1;
  i2 = 3u;
  i1 <<= (i2 & 31);
  i2 = 2156u;
  i1 += i2;
  l2 = i1;
  i0 = i0 == i1;
  if (i0) {goto B4;}
  i0 = l4;
  i1 = l6;
  i0 = i0 > i1;
  B4:;
  i0 = l5;
  i1 = l6;
  i0 = i0 != i1;
  if (i0) {goto B5;}
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2116));
  i2 = 4294967294u;
  i3 = l7;
  i2 = I32_ROTL(i2, i3);
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2116), i1);
  goto B1;
  B5:;
  i0 = l5;
  i1 = l2;
  i0 = i0 == i1;
  if (i0) {goto B6;}
  i0 = l4;
  i1 = l5;
  i0 = i0 > i1;
  B6:;
  i0 = l6;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l5;
  i1 = l6;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B1;
  B3:;
  i0 = l1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
  l7 = i0;
  i0 = l1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  l5 = i0;
  i1 = l1;
  i0 = i0 == i1;
  if (i0) {goto B8;}
  i0 = l4;
  i1 = l1;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 8));
  l2 = i1;
  i0 = i0 > i1;
  if (i0) {goto B9;}
  i0 = l2;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  i1 = l1;
  i0 = i0 != i1;
  B9:;
  i0 = l2;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l5;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B7;
  B8:;
  i0 = l1;
  i1 = 20u;
  i0 += i1;
  l2 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l4 = i0;
  if (i0) {goto B10;}
  i0 = l1;
  i1 = 16u;
  i0 += i1;
  l2 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l4 = i0;
  if (i0) {goto B10;}
  i0 = 0u;
  l5 = i0;
  goto B7;
  B10:;
  L11: 
    i0 = l2;
    l6 = i0;
    i0 = l4;
    l5 = i0;
    i1 = 20u;
    i0 += i1;
    l2 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l4 = i0;
    if (i0) {goto L11;}
    i0 = l5;
    i1 = 16u;
    i0 += i1;
    l2 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
    l4 = i0;
    if (i0) {goto L11;}
  i0 = l6;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  B7:;
  i0 = l7;
  i0 = !(i0);
  if (i0) {goto B1;}
  i0 = l1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 28));
  l4 = i0;
  i1 = 2u;
  i0 <<= (i1 & 31);
  i1 = 2420u;
  i0 += i1;
  l2 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  i1 = l1;
  i0 = i0 != i1;
  if (i0) {goto B13;}
  i0 = l2;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l5;
  if (i0) {goto B12;}
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2120));
  i2 = 4294967294u;
  i3 = l4;
  i2 = I32_ROTL(i2, i3);
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2120), i1);
  goto B1;
  B13:;
  i0 = l7;
  i1 = 16u;
  i2 = 20u;
  i3 = l7;
  i3 = i32_load(Z_envZ_memory, (u64)(i3 + 16));
  i4 = l1;
  i3 = i3 == i4;
  i1 = i3 ? i1 : i2;
  i0 += i1;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l5;
  i0 = !(i0);
  if (i0) {goto B1;}
  B12:;
  i0 = l5;
  i1 = l7;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  i0 = l1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
  l2 = i0;
  i0 = !(i0);
  if (i0) {goto B14;}
  i0 = l5;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = l2;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  B14:;
  i0 = l1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 20));
  l2 = i0;
  i0 = !(i0);
  if (i0) {goto B1;}
  i0 = l5;
  i1 = 20u;
  i0 += i1;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l2;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  goto B1;
  B2:;
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
  l2 = i0;
  i1 = 3u;
  i0 &= i1;
  i1 = 3u;
  i0 = i0 != i1;
  if (i0) {goto B1;}
  i0 = 0u;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 2124), i1);
  i0 = l3;
  i1 = l2;
  i2 = 4294967294u;
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l1;
  i1 = p0;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l1;
  i1 = p0;
  i0 += i1;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  goto Bfunc;
  B1:;
  i0 = l3;
  i1 = l1;
  i0 = i0 <= i1;
  if (i0) {goto B0;}
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
  l2 = i0;
  i1 = 1u;
  i0 &= i1;
  i0 = !(i0);
  if (i0) {goto B0;}
  i0 = l2;
  i1 = 2u;
  i0 &= i1;
  if (i0) {goto B16;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2140));
  i1 = l3;
  i0 = i0 != i1;
  if (i0) {goto B17;}
  i0 = 0u;
  i1 = l1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2140), i1);
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2128));
  i2 = p0;
  i1 += i2;
  p0 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2128), i1);
  i0 = l1;
  i1 = p0;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l1;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2136));
  i0 = i0 != i1;
  if (i0) {goto B0;}
  i0 = 0u;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 2124), i1);
  i0 = 0u;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 2136), i1);
  goto Bfunc;
  B17:;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2136));
  i1 = l3;
  i0 = i0 != i1;
  if (i0) {goto B18;}
  i0 = 0u;
  i1 = l1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2136), i1);
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2124));
  i2 = p0;
  i1 += i2;
  p0 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2124), i1);
  i0 = l1;
  i1 = p0;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l1;
  i1 = p0;
  i0 += i1;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  goto Bfunc;
  B18:;
  i0 = l2;
  i1 = 4294967288u;
  i0 &= i1;
  i1 = p0;
  i0 += i1;
  p0 = i0;
  i0 = l2;
  i1 = 255u;
  i0 = i0 > i1;
  if (i0) {goto B20;}
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  l4 = i0;
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l5 = i0;
  i1 = l2;
  i2 = 3u;
  i1 >>= (i2 & 31);
  l3 = i1;
  i2 = 3u;
  i1 <<= (i2 & 31);
  i2 = 2156u;
  i1 += i2;
  l2 = i1;
  i0 = i0 == i1;
  if (i0) {goto B21;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2132));
  i1 = l5;
  i0 = i0 > i1;
  B21:;
  i0 = l4;
  i1 = l5;
  i0 = i0 != i1;
  if (i0) {goto B22;}
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2116));
  i2 = 4294967294u;
  i3 = l3;
  i2 = I32_ROTL(i2, i3);
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2116), i1);
  goto B19;
  B22:;
  i0 = l4;
  i1 = l2;
  i0 = i0 == i1;
  if (i0) {goto B23;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2132));
  i1 = l4;
  i0 = i0 > i1;
  B23:;
  i0 = l5;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l4;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B19;
  B20:;
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 24));
  l7 = i0;
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  l5 = i0;
  i1 = l3;
  i0 = i0 == i1;
  if (i0) {goto B25;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2132));
  i1 = l3;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 8));
  l2 = i1;
  i0 = i0 > i1;
  if (i0) {goto B26;}
  i0 = l2;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 12));
  i1 = l3;
  i0 = i0 != i1;
  B26:;
  i0 = l2;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l5;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B24;
  B25:;
  i0 = l3;
  i1 = 20u;
  i0 += i1;
  l2 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l4 = i0;
  if (i0) {goto B27;}
  i0 = l3;
  i1 = 16u;
  i0 += i1;
  l2 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l4 = i0;
  if (i0) {goto B27;}
  i0 = 0u;
  l5 = i0;
  goto B24;
  B27:;
  L28: 
    i0 = l2;
    l6 = i0;
    i0 = l4;
    l5 = i0;
    i1 = 20u;
    i0 += i1;
    l2 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l4 = i0;
    if (i0) {goto L28;}
    i0 = l5;
    i1 = 16u;
    i0 += i1;
    l2 = i0;
    i0 = l5;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
    l4 = i0;
    if (i0) {goto L28;}
  i0 = l6;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  B24:;
  i0 = l7;
  i0 = !(i0);
  if (i0) {goto B19;}
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 28));
  l4 = i0;
  i1 = 2u;
  i0 <<= (i1 & 31);
  i1 = 2420u;
  i0 += i1;
  l2 = i0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  i1 = l3;
  i0 = i0 != i1;
  if (i0) {goto B30;}
  i0 = l2;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l5;
  if (i0) {goto B29;}
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2120));
  i2 = 4294967294u;
  i3 = l4;
  i2 = I32_ROTL(i2, i3);
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2120), i1);
  goto B19;
  B30:;
  i0 = l7;
  i1 = 16u;
  i2 = 20u;
  i3 = l7;
  i3 = i32_load(Z_envZ_memory, (u64)(i3 + 16));
  i4 = l3;
  i3 = i3 == i4;
  i1 = i3 ? i1 : i2;
  i0 += i1;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l5;
  i0 = !(i0);
  if (i0) {goto B19;}
  B29:;
  i0 = l5;
  i1 = l7;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
  l2 = i0;
  i0 = !(i0);
  if (i0) {goto B31;}
  i0 = l5;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = l2;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  B31:;
  i0 = l3;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 20));
  l2 = i0;
  i0 = !(i0);
  if (i0) {goto B19;}
  i0 = l5;
  i1 = 20u;
  i0 += i1;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l2;
  i1 = l5;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  B19:;
  i0 = l1;
  i1 = p0;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l1;
  i1 = p0;
  i0 += i1;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l1;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2136));
  i0 = i0 != i1;
  if (i0) {goto B15;}
  i0 = 0u;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 2124), i1);
  goto Bfunc;
  B16:;
  i0 = l3;
  i1 = l2;
  i2 = 4294967294u;
  i1 &= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l1;
  i1 = p0;
  i2 = 1u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = l1;
  i1 = p0;
  i0 += i1;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  B15:;
  i0 = p0;
  i1 = 255u;
  i0 = i0 > i1;
  if (i0) {goto B32;}
  i0 = p0;
  i1 = 3u;
  i0 >>= (i1 & 31);
  l2 = i0;
  i1 = 3u;
  i0 <<= (i1 & 31);
  i1 = 2156u;
  i0 += i1;
  p0 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2116));
  l4 = i0;
  i1 = 1u;
  i2 = l2;
  i1 <<= (i2 & 31);
  l2 = i1;
  i0 &= i1;
  if (i0) {goto B34;}
  i0 = 0u;
  i1 = l4;
  i2 = l2;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2116), i1);
  i0 = p0;
  l2 = i0;
  goto B33;
  B34:;
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  l2 = i0;
  B33:;
  i0 = p0;
  i1 = l1;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l2;
  i1 = l1;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l1;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l1;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto Bfunc;
  B32:;
  i0 = 0u;
  l2 = i0;
  i0 = p0;
  i1 = 8u;
  i0 >>= (i1 & 31);
  l4 = i0;
  i0 = !(i0);
  if (i0) {goto B35;}
  i0 = 31u;
  l2 = i0;
  i0 = p0;
  i1 = 16777215u;
  i0 = i0 > i1;
  if (i0) {goto B35;}
  i0 = l4;
  i1 = l4;
  i2 = 1048320u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 8u;
  i1 &= i2;
  l2 = i1;
  i0 <<= (i1 & 31);
  l4 = i0;
  i1 = l4;
  i2 = 520192u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 4u;
  i1 &= i2;
  l4 = i1;
  i0 <<= (i1 & 31);
  l5 = i0;
  i1 = l5;
  i2 = 245760u;
  i1 += i2;
  i2 = 16u;
  i1 >>= (i2 & 31);
  i2 = 2u;
  i1 &= i2;
  l5 = i1;
  i0 <<= (i1 & 31);
  i1 = 15u;
  i0 >>= (i1 & 31);
  i1 = l4;
  i2 = l2;
  i1 |= i2;
  i2 = l5;
  i1 |= i2;
  i0 -= i1;
  l2 = i0;
  i1 = 1u;
  i0 <<= (i1 & 31);
  i1 = p0;
  i2 = l2;
  i3 = 21u;
  i2 += i3;
  i1 >>= (i2 & 31);
  i2 = 1u;
  i1 &= i2;
  i0 |= i1;
  i1 = 28u;
  i0 += i1;
  l2 = i0;
  B35:;
  i0 = l1;
  j1 = 0ull;
  i64_store(Z_envZ_memory, (u64)(i0 + 16), j1);
  i0 = l1;
  i1 = 28u;
  i0 += i1;
  i1 = l2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l2;
  i1 = 2u;
  i0 <<= (i1 & 31);
  i1 = 2420u;
  i0 += i1;
  l4 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2120));
  l5 = i0;
  i1 = 1u;
  i2 = l2;
  i1 <<= (i2 & 31);
  l3 = i1;
  i0 &= i1;
  if (i0) {goto B39;}
  i0 = 0u;
  i1 = l5;
  i2 = l3;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 2120), i1);
  i0 = l4;
  i1 = l1;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l1;
  i1 = 24u;
  i0 += i1;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  goto B38;
  B39:;
  i0 = p0;
  i1 = 0u;
  i2 = 25u;
  i3 = l2;
  i4 = 1u;
  i3 >>= (i4 & 31);
  i2 -= i3;
  i3 = l2;
  i4 = 31u;
  i3 = i3 == i4;
  i1 = i3 ? i1 : i2;
  i0 <<= (i1 & 31);
  l2 = i0;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l5 = i0;
  L40: 
    i0 = l5;
    l4 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
    i1 = 4294967288u;
    i0 &= i1;
    i1 = p0;
    i0 = i0 == i1;
    if (i0) {goto B37;}
    i0 = l2;
    i1 = 29u;
    i0 >>= (i1 & 31);
    l5 = i0;
    i0 = l2;
    i1 = 1u;
    i0 <<= (i1 & 31);
    l2 = i0;
    i0 = l4;
    i1 = l5;
    i2 = 4u;
    i1 &= i2;
    i0 += i1;
    i1 = 16u;
    i0 += i1;
    l3 = i0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l5 = i0;
    if (i0) {goto L40;}
  i0 = l3;
  i1 = l1;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l1;
  i1 = 24u;
  i0 += i1;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  B38:;
  i0 = l1;
  i1 = l1;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l1;
  i1 = l1;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  goto B36;
  B37:;
  i0 = l4;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 8));
  p0 = i0;
  i1 = l1;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l4;
  i1 = l1;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l1;
  i1 = 24u;
  i0 += i1;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l1;
  i1 = l4;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = l1;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  B36:;
  i0 = 0u;
  i1 = 0u;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 2148));
  i2 = 4294967295u;
  i1 += i2;
  l1 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 2148), i1);
  i0 = l1;
  if (i0) {goto B0;}
  i0 = 2572u;
  l1 = i0;
  L41: 
    i0 = l1;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    p0 = i0;
    i1 = 8u;
    i0 += i1;
    l1 = i0;
    i0 = p0;
    if (i0) {goto L41;}
  i0 = 0u;
  i1 = 4294967295u;
  i32_store(Z_envZ_memory, (u64)(i0 + 2148), i1);
  B0:;
  Bfunc:;
  FUNC_EPILOGUE;
}

static u32 f40(u32 p0) {
  u32 l1 = 0, l2 = 0, l3 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  i0 = f5();
  l1 = i0;
  i0 = (*Z_envZ_memory).pages;
  l2 = i0;
  i0 = l1;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l3 = i0;
  i1 = p0;
  i2 = 3u;
  i1 += i2;
  i2 = 4294967292u;
  i1 &= i2;
  i0 += i1;
  p0 = i0;
  i1 = l2;
  i2 = 16u;
  i1 <<= (i2 & 31);
  i0 = i0 <= i1;
  if (i0) {goto B0;}
  i0 = p0;
  i0 = (*Z_envZ_emscripten_resize_heapZ_ii)(i0);
  if (i0) {goto B0;}
  i0 = __errno_location();
  i1 = 48u;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = 4294967295u;
  goto Bfunc;
  B0:;
  i0 = l1;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l3;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f41(u32 p0, u32 p1, u32 p2) {
  u32 l3 = 0, l4 = 0, l5 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  i0 = p2;
  i1 = 512u;
  i0 = i0 < i1;
  if (i0) {goto B0;}
  i0 = p0;
  i1 = p1;
  i2 = p2;
  i0 = (*Z_envZ_emscripten_memcpy_bigZ_iiii)(i0, i1, i2);
  i0 = p0;
  goto Bfunc;
  B0:;
  i0 = p0;
  i1 = p2;
  i0 += i1;
  l3 = i0;
  i0 = p1;
  i1 = p0;
  i0 ^= i1;
  i1 = 3u;
  i0 &= i1;
  if (i0) {goto B2;}
  i0 = p2;
  i1 = 1u;
  i0 = (u32)((s32)i0 >= (s32)i1);
  if (i0) {goto B4;}
  i0 = p0;
  p2 = i0;
  goto B3;
  B4:;
  i0 = p0;
  i1 = 3u;
  i0 &= i1;
  if (i0) {goto B5;}
  i0 = p0;
  p2 = i0;
  goto B3;
  B5:;
  i0 = p0;
  p2 = i0;
  L6: 
    i0 = p2;
    i1 = p1;
    i1 = i32_load8_u(Z_envZ_memory, (u64)(i1));
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    i0 = p1;
    i1 = 1u;
    i0 += i1;
    p1 = i0;
    i0 = p2;
    i1 = 1u;
    i0 += i1;
    p2 = i0;
    i1 = l3;
    i0 = i0 >= i1;
    if (i0) {goto B3;}
    i0 = p2;
    i1 = 3u;
    i0 &= i1;
    if (i0) {goto L6;}
  B3:;
  i0 = l3;
  i1 = 4294967292u;
  i0 &= i1;
  l4 = i0;
  i1 = 64u;
  i0 = i0 < i1;
  if (i0) {goto B7;}
  i0 = p2;
  i1 = l4;
  i2 = 4294967232u;
  i1 += i2;
  l5 = i1;
  i0 = i0 > i1;
  if (i0) {goto B7;}
  L8: 
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1));
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 4));
    i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 8));
    i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 12));
    i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 16));
    i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 20));
    i32_store(Z_envZ_memory, (u64)(i0 + 20), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 24));
    i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 28));
    i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 32));
    i32_store(Z_envZ_memory, (u64)(i0 + 32), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 36));
    i32_store(Z_envZ_memory, (u64)(i0 + 36), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 40));
    i32_store(Z_envZ_memory, (u64)(i0 + 40), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 44));
    i32_store(Z_envZ_memory, (u64)(i0 + 44), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 48));
    i32_store(Z_envZ_memory, (u64)(i0 + 48), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 52));
    i32_store(Z_envZ_memory, (u64)(i0 + 52), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 56));
    i32_store(Z_envZ_memory, (u64)(i0 + 56), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 60));
    i32_store(Z_envZ_memory, (u64)(i0 + 60), i1);
    i0 = p1;
    i1 = 64u;
    i0 += i1;
    p1 = i0;
    i0 = p2;
    i1 = 64u;
    i0 += i1;
    p2 = i0;
    i1 = l5;
    i0 = i0 <= i1;
    if (i0) {goto L8;}
  B7:;
  i0 = p2;
  i1 = l4;
  i0 = i0 >= i1;
  if (i0) {goto B1;}
  L9: 
    i0 = p2;
    i1 = p1;
    i1 = i32_load(Z_envZ_memory, (u64)(i1));
    i32_store(Z_envZ_memory, (u64)(i0), i1);
    i0 = p1;
    i1 = 4u;
    i0 += i1;
    p1 = i0;
    i0 = p2;
    i1 = 4u;
    i0 += i1;
    p2 = i0;
    i1 = l4;
    i0 = i0 < i1;
    if (i0) {goto L9;}
    goto B1;
  UNREACHABLE;
  B2:;
  i0 = l3;
  i1 = 4u;
  i0 = i0 >= i1;
  if (i0) {goto B10;}
  i0 = p0;
  p2 = i0;
  goto B1;
  B10:;
  i0 = l3;
  i1 = 4294967292u;
  i0 += i1;
  l4 = i0;
  i1 = p0;
  i0 = i0 >= i1;
  if (i0) {goto B11;}
  i0 = p0;
  p2 = i0;
  goto B1;
  B11:;
  i0 = p0;
  p2 = i0;
  L12: 
    i0 = p2;
    i1 = p1;
    i1 = i32_load8_u(Z_envZ_memory, (u64)(i1));
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load8_u(Z_envZ_memory, (u64)(i1 + 1));
    i32_store8(Z_envZ_memory, (u64)(i0 + 1), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load8_u(Z_envZ_memory, (u64)(i1 + 2));
    i32_store8(Z_envZ_memory, (u64)(i0 + 2), i1);
    i0 = p2;
    i1 = p1;
    i1 = i32_load8_u(Z_envZ_memory, (u64)(i1 + 3));
    i32_store8(Z_envZ_memory, (u64)(i0 + 3), i1);
    i0 = p1;
    i1 = 4u;
    i0 += i1;
    p1 = i0;
    i0 = p2;
    i1 = 4u;
    i0 += i1;
    p2 = i0;
    i1 = l4;
    i0 = i0 <= i1;
    if (i0) {goto L12;}
  B1:;
  i0 = p2;
  i1 = l3;
  i0 = i0 >= i1;
  if (i0) {goto B13;}
  L14: 
    i0 = p2;
    i1 = p1;
    i1 = i32_load8_u(Z_envZ_memory, (u64)(i1));
    i32_store8(Z_envZ_memory, (u64)(i0), i1);
    i0 = p1;
    i1 = 1u;
    i0 += i1;
    p1 = i0;
    i0 = p2;
    i1 = 1u;
    i0 += i1;
    p2 = i0;
    i1 = l3;
    i0 = i0 != i1;
    if (i0) {goto L14;}
  B13:;
  i0 = p0;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f42(u32 p0, u32 p1, u32 p2) {
  u32 l3 = 0, l4 = 0, l5 = 0;
  u64 l6 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  u64 j0, j1;
  i0 = p2;
  i0 = !(i0);
  if (i0) {goto B0;}
  i0 = p2;
  i1 = p0;
  i0 += i1;
  l3 = i0;
  i1 = 4294967295u;
  i0 += i1;
  i1 = p1;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = p2;
  i1 = 3u;
  i0 = i0 < i1;
  if (i0) {goto B0;}
  i0 = l3;
  i1 = 4294967294u;
  i0 += i1;
  i1 = p1;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  i32_store8(Z_envZ_memory, (u64)(i0 + 1), i1);
  i0 = l3;
  i1 = 4294967293u;
  i0 += i1;
  i1 = p1;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  i32_store8(Z_envZ_memory, (u64)(i0 + 2), i1);
  i0 = p2;
  i1 = 7u;
  i0 = i0 < i1;
  if (i0) {goto B0;}
  i0 = l3;
  i1 = 4294967292u;
  i0 += i1;
  i1 = p1;
  i32_store8(Z_envZ_memory, (u64)(i0), i1);
  i0 = p0;
  i1 = p1;
  i32_store8(Z_envZ_memory, (u64)(i0 + 3), i1);
  i0 = p2;
  i1 = 9u;
  i0 = i0 < i1;
  if (i0) {goto B0;}
  i0 = p0;
  i1 = 0u;
  i2 = p0;
  i1 -= i2;
  i2 = 3u;
  i1 &= i2;
  l4 = i1;
  i0 += i1;
  l3 = i0;
  i1 = p1;
  i2 = 255u;
  i1 &= i2;
  i2 = 16843009u;
  i1 *= i2;
  p1 = i1;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l3;
  i1 = p2;
  i2 = l4;
  i1 -= i2;
  i2 = 4294967292u;
  i1 &= i2;
  l4 = i1;
  i0 += i1;
  p2 = i0;
  i1 = 4294967292u;
  i0 += i1;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l4;
  i1 = 9u;
  i0 = i0 < i1;
  if (i0) {goto B0;}
  i0 = l3;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 8), i1);
  i0 = l3;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 4), i1);
  i0 = p2;
  i1 = 4294967288u;
  i0 += i1;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p2;
  i1 = 4294967284u;
  i0 += i1;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l4;
  i1 = 25u;
  i0 = i0 < i1;
  if (i0) {goto B0;}
  i0 = l3;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 24), i1);
  i0 = l3;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 20), i1);
  i0 = l3;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = l3;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = p2;
  i1 = 4294967280u;
  i0 += i1;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p2;
  i1 = 4294967276u;
  i0 += i1;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p2;
  i1 = 4294967272u;
  i0 += i1;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = p2;
  i1 = 4294967268u;
  i0 += i1;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = l4;
  i1 = l3;
  i2 = 4u;
  i1 &= i2;
  i2 = 24u;
  i1 |= i2;
  l5 = i1;
  i0 -= i1;
  p2 = i0;
  i1 = 32u;
  i0 = i0 < i1;
  if (i0) {goto B0;}
  i0 = p1;
  j0 = (u64)(i0);
  l6 = j0;
  j1 = 32ull;
  j0 <<= (j1 & 63);
  j1 = l6;
  j0 |= j1;
  l6 = j0;
  i0 = l3;
  i1 = l5;
  i0 += i1;
  p1 = i0;
  L1: 
    i0 = p1;
    j1 = l6;
    i64_store(Z_envZ_memory, (u64)(i0 + 24), j1);
    i0 = p1;
    j1 = l6;
    i64_store(Z_envZ_memory, (u64)(i0 + 16), j1);
    i0 = p1;
    j1 = l6;
    i64_store(Z_envZ_memory, (u64)(i0 + 8), j1);
    i0 = p1;
    j1 = l6;
    i64_store(Z_envZ_memory, (u64)(i0), j1);
    i0 = p1;
    i1 = 32u;
    i0 += i1;
    p1 = i0;
    i0 = p2;
    i1 = 4294967264u;
    i0 += i1;
    p2 = i0;
    i1 = 31u;
    i0 = i0 > i1;
    if (i0) {goto L1;}
  B0:;
  i0 = p0;
  FUNC_EPILOGUE;
  return i0;
}

static void f43(u32 p0) {
  FUNC_PROLOGUE;
  FUNC_EPILOGUE;
}

static void f44(u32 p0) {
  FUNC_PROLOGUE;
  FUNC_EPILOGUE;
}

static u32 f45(void) {
  FUNC_PROLOGUE;
  u32 i0;
  i0 = 2612u;
  f43(i0);
  i0 = 2620u;
  FUNC_EPILOGUE;
  return i0;
}

static void f46(void) {
  FUNC_PROLOGUE;
  u32 i0;
  i0 = 2612u;
  f44(i0);
  FUNC_EPILOGUE;
}

static u32 f47(u32 p0) {
  u32 l1 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  u64 j1;
  i0 = p0;
  i1 = p0;
  i1 = i32_load8_u(Z_envZ_memory, (u64)(i1 + 74));
  l1 = i1;
  i2 = 4294967295u;
  i1 += i2;
  i2 = l1;
  i1 |= i2;
  i32_store8(Z_envZ_memory, (u64)(i0 + 74), i1);
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  l1 = i0;
  i1 = 8u;
  i0 &= i1;
  i0 = !(i0);
  if (i0) {goto B0;}
  i0 = p0;
  i1 = l1;
  i2 = 32u;
  i1 |= i2;
  i32_store(Z_envZ_memory, (u64)(i0), i1);
  i0 = 4294967295u;
  goto Bfunc;
  B0:;
  i0 = p0;
  j1 = 0ull;
  i64_store(Z_envZ_memory, (u64)(i0 + 4), j1);
  i0 = p0;
  i1 = p0;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 44));
  l1 = i1;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  i0 = p0;
  i1 = l1;
  i32_store(Z_envZ_memory, (u64)(i0 + 20), i1);
  i0 = p0;
  i1 = l1;
  i2 = p0;
  i2 = i32_load(Z_envZ_memory, (u64)(i2 + 48));
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 16), i1);
  i0 = 0u;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f48(u32 p0, u32 p1, u32 p2) {
  u32 l3 = 0, l4 = 0, l5 = 0, l6 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3;
  i0 = p2;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
  l3 = i0;
  if (i0) {goto B1;}
  i0 = 0u;
  l4 = i0;
  i0 = p2;
  i0 = f47(i0);
  if (i0) {goto B0;}
  i0 = p2;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 16));
  l3 = i0;
  B1:;
  i0 = l3;
  i1 = p2;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 20));
  l5 = i1;
  i0 -= i1;
  i1 = p1;
  i0 = i0 >= i1;
  if (i0) {goto B2;}
  i0 = p2;
  i1 = p0;
  i2 = p1;
  i3 = p2;
  i3 = i32_load(Z_envZ_memory, (u64)(i3 + 36));
  i0 = CALL_INDIRECT((*Z_envZ_table), u32 (*)(u32, u32, u32), 1, i3, i0, i1, i2);
  goto Bfunc;
  B2:;
  i0 = 0u;
  l6 = i0;
  i0 = p2;
  i0 = i32_load8_s(Z_envZ_memory, (u64)(i0 + 75));
  i1 = 0u;
  i0 = (u32)((s32)i0 < (s32)i1);
  if (i0) {goto B3;}
  i0 = p1;
  l4 = i0;
  L4: 
    i0 = l4;
    l3 = i0;
    i0 = !(i0);
    if (i0) {goto B3;}
    i0 = p0;
    i1 = l3;
    i2 = 4294967295u;
    i1 += i2;
    l4 = i1;
    i0 += i1;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
    i1 = 10u;
    i0 = i0 != i1;
    if (i0) {goto L4;}
  i0 = p2;
  i1 = p0;
  i2 = l3;
  i3 = p2;
  i3 = i32_load(Z_envZ_memory, (u64)(i3 + 36));
  i0 = CALL_INDIRECT((*Z_envZ_table), u32 (*)(u32, u32, u32), 1, i3, i0, i1, i2);
  l4 = i0;
  i1 = l3;
  i0 = i0 < i1;
  if (i0) {goto B0;}
  i0 = p1;
  i1 = l3;
  i0 -= i1;
  p1 = i0;
  i0 = p0;
  i1 = l3;
  i0 += i1;
  p0 = i0;
  i0 = p2;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 20));
  l5 = i0;
  i0 = l3;
  l6 = i0;
  B3:;
  i0 = l5;
  i1 = p0;
  i2 = p1;
  i0 = f41(i0, i1, i2);
  i0 = p2;
  i1 = p2;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 20));
  i2 = p1;
  i1 += i2;
  i32_store(Z_envZ_memory, (u64)(i0 + 20), i1);
  i0 = l6;
  i1 = p1;
  i0 += i1;
  l4 = i0;
  B0:;
  i0 = l4;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f49(u32 p0) {
  FUNC_PROLOGUE;
  u32 i0;
  i0 = 0u;
  FUNC_EPILOGUE;
  return i0;
}

static u64 f50(u32 p0, u64 p1, u32 p2) {
  FUNC_PROLOGUE;
  u64 j0;
  j0 = 0ull;
  FUNC_EPILOGUE;
  return j0;
}

static u32 f51(u32 p0, u32 p1) {
  u32 l2 = 0, l3 = 0, l4 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  i0 = g0;
  i1 = 16u;
  i0 -= i1;
  l2 = i0;
  l3 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l3;
  g0 = i0;
  i0 = l2;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 12), i1);
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 1640));
  i1 = p0;
  i2 = p1;
  i0 = f34(i0, i1, i2);
  p1 = i0;
  i0 = l2;
  i1 = 16u;
  i0 += i1;
  l4 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l4;
  g0 = i0;
  i0 = p1;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f52(u32 p0) {
  FUNC_PROLOGUE;
  u32 i0;
  i0 = 1u;
  FUNC_EPILOGUE;
  return i0;
}

static void f53(u32 p0) {
  FUNC_PROLOGUE;
  FUNC_EPILOGUE;
}

static u32 f54(u32 p0) {
  u32 l1 = 0, l2 = 0, l3 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  i0 = p0;
  l1 = i0;
  i0 = p0;
  i1 = 3u;
  i0 &= i1;
  i0 = !(i0);
  if (i0) {goto B1;}
  i0 = p0;
  i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
  if (i0) {goto B2;}
  i0 = p0;
  i1 = p0;
  i0 -= i1;
  goto Bfunc;
  B2:;
  i0 = p0;
  l1 = i0;
  L3: 
    i0 = l1;
    i1 = 1u;
    i0 += i1;
    l1 = i0;
    i1 = 3u;
    i0 &= i1;
    i0 = !(i0);
    if (i0) {goto B1;}
    i0 = l1;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0));
    i0 = !(i0);
    if (i0) {goto B0;}
    goto L3;
  UNREACHABLE;
  B1:;
  L4: 
    i0 = l1;
    l2 = i0;
    i1 = 4u;
    i0 += i1;
    l1 = i0;
    i0 = l2;
    i0 = i32_load(Z_envZ_memory, (u64)(i0));
    l3 = i0;
    i1 = 4294967295u;
    i0 ^= i1;
    i1 = l3;
    i2 = 4278124287u;
    i1 += i2;
    i0 &= i1;
    i1 = 2155905152u;
    i0 &= i1;
    i0 = !(i0);
    if (i0) {goto L4;}
  i0 = l3;
  i1 = 255u;
  i0 &= i1;
  if (i0) {goto B5;}
  i0 = l2;
  i1 = p0;
  i0 -= i1;
  goto Bfunc;
  B5:;
  L6: 
    i0 = l2;
    i0 = i32_load8_u(Z_envZ_memory, (u64)(i0 + 1));
    l3 = i0;
    i0 = l2;
    i1 = 1u;
    i0 += i1;
    l1 = i0;
    l2 = i0;
    i0 = l3;
    if (i0) {goto L6;}
  B0:;
  i0 = l1;
  i1 = p0;
  i0 -= i1;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static void setThrew(u32 p0, u32 p1) {
  FUNC_PROLOGUE;
  u32 i0, i1;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 3656));
  if (i0) {goto B0;}
  i0 = 0u;
  i1 = p1;
  i32_store(Z_envZ_memory, (u64)(i0 + 3660), i1);
  i0 = 0u;
  i1 = p0;
  i32_store(Z_envZ_memory, (u64)(i0 + 3656), i1);
  B0:;
  FUNC_EPILOGUE;
}

static u32 fflush(u32 p0) {
  u32 l1 = 0, l2 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1;
  i0 = p0;
  i0 = !(i0);
  if (i0) {goto B1;}
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 76));
  i1 = 4294967295u;
  i0 = (u32)((s32)i0 > (s32)i1);
  if (i0) {goto B2;}
  i0 = p0;
  i0 = f57(i0);
  goto Bfunc;
  B2:;
  i0 = p0;
  i0 = f52(i0);
  l1 = i0;
  i0 = p0;
  i0 = f57(i0);
  l2 = i0;
  i0 = l1;
  i0 = !(i0);
  if (i0) {goto B0;}
  i0 = p0;
  f53(i0);
  i0 = l2;
  goto Bfunc;
  B1:;
  i0 = 0u;
  l2 = i0;
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2040));
  i0 = !(i0);
  if (i0) {goto B3;}
  i0 = 0u;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 2040));
  i0 = fflush(i0);
  l2 = i0;
  B3:;
  i0 = f45();
  i0 = i32_load(Z_envZ_memory, (u64)(i0));
  p0 = i0;
  i0 = !(i0);
  if (i0) {goto B4;}
  L5: 
    i0 = 0u;
    l1 = i0;
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 76));
    i1 = 0u;
    i0 = (u32)((s32)i0 < (s32)i1);
    if (i0) {goto B6;}
    i0 = p0;
    i0 = f52(i0);
    l1 = i0;
    B6:;
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 20));
    i1 = p0;
    i1 = i32_load(Z_envZ_memory, (u64)(i1 + 28));
    i0 = i0 <= i1;
    if (i0) {goto B7;}
    i0 = p0;
    i0 = f57(i0);
    i1 = l2;
    i0 |= i1;
    l2 = i0;
    B7:;
    i0 = l1;
    i0 = !(i0);
    if (i0) {goto B8;}
    i0 = p0;
    f53(i0);
    B8:;
    i0 = p0;
    i0 = i32_load(Z_envZ_memory, (u64)(i0 + 56));
    p0 = i0;
    if (i0) {goto L5;}
  B4:;
  f46();
  B0:;
  i0 = l2;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static u32 f57(u32 p0) {
  u32 l1 = 0, l2 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3;
  u64 j0, j1;
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 20));
  i1 = p0;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 28));
  i0 = i0 <= i1;
  if (i0) {goto B0;}
  i0 = p0;
  i1 = 0u;
  i2 = 0u;
  i3 = p0;
  i3 = i32_load(Z_envZ_memory, (u64)(i3 + 36));
  i0 = CALL_INDIRECT((*Z_envZ_table), u32 (*)(u32, u32, u32), 1, i3, i0, i1, i2);
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 20));
  if (i0) {goto B0;}
  i0 = 4294967295u;
  goto Bfunc;
  B0:;
  i0 = p0;
  i0 = i32_load(Z_envZ_memory, (u64)(i0 + 4));
  l1 = i0;
  i1 = p0;
  i1 = i32_load(Z_envZ_memory, (u64)(i1 + 8));
  l2 = i1;
  i0 = i0 >= i1;
  if (i0) {goto B1;}
  i0 = p0;
  i1 = l1;
  i2 = l2;
  i1 -= i2;
  j1 = (u64)(s64)(s32)(i1);
  i2 = 1u;
  i3 = p0;
  i3 = i32_load(Z_envZ_memory, (u64)(i3 + 40));
  j0 = CALL_INDIRECT((*Z_envZ_table), u64 (*)(u32, u64, u32), 8, i3, i0, j1, i2);
  B1:;
  i0 = p0;
  i1 = 0u;
  i32_store(Z_envZ_memory, (u64)(i0 + 28), i1);
  i0 = p0;
  j1 = 0ull;
  i64_store(Z_envZ_memory, (u64)(i0 + 16), j1);
  i0 = p0;
  j1 = 0ull;
  i64_store(Z_envZ_memory, (u64)(i0 + 4), j1);
  i0 = 0u;
  Bfunc:;
  FUNC_EPILOGUE;
  return i0;
}

static void __set_stack_limit(u32 p0) {
  FUNC_PROLOGUE;
  u32 i0;
  i0 = p0;
  g2 = i0;
  FUNC_EPILOGUE;
}

static u32 stackSave(void) {
  FUNC_PROLOGUE;
  u32 i0;
  i0 = g0;
  FUNC_EPILOGUE;
  return i0;
}

static u32 stackAlloc(u32 p0) {
  u32 l1 = 0, l2 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1;
  i0 = g0;
  i1 = p0;
  i0 -= i1;
  i1 = 4294967280u;
  i0 &= i1;
  l1 = i0;
  l2 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l2;
  g0 = i0;
  i0 = l1;
  FUNC_EPILOGUE;
  return i0;
}

static void stackRestore(u32 p0) {
  u32 l1 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1;
  i0 = p0;
  l1 = i0;
  i1 = g2;
  i0 = i0 < i1;
  if (i0) {
    (*Z_envZ___handle_stack_overflowZ_vv)();
  }
  i0 = l1;
  g0 = i0;
  FUNC_EPILOGUE;
}

static u32 __growWasmMemory(u32 p0) {
  FUNC_PROLOGUE;
  u32 i0;
  i0 = p0;
  i0 = wasm_rt_grow_memory(Z_envZ_memory, i0);
  FUNC_EPILOGUE;
  return i0;
}

static u32 dynCall_iidiiii(u32 p0, u32 p1, f64 p2, u32 p3, u32 p4, u32 p5, u32 p6) {
  FUNC_PROLOGUE;
  u32 i0, i2, i3, i4, i5, i6;
  f64 d1;
  i0 = p1;
  d1 = p2;
  i2 = p3;
  i3 = p4;
  i4 = p5;
  i5 = p6;
  i6 = p0;
  i0 = CALL_INDIRECT((*Z_envZ_table), u32 (*)(u32, f64, u32, u32, u32, u32), 7, i6, i0, d1, i2, i3, i4, i5);
  FUNC_EPILOGUE;
  return i0;
}

static void dynCall_vii(u32 p0, u32 p1, u32 p2) {
  FUNC_PROLOGUE;
  u32 i0, i1, i2;
  i0 = p1;
  i1 = p2;
  i2 = p0;
  CALL_INDIRECT((*Z_envZ_table), void (*)(u32, u32), 6, i2, i0, i1);
  FUNC_EPILOGUE;
}

static u32 dynCall_ii(u32 p0, u32 p1) {
  FUNC_PROLOGUE;
  u32 i0, i1;
  i0 = p1;
  i1 = p0;
  i0 = CALL_INDIRECT((*Z_envZ_table), u32 (*)(u32), 0, i1, i0);
  FUNC_EPILOGUE;
  return i0;
}

static u32 dynCall_iiii(u32 p0, u32 p1, u32 p2, u32 p3) {
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3;
  i0 = p1;
  i1 = p2;
  i2 = p3;
  i3 = p0;
  i0 = CALL_INDIRECT((*Z_envZ_table), u32 (*)(u32, u32, u32), 1, i3, i0, i1, i2);
  FUNC_EPILOGUE;
  return i0;
}

static u64 f67(u32 p0, u32 p1, u64 p2, u32 p3) {
  FUNC_PROLOGUE;
  u32 i0, i2, i3;
  u64 j0, j1;
  i0 = p1;
  j1 = p2;
  i2 = p3;
  i3 = p0;
  j0 = CALL_INDIRECT((*Z_envZ_table), u64 (*)(u32, u64, u32), 8, i3, i0, j1, i2);
  FUNC_EPILOGUE;
  return j0;
}

static u32 dynCall_jiji(u32 p0, u32 p1, u32 p2, u32 p3, u32 p4) {
  u64 l5 = 0;
  FUNC_PROLOGUE;
  u32 i0, i1, i2, i3;
  u64 j0, j1, j2, j3, j4;
  i0 = p0;
  i1 = p1;
  i2 = p2;
  j2 = (u64)(i2);
  i3 = p3;
  j3 = (u64)(i3);
  j4 = 32ull;
  j3 <<= (j4 & 63);
  j2 |= j3;
  i3 = p4;
  j0 = f67(i0, i1, j2, i3);
  l5 = j0;
  j0 = l5;
  j1 = 32ull;
  j0 >>= (j1 & 63);
  i0 = (u32)(j0);
  (*Z_envZ_setTempRet0Z_vi)(i0);
  j0 = l5;
  i0 = (u32)(j0);
  FUNC_EPILOGUE;
  return i0;
}

static const u8 data_segment_data_0[] = {
  0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 
  0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 
  0x59, 0x5a, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 
  0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 
  0x77, 0x78, 0x79, 0x7a, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
  0x38, 0x39, 0x2b, 0x2f, 0x00, 0x25, 0x64, 0x0a, 0x00, 0x2d, 0x2b, 0x20, 
  0x20, 0x20, 0x30, 0x58, 0x30, 0x78, 0x00, 0x28, 0x6e, 0x75, 0x6c, 0x6c, 
  0x29, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x11, 0x00, 0x0a, 0x00, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x05, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x0b, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x0f, 0x0a, 
  0x11, 0x11, 0x11, 0x03, 0x0a, 0x07, 0x00, 0x01, 0x13, 0x09, 0x0b, 0x0b, 
  0x00, 0x00, 0x09, 0x06, 0x0b, 0x00, 0x00, 0x0b, 0x00, 0x06, 0x11, 0x00, 
  0x00, 0x00, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x0a, 0x0a, 0x11, 0x11, 
  0x11, 0x00, 0x0a, 0x00, 0x00, 0x02, 0x00, 0x09, 0x0b, 0x00, 0x00, 0x00, 
  0x09, 0x00, 0x0b, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 
  0x0c, 0x00, 0x00, 0x00, 0x00, 0x09, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x0c, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x04, 0x0d, 0x00, 
  0x00, 0x00, 0x00, 0x09, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 
  0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 
  0x00, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 
  0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 
  0x00, 0x00, 0x12, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 
  0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x09, 0x0b, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 
  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x09, 0x0c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x0c, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x30, 0x31, 0x32, 0x33, 
  0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 
  0x2d, 0x30, 0x58, 0x2b, 0x30, 0x58, 0x20, 0x30, 0x58, 0x2d, 0x30, 0x78, 
  0x2b, 0x30, 0x78, 0x20, 0x30, 0x78, 0x00, 0x69, 0x6e, 0x66, 0x00, 0x49, 
  0x4e, 0x46, 0x00, 0x6e, 0x61, 0x6e, 0x00, 0x4e, 0x41, 0x4e, 0x00, 0x2e, 
  0x00, 0x00, 0x00, 0x00, 0x68, 0x07, 0x00, 0x00, 
};

static const u8 data_segment_data_1[] = {
  0x90, 0x69, 0x42, 0x37, 0x13, 0x08, 0x10, 0x09, 0x08, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2c, 0x08, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 
  0x05, 0x00, 0x00, 0x00, 0x48, 0x0a, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x07, 0x00, 0x00, 
  
};

static const u8 data_segment_data_2[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

static void init_memory(void) {
  memcpy(&((*Z_envZ_memory).data[1024u]), data_segment_data_0, 620);
  memcpy(&((*Z_envZ_memory).data[1648u]), data_segment_data_1, 396);
  memcpy(&((*Z_envZ_memory).data[2048u]), data_segment_data_2, 1616);
}

static void init_table(void) {
  uint32_t offset;
  offset = 1u;
  (*Z_envZ_table).data[offset + 0] = (wasm_rt_elem_t){func_types[7], (wasm_rt_anyfunc_t)(&f35)};
  (*Z_envZ_table).data[offset + 1] = (wasm_rt_elem_t){func_types[6], (wasm_rt_anyfunc_t)(&f36)};
  (*Z_envZ_table).data[offset + 2] = (wasm_rt_elem_t){func_types[0], (wasm_rt_anyfunc_t)(&f49)};
  (*Z_envZ_table).data[offset + 3] = (wasm_rt_elem_t){func_types[1], (wasm_rt_anyfunc_t)(&f14)};
  (*Z_envZ_table).data[offset + 4] = (wasm_rt_elem_t){func_types[8], (wasm_rt_anyfunc_t)(&f50)};
}

/* export: '__wasm_call_ctors' */
void (*WASM_RT_ADD_PREFIX(Z___wasm_call_ctorsZ_vv))(void);
/* export: 'malloc' */
u32 (*WASM_RT_ADD_PREFIX(Z_mallocZ_ii))(u32);
/* export: 'free' */
void (*WASM_RT_ADD_PREFIX(Z_freeZ_vi))(u32);
/* export: 'main' */
u32 (*WASM_RT_ADD_PREFIX(Z_mainZ_iii))(u32, u32);
/* export: '__errno_location' */
u32 (*WASM_RT_ADD_PREFIX(Z___errno_locationZ_iv))(void);
/* export: 'fflush' */
u32 (*WASM_RT_ADD_PREFIX(Z_fflushZ_ii))(u32);
/* export: 'setThrew' */
void (*WASM_RT_ADD_PREFIX(Z_setThrewZ_vii))(u32, u32);
/* export: '__data_end' */
u32 (*WASM_RT_ADD_PREFIX(Z___data_endZ_i));
/* export: '__set_stack_limit' */
void (*WASM_RT_ADD_PREFIX(Z___set_stack_limitZ_vi))(u32);
/* export: 'stackSave' */
u32 (*WASM_RT_ADD_PREFIX(Z_stackSaveZ_iv))(void);
/* export: 'stackAlloc' */
u32 (*WASM_RT_ADD_PREFIX(Z_stackAllocZ_ii))(u32);
/* export: 'stackRestore' */
void (*WASM_RT_ADD_PREFIX(Z_stackRestoreZ_vi))(u32);
/* export: '__growWasmMemory' */
u32 (*WASM_RT_ADD_PREFIX(Z___growWasmMemoryZ_ii))(u32);
/* export: 'dynCall_iidiiii' */
u32 (*WASM_RT_ADD_PREFIX(Z_dynCall_iidiiiiZ_iiidiiii))(u32, u32, f64, u32, u32, u32, u32);
/* export: 'dynCall_vii' */
void (*WASM_RT_ADD_PREFIX(Z_dynCall_viiZ_viii))(u32, u32, u32);
/* export: 'dynCall_ii' */
u32 (*WASM_RT_ADD_PREFIX(Z_dynCall_iiZ_iii))(u32, u32);
/* export: 'dynCall_iiii' */
u32 (*WASM_RT_ADD_PREFIX(Z_dynCall_iiiiZ_iiiii))(u32, u32, u32, u32);
/* export: 'dynCall_jiji' */
u32 (*WASM_RT_ADD_PREFIX(Z_dynCall_jijiZ_iiiiii))(u32, u32, u32, u32, u32);

static void init_exports(void) {
  /* export: '__wasm_call_ctors' */
  WASM_RT_ADD_PREFIX(Z___wasm_call_ctorsZ_vv) = (&__wasm_call_ctors);
  /* export: 'malloc' */
  WASM_RT_ADD_PREFIX(Z_mallocZ_ii) = (&malloc);
  /* export: 'free' */
  WASM_RT_ADD_PREFIX(Z_freeZ_vi) = (&free);
  /* export: 'main' */
  WASM_RT_ADD_PREFIX(Z_mainZ_iii) = (&main);
  /* export: '__errno_location' */
  WASM_RT_ADD_PREFIX(Z___errno_locationZ_iv) = (&__errno_location);
  /* export: 'fflush' */
  WASM_RT_ADD_PREFIX(Z_fflushZ_ii) = (&fflush);
  /* export: 'setThrew' */
  WASM_RT_ADD_PREFIX(Z_setThrewZ_vii) = (&setThrew);
  /* export: '__data_end' */
  WASM_RT_ADD_PREFIX(Z___data_endZ_i) = (&__data_end);
  /* export: '__set_stack_limit' */
  WASM_RT_ADD_PREFIX(Z___set_stack_limitZ_vi) = (&__set_stack_limit);
  /* export: 'stackSave' */
  WASM_RT_ADD_PREFIX(Z_stackSaveZ_iv) = (&stackSave);
  /* export: 'stackAlloc' */
  WASM_RT_ADD_PREFIX(Z_stackAllocZ_ii) = (&stackAlloc);
  /* export: 'stackRestore' */
  WASM_RT_ADD_PREFIX(Z_stackRestoreZ_vi) = (&stackRestore);
  /* export: '__growWasmMemory' */
  WASM_RT_ADD_PREFIX(Z___growWasmMemoryZ_ii) = (&__growWasmMemory);
  /* export: 'dynCall_iidiiii' */
  WASM_RT_ADD_PREFIX(Z_dynCall_iidiiiiZ_iiidiiii) = (&dynCall_iidiiii);
  /* export: 'dynCall_vii' */
  WASM_RT_ADD_PREFIX(Z_dynCall_viiZ_viii) = (&dynCall_vii);
  /* export: 'dynCall_ii' */
  WASM_RT_ADD_PREFIX(Z_dynCall_iiZ_iii) = (&dynCall_ii);
  /* export: 'dynCall_iiii' */
  WASM_RT_ADD_PREFIX(Z_dynCall_iiiiZ_iiiii) = (&dynCall_iiii);
  /* export: 'dynCall_jiji' */
  WASM_RT_ADD_PREFIX(Z_dynCall_jijiZ_iiiiii) = (&dynCall_jiji);
}

void WASM_RT_ADD_PREFIX(init)(void) {
  init_func_types();
  init_globals();
  init_memory();
  init_table();
  init_exports();
}
