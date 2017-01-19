
#line 1 "parse_machine.rl"
#include <stdio.h>
#include "parse_machine.h"


#line 15 "parse_machine.rl"



#line 12 "parse_machine.c"
static const char _url_parse_actions[] = {
	0, 1, 0
};

static const char _url_parse_key_offsets[] = {
	0, 0, 1, 2, 3, 4, 5, 6, 
	7
};

static const char _url_parse_trans_keys[] = {
	104, 101, 108, 108, 111, 90, 90, 0
};

static const char _url_parse_single_lengths[] = {
	0, 1, 1, 1, 1, 1, 1, 1, 
	0
};

static const char _url_parse_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0
};

static const char _url_parse_index_offsets[] = {
	0, 0, 2, 4, 6, 8, 10, 12, 
	14
};

static const char _url_parse_trans_targs[] = {
	2, 0, 3, 0, 4, 0, 5, 0, 
	6, 0, 7, 0, 8, 0, 0, 0
};

static const char _url_parse_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 0, 0, 0, 0, 0
};

static const int url_parse_start = 1;
static const int url_parse_first_final = 8;
static const int url_parse_error = 0;

static const int url_parse_en_main = 1;


#line 18 "parse_machine.rl"

void
execute(const char *buffer, size_t len)
{
  int cs = 0;
  const char *p, *pe, *eof;

  p   = buffer;
  pe  = buffer + len;
  eof = pe;

  
#line 71 "parse_machine.c"
	{
	cs = url_parse_start;
	}

#line 30 "parse_machine.rl"
  
#line 78 "parse_machine.c"
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
#line 7 "parse_machine.rl"
	{ printf("shouting!\n"); }
	break;
#line 155 "parse_machine.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 31 "parse_machine.rl"
}
