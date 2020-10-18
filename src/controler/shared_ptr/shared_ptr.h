

#ifndef SMARTPOINTERS_SHARED_PTR_H
#define SMARTPOINTERS_SHARED_PTR_H

#include <iostream>

template <class T>
class SharedPtr {
public:
    explicit SharedPtr(T* ptr = NULL);
    ~SharedPtr();

    template <class U>
    SharedPtr(SharedPtr<U>& other);

    template <class U>
    SharedPtr<T>& operator=(SharedPtr<U>& other);

    explicit operator bool() const;
    T operator*()const ;
    T* operator->()const ;

    T* get_ptr() const;

    template <class U> friend class SharedPtr;
    friend class TestSharedPtr;

private:
    T* m_ptr;
    size_t* m_counter;

    void delete_ptr();

};

#include "shared_ptr.hpp"
#endif //SMARTPOINTERS_SHARED_PTR_H
