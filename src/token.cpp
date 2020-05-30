#include <token.h>


Token::Token() {
}
Token::Token(TokenType type) {
    this->type = type;
}
Token::Token(TokenType type, float value) {
    this->type = type;
    this->value = value;
}
Token::Token(TokenType type, Associativity assoc, int prec, float (*function)(float, float)) {
    this->type = type;
    this->associativity = assoc;
    this->precedence = prec;
    this->function = function;
}
TokenType Token::getType() {
    return this->type;
}
float Token::getValue() {
    return this->value;
}
Associativity Token::getAssociativity() {
    return this->associativity;
}
int Token::getPrecedence() {
    return this->precedence;
}
float Token::ApplyOperation(float x, float y) {
    return this->function(x, y);
}

