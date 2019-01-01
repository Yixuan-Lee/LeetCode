#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty()) {
            return 0;
        }
        if (tokens.size() == 1) {
            return stoi(tokens[0]);
        }

        vector<int> res;    // stores integer operands and the final result
        int operandA;
        int operandB;
        string operatorC;
        int idx = 0;

        // read the first three string, and do the corresponding operation
        operandA = stoi(tokens[idx++]);
        operandB = stoi(tokens[idx++]);
        operatorC = tokens[idx++];
        if (operatorC == "+") {
            res.push_back(operandA + operandB);
        } else if (operatorC == "-") {
            res.push_back(operandA - operandB);
        } else if (operatorC == "*") {
            res.push_back(operandA * operandB);
        } else if (operatorC == "/") {
            res.push_back(operandA / operandB);
        } else {
            // operatorC is a number, not an operator, then push the three numbers
            res.push_back(operandA);
            res.push_back(operandB);
            res.push_back(stoi(operatorC));
        }

        while (idx < tokens.size()) {
            operandA = res.back();
            res.pop_back();
            if (res.empty()) {
                // in this condition, tokens[idx] must be a number
                // operandA is the previous string of operandB
                operandB = stoi(tokens[idx++]);
            } else {
                // operandA is the following string of operandB
                operandB = res.back();
                res.pop_back();

                // for the operation order reason, swap the operandA and oeprandB
                // make sure operatorA always points to the previous string of operatorB
                int temp = operandA;
                operandA = operandB;
                operandB = temp;
            }
            operatorC = tokens[idx++];

            // for debugging
//            std::cout << "operandA: " << operandA << std::endl;
//            std::cout << "operandB: " << operandB << std::endl;
//            std::cout << "operatorC: " << operatorC << std::endl;

            if (operatorC == "+") {
                // notice the sequence here
                add(res, operandA, operandB);
            } else if (operatorC == "-") {
                // notice the sequence here
                subtract(res, operandA, operandB);
            } else if (operatorC == "*") {
                // notice the sequence here
                multiply(res, operandA, operandB);
            } else if (operatorC == "/") {
                // notice the sequence here
                divide(res, operandA, operandB);
            } else {
                // push the previous string and the following string back to the stack
                res.push_back(operandA);
                res.push_back(operandB);

                res.push_back(stoi(operatorC));
            }
        }
        return res[0];
    }

private:
    void add(vector<int> &res, int operandA, int operandB) {
        res.push_back(operandA + operandB);
    }

    void subtract(vector<int> &res, int operandA, int operandB) {
        res.push_back(operandA - operandB);
    }

    void multiply(vector<int> &res, int operandA, int operandB) {
        res.push_back(operandA * operandB);
    }

    void divide(vector<int> &res, int operandA, int operandB) {
        res.push_back(operandA / operandB);
    }
};


int main() {
    Solution s;
    vector<string> tokens {"2", "1", "+", "3", "*"};
    std::cout << s.evalRPN(tokens) << std::endl;

    tokens = vector<string> {"4", "13", "5", "/", "+"};
    std::cout << s.evalRPN(tokens) << std::endl;

    tokens = vector<string> {
            "10", "6", "9", "3", "+", "-11", "*",
            "/", "*", "17", "+", "5", "+"
    };
    std::cout << s.evalRPN(tokens) << std::endl;

    tokens = vector<string> {"18"};
    std::cout << s.evalRPN(tokens) << std::endl;

    tokens = vector<string> {
            "-78", "-33", "196", "+", "-19", "-", "115", "+",
            "-", "-99", "/", "-18", "8", "*", "-86", "-", "-", "16", "/",
            "26", "-14", "-", "-", "47", "-", "101", "-", "163", "*", "143",
            "-", "0", "-", "171", "+", "120", "*", "-60", "+", "156", "/",
            "173", "/", "-24", "11", "+", "21", "/", "*", "44", "*", "180",
            "70", "-40", "-", "*", "86", "132", "-84", "+", "*", "-", "38",
            "/", "/", "21", "28", "/", "+", "83", "/", "-31", "156", "-", "+",
            "28", "/", "95", "-", "120", "+", "8", "*", "90", "-", "-94", "*",
            "-73", "/", "-62", "/", "93", "*", "196", "-", "-59", "+", "187",
            "-", "143", "/", "-79", "-89", "+", "-"
    };
    std::cout << s.evalRPN(tokens) << std::endl;

    tokens = vector<string> {
            "4", "-2", "/", "2", "-3", "-", "-"
    };
    std::cout << s.evalRPN(tokens) << std::endl;

    return 0;
}
