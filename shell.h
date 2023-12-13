#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>

#define small(a, b) (((a) < (b)) ? (a) : (b))

/cons/
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1


/* string helpers */
int __stringcmp(char *, char *);
char *__stringcat(char *, char *);
int __stringspn(char *, char *);
int __stringcspn(char *, char *);
char *_stringchr(char *, char);

extern char **environment;
extern char *ln;
extern char **controls;
extern char *gatesofshell_name;
extern int condition;

/aiders/
void cout(char *, int);
char **unit(char *, char *);
void delete_line(char *);
int __stringlenth(char *);
void __stringcopy(char *, char *);

/inbuit functions/
void surr(char **);
void leave(char **);

/functions of main/
extern void standalone(void);
extern void starter(char **cmnow, int cincommand);

/**
 *struct chart - maps command name to a func. 
 *@funcname: name of the command
 *@func: the function that executes the command
 */

typedef struct chart
{
	char *funcname;
	void (*func)(char **command);
} function_map;

/Memory helpers/
char __stringtok(char *, char *, char *);
int __itoa(char *);
void *__realloc(void *ptr, unsigned int previous_size, unsigned int current_size);
void holder(int);
void delete_comment(char *);

/checks/
int controlparse(char *);
void performcommand(char **, int);
char *accesspath(char *);
void (findfunction(char *))(char *);
char *fetchenvironment(char *);

#endif /SHELL_H/
