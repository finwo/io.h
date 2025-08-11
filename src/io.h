#ifndef __FINWO_IO_H__
#define __FINWO_IO_H__

#if (!(defined(_WIN32) || defined(_WIN64) || defined(__APPLE))) && !defined(_LARGEFILE64_SOURCE)
#define _LARGEFILE64_SOURCE
#endif

#include <fcntl.h>
#include <stdio.h>

#if defined(_WIN32) || defined(_WIN64)
// Needs to be AFTER winsock2 which is used for finwo/endian.h
#include <windows.h>
#include <io.h>
#include <BaseTsd.h>
#else
#include <sys/types.h>
#include <unistd.h>
#endif

#if defined(_WIN32) || defined(_WIN64)
#define access_os _access
#define stat_os __stat64
#define fstat_os _fstat64
#define seek_os _lseeki64
#define open_os _open
#define write_os _write
#define read_os _read
#define unlink_os _unlink
#define close_os _close
#define truncate_os _chsize
#define O_CREAT _O_CREAT
#define O_RDWR  _O_RDWR
#define O_DSYNC 0
#define S_IRUSR _S_IREAD
#define S_IWUSR _S_IWRITE
#define S_IXUSR 0
#define S_IRGRP 0
#define S_IWGRP 0
#define S_IXGRP 0
#define S_IROTH 0
#define S_IWOTH 0
#define S_IXOTH 0
#define ssize_t SSIZE_T
#elif defined(__APPLE__)
#define access_os access
#define stat_os stat
#define fstat_os fstat
#define seek_os lseek
#define open_os open
#define write_os write
#define read_os read
#define unlink_os unlink
#define close_os close
#define truncate_os ftruncate
#else
#define access_os access
#define stat_os stat64
#define fstat_os fstat64
#define seek_os lseek64
#define open_os open
#define write_os write
#define read_os read
#define unlink_os unlink
#define close_os close
#define truncate_os ftruncate
#endif

#endif // __FINWO_IO_H__
