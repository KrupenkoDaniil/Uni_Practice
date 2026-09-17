#include <stdio.h>

#include "dloader.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

typedef void (*lib_entry)(void);

void dloader_run(const char *lib_name, const char *entry_name)
{
#ifdef _WIN32
    HMODULE lib = LoadLibraryA(lib_name);
    lib_entry entry;

    if (lib == NULL) {
        printf("cannot load library '%s'\n", lib_name);
        return;
    }
    entry = (lib_entry)(void *)GetProcAddress(lib, entry_name);
    if (entry == NULL)
        printf("cannot find function '%s'\n", entry_name);
    else
        entry();
    FreeLibrary(lib);
#else
    void *lib = dlopen(lib_name, RTLD_LAZY);
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
#endif
}