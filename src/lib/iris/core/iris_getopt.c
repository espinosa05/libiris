#include "../../../include/iris/core/iris_getopt.h"

#include <string.h>

/* static function declaration start */
static struct iris_opt load_long_opt(char *arg, struct iris_opt *opts);
static struct iris_opt load_short_opt(char *arg, struct iris_opt *opts);

static int is_last_iris_opt(struct iris_opt opt);
/* static function declaration end */


struct iris_opt_result iris_getopt(struct iris_opt *opt_arr, int *counter,
                                        int argc, char **argv)
{
        struct iris_opt_result res = INIT_IRIS_OPT_RESULT_INVALID;
        struct iris_opt opt_entry;
        char *arg = NULL;

        if (argc < *counter)
                return res;
        res.opt_ind = *counter;
        arg = argv[*counter];

        /* has leading dash? */
        if (arg[0] != '-')
                return res;

        /* is long argument? (double dash) */
        if (arg[1] == '-') {
                opt_entry = load_long_opt(arg, opt_arr);
        } else {
                opt_entry = load_short_opt(arg, opt_arr);
        }

        /* consume current arg */
        (*counter)++;
        res.opt_val = opt_entry.out_val;


        if (opt_entry.has_arg) {
                if (argc >= *counter + 1) {
                        res.opt_arg = argv[*counter];
                        (*counter)++; /* skip option */
                } else {
                        res.opt_val = INVALID_OPT_ARG;
                }
        }

        return res;
}

/* contstatns for skipping the dashes */
enum arg_offsets {
        SHORT_ARG_OFFSET = 1,
        LONG_ARG_OFFSET,
};

static struct iris_opt load_long_opt(char *arg, struct iris_opt *opts)
{
        struct iris_opt ret = INIT_IRIS_OPT_INVALID;
        int current = 0;

        arg += LONG_ARG_OFFSET;

        while (!is_last_iris_opt(opts[current])) {
                if (0 == strcmp(opts[current].long_opt, arg)) {
                        ret = opts[current];
                        break;
                }
                current++;
        }

        return ret;
}

static struct iris_opt load_short_opt(char *arg, struct iris_opt *opts)
{
        struct iris_opt ret = INIT_IRIS_OPT_INVALID;
        int current = 0;
        char short_arg;

        arg += SHORT_ARG_OFFSET;
        short_arg = arg[0];

        while (!is_last_iris_opt(opts[current])) {
                if (short_arg == opts[current].short_opt) {
                        ret = opts[current];
                        break;
                }
                current++;
        }


        return ret;
}

static int is_last_iris_opt(struct iris_opt opt)
{
        return (opt.short_opt == 0
                        && opt.long_opt == NULL
                        && opt.has_arg == 0
                        && opt.desc == NULL);
}
