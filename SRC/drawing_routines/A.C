#define BITSOFPRECISION 3
#define BITSOFPRECISIONPOW 8

extern long asm1, asm2, asm3, asm4, fpuasm, globalx3, globaly3;
extern void *reciptable;

static long bpl, transmode = 0;
static long glogx, glogy, gbxinc, gbyinc, gpinc;
static char *gbuf, *gpal, *ghlinepal, *gtrans;

	//Global variable functions
setvlinebpl(long dabpl) { bpl = dabpl; }
fixtransluscence(long datransoff) { gtrans = (char *)datransoff; }
settransnormal() { transmode = 0; }
settransreverse() { transmode = 1; }


	//Ceiling/floor horizontal line functions
sethlinesizes(long logx, long logy, long bufplc)
	{ glogx = logx; glogy = logy; gbuf = (char *)bufplc; }
setpalookupaddress(char *paladdr) { ghlinepal = paladdr; }
setuphlineasm4(long bxinc, long byinc) { gbxinc = bxinc; gbyinc = byinc; }
hlineasm4(long cnt, long skiploadincs, long paloffs, unsigned long by, unsigned long bx, long p)
{
	char *palptr;

	palptr = (char *)&ghlinepal[paloffs];
	if (!skiploadincs) { gbxinc = asm1; gbyinc = asm2; }
	for(;cnt>=0;cnt--)
	{
		*((char *)p) = palptr[gbuf[((bx>>(32-glogx))<<glogy)+(by>>(32-glogy))]];
		bx -= gbxinc;
		by -= gbyinc;
		p--;
	}
}


	//Sloped ceiling/floor vertical line functions
setupslopevlin(long logylogx, long bufplc, long pinc)
{
	glogx = (logylogx&255); glogy = (logylogx>>8);
	gbuf = (char *)bufplc; gpinc = pinc;
}
slopevlin(long p, long i, long slopaloffs, long cnt, long bx, long by)
{
	long *slopalptr, bz, bzinc;
	unsigned long u, v;

	bz = asm3; bzinc = (asm1>>3);
	slopalptr = (long *)slopaloffs;
	for(;cnt>0;cnt--)
	{
		i = krecip(bz>>6); bz += bzinc;
		u = bx+globalx3*i;
		v = by+globaly3*i;
		(*(char *)p) = *(char *)(slopalptr[0]+gbuf[((u>>(32-glogx))<<glogy)+(v>>(32-glogy))]);
		slopalptr--;
		p += gpinc;
	}
}


	//Wall,face sprite/wall sprite vertical line functions
setupvlineasm(long neglogy) { glogy = neglogy; }
vlineasm1(long vinc, long paloffs, long cnt, unsigned long vplc, long bufplc, long p)
{
	gbuf = (char *)bufplc;
	gpal = (char *)paloffs;
	for(;cnt>=0;cnt--)
	{
		*((char *)p) = gpal[gbuf[vplc>>glogy]];
		p += bpl;
		vplc += vinc;
	}
}

setupmvlineasm(long neglogy) { glogy = neglogy; }
mvlineasm1(long vinc, long paloffs, long cnt, unsigned long vplc, long bufplc, long p)
{
	char ch;

	gbuf = (char *)bufplc;
	gpal = (char *)paloffs;
	for(;cnt>=0;cnt--)
	{
		ch = gbuf[vplc>>glogy]; if (ch != 255) *((char *)p) = gpal[ch];
		p += bpl;
		vplc += vinc;
	}
}

setuptvlineasm(long neglogy) { glogy = neglogy; }
tvlineasm1(long vinc, long paloffs, long cnt, unsigned long vplc, long bufplc, long p)
{
	char ch;

	gbuf = (char *)bufplc;
	gpal = (char *)paloffs;
	if (transmode)
	{
		for(;cnt>=0;cnt--)
		{
			ch = gbuf[vplc>>glogy];
			if (ch != 255) *((char *)p) = gtrans[(*((char *)p))+(gpal[ch]<<8)];
			p += bpl;
			vplc += vinc;
		}
	}
	else
	{
		for(;cnt>=0;cnt--)
		{
			ch = gbuf[vplc>>glogy];
			if (ch != 255) *((char *)p) = gtrans[((*((char *)p))<<8)+gpal[ch]];
			p += bpl;
			vplc += vinc;
		}
	}
}

	//Floor sprite horizontal line functions
msethlineshift(long logx, long logy) { glogx = logx; glogy = logy; }
mhline(long bufplc, unsigned long bx, long cntup16, long junk, unsigned long by, long p)
{
	char ch;

	gbuf = (char *)bufplc;
	gpal = (char *)asm3;
	for(cntup16>>=16;cntup16>0;cntup16--)
	{
		ch = gbuf[((bx>>(32-glogx))<<glogy)+(by>>(32-glogy))];
		if (ch != 255) *((char *)p) = gpal[ch];
		bx += asm1;
		by += asm2;
		p++;
	}
}

tsethlineshift(long logx, long logy) { glogx = logx; glogy = logy; }
thline(long bufplc, unsigned long bx, long cntup16, long junk, unsigned long by, long p)
{
	char ch;

	gbuf = (char *)bufplc;
	gpal = (char *)asm3;
	if (transmode)
	{
		for(cntup16>>=16;cntup16>0;cntup16--)
		{
			ch = gbuf[((bx>>(32-glogx))<<glogy)+(by>>(32-glogy))];
			if (ch != 255) *((char *)p) = gtrans[(*((char *)p))+(gpal[ch]<<8)];
			bx += asm1;
			by += asm2;
			p++;
		}
	}
	else
	{
		for(cntup16>>=16;cntup16>0;cntup16--)
		{
			ch = gbuf[((bx>>(32-glogx))<<glogy)+(by>>(32-glogy))];
			if (ch != 255) *((char *)p) = gtrans[((*((char *)p))<<8)+gpal[ch]];
			bx += asm1;
			by += asm2;
			p++;
		}
	}
}


	//Rotatesprite vertical line functions
setupspritevline(long paloffs, long bxinc, long byinc, long ysiz)
{
	gpal = (char *)paloffs;
	gbxinc = bxinc;
	gbyinc = byinc;
	glogy = ysiz;
}
spritevline(long bx, long by, long cnt, long bufplc, long p)
{
	gbuf = (char *)bufplc;
	for(;cnt>1;cnt--)
	{
		(*(char *)p) = gpal[gbuf[(bx>>16)*glogy+(by>>16)]];
		bx += gbxinc;
		by += gbyinc;
		p += bpl;
	}
}

	//Rotatesprite vertical line functions
msetupspritevline(long paloffs, long bxinc, long byinc, long ysiz)
{
	gpal = (char *)paloffs;
	gbxinc = bxinc;
	gbyinc = byinc;
	glogy = ysiz;
}
mspritevline(long bx, long by, long cnt, long bufplc, long p)
{
	char ch;

	gbuf = (char *)bufplc;
	for(;cnt>1;cnt--)
	{
		ch = gbuf[(bx>>16)*glogy+(by>>16)];
		if (ch != 255) (*(char *)p) = gpal[ch];
		bx += gbxinc;
		by += gbyinc;
		p += bpl;
	}
}

tsetupspritevline(long paloffs, long bxinc, long byinc, long ysiz)
{
	gpal = (char *)paloffs;
	gbxinc = bxinc;
	gbyinc = byinc;
	glogy = ysiz;
}
tspritevline(long bx, long by, long cnt, long bufplc, long p)
{
	char ch;

	gbuf = (char *)bufplc;
	if (transmode)
	{
		for(;cnt>1;cnt--)
		{
			ch = gbuf[(bx>>16)*glogy+(by>>16)];
			if (ch != 255) *((char *)p) = gtrans[(*((char *)p))+(gpal[ch]<<8)];
			bx += gbxinc;
			by += gbyinc;
			p += bpl;
		}
	}
	else
	{
		for(;cnt>1;cnt--)
		{
			ch = gbuf[(bx>>16)*glogy+(by>>16)];
			if (ch != 255) *((char *)p) = gtrans[((*((char *)p))<<8)+gpal[ch]];
			bx += gbxinc;
			by += gbyinc;
			p += bpl;
		}
	}
}
