#include "hash.h"
#include "vec.h"

#ifndef DATABASE_H
#define DATABASE_H

/* type definitions */
typedef struct Column {
  char *name;
} Column;

typedef struct Row {
  hash_t *cells;
  int num_cells;
} Row;

typedef vec_t(Row*) row_vec_t;

typedef struct Table {
  char *name;
  hash_t *columns;
  row_vec_t *rows;
} Table;

/* function headers */
void init_db();
void free_db();
int find_table_index(char *table_name);
Table *find_table(char *table_name);
Column *find_column(Table *table, char *column_name);
int create_table(char *name);
int drop_table(char *name);
int add_column(Table *table, char *column_name);
int drop_column(Column *column);
int drop_row(Row *row);
int insert_into(char *table_name, char *column_names[], char *values[], int num_values);
/* returns pointer to a cell hash which has to be appropriately freed! */
hash_t *select_from(char *column_names[], int num_columns, char *table_name, int row_index);
int list_columns(Table *table);
int list_tables();
int where_equals(char *table_name, char *column_name, char *value);

#endif
