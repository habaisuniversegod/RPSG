#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lexer.h"
#include "eval.h"
#include "wsave.h"

int main(int argc, char **argv){
    if (argc < 5) return -1488;

    unsigned int sample_rate = atol(argv[2]);
    unsigned int samples = atof(argv[3]) * sample_rate;

    Lexer lexer = Lexer(std::string(argv[1]));
    auto tokens = lexer.parse();

    Eval eval;

    for (auto i: tokens){
        std::cout << i.repr() << "\n";
    }

    std::cout << "Parsing " << samples << " samples (~" << samples / (double)sample_rate << " seconds)...\n";

    std::srand(std::time(0));

    WAV_Header header;
    setup_header(&header, samples * 2, sample_rate);
    auto data = generate_audio(eval, tokens, samples);
    save_WAV(std::string(argv[4]), &header, (unsigned char*)data);
    delete[] data;
    
    std::cout << "Saved to file '" << argv[4] << "'.\nProcess finished. Press ENTER to exit...";

    getc(stdin); 

    return 0;
}