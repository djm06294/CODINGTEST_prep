// Copyright 2022 <jehan.yoon>
#include <cstdio>
#include <algorithm>

#include <algorithm>
#include <cctype>
namespace fio {
  constexpr size_t BUF_SIZ = 0x2'0000, SPARE = 20;
  char buf_i[BUF_SIZ], *p_in = buf_i, *p_max = p_in;

  inline char getCh(void) {
    if (p_in == p_max) {
      p_max = buf_i + fread(buf_i, 1, BUF_SIZ, stdin);
      p_in = buf_i;
    }
    return (p_in != p_max) ? *(p_in++) : -1;
  }

  template<typename T>
  inline T get(void) {
    int t, sign = 1;
    T r = 0;
    do {
      t = getCh();
    } while (t != '-' && (t < '0' || t > '9'));
    if (t == '-')  sign = -1, t = getCh();
    while (true) {
      r = r * 10 + t - '0'; t = getCh();
      if (t < '0' || t > '9')    break;
    }
    return r * sign;
  }

  void getString(char* s) {
    char c;
    do {
      c = getCh();
    } while (isspace(c));
    while (!isspace(c)) {
      *s++ = c;
      c = getCh();
    }
    *s = '\0';
  }

  char buf_o[BUF_SIZ + SPARE], *p_out = buf_o;

  template<typename T>
  void prt(T n, char delim = ' ') {
    if (n < 0) n = -n, *p_out++ = '-';
    char *ptr = p_out;
    do { *ptr++ = n % 10 + '0';  n /= 10; } while (n);
    std::reverse(p_out, ptr);
    *ptr++ = delim;
    if (ptr < buf_o + BUF_SIZ) {
      p_out = ptr;
    } else {
      fwrite(buf_o, ptr - buf_o, 1, stdout); p_out = buf_o;
    }
  }

  inline void prtn(void) {
    *p_out++ = '\n';
    if (p_out >= buf_o + BUF_SIZ)
    { fwrite(buf_o, p_out - buf_o, 1, stdout); p_out = buf_o; }
  }

  void flush(void) {
    fwrite(buf_o, p_out - buf_o, 1, stdout);
    p_out = buf_o;
  }
};  // namespace fio
///////////////////////////

constexpr int MAXW = 10'000;
int weight[MAXW + 1];

int main( void)
{
#ifdef JH_DEBUG
  freopen("2217_input.txt", "rt", stdin);
#endif
	int N, ans = 0;

	N = fio::get<int>();
	for( int i = 0; i <= MAXW; i++) weight[i] = 0;
	for( int i = 0; i < N; i++) {
		weight[fio::get<int>()]++;
	}

	for( int i = MAXW, cnt = 0; i > 0; i--) {
		cnt += weight[i];
		ans = std::max( ans, i * cnt);
	}
	fio::prt(ans, '\n');
	fio::flush();

	return 0;
}