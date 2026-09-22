#include "dloader.h"

#include <stdio.h>

#include <dlfcn.h>


typedef void (*lib_entry)(void);

void dloader_run(const char* lib_name, const char* entry_name) {
  void* lib = dlopen(lib_name, RTLD_LAZY);
  lib_entry entry;

  if (lib == NULL) {
    printf("cannot load library '%s': %s\n", lib_name, dlerror());
    return;
  }
  entry = (lib_entry)dlsym(lib, entry_name);
  if (entry == NULL)
    printf("cannot find function '%s': %s\n", entry_name, dlerror());
  else
    entry();
  dlclose(lib);
}
