# RabbitBAM-SORT

Efficient BAM file sorting with [RabbitBAM](https://github.com/RabbitBio/RabbitBAM) I/O library

## Dependancy

- gcc 8.5.0 or newer
- [htslib](https://github.com/samtools/htslib) 1.15 or newer
- [libdeflate](https://github.com/ebiggers/libdeflate) 1.12 or newer
- [RabbitBAM](https://github.com/RabbitBio/RabbitBAM)

## Installation

```bash
git clone https://github.com/RabbitBio/RabbitBAM-SORT
cd RabbitBAM-SORT
bash configure.sh <path-to-htslib-installation-directory> <path-to-RabbitBAM-installation-directory> <path-to-libdeflate-installation-directory>
source env.sh
make clean && make
```

## Usage

refer to `./bam_sort -h`
