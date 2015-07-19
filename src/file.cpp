#include "file.h"

#include "endian_utils.h"
#include "error.h"
#include "filesystem.h"
#include "globals.h"

#include <cmath>
#include <sys/stat.h>
#include <dirent.h>

time_t getLastFileModification(const char *filename)
{
    struct stat status;

    String fullFilename = fileSys != nullptr ? fileSys->getAbsolutePath(filename) : filename;

    if (fullFilename.getLength() == 0)
    {
        THROW(FileException, filename, "Unable to get modification date.");
    }

    if (stat(fullFilename.getData(), &status) != -1)
    {
        return status.st_mtime;
    } else
    {
        THROW(FileException, fullFilename, "Unable to get modification date.");
    }
}

bool doesFileExist(const char *filename)
{
    String fullFilename = fileSys != nullptr ? fileSys->getAbsolutePath(filename) : filename;

    struct stat status;

    return stat(fullFilename.getData(), &status) != -1;
}

List<String> listFiles(const char *directory)
{
    List<String> result;

    DIR *dir = opendir(directory);

    if (dir == nullptr)
    {
        THROW(FileException, directory, "Unable to open file");
    }

    dirent *ent;

    while ((ent = readdir(dir)) != nullptr)
    {
        struct stat status;

        String fullName = String::format("%s/%s", directory, ent->d_name);

        if (stat(fullName.getData(), &status) == -1)
        {
            continue;
        }

        if (S_ISREG(status.st_mode))
        {
            result.append(ent->d_name);
        }
    }

    closedir(dir);

    return result;
}

File::File(const char *filename_, const char *mode)
{
    if (fileSys != nullptr)
    {
        filename = fileSys->getAbsolutePath(filename_);
    } else
    {
        filename = filename_;
    }

    file = std::fopen(filename.getData(), mode);

    if (file == nullptr)
    {
        THROW(FileException, filename, "Unable to open");
    }
}

File::~File()
{
    if (file != nullptr)
    {
        std::fclose(file);
    }
}

void File::read(size_t amount, void *destination)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    if (std::fread(destination, amount, 1, file) != 1)
    {
        THROW(FileException, filename, "Unable to read from file.")
    }
}

void File::write(size_t amount, const void *data)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    if (std::fwrite(data, amount, 1, file) != 1)
    {
        THROW(FileException, filename, "Unable to write to file.")
    }
}

void File::seek(long int offset, Origin origin)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    switch (origin)
    {
    case Set:
    {
        if (std::fseek(file, offset, SEEK_SET) != 0)
        {
            THROW(FileException, filename, "Unable to seek file.");
        }
        break;
    }
    case Current:
    {
        if (std::fseek(file, offset, SEEK_CUR) != 0)
        {
            THROW(FileException, filename, "Unable to seek file.");
        }
        break;
    }
    case End:
    {
        if (std::fseek(file, offset, SEEK_END) != 0)
        {
            THROW(FileException, filename, "Unable to seek file.");
        }
        break;
    }
    }
}

long int File::tell()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    return std::ftell(file);
}

void File::flush()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    std::fflush(file);
}

bool File::isAtEndOfFile()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    return std::feof(file);
}

size_t File::getSize()
{
    long int lastPosition = tell();

    seek(0, End);

    size_t size = tell();

    seek(lastPosition, Set);

    return size;
}

uint8_t File::readUInt8()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    uint8_t integer;

    read(1, &integer);

    return integer;
}

int8_t File::readInt8()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    int8_t integer;

    read(1, &integer);

    return integer;
}

uint16_t File::readUInt16LE()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    uint16_t integer;

    read(2, &integer);

    return FROM_LE_U16(integer);
}

int16_t File::readInt16LE()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    int16_t integer;

    read(2, &integer);

    return FROM_LE_S16(integer);
}

uint32_t File::readUInt32LE()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    uint32_t integer;

    read(4, &integer);

    return FROM_LE_U32(integer);
}

int32_t File::readInt32LE()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    int32_t integer;

    read(4, &integer);

    return FROM_LE_S32(integer);
}

uint64_t File::readUInt64LE()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    uint64_t integer;

    read(8, &integer);

    return FROM_LE_U64(integer);
}

int64_t File::readInt64LE()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    int64_t integer;

    read(8, &integer);

    return FROM_LE_S64(integer);
}

uint16_t File::readUInt16BE()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    uint16_t integer;

    read(2, &integer);

    return FROM_BE_U16(integer);
}

int16_t File::readInt16BE()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    int16_t integer;

    read(2, &integer);

    return FROM_BE_S16(integer);
}

uint32_t File::readUInt32BE()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    uint32_t integer;

    read(4, &integer);

    return FROM_BE_U32(integer);
}

int32_t File::readInt32BE()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    int32_t integer;

    read(4, &integer);

    return FROM_BE_S32(integer);
}

uint64_t File::readUInt64BE()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    uint64_t integer;

    read(8, &integer);

    return FROM_BE_U64(integer);
}

int64_t File::readInt64BE()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    int64_t integer;

    read(8, &integer);

    return FROM_BE_S64(integer);
}

float File::readFloat32()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    float result;

    read(4, &result);

    return result;
}

char File::readChar()
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    int value = std::fgetc(file);

    if (value == EOF)
    {
        return '\x00';
    }

    return static_cast<char>(value);
}

void File::writeUInt8(uint8_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    write(1, &value);
}

void File::writeInt8(int8_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    write(1, &value);
}

void File::writeUInt16LE(uint16_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    value = TO_LE_U64(value);

    write(2, &value);
}

void File::writeInt16LE(int16_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    value = TO_LE_S64(value);

    write(2, &value);
}

void File::writeUInt32LE(uint32_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    value = TO_LE_U64(value);

    write(4, &value);
}

void File::writeInt32LE(int32_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    value = TO_LE_S64(value);

    write(4, &value);
}

void File::writeUInt64LE(uint64_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    value = TO_LE_U64(value);

    write(8, &value);
}

void File::writeInt64LE(int64_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    value = TO_LE_S64(value);

    write(8, &value);
}

void File::writeUInt16BE(uint16_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    value = TO_BE_U64(value);

    write(2, &value);
}

void File::writeInt16BE(int16_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    value = TO_BE_S64(value);

    write(2, &value);
}

void File::writeUInt32BE(uint32_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    value = TO_BE_U64(value);

    write(4, &value);
}

void File::writeInt32BE(int32_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    value = TO_BE_S64(value);

    write(4, &value);
}

void File::writeUInt64BE(uint64_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    value = TO_BE_U64(value);

    write(8, &value);
}

void File::writeInt64BE(int64_t value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    value = TO_BE_S64(value);

    write(8, &value);
}

void File::writeFloat32(float value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    write(4, &value);
}

void File::printf(const char *format, ...)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    va_list list;

    va_start(list, format);

    std::vfprintf(file, format, list);

    va_end(list);
}

void File::vprintf(const char *format, va_list list)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    std::vfprintf(file, format, list);
}

void File::writeChar(char value)
{
    #ifdef DEBUG
    if (file == nullptr)
    {
        THROW(FileException, filename, "File invalid");
    }
    #endif

    std::putc(value, file);
}
