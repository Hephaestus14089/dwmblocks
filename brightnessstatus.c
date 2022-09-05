#define TOTAL       "/sys/class/backlight/intel_backlight/max_brightness"
#define CURRENT     "/sys/class/backlight/intel_backlight/actual_brightness"

#include <stdio.h>

int
get_brightness() {
    float curr_brightness = 0.0;
    float total_brightness = 0.0;

    FILE *fp = NULL;

    if ((fp = fopen(TOTAL, "r"))) {

        fscanf(fp, "%d\n", &total_brightness);
        fclose(fp);

        fp = fopen(CURRENT, "r");
        fscanf(fp, "%d\n", &curr_brightness);
        fclose(fp);
    }

    float brightness_percent = (curr_brightness / total_brightness) * 100;
    return (int)brightness_percent;
}

int
main() {
    int brightness = get_brightness();
    printf("%d", brightness);
    return 0;
}
