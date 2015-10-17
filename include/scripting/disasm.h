#ifndef DISASM_H
#define DISASM_H

#include "scripting/vm/bytecode.h"
#include "containers/string.h"

namespace scripting
{
    Str disasm(const Bytecode& bytecode);
}

#endif // DISASM_H
