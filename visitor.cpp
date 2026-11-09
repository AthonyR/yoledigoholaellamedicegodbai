#include <iostream>
#include <algorithm>
#include <array>
#include <stdexcept>
#include <unordered_map>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <map>
#include <cstring>
#include "ast.h"
#include "parser.h"
#include "visitor.h"
#include "diagnostico.h"

using namespace std;


// =====================================================
// ====================== accept =======================
// =====================================================

// El nodo más profundo que tiene ubicación aporta la posición del error de tipos.
template <typename Nodo>
static auto visitar(Nodo* nodo, Visitor* visitor) {
    try {
        return visitor->visit(nodo);
    } catch (ErrorSemantico& e) {
        if (e.posicion < 0) e.posicion = nodo->posicion;
        throw;
    }
}

Type BinaryExp::accept(Visitor* visitor)  { return visitar(this, visitor); }
Type StructExp::accept(Visitor* visitor)  { return visitar(this, visitor); }
Type CampoExp::accept(Visitor* visitor)   { return visitar(this, visitor); }
Type UnaryExp::accept(Visitor* visitor)   { return visitar(this, visitor); }
Type ArrayExp::accept(Visitor* visitor)   { return visitar(this, visitor); }
Type IncDecExp::accept(Visitor* visitor)  { return visitar(this, visitor); }
Type DireccionExp::accept(Visitor* visitor) { return visitar(this, visitor); }
Type DerefExp::accept(Visitor* visitor)   { return visitar(this, visitor); }
Type LongitudExp::accept(Visitor* visitor) { return visitar(this, visitor); }
Type NumberExp::accept(Visitor* visitor)  { return visitar(this, visitor); }
Type IdExp::accept(Visitor* visitor)      { return visitar(this, visitor); }
Type IfExp::accept(Visitor* visitor)      { return visitar(this, visitor); }
Type FCallExp::accept(Visitor* visitor)   { return visitar(this, visitor); }

void AssignStmt::accept(Visitor* visitor)  { visitar(this, visitor); }
void AssignPunteroStmt::accept(Visitor* visitor) { visitar(this, visitor); }
void PrintStmt::accept(Visitor* visitor)   { visitar(this, visitor); }
void IfStmt::accept(Visitor* visitor)      { visitar(this, visitor); }
void WhileStmt::accept(Visitor* visitor)   { visitar(this, visitor); }
void DoWhileStmt::accept(Visitor* visitor) { visitar(this, visitor); }
void BreakStmt::accept(Visitor* visitor)   { visitar(this, visitor); }
void ReturnStmt::accept(Visitor* visitor)  { visitar(this, visitor); }
void BlockStmt::accept(Visitor* visitor)   { visitar(this, visitor); }
void ExprStmt::accept(Visitor* visitor)    { visitar(this, visitor); }
void ForStmt::accept(Visitor* visitor)     { visitar(this, visitor); }
void ContinueStmt::accept(Visitor* visitor) { visitar(this, visitor); }
void SwitchStmt::accept(Visitor* visitor)  { visitar(this, visitor); }

void VarDec::accept(Visitor* visitor)   { visitar(this, visitor); }
void Body::accept(Visitor* visitor)     { visitor->visit(this); }
void FunDec::accept(Visitor* visitor)   { visitar(this, visitor); }
void Programa::accept(Visitor* visitor) { visitor->visit(this); }

