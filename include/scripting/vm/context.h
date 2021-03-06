#ifndef SCRIPTING_CONTEXT_H
#define SCRIPTING_CONTEXT_H

#include "scripting/vm/types.h"
#include "scripting/vm/bytecode.h"
#include <setjmp.h>

#define SCRIPTING_MAX_CALLSTACK_SIZE 256
#define SCRIPTING_MAX_STACK_SIZE 128

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
        struct Stack
        {
            Stack() : size(0) {}

            size_t size;
            Value values[SCRIPTING_MAX_STACK_SIZE];
        };

        struct CallstackEntry
        {
            CallstackEntry() : offset(0) {}
            CallstackEntry(Bytecode bytecode_) : bytecode(bytecode_), offset(0) {}

            Bytecode bytecode;
            HashMap<Str, Value> variables;
            List<Stack> stacks;
            List<size_t> catchBlocks;
            size_t offset;
        };

        Context(Engine *engine);
        ~Context();

        const CallstackEntry *getCallstack() const
        {
            return callStack;
        }

        CallstackEntry *getCallstack()
        {
            return callStack;
        }

        size_t getCallstackSize() const
        {
            return callStackSize;
        }

        Engine *getEngine() const
        {
            return engine;
        }

        scripting::Value getVariable(const Str& name);

        void reset();
        Value run(const Bytecode& bytecode, List<Value> args);
        void throwException(Value exc);
    private:
        void popCallstack();
        Value _run(const Bytecode& bytecode, List<Value> args);
        Engine *engine;
        size_t callStackSize;
        CallstackEntry callStack[SCRIPTING_MAX_CALLSTACK_SIZE];
        Value exception;
        jmp_buf jumpBuf;

        Value popStack(Stack& stack);
};

class UnhandledExcException : public ExecutionException
{
    public:
        UnhandledExcException(const char *file_,
                              size_t line_,
                              const char *function_,
                              Context *ctx_,
                              const Value& exception_);
        UnhandledExcException(const UnhandledExcException& other);
        virtual ~UnhandledExcException();

        virtual const char *getString() const
        {
            return "Unhandled script exception.";
        }

        Value getException() const
        {
            return exception;
        }

        Context *getContext() const
        {
            return ctx;
        }
    private:
        Context *ctx;
        Value exception;
};

size_t toIndex(Context *ctx, const Value& value);
Value getMember(Context *ctx, const Value& val, const Value& key);
void setMember(Context *ctx, const Value& dest, const Value& key, const Value& value);
Value call(Context *ctx, const Value& value, const List<Value>& args);
Value callMethod(Context *ctx, const Value& obj, const Str& methName, const List<Value>& args);
bool isInstance(Context *ctx, const Value& obj, const Value& type);
}

#endif // SCRIPTING_CONTEXT_H
