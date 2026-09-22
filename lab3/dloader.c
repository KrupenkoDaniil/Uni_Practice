#include "dloader.h"

#include <stdio.h>

#include <windows.h>


typedef void (*lib_entry)(void);

void dloader_run(const char* lib_name, const char* entry_name) {
  HMODULE lib = LoadLibraryA(lib_name);
  lib_entry entry;

  if (lib == NULL) {
    printf("cannot load library '%s'\n", lib_name);
    return;
  }
  entry = (lib_entry)(void*)GetProcAddress(lib, entry_name);
  if (entry == NULL)
    printf("cannot find function '%s'\n", entry_name);
  else
    entry();
  FreeLibrary(lib);

}
