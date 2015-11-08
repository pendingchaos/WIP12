#ifndef FILE_H
#define FILE_H

#include "misc_macros.h"
#include "containers/list.h"
#include "containers/string.h"
#include "scripting/bindings.h"

#include <exception>
#include <stdint.h>
#include <stddef.h>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <time.h>

class FileException : public Exception
{
    public:
        FileException(const char *file_,
                      size_t line_,
                      const char *function_,
                      Str filename_,
                      Str problem_) : Exception(file_, line_, function_),
                                         filename(filename_),
                                         problem(problem_) {}

        virtual const char *getString() const
        {
            static char string[FILENAME_MAX+256];
            std::memset(string, 0, sizeof(string));

            std::snprintf(string,
                          sizeof(string),
                          "Unable to do something with a file at %s: %s",
                          filename.getData(),
                          problem.getData());

            return string;
        }

        const Str& getFilename() const
        {
            return filename;
        }

        const Str& getProblem() const
        {
            return problem;
        }
    private:
        Str filename;
        Str problem;
};

time_t getLastFileModification(const char *filename);
bool doesFileExist(const char *filename) BIND;
List<Str> listFiles(const char *directory) BIND;

enum class FileOrigin
{
    Set,
    Current,
    End
} BIND ENUM_CLASS;

class File
{
    NO_COPY(File);

    public:
        File(const char *filename, const char *mode);
        ~File();

        void read(size_t amount, void *destination) NO_BIND;

        ResizableData read(size_t amount)
        {
            ResizableData data(amount);
            read(amount, data.getData());
            return data;
        }

        void write(size_t amount, const void *data) NO_BIND;

        void write(const ResizableData& data)
        {
            write(data.getSize(), data.getData());
        }

        void seek(long int offset, FileOrigin origin);

        size_t tell();

        void flush();

        bool isAtEndOfFile();

        size_t getSize();

        uint8_t readUInt8();
        int8_t readInt8();
        uint16_t readUInt16LE();
        int16_t readInt16LE();
        uint32_t readUInt32LE();
        int32_t readInt32LE();
        uint64_t readUInt64LE();
        int64_t readInt64LE();
        uint16_t readUInt16BE();
        int16_t readInt16BE();
        uint32_t readUInt32BE();
        int32_t readInt32BE();
        uint64_t readUInt64BE();
        int64_t readInt64BE();
        float readFloat32();
        char readChar();
        Str readStr(size_t length);

        void writeUInt8(uint8_t value);
        void writeInt8(int8_t value);
        void writeUInt16LE(uint16_t value);
        void writeInt16LE(int16_t value);
        void writeUInt32LE(uint32_t value);
        void writeInt32LE(int32_t value);
        void writeUInt64LE(uint64_t value);
        void writeInt64LE(int64_t value);
        void writeUInt16BE(uint16_t value);
        void writeInt16BE(int16_t value);
        void writeUInt32BE(uint32_t value);
        void writeInt32BE(int32_t value);
        void writeUInt64BE(uint64_t value);
        void writeInt64BE(int64_t value);
        void writeFloat32(float value);
        void writeStr(Str s);

        void printf(const char *format, ...) NO_BIND;

        void vprintf(const char *format, va_list list) NO_BIND;

        void writeChar(char value);
    private:
        FILE *file;
        Str filename;
} BIND NOT_COPYABLE;

#endif // FILE_H
