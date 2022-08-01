#include "constants.h"
#include "secondStep.h"
#include "converting.h"


/*The second step of the Assembler*/
void second_step(multiVars *vars){
	int index;
	char *label_name;

	/* Pointers to temporery labelApearance and label_table */
	ptr_label_apearence temp_label_apear;
	ptr_label temp_label;

    temp_label = (ptr_label) malloc(sizeof(label));
	temp_label_apear = (ptr_label_apearence) malloc(sizeof(labelApearance));

	label_name = NULL;	

	if(!temp_label_apear || !temp_label){
		printf("Memory allocation failed\n");
		exit(0);
	}

	temp_label = vars->head_label;
	temp_label_apear = vars->head_label_apear;
	
	/*While it is not the end of the list*/
	for(index = 0; !vars->commands_table[index]; index++){
		/*Finds the lines without binary code*/
		if(vars->commands_table[index] == '?'){
			/* Finds the name of label */
			temp_label_apear = vars->head_label_apear;
			while (temp_label_apear){
				if((temp_label_apear->index_in_commands_table) != index)
					temp_label_apear = temp_label_apear->next;
				else{
					strcpy(label_name, temp_label_apear->name);
					continue;
                }
			}

			/* Finds the eddress of the label */
			temp_label = vars->head_label;
            /* Finds the address of the label and replace the '?' by it*/
			while(temp_label){
				/*If temp_label->name != label_name*/
				if(strcmp(temp_label->name, label_name))
      				temp_label = temp_label->next;
      			else{/*If they are equals*/
      				vars->commands_table[index] = convertDtoB(temp_label->dec_address);
      				continue;
                }
      		}

		}
	}

	free(temp_label);
	free(temp_label_apear);
}

