#include <cstdio>
#include <cstring>
struct poke {
  int num;int color;
};

const double total = 43;

char mine[6][3] , enem[6][3];
bool hash[15][5];
int  len[6] , ll[6], h[15] , ml , yl;
double win;
poke me[6] , you[6] , bak[6] , b[6];

bool  check()
{
  int i ,type , top , s1 , s2;
  bool ord1[6] , ord2[6];
  int p1 = 0, p2 = 0, q1 = 0 , q2 = 0;
  if ((ml == 1) || (ml == 2)) type = 1;
    else {
      if ((ml == 4) || (ml == 9)) type = 2;
        else if ((ml == 7) || (ml == 8)) type = 3;
          else type = 4;
    }
  switch (type) {
    case 1 : {
      if (b[1].num > bak[1].num) return true;
        else return false;
      break;
    }
    case 2 : {
      top = 1;
      while (b[top].num == bak[top].num) top++;
      if (b[top].num > bak[top].num) return true;
        else return false;
      break;
    }
    case 3 : {
      memset(ord1,true,sizeof(ord1));
      memset(ord2,true,sizeof(ord2));
      p1 = 1;
      while (b[p1].num != b[p1+1].num) { p1++;ord1[p1] = false; }
      p2 = 1;
      while (bak[p2].num != bak[p2+1].num) { p2++;ord2[p2] = false; }
      if (ml == 7) {
        q1 = p1+1;
        while (b[q1].num != b[q1+1].num) { q1++;ord1[q1] = false; }
        q2 = p2+1;
        while (bak[q2].num != bak[q2+1].num) { q2++;ord2[q2] = false; }
        if (b[p1].num > bak[p2].num) return true;
          else {
            if (b[p1].num == bak[p2].num) {
              if (b[q1].num > bak[q2].num) return true;
                else {
                   for (i = 1;i <= 5;i++)
                     if (!ord1[i]) break;
                   s1 = b[i].num;
                   for (i = 1;i <= 5;i++)
                     if (!ord2[i]) break;
                   s2 = bak[i].num;
                   if (s1 > s2) return true;
                     else return false;
                  }
            }
       }
       }
     else
       {
        if (b[p1].num > bak[p2].num) return true;
          else {
            if (b[p1].num == bak[p2].num) {
              top = 1;
              while (b[top].num == bak[top].num) top++;
                if (b[top].num > bak[top].num) return true;
                  else return false;
              }
            else return false;
          }
      }
      break;
    }
    case 4 : {
    s1 = 0;
    for (i = 2;i <= 14;i++)
      if (h[i] >= 3) s1 = i;
    memset(h,0,sizeof(h));
    for (i = 1;i <= 5;i++)
      h[b[i].num]++;
    s2 = 0;
    for (i = 2;i <= 14;i++)
      if (h[i] >= 3) s2 = i;
    if (s2 > s1) return true;
      else return false;
    break;
		}
	}
}

bool  csame() {
  int i;
  for (i = 1;i <= 4;i++)
    if (bak[i].color != bak[i+1].color) return false;
  return true;
}

inline void  sort() {
  int i , j;
  poke tmp;
  for (i = 1;i <= 4;i++)
    for (j = i+1;j <= 5;j++)
      if ((bak[i].num < bak[j].num)||
        ((bak[i].num == bak[j].num)&&(bak[i].color > bak[j].color))) {
          tmp = bak[i];bak[i] = bak[j];bak[j] = tmp;
       }
}

bool  sorted() {
  int i;
  for (i = 1;i <= 4;i++)
    if (bak[i].num != bak[i+1].num+1) return false;
  return true;
}
 
int  calc() {
  int i;
  memset(h,0,sizeof(h));
  for (i = 1;i <= 5;i++)
    h[bak[i].num]++;
  if (csame()) {
    if (sorted())
      return 1;
    else
      return 4;
  }
  else  {
      if (sorted())
        return 5;
    }
  int p = 0 , sum = 0 , sec = 0;
  for (i = 2;i <= 14;i++) {
      if (h[i] > sum) { sum = h[i];p = i; }
      if (sum == 4) return 2;
    }
  for (i = 2;i <= 14;i++)
    if (i == p) continue;
      else if (h[i] > sec) sec = h[i];    
  if (sum == 3) {
    if (sec == 2) return 3;
      else return 6;
  }
  else {
     if (sum == 2) {
        if (sec == 2) return 7;
          else return 8;
      }
  }
  return 9;
}

inline void  init() {
  int i;
  for (i = 1;i < 5;i++) {
      scanf("%s ",&enem[i]);
      ll[i] = strlen(enem[i]);
    }
    scanf("%s\n",&enem[i]);
    ll[i] = strlen(enem[i]);
  for (i = 1;i < 5;i++) {
      scanf("%s ",&mine[i]);
      len[i] = strlen(mine[i]);
    }
    scanf("%s\n",&mine[i]);
    len[i] = strlen(mine[i]);
}

inline void  translate() {
  int i;
  for (i = 1;i <= 5;i++) {
     if (len[i] == 3) me[i].num = 10;
       else  { if (mine[i][0] < 65) me[i].num = mine[i][0]-48; 
         else {
          switch (mine[i][0]) {
            case 'A' : me[i].num = 14;break;
            case 'J' : me[i].num = 11;break;
            case 'Q' : me[i].num = 12;break;
            case 'K' : me[i].num = 13;break;
        }
      }
     }
     switch (mine[i][len[i]-1]) {
       case 'C' : me[i].color = 1;break;
       case 'D' : me[i].color = 2;break;
       case 'S' : me[i].color = 3;break;
       case 'H' : me[i].color = 4;break;
     }
    hash[me[i].num][me[i].color] = false;
   }
  for (i = 2;i <= 5;i++) {
     if (ll[i] == 3) you[i].num = 10;
       else  { if (enem[i][0] < 65) you[i].num = enem[i][0]-48; 
         else {
          switch (enem[i][0]) {
            case 'A' : you[i].num = 14;break;
            case 'J' : you[i].num = 11;break;
            case 'Q' : you[i].num = 12;break;
            case 'K' : you[i].num = 13;break;
        }
      }
     }
     switch (enem[i][ll[i]-1]) {
       case 'C' : you[i].color = 1;break;
       case 'D' : you[i].color = 2;break;
       case 'S' : you[i].color = 3;break;
       case 'H' : you[i].color = 4;break;
     }
    hash[you[i].num][you[i].color] = false;
   }
}

inline  void work()
{
  int i , j , l;
  for (i = 2;i <= 14;i++)
    for (j = 1;j <= 4;j++)
      if (hash[i][j]) { 
        hash[i][j] = false;
        bak[1].num = i;bak[1].color = j;
        for (l = 2;l <= 5;l++) bak[l] = you[l];
        sort();
        yl = calc();
        if (ml < yl) win++;
          else {
             if ((ml == yl)&&(check()))
               win++;
            }
      }
}

int main () {
  freopen("poke.in","r",stdin);
  //freopen("poke.out","w",stdout);
  init();
  memset(hash,true,sizeof(hash));
  translate();
  win = 0;
  int i , j;
  poke tmp;
  for (i = 1;i <= 5;i++) { bak[i] = me[i];b[i] = bak[i]; }
  for (i = 1;i <= 4;i++)
    for (j = i+1;j <= 5;j++)
      if ((b[i].num < b[j].num)||
        ((b[i].num == b[j].num)&&(b[i].color > b[j].color))) {
          tmp = b[i];b[i] = b[j];b[j] = tmp;
       }
  sort();
  ml = calc();
  work();
  win = win/total;
  printf("%d\n",ml);
  printf("%.4f\n",win);
  if (win > 0.7) printf("You can put All your money!");
  if (win < 0.3) printf("Give it up");
  else printf("Try it!Anything!");
  return 0;
}
