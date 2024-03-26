#ifndef UTILS_IRIS_GETOPT_H
#define UTILS_IRIS_GETOPT_H

#define INVALID_OPT_ARG ':'
#define INVALID_OPT_VAL '?'

/* sentinel initializer for 'struct iris_opt_result' */
#define INIT_IRIS_OPT_RESULT_INVALID {  \
        .opt_val = INVALID_OPT_VAL,     \
        .opt_arg = NULL,                \
        .last_index = -1,               \
        .opt_ind = -1                   \
}

/* sentinel initializer for 'struct iris_opt' */
#define INIT_IRIS_OPT_INVALID {         \
        .short_opt = INVALID_OPT_VAL,   \
        .long_opt = NULL,               \
        .has_arg = 0,                   \
        .desc = NULL,                   \
}


#define REQUIRED_ARGUMENT 1
#define NO_ARGUMENT 0
/* definition for option value */
struct iris_opt {
        /* short option value (E.g.: '-o') */
        int short_opt;
        /* value of that gets written to 'opt_val' */
        int out_val;
        /* long option value (E.g.: '--output' */
        char *long_opt;
        /* select for sub option */
        int has_arg;
        /* flag description (E.g.: 'sets a custom path for the output file') */
        char *desc;
};

/* definition for 'iris_getopt' result */
struct iris_opt_result {
        /* the value of the 'short_opt' field inside the 'iris_opt' structure */
        int opt_val;
        /* the argument of the option, if supported */
        char *opt_arg;
        /* if the argument was supplied earlier, the index is stored here */
        int last_index;
        /* last cli parameter index */
        int opt_ind;
};

struct iris_opt_result iris_getopt(struct iris_opt *opt_arr, int *counter, int argc, char **argv);

#endif /* UTILS_IRIS_GETOPT_H */
