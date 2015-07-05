#extension GL_ARB_separate_shader_objects : enable

#ifdef GL_ARB_separate_shader_objects
#define DECLUNIFORM(type, name) uniform type _##name##_uniform;
#define U(name) _##name##_uniform
#else
#ifdef __VERTEX__
#define DECLUNIFORM(type, name) uniform type _##name##_vertex;
#define U(name) _##name##_vertex
#elif defined(__TESS_CONTROL__)
#define DECLUNIFORM(type, name) uniform type _##name##_tessControl;
#define U(name) _##name##_tessControl
#elif defined(__TESS_EVAL__)
#define DECLUNIFORM(type, name) uniform type _##name##_tessEval;
#define U(name) _##name##_tessEval
#elif defined(__GEOMETRY__)
#define DECLUNIFORM(type, name) uniform type _##name##_geometry;
#define U(name) _##name##_geometry
#elif defined(__FRAGMENT__)
#define DECLUNIFORM(type, name) uniform type _##name##_fragment;
#define U(name) _##name##_fragment
#elif defined(__COMPUTE__)
#define DECLUNIFORM(type, name) uniform type _##name##_compute;
#define U(name) _##name##_compute
#endif
#endif
