08/20/2003: BUILDC.ZIP

Summary:
A.ASM (of the Build source code distribution) ported to C, originally done by Ken Silverman in June of 1996. On 08/20/2003, I fixed a few bugs with it - at least the ones I remembered. :)

Story:
I did this conversion back in 1996 to help the port teams (such as Mac and consoles) so they could do their job faster. I also did it to hide my optimization tricks (in 32-bit x86 ASM), but as it turns out, this really shouldn't have been a concern of mine.

Instructions:
To lower the size of this distribution, I omitted a few files. Please copy these from my original Build Source distribution (KENBUILD.ZIP):

	TILES000.ART
	PALETTE.DAT
	TABLES.DAT
	SETUP.EXE
	SETUP.DAT
	PRAGMAS.H
	BUILD.H
	VES2.H
	CACHE1D.C

Notes about source:

1. This code is from a few months before I stopped making changes to the optimized Build code, so it's a possibile there are some bug fixes after that time that didn't make into this distribution. While preparing this source for release, I did find the clippoly bug (See BUILD2.TXT, 5/22/97) was still there, so I fixed that for you. Also, I fixed the NT/2K/XP keyboard handler bug which was in TEST.C. I don't remember any other changes to the code other than those Pentium Pro optimizations in A.ASM. Fortunately, that should have no effect on the contents of this distrubion.

2. A.C is not an exact replacement of A.ASM. I also simplified some things in ENGINE.C. For example, the biggest thing that comes to mind is: vlineasm4 and mvlineasm4 have been removed. These routines are "optimized" versions of vlineasm1 and mvlineasm1, and they don't provide any extra functionality to the engine.

3. KVX voxel support is missing! I was a bit selfish at the time and thought this feature should only exist in the PC version. It was probably a mistake. :> This only affects the port of Shadow Warrior to the Mac.

4. ksqrt() and krecip() are C replacements of nsqrtasm() and krecipasm() (respectively). You should be warned that my movement code relies on these functions, so if you use them, and you play a network game (or record a demo) with the original version, it will go out of sync pretty fast. If this is important for your project, then you must use (or simulate) the lookup table I use in my original assembler code.

-Ken S.