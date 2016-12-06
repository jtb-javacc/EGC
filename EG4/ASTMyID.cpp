/*
 * ASTMyID.cpp
 *
 *  Created on: 28 mars 2014
 *      Author: FrancisANDRE
 */

#include "ASTMyID.h"
#include "ParserVisitor.h"

namespace EG4 {

ASTMyID::ASTMyID(int i) : SimpleNode(i) {
}
ASTMyID::ASTMyID(Parser *p, int id) : SimpleNode(p, id){
}
ASTMyID::~ASTMyID() {
}

void
ASTMyID::setName(JAVACC_STRING_TYPE image) {
	name = image;
}
JAVACC_STRING_TYPE
ASTMyID::toString() const {
  return "Identifier: " + name;
}
/** Accept the visitor. **/
void*
ASTMyID::jjtAccept(ParserVisitor *visitor, void * data) const {
  return visitor->visit(this, data);
}


} /* namespace EG4 */
