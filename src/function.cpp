#include <function.h>

Token Add(BINARY_OPERATOR, LEFT_ASSOCIATIVE, 2, add);
Token Substract(BINARY_OPERATOR, LEFT_ASSOCIATIVE, 2, substract);
Token Multiply(BINARY_OPERATOR, LEFT_ASSOCIATIVE, 3, multiply);
Token Divide(BINARY_OPERATOR, LEFT_ASSOCIATIVE, 3, divide);
Token Raise(BINARY_OPERATOR, RIGHT_ASSOCIATIVE, 4, raise);
Token Sine(UNARY_OPERATOR, NON_ASSOCIATIVE, 5, sine);
Token Cosine(UNARY_OPERATOR, NON_ASSOCIATIVE, 5, cosine);
Token Tangent(UNARY_OPERATOR, NON_ASSOCIATIVE, 5, tangent);
Token Logarithm(UNARY_OPERATOR, NON_ASSOCIATIVE, 5, logarithm);
Token SquareRoot(UNARY_OPERATOR, NON_ASSOCIATIVE, 5, sqroot);
Token LeftParanthese(LEFT_PARANTHESE);
Token RightParanthese(RIGHT_PARANTHESE);


bool Function::value(float x, float &y) {
    int length = tokenStack.size();
    std::vector <float> outputStack;
    std::vector <Token*> opStack;
    bool ok = 1;
    for (int i = 0; i < length && ok == 1; i++) {
        if (tokenStack[i]->getType() == NUMBER) {
            outputStack.push_back(tokenStack[i]->getValue());
        }
        else if(tokenStack[i]->getType() == INDETERMINATE) {
            outputStack.push_back(x);
        }
        else if(tokenStack[i]->getType() == UNARY_OPERATOR) {
            opStack.push_back(tokenStack[i]);
        }
        else if(tokenStack[i]->getType() == BINARY_OPERATOR) {
            while(opStack.back()->getPrecedence() > tokenStack[i]->getPrecedence() || (opStack.back()->getPrecedence() == tokenStack[i]->getPrecedence() && opStack.back()->getAssociativity() == LEFT_ASSOCIATIVE)) {
                if (opStack.back()->getType() == UNARY_OPERATOR) {
                    float k = opStack.back()->ApplyOperation(outputStack.back(), 0);
                    outputStack.pop_back();
                    outputStack.push_back(k);
                    opStack.pop_back();
                }
                else if(opStack.back()->getType() == BINARY_OPERATOR) {
                    float nr = outputStack.back();
                    outputStack.pop_back();
                    float k = opStack.back()->ApplyOperation(outputStack.back(), nr);
                    outputStack.pop_back();
                    outputStack.push_back(k);
                    opStack.pop_back();
                }
            }
            opStack.push_back(tokenStack[i]);
        }
        else if (tokenStack[i]->getType() ==  LEFT_PARANTHESE)
            opStack.push_back(tokenStack[i]);
        else if (tokenStack[i]->getType() ==  RIGHT_PARANTHESE) {
            while(opStack.back()->getType() != LEFT_PARANTHESE) {
                if (opStack.back()->getType() == UNARY_OPERATOR) {
                    float k = opStack.back()->ApplyOperation(outputStack.back(), 0);
                    outputStack.pop_back();
                    outputStack.push_back(k);
                    opStack.pop_back();
                }
                else if(opStack.back()->getType() == BINARY_OPERATOR) {
                    float nr = outputStack.back();
                    outputStack.pop_back();
                    float k = opStack.back()->ApplyOperation(outputStack.back(), nr);
                    outputStack.pop_back();
                    outputStack.push_back(k);
                    opStack.pop_back();
                }
            }
            if (opStack.back()->getType() == LEFT_PARANTHESE)
                opStack.pop_back();
            else {
                ok = 0;
            }
        }
    }
    while (!opStack.empty() && ok == 1) {
        if (opStack.back()->getType() == LEFT_PARANTHESE)
            ok = 0;
        else {
            if (opStack.back()->getType() == UNARY_OPERATOR) {
                float k = opStack.back()->ApplyOperation(outputStack.back(), 0);
                outputStack.pop_back();
                outputStack.push_back(k);
                opStack.pop_back();
            }
            else if(opStack.back()->getType() == BINARY_OPERATOR) {
                float nr = outputStack.back();
                outputStack.pop_back();
                float k = opStack.back()->ApplyOperation(outputStack.back(), nr);
                outputStack.pop_back();
                outputStack.push_back(k);
                opStack.pop_back();
            }
        }
    }
    if (outputStack.size() != 1)
        ok = 0;
    else {
        float k = outputStack.back();
        y = k;
    }

    return ok;
}

bool Function::convertStringToTokenVector() {
    int strl = currentFunction.length();
    bool ok = 1;
    tokenStack.clear();
    for (int i = 0; i < strl && ok == 1; i++) {
        if (currentFunction[i] >= '0' && currentFunction[i] <= '9') {
            int nr;
            while (currentFunction[i] >= '0' && currentFunction[i] <= '9') {
                nr = nr * 10 + currentFunction[i] - '0';
                i++;
            }
            if (currentFunction[i] == '.') {
                int p = 10;
                while (currentFunction[i] >= '0' && currentFunction[i] <= '9') {
                    nr = nr + 1.0 * (currentFunction[i] - '0') / p;
                    i++;
                    p = p * 10;
                }
            }
            i--;
            Token tok(NUMBER, nr);
            tokenStack.push_back(&tok);
        }
        else if (currentFunction[i] == 'x') {
            Token tok(INDETERMINATE);
            tokenStack.push_back(&tok);
        }
        else if (currentFunction[i] == '+') {
            tokenStack.push_back(&Add);
        }
        else if (currentFunction[i] == '-') {
            tokenStack.push_back(&Substract);
        }
        else if (currentFunction[i] == '*') {
            tokenStack.push_back(&Multiply);
        }
        else if (currentFunction[i] == '/') {
            tokenStack.push_back(&Divide);
        }
        else if (currentFunction[i] == '^') {
            tokenStack.push_back(&Raise);
        }
        else if (currentFunction[i] == 's') {
            if (currentFunction[i + 1] == 'i' && currentFunction[i + 2] == 'n') {
                tokenStack.push_back(&Sine);
                i = i + 2;
            }
            else if (currentFunction[i + 1] == 'q' && currentFunction[i + 2] == 'r' && currentFunction[i + 2] == 't') {
                tokenStack.push_back(&SquareRoot);
                i = i + 3;
            }
            else
                ok = 0;
        }
        else if (currentFunction[i] == 'c') {
            if (currentFunction[i + 1] == 'o' && currentFunction[i + 2] == 's') {
                tokenStack.push_back(&Cosine);
                i = i + 2;
            }
            else
                ok = 0;
        }
        else if (currentFunction[i] == 't') {
            if (currentFunction[i + 1] == 'a' && currentFunction[i + 2] == 'n') {
                tokenStack.push_back(&Tangent);
                i = i + 2;
            }
            else
                ok = 0;
        }
        else if (currentFunction[i] == 'l') {
            if (currentFunction[i + 1] == 'n') {
                tokenStack.push_back(&Logarithm);
                i++;
            }
            else
                ok = 0;
        }
        else if (currentFunction[i] == 'p') {
            if (currentFunction[i + 1] == 'i') {
                Token tok(NUMBER, PI);
                tokenStack.push_back(&tok);
            }
            else
                ok = 0;
        }
        else if (currentFunction[i] == 'e') {
            Token tok(NUMBER, E);
            tokenStack.push_back(&tok);
        }
        else if (currentFunction[i] == '(') {
            tokenStack.push_back(&LeftParanthese);
        }
        else if (currentFunction[i] == ')') {
            tokenStack.push_back(&RightParanthese);
        }
        else if (currentFunction[i] == ' ') {

        }
        else
            ok = 0;
    }
    return ok;
}

