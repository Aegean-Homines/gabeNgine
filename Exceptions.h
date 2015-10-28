#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>
#include <iostream>

class WindowManagerException : public std::runtime_error
{
public:
	const char * what() const throw ()
	{
		return this->exceptionMessage;
	}

	WindowManagerException(const char* message) : runtime_error(message){
		exceptionMessage = message;
	}

private:
	const char* exceptionMessage;
};

class FileManagerException: public std::runtime_error
{
public:
	const char * what() const throw ()
	{
		return this->exceptionMessage;
	}

	FileManagerException(const char* message) : runtime_error(message){
		exceptionMessage = message;
	}

private:
	const char* exceptionMessage;
};

class SurfaceManagerException : public std::runtime_error
{
public:
	const char * what() const throw ()
	{
		return this->exceptionMessage;
	}

	SurfaceManagerException(const char* message) : runtime_error(message){
		exceptionMessage = message;
	}

private:
	const char* exceptionMessage;
};

class ImageManagerException : public std::runtime_error
{
public:
	const char * what() const throw ()
	{
		return this->exceptionMessage;
	}

	ImageManagerException(const char* message) : runtime_error(message){
		exceptionMessage = message;
	}

private:
	const char* exceptionMessage;
};


#endif // EXCEPTIONS_H_