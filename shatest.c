#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef enum {
  SUCCESS, //0
  FAILURE, //1
  ERROR,   //2
} STATUS;

STATUS sha384(size_t input_len, size_t output_len, uint8_t* input, uint8_t* output) {
    if((input == NULL) || (output == NULL)){
        return FAILURE;
    }
    if(output_len > SHA384_DIGEST_LENGTH){
        return FAILURE;
    }

    uint8_t hash_output_array[SHA384_DIGEST_LENGTH];

    SHA384(input, input_len, hash_output_array);
    memcpy(output, hash_output_array, output_len);
    return SUCCESS;
}

STATUS sha256(size_t input_len, size_t output_len, uint8_t* input, uint8_t* output) {
    if((input == NULL) || (output == NULL)){
        return FAILURE;
    }
    if(output_len > SHA256_DIGEST_LENGTH){
        return FAILURE;
    }

    uint8_t hash_output_array[SHA256_DIGEST_LENGTH];
    
    SHA256(input, input_len, hash_output_array);
    memcpy(output, hash_output_array, output_len);
    return SUCCESS;
}
