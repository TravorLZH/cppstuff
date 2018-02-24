C/C++ Demonstration
=======
This is the first repository I created in C++. I have been writing programs in C language for years. Some of them are even written with `cpp` extension. But I have never used some C++ features. So in this repo, I would like to show you some examples of C++ STL.

> You should prepare all the libraries needed in order to generate Makefiles

1. **vectordemo**: A demonstration of `std::vector`. It's something similar to an array. But it contains more methods. It simply prints out everything inside the array.

1. **regexdemo**: A demonstration of **POSIX BRE** written in C language using **libgnurx** because I can't use the standard **C++11**'s regex library in **MinGW**.

1. **libvoid**: A set of functions that demonstrates generic type `void*`.

| Function Prototypes | Description |
|:------|:------|
| void swap(void\* ap,void\* bp,size\_t sz) | Switch the values between two generic pointers. |
| void\* lsearch(void\* key,void\* base,size\_t n,size\_t each) | Search stuff from an unknown type array and returns the address of the result. |
| void\* lsearchx(void\* key,void\* base,size\_t n,size\_t each,cmpfunc cmp) | Same as **lsearch**, but with a custom function for comparing values |

## Demonstrations of libvoid

1. **swapdemo**: Demonstration of **swap()**.

1. **searchdemo**: Demonstration of **lsearch()**.

1. **customcmpsearch**: Demonstration of **lsearchx()**.

