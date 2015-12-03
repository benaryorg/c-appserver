#include <stdio.h>
#include <stdarg.h>
#include <cappserver.h>

void print_file(FILE *file,const char *name,const char *format,va_list ap)
{
	char arr[0x1000]={0};
	vsprintf(arr,format,ap);
	fprintf(file,"[%s]: %s\n",name,arr);
}

void print_error(const char *name,const char *format,...)
{
	va_list ap;
	va_start(ap,format);
	print_file(stderr,name,format,ap);
	va_end(ap);
}

void print_log(const char *name,const char *format,...)
{
	va_list ap;
	va_start(ap,format);
	print_file(stdout,name,format,ap);
	va_end(ap);
}

