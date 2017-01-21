
#line 1 "parse_machine.rl"
#include <stdio.h>
#include "parse_machine.h"
#include "uri_parse.h"

#define LEN(AT, FPC) (FPC - buffer - AT)
#define MARK(M,FPC) (M = (FPC) - buffer)
#define PTR_TO(FIELD) (buffer + FIELD)


#line 58 "parse_machine.rl"



#line 17 "parse_machine.c"
static const char _uri_parse_actions[] = {
	0, 1, 0, 1, 1
};

static const short _uri_parse_key_offsets[] = {
	0, 0, 1, 2, 16, 22, 28, 34, 
	42, 49, 57, 63, 70, 72, 78, 86, 
	92, 100, 106, 124, 141, 159, 175, 192, 
	208, 224, 242, 258, 276, 292, 308, 317, 
	324, 326, 335, 353, 369, 385
};

static const char _uri_parse_trans_keys[] = {
	47, 47, 33, 37, 61, 64, 95, 126, 
	36, 46, 48, 59, 65, 90, 97, 122, 
	48, 57, 65, 70, 97, 102, 48, 57, 
	65, 70, 97, 102, 48, 57, 65, 90, 
	97, 122, 45, 46, 48, 57, 65, 90, 
	97, 122, 45, 48, 57, 65, 90, 97, 
	122, 45, 46, 48, 57, 65, 90, 97, 
	122, 48, 57, 65, 90, 97, 122, 45, 
	48, 57, 65, 90, 97, 122, 48, 57, 
	48, 57, 65, 90, 97, 122, 45, 46, 
	48, 57, 65, 90, 97, 122, 48, 57, 
	65, 90, 97, 122, 45, 46, 48, 57, 
	65, 90, 97, 122, 48, 57, 65, 90, 
	97, 122, 33, 37, 45, 46, 61, 64, 
	95, 126, 36, 44, 48, 57, 58, 59, 
	65, 90, 97, 122, 33, 37, 45, 61, 
	64, 95, 126, 36, 46, 48, 57, 58, 
	59, 65, 90, 97, 122, 33, 37, 45, 
	46, 61, 64, 95, 126, 36, 44, 48, 
	57, 58, 59, 65, 90, 97, 122, 33, 
	37, 61, 64, 95, 126, 36, 46, 48, 
	57, 58, 59, 65, 90, 97, 122, 33, 
	37, 45, 61, 64, 95, 126, 36, 46, 
	48, 57, 58, 59, 65, 90, 97, 122, 
	33, 37, 61, 64, 95, 126, 36, 46, 
	48, 57, 58, 59, 65, 90, 97, 122, 
	33, 37, 61, 64, 95, 126, 36, 46, 
	48, 57, 58, 59, 65, 90, 97, 122, 
	33, 37, 45, 46, 61, 64, 95, 126, 
	36, 44, 48, 57, 58, 59, 65, 90, 
	97, 122, 33, 37, 61, 64, 95, 126, 
	36, 46, 48, 57, 58, 59, 65, 90, 
	97, 122, 33, 37, 45, 46, 61, 64, 
	95, 126, 36, 44, 48, 57, 58, 59, 
	65, 90, 97, 122, 33, 37, 61, 64, 
	95, 126, 36, 46, 48, 57, 58, 59, 
	65, 90, 97, 122, 33, 37, 61, 64, 
	95, 126, 36, 46, 48, 57, 58, 59, 
	65, 90, 97, 122, 45, 46, 58, 48, 
	57, 65, 90, 97, 122, 58, 48, 57, 
	65, 90, 97, 122, 48, 57, 45, 46, 
	58, 48, 57, 65, 90, 97, 122, 33, 
	37, 45, 46, 58, 59, 61, 64, 95, 
	126, 36, 44, 48, 57, 65, 90, 97, 
	122, 33, 37, 58, 59, 61, 64, 95, 
	126, 36, 46, 48, 57, 65, 90, 97, 
	122, 33, 37, 61, 64, 95, 126, 36, 
	46, 48, 57, 58, 59, 65, 90, 97, 
	122, 33, 37, 45, 46, 58, 59, 61, 
	64, 95, 126, 36, 44, 48, 57, 65, 
	90, 97, 122, 0
};

static const char _uri_parse_single_lengths[] = {
	0, 1, 1, 6, 0, 0, 0, 2, 
	1, 2, 0, 1, 0, 0, 2, 0, 
	2, 0, 8, 7, 8, 6, 7, 6, 
	6, 8, 6, 8, 6, 6, 3, 1, 
	0, 3, 10, 8, 6, 10
};

static const char _uri_parse_range_lengths[] = {
	0, 0, 0, 4, 3, 3, 3, 3, 
	3, 3, 3, 3, 1, 3, 3, 3, 
	3, 3, 5, 5, 5, 5, 5, 5, 
	5, 5, 5, 5, 5, 5, 3, 3, 
	1, 3, 4, 4, 5, 4
};

static const short _uri_parse_index_offsets[] = {
	0, 0, 2, 4, 15, 19, 23, 27, 
	33, 38, 44, 48, 53, 55, 59, 65, 
	69, 75, 79, 93, 106, 120, 132, 145, 
	157, 169, 183, 195, 209, 221, 233, 240, 
	245, 247, 254, 269, 282, 294
};

static const char _uri_parse_indicies[] = {
	0, 1, 2, 1, 3, 4, 3, 5, 
	3, 3, 3, 3, 3, 3, 1, 6, 
	6, 6, 1, 3, 3, 3, 1, 7, 
	8, 8, 1, 9, 10, 7, 11, 11, 
	1, 9, 11, 11, 11, 1, 9, 12, 
	11, 11, 11, 1, 11, 8, 8, 1, 
	13, 8, 8, 8, 1, 14, 1, 15, 
	8, 8, 1, 9, 16, 15, 11, 11, 
	1, 17, 8, 8, 1, 9, 18, 17, 
	11, 11, 1, 19, 8, 8, 1, 3, 
	4, 20, 21, 3, 5, 3, 3, 3, 
	22, 3, 23, 23, 1, 3, 4, 20, 
	3, 5, 3, 3, 3, 23, 3, 23, 
	23, 1, 3, 4, 20, 24, 3, 5, 
	3, 3, 3, 23, 3, 23, 23, 1, 
	3, 4, 3, 5, 3, 3, 3, 23, 
	3, 25, 25, 1, 3, 4, 26, 3, 
	5, 3, 3, 3, 25, 3, 25, 25, 
	1, 3, 4, 3, 5, 3, 3, 3, 
	27, 3, 3, 3, 1, 3, 4, 3, 
	5, 3, 3, 3, 28, 3, 25, 25, 
	1, 3, 4, 20, 29, 3, 5, 3, 
	3, 3, 28, 3, 23, 23, 1, 3, 
	4, 3, 5, 3, 3, 3, 30, 3, 
	25, 25, 1, 3, 4, 20, 31, 3, 
	5, 3, 3, 3, 30, 3, 23, 23, 
	1, 3, 4, 3, 5, 3, 3, 3, 
	32, 3, 25, 25, 1, 3, 4, 3, 
	5, 3, 3, 3, 22, 3, 25, 25, 
	1, 13, 33, 34, 8, 8, 8, 1, 
	34, 11, 8, 8, 1, 14, 1, 9, 
	12, 34, 19, 11, 11, 1, 3, 4, 
	26, 35, 36, 3, 3, 5, 3, 3, 
	3, 25, 25, 25, 1, 3, 4, 36, 
	3, 3, 5, 3, 3, 3, 23, 25, 
	25, 1, 3, 4, 3, 5, 3, 3, 
	3, 27, 3, 3, 3, 1, 3, 4, 
	20, 24, 36, 3, 3, 5, 3, 3, 
	3, 32, 23, 23, 1, 0
};

static const char _uri_parse_trans_targs[] = {
	2, 0, 29, 3, 4, 6, 5, 7, 
	30, 8, 13, 9, 10, 11, 32, 14, 
	15, 16, 17, 33, 19, 24, 18, 20, 
	21, 34, 22, 36, 25, 26, 27, 28, 
	37, 31, 12, 35, 23
};

static const char _uri_parse_trans_actions[] = {
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0
};

static const char _uri_parse_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 3, 3, 3, 
	3, 3, 3, 3, 3, 3
};

static const int uri_parse_start = 1;
static const int uri_parse_first_final = 29;
static const int uri_parse_error = 0;

static const int uri_parse_en_main = 1;


#line 61 "parse_machine.rl"

void
execute(void *hash, const char *buffer, size_t len)
{
  size_t mark = 0;
  int cs = 0;
  const char *p, *pe, *eof;

  p   = buffer;
  pe  = buffer + len;
  eof = pe;

  
#line 195 "parse_machine.c"
	{
	cs = uri_parse_start;
	}

#line 74 "parse_machine.rl"
  
#line 202 "parse_machine.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _uri_parse_trans_keys + _uri_parse_key_offsets[cs];
	_trans = _uri_parse_index_offsets[cs];

	_klen = _uri_parse_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _uri_parse_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _uri_parse_indicies[_trans];
	cs = _uri_parse_trans_targs[_trans];

	if ( _uri_parse_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _uri_parse_actions + _uri_parse_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 12 "parse_machine.rl"
	{
    MARK(mark, p);
  }
	break;
#line 282 "parse_machine.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _uri_parse_actions + _uri_parse_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 1:
#line 16 "parse_machine.rl"
	{
    URIParse_set(hash, PTR_TO(mark), LEN(mark, p), id_uri);
  }
	break;
#line 304 "parse_machine.c"
		}
	}
	}

	_out: {}
	}

#line 75 "parse_machine.rl"
}
