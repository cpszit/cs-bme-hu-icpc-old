/*
  ACM probaverseny
  BME, 2003
  
  Problem B - Enthropy
  
 */

#include <stdlib.h>
#include <stdio.h>

int hmo[256];

struct tc {
  int freq;
  int alive;
  char ch;
  tc *father;
  tc *next;
};


tc *first;
tc *last;
tc *current;

void clear_tcs ( ) {
  first = NULL;
  last = NULL;
  current = NULL;
}


tc *new_tc ( ) {
  tc *ntc = new tc;
  if (last != NULL)
    last->next = ntc;
  if (first == NULL)
    first = ntc;
  ntc->next = NULL;
  last = ntc;
  return ntc;
}

void reset_tcs ( ) {
  current = first;
}

int get_next_tc ( tc **where) {
  if (current != NULL) {
    *where = current;
    //    fprintf (stderr, "From list: %d \n", current->ch);
    current = current->next;
    return 1;
  } else
    return 0;
}

int get_next_alive_tc ( tc **where ) {
  int done = 0;
  int eof = 0;
  while ((!done) && (!eof)) {
    if (get_next_tc(where)) 
      done = (*where)->alive;
    else
      eof = 1;
  }
  return done;
}

int numof_tc;

tc *cc[256];


int main ( ) {
  while (1) {
    int ch;
    int done = 0;
    int l = 0;
    char s[4];
    int obl;
    int bl;
    int sl = 0;
    for (ch = 255; ch ; ch--)
      hmo[ch] = 0;
    while (( ch = getchar()) != '\n' ) {
      if (l < 3)
	s[l++] = ch;
      if (l == 3) {
	s[l] = 0;
	l++;
	done = !strcmp("END", s);
      }
      hmo[ch]++;
      sl++;
    }
    if (done)
      break;

    /*
    for (ch = 0; ch <= 255; ch++)
      if (hmo[ch])
	printf ("%c: %d ", ch, hmo[ch]);
    printf("\n");
    */


    numof_tc = 0;
    clear_tcs();

    for (ch = 0; ch <= 255; ch++)
      if (hmo[ch]) {
	tc *ctc = new_tc();
	ctc->alive = 1;
	ctc->freq = hmo[ch];
	ctc->ch = ch;
	ctc->father = NULL;
	numof_tc++;
	cc[ch] = ctc;
      }


    while (numof_tc > 1) {
      tc *tc1, *tc2, *ctc;

      reset_tcs();

      get_next_alive_tc(&tc1);
      get_next_alive_tc(&tc2);


      if (tc1->freq > tc2->freq) {
	ctc = tc1;
	tc1 = tc2;
	tc2 = ctc;
      }

      while (get_next_alive_tc(&ctc)) {
	if (ctc->freq < tc2->freq)
	  if (ctc->freq < tc1->freq) {
	    tc2 = tc1;
	    tc1 = ctc;
	  } else
	    tc2 = ctc;
      }

      ctc = new_tc();
      tc1->alive = 0;
      tc2->alive = 0;
      tc1->father = ctc;
      tc2->father = ctc;
      ctc->alive = 1;
      ctc->father = NULL;
      ctc->freq = tc1->freq + tc2->freq;
      numof_tc--;

    };

    for (bl = 0, ch = 0; ch <= 255; ch++) 
      if (hmo[ch]) {
	int cl;
	tc *ctc;
	for (cl = 0, ctc = cc[ch]; ctc->father != NULL; ctc = ctc->father)
	  cl++;
	bl += hmo[ch] * cl;
      }

    obl = sl * 8;

    printf("%d %d %.1f\n", obl, bl, (double)obl/(double)bl);

  }
  return 0;
}
