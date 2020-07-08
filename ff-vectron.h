#define mat4 matrix
#define inout output

// ----------------------------------------- scalars -------------------------------------------------
float fract(float x) { return x - floor(x); }
float clamp(float x, float minVal, float maxVal) { return x<minVal ? minVal : x > maxVal ? maxVal : x; }
// ------------------------------------------ vec2 ---------------------------------------------------
struct vec2{ float x, y; };
vec2 __operator__add__(vec2 a, vec2 b) { return vec2(a.x+b.x, a.y+b.y); }
vec2 __operator__sub__(vec2 a, vec2 b) { return vec2(a.x-b.x, a.y-b.y); }
vec2 abs(vec2 a) { return vec2(fabs(a.x), fabs(a.y) ); }
float length(vec2 a) { return sqrt(a.x*a.x + a.y*a.y); }
// ------------------------------------------ vec3 ---------------------------------------------------
struct vec3{ float x, y, z; };

vec3 __operator__add__(vec3 a, vec3 b) { return vec3(a.x+b.x, a.y+b.y, a.z+b.z); }
vec3 __operator__mul__(float val, vec3 v) { return vec3(val*v.x, val*v.y, val*v.z); }
vec3 __operator__div__(vec3 a, float b) { return vec3(a.x/b, a.y/b, a.z/b); }
vec3 __operator__mul__(float val, vec3 v) { return vec3(val*v.x, val*v.y, val*v.z); }
vec3 __operator__mul__(vec3 a, vec3 b) { return vec3(a.x * b.x, a.y * b.y, a.z * b.z); }
vec3 __operator__add__(vec3 a, float b) { return vec3(a.x+b, a.y+b, a.z+b); }
vec3 __operator__sub__(vec3 a, float b) { return vec3(a.x-b, a.y-b, a.z-b); }
vec3 __operator__sub__(vec3 a, vec3 b) { return vec3(a.x-b.x, a.y-b.y, a.z-b.z); }
vec3 __operator__mul__(vec3 a, float b) { return vec3(a.x*b, a.y*b, a.z*b); }
float length(vec3 v) { return length(vector(v.x,v.y,v.z)); }
vec3 normalize(vec3 a) { return a/length(a); }
vec3 toVec3(vector v) { return vec3(v[0], v[1], v[2]); }
float dot(vec3 a, vec3 b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
vec3 cross(vec3 a, vec3 b) { return vec3(a.y*b.z - a.z * b.y, a.x*b.z-a.z*b.x, a.y*b.x - a.x*b.y  ); }
vec3 fract(vec3 a) { return vec3( fract(a.x), fract(a.y), fract(a.z) ); }
vec3 clamp(vec3 x, vec3 minVal, vec3 maxVal) { return vec3( clamp(x.x, minVal.x, maxVal.x), clamp(x.y, minVal.y, maxVal.y), clamp(x.z, minVal.z, maxVal.z) ); }
vec3 abs(vec3 a) { return vec3(fabs(a.x), fabs(a.y), fabs(a.z) ); }
vec3 swap_xy(vec3 a) { return vec3(a.y, a.x, a.z ); }
vec3 swap_xz(vec3 a) { return vec3(a.z, a.y, a.x ); }
vec3 min(vec3 x, float v) { return vec3( min(x.x, v), min(x.y, v), min(x.z, v) ); }
vec3 max(vec3 x, float v) { return vec3( max(x.x, v), max(x.y, v), max(x.z, v) ); }
vec2 xy(vec3 v) { return vec2(v.x, v.y); }
vec3 setXy(vec3 src, vec2 v) { return vec3(v.x, v.y, src.z ); }	
// ------------------------------------------ vec4 ---------------------------------------------------
struct vec4{ float x, y, z, w; };

float length(vec4 a) { return sqrt(a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w); }
float dot(vec4 a, vec4 b) { return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w; }
vec4 __operator__div__(vec4 a, float b) { return vec4(a.x/b, a.y/b, a.z/b, a.w/b); }
vec4 __operator__mul__(vec4 a, float b) { return vec4(a.x*b, a.y*b, a.z*b, a.w*b); }
vec4 __operator__mul__(vec4 a, vec4 b) { return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }
vec4 __operator__add__(vec4 a, vec4 b) { return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
vec4 __operator__sub__(vec4 a, vec4 b) { return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
vec3 __operator__mul__(vec3 a, vec4 b) { return vec3(a.x * b.x, a.y * b.y, a.z * b.z); }

vec3 xyz(vec4 v) { return vec3(v.x, v.y, v.z); }
vec3 xyz(vec4 v) { return vec3(v.x, v.y, v.z); }
vec3 yzw(vec4 v) { return vec3(v.y, v.z, v.w); }

vec2 xy(vec4 v) { return vec2(v.x, v.y); }
vec4 setXy(vec4 src, vec2 v) { return vec4(v.x, v.y, src.z, src.w ); }	
vec4 setXyz(vec4 src, vec3 v) { return vec4(v.x, v.y, v.z, src.w ); }	


vec4 __operator__add__(vec4 a, vec4 b) { return vec4(a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w); }
vec4 __operator__mul__(float val, vec4 v) { return vec4(val*v.x, val*v.y, val*v.z, val*v.w); }
vec3 clamp(vec3 x, vec4 minVal, vec4 maxVal) { return vec3( clamp(x.x, minVal.x, maxVal.x), clamp(x.y, minVal.y, maxVal.y), clamp(x.z, minVal.z, maxVal.z) ); }
vec4 abs(vec4 a) { return vec4(fabs(a.x), fabs(a.y), fabs(a.z), fabs(a.w) ); }
vec4 min(vec4 x, float v) { return vec4( min(x.x, v), min(x.y, v), min(x.z, v), min(x.w, v) ); }
vec4 max(vec4 x, float v) { return vec4( max(x.x, v), max(x.y, v), max(x.z, v), max(x.w, v) ); }
vec4 min(vec4 x, vec4 y) { return vec4( min(x.x, y.x), min(x.y, y.y), min(x.z, y.z), min(x.w, y.w) ); }


vec4 toVec4(vec3 v3, float s) { return vec4(v3.x, v3.y, v3.z, s); }	
vec4 toVec4(float s, vec3 v3) { return vec4(s, v3.x, v3.y, v3.z); }	
vec4 toVec4(float s) { return vec4(s, s, s, s); }	
// ------------------------------------------ mat3 ---------------------------------------------------
struct mat3{ float m00, m01, m02, m10, m11, m12, m20, m21, m22; };
mat3 __operator__mul__(float val, mat3 m) { return mat3(val*m.m00, m.m01, m.m02, m.m10, val*m.m11, m.m12, m.m20, m.m21, val * m.m22); }
mat3  rotationMatrix3(vec3 v, float angle){ float c = cos(radians(angle)), s = sin(radians(angle)); return mat3(c+(1.0-c)*v.x*v.x, (1.0-c)*v.x*v.y-s*v.z, (1.0-c)*v.x*v.z+s*v.y,  (1.0-c)*v.x*v.y+s*v.z, c+(1.0-c)*v.y*v.y, (1.0-c)*v.y*v.z-s*v.x,  (1.0-c)*v.x*v.z-s*v.y, (1.0-c)*v.y*v.z+s*v.x, c+(1.0-c)*v.z*v.z); }
mat3 __operator__mul__(mat3 A, mat3 B) { return mat3(A.m00*B.m00+A.m01*B.m10+A.m02*B.m20, A.m00*B.m01+A.m01*B.m11+A.m02*B.m21, A.m00*B.m02+A.m01*B.m12+A.m02*B.m22, A.m10*B.m00+A.m11*B.m10+A.m12*B.m20, A.m10*B.m01+A.m11*B.m11+A.m12*B.m21, A.m10*B.m02+A.m11*B.m12+A.m12*B.m22, A.m20*B.m00+A.m21*B.m10+A.m22*B.m20, A.m20*B.m01+A.m21*B.m11+A.m22*B.m21, A.m20*B.m02+A.m21*B.m12+A.m22*B.m22); }
vec3 __operator__mul__(vec3 v, mat3 m) { return vec3(v.x*m.m00+v.y*m.m01+v.z*m.m02, v.x*m.m10+v.y*m.m11+v.z*m.m12, v.x*m.m20+v.y*m.m21+v.z*m.m22); }
// ------------------------------------------ misc ---------------------------------------------------
float opS( float d1, float d2 ){ return max(-d2,d1); }
vector opU( vector d1, vector d2 ){ return (d1[0]<d2[0]) ? d1 : d2; }
vector opRep( vector p, vector c ){ return mod(p,c)-0.5*c; }
// --------------------------------------- coloring --------------------------------------------------
#define UV_MODE_SQRT 0
#define UV_MODE_LOG 1
#define UV_MODE_CONST 2
#define UV_MODE_NONE 3

#define ADD_COLOR_PARAMS int ColorIterations = 16, int UMode = UV_MODE_SQRT, float UScale = 2, int VMode = UV_MODE_SQRT, float VScale = 2
#define INIT_ORBIT_TRAP float orbitTrap = 10000.0
#define APPLY_ORBIT_TRAP         if(UMode==UV_MODE_SQRT)  \
          c.u = sqrt(orbitTrap) * UScale; \
        else if(UMode==UV_MODE_LOG)  \
          c.u = log(orbitTrap) * UScale; \
        else if(UMode==UV_MODE_CONST) \
          c.u = UScale; \
        if(VMode==UV_MODE_SQRT)  \
          c.v = sqrt(orbitTrap) * VScale; \
        else if(VMode==UV_MODE_LOG)  \
          c.v = log(orbitTrap) * VScale;\
        else if(VMode==UV_MODE_CONST)\
          c.v = VScale
