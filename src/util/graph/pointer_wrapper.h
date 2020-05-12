#ifndef FEUP_CAL_PROJ_POINTER_WRAPPER_H
#define FEUP_CAL_PROJ_POINTER_WRAPPER_H


#include <memory>

template<class T>
class PointerWrapper {
public:
    T *pointer;

    explicit PointerWrapper(T *pointer) : pointer(pointer) {}

    bool operator==(const PointerWrapper &rhs) const;

    bool operator!=(const PointerWrapper &rhs) const;
};

template<class T>
bool PointerWrapper<T>::operator==(const PointerWrapper &rhs) const {
    return *pointer == *rhs.pointer;
}

template<class T>
bool PointerWrapper<T>::operator!=(const PointerWrapper &rhs) const {
    return !(rhs == *this);
}


#endif //FEUP_CAL_PROJ_POINTER_WRAPPER_H
