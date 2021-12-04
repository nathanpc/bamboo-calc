
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the LISP_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// LISP_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef LISP_EXPORTS
#define LISP_API __declspec(dllexport)
#else
#define LISP_API __declspec(dllimport)
#endif

// This class is exported from the Lisp.dll
class LISP_API CLisp {
public:
	CLisp(void);
	// TODO: add your methods here.
};

extern LISP_API int nLisp;

LISP_API int fnLisp(void);

