/* Loading of a dynamic library at run time (lab 3).
   Windows: LoadLibrary/GetProcAddress/FreeLibrary.
   Linux:   dlopen/dlsym/dlclose. */

#ifndef DLOADER_H
#define DLOADER_H

/* Loads the library with the given file name and calls its entry point. */
void dloader_run(const char *lib_name, const char *entry_name);

#endif