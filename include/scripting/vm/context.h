#ifndef SCRIPTING_CONTEXT_H
#define SCRIPTING_CONTEXT_H

#include "scripting/vm/types.h"
#include "scripting/vm/bytecode.h"
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
            HashMap<String, Value *> variables;
            List<List<Value *>> stacks;
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
        Value *run(const Bytecode& bytecode, List<Value *> args);
        void throwException(Value *exc);
    private:
        Value *_run(const Bytecode& bytecode, List<Value *> args);
        Engine *engine;
        size_t callStackSize;
        CallstackEntry callStack[SCRIPTING_MAX_CALLSTACK_SIZE];
        Value *exception;
        jmp_buf jumpBuf;

        Value *popStack(List<Value *>& stack);
};

class UnhandledExcException : public ExecutionException
{
    public:
        UnhandledExcException(const char *file_,
                              size_t line_,
                              const char *function_,
                              Context *ctx_,
                              Value *exception_);
        UnhandledExcException(const UnhandledExcException& other);
        virtual ~UnhandledExcException();

        virtual const char *getString() const
        {
            return "Unhandled script exception.";
        }

        inline Value *getException() const
        {
            return exception;
        }

        inline Context *getContext() const
        {
            return ctx;
        }
    private:
        Context *ctx;
        Value *exception;
};

size_t toIndex(Context *ctx, Value *value);
Value *getMember(Context *ctx, Value *val, Value *key);
void setMember(Context *ctx, Value *dest, Value *key, Value *value);
Value *call(Context *ctx, Value *value, const List<Value *>& args);
Value *callMethod(Context *ctx, Value *obj, const String& methName, const List<Value *>& args);
bool isInstance(Context *ctx, Value *obj, Value *type);
}

#endif // SCRIPTING_CONTEXT_H
