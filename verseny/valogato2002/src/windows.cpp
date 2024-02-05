//
// Problem F: Windows
//

#include <stdio.h>
#include <math.h>

int sc_w, sc_h;
double win_ratio[4];


int try_width (int win_no, int width)
{
  if (width == 0)
    return -1;
  double height = width / win_ratio[win_no];
  int int_height = (int)(height + .0000005);
  if (fabs (height - int_height) < .000001)
    {
      return int_height;
    }
  else
    {
      return -1;
    }
}


int try_height (int win_no, int height)
{
  if (height == 0)
    return -1;
  double width = height * win_ratio[win_no];
  int int_width = (int)(width + .0000005);
  if (fabs (width - int_width) < .000001)
    {
      return int_width;
    }
  else
    {
      return -1;
    }
}

int try_filling (int sc_w, int sc_h, int used[], int n)
{
  int win_no, wd, ht;
  if (sc_w == 0 || sc_h == 0)
    {
      return (n == 4) ? 1 : 0;
    }

  for (win_no = 0; win_no < 4; win_no++)
    {
      if (!used[win_no])
	{
	  used[win_no] = 1;

	  ht = try_width (win_no, sc_w);
	  if (ht != -1 && ht <= sc_h)
	    {
	      if (try_filling (sc_w, sc_h - ht, used, n + 1))
		return 1;
	    }
	  else
	    {
	      wd = try_height (win_no, sc_h);
	      if (wd != -1 && wd <= sc_w)
		{
		  if (try_filling (sc_w - wd, sc_h, used, n + 1))
		    return 1;
		}
	    }

	  used[win_no] = 0;
	}
    }
  return 0;
}


int try_mixed ()
{
  int w1, w2, w3, w4;
  int used[4] = { 0 };

  for (w1 = 0; w1 < 1; w1++)
    {
      used[w1] = 1;
      for (w2 = 0; w2 < 4; w2++)
	{
	  if (!used[w2])
	    {
	      used[w2] = 1;

	      int width_1 = (int)
		((win_ratio[w1] * sc_w) / (win_ratio[w1] + win_ratio[w2]));
	      int height_1 = try_width (w1, width_1);
	      int width_2 = sc_w - width_1;
	      int height_2 = try_width (w2, width_2);
	      if (height_1 != -1 && height_1 == height_2)
		{


		  for (w3 = 0; w3 < 4; w3++)
		    {
		      if (!used[w3])
			{
			  used[w3] = 1;
			  for (w4 = 0; w4 < 4; w4++)
			    {
			      if (!used[w4])
				{

				  int width_3 = (int)
				    ((win_ratio[w3] * sc_w) / (win_ratio[w3] +
							      win_ratio[w4]));
				  int height_3 = try_width (w3, width_3);
				  int width_4 = sc_w - width_3;
				  int height_4 = try_width (w4, width_4);
				  if (height_3 != -1 && height_3 == height_4
				      && height_1 + height_3 == sc_h)
				    return 1;

				}
			    }
			  used[w3] = 0;
			}
		    }


		}
	      used[w2] = 0;
	    }
	}
      used[w1] = 0;
    }

  return 0;
}


int main ()
{
  int i, set_no = 1, found, w, h;
  FILE *inf = stdin;
  int used[4];

  while (fscanf (inf, "%d %d", &sc_w, &sc_h), sc_w || sc_h)
    {
      found = 0;
      for (i = 0; i < 4; i++)
	{
	  used[i] = 0;
	  fscanf (inf, "%d %d", &w, &h);
	  win_ratio[i] = (float) w / h;
	}
      if (try_filling (sc_w, sc_h, used, 0))
	{
	  found = 1;
	}
      else
	{
	  if (try_mixed ())
	    {
	      found = 1;
	    }
	  else
	    {
	      for (i = 0; i < 4; i++)
		win_ratio[i] = 1 / win_ratio[i];
	      w = sc_w;
	      sc_w = sc_h;
	      sc_h = w;
	      if (try_mixed ())
		{
		  found = 1;
		}
	    }
	}
      if (found)
	{
	  printf ("Yes\n", set_no++);
	}
      else
	{
	  printf ("No\n", set_no++);
	}
    }
  return 0;
}














