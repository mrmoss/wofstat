Walls of Fire Stat - Universal netstat program for Linux, Windows, BSD, OSX, and Solaris.

	Tired of all the different netstat programs out there?
	Tired of remember if it's -tulpan, -bano, -an -f inet?
	Or was it lsof? pfiles? sockstat?

Why not give wofstat a shot?

	I know what you're thinking, not another *stat program...

	Is it easy to use?
		./wofstat

	It can also be used in conjunction with wof:
		./wofstat -w

Note on Solaris:

	It seems to be literally easier to upgrade to 11 then it is to get good networking information out of it...
	On that note, this does work with 10, it just doesn't show the PIDs of the owning processes...
