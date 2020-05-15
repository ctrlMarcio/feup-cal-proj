
#include "pointer_wrapper.h"

template<class T>
PointerWrapper<T>::PointerWrapper(T *pointer) : pointer(pointer) {}

template<class T>
bool PointerWrapper<T>::operator==(const PointerWrapper &rhs) const {
    return *pointer == *rhs.pointer;
}

template<class T>
bool PointerWrapper<T>::operator!=(const PointerWrapper &rhs) const {
    return !(rhs == *this);
}

template<class T>
T *PointerWrapper<T>::getPointer() const {
    return pointer;
}
