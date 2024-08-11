

#include "rbam_read.h"

#include "BamReader.h"
#include "BamTools.h"
#include "BamWriter.h"

BamReader *reader;

std::vector<bam1_t*> b_vec[THREAD_NUM_P];

const int RN = 40 << 10;

void RBAM_init(const char* fn, int n_threads, bool is_tgs) {
    reader = new BamReader(fn, n_threads, is_tgs);

    for(int i = 0; i < THREAD_NUM_P; i++) {
        for(int j = 0; j < RN; j++) {
            bam1_t *item = bam_init1();
            b_vec[i].push_back(item);
        }
    }
}


void RBAM_getdata(bam1_t **buffer, int *size) {
    auto res_vec = reader->getBam1_t_parallel(b_vec);
    *size = res_vec.size();
    for (int i = 0; i < *size; ++i) {
        buffer[i] = res_vec[i];
    }
}

