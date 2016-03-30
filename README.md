# Call DLL on Linux
The project shows how to call DLL on Linux. 

The code is based on that from the article [*Writing DLLs for Linux apps*](http://www.ibm.com/developerworks/library/l-dll/).

## DLL on Linux
The DLL on Linux is `.so` ([Shared Object](http://stackoverflow.com/a/9810368/5920930)) instead of `.dll` (Dynamic-link library) which you often see on Windows.

## How files work together
1. `printHelloworld` call function `returnHelloworld()` in `returnHelloworld`
2. `returnHelloworld` return string `"Hello World"` to the `main()` function in `printHelloworld`
3. `printHelloworld` prints the string `"Hello World"` to **console**

## How to run
`make` and you will see:

![](make.png)



