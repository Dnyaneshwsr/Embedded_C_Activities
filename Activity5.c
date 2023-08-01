#include <stdio.h>
#include <string.h>

// Define a structure to hold sensor data
typedef struct {
    char sensor_id[10];
    float temperature;
    int humidity;
    int light_intensity;
} SensorData;

// Function to parse the ASCII data and populate the structure fields
void parse_data(const char* data, SensorData* sensor) {
    // Format of the ASCII data: "S1-T:36.5-H:100-L:50"
    sscanf(data, "%[^-]-T:%f-H:%d-L:%d", sensor->sensor_id, &sensor->temperature,
           &sensor->humidity, &sensor->light_intensity);
}

int main() {
    const char* ascii_data = "S1-T:36.5-H:100-L:50";
    SensorData sensor;

    // Parse the ASCII data and populate the structure fields
    parse_data(ascii_data, &sensor);

    // Display the parsed data in the desired format
    printf("Sensor Info:\n");
    printf("_____________________\n");
    printf("Sensor ID: %s\n", sensor.sensor_id);
    printf("Temperature: %.1f C\n", sensor.temperature);
    printf("Humidity: %d\n", sensor.humidity);
    printf("Light Intensity: %d%%\n", sensor.light_intensity);

    return 0;
}
