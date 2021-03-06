/**
    AW: Avoided Words
    Copyright (C) 2016 Jia Gao and Solon P. Pissis.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

#include <sdsl/cst_sct3.hpp>
typedef sdsl::bp_interval<> node_type;

#define ALLOC_SIZE              1048576
#define DEL                     '$'
#define DEL_STR                 "$"
#define INPUT_STR               "input_str.txt"

#define DNA                     "ACGTN"                         //DNA alphabet
#define PROT                    "ARNDCQEGHILKMFPSTWYVOUBZJX*"          //Proteins alphabet
#define IUPAC                   "ACGTUWSMKRYBDHVN"          	//IUPAC alphabet
#define max(a,b) ((a) > (b)) ? (a) : (b)
#define min(a,b) ((a) < (b)) ? (a) : (b)

#ifdef _USE_64
typedef int64_t INT;
#endif

#ifdef _USE_32
typedef int32_t INT;
#endif

struct TSwitch
 {
   char               * alphabet;
   char               * input_filename;
   char               * output_filename;
   unsigned int         k;
   double	        t;
   unsigned int         r;
   unsigned int         total_length;
 };

double gettime( void );
int decode_switches ( int argc, char * argv [], struct TSwitch * sw );
void usage ( void );
unsigned int RevComStr ( unsigned char * str, unsigned char * str2, INT iLen );
unsigned int compute_aw ( unsigned char * seq, unsigned char * seq_id, struct TSwitch sw );

inline void compute_avoidnumk(const node_type &v, INT nuk, unsigned char * seq);
inline void find_avoid(const node_type &v, unsigned char * seq);
inline INT nodenow(const node_type &v);
inline INT nodesuffix(const node_type &v);
inline INT nodeprefix(const node_type &v);
inline INT nodeinfix(const node_type &v);

