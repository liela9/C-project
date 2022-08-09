#ifndef WRITE_FILES_H
#define WRITE_FILES_H

#define ENT_EXTENSION ".ent"
#define EXT_EXTENSION ".ext"
#define OB_EXTENSION ".ob"

/*Functions of file 'writeFiles.c'*/
bool write_files(char *, multiVars *);
bool write_ob_file(char *, multiVars *);
bool write_ext_ent_files(char *, multiVars *);
void add_line_to_ob(int , unsigned long , FILE *);

#endif
