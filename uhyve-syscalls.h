/* Copyright (c) 2017, RWTH Aachen University
 * Author(s): Daniel Krebs <github@daniel-krebs.net>
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose with or without fee is hereby granted, provided
 * that the above copyright notice and this permission notice appear
 * in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#ifndef UHYVE_SYSCALLS_H
#define UHYVE_SYSCALLS_H

#include <unistd.h>
#include <stddef.h>

typedef struct {
	int fd;
	const char* buf;
	size_t len;
	int ret;
} __attribute__((packed)) uhyve_write_t;

typedef struct {
	const char* name;
	int flags;
	int mode;
	int ret;
} __attribute__((packed)) uhyve_open_t;

typedef struct {
	int fd;
	int ret;
} __attribute__((packed)) uhyve_close_t;

typedef struct {
	int fd;
	char* buf;
	size_t len;
	ssize_t ret;
} __attribute__((packed)) uhyve_read_t;

typedef struct {
	int fd;
	off_t offset;
	int whence;
} __attribute__((packed)) uhyve_lseek_t;

typedef struct {
	uint64_t rip;
	uint64_t addr;
	int success;
} __attribute__ ((packed)) uhyve_pfault_t;

typedef struct {
	int dirfd;
	const char* name;
	int flags;
	int mode;
	int ret;
} __attribute__((packed)) uhyve_openat_t;

typedef struct {
    int dirfd;
	char *path;
	char* buf;
	int bufsz;
	ssize_t ret;
} __attribute__((packed)) uhyve_readlinkat_t;

typedef struct {
	int fd;
	int ret;
	struct stat *st;
} __attribute__ ((packed)) uhyve_fstat_t;

typedef struct {
    int dirfd;
	const char *pathname;
	int mode;
	int ret;
    int flags;
} __attribute__((packed)) uhyve_faccessat_t;

typedef struct {
	int dirfd;
	char *filename;
	struct stat *buf;
    int flag;
    int ret;
} __attribute__ ((packed)) uhyve_newfstatat_t;

typedef struct {
	char *buf;
	size_t size;
	int ret;
} __attribute__ ((packed)) uhyve_getcwd_t;

typedef unsigned short umode_t;
typedef struct {
    int dirfd;
	const char *pathname;
	umode_t mode;
	int ret;
} __attribute__ ((packed)) uhyve_mkdirat_t;

typedef struct {
    int dirfd;
	const char* pathname;
    int flags;
	int ret;
} __attribute__((packed)) uhyve_unlinkat_t;

/* Warning: this needs to be consistent with what is in kernel/minifs.c! */
#define MINIFS_LOAD_MAXPATH		128
typedef struct {
	char hostpath[MINIFS_LOAD_MAXPATH];
	char guestpath[MINIFS_LOAD_MAXPATH];
} __attribute__((packed)) uhyve_minifs_load_t;

#endif // UHYVE_SYSCALLS_H
