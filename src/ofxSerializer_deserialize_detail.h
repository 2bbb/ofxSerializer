/*
 for(var i = 2; i <= 20; i++) {
 var args = [];
 for(var j = 0; j < i; j++) args.push(j);
 var str = "template <" + args.map(function(n) { return "typename Arg" + n; }).join(", ") + ">\n"
 + "inline void deserialize(std::istream &is, " + args.map(function(n) { return "Arg" + n + " &arg" + n; }).join(", ") + ") {\n"
 + "    deserialize(is, arg0);\n"
 + (i == 1 ? "" : "    deserialize(is, " + args.slice(1).map(function(n) { return "arg" + n; }).join(", ") + ");\n")
 + "}";
 console.log(str);
 }
 */
template <typename Arg0, typename Arg1>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1) {
    deserialize(is, arg0);
    deserialize(is, arg1);
}
template <typename Arg0, typename Arg1, typename Arg2>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7, Arg8 &arg8) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7, Arg8 &arg8, Arg9 &arg9) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7, Arg8 &arg8, Arg9 &arg9, Arg10 &arg10) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7, Arg8 &arg8, Arg9 &arg9, Arg10 &arg10, Arg11 &arg11) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7, Arg8 &arg8, Arg9 &arg9, Arg10 &arg10, Arg11 &arg11, Arg12 &arg12) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7, Arg8 &arg8, Arg9 &arg9, Arg10 &arg10, Arg11 &arg11, Arg12 &arg12, Arg13 &arg13) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7, Arg8 &arg8, Arg9 &arg9, Arg10 &arg10, Arg11 &arg11, Arg12 &arg12, Arg13 &arg13, Arg14 &arg14) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7, Arg8 &arg8, Arg9 &arg9, Arg10 &arg10, Arg11 &arg11, Arg12 &arg12, Arg13 &arg13, Arg14 &arg14, Arg15 &arg15) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7, Arg8 &arg8, Arg9 &arg9, Arg10 &arg10, Arg11 &arg11, Arg12 &arg12, Arg13 &arg13, Arg14 &arg14, Arg15 &arg15, Arg16 &arg16) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7, Arg8 &arg8, Arg9 &arg9, Arg10 &arg10, Arg11 &arg11, Arg12 &arg12, Arg13 &arg13, Arg14 &arg14, Arg15 &arg15, Arg16 &arg16, Arg17 &arg17) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7, Arg8 &arg8, Arg9 &arg9, Arg10 &arg10, Arg11 &arg11, Arg12 &arg12, Arg13 &arg13, Arg14 &arg14, Arg15 &arg15, Arg16 &arg16, Arg17 &arg17, Arg18 &arg18) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18);
}
template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7, typename Arg8, typename Arg9, typename Arg10, typename Arg11, typename Arg12, typename Arg13, typename Arg14, typename Arg15, typename Arg16, typename Arg17, typename Arg18, typename Arg19>
inline void deserialize(std::istream &is, Arg0 &arg0, Arg1 &arg1, Arg2 &arg2, Arg3 &arg3, Arg4 &arg4, Arg5 &arg5, Arg6 &arg6, Arg7 &arg7, Arg8 &arg8, Arg9 &arg9, Arg10 &arg10, Arg11 &arg11, Arg12 &arg12, Arg13 &arg13, Arg14 &arg14, Arg15 &arg15, Arg16 &arg16, Arg17 &arg17, Arg18 &arg18, Arg19 &arg19) {
    deserialize(is, arg0);
    deserialize(is, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19);
}
