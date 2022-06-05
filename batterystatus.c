#define BATT_NOW        "/sys/class/power_supply/BAT0/capacity"
#define BATT_STATUS       "/sys/class/power_supply/BAT0/status"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

struct bat {

	int charge;
	char status;
};

typedef struct bat bat;

bat *
getbattery(){
    
    int curr_charge = 0;
    char *status = malloc(sizeof(char)*12);
    char s = '?';    
    FILE *fp = NULL;
    
    if ((fp = fopen(BATT_NOW, "r"))) {
        
	fscanf(fp, "%d\n", &curr_charge);
        fclose(fp);
        
        fp = fopen(BATT_STATUS, "r");
        fscanf(fp, "%s\n", status);
        fclose(fp);

        if (strcmp(status,"Charging") == 0)
            s = '+';
        if (strcmp(status,"Discharging") == 0)
            s = '-';
        if (strcmp(status,"Full") == 0)
            s = '=';
    }

    bat *curr_bat = (bat*)malloc(sizeof(bat));

    curr_bat->charge = curr_charge;
    curr_bat->status = s;

    return curr_bat;
}


int main() {

	bat *curr_bat = getbattery();
	
	printf("%d(%c)", curr_bat->charge, curr_bat->status);
	
	return 0;
}
