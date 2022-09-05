#define BATT_NOW        "/sys/class/power_supply/BAT0/capacity"
#define BATT_STATUS       "/sys/class/power_supply/BAT0/status"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

typedef struct bat {
	int charge;
	char* symbol;
} bat;

char*
getbatsymbol(int charge, int isCharging) {
    char* symbol = NULL;

    if (isCharging == 1)
        symbol = "";
    else if (charge >= 85)
        symbol = "";
    else if (charge >= 25)
        symbol = "";
    else if (charge >= 10)
        symbol = "";
    else
        symbol = "";

    return symbol;
}

bat*
getbattery() {
    
    int curr_charge = 0;
    char *status = malloc(sizeof(char)*12);
    // char s = '?';
    FILE *fp = NULL;
    int isCharging = 0;
    
    if ((fp = fopen(BATT_NOW, "r"))) {
        
        fscanf(fp, "%d\n", &curr_charge);
        fclose(fp);
        
        fp = fopen(BATT_STATUS, "r");
        fscanf(fp, "%s\n", status);
        fclose(fp);

        if (strcmp(status,"Charging") == 0)
            isCharging = 1;
    }

    bat *curr_bat = (bat*)malloc(sizeof(bat));

    curr_bat->charge = curr_charge;
    curr_bat->symbol = getbatsymbol(curr_bat->charge, isCharging);

    return curr_bat;
}


int main() {
	bat *curr_bat = getbattery();
	printf("%s %d", curr_bat->symbol, curr_bat->charge);
	
	return 0;
}
