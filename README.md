C/C++ Demonstration
=======
This is the first repository I created in C++. I have been writing programs in C language for years. Some of them are even written with `cpp` extension. But I have never used some C++ features. So in this repo, I would like to show you some examples of C++ STL.

> You should prepare all the libraries needed in order to generate Makefiles

## Executables

* **vectordemo**: A demonstration of `std::vector`. It's something similar to an array. But it contains more methods. It simply prints out everything inside the array.

* **regexdemo**: A demonstration of **POSIX BRE** written in C language using **libgnurx** because I can't use the standard **C++11**'s regex library in **MinGW**.

* **posixeredemo**: A demonstration of **POSIX ERE** which stands for Extended Regular Expression, written in C language too. I recently discovered that the only difference is to add REG\_EXTENDED in `cflags`.

* **globalctors**: A demonstration of **GCC Global Constructor**: A function that is automatically called before **main**.

## Structures

* **bitfield**: A program that shows the value of struct with bitfield in the memory
```
struct{
	char a:1;
	char b:1;
	char c:1;
	char d:2;
} bitfield;
```

* **structdemo**: A program that shows difference between packed struct and default (aligned) struct.

## Libraries

* **libvoid**: A set of functions that demonstrates generic type `void*`.

| Function Prototypes | Description |
|:------|:------|
| void swap(void\* ap,void\* bp,size\_t sz) | Switch the values between two generic pointers. |
| void\* lsearch(void\* key,void\* base,size\_t n,size\_t each) | Search stuff from an unknown type array and returns the address of the result. |
| void\* lsearchx(void\* key,void\* base,size\_t n,size\_t each,cmpfunc cmp) | Same as **lsearch**, but with a custom function for comparing values |

### Demonstrations of libvoid

* **swapdemo**: Demonstration of **swap()**.

* **searchdemo**: Demonstration of **lsearch()**.

* **customcmpsearch**: Demonstration of **lsearchx()**.

## Documents

* **man\_regex.txt**: regular expression manual from Linux. I got function prototypes here.
