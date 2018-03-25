#ifndef _STM32_ARCH_H
#define _STM32_ARCH_H 1
#include <stm32f4xx.h>
#include <stdlib.h>

/**
 * Definition of byte order in STM32
 */
#define BYTE_ORDER LITTLE_ENDIAN

/**
 * Definitions of integral types used in lwIP stack
 */
typedef int8_t   s8_t;
typedef uint8_t  u8_t;
typedef int16_t  s16_t;
typedef uint16_t u16_t;
typedef int32_t  s32_t;
typedef uint32_t u32_t;
typedef u32_t    mem_ptr_t;

/**
 * lwIP types definiotions for print function
 */
#define S16_F "hd"
#define U16_F "hu"
#define X16_F "hx"
#define S32_F "ld"
#define U32_F "lu"
#define X32_F "lx"
#define SZT_F "zu"

/**
 * Bytes alignment in 32-bit architecture
 */
#if defined __GNUC__
  #define ALIGN4 __attribute__ ((aligned (4)))
#else
  #error Define ALIGN4 macro for your compiler.
#endif

/**
 * Swap bytes function in ARM architecture
 */
#if defined __GNUC__
  #define LWIP_PLATFORM_HTONS(x) ({                 \
    u16_t result;                                   \
    asm ("rev16 %0, %1" : "=r" (result) : "r" (x)); \
    result;                                         \
  })
  #define LWIP_PLATFORM_HTONL(x) ({                 \
    u32_t result;                                   \
    asm ("rev %0, %1" : "=r" (result) : "r" (x));   \
    result;                                         \
  })
#else
  #define LWIP_PLATFORM_HTONS(x) __REV16(x)
  #define LWIP_PLATFORM_HTONL(x) __REV(x)
#endif

/* Optymalizuj czas działania - nie używaj asercji. */
#define LWIP_PLATFORM_DIAG(x) ((void)0)
#define LWIP_PLATFORM_ASSERT(x) ((void)0)
/* Oryginalnie było tak
#define LWIP_PLATFORM_ASSERT(x) do { if(!(x)) while(1); } while(0)
*/

/* Jeśli w lwiopts.h zdefiniowano opcję SYS_LIGHTWEIGHT_PROT == 1,
   trzeba też zdefiniować makra chroniące dostępy do pamięci. Makra
   te pojawiają się w funkcjach memp_free, memp_malloc, pbuf_ref,
   pbuf_free oraz gdy zdefiniowano MEM_LIBC_MALLOC == 0, to również
   w mem_realloc i mem_free, choć wtedy między wystąpieniami
   SYS_ARCH_PROTECT i SYS_ARCH_UNPROTECT nie ma żadnego kodu. */
#if defined __GNUC__
  #define SYS_ARCH_DECL_PROTECT(x)                \
    u32_t x
  #define SYS_ARCH_PROTECT(x) ({                  \
    asm volatile (                                \
      "mrs %0, PRIMASK\n\t"                       \
      "cpsid i" :                                 \
      "=r" (x) :                                  \
    );                                            \
  })
  #define SYS_ARCH_UNPROTECT(x) ({                \
    asm volatile ("msr PRIMASK, %0" : : "r" (x)); \
  })
#else
  #define SYS_ARCH_DECL_PROTECT(x)                \
    u32_t x
  #define SYS_ARCH_PROTECT(x)                     \
    (x = __get_PRIMASK(), __disable_irq())
  #define SYS_ARCH_UNPROTECT(x)                   \
    __set_PRIMASK(x)
#endif

/**
 * Interrupts priorities
 */
#define HIGH_IRQ_PRIO 1
#define LWIP_IRQ_PRIO 2
#define LOW_IRQ_PRIO  3
#define PREEMPTION_PRIORITY_BITS 2

/**
 *  Interrupts disable according to it's priority
 */
#define SET_IRQ_PROTECTION()                            \
  NVIC_SetPriorityGrouping(7 - PREEMPTION_PRIORITY_BITS)

/* Definiujemy własne makro, gdyż funkcja NVIC_SetPriority
   z biblioteki CMSIS nie uwzględnia zmienionej liczby bitów
   priorytetu i podpriorytetu. */
#define SET_PRIORITY(irq, prio, subprio)           \
  NVIC_SetPriority((irq), (subprio) | ((prio) <<   \
    (__NVIC_PRIO_BITS - PREEMPTION_PRIORITY_BITS)))

/* Macro IRQ_DECL_PROTECT(prv) declares variable which holds
 * informations about disabled interrupts. Macro IRQ_PROTECT(prv, lvl)
 * saves in variable prv current blocked interrupts and blocks interrupts
 * with lower or equal priority. Macro IRQ_UNPROTECT(prv) restores interrupts
 * saved in prv variable
 */
#if defined __GNUC__
  #define IRQ_DECL_PROTECT(prv)                             \
    u32_t prv
  #define IRQ_PROTECT(prv, lvl) ({                          \
    u32_t tmp;                                              \
    asm volatile (                                          \
      "mrs %0, BASEPRI\n\t"                                 \
      "movs %1, %2\n\t"                                     \
      "msr BASEPRI, %1" :                                   \
      "=r" (prv), "=r" (tmp) :                              \
      "i" ((lvl) << (8 - PREEMPTION_PRIORITY_BITS))         \
    );                                                      \
  })
  #define IRQ_UNPROTECT(prv) ({                             \
    asm volatile ("msr BASEPRI, %0" : : "r" (prv));         \
  })
#else
  #define IRQ_DECL_PROTECT(prv)                             \
    u32_t prv
  #define IRQ_PROTECT(prv, lvl)                             \
    (prv = __get_BASEPRI(),                                 \
     __set_BASEPRI((lvl) << (8 - PREEMPTION_PRIORITY_BITS)))
  #define IRQ_UNPROTECT(prv)                                \
    __set_BASEPRI(prv)
#endif

/**
 * In file lwiopts.h memory allocation functions mem_* are redefinied
 * to protected_*
 */
static __INLINE void protected_free(void *ptr) {
  SYS_ARCH_DECL_PROTECT(v);
  SYS_ARCH_PROTECT(v);
  free(ptr);
  SYS_ARCH_UNPROTECT(v);
}

static __INLINE void *protected_calloc(size_t nmemb, size_t size) {
  void *ret;
  SYS_ARCH_DECL_PROTECT(v);
  SYS_ARCH_PROTECT(v);
  ret = calloc(nmemb, size);
  SYS_ARCH_UNPROTECT(v);
  return ret;
}

static __INLINE void *protected_malloc(size_t size) {
  void *ret;
  SYS_ARCH_DECL_PROTECT(v);
  SYS_ARCH_PROTECT(v);
  ret = malloc(size);
  SYS_ARCH_UNPROTECT(v);
  return ret;
}

static __INLINE void *protected_realloc(void *ptr, size_t size) {
  void *ret;
  SYS_ARCH_DECL_PROTECT(v);
  SYS_ARCH_PROTECT(v);
  ret = realloc(ptr, size);
  SYS_ARCH_UNPROTECT(v);
  return ret;
}

#endif
