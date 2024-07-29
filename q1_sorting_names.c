#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_NAMES 100

/* Function prototypes */
int compare_asc(const void *a, const void *b);
int compare_desc(const void *a, const void *b);
void print_names(const char *names[], int length);
int get_names_length(const char *names[]);


/**
 * main - sort names in asc | desc order
 *
 * Task 1: You are having a function pointer that will be taking the array \
 * of names and a callback function that will be used to sort names \
 * in the chosen order.
 * Task 2: You are having a second function will count the number of \
 * names in an array.
 * Task 3: You will need to have an array of functions such that \
 * the user chooses 1 for function 1 and 2 for function 2.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(void)
{
    const char *sample_names[NUM_NAMES] = {
        "John Nshimiyimana", "Marie Uwimana", "Jean-Luc Habimana", "Claude Ndahiro", "Aline Mukamana",
        "Joseph Mutabazi", "Nadia Uwera", "Isaac Gakuba", "Pauline Nyiramana", "Patrick Mugisha",
        "Jacques Ndayisaba", "Sylvie Ingabire", "Amelie Umutesi", "Yves Nkurunziza", "Pierre Muhire",
        "Christine Kamikazi", "Michel Rutayisire", "Esther Imanizabayo", "David Mugenzi", "Alice Uwase",
        "Gerard Gasana", "Lucie Nirere", "Simon Twagirayezu", "Sophie Niyonzima", "Olivier Kayitesi",
        "Gabrielle Mukeshimana", "Emmanuel Niyigena", "Charlotte Ishimwe", "Thierry Habyarimana", "Eliane Nyiramatama",
        "Frederic Manzi", "Helene Uwimbabazi", "Marc Niyonsenga", "Suzanne Nyirahabimana", "Bernard Ntaganda",
        "Celine Niyomugabo", "Thomas Hakizimana", "Pascale Murekatete", "Julien Niyonteze", "Monique Umuhoza",
        "Pascal Mukamana", "Rachel Niragire", "Antoine Nyandwi", "Florence Niyibizi", "Bruno Mbabazi",
        "Danielle Mukamurenzi", "Alain Nshuti", "Madeleine Uwayezu", "Andre Mugabo", "Valerie Ingabire",
        "Jean-Luc Nyirimbabazi", "Claire Niyonshuti", "Dominique Mugiraneza", "Catherine Uwimbabazi", "Didier Kabera",
        "Martine Mbarubukeye", "Philippe Niyibizi", "Mireille Niyonsaba", "Christian Rwema", "Brigitte Mutesi",
        "Laurent Nkurunziza", "Agnes Uwase", "Daniel Mugisha", "Sandrine Murebwayire", "Stephane Mbonigaba",
        "Virginie Uwamahoro", "Rene Ngendahayo", "Viviane Uwimbabazi", "Alphonse Habimana", "Yvonne Nyirahabimana",
        "Claude Munyaneza", "Francine Niyonshuti", "Jean-Pierre Nkurikiyinka", "Marguerite Uwamaliya", "Etienne Mugisha",
        "Solange Nyirahabineza", "Juliette Uwimana", "Gerald Niyonteze", "Hortense Mukamurenzi", "Roger Rwanyindo",
        "Benoit Ntirenganya", "Louise Murekatete", "Fabrice Ndayambaje", "Genevieve Mukamusoni", "Cedric Uwimana",
        "Odile Mukamana", "Robert Niyomugabo", "Leontine Mukantabana", "Henri Habyarimana", "Camille Nyiramana",
        "Gilbert Niyitegeka", "Louise Mukarwema", "Maurice Uwase", "Rose Mukamana", "Arnaud Mugenzi",
        "Therese Umutesi", "Sebastien Uwiragiye", "Jacqueline Nyirabatutsi", "Charles Umugwaneza", "Claudette Nyiramana"
    };
	
    int length = get_names_length(sample_names);
    int choice;
    int (*compare_functions[])(const void *, const void *) = { compare_asc, compare_desc };

    printf("Choose sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2)
    {
        qsort(sample_names, length, sizeof(char *), compare_functions[choice - 1]);
        print_names(sample_names, length);
    }
    else
    {
        printf("Invalid choice.\n");
        return (1);
    }

    return (0);
}

/**
 * compare_asc - Compare two strings for ascending order
 * @a: Pointer to the first string
 * @b: Pointer to the second string
 *
 * Return: Negative value if a < b, 0 if a == b, positive value if a > b
 */
int compare_asc(const void *a, const void *b)
{
    return (strcmp(*(const char **)a, *(const char **)b));
}

/**
 * compare_desc - Compare two strings for descending order
 * @a: Pointer to the first string
 * @b: Pointer to the second string
 *
 * Return: Negative value if a > b, 0 if a == b, positive value if a < b
 */
int compare_desc(const void *a, const void *b)
{
    return (strcmp(*(const char **)b, *(const char **)a));
}

/**
 * print_names - Print an array of names
 * @names: Array of names
 * @length: Number of names in the array
 */
void print_names(const char *names[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%s\n", names[i]);
    }
}

/**
 * get_names_length - Compute the length of the names array
 * @names: Array of names
 *
 * Return: The number of names in the array
 */
int get_names_length(const char *names[])
{

    return (NUM_NAMES);
}
