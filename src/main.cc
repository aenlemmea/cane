#include <fstream>
#include <iostream>
#include "lex.hh"
#include "lexertil.hh"

int main(int argc, char** argv) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::ifstream inp_file{ std::string(argv[1]) };

    if (!inp_file.is_open()) {
        std::cerr << "Error opening file" << "\n";
        return 1;
    }

    Lexer lx;
    lx.switch_streams(&inp_file, 0);

    dtok ap = lx.get_next_token();

    while(ap.tok != token::__FIN) {
        ap.show();
        ap = lx.get_next_token();
    };

    inp_file.close();
}
