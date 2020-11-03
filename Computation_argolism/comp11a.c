/* 一様擬似乱数の生成の練習 */
#include <stdio.h>
#include <stdlib.h>  /* 関数srand、randと定数RAND_MAXが定義されているヘッダファイル */
 
#define A  48271   /* 線形合同法のパラメータ：掛ける数 */
#define C  0       /* 線形合同法のパラメータ：足す数 */
#define M  2147483647   /* 線形合同法のパラメータ：割る数 (2の31乗-1) */

#define N  5 /* 乱数を生成する個数 */
 
/* グローバル変数 (どの関数の中でも使用可能) */
unsigned int X;    /* 線形合同法で生成される非負の整数値一様擬似乱数列 */

/*====================================================*/
/* 線形合同法による整数値一様擬似乱数の生成関数(自作) */
/*====================================================*/
unsigned int myrand( void )
{
  X = ( A * X + C ) % M;

  return X;
}

/*====================================================*/
/* 整数値一様擬似乱数の初期値を設定する関数(自作)     */
/*====================================================*/
void mysrand( unsigned int x0 )
{
  X = x0;
}

/* main関数 */
int main( void )
{
  int i, m;
  double x;

  /* =========  自作関数で乱数列を生成する場合 =========  */
  printf( "(1)自作関数myrandによる整数値一様乱数\n" );
  printf( "A = %d\n", A );
  printf( "C = %d\n", C );
  printf( "M = %d\n", M );
  printf( "整数値一様乱数の最大値(M-1) = %d\n", M-1 );

  mysrand( 1 ); /* 自作関数mysrandで整数値乱数の初期値(初項)を設定 */

  for( i = 1; i <= N; i++ ) {  /* for文で擬似乱数をN個生成する */
    m = myrand( );       /* 自作関数myrandで整数値一様乱数を生成しmに代入 */
    printf( "%-2d m = %d\n", i, m );
  }

  /* =========  標準ライブラリ関数で乱数列を生成する場合 =========  */
  printf( "\n(2)標準ライブラリ関数randによる整数値一様乱数\n" );
  printf( "整数値一様乱数の最大値(RAND_MAX) = %d\n", RAND_MAX );
 
  srand( 1 ); /* 標準ライブラリ関数srandで整数値乱数の初期値(初項)を設定 */

  for( i = 1; i <= N; i++ ) {  /* for文で擬似乱数をN個生成する */
    m = rand( ); /* 標準ライブラリ関数randで整数値一様乱数を生成しmに代入 */
    printf( "%-2d m = %d\n", i, m );
  }

  printf( "\n(3)標準ライブラリ関数randによる[0,1]の実数値一様乱数\n" );

  for( i = 1; i <= N; i++ ) {  /* for文で擬似乱数をN個生成する */
    x = (double) rand( ) / RAND_MAX; /* 標準ライブラリ関数randで整数値一様乱数を生成し[0,1]に変換後xに代入 */
    printf( "%-2d x = %f\n", i, x );
  }

  return 0;
}

