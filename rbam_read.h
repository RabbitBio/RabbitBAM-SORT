
#include <config.h>

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <getopt.h>
#include <assert.h>
#include <pthread.h>
#include <inttypes.h>
#include "htslib/ksort.h"
#include "htslib/hts_os.h"
#include "htslib/khash.h"
#include "htslib/klist.h"
#include "htslib/kstring.h"
#include "htslib/sam.h"
#include "htslib/hts_endian.h"
#include "htslib/cram.h"
#include "htslib/thread_pool.h"
#include "sam_opts.h"
#include "samtools.h"
#include "bedidx.h"
#include "bam.h"




//#define use_read_parallel



#ifndef RBAM_READ_H
#define RBAM_READ_H

#ifdef __cplusplus
extern "C" {
#endif

    void RBAM_init(const char* fn, int n_threads, bool is_tgs);
    void RBAM_getdata(bam1_t **buffer, int *size);

#ifdef __cplusplus
    
}
#endif

#endif // RBAM_READ_H

