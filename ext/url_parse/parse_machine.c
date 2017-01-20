
#line 1 "parse_machine.rl"
#include <stdio.h>
#include "parse_machine.h"
#include "url_parse.h"

#define LEN(AT, FPC) (FPC - buffer - AT)
#define MARK(M,FPC) (M = (FPC) - buffer)
#define PTR_TO(FIELD) (buffer + FIELD)


#line 56 "parse_machine.rl"



#line 17 "parse_machine.c"
static const char _url_parse_actions[] = {
	0, 1, 0, 1, 1
};

static const char _url_parse_key_offsets[] = {
	0, 0, 1, 2, 8, 16, 23, 30
};

static const char _url_parse_trans_keys[] = {
	47, 47, 48, 57, 65, 90, 97, 122, 
	45, 46, 48, 57, 65, 90, 97, 122, 
	45, 48, 57, 65, 90, 97, 122, 45, 
	48, 57, 65, 90, 97, 122, 45, 46, 
	48, 57, 65, 90, 97, 122, 0
};

static const char _url_parse_single_lengths[] = {
	0, 1, 1, 0, 2, 1, 1, 2
};

static const char _url_parse_range_lengths[] = {
	0, 0, 0, 3, 3, 3, 3, 3
};

static const char _url_parse_index_offsets[] = {
	0, 0, 2, 4, 8, 14, 19, 24
};

static const char _url_parse_indicies[] = {
	0, 1, 2, 1, 3, 4, 4, 1, 
	5, 2, 3, 3, 3, 1, 5, 3, 
	3, 3, 1, 6, 4, 4, 4, 1, 
	6, 2, 4, 4, 4, 1, 0
};

static const char _url_parse_trans_targs[] = {
	2, 0, 3, 4, 7, 5, 6
};

static const char _url_parse_trans_actions[] = {
	1, 0, 0, 0, 0, 0, 0
};

static const char _url_parse_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 3
};

static const int url_parse_start = 1;
static const int url_parse_first_final = 7;
static const int url_parse_error = 0;

static const int url_parse_en_main = 1;


#line 59 "parse_machine.rl"

void
execute(const char *buffer, size_t len)
{
  size_t mark = 0;
  int cs = 0;
  const char *p, *pe, *eof;

  p   = buffer;
  pe  = buffer + len;
  eof = pe;

  
#line 86 "parse_machine.c"
	{
	cs = url_parse_start;
	}

#line 72 "parse_machine.rl"
  
#line 93 "parse_machine.c"
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
	_keys = _url_parse_trans_keys + _url_parse_key_offsets[cs];
	_trans = _url_parse_index_offsets[cs];

	_klen = _url_parse_single_lengths[cs];
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

	_klen = _url_parse_range_lengths[cs];
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
	_trans = _url_parse_indicies[_trans];
	cs = _url_parse_trans_targs[_trans];

	if ( _url_parse_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _url_parse_actions + _url_parse_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 16 "parse_machine.rl"
	{
    MARK(mark, p);
  }
	break;
#line 173 "parse_machine.c"
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
	const char *__acts = _url_parse_actions + _url_parse_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 1:
#line 20 "parse_machine.rl"
	{
    printf("URI: %s\n", PTR_TO(mark));
  }
	break;
#line 195 "parse_machine.c"
		}
	}
	}

	_out: {}
	}

#line 73 "parse_machine.rl"
}
