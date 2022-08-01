#include "constants.h"
#include "free.h"



#define FREE(type, head)    type temp;\
                            while (head) {\
                                temp = head;\
                                head = head->next;\
                                free(temp);\
                            }
                    


/*Free all the lists in the project*/
void free_lists(multiVars *vars){

    FREE(ptr_label, vars->head_label)
    FREE(ptr_label_apearence, vars->head_label_apear)
    free(vars->data_table);
    free(vars->orders_table);
}

   
   
/*
void free_label_list(ptr_label head){
    ptr_label temp;

    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
*/   

