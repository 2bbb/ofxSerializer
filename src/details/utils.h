//
//  ofxSerializer_utils.h
//  ofxSerializerExample
//
//  Created by ISHII 2bit on 2015/05/01.
//
//

#pragma once

namespace util {
    template <typename T>
    struct is_arithmetic {
        static const bool value = false;
    };
    
#define IsArithmetic(Type) \
template <> struct is_arithmetic<Type> { static const bool value = true; };
    
    IsArithmetic(bool);
    IsArithmetic(char);
    IsArithmetic(unsigned char);
    IsArithmetic(short);
    IsArithmetic(unsigned short);
    IsArithmetic(int);
    IsArithmetic(unsigned int);
    IsArithmetic(long);
    IsArithmetic(unsigned long);
    IsArithmetic(long long);
    IsArithmetic(unsigned long long);
    IsArithmetic(float);
    IsArithmetic(double);
    IsArithmetic(long double);
    
#undef IsArithmetic
    
    template <typename T, typename U>
    struct is_same {
        static const bool value = false;
    };
    template <typename T>
    struct is_same<T, T> {
        static const bool value = true;
    };
    
    template <bool b, typename T = void> struct enable_if;
    
    template <typename T>
    struct enable_if<true, T> { typedef void type; };
    
    template <typename T>
    struct remove_const {
        typedef T type;
    };
    template <typename T>
    struct remove_const<const T> {
        typedef T type;
    };
    
    template <typename T>
    struct remove_pointer {
        typedef T type;
    };
    template <typename T>
    struct remove_pointer<T *> {
        typedef T type;
    };
    
    template <typename T>
    struct add_lvalue_reference {
        typedef T& type;
    };
    template <typename T>
    struct add_lvalue_reference<T &> {
        typedef T type;
    };
};

