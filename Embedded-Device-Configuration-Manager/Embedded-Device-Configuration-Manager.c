#include <stdio.h>
#include <string.h>

#define MAX_DEVICES 100

/* Operating modes */
enum OperatingMode
{
    NORMAL = 1,
    POWER_SAVE,
    MAINTENANCE
};

/* Communication modes */
enum CommunicationMode
{
    UART = 1,
    SPI,
    I2C,
    CAN
};

/* Device configuration structure */
struct DeviceConfig
{
    int device_id;
    char firmware_version[20];
    int sampling_rate;

    enum OperatingMode operating_mode;

    float temperature_limit;
    float voltage_limit;

    enum CommunicationMode communication_mode;

    unsigned char status_flags;
};


/* Display operating mode */
void display_operating_mode(enum OperatingMode mode)
{
    if (mode == NORMAL)
        printf("Normal");
    else if (mode == POWER_SAVE)
        printf("Power Save");
    else if (mode == MAINTENANCE)
        printf("Maintenance");
    else
        printf("Invalid");
}


/* Display communication mode */
void display_communication_mode(enum CommunicationMode mode)
{
    if (mode == UART)
        printf("UART");
    else if (mode == SPI)
        printf("SPI");
    else if (mode == I2C)
        printf("I2C");
    else if (mode == CAN)
        printf("CAN");
    else
        printf("Invalid");
}


/* Set a new device configuration */
void set_configuration(struct DeviceConfig *config)
{
    int choice;

    printf("\n===============================================\n");
    printf("           SET DEVICE CONFIGURATION\n");
    printf("===============================================\n");

    printf("Enter Device ID: ");
    scanf("%d", &config->device_id);

    printf("Enter Firmware Version: ");
    scanf("%19s", config->firmware_version);

    printf("Enter Sampling Rate (Hz): ");
    scanf("%d", &config->sampling_rate);

    printf("\nOperating Mode\n");
    printf("1. Normal\n");
    printf("2. Power Save\n");
    printf("3. Maintenance\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3)
    {
        config->operating_mode = choice;
    }
    else
    {
        printf("Invalid operating mode.\n");
        config->operating_mode = 0;
    }

    printf("\nEnter Temperature Limit (C): ");
    scanf("%f", &config->temperature_limit);

    printf("Enter Voltage Limit (V): ");
    scanf("%f", &config->voltage_limit);

    printf("\nCommunication Mode\n");
    printf("1. UART\n");
    printf("2. SPI\n");
    printf("3. I2C\n");
    printf("4. CAN\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 4)
    {
        config->communication_mode = choice;
    }
    else
    {
        printf("Invalid communication mode.\n");
        config->communication_mode = 0;
    }

    config->status_flags = 0;

    printf("\n[INFO] Device configuration added successfully.\n");
}


/* Display one device configuration */
void display_one_configuration(struct DeviceConfig *config, int number)
{
    printf("\n-----------------------------------------------\n");
    printf("              DEVICE %d\n", number);
    printf("-----------------------------------------------\n");

    printf("Device ID          : %d\n",
           config->device_id);

    printf("Firmware Version   : %s\n",
           config->firmware_version);

    printf("Sampling Rate      : %d Hz\n",
           config->sampling_rate);

    printf("Operating Mode     : ");
    display_operating_mode(config->operating_mode);
    printf("\n");

    printf("Temperature Limit  : %.2f C\n",
           config->temperature_limit);

    printf("Voltage Limit      : %.2f V\n",
           config->voltage_limit);

    printf("Communication Mode : ");
    display_communication_mode(config->communication_mode);
    printf("\n");

    printf("Status Flags       : 0x%02X\n",
           config->status_flags);
}


/* Display all configurations */
void display_all_configurations(struct DeviceConfig config[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\n[INFO] No device configurations available.\n");
        return;
    }

    printf("\n===============================================\n");
    printf("          ALL DEVICE CONFIGURATIONS\n");
    printf("===============================================\n");

    printf("Total Devices: %d\n", count);

    for (i = 0; i < count; i++)
    {
        display_one_configuration(&config[i], i + 1);
    }

    printf("\n===============================================\n");
}


/* Validate one configuration */
void validate_configuration(struct DeviceConfig *config)
{
    config->status_flags = 0;

    printf("\n===============================================\n");
    printf("          VALIDATING CONFIGURATION\n");
    printf("===============================================\n");

    /* Bit 0 - Device ID */
    if (config->device_id > 0)
    {
        printf("[CHECK] Device ID................. OK\n");
        config->status_flags |= (1 << 0);
    }
    else
    {
        printf("[CHECK] Device ID................. FAILED\n");
    }


    /* Bit 1 - Firmware Version */
    if (strlen(config->firmware_version) > 0)
    {
        printf("[CHECK] Firmware Version.......... OK\n");
        config->status_flags |= (1 << 1);
    }
    else
    {
        printf("[CHECK] Firmware Version.......... FAILED\n");
    }


    /* Bit 2 - Sampling Rate */
    if (config->sampling_rate >= 1 &&
        config->sampling_rate <= 1000)
    {
        printf("[CHECK] Sampling Rate............. OK\n");
        config->status_flags |= (1 << 2);
    }
    else
    {
        printf("[CHECK] Sampling Rate............. FAILED\n");
    }


    /* Bit 3 - Temperature Limit */
    if (config->temperature_limit >= -40 &&
        config->temperature_limit <= 125)
    {
        printf("[CHECK] Temperature Limit......... OK\n");
        config->status_flags |= (1 << 3);
    }
    else
    {
        printf("[CHECK] Temperature Limit......... FAILED\n");
    }


    /* Bit 4 - Voltage Limit */
    if (config->voltage_limit >= 1 &&
        config->voltage_limit <= 24)
    {
        printf("[CHECK] Voltage Limit............. OK\n");
        config->status_flags |= (1 << 4);
    }
    else
    {
        printf("[CHECK] Voltage Limit............. FAILED\n");
    }


    /* Bit 5 - Communication Mode */
    if (config->communication_mode >= UART &&
        config->communication_mode <= CAN)
    {
        printf("[CHECK] Communication Mode........ OK\n");
        config->status_flags |= (1 << 5);
    }
    else
    {
        printf("[CHECK] Communication Mode........ FAILED\n");
    }


    printf("\nStatus Flags : 0x%02X\n",
           config->status_flags);

    if (config->status_flags == 0x3F)
    {
        printf("Configuration Status : VALID\n");
    }
    else
    {
        printf("Configuration Status : INVALID\n");
    }

    printf("===============================================\n");
}


/* Validate all configurations */
void validate_all_configurations(struct DeviceConfig config[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\n[INFO] No configurations available.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("\n\nValidating Device %d\n", i + 1);

        validate_configuration(&config[i]);
    }
}


/* Modify a configuration */
void modify_configuration(struct DeviceConfig config[], int count)
{
    int device_number;
    int choice;
    int value;

    if (count == 0)
    {
        printf("\n[INFO] No configurations available to modify.\n");
        return;
    }

    printf("\n===============================================\n");
    printf("             MODIFY CONFIGURATION\n");
    printf("===============================================\n");

    printf("Available Devices:\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d. Device ID: %d\n",
               i + 1,
               config[i].device_id);
    }

    printf("\nEnter device number to modify: ");
    scanf("%d", &device_number);

    if (device_number < 1 || device_number > count)
    {
        printf("[ERROR] Invalid device number.\n");
        return;
    }

    device_number--;

    printf("\nSelect parameter to modify:\n");

    printf("1. Device ID\n");
    printf("2. Firmware Version\n");
    printf("3. Sampling Rate\n");
    printf("4. Operating Mode\n");
    printf("5. Temperature Limit\n");
    printf("6. Voltage Limit\n");
    printf("7. Communication Mode\n");

    printf("\nEnter parameter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:

            printf("Enter new Device ID: ");
            scanf("%d", &config[device_number].device_id);

            printf("[INFO] Device ID updated successfully.\n");

            break;


        case 2:

            printf("Enter new Firmware Version: ");
            scanf("%19s",
                  config[device_number].firmware_version);

            printf("[INFO] Firmware Version updated successfully.\n");

            break;


        case 3:

            printf("Enter new Sampling Rate (Hz): ");
            scanf("%d",
                  &config[device_number].sampling_rate);

            printf("[INFO] Sampling Rate updated successfully.\n");

            break;


        case 4:

            printf("\nOperating Mode\n");
            printf("1. Normal\n");
            printf("2. Power Save\n");
            printf("3. Maintenance\n");

            printf("Enter choice: ");
            scanf("%d", &value);

            if (value >= 1 && value <= 3)
            {
                config[device_number].operating_mode = value;

                printf("[INFO] Operating Mode updated successfully.\n");
            }
            else
            {
                printf("[ERROR] Invalid Operating Mode.\n");
            }

            break;


        case 5:

            printf("Enter new Temperature Limit (C): ");
            scanf("%f",
                  &config[device_number].temperature_limit);

            printf("[INFO] Temperature Limit updated successfully.\n");

            break;


        case 6:

            printf("Enter new Voltage Limit (V): ");
            scanf("%f",
                  &config[device_number].voltage_limit);

            printf("[INFO] Voltage Limit updated successfully.\n");

            break;


        case 7:

            printf("\nCommunication Mode\n");
            printf("1. UART\n");
            printf("2. SPI\n");
            printf("3. I2C\n");
            printf("4. CAN\n");

            printf("Enter choice: ");
            scanf("%d", &value);

            if (value >= 1 && value <= 4)
            {
                config[device_number].communication_mode = value;

                printf("[INFO] Communication Mode updated successfully.\n");
            }
            else
            {
                printf("[ERROR] Invalid Communication Mode.\n");
            }

            break;


        default:

            printf("[ERROR] Invalid parameter choice.\n");

            break;
    }
}


/* Reset one configuration */
void reset_configuration(struct DeviceConfig config[], int *count)
{
    int device_number;

    if (*count == 0)
    {
        printf("\n[INFO] No configurations available.\n");
        return;
    }

    printf("\n===============================================\n");
    printf("              RESET CONFIGURATION\n");
    printf("===============================================\n");

    printf("Available Devices:\n");

    for (int i = 0; i < *count; i++)
    {
        printf("%d. Device ID: %d\n",
               i + 1,
               config[i].device_id);
    }

    printf("\nEnter device number to reset: ");
    scanf("%d", &device_number);

    if (device_number < 1 || device_number > *count)
    {
        printf("[ERROR] Invalid device number.\n");
        return;
    }

    device_number--;

    /*
       Remove the selected configuration by shifting
       the remaining configurations one position left.
    */
    for (int i = device_number; i < *count - 1; i++)
    {
        config[i] = config[i + 1];
    }

    (*count)--;

    printf("\n[INFO] Device configuration reset successfully.\n");
}


/* Main function */
int main()
{
    struct DeviceConfig config[MAX_DEVICES];

    int count = 0;
    int choice;

    while (1)
    {
        printf("\n\n");
        printf("======================================================\n");
        printf("      EMBEDDED DEVICE CONFIGURATION MANAGER v1.0 \n");
        printf("======================================================\n");

        printf("1. Set Configuration\n");
        printf("2. Modify Configuration\n");
        printf("3. Display All Configurations\n");
        printf("4. Validate Configuration\n");
        printf("5. Reset Configuration\n");
        printf("6. Exit\n");

        printf("-----------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1:

                if (count >= MAX_DEVICES)
                {
                    printf("\n[ERROR] Maximum device limit reached.\n");
                }
                else
                {
                    set_configuration(&config[count]);

                    count++;
                }

                break;


            case 2:

                modify_configuration(config, count);

                break;


            case 3:

                display_all_configurations(config, count);

                break;


            case 4:

                validate_all_configurations(config, count);

                break;


            case 5:

                reset_configuration(config, &count);

                break;


            case 6:

                printf("\n");
                printf("==================================================\n");
                printf(" Configuration management completed successfully.\n");
                printf("==================================================\n");

                return 0;


            default:

                printf("\n[ERROR] Invalid choice. Please try again.\n");

                break;
        }
    }

    return 0;
}
