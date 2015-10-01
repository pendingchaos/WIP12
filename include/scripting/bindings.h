#ifndef BINDINGS_H
#define BINDINGS_H

#include "misc_macros.h"

#ifdef SCRIPT_BINDING_GENERATOR
#define GETTER __attribute__((annotate("getter")))
#define SETTER __attribute__((annotate("setter")))
#define TEMPLATE_TYPES(class, ...) __attribute__((annotate("templatetypes" STR(class) ";" STR(__VA_ARGS__)))) static int JOIN(_, __COUNTER__);
#define BIND __attribute__((annotate("bind")))
//For some reason BIND does not work with templated classes. This is a workaround.
#define BIND_CLASS(name) __attribute__((annotate("classbind" STR(name)))) static int JOIN(_, __COUNTER__);
#define NO_BIND __attribute__((annotate("nobind")))
#define DOC_ARG(arg, str) __attribute__((annotate("argdoc"arg" "str)))
#define DOC_DESC(str) __attribute__((annotate("descdoc"str)))
#define DOC_EXCEPTION(type, reason) __attribute__((annotate("excdoc"type" "reason)))
//Example: ARG_CONV(0, own<Float2>) so the C++ code can free argument 2 (which is a Float2 *).
#define ARG_CONV(index, func) __attribute__((annotate("argconv" STR(index) ":" STR(func))))
#define NOT_COPYABLE __attribute__((annotate("nocopy")))
#define ENUM_CLASS __attribute__((annotate("enumclass")))
#define DESTROY(...) __attribute__((annotate("destroy" STR(__VA_ARGS__))))
#define RET_PTR_NO_CPP_REF __attribute__((annotate("retptrnocppref")))
#define RENAME(name) __attribute__((annotate("rename" name)))
#else
#define GETTER
#define SETTER
#define TEMPLATE_TYPES(class, ...)
#define BIND
#define BIND_CLASS(name)
#define NO_BIND
#define DOC_ARG(arg, str)
#define DOC_DESC(str)
#define ARG_CONV(index, func)
#define NOT_COPYABLE
#define ENUM_CLASS
#define DESTROY(...)
#define RET_PTR_NO_CPP_REF
#define RENAME(name)
#endif

namespace scripting
{
    class Engine;

    void registerBindings(scripting::Engine *engine);
};

#endif // BINDINGS_H
