#include "wsave.h"
#include <string.h>

void setup_header(WAV_Header* header, unsigned int data_size, unsigned int sample_rate){
    header->sample_rate = sample_rate;
    header->data_rate = sample_rate * 2;
    header->data_size = data_size;
    header->fsize = data_size + WAVHEAD_SIZE;
}

void save_WAV(const std::string& fname, WAV_Header* header, unsigned char* data){
    std::ofstream file(fname, std::ios::out | std::ios::binary);

    unsigned char* buffer = new unsigned char[header->fsize];

    if (!file){
        fprintf(stderr, "Error: cannot open file '%s' to write", fname.c_str());
        exit(-3);
    }
    memcpy(buffer, (unsigned char*)header, WAVHEAD_SIZE);
    memcpy(&buffer[WAVHEAD_SIZE], data, header->data_size);

    file.write((char*)buffer, header->fsize);
    file.close();

    delete[] buffer;
}

short* generate_audio(Eval& e, const std::vector<Token>& prog, unsigned int samples_count){
    short* data = new short[samples_count];

    for (unsigned int i = 0; i < samples_count; i++){
        data[i] = 32767 * std::max(-1.0, std::min(1.0, e.eval(prog, (double)i, (double)samples_count)));
    }

    return data;
}