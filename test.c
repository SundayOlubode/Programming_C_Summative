#include <stdio.h>
#include <stdlib.h>

struct Array {
    void **values;
    int length;
};

#define array(elements...) ({ void *values[] = { elements }; array_make(values, sizeof(values) / sizeof(void *)); })
#define destroy(arr) ({ free(arr.values); })

struct Array array_make(void **elements, int count)
{
    struct Array ret;
    ret.values = malloc(sizeof(void *) * count);
    ret.length = count;

    for (int i = 0; i < count; i++) {
        ret.values[i] = elements[i];
    }

    return ret;
}

int main() {
    struct Array myArray = array("Hi", "There", "This", "Is", "A", "Test");

    // Use myArray
    printf("%i\n", myArray.length);

    destroy(myArray);

    return 0;
}

