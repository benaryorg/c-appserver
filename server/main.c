#include <assert.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <cappserver.h>

int main(int argc,char **argv)
{
	int i;
	void **arr;
	void *ptr;
	
	assert(arr = malloc(sizeof(void *)*argc));

	for(i = 1;i < argc;i++)
	{
		print_log("SERVER","loading %s",argv[i]);
		assert(arr[i-1] = dlopen(argv[i],RTLD_LAZY));
		print_log("SERVER","loaded %s",argv[i]);
	}

	for(i = 0;i < argc-1;i++)
	{
		assert(ptr = dlsym(arr[i],"init"));
		(*((void (**)(void))&ptr))();
	}

	for(i = 0;i < argc-1;i++)
	{
		dlclose(arr[i]);
	}
	free(arr);
}

