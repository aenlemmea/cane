#ifndef CANE_LEXERTIL_HH
#define CANE_LEXERTIL_HH

#include <cstdint>
#include <string>
#include <ostream>

#if ! defined(yyFlexLexerOnce)
#undef yyFlexLexer
#define yyFlexLexer Cane_Lexer
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL dtok Lexer::get_next_token()

enum class token : int16_t {
    __INVALID,
    __FIN,
    AUTO,
    TO,
    IMPORT,
    IDENT,
    INTLIT,
    DUBLIT,
    INT32,
    INT64,
    DUB32,
    DUB64,
    CHAR32,
    LPAREN,
    RPAREN,
    LCURLY,
    RCURLY,
    SEMICOLON,
    COMMA,
    COLON,
    ARROW,
    ASSIGN,
    RET,
};

struct dtok {
    std::string str;
    token tok;

    dtok(std::string_view string, token t) : str{ string }, tok { t } {}

    void show() {
        std::cout << *this;
    }

    static const std::string token_matcher(token t) {
        switch (t) {
            case token::__INVALID: return "__INVALID";
            case token::__FIN: return "__FIN";
            case token::AUTO: return "AUTO";
            case token::TO: return "TO";
            case token::IMPORT: return "IMPORT";
            case token::IDENT: return "IDENT";
            case token::INTLIT: return "INTLIT";
            case token::DUBLIT: return "DUBLIT";
            case token::INT32: return "INT32";
            case token::INT64: return "INT64";
            case token::DUB32: return "DUB32";
            case token::DUB64: return "DUB64";
            case token::CHAR32: return "CHAR32";
            case token::LPAREN: return "LPAREN";
            case token::RPAREN: return "RPAREN";
            case token::LCURLY: return "LCURLY";
            case token::RCURLY: return "RCURLY";
            case token::SEMICOLON: return "SEMICOLON";
            case token::COMMA: return "COMMA";
            case token::COLON: return "COLON";
            case token::ARROW: return "ARROW";
            case token::ASSIGN: return "ASSIGN";
            case token::RET: return "RET";
            default: return "Unknown token"; // Fallback case
        }
    }


    friend std::ostream& operator<<(std::ostream& os, dtok& tokie) {
        os << "[ Token: " << token_matcher(tokie.tok) << " val: " << tokie.str << " ]\n";
        return os;
    }
};

class Lexer : public yyFlexLexer {
    public:
    virtual dtok get_next_token();
};
#endif
