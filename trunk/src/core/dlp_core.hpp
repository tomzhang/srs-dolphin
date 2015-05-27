
/*
 The MIT License (MIT)
 
 Copyright (c) 2015 winlin
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef DLP_CORE_HPP
#define DLP_CORE_HPP

/*
 #include <dlp_core.hpp>
 */

#define DLP_VERSION "1.0.0"
#define DLP_AUTHORS "winlin"

// for 32bit os, 2G big file limit for unistd io,
// ie. read/write/lseek to use 64bits size for huge file.
#ifndef _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64
#endif

// for int64_t print using PRId64 format.
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif

#include <inttypes.h>

#include <assert.h>
#define srs_assert(expression) assert(expression)

#include <stddef.h>
#include <sys/types.h>

// free the p and set to NULL.
// p must be a T*.
#define dlp_freep(p) \
    if (p) { \
        delete p; \
        p = NULL; \
    } \
    (void)0

// log.
#include <stdio.h>
#include <unistd.h>
extern int dlp_generate_id();
extern int dlp_get_id();
#define dlp_verbose(msg, ...) printf("[verbose][%d][%d] ", getpid(), dlp_get_id()); printf(msg, ##__VA_ARGS__); printf("\n")
#define dlp_info(msg, ...) printf("[info][%d][%d] ", getpid(), dlp_get_id()); printf(msg, ##__VA_ARGS__); printf("\n")
#define dlp_trace(msg, ...) printf("[trace][%d][%d] ", getpid(), dlp_get_id()); printf(msg, ##__VA_ARGS__); printf("\n")
#define dlp_warn(msg, ...) printf("[warn][%d][%d] ", getpid(), dlp_get_id()); printf(msg, ##__VA_ARGS__); printf("\n")
#define dlp_error(msg, ...) printf("[error][%d][%d] ", getpid(), dlp_get_id()); printf(msg, ##__VA_ARGS__); printf("\n")

// errors.

#define ERROR_SUCCESS 0
#define ERROR_SOCKET_LISTEN     1000
#define ERROR_FORK_WORKER       1001
#define ERROR_ST_INITIALIZE     1002

// utilies.
#include <string>
#include <vector>
extern std::vector<int> dlp_list_to_ints(std::string str_list);
extern int dlp_listen_tcp(int port, int& fd);
extern int dlp_st_init();

#endif
