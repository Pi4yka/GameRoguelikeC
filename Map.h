#pragma once
#include "SFML\Graphics.hpp"
const int HEIGHT_MAP = 40;//размер карты высота
const int WIDTH_MAP = 60;//размер карты ширина 
						 /*
						 1 - стенка

						 4.5.6.7 - сломанный камень
						 b,c -  стенки
						 3-верхняя часть стены
						 2-нижняя часть стены

						 пол - " ",a
						 камушки - q,w
						 g,z - chest
						 s,t - стойки
						 k,e - кувшин
						 n,p - corobka

						 j,i - table break
						 h,v - table
						 */

sf::String TileMap[HEIGHT_MAP] = {
	"30000000000000000000000000003000000000000000000000000000003",
	"1a      a          1        1                      a      1",
	"1   a          a   1    a   1      a  a                   1",
	"1  30000000        1        1                             1",
	"1  1               1    a   1   a                  a      1",
	"1  1               2        2   a                         1",
	"1  2bqw3                                       a          1",
	"1      2bcb3               a              a        a      1",
	"1 a        1       qbc3     3                             1",
	"1          1          1     1           a                 1",
	"1 a        1          1     1    aaa          a           1",
	"1 a    a   1 a   a    1     1      a a a           a      1",
	"1bcbcb  cbc2bcbcbcbcbcb     2bcbcbcbcbcbcbcbcbcbcbcbcbcbcb1",
	"146 a  a   a    a                                         1",
	"157                                       a        a      1",
	"146    a  a  a                   a                        1",
	"1bcbcbcbcbcb3bcbc  bcbcbc3                         a      1",
	"1   a       1gzzq  qgg z 1                                1",
	"1ji    a  hv1   qwqw     1    a                 a         1",
	"1e  a       1kk          1          a           bcbcbcbcbc1",
	"1ji       hv1         n  1                                1",
	"1   a      e1n   pn    kk1    a                           1",
	"1hv       ji1n         kk1                         a      1",
	"1           q ststst   kk1         bcbcbcbcbc             1",
	"1a          wbcbcbcbcbcbc2                                1",
	"1e                            a                      a  a 1",
	"1st    a                                                  1",
	"1a          w                            cbcbcbcbcbcbcbcbc1",
	"1bcbcbcbcbcbcb3bcbcbc3bcbcbcbcbcb3                        1",
	"146a       a  1a     1 a         1        a         a     1",
	"157a          1      1           1   a                 a  1",
	"146a          1 a    1  a        1                        1",
	"157a     a    1      1           1       a                1",
	"1aa           1      1        a  1                        1",
	"1             2cb  cb2cbbc     bc2              a         1",
	"1                                                         1",
	"1    a                  a                            a    1",
	"1                 a                         a             1",
	"1              a                                     a    1",
	"20000000000000000000000000000000000000000000000000000000002"
};