/*
 * ASTMyID.cpp
 *
 *  Created on: 28 mars 2014
 *      Author: FrancisANDRE
 */

#include "ASTMyID.h"

namespace EG2 {

ASTMyID::ASTMyID(int i) : SimpleNode(i) {
}
ASTMyID::ASTMyID(Parser *p, int id) : SimpleNode(p, id){
}

void
ASTMyID::setName(JAVACC_STRING_TYPE image) {
	name = image;
}

ASTMyID::~ASTMyID() {
}

JAVACC_STRING_TYPE ASTMyID::toString() const {
  return "Identifier: " + name;
}


} /* namespace EG2 */
