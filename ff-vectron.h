#define mat4 matrix
#define inout output
vector vec2(float a, float b) { return vector(a,b,0); }
struct vec3{ float x, y, z; };
struct vec4{ float x, y, z, w; };
struct mat3{ float m00, m01, m02, m10, m11, m12, m20, m21, m22; };
vector xyz(vec4 v) { return vector(v.x, v.y, v.z); }
vector xyz(vec4 v) { return vector(v.x, v.y, v.z); }
vector yzw(vec4 v) { return vector(v.y, v.z, v.w); }

mat3 __operator__mul__(mat3 A, mat3 B) { return mat3(A.m00*B.m00+A.m01*B.m10+A.m02*B.m20, A.m00*B.m01+A.m01*B.m11+A.m02*B.m21, A.m00*B.m02+A.m01*B.m12+A.m02*B.m22, A.m10*B.m00+A.m11*B.m10+A.m12*B.m20, A.m10*B.m01+A.m11*B.m11+A.m12*B.m21, A.m10*B.m02+A.m11*B.m12+A.m12*B.m22, A.m20*B.m00+A.m21*B.m10+A.m22*B.m20, A.m20*B.m01+A.m21*B.m11+A.m22*B.m21, A.m20*B.m02+A.m21*B.m12+A.m22*B.m22); }
vec3 __operator__add__(vec3 a, vec3 b) { return vec3(a.x+b.x, a.y+b.y, a.z+b.z); }
vec3 __operator__mul__(float val, vec3 v) { return vec3(val*v.x, val*v.y, val*v.z); }
vec3 __operator__div__(vec3 a, float b) { return vec3(a.x/b, a.y/b, a.z/b); }
vec3 __operator__mul__(vec3 v, mat3 m) { return vec3(v.x*m.m00+v.y*m.m01+v.z*m.m02, v.x*m.m10+v.y*m.m11+v.z*m.m12, v.x*m.m20+v.y*m.m21+v.z*m.m22); }
vec4 __operator__add__(vec4 a, vec4 b) { return vec4(a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w); }
vec4 __operator__mul__(float val, vec4 v) { return vec4(val*v.x, val*v.y, val*v.z, val*v.w); }
vec3 __operator__mul__(float val, vec3 v) { return vec3(val*v.x, val*v.y, val*v.z); }
mat3 __operator__mul__(float val, mat3 m) { return mat3(val*m.m00, m.m01, m.m02, m.m10, val*m.m11, m.m12, m.m20, m.m21, val * m.m22); }
vec3 __operator__add__(vec3 a, float b) { return vec3(a.x+b, a.y+b, a.z+b); }
vec3 __operator__sub__(vec3 a, float b) { return vec3(a.x-b, a.y-b, a.z-b); }

mat3  rotationMatrix3(vec3 v, float angle){ float c = cos(radians(angle)), s = sin(radians(angle)); return mat3(c+(1.0-c)*v.x*v.x, (1.0-c)*v.x*v.y-s*v.z, (1.0-c)*v.x*v.z+s*v.y,  (1.0-c)*v.x*v.y+s*v.z, c+(1.0-c)*v.y*v.y, (1.0-c)*v.y*v.z-s*v.x,  (1.0-c)*v.x*v.z-s*v.y, (1.0-c)*v.y*v.z+s*v.x, c+(1.0-c)*v.z*v.z); }

vec3 toVec3(vector v) { return vec3(v[0], v[1], v[2]); }

float length(vec3 v) { return length(vector(v.x,v.y,v.z)); }
float length(vec4 a) { return sqrt(a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w); }

float dot(vec3 a, vec3 b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
float dot(vec4 a, vec4 b) { return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w; }
float opS( float d1, float d2 ){ return max(-d2,d1); }
vector opU( vector d1, vector d2 ){ return (d1[0]<d2[0]) ? d1 : d2; }
vector opRep( vector p, vector c ){ return mod(p,c)-0.5*c; }
vec3 __operator__sub__(vec3 a, vec3 b) { return vec3(a.x-b.x, a.y-b.y, a.z-b.z); }
vec3 __operator__mul__(vec3 a, float b) { return vec3(a.x*b, a.y*b, a.z*b); }

vec3 normalize(vec3 a) { return a/length(a); }
float fract(float x) {
	return x - floor(x); 
}
vec3 fract(vec3 a) { return vec3( fract(a.x), fract(a.y), fract(a.z) ); }

float clamp(float x, float minVal, float maxVal) {
	return x<minVal ? minVal : x > maxVal ? maxVal : x;
}

vec3 clamp(vec3 x, vec3 minVal, vec3 maxVal) { return vec3( clamp(x.x, minVal.x, maxVal.x), clamp(x.y, minVal.y, maxVal.y), clamp(x.z, minVal.z, maxVal.z) ); }
vec3 clamp(vec3 x, vec4 minVal, vec4 maxVal) { return vec3( clamp(x.x, minVal.x, maxVal.x), clamp(x.y, minVal.y, maxVal.y), clamp(x.z, minVal.z, maxVal.z) ); }


vec3 abs(vec3 a) { return vec3(fabs(a.x), fabs(a.y), fabs(a.z) ); }
vec3 swap_xy(vec3 a) { 
  return vec3(a.y, a.x, a.z );
}

vec3 swap_xz(vec3 a) { 
  return vec3(a.z, a.y, a.x );
}
