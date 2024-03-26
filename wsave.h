#pragma once

#include "eval.h"

#define WAVHEAD_SIZE 44

struct WAV_Header {
    const char riff_header[4] = {'R', 'I', 'F', 'F'};
    unsigned int fsize = 0;
    const char wav_header[4] = {'W', 'A', 'V', 'E'};
    const char fmt_chunk[4] = {'f', 'm', 't', ' '};
    const unsigned int fmt_length = 16;
    const unsigned short fmt_type = 1;
    const unsigned short channels_count = 1;
    unsigned int sample_rate = 44100;
    unsigned int data_rate = 44100 * 2;
    const unsigned short idk = 2;
    const unsigned short bit_depth = 16;
    const char data_header[4] = {'d', 'a', 't', 'a'};
    unsigned int data_size = 0;
};

void setup_header(WAV_Header* header, unsigned int data_size, unsigned int sample_rate);

void save_WAV(const std::string& fname, WAV_Header* header, unsigned char* data);

short* generate_audio(Eval& e, const std::vector<Token>& prog, unsigned int samples_count);