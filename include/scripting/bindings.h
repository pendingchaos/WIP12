#ifndef BINDING_H
#define BINDING_H

#ifdef SCRIPT_BINDING_GENERATOR
#include "misc_macros.h"

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
#else
#define GETTER
#define SETTER
#define TEMPLATE_TYPES(class, ...)
#define BIND
#define BIND_CLASS(name)
#define NO_BIND
#define DOC_ARG(arg, str)
#define DOC_DESC(str)
#endif

namespace scripting
{
    class Engine;
};

void registerBindings(scripting::Engine *engine);

#endif // BINDING_H