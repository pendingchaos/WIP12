#define DECLUNIFORM(type, name) uniform type _##name##_uniform;
#define U(name) _##name##_uniform

#define DECLUNIFORMARRAY(type, count, name) uniform type _##name##_uniform[count];
#define U(name) _##name##_uniform
