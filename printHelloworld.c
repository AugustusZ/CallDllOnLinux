/************************************************************/
/*	Test Linux Dynamic Function Loading with "Hello World"	*/
/*															*/
/*	void *dlopen(const char *filename, int flag)			*/
/*			Opens dynamic library and return handle			*/
/*															*/
/*	const char *dlerror(void)								*/
/*	    	Returns string describing the last error.		*/
/*															*/
/*	void *dlsym(void *handle, char *symbol)					*/
/*	    	Return pointer to symbol's load point.			*/
/*	    	If symbol is undefined, NULL is returned.		*/
/*															*/
/*	int dlclose (void *handle)								*/
/*	    	Close the dynamic library handle.				*/
/*															*/
/************************************************************/
#include <stdio.h>
#include <stdlib.h>
 
/* Include file and variables	*/
#include <dlfcn.h>
void  *FunctionLib;		/*  Handle to shared lib file */
const char * (*Function)();		/*  Pointer to loaded routine */
const char *dlError;		/*  Pointer to error string */

int main()
{
  int rc;	

/* Open Dynamic Loadable Libary using LD_LIBRARY path */
  FunctionLib = dlopen("./returnHelloworld.so",RTLD_LAZY);
  // dlError = dlerror();
  // if( dlError ) exit(1);

/* Find the second loaded function */
  Function = dlsym( FunctionLib, "returnHelloworld");
  // dlError = dlerror();
  // if( dlError ) exit(1);

/* Execute the second loaded function */
  const char * HelloworldString = (*Function)();
  printf("%s\n", HelloworldString); 

/* Close the shared library handle */
  rc = dlclose(FunctionLib);
  // dlError = dlerror();

  return(0);
}