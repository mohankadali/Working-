#if defined(BUILD_TYPE_NORMAL)
# define DEBUG(x) do {;} while (0) /* paranoid-style null code */
#elif defined(BUILD_TYPE_DEBUG)
# define DEBUG(x) _debug_trace x /* e.g. DEBUG((_debug_trace args)) */
#else
# error "Please specify build type in the Makefile"
#endif 
