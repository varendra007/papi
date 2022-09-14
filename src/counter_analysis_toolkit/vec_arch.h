#include <inttypes.h>

typedef unsigned long long uint64;

#if defined(INTEL) || defined(AMD)
void test_hp_128B_VEC( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );
void test_sp_128B_VEC( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );
void test_dp_128B_VEC( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );

void test_hp_256B_VEC( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );
void test_sp_256B_VEC( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );
void test_dp_256B_VEC( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );

void test_hp_512B_VEC( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );
void test_sp_512B_VEC( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );
void test_dp_512B_VEC( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );

void test_hp_128B_VEC_FMA( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );
void test_sp_128B_VEC_FMA( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );
void test_dp_128B_VEC_FMA( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );

void test_hp_256B_VEC_FMA( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );
void test_sp_256B_VEC_FMA( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );
void test_dp_256B_VEC_FMA( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );

void test_hp_512B_VEC_FMA( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );
void test_sp_512B_VEC_FMA( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );
void test_dp_512B_VEC_FMA( int instr_per_loop, uint64 iterations, int EventSet, FILE *fp );

#include <immintrin.h>

typedef __m128  SP_SCALAR_TYPE;
typedef __m128d DP_SCALAR_TYPE;

#define SET_VEC_SS(_I_)         _mm_set_ss( _I_ );
#define ADD_VEC_SS(_I_,_J_)     _mm_add_ss( _I_ , _J_ );
#define MUL_VEC_SS(_I_,_J_)     _mm_mul_ss( _I_ , _J_ );
#define FMA_VEC_SS(_I_,_J_,_K_) _mm_fmadd_ss( _I_ , _J_ , _K_ );

#define SET_VEC_SD(_I_)         _mm_set_sd( _I_ );
#define ADD_VEC_SD(_I_,_J_)     _mm_add_sd( _I_ , _J_ );
#define MUL_VEC_SD(_I_,_J_)     _mm_mul_sd( _I_ , _J_ );
#define FMA_VEC_SD(_I_,_J_,_K_) _mm_fmadd_sd( _I_ , _J_ , _K_ );

#if defined(VEC_WIDTH_128)
typedef __m128  SP_VEC_TYPE;
typedef __m128d DP_VEC_TYPE;

#define SET_VEC_PS(_I_)         _mm_set1_ps( _I_ );
#define ADD_VEC_PS(_I_,_J_)     _mm_add_ps( _I_ , _J_ );
#define MUL_VEC_PS(_I_,_J_)     _mm_mul_ps( _I_ , _J_ );
#define FMA_VEC_PS(_I_,_J_,_K_) _mm_fmadd_ps( _I_ , _J_ , _K_ );

#define SET_VEC_PD(_I_)         _mm_set1_pd( _I_ );
#define ADD_VEC_PD(_I_,_J_)     _mm_add_pd( _I_ , _J_ );
#define MUL_VEC_PD(_I_,_J_)     _mm_mul_pd( _I_ , _J_ );
#define FMA_VEC_PD(_I_,_J_,_K_) _mm_fmadd_pd( _I_ , _J_ , _K_ );

#elif defined(VEC_WIDTH_512)
typedef __m512  SP_VEC_TYPE;
typedef __m512d DP_VEC_TYPE;

#define SET_VEC_PS(_I_)         _mm512_set1_ps( _I_ );
#define ADD_VEC_PS(_I_,_J_)     _mm512_add_ps( _I_ , _J_ );
#define MUL_VEC_PS(_I_,_J_)     _mm512_mul_ps( _I_ , _J_ );
#define FMA_VEC_PS(_I_,_J_,_K_) _mm512_fmadd_ps( _I_ , _J_ , _K_ );

#define SET_VEC_PD(_I_)         _mm512_set1_pd( _I_ );
#define ADD_VEC_PD(_I_,_J_)     _mm512_add_pd( _I_ , _J_ );
#define MUL_VEC_PD(_I_,_J_)     _mm512_mul_pd( _I_ , _J_ );
#define FMA_VEC_PD(_I_,_J_,_K_) _mm512_fmadd_pd( _I_ , _J_ , _K_ );

#else
typedef __m256  SP_VEC_TYPE;
typedef __m256d DP_VEC_TYPE;

#define SET_VEC_PS(_I_)         _mm256_set1_ps( _I_ );
#define ADD_VEC_PS(_I_,_J_)     _mm256_add_ps( _I_ , _J_ );
#define MUL_VEC_PS(_I_,_J_)     _mm256_mul_ps( _I_ , _J_ );
#define FMA_VEC_PS(_I_,_J_,_K_) _mm256_fmadd_ps( _I_ , _J_ , _K_ );

#define SET_VEC_PD(_I_)         _mm256_set1_pd( _I_ );
#define ADD_VEC_PD(_I_,_J_)     _mm256_add_pd( _I_ , _J_ );
#define MUL_VEC_PD(_I_,_J_)     _mm256_mul_pd( _I_ , _J_ );
#define FMA_VEC_PD(_I_,_J_,_K_) _mm256_fmadd_pd( _I_ , _J_ , _K_ );
#endif

#elif defined(ARM)

#include <arm_neon.h>

typedef __fp16 HP_SCALAR_TYPE;
typedef float  SP_SCALAR_TYPE;
typedef double DP_SCALAR_TYPE;

#define SET_VEC_SH(_I_)         _I_ ;
#define ADD_VEC_SH(_I_,_J_)     vaddh_f16( _I_ , _J_ );
#define MUL_VEC_SH(_I_,_J_)     vmulh_f16( _I_ , _J_ );
#define FMA_VEC_SH(_I_,_J_,_K_) vaddh_f16( vmulh_f16( _I_ , _J_) , _K_ );

#define SET_VEC_SS(_I_)         _I_ ;
#define ADD_VEC_SS(_I_,_J_)     _I_ + _J_ ;
#define MUL_VEC_SS(_I_,_J_)     _I_ * _J_ ;
#define FMA_VEC_SS(_I_,_J_,_K_) _I_ * _J_ + _K_ ;

#define SET_VEC_SD(_I_)         _I_ ;
#define ADD_VEC_SD(_I_,_J_)     _I_ + _J_ ;
#define MUL_VEC_SD(_I_,_J_)     _I_ * _J_ ;
#define FMA_VEC_SD(_I_,_J_,_K_) _I_ * _J_ + _K_ ;

typedef float16x8_t HP_VEC_TYPE;
typedef float32x4_t SP_VEC_TYPE;
typedef float64x2_t DP_VEC_TYPE;

#define SET_VEC_PH(_I_) (float16x8_t)vdupq_n_f16( _I_ );
#define SET_VEC_PS(_I_) (float32x4_t)vdupq_n_f32( _I_ );
#define SET_VEC_PD(_I_) (float64x2_t)vdupq_n_f64( _I_ );

#define ADD_VEC_PH(_I_,_J_) (float16x8_t)vaddq_f16( _I_ , _J_ );
#define ADD_VEC_PS(_I_,_J_) (float32x4_t)vaddq_f32( _I_ , _J_ );
#define ADD_VEC_PD(_I_,_J_) (float64x2_t)vaddq_f64( _I_ , _J_ );

#define MUL_VEC_PH(_I_,_J_) (float16x8_t)vmulq_f16( _I_ , _J_ );
#define MUL_VEC_PS(_I_,_J_) (float32x4_t)vmulq_f32( _I_ , _J_ );
#define MUL_VEC_PD(_I_,_J_) (float64x2_t)vmulq_f64( _I_ , _J_ );

#define FMA_VEC_PH(_I_,_J_,_K_) (float16x8_t)vfmaq_f16( _K_ , _J_ , _I_ );
#define FMA_VEC_PS(_I_,_J_,_K_) (float32x4_t)vfmaq_f32( _K_ , _J_ , _I_ );
#define FMA_VEC_PD(_I_,_J_,_K_) (float64x2_t)vfmaq_f64( _K_ , _J_ , _I_ );

#elif defined(IBM)

#include <altivec.h>

typedef float  SP_SCALAR_TYPE;
typedef double DP_SCALAR_TYPE;

#define SET_VEC_SS(_I_)         _I_ ;
#define ADD_VEC_SS(_I_,_J_)     _I_ + _J_ ;
#define MUL_VEC_SS(_I_,_J_)     _I_ * _J_ ;
#define FMA_VEC_SS(_I_,_J_,_K_) _I_ * _J_ + _K_ ;

#define SET_VEC_SD(_I_)         _I_ ;
#define ADD_VEC_SD(_I_,_J_)     _I_ + _J_ ;
#define MUL_VEC_SD(_I_,_J_)     _I_ * _J_ ;
#define FMA_VEC_SD(_I_,_J_,_K_) _I_ * _J_ + _K_ ;

typedef __vector float  SP_VEC_TYPE;
typedef __vector double DP_VEC_TYPE;

#define SET_VEC_PS(_I_) (__vector float){ _I_ , _I_ , _I_ , _I_ };
#define SET_VEC_PD(_I_) (__vector double){ _I_ , _I_ };

#define ADD_VEC_PS(_I_,_J_) (__vector float)vec_add( _I_ , _J_ );
#define ADD_VEC_PD(_I_,_J_) (__vector double)vec_add( _I_ , _J_ );

#define MUL_VEC_PS(_I_,_J_) (__vector float)vec_mul( _I_ , _J_ );
#define MUL_VEC_PD(_I_,_J_) (__vector double)vec_mul( _I_ , _J_ );

#define FMA_VEC_PS(_I_,_J_,_K_) (__vector float)vec_madd( _I_ , _J_ , _K_ );
#define FMA_VEC_PD(_I_,_J_,_K_) (__vector double)vec_madd( _I_ , _J_ , _K_ );

#endif
