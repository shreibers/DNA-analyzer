//
// Created by a on 9/22/20.
//

#ifndef SRC_MYEXCEPTION_H
#define SRC_MYEXCEPTION_H


#include <exception>

class MyException : public std::exception{
public:
    MyException(const char * message);
    /*virtual*/ const char* what() const throw()
    {
        return m_message;
    }

private:
    const char* m_message;
};


#endif //SRC_MYEXCEPTION_H
