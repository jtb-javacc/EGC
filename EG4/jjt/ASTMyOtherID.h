/*
 * ASTMyOtherID.h
 *
 *  Created on: 27 mars 2014
 *      Author: FrancisANDRE
 */

#ifndef ASTMYOTHERID_H_
#define ASTMYOTHERID_H_
#include "EG4Visitors.h"
#include "ParserTree.h"
#include "SimpleNode.h"

namespace EG4 {
class ParserVisitor;

class ASTMyOtherID: public EG4Visitors, public SimpleNode {
private:
	JAVACC_SIMPLE_STRING name;

public:
	ASTMyOtherID(int id);
	ASTMyOtherID(Parser *p, int id);
	virtual ~ASTMyOtherID();

	void setName(JAVACC_STRING_TYPE image);
	JAVACC_STRING_TYPE toString() const;

	double x;

	/** Accept the visitor. **/
	virtual void* jjtAccept(ParserVisitor *visitor, void * data) const;

	void accept(EG4Visitors::MyConstVisitor& v)
    {
        v.visit(*this);
    }
};
}
#endif /* ASTMYOTHERID_H_ */
