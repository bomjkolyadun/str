/* === V1 ===                                                                 */
/* Simple and optimized for space. No extra memory is allocated.              */
/* Returns NULL on illegal input and on allocation errors.                    */
/* Best usecase: Short strings or string with large variance of sizes.        */

#include <stdlib.h>
#include <string.h>

void str_free(char** ptr) {
  if (ptr) free(*ptr);
}
 
char* str_cpy(char** dest, const char* source) {
  if (!dest) return NULL;
  if (source && *dest != source) {
    size_t src_size = strlen(source) + 1;
    char* result = malloc(src_size);
    if (!result) return NULL;
    result = memcpy(result, source, src_size);
    str_free(dest);
    *dest = result;
  }
  return *dest;
}
 
char* str_cat(char** dest, const char* source) {
  if (!dest) return NULL;
  if (!*dest) return str_cpy(dest, source);
  if (source) {
    char* orig_dest = *dest;
    size_t src_size = strlen(source) + 1;
    size_t dst_len = strlen(orig_dest);
    if (*dest = realloc(orig_dest, dst_len + src_size)) {
      if (source >= orig_dest && source <= orig_dest + dst_len)
        source += *dest - orig_dest;
      memcpy(*dest + dst_len, source, src_size);
    }
  }
  return *dest;
}