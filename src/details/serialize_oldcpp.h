/*
 for(var i = 2; i <= 20; i++) {
 var args = [];
 for(var j = 0; j < i; j++) args.push(j);
 var str = "template <" + args.map(function(n) { return "typename Arg" + n; }).join(", ") + ">\n"
 + "inline void serialize(std::ostream &os, " + args.map(function(n) { return "const Arg" + n + " &arg" + n; }).join(", ") + ") {\n"
 + "    serialize(os, arg0);\n"
 + (i == 1 ? "" : "    serialize(os, " + args.slice(1).map(function(n) { return "arg" + n; }).join(", ") + ");\n")
 + "}";
 console.log(str);
 }
 */
template <typename Arg0, typename Arg1>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1) {
    serialize(os, arg0);
    serialize(os, arg1);
}
template <typename Arg0, typename Arg1, typename Arg2>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2) {
    serialize(os, arg0);
    serialize(os, arg1, arg2);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7, const Arg8 &arg8) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7, const Arg8 &arg8, const Arg9 &arg9) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7, const Arg8 &arg8, const Arg9 &arg9, const Arg10 &arg10) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7, const Arg8 &arg8, const Arg9 &arg9, const Arg10 &arg10, const Arg11 &arg11) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7, const Arg8 &arg8, const Arg9 &arg9, const Arg10 &arg10, const Arg11 &arg11, const Arg12 &arg12) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7, const Arg8 &arg8, const Arg9 &arg9, const Arg10 &arg10, const Arg11 &arg11, const Arg12 &arg12, const Arg13 &arg13) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7, const Arg8 &arg8, const Arg9 &arg9, const Arg10 &arg10, const Arg11 &arg11, const Arg12 &arg12, const Arg13 &arg13, const Arg14 &arg14) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7, const Arg8 &arg8, const Arg9 &arg9, const Arg10 &arg10, const Arg11 &arg11, const Arg12 &arg12, const Arg13 &arg13, const Arg14 &arg14, const Arg15 &arg15) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7, const Arg8 &arg8, const Arg9 &arg9, const Arg10 &arg10, const Arg11 &arg11, const Arg12 &arg12, const Arg13 &arg13, const Arg14 &arg14, const Arg15 &arg15, const Arg16 &arg16) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7, const Arg8 &arg8, const Arg9 &arg9, const Arg10 &arg10, const Arg11 &arg11, const Arg12 &arg12, const Arg13 &arg13, const Arg14 &arg14, const Arg15 &arg15, const Arg16 &arg16, const Arg17 &arg17) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7, const Arg8 &arg8, const Arg9 &arg9, const Arg10 &arg10, const Arg11 &arg11, const Arg12 &arg12, const Arg13 &arg13, const Arg14 &arg14, const Arg15 &arg15, const Arg16 &arg16, const Arg17 &arg17, const Arg18 &arg18) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18, typename Arg19>
inline void serialize(std::ostream &os, const Arg0 &arg0, const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5, const Arg6 &arg6, const Arg7 &arg7, const Arg8 &arg8, const Arg9 &arg9, const Arg10 &arg10, const Arg11 &arg11, const Arg12 &arg12, const Arg13 &arg13, const Arg14 &arg14, const Arg15 &arg15, const Arg16 &arg16, const Arg17 &arg17, const Arg18 &arg18, const Arg19 &arg19) {
    serialize(os, arg0);
    serialize(os, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19);
}
