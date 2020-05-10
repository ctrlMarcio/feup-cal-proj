#ifndef FEUP_CAL_PROJ_POINTER_WRAPPER_H
#define FEUP_CAL_PROJ_POINTER_WRAPPER_H


#include <memory>

template<class T>
class PointerWrapper {
public:
    std::shared_ptr<T> pointer;

    explicit PointerWrapper(const std::shared_ptr<T> &pointer) : pointer(pointer) {}

    explicit PointerWrapper(T &content) : pointer(std::make_shared<T>(content)) {}

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
