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
#define stat_os __stat64
#define fstat_os _fstat64
#define seek_os _lseeki64
#define open_os _open
#define write_os _write
#define read_os _read
#define unlink_os _unlink
#define close_os _close
#define O_CREAT _O_CREAT
#define O_RDWR  _O_RDWR
#define O_DSYNC 0
#define ssize_t SSIZE_T
#elif defined(__APPLE__)
#define stat_os stat
#define fstat_os fstat
#define seek_os lseek
#define open_os open
#define write_os write
#define read_os read
#define unlink_os unlink
#define close_os close
#else
#define stat_os stat64
#define fstat_os fstat64
#define seek_os lseek64
#define open_os open
#define write_os write
#define read_os read
#define unlink_os unlink
#define close_os close
#endif
