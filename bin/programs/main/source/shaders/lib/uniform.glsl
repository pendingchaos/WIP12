#ifdef GL_ARB_separate_shader_objects
#define DECLUNIFORM(type, name) uniform type _##name##_uniform;
#define U(name) _##name##_uniform
#else
#ifdef VERTEX
#define DECLUNIFORM(type, name) uniform type _##name##_vertex;
#define U(name) _##name##_vertex
#elif defined(TESS_CONTROL)
#define DECLUNIFORM(type, name) uniform type _##name##_tessControl;
#define U(name) _##name##_tessControl
#elif defined(TESS_EVAL)
#define DECLUNIFORM(type, name) uniform type _##name##_tessEval;
#define U(name) _##name##_tessEval
#elif defined(GEOMETRY)
#define DECLUNIFORM(type, name) uniform type _##name##_geometry;
#define U(name) _##name##_geometry
#elif defined(FRAGMENT)
#define DECLUNIFORM(type, name) uniform type _##name##_fragment;
#define U(name) _##name##_fragment
#elif defined(COMPUTE)
#define DECLUNIFORM(type, name) uniform type _##name##_compute;
#define U(name) _##name##_compute
#endif
#endif
