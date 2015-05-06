/*
for(var i = 2; i <= 20; i++) {
    var args = [];
    for(var j = 0; j < i; j++) args.push(j);
    var str = "template <" + args.map(function(n) { return "typename Arg" + n; }).join(", ") + ">\n"
            + "inline void jsonize(std::ostream &os, " + args.map(function(n) { return "const char * const key" + n + ", const Arg" + n + " &arg" + n; }).join(", ") + ") {\n"
            + "    jsonize(os, key0, arg0);\n"
            + "    jsonize(os << \", \", " + args.slice(1).map(function(n) { return "key" + n + ", arg" + n; }).join(", ") + ");\n"
            + "}";
    console.log(str);
}
*/

template <typename Arg0, typename Arg1>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1);
}
template <typename Arg0, typename Arg1, typename Arg2>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7, const char * const key8, const Arg8 &arg8) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7, key8, arg8);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7, const char * const key8, const Arg8 &arg8, const char * const key9, const Arg9 &arg9) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7, key8, arg8, key9, arg9);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7, const char * const key8, const Arg8 &arg8, const char * const key9, const Arg9 &arg9, const char * const key10, const Arg10 &arg10) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7, key8, arg8, key9, arg9, key10, arg10);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7, const char * const key8, const Arg8 &arg8, const char * const key9, const Arg9 &arg9, const char * const key10, const Arg10 &arg10, const char * const key11, const Arg11 &arg11) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7, key8, arg8, key9, arg9, key10, arg10, key11, arg11);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7, const char * const key8, const Arg8 &arg8, const char * const key9, const Arg9 &arg9, const char * const key10, const Arg10 &arg10, const char * const key11, const Arg11 &arg11, const char * const key12, const Arg12 &arg12) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7, key8, arg8, key9, arg9, key10, arg10, key11, arg11, key12, arg12);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7, const char * const key8, const Arg8 &arg8, const char * const key9, const Arg9 &arg9, const char * const key10, const Arg10 &arg10, const char * const key11, const Arg11 &arg11, const char * const key12, const Arg12 &arg12, const char * const key13, const Arg13 &arg13) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7, key8, arg8, key9, arg9, key10, arg10, key11, arg11, key12, arg12, key13, arg13);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7, const char * const key8, const Arg8 &arg8, const char * const key9, const Arg9 &arg9, const char * const key10, const Arg10 &arg10, const char * const key11, const Arg11 &arg11, const char * const key12, const Arg12 &arg12, const char * const key13, const Arg13 &arg13, const char * const key14, const Arg14 &arg14) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7, key8, arg8, key9, arg9, key10, arg10, key11, arg11, key12, arg12, key13, arg13, key14, arg14);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7, const char * const key8, const Arg8 &arg8, const char * const key9, const Arg9 &arg9, const char * const key10, const Arg10 &arg10, const char * const key11, const Arg11 &arg11, const char * const key12, const Arg12 &arg12, const char * const key13, const Arg13 &arg13, const char * const key14, const Arg14 &arg14, const char * const key15, const Arg15 &arg15) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7, key8, arg8, key9, arg9, key10, arg10, key11, arg11, key12, arg12, key13, arg13, key14, arg14, key15, arg15);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7, const char * const key8, const Arg8 &arg8, const char * const key9, const Arg9 &arg9, const char * const key10, const Arg10 &arg10, const char * const key11, const Arg11 &arg11, const char * const key12, const Arg12 &arg12, const char * const key13, const Arg13 &arg13, const char * const key14, const Arg14 &arg14, const char * const key15, const Arg15 &arg15, const char * const key16, const Arg16 &arg16) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7, key8, arg8, key9, arg9, key10, arg10, key11, arg11, key12, arg12, key13, arg13, key14, arg14, key15, arg15, key16, arg16);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7, const char * const key8, const Arg8 &arg8, const char * const key9, const Arg9 &arg9, const char * const key10, const Arg10 &arg10, const char * const key11, const Arg11 &arg11, const char * const key12, const Arg12 &arg12, const char * const key13, const Arg13 &arg13, const char * const key14, const Arg14 &arg14, const char * const key15, const Arg15 &arg15, const char * const key16, const Arg16 &arg16, const char * const key17, const Arg17 &arg17) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7, key8, arg8, key9, arg9, key10, arg10, key11, arg11, key12, arg12, key13, arg13, key14, arg14, key15, arg15, key16, arg16, key17, arg17);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7, const char * const key8, const Arg8 &arg8, const char * const key9, const Arg9 &arg9, const char * const key10, const Arg10 &arg10, const char * const key11, const Arg11 &arg11, const char * const key12, const Arg12 &arg12, const char * const key13, const Arg13 &arg13, const char * const key14, const Arg14 &arg14, const char * const key15, const Arg15 &arg15, const char * const key16, const Arg16 &arg16, const char * const key17, const Arg17 &arg17, const char * const key18, const Arg18 &arg18) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7, key8, arg8, key9, arg9, key10, arg10, key11, arg11, key12, arg12, key13, arg13, key14, arg14, key15, arg15, key16, arg16, key17, arg17, key18, arg18);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18, typename Arg19>
inline void jsonize(std::ostream &os, const char * const key0, const Arg0 &arg0, const char * const key1, const Arg1 &arg1, const char * const key2, const Arg2 &arg2, const char * const key3, const Arg3 &arg3, const char * const key4, const Arg4 &arg4, const char * const key5, const Arg5 &arg5, const char * const key6, const Arg6 &arg6, const char * const key7, const Arg7 &arg7, const char * const key8, const Arg8 &arg8, const char * const key9, const Arg9 &arg9, const char * const key10, const Arg10 &arg10, const char * const key11, const Arg11 &arg11, const char * const key12, const Arg12 &arg12, const char * const key13, const Arg13 &arg13, const char * const key14, const Arg14 &arg14, const char * const key15, const Arg15 &arg15, const char * const key16, const Arg16 &arg16, const char * const key17, const Arg17 &arg17, const char * const key18, const Arg18 &arg18, const char * const key19, const Arg19 &arg19) {
    jsonize(os, key0, arg0);
    jsonize(os << ", ", key1, arg1, key2, arg2, key3, arg3, key4, arg4, key5, arg5, key6, arg6, key7, arg7, key8, arg8, key9, arg9, key10, arg10, key11, arg11, key12, arg12, key13, arg13, key14, arg14, key15, arg15, key16, arg16, key17, arg17, key18, arg18, key19, arg19);
}
