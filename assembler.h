#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 


#define MAX_LINE_LENGTH 81
#define MAX_LABEL_LENGTH 30
#define AM_FILE ".am"



/*Uses for the labels table*/
enum {ENTRY, EXTERNAL, DATA};
typedef enum {false, true} bool;


/*
A linked list of macros.
*/
typedef struct macro *ptr_macro;
typedef struct macro{
    char *macro_id; /*Number of the macro*/
    char *macro_content; /*Content of the macro*/

    ptr_macro next;
}macro;


/*
A linked list of labels.
*/
typedef struct label *ptr_label;
typedef struct label{
    char name[MAX_LABEL_LENGTH];/*Label name*/
    int type; /*Options: 0 == ENTRY, 1 == EXTERNAL, 2 == DATA*/
    int dec_address; /*Decimal address*/

    ptr_label next;

}label;


/*
A linked list of unknown labels in the orders_table.
Assists to complete the orders_table in second step.
*/
typedef struct labelApearance *ptr_label_apearence;
typedef struct labelApearance{
    char name[MAX_LABEL_LENGTH];/*Label name*/
    int index_in_orders_table;
    /*Contains the index of unknown label line at the first step*/

    ptr_label_apearence next;

}labelApearance;


/*
A structure of multiple types of variables.
Assists to save and move variables from first step to second step.
*/
typedef struct multiVars{
    ptr_label head_label;
    ptr_label_apearence head_label_apear;
    unsigned int *orders_table;
    unsigned int *data_table;
    int IC;/*Instruction counter*/
    int DC;/*Data counter*/

    bool there_is_error_flag;

}multiVars;



/*Functions of file 'preAssembler.c'*/
bool pre_assembler(FILE *, char *);
long int find_word(char *word, FILE *);


/*Functions of file 'macro.c'*/
ptr_macro add_macro(char *);
ptr_macro get_macro_by_id(char *);
void print_macro_list();
void free_macro_list();


/*Functions of file 'firsStep.c'*/
multiVars* first_step();
int find_opcode(char *);
int find_group(int IC, int , ptr_label, ptr_label_apearence);


/*Function of file 'secondStep.c'*/
void second_step(multiVars *);


/*Functions of file 'utils.c'*/
int is_register(char *);
char** is_struct(char *);
void realloc_check(int , unsigned int *);
bool is_saved_words(char *);
bool alphanumeric_str(char *);

/*Functions of file 'lines.c'*/
int insert_order(int , unsigned long , char *, char *, ptr_label, ptr_label_apearence);
int create_order_line(int , unsigned long , long , long , unsigned int *);
int create_registers_line(int , int , int , unsigned int *);
int create_value_line(char *, int , unsigned int *);
int create_index_line(int , int , unsigned int *);
int create_unknown_line(int , unsigned int *, char *, ptr_label_apearence );
int create_data_line(int , char *, unsigned int *, char *);
void create_zero_line(unsigned int *, int DC);


/*Functions of file 'converting.c'*/
unsigned long convertDtoB(int);
int convertBtoD(unsigned long);
char* reverstr(char [], int);
char* convertDtoB32(int);


/*Functions of file 'label.c'*/
bool insert_new_label(char *, int , int , ptr_label , ptr_label );
bool label_exists(char *, ptr_label );
bool valid_label_name(char *);


/*Functions of file 'writeFiles.c'*/
void write_files(char *, multiVars *);
void write_ob_file(char *, multiVars *);
void write_ext_ent_files(char *, multiVars *);



/*Functions of file 'free.c'*/
void free_lists(multiVars *);
void free_label_list(multiVars *);
void free_labelApearence_list(multiVars *);
void free_data_table();
void free_orders_table(multiVars *);