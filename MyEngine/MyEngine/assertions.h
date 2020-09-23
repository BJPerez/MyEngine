#pragma once

#if ASSERTIONS_ENABLED  

	// Define classic assert (runtime)
	#define debugBreak() __debugbreak()

	#define ASSERT(expr) \
	if (expr) {} \
	else \
	{ \
		std::cout << "Assertion: (" << #expr << ") dans le fichier: " << __FILE__ << "::" << __LINE__ << std::endl; \
		debugBreak(); \
	}  


	// Defining static assert (compile-time)
	#ifdef __cplusplus  
		#if __cplusplus >= 201103L  
			#define STATIC_ASSERT(expr)\
				static_assert(expr, "static assert failed:"\  #expr)  
		#else  
		#define  _ASSERT_GLUE(a, b) a ##b 
		#define ASSERT_GLUE(a, b)  _ASSERT_GLUE(a, b) 


		template<bool> class TStaticAssert;  
		template<> class TStaticAssert<true> {};  
		#define STATIC_ASSERT(expr) \
			enum \
			{ \
				ASSERT_GLUE(g_assert_fail_, __LINE__) = sizeof(TStaticAssert<!!(expr)>) \
			}  
		#endif  

	#endif 

#else  

	#define ASSERT(expr)// evaluates to nothing  

#endif 


