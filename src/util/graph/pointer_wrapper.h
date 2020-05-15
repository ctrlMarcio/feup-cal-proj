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
     * @brief The constructor that receives the pointer
     *
     * @param pointer   the pointer to wrap
     */
    explicit PointerWrapper(T *pointer);

    /**
     * @brief Gets the pointer
     *
     * @return  the pointer
     */
    T *getPointer() const;

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

private:
    /**
     * @brief The wrapped pointer
     */
    T *pointer;
};

#include "pointer_wrapper.tpp"

#endif //FEUP_CAL_PROJ_POINTER_WRAPPER_H
