#ifndef SCRIPTING_CONTEXT_H
#define SCRIPTING_CONTEXT_H

#include "scripting/vm/types.h"
#include "scripting/vm/bytecode.h"
#include "containers/pair.h"
#include <setjmp.h>

#define SCRIPTING_MAX_CALLSTACK_SIZE 2048

namespace scripting
{
class Engine;

class ExecutionException : public Exception
{
    public:
        ExecutionException(const char *file_,
                           size_t line_,
                           const char *function_) : Exception(file_, line_, function_) {}

        virtual const char *getString() const
        {
            return "Execution exception.";
        }
};

class StackBoundsException : public ExecutionException
{
    public:
        StackBoundsException(const char *file_,
                             size_t line_,
                             const char *function_) : ExecutionException(file_, line_, function_) {}

        virtual const char *getString() const
        {
            return "Stack bounds exception.";
        }
};

class CallstackBoundsException : public ExecutionException
{
    public:
        CallstackBoundsException(const char *file_,
                                 size_t line_,
                                 const char *function_) : ExecutionException(file_, line_, function_) {}

        virtual const char *getString() const
        {
            return "Callstack bounds exception.";
        }
};

class Context
{
    public:
        struct CallstackEntry
        {
            CallstackEntry() : offset(0) {}
            CallstackEntry(Bytecode bytecode_) : bytecode(bytecode_), offset(0) {}

            Bytecode bytecode;
            HashMap<String, Ref> variables;
            List<List<Ref>> stacks;
            List<size_t> catchBlocks;
            size_t offset;
        };

        Context(Engine *engine);
        ~Context();

        inline const CallstackEntry *getCallstack() const
        {
            return callStack;
        }

        inline CallstackEntry *getCallstack()
        {
            return callStack;
        }

        inline size_t getCallstackSize() const
        {
            return callStackSize;
        }

        inline Engine *getEngine() const
        {
            return engine;
        }

        void reset();
        Ref run(const Bytecode& bytecode, List<Ref> args);
        void throwException(Ref exc);
    private:
        Ref _run(const Bytecode& bytecode, List<Ref> args);
        Engine *engine;
        size_t callStackSize;
        CallstackEntry callStack[SCRIPTING_MAX_CALLSTACK_SIZE];
        Ref exception;
        jmp_buf jumpBuf;

        Ref popStack(List<Ref>& stack);
};

class UnhandledExcException : public ExecutionException
{
    public:
        UnhandledExcException(const char *file_,
                              size_t line_,
                              const char *function_,
                              Context *ctx_,
                              Ref exception_);
        UnhandledExcException(const UnhandledExcException& other);
        virtual ~UnhandledExcException();

        virtual const char *getString() const
        {
            return "Callstack bounds exception.";
        }

        inline Ref getException() const
        {
            return exception;
        }

        inline Context *getContext() const
        {
            return ctx;
        }
    private:
        Context *ctx;
        Ref exception;
};

size_t toIndex(Context *ctx, Value *value);
Ref getMember(Context *ctx, Value *val, Value *key);
Ref setMember(Context *ctx, Value *dest, Value *key, Value *value);
Ref call(Context *ctx, Value *value, const List<Ref>& args);
Ref callMethod(Context *ctx, Value *obj, const String& methName, const List<Ref>& args);
bool isInstance(Context *ctx, Value *obj, Value *type);
}

#endif // SCRIPTING_CONTEXT_H
