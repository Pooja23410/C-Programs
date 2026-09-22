#include <stdio.h>

#define NORMAL 0
#define WARNING 1
#define CRITICAL 2

int check_temperature(float temperature)
{
    if (temperature > 85)
        return CRITICAL;
    else if (temperature > 70)
        return WARNING;
    else
        return NORMAL;
}

int check_voltage(float voltage)
{
    if (voltage < 3.0 || voltage > 5.5)
        return CRITICAL;
    else if (voltage < 3.3 || voltage > 5.0)
        return WARNING;
    else
        return NORMAL;
}

int check_current(float current)
{
    if (current > 3.0)
        return CRITICAL;
    else if (current > 2.0)
        return WARNING;
    else
        return NORMAL;
}

int check_memory(float memory)
{
    if (memory > 85)
        return CRITICAL;
    else if (memory > 70)
        return WARNING;
    else
        return NORMAL;
}

int check_cpu(float cpu)
{
    if (cpu > 85)
        return CRITICAL;
    else if (cpu > 70)
        return WARNING;
    else
        return NORMAL;
}

int check_battery(float battery)
{
    if (battery < 20)
        return CRITICAL;
    else if (battery < 50)
        return WARNING;
    else
        return NORMAL;
}

void display_status(int status)
{
    if (status == NORMAL)
        printf("NORMAL");
    else if (status == WARNING)
        printf("WARNING");
    else
        printf("CRITICAL");
}

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

int main()
{
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

    printf("======================================================\n");
    printf("       EMBEDDED DEVICE HEALTH MONITORING SYSTEM\n");
    printf("======================================================\n");

    printf("\nEnter Device Parameters\n");
    printf("------------------------\n");

    printf("Temperature (C): ");
    scanf("%f", &temperature);

    printf("Voltage (V): ");
    scanf("%f", &voltage);

    printf("Current (A): ");
    scanf("%f", &current);

    printf("Memory Usage (%%): ");
    scanf("%f", &memory);

    printf("CPU Usage (%%): ");
    scanf("%f", &cpu);

    printf("Battery Level (%%): ");
    scanf("%f", &battery);

    temperature_status = check_temperature(temperature);
    voltage_status = check_voltage(voltage);
    current_status = check_current(current);
    memory_status = check_memory(memory);
    cpu_status = check_cpu(cpu);
    battery_status = check_battery(battery);

    overall_status = get_overall_status(
        temperature_status,
        voltage_status,
        current_status,
        memory_status,
        cpu_status,
        battery_status
    );

    printf("\n====================================================\n");
    printf("              DEVICE HEALTH REPORT\n");
    printf("====================================================\n");

    printf("Temperature : %.2f C     Status: ", temperature);
    display_status(temperature_status);
    printf("\n");

    printf("Voltage     : %.2f V     Status: ", voltage);
    display_status(voltage_status);
    printf("\n");

    printf("Current     : %.2f A     Status: ", current);
    display_status(current_status);
    printf("\n");

    printf("Memory      : %.2f %%     Status: ", memory);
    display_status(memory_status);
    printf("\n");

    printf("CPU Usage   : %.2f %%     Status: ", cpu);
    display_status(cpu_status);
    printf("\n");

    printf("Battery     : %.2f %%     Status: ", battery);
    display_status(battery_status);
    printf("\n");

    printf("----------------------------------------------------\n");

    printf("Device Status: ");
    display_status(overall_status);
    printf("\n");

    printf("====================================================\n");

    if (overall_status == NORMAL)
    {
        printf("Device is operating within normal conditions.\n");
    }
    else if (overall_status == WARNING)
    {
        printf("Warning: One or more parameters require attention.\n");
    }
    else
    {
        printf("Critical: Immediate attention is required.\n");
    }

    return 0;
}
