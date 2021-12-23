/**
 * BambooWrapper.h
 * A C++ wrapper for the Bamboo Lisp interpreter C library.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#include "BambooWrapper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/**
 * Initializes a brand new interpreter environment.
 */
Bamboo::Bamboo() {
	bamboo_error_t err;

	err = bamboo_init(&this->env);
	if (err)
		throw BambooException(err);
}

/**
 * Destroys the interpreter environment.
 */
Bamboo::~Bamboo() {

}

/**
 * Wraps Bamboo's error system into a pretty little C++ exception.
 *
 * @param err Bamboo error.
 */
BambooException::BambooException(bamboo_error_t err) {
	this->err = err;
}

/**
 * Creates the error message according to Bamboo's internal error handling.
 *
 * @return Descriptive error message.
 */
const char* BambooException::what() const throw() {
	return bamboo_error_detail();
}

/**
 * Grabs the internal Bamboo Lisp error code that generated the exception.
 *
 * @return Internal error code.
 */
bamboo_error_t BambooException::ErrorCode() {
	return this->err;
}