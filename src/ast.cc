#include "ast.hh"

#include <string>
#include <vector>

NodeBinOp::NodeBinOp(NodeBinOp::Op ope, Node *leftptr, Node *rightptr) {
    type = BIN_OP;
    op = ope;
    left = leftptr;
    right = rightptr;
}

std::string NodeBinOp::to_string() {
    std::string out = "(";
    switch(op) {
        case PLUS: out += '+'; break;
        case MINUS: out += '-'; break;
        case MULT: out += '*'; break;
        case DIV: out += '/'; break;
    }

    out += ' ' + left->to_string() + ' ' + right->to_string() + ')';

    return out;
}

NodeInt::NodeInt(int val) {
    type = INT_LIT;
    value = val;
}

std::string NodeInt::to_string() {
    return std::to_string(value);
}

NodeStmts::NodeStmts() {
    type = STMTS;
    list = std::vector<Node*>();
}

void NodeStmts::push_back(Node *node) {
    list.push_back(node);
}

std::string NodeStmts::to_string() {
    std::string out = "(begin";
    for(auto i : list) {
        out += " " + i->to_string();
    }

    out += ')';

    return out;
}

NodeAssn::NodeAssn(std::string id, Node *expr) {
    type = ASSN;
    identifier = id;
    expression = expr;
}

std::string NodeAssn::to_string() {
    return "(let " + identifier + " " + expression->to_string() + ")";
}

NodeDebug::NodeDebug(Node *expr) {
    type = DBG;
    expression = expr;
}

std::string NodeDebug::to_string() {
    return "(dbg " + expression->to_string() + ")";
}

NodeIdent::NodeIdent(std::string ident) {
    identifier = ident;
}
std::string NodeIdent::to_string() {
    return identifier;
}

NodeVarDecl::NodeVarDecl(std::string id, Node *expr) {
    type = VAR_DECL;
    identifier = id;
    expression = expr;
}

std::string NodeVarDecl::to_string() {
    return "(assign " + identifier + " " + expression->to_string() + ")";
}

NodeTernary::NodeTernary(Node::NodeType type, Op op, Node *cond, Node *true_expr, Node *false_expr) {
    type = TERNARY_OP;
    
    ope = op;
    condition = cond;
    true_expression = true_expr;
    false_expression = false_expr;
}

std::string to_string() {
    std::string out = "(";
    out += (op == TQUESTION) ? '?' : ':';
    out += ' ' + condition->to_string() + ' ' + true_expression->to_string() + ' ' + false_expression->to_string() + ')';
    return out;
}
