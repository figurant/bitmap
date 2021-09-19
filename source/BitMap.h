//
// Created by zhuwei on 2021/9/16.
//

#ifndef UNTITLED_BITMAP_H
#define UNTITLED_BITMAP_H
#define unlikely(x) __builtin_expect(!!(x), 0)

#include <cstdlib>
#include <__bit_reference>
#include <climits>

class BitMap {
public:
    typedef std::__bit_reference<BitMap, true> reference;
    typedef std::__bit_const_reference<BitMap> const_reference;
    typedef size_t __storage_type;
    typedef __storage_type *__storage_pointer;
    typedef const __storage_type *__const_storage_pointer;
    typedef BitMap __self;

    BitMap(size_t size);
    BitMap(const BitMap &__v);

    void reset();//将所有bit置为0

    const_reference operator[](size_t pos) const;
    reference operator[](size_t pos);

    void operator&=(const BitMap &__v);
    void operator|=(const BitMap &__v);
    void flip();//将所有bit取反
    bool operator==(const BitMap &__rhs) const;


    class BitMapException : std::exception {
    public:
        enum ExceptionType {
            outOfIndex, sizeNotEqual
        };

        explicit BitMapException(ExceptionType type) {
            this->type = type;
        }

    private:
        ExceptionType type;
    };

private:
    static const unsigned __bits_per_word = static_cast<unsigned>(sizeof(__storage_type) * CHAR_BIT);
    std::shared_ptr<__storage_type> __bitmap_;
    size_t size;

    inline void index_bound_check(size_t idx) const {
        if (unlikely(idx >= size)) {
            throw new BitMapException(BitMapException::outOfIndex);
        }
    }

    inline void size_equal_check(const BitMap &__v) const {
        if (unlikely(size != __v.size)) {
            throw new BitMapException(BitMapException::sizeNotEqual);
        }
    }

    inline size_t _word_count() const{
        return (size % __bits_per_word == 0) ? (size / __bits_per_word) : (size / __bits_per_word + 1);
    }
};

#endif //UNTITLED_BITMAP_H
