#pragma once

namespace util {
    template <typename T>
    struct is_arithmetic { static const bool value = false; };
    
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
    struct is_same { static const bool value = false; };
    template <typename T>
    struct is_same<T, T> { static const bool value = true; };
    
    template <bool b, typename T = void> struct enable_if;
    
    template <typename T>
    struct enable_if<true, T> { typedef T type; };
    
    template <typename T>
    struct remove_const { typedef T type; };
    template <typename T>
    struct remove_const<const T> { typedef T type; };
    
    template <typename T>
    struct remove_pointer { typedef T type; };
    template <typename T>
    struct remove_pointer<T *> { typedef T type; };
    
    template <typename T>
    struct add_lvalue_reference { typedef T& type; };
    template <typename T>
    struct add_lvalue_reference<T &> { typedef T type; };
    
    
#pragma mark utilities for array

    template<typename T>
    struct is_pointer { static const bool value = false; };
    
    template<typename T>
    struct is_pointer<T *> { static const bool value = true; };
    
    template<typename, unsigned = 0>
    struct extent;
    
    template<typename, unsigned _Uint>
    struct extent { static const std::size_t value = 0; };
	   
    template<typename _Tp, unsigned _Uint, std::size_t _Size>
    struct extent<_Tp[_Size], _Uint> {
        static const std::size_t value = _Uint == 0 ? _Size : extent<_Tp, _Uint - 1>::value;
    };
    
    template<typename _Tp, unsigned _Uint>
    struct extent<_Tp[], _Uint> {
        static const std::size_t value = _Uint == 0 ? 0 : extent<_Tp, _Uint - 1>::value;
    };
    
    template<class T>
    struct is_array { static const bool value = 0 < util::extent<T>::value; };
    
    template <typename T>
    size_t length(T &t) { return util::extent<T>::value; }
};

