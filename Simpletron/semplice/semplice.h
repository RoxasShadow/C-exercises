typedef struct {
  int symbol;
  char type;    /* 'C' (Constant), 'L' (Line), 'V' (Variable) */
  int location; /* 00-99 */
} TableEntry;

int getFileSize(FILE *file);

int getFileSize(FILE *file) {
  fseek(file, 0L, SEEK_END);
  int size = ftell(file);
  rewind(file);
  return size;
}
