//
// Problem D: Winning Move
//

#include <stdio.h>
#include <string.h>

char board[100];
#define SPACE '.'
#define HASHSIZE (11*11*11*11*11*11)

#define hash(x) ((x)%HASHSIZE)

int hashtable[HASHSIZE];

int code;
int mask[16];

int isWin (int i, char player);
int oForcedLossPlaying (int j);
int xForcedWinPlaying (int i);


int lookup (int &p)
{
  p = hash (code);
  while (hashtable[p])
    {
      if (hashtable[p] == code)
	return 1;
      if (hashtable[p] == -code)
	return 0;
      if (!p--)
	p += HASHSIZE;
    }
  return -1;
}


int findForcedWin ()
{
  for (int i = 0; i < 16; ++i)
    if (board[i] == SPACE && xForcedWinPlaying (i))
      return i;
  return -1;
}


int main ()
{
  int i;
  int t = 1;
  for (i = 0; i < 16; i++)
    {
      mask[i] = t;
      t *= 3;
    }
  memset (hashtable, 0, 4 * HASHSIZE);
  for (;;)
    {
      char c;
      scanf ("%c\n", &c);
      if (c != '?')
	break;
      for (i = 0; i < 4; i++)
	scanf ("%s\n", board + i * 4);
      code = 0;
      for (i = 0; i < 16; i++)
	{
	  if (board[i] == 'x')
	    code += mask[i] * 1;
	  if (board[i] == 'o')
	    code += mask[i] * 2;
	}
      int k = findForcedWin ();
      if (k >= 0)
	printf ("%d %d\n", k / 4, k % 4);
      else
	printf ("#####\n");
    }
}


int oForcedLossPlaying (int j)
{
  board[j] = 'o';
  code += mask[j] * 2;
  int p;
  int l = lookup (p);
  if (l >= 0)
    {
      board[j] = SPACE;
      code -= mask[j] * 2;
      return l;
    }

  if (!isWin (j, 'o'))
    {
      for (int i = 0; i < 16; ++i)
	{
	  if (board[i] == SPACE && xForcedWinPlaying (i))
	    {
	      hashtable[p] = code;
	      board[j] = SPACE;
	      code -= mask[j] * 2;
	      return 1;
	    }
	}
    }

  hashtable[p] = -code;
  board[j] = SPACE;
  code -= mask[j] * 2;
  return 0;
}

int xForcedWinPlaying (int i)
{
  board[i] = 'x';
  code += mask[i] * 1;
  int p;
  int l = lookup (p);
  if (l >= 0)
    {
      board[i] = SPACE;
      code -= mask[i] * 1;
      return l;
    }
  if (!isWin (i, 'x'))
    {
      for (int j = 0; j < 16; ++j)
	{
	  if (board[j] == SPACE && !oForcedLossPlaying (j))
	    {
	      board[i] = SPACE;
	      hashtable[p] = -code;
	      code -= mask[i] * 1;
	      return 0;
	    }
	}
    }
  hashtable[p] = code;
  board[i] = SPACE;
  code -= mask[i] * 1;
  return 1;
}



int isWin (int i, char player)
{

  int r = 4 * (i / 4);
  int c = i % 4;

  int result = (board[r] == player && board[r + 1] == player &&
		board[r + 2] == player && board[r + 3] == player)
    || (board[c] == player && board[c + 4] == player &&
	board[c + 8] == player && board[c + 12] == player)
    || (board[0] == player && board[5] == player &&
	board[10] == player && board[15] == player)
    || (board[3] == player && board[6] == player &&
	board[9] == player && board[12] == player);
  return result;
}

