//kpm.c
#include "kpm.h"
#include "kpm_defines.h"
#include <lpc21xx.h>
u32 kpmlut[4][4]={
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'c','0','=','+'}
	};
void init_kpm(void)
{
IODIR1|=15<<row0;
}
u32 colscan(void)
{
u32 status;
status=(((IOPIN1>>col0)&15)<15)?0:1;
return status;
}
u32 rowcheck(void)
{
u32 r;
for(r=0;r<=3;r++)
{
IOPIN1=((IOPIN1&~(15<<row0))|(~(1<<r)<<row0));
if(colscan()==0)
{
break;
}
}
IOCLR1=15<<row0;
return r;
}
u32 colcheck(void)
{
u32 c;
for(c=0;c<=3;c++)
{
if(((IOPIN1>>col0+c)&1)==0)
{
break;
}
}
return c;
}
u32 keyscan(void)
{
u32 r,c,key;
init_kpm();
while(colscan()!=0);
r=rowcheck();
c=colcheck();
key=kpmlut[r][c];
return key;
}
