// Reference: http://qiita.com/saltheads/items/e1b0ab54d3d6029c9593
/*
console.log("#define S(n) #n, n");
for(var n = 1, args_ = []; n <= 20; n++) {
	args_.push(n);
	var args = [];
	for(var i = 0; i < n; i++) args.push(i);
	var str = "#define str_impl" + n + "(" + args.map(function(x) { return "n" + x; }).join(", ") + ") " + (args.map(function(x) { return "S(n" + x + ")"; }).join(", "));
	console.log(str);
}
 
var str = "#define Select(" + args_.map(function(x) { return "_" + x; }).join(", ") + ", name, ...) name";
console.log(str);

str = "#define MakeStringifiedPair(...) Select(__VA_ARGS__, " + args_.reverse().map(function(n) { return "str_impl" + n; }).join(", ") + ") (__VA_ARGS__)";
console.log(str);
*/

#define S(n) #n, n
#define str_impl1(n0) S(n0)
#define str_impl2(n0, n1) S(n0), S(n1)
#define str_impl3(n0, n1, n2) S(n0), S(n1), S(n2)
#define str_impl4(n0, n1, n2, n3) S(n0), S(n1), S(n2), S(n3)
#define str_impl5(n0, n1, n2, n3, n4) S(n0), S(n1), S(n2), S(n3), S(n4)
#define str_impl6(n0, n1, n2, n3, n4, n5) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5)
#define str_impl7(n0, n1, n2, n3, n4, n5, n6) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6)
#define str_impl8(n0, n1, n2, n3, n4, n5, n6, n7) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7)
#define str_impl9(n0, n1, n2, n3, n4, n5, n6, n7, n8) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7), S(n8)
#define str_impl10(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7), S(n8), S(n9)
#define str_impl11(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7), S(n8), S(n9), S(n10)
#define str_impl12(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7), S(n8), S(n9), S(n10), S(n11)
#define str_impl13(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7), S(n8), S(n9), S(n10), S(n11), S(n12)
#define str_impl14(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7), S(n8), S(n9), S(n10), S(n11), S(n12), S(n13)
#define str_impl15(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7), S(n8), S(n9), S(n10), S(n11), S(n12), S(n13), S(n14)
#define str_impl16(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7), S(n8), S(n9), S(n10), S(n11), S(n12), S(n13), S(n14), S(n15)
#define str_impl17(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7), S(n8), S(n9), S(n10), S(n11), S(n12), S(n13), S(n14), S(n15), S(n16)
#define str_impl18(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7), S(n8), S(n9), S(n10), S(n11), S(n12), S(n13), S(n14), S(n15), S(n16), S(n17)
#define str_impl19(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17, n18) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7), S(n8), S(n9), S(n10), S(n11), S(n12), S(n13), S(n14), S(n15), S(n16), S(n17), S(n18)
#define str_impl20(n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17, n18, n19) S(n0), S(n1), S(n2), S(n3), S(n4), S(n5), S(n6), S(n7), S(n8), S(n9), S(n10), S(n11), S(n12), S(n13), S(n14), S(n15), S(n16), S(n17), S(n18), S(n19)
#define Select(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, name, ...) name
#define MakeStringifiedPair(...) Select(__VA_ARGS__, str_impl20, str_impl19, str_impl18, str_impl17, str_impl16, str_impl15, str_impl14, str_impl13, str_impl12, str_impl11, str_impl10, str_impl9, str_impl8, str_impl7, str_impl6, str_impl5, str_impl4, str_impl3, str_impl2, str_impl1) (__VA_ARGS__)
