#include <stdio.h>

#define MAX_READINGS 20

typedef struct {
    int id;
    float temperature;
    float humidity;
    float pressure;
    float battery;
    int status;
} SensorData;

int check_status(float temp, float humidity, float pressure, float battery) {
    if (temp > 40 || humidity > 80 || pressure < 950 || pressure > 1050 || battery < 3.0)
        return 2;  // CRITICAL

    if (temp > 35 || humidity > 70 || pressure < 980 || pressure > 1030 || battery < 3.5)
        return 1;  // WARNING

    return 0;      // NORMAL
}

void display_status(int status) {
    if (status == 0)
        printf("NORMAL");
    else if (status == 1)
        printf("WARNING");
    else
        printf("CRITICAL");
}

void display_log(SensorData data[], int n) {
    printf("\n--------------- SENSOR DATA LOG ---------------\n");
    printf("ID   Temp    Humidity   Pressure   Battery   Status\n");

    for (int i = 0; i < n; i++) {
        printf("%-4d %-7.1f %-10.1f %-10.1f %-9.1f",
               data[i].id,
               data[i].temperature,
               data[i].humidity,
               data[i].pressure,
               data[i].battery);

        display_status(data[i].status);
        printf("\n");
    }
}

void display_statistics(SensorData data[], int n) {
    float temp_sum = 0, humidity_sum = 0;
    float temp_min = data[0].temperature;
    float temp_max = data[0].temperature;
    int normal = 0, warning = 0, critical = 0;

    for (int i = 0; i < n; i++) {
        temp_sum += data[i].temperature;
        humidity_sum += data[i].humidity;

        if (data[i].temperature < temp_min)
            temp_min = data[i].temperature;

        if (data[i].temperature > temp_max)
            temp_max = data[i].temperature;

        if (data[i].status == 0)
            normal++;
        else if (data[i].status == 1)
            warning++;
        else
            critical++;
    }

    printf("\n--------------- STATISTICS --------------------\n");
    printf("Minimum Temperature : %.1f C\n", temp_min);
    printf("Maximum Temperature : %.1f C\n", temp_max);
    printf("Average Temperature : %.1f C\n", temp_sum / n);
    printf("Average Humidity    : %.1f %%\n", humidity_sum / n);

    printf("\nReading Status:\n");
    printf("NORMAL   : %d\n", normal);
    printf("WARNING  : %d\n", warning);
    printf("CRITICAL : %d\n", critical);
}

int main() {
    SensorData data[MAX_READINGS];
    int n;

    printf("===== SENSOR DATA LOGGER IN C =====\n");

    printf("Enter number of readings (1-%d): ", MAX_READINGS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_READINGS) {
        printf("Invalid number of readings.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        data[i].id = i + 1;

        printf("\nReading %d\n", i + 1);

        printf("Temperature (C): ");
        scanf("%f", &data[i].temperature);

        printf("Humidity (%%): ");
        scanf("%f", &data[i].humidity);

        printf("Pressure (hPa): ");
        scanf("%f", &data[i].pressure);

        printf("Battery (V): ");
        scanf("%f", &data[i].battery);

        /* Basic input validation */
        if (data[i].temperature < -50 || data[i].temperature > 100 ||
            data[i].humidity < 0 || data[i].humidity > 100 ||
            data[i].pressure < 800 || data[i].pressure > 1200 ||
            data[i].battery < 0 || data[i].battery > 5) {

            printf("Invalid sensor reading. Please enter valid values.\n");
            i--;
            continue;
        }

        data[i].status = check_status(
            data[i].temperature,
            data[i].humidity,
            data[i].pressure,
            data[i].battery
        );
    }

    display_log(data, n);
    display_statistics(data, n);

    return 0;
}
