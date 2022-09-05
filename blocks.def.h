//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
     	/*Icon*/    /*Command*/    /*Update Interval*/    /*Update Signal*/
	{" Vol: ",    "amixer -D pulse get Master | tail -n 1 | awk '{print $5}' | awk '{print substr($0, 2, length($0) - 3)}'",    1,    0}, 

    	{"Brg: ",    "~/Projects/dwmblocks/brightnessstatus.o",    1,    0},

	{"Mem: ",    "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",    10,    0},

	{"Bat: ",    "~/Projects/dwmblocks/batterystatus.o",    10,    0},

	{"",    "date '+%a, %b %d | %I:%M%p '",    10,    0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
