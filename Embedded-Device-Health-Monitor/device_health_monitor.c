#include <stdio.h>

#define NORMAL 0
#define WARNING 1
#define CRITICAL 2
#define MAX_DEVICES 10

/* Structure to store device information */
struct Device
{
    int device_id;

    float temperature;
    float voltage;
    float current;
    float memory;
    float cpu;
    float battery;

    int temperature_status;
    int voltage_status;
    int current_status;
    int memory_status;
    int cpu_status;
    int battery_status;

    int overall_status;
};

/* Check temperature */
int check_temperature(float temperature)
{
    if (temperature > 85)
        return CRITICAL;
    else if (temperature > 70)
        return WARNING;
    else
        return NORMAL;
}

/* Check voltage */
int check_voltage(float voltage)
{
    if (voltage < 3.0 || voltage > 5.5)
        return CRITICAL;
    else if (voltage < 3.3 || voltage > 5.0)
        return WARNING;
    else
        return NORMAL;
}

/* Check current */
int check_current(float current)
{
    if (current > 3.0)
        return CRITICAL;
    else if (current > 2.0)
        return WARNING;
    else
        return NORMAL;
}

/* Check memory usage */
int check_memory(float memory)
{
    if (memory > 85)
        return CRITICAL;
    else if (memory > 70)
        return WARNING;
    else
        return NORMAL;
}

/* Check CPU usage */
int check_cpu(float cpu)
{
    if (cpu > 85)
        return CRITICAL;
    else if (cpu > 70)
        return WARNING;
    else
        return NORMAL;
}

/* Check battery level */
int check_battery(float battery)
{
    if (battery < 20)
        return CRITICAL;
    else if (battery < 50)
        return WARNING;
    else
        return NORMAL;
}

/* Display status */
void display_status(int status)
{
    if (status == NORMAL)
        printf("NORMAL");
    else if (status == WARNING)
        printf("WARNING");
    else
        printf("CRITICAL");
}

/* Find highest severity */
int get_overall_status(int status1, int status2, int status3,
                       int status4, int status5, int status6)
{
    int overall_status = NORMAL;

    if (status1 > overall_status)
        overall_status = status1;

    if (status2 > overall_status)
        overall_status = status2;

    if (status3 > overall_status)
        overall_status = status3;

    if (status4 > overall_status)
        overall_status = status4;

    if (status5 > overall_status)
        overall_status = status5;

    if (status6 > overall_status)
        overall_status = status6;

    return overall_status;
}

/* Collect and check one device */
void monitor_device(struct Device *device)
{
    printf("\n----------------------------------------------\n");
    printf("Enter Parameters for Device %d\n", device->device_id);
    printf("----------------------------------------------\n");

    printf("Temperature (C): ");
    scanf("%f", &device->temperature);

    printf("Voltage (V): ");
    scanf("%f", &device->voltage);

    printf("Current (A): ");
    scanf("%f", &device->current);

    printf("Memory Usage (%%): ");
    scanf("%f", &device->memory);

    printf("CPU Usage (%%): ");
    scanf("%f", &device->cpu);

    printf("Battery Level (%%): ");
    scanf("%f", &device->battery);

    /* Check every parameter */
    device->temperature_status =
        check_temperature(device->temperature);

    device->voltage_status =
        check_voltage(device->voltage);

    device->current_status =
        check_current(device->current);

    device->memory_status =
        check_memory(device->memory);

    device->cpu_status =
        check_cpu(device->cpu);

    device->battery_status =
        check_battery(device->battery);

    /* Calculate overall device status */
    device->overall_status = get_overall_status(
        device->temperature_status,
        device->voltage_status,
        device->current_status,
        device->memory_status,
        device->cpu_status,
        device->battery_status
    );

    printf("Device %d data recorded successfully.\n",
           device->device_id);
}

/* Display complete report for one device */
void display_device_report(struct Device device)
{
    printf("\n====================================================\n");
    printf("                 DEVICE %d REPORT\n", device.device_id);
    printf("====================================================\n");

    printf("Temperature : %.2f C     Status: ",
           device.temperature);
    display_status(device.temperature_status);
    printf("\n");

    printf("Voltage     : %.2f V     Status: ",
           device.voltage);
    display_status(device.voltage_status);
    printf("\n");

    printf("Current     : %.2f A     Status: ",
           device.current);
    display_status(device.current_status);
    printf("\n");

    printf("Memory      : %.2f %%     Status: ",
           device.memory);
    display_status(device.memory_status);
    printf("\n");

    printf("CPU Usage   : %.2f %%     Status: ",
           device.cpu);
    display_status(device.cpu_status);
    printf("\n");

    printf("Battery     : %.2f %%     Status: ",
           device.battery);
    display_status(device.battery_status);
    printf("\n");

    printf("----------------------------------------------------\n");

    printf("Device Status: ");
    display_status(device.overall_status);
    printf("\n");

    if (device.overall_status == NORMAL)
    {
        printf("Device is operating within normal conditions.\n");
    }
    else if (device.overall_status == WARNING)
    {
        printf("Warning: One or more parameters require attention.\n");
    }
    else
    {
        printf("Critical: Immediate attention is required.\n");
    }

    printf("====================================================\n");
}

int main()
{
    struct Device devices[MAX_DEVICES];

    int number_of_devices;
    int i;

    printf("======================================================\n");
    printf("       EMBEDDED DEVICE HEALTH MONITORING SYSTEM\n");
    printf("======================================================\n");

    printf("\nEnter number of devices to monitor (1-%d): ",
           MAX_DEVICES);
    scanf("%d", &number_of_devices);

    /* Validate number of devices */
    if (number_of_devices < 1 ||
        number_of_devices > MAX_DEVICES)
    {
        printf("\nInvalid number of devices.\n");
        printf("Please enter a value between 1 and %d.\n",
               MAX_DEVICES);
        return 0;
    }

    /* Monitor devices one by one */
    for (i = 0; i < number_of_devices; i++)
    {
        devices[i].device_id = i + 1;

        monitor_device(&devices[i]);
    }

    /* Display all results at the end */
    printf("\n\n");
    printf("######################################################\n");
    printf("              FINAL DEVICE HEALTH REPORT\n");
    printf("######################################################\n");

    for (i = 0; i < number_of_devices; i++)
    {
        display_device_report(devices[i]);
    }

    printf("\n======================================================\n");
    printf("          ALL DEVICE RESULTS DISPLAYED\n");
    printf("======================================================\n");

    return 0;
}
