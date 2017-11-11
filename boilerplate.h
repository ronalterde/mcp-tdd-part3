/*
 * This is needed because we don't have a C++ std lib
 */

extern "C" void __cxa_pure_virtual() { while (1); }

void operator delete(void * p) {
	(void)p;
}
