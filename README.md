# PaySkyAssigment
/*
*
Auther Name :Ahmed Esmail
File name :README.md
*/
the c files in this directory implement Replace Utility
-------------------------------------------------------------
-----------------------Build command-------------------------
Replace utility could be build using GCC compilier with the 
following command
#gcc -o Replace Replace.c MyFunctions.c

-------------------------------------------------------------
-----------------------Usage---------------------------------
Usage : Replace -<option> from to >LOF>
option is one of the following.
	-i   : case insensetive
	-f   : Replace only First
	-b   : Back up before replacement
	-l   : Discover Resources
from : String that replace to
to   : String that were replaced with from
LOF  : List of files the command works on

-------------------------------------------------------------
------------------------notes--------------------------------
when the -b option is select each file of LOF is backed up in 
in file with the same namelocal time at which back up took  place
for example if file name is is ahmed.txt then  back up in file 
like ahmed.txt_Jul 22 18:33:39.BU
the file has extension .BU

