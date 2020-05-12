#ifndef FEUP_CAL_PROJ_POINTER_WRAPPER_H
#define FEUP_CAL_PROJ_POINTER_WRAPPER_H


#include <memory>

/**
 * @brief Wraps a pointer into a class
 *
 * @tparam T    the type that the pointer stores
 */
template<class T>
class PointerWrapper {
public:
    /**
     * @brief The wrapped pointer
     */
    T *pointer;

    /**
     * @brief The constructor that receives the pointer
     *
     * @param pointer   the pointer to wrap
     */
    explicit PointerWrapper(T *pointer) : pointer(pointer) {}

    /**
     * @brief Compares to another wrapper
     *
     * Compares what the pointer holds.
     *
     * @param rhs   the other wrapper
     * @return      true if they are equal, false otherwise
     */
    bool operator==(const PointerWrapper &rhs) const;

    /**
     * @brief Compares to another wrapper
     *
     * Compares what the pointer holds.
     *
     * @param rhs   the other wrapper
     * @return      true if they are different, false otherwise
     */
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
