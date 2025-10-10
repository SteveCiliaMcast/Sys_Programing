#include <stdio.h>
#include <string.h>

typedef struct {
    char first_name[51];
    char last_name[51];
    int age;
    double height_cm;
} Person;

static void read_line(char *buffer, size_t size);
static void discard_remaining_input(void);

int main(void) {
    Person person = {0};

    printf("Enter first name: ");
    read_line(person.first_name, sizeof(person.first_name));

    printf("Enter last name: ");
    read_line(person.last_name, sizeof(person.last_name));

    printf("Enter age: ");
    if (scanf("%d", &person.age) != 1) {
        fprintf(stderr, "Invalid input for age.\n");
        discard_remaining_input();
        return 1;
    }

    printf("Enter height in centimeters: ");
    if (scanf("%lf", &person.height_cm) != 1) {
        fprintf(stderr, "Invalid input for height.\n");
        discard_remaining_input();
        return 1;
    }
    discard_remaining_input();

    printf("\nRecorded person details:\n");
    printf("First name: %s\n", person.first_name);
    printf("Last name: %s\n", person.last_name);
    printf("Age: %d\n", person.age);
    printf("Height: %.1f cm\n", person.height_cm);

    return 0;
}

static void read_line(char *buffer, size_t size) {
    if (fgets(buffer, (int)size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    } else if (size > 0) {
        buffer[0] = '\0';
    }
}

static void discard_remaining_input(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard */
    }
}
