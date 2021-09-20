//
// Created by zhuwei on 2021/9/16.
//

#include "BitMap.h"

BitMap::BitMap(size_t size) {
    size_t wordCount = (size % __bits_per_word == 0) ? (size / __bits_per_word) : (size / __bits_per_word + 1);
    this->__bitmap_ = std::make_shared<__storage_type>(wordCount);
    this->size = size;
    for (auto i = 0; i < wordCount; i++) {
        __bitmap_.get()[i] = 0;
    }
}

BitMap::BitMap(const BitMap &__v) {
    size_t wordCount = (__v.size % __bits_per_word == 0) ? (__v.size / __bits_per_word) : (__v.size / __bits_per_word +
                                                                                           1);
    this->__bitmap_ = std::make_shared<__storage_type>(wordCount);
    this->size = __v.size;
    for (auto i = 0; i < wordCount; i++) {
        __bitmap_.get()[i] = __v.__bitmap_.get()[i];
    }
}

void BitMap::reset() {
    size_t wordCount = _word_count();
    for (auto i = 0; i < wordCount; i++) {
        __bitmap_.get()[i] = 0;
    }
}

BitMap::const_reference BitMap::operator[](size_t pos) const {
    index_bound_check(pos);
    return const_reference(__bitmap_.get() + pos / __bits_per_word, __storage_type(1) << pos % __bits_per_word);
}

BitMap::reference BitMap::operator[](size_t pos) {
    index_bound_check(pos);
    return reference(__bitmap_.get() + pos / __bits_per_word, __storage_type(1) << pos % __bits_per_word);
}

void BitMap::operator&=(const BitMap &__v) {
    if (__v.size >= size) {
        size_t wordCount = _word_count();
        for (auto i = 0; i < wordCount; i++) {
            __bitmap_.get()[i] &= __v.__bitmap_.get()[i];
        }
    } else {
        size_t wordCount = (__v.size / __bits_per_word);
        for (auto i = 0; i < wordCount; i++) {
            __bitmap_.get()[i] &= __v.__bitmap_.get()[i];
        }
        size_t extraBitCount = __v.size % __bits_per_word;
        for (auto i = wordCount * __bits_per_word; i < wordCount * __bits_per_word + extraBitCount; i++) {
            this->operator[](i) = this->operator[](i) & __v[i];
        }
    }
}

void BitMap::operator|=(const BitMap &__v) {
    if (__v.size >= size) {
        size_t wordCount = _word_count();
        for (auto i = 0; i < wordCount; i++) {
            __bitmap_.get()[i] |= __v.__bitmap_.get()[i];
        }
    } else {
        size_t wordCount = (__v.size / __bits_per_word);
        for (auto i = 0; i < wordCount; i++) {
            __bitmap_.get()[i] |= __v.__bitmap_.get()[i];
        }
        size_t extraBitCount = __v.size % __bits_per_word;
        for (auto i = wordCount * __bits_per_word; i < wordCount * __bits_per_word + extraBitCount; i++) {
            this->operator[](i) = this->operator[](i) | __v[i];
        }
    }

}

void BitMap::flip() {
    size_t wordCount = _word_count();
    for (auto i = 0; i < wordCount; i++) {
        __bitmap_.get()[i] = ~__bitmap_.get()[i];
    }
}

bool BitMap::operator==(const BitMap &__rhs) const {
    if (size != __rhs.size) {
        return false;
    }
    size_t wordCount = _word_count();
    for (auto i = 0; i < wordCount; i++) {
        if (__bitmap_.get()[i] != __rhs.__bitmap_.get()[i])
            return false;
    }
    return true;
}