#ifndef LOG_H
#define LOG_H

#include <iostream>

const int LOG_LEVEL_TRACE = 0;
const int LOG_LEVEL_DEBUG = 1;
const int LOG_LEVEL_INFO = 2;
const int LOG_LEVEL_WARN = 3;
const int LOG_LEVEL_ERROR = 4;
const int LOG_LEVEL_FATAL = 5;

extern int LOG_LEVEL;

static std::ostream & os = std::cout;

class Logger {

public:

	int & level;

	Logger() : level(LOG_LEVEL){}

	std::ostream & log_trace(){
		return os << "TRACE - ";
	}

	std::ostream & log_debug(){
		return os << "DEBUG - ";
	}

	std::ostream & log_info(){
		return os << "INFO  - ";
	}

	std::ostream & log_warn(){
		return os << "WARN  - ";
	}

	std::ostream & log_fatal(){
		return os << "FATAL - ";
	}

	std::ostream & log_error(){
		return os << "ERROR - ";
	}

	bool is_trace() {return LOG_LEVEL <= LOG_LEVEL_TRACE;}
	bool is_debug() {return LOG_LEVEL <= LOG_LEVEL_DEBUG;}
	bool is_info() {return LOG_LEVEL <= LOG_LEVEL_INFO;}
	bool is_warn() {return LOG_LEVEL <= LOG_LEVEL_WARN;}
	bool is_error() {return LOG_LEVEL <= LOG_LEVEL_ERROR;}
	bool is_fatal() {return LOG_LEVEL <= LOG_LEVEL_FATAL;}

};

extern Logger logger;


#endif