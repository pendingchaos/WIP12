#ifndef FILE_H
#define FILE_H

#include "misc_macros.h"
#include "containers/list.h"
#include "containers/string.h"

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
                      String filename_,
                      String problem_) : Exception(file_, line_, function_),
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

        inline const String& getFilename() const
        {
            return filename;
        }

        inline const String& getProblem() const
        {
            return problem;
        }
    private:
        String filename;
        String problem;
};

time_t getLastFileModification(const char *filename);
bool doesFileExist(const char *filename);
List<String> listFiles(const char *directory);

class File
{
    NO_COPY(File);

    public:
        enum Origin
        {
            Set,
            Current,
            End
        };

        File(const char *filename, const char *mode);
        ~File();

        void read(size_t amount, void *destination);

        void write(size_t amount, const void *data);

        void seek(long int offset, File::Origin origin);

        long int tell();

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

        void printf(const char *format, ...);

        void vprintf(const char *format, va_list list);

        void writeChar(char value);
    private:
        FILE *file;
        String filename;
};

#endif // FILE_H
