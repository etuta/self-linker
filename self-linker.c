//* self_liker.c

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

extern void *_GLOBAL_OFFSET_TABLE_;

int main (int argc, char * argv[]){
//handle will be a pointer returned after loading the dynamicly shared library
//with dlopen
//fptr will be a pointer used to save the location in memory of function puts
  void *handle;
  void *fptr;


  //Issue call to get the first entry of GOT
  printf("The first entry of the global offset table is %p\n", _GLOBAL_OFFSET_TABLE_);
  printf("The GOT starts at address %p\n", (void*)&_GLOBAL_OFFSET_TABLE_);

  //Use the dlopen system call to open the dynamic library libc
  handle= dlopen ("/lib/libc.so.6", RTLD_LAZY);
  printf ("handle %p\n=", handle);

  //Check if the library was found or not
  if (!handle) {
    fprintf(stderr, "%s\n", dlerror());
    exit(EXIT_FAILURE);
  }

  printf ("handle %p\n", handle);


  //Finds function puts in libc and saves it at the adress fptr
  fptr = dlsym(handle, "puts");
  if (fptr == NULL) {
       fprintf(stderr, "Couldn't find function: puts\n");
       exit(1);
   }

  printf ("pointer to function %p\n", (void*) fptr);

  //Because the puts function is in the third entry of the GOT, we will assign
  //to the third entry in GOT the value at the adress fptr that we previously found
  *(&_GLOBAL_OFFSET_TABLE_+3)= fptr ;
  //printf ("puts in GOT %p\n", (void*) fptr);

  //Issuea call to external function puts
  puts("hello");
  puts ("world!");


  dlclose(handle);


}
