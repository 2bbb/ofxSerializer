#if (_MSC_VER)
#   define DECLTYPE(...) decltype(__VA_ARGS__)
#else
#   if __cplusplus<201103L
#       define DECLTYPE(...) typeof(__VA_ARGS__)
#   else
#       define DECLTYPE(...) decltype(__VA_ARGS__)
#   endif
#endif

BEGIN_NAMESPACE(ofx)
BEGIN_NAMESPACE(Serializer)
namespace {
#define DefineMethodChecker(method) \
    template <typename T> \
    struct has_##method##_impl { \
    private: \
        template <typename U> \
        static char check_method(DECLTYPE(&U::method)); \
        template <typename> \
        static long check_method(...); \
    public: \
        static const bool value = (sizeof(check_method<T>(0)) == sizeof(char)); \
    };
    
    DefineMethodChecker(serialize); // define struct has_serialize_impl
    DefineMethodChecker(deserialize); // define struct has_deserialize_impl
    DefineMethodChecker(jsonize); // define struct has_jsonize_impl
#undef DefineMethodChecker
    
#pragma mark type_filter predicate
    template <typename T>
    struct has_serialize {
        static const bool value = has_serialize_impl<T>::value;
    };
    
    template <typename T>
    struct has_deserialize {
        static const bool value = has_deserialize_impl<T>::value;
    };
    
    template <typename T>
    struct is_number {
        static const bool value = util::is_arithmetic<T>::value;
    };
    
    template <typename T, template <typename> class Template>
    struct is_object {
        static const bool value = !util::is_arithmetic<T>::value
        && !util::is_array<T>::value
        && !util::is_pointer<T>::value
        && !Template<T>::value;
    };
    
    template <typename T>
    struct is_pointer_without_array {
        static const bool value = !util::is_array<T>::value
        && util::is_pointer<T>::value;
    };
    
    template <typename T>
    struct is_array {
        static const bool value = util::is_array<T>::value;
    };
};

#define type_filter(...) inline typename util::enable_if<__VA_ARGS__::value >::type

END_NAMESPACE(Serializer)
END_NAMESPACE(ofx)
