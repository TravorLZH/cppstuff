#include <string.h>
#ifndef	__GENFUNC_H_
#define	__GENFUNC_H_
typedef int (*cmpfunc)(void*,void*);
#ifdef	__cplusplus
extern	"C"{
#endif
extern void swap(void* ap,void* bp,size_t sz);
extern void *lsearch(void* key,void* base,size_t n,size_t each);
extern void *lsearchx(void* key,void* base,size_t n,size_t each,cmpfunc cmp);
#ifdef	__cplusplus
}
#endif
#endif
