#ifndef EXTENSIONS_H
#define EXTENSIONS_H

void *initExtensions();
void deinitExtensions(void *ext);

void *get_mc_clone(void *exts);
#endif // EXTENSIONS_H
